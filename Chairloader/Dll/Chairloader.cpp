#include <fmt/format.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/CryGame/Game.h>
#include <Prey/CryEntitySystem/EntitySystem.h>
#include <Prey/CryAction/CryAction.h>
#include <Chairloader/Hooks/HookTransaction.h>
#include <Chairloader/PreyFunction.h>
#include <Chairloader/ChairloaderEnv.h>
#include <Chairloader/IChairloaderMod.h>
#include <Chairloader/IModDllManager.h>
#include "ImportantClass.h"
#include <mem.h>
#include "Chairloader.h"
#include <Chairloader/IChairVarManager.h>
#include <Chairloader/ChairXmlUtils.h>

#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <detours/detours.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Chairloader/ModSDK/ChairGlobalModName.h>

static ChairloaderGlobalEnvironment s_CLEnv;
static std::unique_ptr<Chairloader> gChairloaderDll;

Internal::IChairloaderDll* gChair = nullptr;
ChairloaderGlobalEnvironment* gCL = &s_CLEnv;

static int CV_cl_asserts;
static ChairXmlUtils g_XmlUtils;

static std::unique_ptr<ImportantListener> g_ImportantListener;

namespace
{

//-----------------------------------------------------------------
// CSystem
//-----------------------------------------------------------------
FunctionHook<decltype(CSystem::FInitializeEngineModule)::Type> g_CSystem_InitializeEngineModule_Hook;
auto g_CSystem_Shutdown_Hook = CSystem::FShutdown.MakeHook();
auto g_CSystem_Update_Hook = CSystem::FUpdate.MakeHook();

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
		gChairloaderDll->InitSystem(_this);
	}

	return g_CSystem_InitializeEngineModule_Hook.InvokeOrig(_this, _initInfo, initParams, bQuitIfNotFound);
}

void CSystem_Shutdown_Hook(CSystem* _this)
{
	gChairloaderDll->ShutdownSystem();
	g_CSystem_Shutdown_Hook.InvokeOrig(_this);

	// Shutdown Chairloader for good
	gChairloaderDll = nullptr;
}

bool CSystem_Update_Hook(CSystem* const _this, int updateFlags, int nPauseMode)
{
	bool result = g_CSystem_Update_Hook.InvokeOrig(_this, updateFlags, nPauseMode);
	gChairloaderDll->MainUpdate(updateFlags);
	return result;
}

//-----------------------------------------------------------------
// CGame
//-----------------------------------------------------------------
auto g_CGame_Init_Hook = CGame::FInit.MakeHook();
auto g_CGame_Update_Hook = CGame::FUpdate.MakeHook();
auto g_CGame_Shutdown_Hook = CGame::FShutdown.MakeHook();

bool CGame_Init_Hook(CGame* _this, IGameFramework* pFramework)
{
	g_pGame = _this;

	gChairloaderDll->PreInitGame(_this, pFramework);

	bool result = g_CGame_Init_Hook.InvokeOrig(_this, pFramework);

	if (result)
		gChairloaderDll->InitGame(_this, pFramework);

	return result;
}

int CGame_Update_Hook(CGame* _this, bool haveFocus, unsigned int updateFlags)
{
	gChairloaderDll->UpdateBeforeSystem(updateFlags);
	int result = g_CGame_Update_Hook.InvokeOrig(_this, haveFocus, updateFlags);
	return result;
}

void CGame_Shutdown_Hook(CGame* _this)
{
	gChairloaderDll->ShutdownGame();
	g_CGame_Shutdown_Hook.InvokeOrig(_this);
}

//-----------------------------------------------------------------
// CEntitySystem
//-----------------------------------------------------------------
auto g_CEntitySystem_PrePhysicsUpdate_Hook = CEntitySystem::FPrePhysicsUpdate.MakeHook();

void CEntitySystem_PrePhysicsUpdate_Hook(CEntitySystem* _this)
{
	gChairloaderDll->UpdateBeforePhysics();
	g_CEntitySystem_PrePhysicsUpdate_Hook.InvokeOrig(_this);
}

//-----------------------------------------------------------------
// CCryAction
//-----------------------------------------------------------------
auto g_CCryAction_FPostUpdate_Hook = CCryAction::FPostUpdate.MakeHook();

void CCryAction_FPostUpdate_Hook(CCryAction* const _this, bool haveFocus, unsigned updateFlags)
{
	gChairloaderDll->LateUpdate(updateFlags);
	g_CCryAction_FPostUpdate_Hook.InvokeOrig(_this, haveFocus, updateFlags);
}


