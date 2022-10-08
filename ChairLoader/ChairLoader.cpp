#include <Prey/CryCore/Platform/platform_impl.inl>
#include <filesystem>
#include <Prey/CryInput/IInput.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/CryGame/Game.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h>
#include <Prey/GameDll/ark/player/arkplayermovementstates.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <ChairLoader/PreyFunction.h>
#include <mem.h>
#include "ChairLoader.h"
#include "EntityUtils.h"
#include "ChairloaderGui.h"
#include "Profiler.h"
#include <Prey/CryCore/Platform/CryWindows.h>
#include <detours/detours.h>
#include "Chairloader/ChairloaderEnv.h"
#include "RenderDll/RenderDll.h"
#include "RenderDll/Shaders/ShaderPaths.h"
#include "ModDllManager.h"
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include "Editor/Editor.h"

static ChairloaderGlobalEnvironment s_CLEnv;
ChairLoader* gChair = nullptr;
ChairloaderGlobalEnvironment* gCL = &s_CLEnv;

static bool smokeFormExited = false;

namespace {

class ConsoleStdoutSink : public IOutputPrintSink {
public:
	void Init() {
		gEnv->pConsole->AddOutputPrintSink(this);
		PrintExistingMessages();
	}

	void Print(const char *inszText) override {
		printf("%s\n", inszText);
	}

	void PrintExistingMessages() {
		Print(">>>>>>>> Printing console log");
		int count = gEnv->pConsole->GetLineCount();

		for (int i = count - 1; i >= 0; i--) {
			char buf[1024];
			gEnv->pConsole->GetLineNo(i, buf, sizeof(buf));
			printf("%s\n", buf);
		}

		Print(">>>>>>>> Finished printing console log");
	}
};

ConsoleStdoutSink g_StdoutConsole;

FunctionHook<decltype(CSystem::FInitializeEngineModule)::Type> g_CSystem_InitializeEngineModule_Hook;
auto g_CSystem_Shutdown_Hook = CSystem::FShutdown.MakeHook();
auto g_CGame_Init_Hook = CGame::FInit.MakeHook();
auto g_CGame_Update_Hook = CGame::FUpdate.MakeHook();
auto g_CGame_Shutdown_Hook = CGame::FShutdown.MakeHook();
auto g_SmokeForm_Exit_hook = ArkPsiPowerSmokeForm::FExit.MakeHook();
auto g_SmokeForm_TryMorphOut_hook = ArkPsiPowerSmokeForm::FTryMorphOut.MakeHook();
auto g_SmokeForm_Stop_hook = ArkPsiPowerSmokeForm::FStop.MakeHook();



bool CSystem_InitializeEngineModule_Hook(
	CSystem* _this,
	const SModuleInitInfo* _initInfo,
	const SSystemInitParams* initParams,
	bool bQuitIfNotFound)
{
	// Init Chairloader on first call
	static bool isChairloaderInited = false;
	if (!isChairloaderInited)
	{
		isChairloaderInited = true;
		gChair->InitSystem(_this);
	}

	return g_CSystem_InitializeEngineModule_Hook.InvokeOrig(_this, _initInfo, initParams, bQuitIfNotFound);
}

void CSystem_Shutdown_Hook(CSystem* _this)
{
	gChair->ShutdownSystem();
	g_CSystem_Shutdown_Hook.InvokeOrig(_this);

	// Shutdown Chairloader for good
	delete gChair;
	gChair = nullptr;
}

bool CGame_Init_Hook(CGame* _this, IGameFramework* pFramework)
{
	g_pGame = _this;
	bool result = g_CGame_Init_Hook.InvokeOrig(_this, pFramework);

	if (result)
		gChair->InitGame(pFramework);

	return result;
}

int CGame_Update_Hook(CGame* _this, bool haveFocus, unsigned int updateFlags)
{
	gChair->PreUpdate(haveFocus, updateFlags);
	int result = g_CGame_Update_Hook.InvokeOrig(_this, haveFocus, updateFlags);
	gChair->PostUpdate(haveFocus, updateFlags);
	return result;
}

void CGame_Shutdown_Hook(CGame* _this)
{
	gChair->ShutdownGame();
	g_CGame_Shutdown_Hook.InvokeOrig(_this);
}

void SmokeForm_Exit_Hook(ArkPsiPowerSmokeForm* _this) {
	smokeFormExited = true;
	g_SmokeForm_Exit_hook.InvokeOrig(_this);
}

//char SmokeForm_TryMorphOut_Hook(ArkPsiPowerSmokeForm* _this) {
//	char retValue = g_SmokeForm_TryMorphOut_hook.InvokeOrig(_this);
//	ArkPlayerMovementStates::Smoke::Exit();
//	gCLEnv->entUtils->ArkPlayerPtr()->Physicalize();
//	return retValue;
//}
//
//char SmokeForm_Stop_Hook(ArkPsiPowerSmokeForm* _this) {
//	auto retValue = g_SmokeForm_Stop_hook.InvokeOrig(_this);
//	gCLEnv->entUtils->ArkPlayerPtr()->m_movementFSM.m_smokeState.Exit();
//	return retValue;
//}
}

