#include <Prey/CryCore/Platform/platform_impl.inl>
#include <filesystem>
#include <Prey/CryInput/IInput.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/CryGame/Game.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerSmokeForm.h>
#include <Prey/GameDll/ark/player/arkplayermovementstates.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <ChairLoader/PreyFunction.h>
#include "ChairLoader.h"
#include "EntityUtils.h"
#include "ChairloaderGui.h"
#include "Profiler.h"
#include <Prey/CryCore/Platform/CryWindows.h>
#include <detours/detours.h>
#include "ChairLoader/ChairloaderEnv.h"
#include "RenderDll/RenderAuxGeomPatch.h"
#include <Prey/CryRenderer/IRenderAuxGeom.h>

ChairLoader *gCL = nullptr;
static bool smokeFormExited = false;
static ChairloaderGlobalEnvironment s_CLEnv;



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

auto g_CSystem_InitializeEngineModule_Hook = CSystem::FInitializeEngineModule.MakeHook();
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
		gCL->InitSystem(_this);
	}

	return g_CSystem_InitializeEngineModule_Hook.InvokeOrig(_this, _initInfo, initParams, bQuitIfNotFound);
}

void CSystem_Shutdown_Hook(CSystem* _this)
{
	gCL->ShutdownSystem();
	g_CSystem_Shutdown_Hook.InvokeOrig(_this);

	// Shutdown ChairLoader for good
	delete gCL;
	gCL = nullptr;
}

bool CGame_Init_Hook(CGame* _this, IGameFramework* pFramework)
{
	bool result = g_CGame_Init_Hook.InvokeOrig(_this, pFramework);

	if (result)
		gCL->InitGame(pFramework);

	return result;
}

int CGame_Update_Hook(CGame* _this, bool haveFocus, unsigned int updateFlags)
{
	gCL->PreUpdate(haveFocus, updateFlags);
	int result = g_CGame_Update_Hook.InvokeOrig(_this, haveFocus, updateFlags);
	gCL->PostUpdate(haveFocus, updateFlags);
	return result;
}

void CGame_Shutdown_Hook(CGame* _this)
{
	gCL->ShutdownGame();
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
	g_CSystem_InitializeEngineModule_Hook.SetHookFunc(&CSystem_InitializeEngineModule_Hook);
	g_CSystem_Shutdown_Hook.SetHookFunc(&CSystem_Shutdown_Hook);
	g_CGame_Init_Hook.SetHookFunc(&CGame_Init_Hook);
	g_CGame_Update_Hook.SetHookFunc(&CGame_Update_Hook);
	g_CGame_Shutdown_Hook.SetHookFunc(&CGame_Shutdown_Hook);
	g_SmokeForm_Exit_hook.SetHookFunc(&SmokeForm_Exit_Hook);
	ChairLoaderImGui::InitHooks();
	InitRenderAuxGeomPatchHooks();

	// Install all hooks
	PreyFunctionSystem::Init(m_ModuleBase);
	InstallHooks();
}

void ChairLoader::InitSystem(CSystem* pSystem)
{
	ModuleInitISystem(pSystem, "ChairLoader");
	g_StdoutConsole.Init();
	CryLog("ChairLoader::InitSystem");
	CryLog("ChairLoader: gEnv = 0x%p\n", gEnv);

	// Increase log verbosity: messages, warnings, errors.
	// Max level is 4 (eComment) but it floods the console.
	gEnv->pConsole->ExecuteString("log_Verbosity 3");

	if (!pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "nodevmode"))
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

	WaitForRenderDoc();

	m_MainThreadId = std::this_thread::get_id();
	gConf = new ChairloaderConfigManager();
	s_CLEnv.conf = gConf;
	CryLog("Chairloader config loaded: %u", gConf->loadModConfigFile(chairloaderModName));

	InitRenderAuxGeomPatch();

	// get list of installed mods and their load order
	ReadModList();
	// load the DLLs and register the mods
	initializeMods();
	// load the config files into the config manager
	loadAllConfigs();
	// run each mod InitSystem()
	for(auto mod: modList) {
		mod.pMod->InitSystem(pSystem, GetModuleBase());
	}
}


void ChairLoader::InitGame(IGameFramework* pFramework)
{
	CryLog("ChairLoader::InitGame");
	m_pFramework = pFramework;
	gEntUtils = new EntityUtils();
	m_ImGui = std::make_unique<ChairLoaderImGui>();
	gui = new ChairloaderGui(&s_CLEnv);
	g_pProfiler = new Profiler();

	s_CLEnv.cl = this;
	s_CLEnv.pImGui = m_ImGui.get();
	s_CLEnv.gui = gui;
	s_CLEnv.entUtils = gEntUtils;

	// run each mod InitGame();
	for (auto& mod : modList) {
		mod.pMod->InitGame(pFramework, this);
	}
}

void ChairLoader::ShutdownGame()
{
	CryLog("ChairLoader::ShutdownGame");

	// Shutdown all mods in reverse order
	for (auto it = modList.rbegin(); it != modList.rend(); ++it)
	{
		it->pMod->ShutdownGame();
	}

	m_ImGui = nullptr;
	m_pFramework = nullptr;
}