//-----------------------------------------------------------------
// ImportantClass
//-----------------------------------------------------------------

auto g_CEntitySystem_FOnLevelEnd_Hook = CEntitySystem::FOnLevelEnd.MakeHook();

void CEntitySystem_FOnLevelEnd_Hook(CEntitySystem* _this) {
    ImportantClass::DestroyImportantObject();
    g_CEntitySystem_FOnLevelEnd_Hook.InvokeOrig(_this);
}


} // namespace

void Chairloader::CreateInstance(void* hThisDll)
{
	gChairloaderDll = std::make_unique<Chairloader>(hThisDll);
}

Chairloader* Chairloader::Get()
{
	return gChairloaderDll.get();
}

Chairloader::Chairloader(void* hThisDll) {
	m_hThisDll = hThisDll;
	gChair = this;
	m_WinConsole.InitConsole();
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
	HookTransaction hookTr;
	g_CSystem_InitializeEngineModule_Hook.InstallHook(CSystem::FInitializeEngineModule.Get(), &CSystem_InitializeEngineModule_Hook);
	hookTr.CommitOrDie();

	// Instantiate modules
	m_pCore = Internal::IChairloaderCore::CreateInstance();
	m_pRender = Internal::IChairloaderCryRender::CreateInstance();
	m_pTools = Internal::IChairloaderTools::CreateInstance();
}

Chairloader::~Chairloader()
{
	// Free modules
	m_pRender = nullptr;
	m_pCore = nullptr;

	// Remove all installed hooks
	try
	{
		HookTransaction hookTr;
		PreyFunctionSystem::RemoveHooks();
		hookTr.Commit();
	}
	catch (const std::exception& e)
	{
		// Can't handle the error any further than log it.
		CryError("Failed to remove hooks:\n{}", e.what());
	}

	m_WinConsole.ShutdownConsole();

	FreeConsole();
	gChair = nullptr;
}

void Chairloader::InitSystem(CSystem* pSystem)
{
	gCL->cl = this;
	gCL->pXmlUtils = &g_XmlUtils;
	ModuleInitISystem(pSystem, "Chairloader");
	ModuleInitIChairLogger("Chairloader");
	m_WinConsole.InitSystem();
	CryLog("Chairloader::InitSystem");
	CryLog("Chairloader: gEnv = 0x{:p}\n", (void*)gEnv);
    ChairSetGlobalModName("Chairloader");
	// Increase log verbosity: messages, warnings, errors.
	// Max level is 4 (eComment) but it floods the console.
	gEnv->pConsole->ExecuteString("log_Verbosity 3");

	// Editor cmd line switch
	m_bEditorEnabled = pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "editor");
	if (m_bEditorEnabled)
	{
		// Dev mode is always enabled in Editor.
		pSystem->SetDevMode(true);
        m_bTrainerEnabled = true;
	}
	else if (!pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "nodevmode"))
	{
		bool devMode = false;
#ifdef DEBUG_BUILD
		// Activate dev mode in debug build
		devMode = true;
        m_bTrainerEnabled = true;
#else
		// Activate dev mode if user requested it
		devMode = pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "devmode") != nullptr;
        m_bTrainerEnabled = pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "trainer");
#endif
		pSystem->SetDevMode(devMode);
	}

	// Register assert cvar
#ifdef DEBUG_BUILD
	const bool defaultAsserts = true;
#else
	const bool defaultAsserts = pSystem->IsDevMode();
#endif
	REGISTER_CVAR2("cl_asserts", &CV_cl_asserts, defaultAsserts, VF_CHEAT,
		"0 = Disable Asserts\n"
		"1 = Enable Asserts\n"
	);
	CryAssertSetGlobalFlagAddress(GetAssertFlagAddress());

	// Disabling audio speeds up loading immensely (8 seconds on my hardware)
	if (pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "noaudio"))
		pSystem->m_sys_audio_disable->Set(1);

	InitPaths();

	// Initialize Core
	m_pCore->InitSystem();

	// Initialize Patches
	if (!pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "nopatches"))
	{
		m_pPatches = Internal::IChairloaderPatches::CreateInstance();
		m_pPatches->InitSystem();
	}
	else
	{
		CryLog("Optional patches disabled via command line");
	}

	// Initialize Tools
	Internal::SToolsInitParams toolsParams;
	toolsParams.bEnableEditor = m_bEditorEnabled;
	toolsParams.bEnableTrainer = m_bTrainerEnabled;
	m_pTools->InitSystem(toolsParams);

	// Register mods
	m_pCore->RegisterMods();

	// Init renderer patches. Must be done after shader mods are registered.
	Internal::SCryRenderInitParams renderParams;
	renderParams.bEnableAuxGeom = gEnv->pSystem->IsDevMode();
	m_pRender->SetRenderThreadIsIdle(true);
	m_pRender->InitSystem(renderParams);

	// Install hooks late into init, some SetHookFunc calls depend on cmd line or mods
	InitHooks();
	InstallHooks();

	// Load DLL mods
	m_pCore->GetDllManager()->LoadModules();
	m_pCore->GetDllManager()->CallInitSystem();
    m_pCore->GetDllManager()->CallConnect();

	m_pRender->SetRenderThreadIsIdle(false);

    g_ImportantListener = std::make_unique<ImportantListener>();
}