ChairLoader::ChairLoader() {
	CreateConsole();
	printf("ChairLoader Initializing...\n");

	// Get game DLL address
	HMODULE hGameDll = nullptr;
	GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, PREY_DLL_NAME, &hGameDll);

	if (!hGameDll)
	{
		printf("Error! Failed to get " PREY_DLL_NAME " module base address\n");
		std::abort();
	}

	m_ModuleBase = (uintptr_t)hGameDll;
	printf(PREY_DLL_NAME " = 0x%016llX\n", m_ModuleBase);

    // insert key name pairs into bimap bc bimaps kinda suck at static initialization
    LoadKeyNames();

	PreyFunctionSystem::Init(m_ModuleBase);

	// Install CSystem manual hook for InitSystem
	DetourTransactionBegin();
	g_CSystem_InitializeEngineModule_Hook.InstallHook(CSystem::FInitializeEngineModule.Get(), &CSystem_InitializeEngineModule_Hook);
	DetourTransactionCommit();
}

void ChairLoader::InitHooks()
{
	// Set up hooks
	//
	// Explicit SetHookFunc calls are ugly but I see no other way to do it in C++.
	// If PreyFunctionHook were to take the func in the contructor, then it'd be possible
	// to have a .cpp file with just PreyFunctionHook globals. Such file won't have
	// any symbols referenced and may be removed by the linker, which is an incorrect behaviour.
	// Explicit SetHookFunc calls from here make sure other files are referenced.
	// 
	// Additionally, the contructor approach requires forward declaration of either
	// the hook function or the PreyFunctionHook object, that implies repetition of
	// function arguments, which is even more ugly.
	//
	g_CSystem_Shutdown_Hook.SetHookFunc(&CSystem_Shutdown_Hook);
	g_CGame_Init_Hook.SetHookFunc(&CGame_Init_Hook);
	g_CGame_Update_Hook.SetHookFunc(&CGame_Update_Hook);
	g_CGame_Shutdown_Hook.SetHookFunc(&CGame_Shutdown_Hook);
	g_SmokeForm_Exit_hook.SetHookFunc(&SmokeForm_Exit_Hook);
	ChairLoaderImGui::InitHooks();

	if (m_bEditorEnabled)
		Editor::InitHooks();

	// DeviceInfo::CreateDevice: Remove D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY flag
	// Allows graphics debuggers to be attached
	{
		uint8_t bytes[] = { 0x00, 0x08 };
		uint8_t* base = (uint8_t*)GetModuleBase();
		mem::Patch(base + 0xF240CD, bytes + 0, 1);
		mem::Patch(base + 0xF240E0, bytes + 1, 1);
	}

	// Install all hooks
	InstallHooks();
}