void ChairLoader::ShutdownSystem()
{
	CryLog("ChairLoader::ShutdownSystem");
	
	// Shutdown all mods in reverse order
	for (auto it = modList.rbegin(); it != modList.rend(); ++it)
	{
		it->pMod->ShutdownSystem();
	}

	// Unload mods
	for (auto it = modList.rbegin(); it != modList.rend(); ++it)
	{
		it->pMod = nullptr;
		it->pfnShutdown();
		it->pfnShutdown = nullptr;
		it->pfnInit = nullptr;
		FreeLibrary(it->hModule);
		it->hModule = nullptr;
	}

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
	m_ImGui->PreUpdate(haveFocus);
	UpdateFreeCam();
	SmokeFormExit();
	gui->update();
	gConf->Update();

	// pre update all mods
	for (auto& mod : modList) {
		mod.pMod->PreUpdate();
	}

	bool todo = true;
	gui->draw(&todo);

	// draw all mods
	for (auto& mod : modList) {
		mod.pMod->Draw();
	}
}

void ChairLoader::PostUpdate(bool haveFocus, unsigned int updateFlags) {
	m_ImGui->PostUpdate();

	// post update all mods
	for (auto& mod : modList) {
		mod.pMod->PostUpdate();
	}
}

bool ChairLoader::HandleKeyPress(const SInputEvent &event) {
	if (event.keyId == eKI_Tilde && event.state == eIS_Pressed) {
		gui->SetDevConsoleVisible(!gui->IsDevConsoleVisible());
		return true;
	}

	return false;
}

void ChairLoader::SmokeFormExit() {
	if(smokeFormExited) {
		s_CLEnv.entUtils->ArkPlayerPtr()->m_movementFSM.m_smokeState.Exit();
		smokeFormExited = false;
	}
}

void ChairLoader::initializeMods() {
	for(auto &mod: modLoadOrder) {
		ModEntry entry;
		std::string modName = mod.first;
		entry.modName = modName;
		entry.hModule = LoadLibraryA((".\\Mods\\" + modName + "\\" + modName + ".dll").c_str());

		if (!entry.hModule)
			CryFatalError("%s: DLL Failed to load", modName.c_str());

		entry.pfnInit = (IChairloaderMod::ProcInitialize*)GetProcAddress(entry.hModule, IChairloaderMod::PROC_INITIALIZE);
		entry.pfnShutdown = (IChairloaderMod::ProcShutdown*)GetProcAddress(entry.hModule, IChairloaderMod::PROC_SHUTDOWN);

		if (!entry.pfnInit || !entry.pfnShutdown)
			CryFatalError("%s: Missing function exports", modName.c_str());

		entry.pMod = entry.pfnInit();

		if (!entry.pMod)
			CryFatalError("%s: Initialize returned nullptr", modName.c_str());

		bool isRegistered = RegisterMod(std::move(entry));
		if (!isRegistered)
			CryFatalError("%s: RegisterMod returned false", modName.c_str());
	}
}

void ChairLoader::loadAllConfigs() {
	for(auto &mod : modList) {
		gConf->loadModConfigFile(mod.modName);
	}
}

//TODO: as mods are registered they must be sorted by load order as specified by the configuration file


bool ChairLoader::RegisterMod(ModEntry&& mod) {
	if (modLoadOrder.find(mod.modName) != modLoadOrder.end()) {
		CryLog("Mod Registered: %s", mod.modName.c_str());
		modList.emplace_back(std::move(mod));
		sortLoadOrder();
		return true;
	} 
	return false;
}

void ChairLoader::ReadModList() {
	auto cfgValue = gConf->getConfigValue(chairloaderModName, "ModList");

	// FIXME: Magic numbers
	if (cfgValue.which() != 7)
		return;

	auto node = boost::get<pugi::xml_node>(cfgValue);
	for(auto &mod : node) {
		auto modName = boost::get<std::string>(gConf->getNodeConfigValue(mod, "modName"));
        if(mod.child("enabled").text().as_bool() && mod.child("hasDLL").text().as_bool()) {
            auto loadOrder = boost::get<int>(gConf->getNodeConfigValue(mod, "loadOrder"));
            modLoadOrder.insert(std::pair(modName, loadOrder));
            CryLog("Load order found: %s %i", modName.c_str(), loadOrder);
        } 
	}
}

void ChairLoader::sortLoadOrder() {
	std::sort(modList.begin(), modList.end());
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

void ChairLoader::UpdateFreeCam() {
	if (GetAsyncKeyState(m_FreeCamKey) & 1) {
		m_FreeCamEnabled = !m_FreeCamEnabled;
		CryLog("Freecam state: %u\n", m_FreeCamEnabled);
		if (m_FreeCamEnabled) {
			m_DevMode = true;
			((CSystem*)gEnv->pSystem)->SetDevMode(m_DevMode);
			gEnv->pConsole->ExecuteString("FreeCamEnable", false, true);
		}
		else {
			((CSystem*)gEnv->pSystem)->SetDevMode(m_DevMode);
			gEnv->pConsole->ExecuteString("FreeCamDisable", false, true);
		}
	}
}

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
	return &s_CLEnv;
}