void Chairloader::PreInitGame(CGame* pGame, IGameFramework* pFramework)
{
	CryLog("Chairloader::PreInitGame");
	m_pGame = pGame;
	m_pFramework = pFramework;
	gChairloaderDll->GetCore()->PreInitGame();
}

void Chairloader::InitGame(CGame* pGame, IGameFramework* pFramework)
{
	CryLog("Chairloader::InitGame");

	gRenDev->m_pRT->SyncMainWithRender();
	gRenDev->m_pRT->SyncMainWithRender();
	m_pRender->SetRenderThreadIsIdle(true);
	m_pCore->InitGame();
	m_pRender->InitGame();

	if (m_pPatches)
		m_pPatches->InitGame();

	m_pTools->InitGame();
	m_pCore->GetDllManager()->CallInitGame();
	m_pRender->SetRenderThreadIsIdle(false);
}

void Chairloader::ShutdownGame()
{
	CryLog("Chairloader::ShutdownGame");

	gRenDev->m_pRT->SyncMainWithRender();
	gRenDev->m_pRT->SyncMainWithRender();
	m_pRender->SetRenderThreadIsIdle(true);

	m_pCore->GetDllManager()->CallShutdownGame();
	m_pTools->ShutdownGame();
	m_pRender->ShutdownGame();

	// Destroy tools before ImGui
	m_pTools = nullptr;

	if (m_pPatches)
		m_pPatches->ShutdownGame();

	m_pCore->ShutdownGame();
	m_pFramework = nullptr;

	m_pRender->SetRenderThreadIsIdle(false);
}

void Chairloader::ShutdownSystem()
{
	CryLog("Chairloader::ShutdownGame");
	
	m_pRender->SetRenderThreadIsIdle(true);

	m_pCore->GetDllManager()->CallShutdownSystem();
	m_pCore->GetDllManager()->UnloadModules();

	if (m_pPatches)
		m_pPatches->ShutdownGame();

	m_pRender->ShutdownSystem();
	m_pCore->ShutdownSystem();

	m_pRender->SetRenderThreadIsIdle(false);
	gEnv = nullptr;
}

void Chairloader::UpdateBeforeSystem(unsigned updateFlags)
{
	m_SavedUpdateFlags = updateFlags;
	m_pCore->UpdateBeforeSystem(updateFlags);
	m_pRender->UpdateBeforeSystem(updateFlags);
	m_pTools->UpdateBeforeSystem(updateFlags);

	// Tools update MUST come before mod PreUpdate for proper hot-reloading in the Editor
	m_pCore->GetDllManager()->CallUpdateBeforeSystem(updateFlags);
}

void Chairloader::UpdateBeforePhysics()
{
	unsigned updateFlags = m_SavedUpdateFlags;
	m_pCore->UpdateBeforePhysics(updateFlags);
	m_pRender->UpdateBeforePhysics(updateFlags);
	m_pTools->UpdateBeforePhysics(updateFlags);
	m_pCore->GetDllManager()->CallUpdateBeforePhysics(updateFlags);
}

void Chairloader::MainUpdate(unsigned updateFlags)
{
	m_pCore->MainUpdate(updateFlags);
	m_pRender->MainUpdate(updateFlags);

	if (m_pPatches)
		m_pPatches->MainUpdate(updateFlags);

	m_pTools->MainUpdate(updateFlags);

	if (gCL->gui->IsEnabled())
		m_pCore->GetDllManager()->CallDraw();

	m_pCore->GetDllManager()->CallMainUpdate(updateFlags);
}