void ChairLoader::InitSystem(CSystem* pSystem)
{
	ModuleInitISystem(pSystem, "ChairLoader");
	g_StdoutConsole.Init();
	CryLog("ChairLoader::InitSystem");
	CryLog("ChairLoader: gEnv = 0x%p\n", gEnv);

	gCL->cl = this;

	// Increase log verbosity: messages, warnings, errors.
	// Max level is 4 (eComment) but it floods the console.
	gEnv->pConsole->ExecuteString("log_Verbosity 3");

	// Editor cmd line switch
	m_bEditorEnabled = pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "editor");

	if (m_bEditorEnabled)
	{
		// Dev mode is always enabled in Editor.
		pSystem->SetDevMode(true);
	}
	else if (!pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "nodevmode"))
	{
		bool devMode = false;
#ifdef DEBUG_BUILD
		// Activate dev mode in debug build
		devMode = true;
#else
		// Activate dev mode if user requested it
		devMode = pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "devmode") != nullptr;
#endif
		pSystem->SetDevMode(devMode);
	}

	// Disabling audio speeds up loading immensely (8 seconds on my hardware)
	if (pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "noaudio"))
		pSystem->m_sys_audio_disable->Set(1);

	WaitForRenderDoc();

	m_MainThreadId = std::this_thread::get_id();
	gConf = new ChairloaderConfigManager();
	gCL->conf = gConf;
	CryLog("Chairloader config loaded: %u", gConf->loadModConfigFile(chairloaderModName));

    // Get config parameters From Config
    loadConfigParameters();

	// Register mods
	m_pModDllManager = std::make_unique<ModDllManager>();
	m_pModDllManager->SetHotReloadEnabled(IsEditorEnabled());
	RegisterMods();

	// Init renderer patches. Must be done after shader mods are registered.
	RenderDll::SetRenderThreadIsIdle(true);
	RenderDll::SRenderDllPatchParams renderDllPatch;
	renderDllPatch.bEnableAuxGeom = gEnv->pSystem->IsDevMode();
	RenderDll::InitRenderDllPatches(renderDllPatch);

	// Install hooks late into init, some SetHookFunc calls depend on cmd line or mods
	InitHooks();

	// Load DLL mods
	m_pModDllManager->LoadModules();	
	m_pModDllManager->CallInitSystem();

	RenderDll::SetRenderThreadIsIdle(false);
}


void ChairLoader::InitGame(IGameFramework* pFramework)
{
	CryLog("ChairLoader::InitGame");
	m_pFramework = pFramework;
	gEntUtils = new EntityUtils();
	m_ImGui = std::make_unique<ChairLoaderImGui>();
	gui = new ChairloaderGui();
	g_pProfiler = new Profiler();

	if (m_bEditorEnabled)
		m_pEditor = std::make_unique<Editor>();

	gCL->pImGui = m_ImGui.get();
	gCL->gui = gui;
	gCL->entUtils = gEntUtils;

	gRenDev->m_pRT->SyncMainWithRender();
	gRenDev->m_pRT->SyncMainWithRender();
	RenderDll::SetRenderThreadIsIdle(true);
	m_pModDllManager->CallInitGame();
	RenderDll::SetRenderThreadIsIdle(false);
}

void ChairLoader::ShutdownGame()
{
	CryLog("ChairLoader::ShutdownGame");

	m_pModDllManager->CallShutdownGame();
	m_pEditor = nullptr;
	m_ImGui = nullptr;
	m_pFramework = nullptr;
}

void ChairLoader::ShutdownSystem()
{
	CryLog("ChairLoader::ShutdownSystem");
	
	RenderDll::SetRenderThreadIsIdle(true);
	m_pModDllManager->CallShutdownSystem();
	m_pModDllManager->UnloadModules();
	RenderDll::ShutdownSystem();
	RenderDll::SetRenderThreadIsIdle(false);

	gEnv = nullptr;
}

ChairLoader::~ChairLoader()
{
	// Remove all installed hooks
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	PreyFunctionSystem::RemoveHooks();
	DetourTransactionCommit();

	// Close the console
	if (m_pConsoleFile) {
		fclose(m_pConsoleFile);
		m_pConsoleFile = nullptr;
	}

	FreeConsole();
}