void Chairloader::LateUpdate(unsigned updateFlags)
{
	m_pCore->LateUpdate(updateFlags);
	m_pRender->LateUpdate(updateFlags);
	m_pTools->LateUpdate(updateFlags);
	m_pCore->GetDllManager()->CallLateUpdate(updateFlags);
}

void Chairloader::InitHooks()
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
	g_CSystem_Update_Hook.SetHookFunc(&CSystem_Update_Hook);
	g_CGame_Init_Hook.SetHookFunc(&CGame_Init_Hook);
	g_CGame_Update_Hook.SetHookFunc(&CGame_Update_Hook);
	g_CGame_Shutdown_Hook.SetHookFunc(&CGame_Shutdown_Hook);
	g_CEntitySystem_PrePhysicsUpdate_Hook.SetHookFunc(&CEntitySystem_PrePhysicsUpdate_Hook);
	g_CCryAction_FPostUpdate_Hook.SetHookFunc(&CCryAction_FPostUpdate_Hook);
    g_CEntitySystem_FOnLevelEnd_Hook.SetHookFunc(&CEntitySystem_FOnLevelEnd_Hook);
	// DeviceInfo::CreateDevice: Remove D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY flag
	// Allows graphics debuggers to be attached
	{
		uint8_t bytes[] = { 0x00, 0x08 };
		uint8_t* base = (uint8_t*)GetModuleBase();
		mem::Patch(base + 0xF240CD, bytes + 0, 1);
		mem::Patch(base + 0xF240E0, bytes + 1, 1);
	}
}

void Chairloader::InitPaths()
{
	if (false)
	{
		// Preditor code will go here...
	}
	else
	{
		auto fnReadFromCmdLineOrDefault = [](fs::path& outPath, const char* cmdArg, const char* defaultName)
		{
			const ICmdLineArg* pArg = gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, cmdArg);

			if (pArg)
			{
				// Use the path from command line
				outPath = fs::u8path(pArg->GetValue());

				if (outPath.is_relative())
					outPath = fs::current_path() / outPath;

				if (!fs::exists(outPath) || !fs::is_directory(outPath))
				{
					CryFatalError("Path supplied to -{} doesn't exist or not valid.\n"
						"It must point to an existing directory.\n\n"
						"Path:\n"
						"{}",
						cmdArg, outPath.u8string()
					);
				}
			}
			else
			{
				// Use default path
				outPath = fs::current_path() / fs::u8path(defaultName);
				fs::create_directories(outPath);
			}
		};

		// I thought the config dir was next to Mods, so I made this extendable.
		// Turned out it was in Mods. Well, I'm not rewriting this. - tmp64
		fnReadFromCmdLineOrDefault(m_ModsDirPath, "chair_mods_path", "Mods");
	}

	CryLog("Mods Path: {}", m_ModsDirPath.u8string());

	// Create config fir
	std::error_code ec;
	fs::path configDirPath = m_ModsDirPath / "config";
	fs::create_directory(configDirPath, ec);

	if (ec)
	{
		CryFatalError("Failed to create config directory.\n\n"
			"Path: {}\n"
			"Reason: {}",
			configDirPath.u8string(), ec.message()
		);
	}
}

void Chairloader::InstallHooks()
{
	HookTransaction hookTr;
	PreyFunctionSystem::InstallHooks();
	hookTr.CommitOrDie();
}

bool Chairloader::HandleKeyPress(const SInputEvent &event) {
	if (m_pCore->HandleKeyPress(event))
		return true;
	if (m_pRender->HandleKeyPress(event))
		return true;
	if (m_pTools->HandleKeyPress(event))
		return true;
	return false;
}