void ChairLoader::PreUpdate(bool haveFocus, unsigned int updateFlags) {
    if(gConf->getConfigDirty(chairloaderModName)){
        loadConfigParameters();
    }
	m_ImGui->PreUpdate(haveFocus);
	SmokeFormExit();
	gui->update();
	gConf->Update();

	gui->draw(&m_ShowGui);
	m_pModDllManager->CallDraw();

	// Editor update MUST come before mod PreUpdate for proper hot-reloading
	if (m_pEditor)
	{
		m_pEditor->Update();
		
		if (m_ShowGui)
			m_pEditor->ShowUI();
	}

	m_pModDllManager->CallPreUpdate();
}

void ChairLoader::PostUpdate(bool haveFocus, unsigned int updateFlags) {
	m_ImGui->PostUpdate();
	m_pModDllManager->CallPostUpdate();
}

bool ChairLoader::HandleKeyPress(const SInputEvent &event) {
	if (event.keyId == eKI_Tilde && event.state == eIS_Pressed) {
        if(!m_ShowGui){
            m_ShowGui = true;
            gui->SetDevConsoleVisible(true);
        } else {
            gui->SetDevConsoleVisible(!gui->IsDevConsoleVisible());
        }
		return true;
	}
    if(event.keyId == m_hideGuiKey && event.state == eIS_Pressed) {
        m_ShowGui = !m_ShowGui;
        return true;
    }
    if(event.keyId == m_toggleFreecamKey && event.state == eIS_Pressed) {
        m_FreeCamEnabled = !m_FreeCamEnabled;
        CryLog("Freecam state: %u\n", m_FreeCamEnabled);
        if (m_FreeCamEnabled) {
            m_DevMode = true;
            ((CSystem*)gEnv->pSystem)->SetDevMode(m_DevMode);
            gEnv->pConsole->ExecuteString("FreeCamEnable", true, false);
        }
        else {
            ((CSystem*)gEnv->pSystem)->SetDevMode(m_DevMode);
            gEnv->pConsole->ExecuteString("FreeCamDisable", true, false);
        }
        return true;
    }

	if (m_pEditor && m_pEditor->HandleKeyPress(event))
		return true;

	return false;
}

void ChairLoader::SmokeFormExit() {
	if(smokeFormExited) {
		gCL->entUtils->ArkPlayerPtr()->m_movementFSM.m_smokeState.Exit();
		smokeFormExited = false;
	}
}

void ChairLoader::CreateConsole() {
	AllocConsole();
	freopen_s(&m_pConsoleFile, "CONOUT$", "w", stdout);
	printf("Welcome to funland sonic\n");
}

void ChairLoader::InstallHooks()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	PreyFunctionSystem::InstallHooks();
	DetourTransactionCommit();
}

//TODO: deprecated config system keys


void ChairLoader::WaitForRenderDoc()
{
	constexpr int WAIT_TIME_SEC = 10;

	if (gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "renderdoc"))
	{
		for (int i = 0; i < WAIT_TIME_SEC; i++)
		{
			CryLog("Waiting for RenderDoc - %d seconds...", WAIT_TIME_SEC - i);

			for (int j = 0; j < 10; j++)
			{
				HMODULE renderdoc = GetModuleHandleA("renderdoc.dll");

				if (renderdoc)
				{
					CryLog("RenderDoc found!");
					return;
				}

				Sleep(100);
			}
		}

		CryLog("RenderDoc not found, continuing loading");
	}
}

ChairloaderGlobalEnvironment* ChairLoader::GetChairloaderEnvironment() {
	return gCL;
}

uintptr_t ChairLoader::GetPreyDllBase()
{
	return GetModuleBase();
}

//! this function is needed because bimaps don't handle static initialization very well
void ChairLoader::LoadKeyNames() {
    //eKI_Escape = 0x0, eKI_1 = 0x1, eKI_2 = 0x2, eKI_3 = 0x3, eKI_4 = 0x4, eKI_5 = 0x5, eKI_6 = 0x6, eKI_7 = 0x7, eKI_8 = 0x8, eKI_9 = 0x9, eKI_0 = 0xA, eKI_Minus = 0xB, eKI_Equals = 0xC, eKI_Backspace = 0xD, eKI_Tab = 0xE, eKI_Q = 0xF, eKI_W = 0x10, eKI_E = 0x11, eKI_R = 0x12, eKI_T = 0x13, eKI_Y = 0x14, eKI_U = 0x15, eKI_I = 0x16, eKI_O = 0x17, eKI_P = 0x18, eKI_LBracket = 0x19, eKI_RBracket = 0x1A, eKI_Enter = 0x1B, eKI_LCtrl = 0x1C, eKI_A = 0x1D, eKI_S = 0x1E, eKI_D = 0x1F, eKI_F = 0x20, eKI_G = 0x21, eKI_H = 0x22, eKI_J = 0x23, eKI_K = 0x24, eKI_L = 0x25, eKI_Semicolon = 0x26,
    m_KeyNames.insert(KeyNamePair(eKI_Escape, "escape"));
    m_KeyNames.insert(KeyNamePair(eKI_1, "1"));
    m_KeyNames.insert(KeyNamePair(eKI_2, "2"));
    m_KeyNames.insert(KeyNamePair(eKI_3, "3"));
    m_KeyNames.insert(KeyNamePair(eKI_4, "4"));
    m_KeyNames.insert(KeyNamePair(eKI_5, "5"));
    m_KeyNames.insert(KeyNamePair(eKI_6, "6"));
    m_KeyNames.insert(KeyNamePair(eKI_7, "7"));
    m_KeyNames.insert(KeyNamePair(eKI_8, "8"));
    m_KeyNames.insert(KeyNamePair(eKI_9, "9"));
    m_KeyNames.insert(KeyNamePair(eKI_0, "0"));
    m_KeyNames.insert(KeyNamePair(eKI_Minus, "minus"));
    m_KeyNames.insert(KeyNamePair(eKI_Equals, "equals"));
    m_KeyNames.insert(KeyNamePair(eKI_Backspace, "backspace"));
    m_KeyNames.insert(KeyNamePair(eKI_Tab, "tab"));
    m_KeyNames.insert(KeyNamePair(eKI_Q, "q"));
    m_KeyNames.insert(KeyNamePair(eKI_W, "w"));
    m_KeyNames.insert(KeyNamePair(eKI_E, "e"));
    m_KeyNames.insert(KeyNamePair(eKI_R, "r"));
    m_KeyNames.insert(KeyNamePair(eKI_T, "t"));
    m_KeyNames.insert(KeyNamePair(eKI_Y, "y"));
    m_KeyNames.insert(KeyNamePair(eKI_U, "u"));
    m_KeyNames.insert(KeyNamePair(eKI_I, "i"));
    m_KeyNames.insert(KeyNamePair(eKI_O, "o"));
    m_KeyNames.insert(KeyNamePair(eKI_P, "p"));
    m_KeyNames.insert(KeyNamePair(eKI_LBracket, "lbracket"));
    m_KeyNames.insert(KeyNamePair(eKI_RBracket, "rbracket"));
    m_KeyNames.insert(KeyNamePair(eKI_Enter, "enter"));
    m_KeyNames.insert(KeyNamePair(eKI_LCtrl, "lctrl"));
    m_KeyNames.insert(KeyNamePair(eKI_A, "a"));
    m_KeyNames.insert(KeyNamePair(eKI_S, "s"));
    m_KeyNames.insert(KeyNamePair(eKI_D, "d"));
    m_KeyNames.insert(KeyNamePair(eKI_F, "f"));
    m_KeyNames.insert(KeyNamePair(eKI_G, "g"));
    m_KeyNames.insert(KeyNamePair(eKI_H, "h"));
    m_KeyNames.insert(KeyNamePair(eKI_J, "j"));
    m_KeyNames.insert(KeyNamePair(eKI_K, "k"));
    m_KeyNames.insert(KeyNamePair(eKI_L, "l"));
    m_KeyNames.insert(KeyNamePair(eKI_Semicolon, "semicolon"));
    // eKI_Apostrophe = 0x27, eKI_Tilde = 0x28, eKI_LShift = 0x29, eKI_Backslash = 0x2A, eKI_Z = 0x2B, eKI_X = 0x2C, eKI_C = 0x2D, eKI_V = 0x2E, eKI_B = 0x2F, eKI_N = 0x30, eKI_M = 0x31, eKI_Comma = 0x32, eKI_Period = 0x33, eKI_Slash = 0x34, eKI_RShift = 0x35, eKI_NP_Multiply = 0x36, eKI_LAlt = 0x37, eKI_Space = 0x38, eKI_CapsLock = 0x39, eKI_F1 = 0x3A, eKI_F2 = 0x3B, eKI_F3 = 0x3C, eKI_F4 = 0x3D, eKI_F5 = 0x3E, eKI_F6 = 0x3F, eKI_F7 = 0x40, eKI_F8 = 0x41, eKI_F9 = 0x42, eKI_F10 = 0x43, eKI_NumLock = 0x44, eKI_ScrollLock = 0x45, eKI_NP_7 = 0x46, eKI_NP_8 = 0x47, eKI_NP_9 = 0x48, eKI_NP_Substract = 0x49, eKI_NP_4 = 0x4A, eKI_NP_5 = 0x4B, eKI_NP_6 = 0x4C, eKI_NP_Add = 0x4D, eKI_NP_1 = 0x4E, eKI_NP_2 = 0x4F, eKI_NP_3 = 0x50, eKI_NP_0 = 0x51, eKI_F11 = 0x52, eKI_F12 = 0x53, eKI_F13 = 0x54, eKI_F14 = 0x55, eKI_F15 = 0x56,
    m_KeyNames.insert(KeyNamePair(eKI_Apostrophe, "apostrophe"));
    m_KeyNames.insert(KeyNamePair(eKI_Tilde, "tilde"));
    m_KeyNames.insert(KeyNamePair(eKI_LShift, "lshift"));
    m_KeyNames.insert(KeyNamePair(eKI_Backslash, "backslash"));
    m_KeyNames.insert(KeyNamePair(eKI_Z, "z"));
    m_KeyNames.insert(KeyNamePair(eKI_X, "x"));
    m_KeyNames.insert(KeyNamePair(eKI_C, "c"));
    m_KeyNames.insert(KeyNamePair(eKI_V, "v"));
    m_KeyNames.insert(KeyNamePair(eKI_B, "b"));
    m_KeyNames.insert(KeyNamePair(eKI_N, "n"));
    m_KeyNames.insert(KeyNamePair(eKI_M, "m"));
    m_KeyNames.insert(KeyNamePair(eKI_Comma, "comma"));
    m_KeyNames.insert(KeyNamePair(eKI_Period, "period"));
    m_KeyNames.insert(KeyNamePair(eKI_Slash, "slash"));
    m_KeyNames.insert(KeyNamePair(eKI_RShift, "rshift"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_Multiply, "np_multiply"));
    m_KeyNames.insert(KeyNamePair(eKI_LAlt, "lalt"));
    m_KeyNames.insert(KeyNamePair(eKI_Space, "space"));
    m_KeyNames.insert(KeyNamePair(eKI_CapsLock, "capslock"));
    m_KeyNames.insert(KeyNamePair(eKI_F1, "f1"));
    m_KeyNames.insert(KeyNamePair(eKI_F2, "f2"));
    m_KeyNames.insert(KeyNamePair(eKI_F3, "f3"));
    m_KeyNames.insert(KeyNamePair(eKI_F4, "f4"));
    m_KeyNames.insert(KeyNamePair(eKI_F5, "f5"));
    m_KeyNames.insert(KeyNamePair(eKI_F6, "f6"));
    m_KeyNames.insert(KeyNamePair(eKI_F7, "f7"));
    m_KeyNames.insert(KeyNamePair(eKI_F8, "f8"));
    m_KeyNames.insert(KeyNamePair(eKI_F9, "f9"));
    m_KeyNames.insert(KeyNamePair(eKI_F10, "f10"));
    m_KeyNames.insert(KeyNamePair(eKI_NumLock, "numlock"));
    m_KeyNames.insert(KeyNamePair(eKI_ScrollLock, "scrolllock"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_7, "np_7"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_8, "np_8"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_9, "np_9"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_Substract, "np_substract"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_4, "np_4"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_5, "np_5"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_6, "np_6"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_Add, "np_add"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_1, "np_1"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_2, "np_2"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_3, "np_3"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_0, "np_0"));
    m_KeyNames.insert(KeyNamePair(eKI_F11, "f11"));
    m_KeyNames.insert(KeyNamePair(eKI_F12, "f12"));
    m_KeyNames.insert(KeyNamePair(eKI_F13, "f13"));
    m_KeyNames.insert(KeyNamePair(eKI_F14, "f14"));
    m_KeyNames.insert(KeyNamePair(eKI_F15, "f15"));
   // eKI_Colon = 0x57, eKI_Underline = 0x58, eKI_NP_Enter = 0x59, eKI_RCtrl = 0x5A, eKI_NP_Period = 0x5B, eKI_NP_Divide = 0x5C, eKI_Print = 0x5D, eKI_RAlt = 0x5E, eKI_Pause = 0x5F, eKI_Home = 0x60, eKI_Up = 0x61, eKI_PgUp = 0x62, eKI_Left = 0x63, eKI_Right = 0x64, eKI_End = 0x65, eKI_Down = 0x66, eKI_PgDn = 0x67, eKI_Insert = 0x68, eKI_Delete = 0x69, eKI_LWin = 0x6A, eKI_RWin = 0x6B,
    m_KeyNames.insert(KeyNamePair(eKI_NP_Enter, "np_enter"));
    m_KeyNames.insert(KeyNamePair(eKI_RCtrl, "rctrl"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_Period, "np_period"));
    m_KeyNames.insert(KeyNamePair(eKI_NP_Divide, "np_divide"));
    m_KeyNames.insert(KeyNamePair(eKI_Print, "print"));
    m_KeyNames.insert(KeyNamePair(eKI_RAlt, "ralt"));
    m_KeyNames.insert(KeyNamePair(eKI_Pause, "pause"));
    m_KeyNames.insert(KeyNamePair(eKI_Home, "home"));
    m_KeyNames.insert(KeyNamePair(eKI_Up, "up"));
    m_KeyNames.insert(KeyNamePair(eKI_PgUp, "pgup"));
    m_KeyNames.insert(KeyNamePair(eKI_Left, "left"));
    m_KeyNames.insert(KeyNamePair(eKI_Right, "right"));
    m_KeyNames.insert(KeyNamePair(eKI_End, "end"));
    m_KeyNames.insert(KeyNamePair(eKI_Down, "down"));
    m_KeyNames.insert(KeyNamePair(eKI_PgDn, "pgdn"));
    m_KeyNames.insert(KeyNamePair(eKI_Insert, "insert"));
    m_KeyNames.insert(KeyNamePair(eKI_Delete, "delete"));
    m_KeyNames.insert(KeyNamePair(eKI_LWin, "lwin"));
    m_KeyNames.insert(KeyNamePair(eKI_RWin, "rwin"));
}