//! this function is needed because bimaps don't handle static initialization very well
void Chairloader::LoadKeyNames() {
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
    m_KeyNames.insert(KeyNamePair(eKI_Minus, "-"));
    m_KeyNames.insert(KeyNamePair(eKI_Equals, "="));
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
    m_KeyNames.insert(KeyNamePair(eKI_LBracket, "["));
    m_KeyNames.insert(KeyNamePair(eKI_RBracket, "]"));
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
    m_KeyNames.insert(KeyNamePair(eKI_Semicolon, ";"));
    // eKI_Apostrophe = 0x27, eKI_Tilde = 0x28, eKI_LShift = 0x29, eKI_Backslash = 0x2A, eKI_Z = 0x2B, eKI_X = 0x2C, eKI_C = 0x2D, eKI_V = 0x2E, eKI_B = 0x2F, eKI_N = 0x30, eKI_M = 0x31, eKI_Comma = 0x32, eKI_Period = 0x33, eKI_Slash = 0x34, eKI_RShift = 0x35, eKI_NP_Multiply = 0x36, eKI_LAlt = 0x37, eKI_Space = 0x38, eKI_CapsLock = 0x39, eKI_F1 = 0x3A, eKI_F2 = 0x3B, eKI_F3 = 0x3C, eKI_F4 = 0x3D, eKI_F5 = 0x3E, eKI_F6 = 0x3F, eKI_F7 = 0x40, eKI_F8 = 0x41, eKI_F9 = 0x42, eKI_F10 = 0x43, eKI_NumLock = 0x44, eKI_ScrollLock = 0x45, eKI_NP_7 = 0x46, eKI_NP_8 = 0x47, eKI_NP_9 = 0x48, eKI_NP_Substract = 0x49, eKI_NP_4 = 0x4A, eKI_NP_5 = 0x4B, eKI_NP_6 = 0x4C, eKI_NP_Add = 0x4D, eKI_NP_1 = 0x4E, eKI_NP_2 = 0x4F, eKI_NP_3 = 0x50, eKI_NP_0 = 0x51, eKI_F11 = 0x52, eKI_F12 = 0x53, eKI_F13 = 0x54, eKI_F14 = 0x55, eKI_F15 = 0x56,
    m_KeyNames.insert(KeyNamePair(eKI_Apostrophe, "'"));
    m_KeyNames.insert(KeyNamePair(eKI_Tilde, "~"));
    m_KeyNames.insert(KeyNamePair(eKI_LShift, "lshift"));
    m_KeyNames.insert(KeyNamePair(eKI_Backslash, "\\"));
    m_KeyNames.insert(KeyNamePair(eKI_Z, "z"));
    m_KeyNames.insert(KeyNamePair(eKI_X, "x"));
    m_KeyNames.insert(KeyNamePair(eKI_C, "c"));
    m_KeyNames.insert(KeyNamePair(eKI_V, "v"));
    m_KeyNames.insert(KeyNamePair(eKI_B, "b"));
    m_KeyNames.insert(KeyNamePair(eKI_N, "n"));
    m_KeyNames.insert(KeyNamePair(eKI_M, "m"));
    m_KeyNames.insert(KeyNamePair(eKI_Comma, ","));
    m_KeyNames.insert(KeyNamePair(eKI_Period, "."));
    m_KeyNames.insert(KeyNamePair(eKI_Slash, "/"));
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

void Chairloader::GetModSdkVersion(int& major, int& minor, int& patch)
{
	major = MOD_SDK_VERSION_MAJOR;
	minor = MOD_SDK_VERSION_MINOR;
	patch = MOD_SDK_VERSION_PATCH;
}

ChairloaderGlobalEnvironment* Chairloader::GetChairloaderEnvironment() {
	return gCL;
}

uintptr_t Chairloader::GetPreyDllBase()
{
	return GetModuleBase();
}

std::unique_ptr<IChairLogger> Chairloader::CreateLogger()
{
	return m_pCore->CreateLogger();
}

bool Chairloader::IsEditorEnabled()
{
	return m_bEditorEnabled;
}

CGame* Chairloader::GetCGame()
{
	return m_pGame;
}

int* Chairloader::GetAssertFlagAddress()
{
	return &CV_cl_asserts;
}

void Chairloader::ReloadModDLLs()
{
	// Mods may hook code running in other threads. Make sure as many of them as possible are idle.
	// Wait for render thread to finish
	auto rd = static_cast<CD3D9Renderer*>(gEnv->pRenderer);
	rd->m_pRT->SyncMainWithRender(); // Last frame
	rd->m_pRT->SyncMainWithRender(); // This frame
	m_pRender->SetRenderThreadIsIdle(true);

	m_pCore->GetDllManager()->ReloadModules();

	m_pRender->SetRenderThreadIsIdle(false);
}

void Chairloader::RegisterCVar(ICVar *pCVar, std::string &modName) {
    //TODO: do things
    if(pCVar == nullptr) {
        CryError("Attempted to register a null cvar for {}", modName);
        return;
    }
    if(pCVar->GetFlags() & VF_DUMPTOCHAIR) {
        CryLog("Registering CVar {} for {}", pCVar->GetName(), modName);
        m_pCore->GetCVarManager()->RegisterCVar(pCVar, modName);
    }
}

const fs::path& Chairloader::GetModsPath()
{
	return m_ModsDirPath;
}