void ChairLoader::RegisterMods()
{
	auto cfgValue = gConf->getConfigValue(chairloaderModName, "ModList");

	if (cfgValue.type() != typeid(pugi::xml_node))
	{
		CryWarning("ModList is not a node in the config.");
		return;
	}

	auto node = boost::get<pugi::xml_node>(cfgValue);
	for (pugi::xml_node& mod : node) {
		auto modName = boost::get<std::string>(gConf->getNodeConfigValue(mod, "modName"));
		if (mod.child("enabled").text().as_bool()) {
			if (mod.child("dllName"))
			{
				CryLog("Found DLL mod: %s", modName.c_str());
				m_pModDllManager->RegisterModFromXML(mod);
			}

			fs::path modDirPath = fs::current_path() / "Mods" / fs::u8path(modName);
			fs::path shadersPath = modDirPath / "Shaders";
			if (fs::exists(shadersPath))
			{
				CryLog("Found Shader mod: %s", modName.c_str());
				RenderDll::Shaders::ShaderPaths::Get().AddShadersDir(shadersPath);
			}
		}
	}

	RenderDll::Shaders::ShaderPaths::Get().RefreshFileList();
}

void ChairLoader::loadConfigParameters() {
    // Hide GUI Key, default = f1
    auto key = gConf->getConfigValue(chairloaderModName, "HideGUIKey");
    if(key.type() == typeid(std::string)){
        auto keyName = boost::get<std::string>(key);
        std::transform(keyName.begin(), keyName.end(), keyName.begin(), ::tolower);
        if(m_KeyNames.right.find(keyName) != m_KeyNames.right.end()){
            // Load Key into file
            auto keyCode = m_KeyNames.right.at(keyName);
            m_hideGuiKey = keyCode;
            CryLog("Chairloader: Hide GUI Key set to %s", keyName.c_str());
        } else {
            // Key was an invalid string, reset to default
            CryError("Chairloader: Invalid HideGUIKey string '%s', setting to default", keyName.c_str());
            m_hideGuiKey = eKI_F1;
            gConf->setConfigValue(chairloaderModName, "HideGUIKey", m_KeyNames.left.at(m_hideGuiKey), IChairloaderConfigManager::parameterType::String);
        }
    } else {
        // Key config parameter was not found, set to default
        CryError("Chairloader: HideGUIKey config parameter not found, setting to default");
        m_hideGuiKey = eKI_F1;
        gConf->setConfigValue(chairloaderModName, "HideGUIKey", m_KeyNames.left.at(m_hideGuiKey), IChairloaderConfigManager::parameterType::String);
    }
    // toggle freecam key, default = f2
    key = gConf->getConfigValue(chairloaderModName, "ToggleFreecamKey");
    if(key.type() == typeid(std::string)){
        auto keyName = boost::get<std::string>(key);
        std::transform(keyName.begin(), keyName.end(), keyName.begin(), ::tolower);
        if(m_KeyNames.right.find(keyName) != m_KeyNames.right.end()){
            // Load Key into file
            auto keyCode = m_KeyNames.right.at(keyName);
            m_toggleFreecamKey = keyCode;
            CryLog("Chairloader: Toggle Freecam Key set to %s", keyName.c_str());
        } else {
            // Key was an invalid string, reset to default
            CryError("Chairloader: Invalid ToggleFreecamKey string '%s', setting to default", keyName.c_str());
            m_toggleFreecamKey = eKI_F2;
            gConf->setConfigValue(chairloaderModName, "ToggleFreecamKey", m_KeyNames.left.at(m_toggleFreecamKey), IChairloaderConfigManager::parameterType::String);
        }
    } else {
        // Key config parameter was not found, set to default
        CryError("Chairloader: ToggleFreecamKey config parameter not found, setting to default");
        m_toggleFreecamKey = eKI_F2;
        gConf->setConfigValue(chairloaderModName, "ToggleFreecamKey", m_KeyNames.left.at(m_toggleFreecamKey), IChairloaderConfigManager::parameterType::String);
    }
}

std::string ChairLoader::getKeyBind(std::string action) {
    if(action == "HideGUIKey"){
        return m_KeyNames.left.at(m_hideGuiKey);
    } else if(action == "ToggleFreecamKey"){
        return m_KeyNames.left.at(m_toggleFreecamKey);
    } else {
        return "";
    }
    return std::string();
}

bool ChairLoader::IsEditorEnabled()
{
	return m_bEditorEnabled;
}

void ChairLoader::ReloadModDLLs()
{
	// Mods may hook code running in other threads. Make sure as many of them as possible are idle.
	// Wait for render thread to finish
	auto rd = static_cast<CD3D9Renderer*>(gEnv->pRenderer);
	rd->m_pRT->SyncMainWithRender(); // Last frame
	rd->m_pRT->SyncMainWithRender(); // This frame
	RenderDll::SetRenderThreadIsIdle(true);

	m_pModDllManager->ReloadModules();

	RenderDll::SetRenderThreadIsIdle(false);
}

bool ChairLoader::CheckDLLsForChanges()
{
	return m_pModDllManager->CheckModulesForChanges();
}
