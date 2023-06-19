#include <detours/detours.h>
#include <mem.h>
#include <Chairloader/SemanticVersion.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/CryGame/Game.h>
#include <Prey/GameDll/GameStartup.h>
#include <Prey/GameDll/basiceventlistener.h>
#include <Chairloader/IChairloaderMod.h>
#include <Chairloader/IChairToPreditor.h>
#include <Chairloader/Hooks/HookTransaction.h>
#include <App/Application.h>
#include <Preditor/Main/IUserProjectSettings.h>
#include <Preditor/Main/IPreditor.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include <Preditor/Viewport/IViewport.h>
#include <imgui.h>
#include "PreditorEngine.h"
#include "DebuggerConsoleOutput.h"
#include "ArkUglySteamDlcSystem.h"

#include "PreditorImGui.h"
#include "EngineSwapChainPatch.h"
#include "GameViewportPatch.h"
#include "MainWindowResizePatch.h"
#include "HardwareMousePatch.h"
#include "RendererGlobals.h"
#include "SimulationController.h"

namespace Engine
{
namespace
{

//----------------------------------------------------------------------------
// Globals
//----------------------------------------------------------------------------
PreditorEngine g_PreditorEngine;
Engine::PreditorEngine::ProgressCallback g_ProgressCallback;
Engine::PreditorEngine::InitParams g_InitParams;
DebuggerConsoleOutput g_DebuggerConsoleOutput;

//----------------------------------------------------------------------------
// SystemUserCallback
//----------------------------------------------------------------------------
class SystemUserCallback : public ISystemUserCallback
{
public:
	bool OnError(const char* szErrorString) override
	{
		if (IsDebuggerPresent())
			__debugbreak();

		int btn = ShowMessage(szErrorString, "Engine Error", MB_ABORTRETRYIGNORE | MB_ICONERROR);

		if (btn == IDABORT)
			return true; // true halts execution
		else
			return false;
	}

	bool OnSaveDocument() override { return true; }

	void OnProcessSwitch() override {}

	void OnInitProgress(const char* sProgressMsg) override {
		if (g_ProgressCallback)
			g_ProgressCallback(sProgressMsg);
	}

	void OnInit(ISystem* pSystem) override
	{
		static_cast<CSystem*>(pSystem)->SetDevMode(true);
		ModuleInitISystem(pSystem, "Preditor");
		gEnv->pLog->SetVerbosity(4);
		g_DebuggerConsoleOutput.Init();

		if (g_InitParams.minimal)
		{
			// Register fake cvars
			gEnv->pConsole->RegisterFloat("e_ViewDistMin", 0.0f, VF_NULL);
			gEnv->pConsole->RegisterFloat("e_ViewDistRatio", 0.0f, VF_NULL);
			gEnv->pConsole->RegisterFloat("e_CastShadowViewDistMin", 0.0f, VF_NULL);
			gEnv->pConsole->RegisterFloat("e_CastShadowViewDistRatio", 0.0f, VF_NULL);
			gEnv->pConsole->RegisterFloat("e_ViewDistRatioCustom", 0.0f, VF_NULL);
			gEnv->pConsole->RegisterFloat("e_ViewDistRatioDetail", 0.0f, VF_NULL);
		}
	}

	void GetMemoryUsage(ICrySizer* pSizer) override {}
};

SystemUserCallback g_SystemUserCallback;

//----------------------------------------------------------------------------
// PreditorAsMod
//----------------------------------------------------------------------------
class PreditorAsMod : public IChairloaderMod
{
public:
	// IChairloaderMod
	void GetModSdkVersion(SemanticVersion& version) override
	{
		version.m_Major = MOD_SDK_VERSION_MAJOR;
		version.m_Minor = MOD_SDK_VERSION_MINOR;
		version.m_Patch = MOD_SDK_VERSION_PATCH;
		version.m_ReleaseType = MOD_SDK_VERSION_RELEASE_TYPE;
	}

	void* QueryInterface(const char* ifaceName) override
	{
		return nullptr;
	}

	void InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo) override
	{
		assert(!initInfo.isHotReloading);
		dllInfo.thisStructSize = sizeof(ModDllInfo);
		dllInfo.modName = "Chairloader.Preditor";
		dllInfo.supportsHotReload = false;

		gCL = initInfo.pChair->GetChairloaderEnvironment();
		CryAssertSetGlobalFlagAddress(gCL->cl->GetAssertFlagAddress());
		ModuleInitIChairLogger("Preditor");

		RendererGlobals::InitSystem();
		MainWindowResizePatch::InitSystem();

		gPreditor->pMain->InitSystem();
	}

	void Connect(const std::vector<IChairloaderMod*>& mods) override {}

	void InitGame(bool isHotReloading) override
	{
		assert(!isHotReloading);
		g_pGame = gCL->cl->GetCGame();
		g_PreditorEngine.InitGame();
		gPreditor->pMain->InitGame();
	}

	void ShutdownGame(bool isHotUnloading) override
	{
		assert(!isHotUnloading);
		gPreditor->pMain->ShutdownGame();
		g_PreditorEngine.ShutdownGame();
	}

	void ShutdownSystem(bool isHotUnloading) override
	{
		assert(!isHotUnloading);
		gPreditor->pMain->ShutdownSystem();
		MainWindowResizePatch::ShutdownSystem();
		RendererGlobals::ShutdownSystem();
	}
};

PreditorAsMod g_PreditorAsMod;

//----------------------------------------------------------------------------
// Function pointers
//----------------------------------------------------------------------------
auto Prey_CreateSystemInterface = PreyFunction<ISystem* (const SSystemInitParams& startupParams)>(0xDA2010);
auto Prey_CreateGameStartup = PreyFunction<CGameStartup* ()>(0x16FD6B0);

//----------------------------------------------------------------------------
// Hooks
//----------------------------------------------------------------------------
auto g_CSystem_CreateSystemVars_Hook = CSystem::FCreateSystemVars.MakeHook();
auto g_CSystem_ChangeUserPath_Hook = CSystem::FChangeUserPath.MakeHook();
auto g_CSystem_LoadConfiguration_Hook = CSystem::FLoadConfiguration.MakeHook();
auto g_CSystem_OpenBasicPaks_Hook = CSystem::FOpenBasicPaks.MakeHook();

void CSystem_CreateSystemVars_Hook(CSystem* const _this)
{
	g_CSystem_CreateSystemVars_Hook.InvokeOrig(_this);

	// Load files from disk first, then from PAKs
	gEnv->pConsole->GetCVar("sys_PakPriority")->Set(0);

	if (g_InitParams.minimal)
	{
		// Enable dedicated server mode
		_this->m_bDedicatedServer = true;
	}
}

void CSystem_ChangeUserPath_Hook(CSystem* const _this, const char* sUserPath)
{
	// Don't use My Games, use the path directly
	std::string path = g_InitParams.userPath.u8string();
	_this->m_env->pCryPak->SetAlias("%USER%", path.c_str(), true);
}

void CSystem_LoadConfiguration_Hook(CSystem* const _this, const char* sFilename, ILoadConfigurationEntrySink* pSink, bool allowMissing)
{
	g_CSystem_LoadConfiguration_Hook.InvokeOrig(_this, sFilename, pSink, allowMissing);

	if (!strcmp(sFilename, "system.cfg"))
	{
		// Override system.cfg params
		if (!g_InitParams.gameSdkPath.empty())
			_this->GetIConsole()->GetCVar("sys_game_folder")->Set(g_InitParams.gameSdkPath.u8string().c_str());
	}
	else if (!strcmp(sFilename, "user.cfg"))
	{
		if (gPreditor->pUserSettings)
		{
			// Disable fullscreen
			_this->m_rFullscreen->Set(0);

			// Set window size
			IUserProjectSettings* pSettings = gPreditor->pUserSettings;
			Vec2i size = pSettings->GetWindowRestoredSize();

			if (size.x != IUserProjectSettings::INVALID_SIZE && size.y != IUserProjectSettings::INVALID_SIZE)
			{
				_this->m_rWidth->Set(size.x);
				_this->m_rHeight->Set(size.y);
			}
			else
			{
				// Default to working area size of the main monitor
				RECT rc;
				if (SystemParametersInfoA(SPI_GETWORKAREA, 0, &rc, 0))
				{
					_this->m_rWidth->Set(rc.right - rc.left);
					_this->m_rHeight->Set(rc.bottom - rc.top);
				}
			}
		}
	}
}

void CSystem_OpenBasicPaks_Hook(CSystem* const _this)
{
	static bool bBasicPaksLoaded = false;
	if (!bBasicPaksLoaded)
	{
		if (!g_InitParams.modDirPath.empty())
			_this->m_env->pCryPak->AddMod(g_InitParams.modDirPath.u8string().c_str());

		if (g_InitParams.loadGamePaks)
		{
			// Load all PAKs from the original GameSDK
			std::string gameSdkPath = (g_InitParams.enginePath.GetGamePath() / "GameSDK").u8string();
			_this->m_env->pCryPak->AddMod(gameSdkPath.c_str());
			_this->m_env->pCryPak->OpenPacks((gameSdkPath + "/*.pak").c_str(), ICryPak::FLAGS_PATH_REAL, nullptr);
			_this->m_env->pCryPak->OpenPacks((gameSdkPath + "/Precache/Patch*.pak").c_str(), ICryPak::FLAGS_PATH_REAL, nullptr);
		}
	}
	bBasicPaksLoaded = true;
	g_CSystem_OpenBasicPaks_Hook.InvokeOrig(_this);
}

// Returns the last Win32 error, in string format. Returns an empty string if there is no error.
// https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror
// I hate WinAPI
std::string GetLastErrorAsString()
{
	// Get the error message ID, if any.
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0) {
		return std::string(); //No error message has been recorded
	}

	LPSTR messageBuffer = nullptr;

	// Ask Win32 to give us the string version of that message ID.
	// The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	// Copy the error message into a std::string.
	std::string message(messageBuffer, size);

	// Free the Win32's string's buffer.
	LocalFree(messageBuffer);

	return message;
}

} // namespace
} // namespace Engine

IPreditorEngine* IPreditorEngine::Get() { return &Engine::g_PreditorEngine; }

void Engine::PreditorEngine::InitGame()
{
	m_pImGui = std::make_shared<PreditorImGui>();
	m_pSimulationController = std::make_unique<SimulationController>();
}

void Engine::PreditorEngine::ShutdownGame()
{
	m_pSimulationController = nullptr;
	m_pImGui = nullptr;
	Application::Get()->SetAppImGui(nullptr);
}

bool Engine::PreditorEngine::HandleKeyboardMessage(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam)
{
	HWND hMainWnd = (HWND)gEnv->pSystem->GetHWND();
	IBasicEventListener* pBasicEventListener = &static_cast<CGameStartup*>(g_PreditorEngine.m_pGameStartup)->m_basicEventListener;
	IBasicEventListener::EAction result = IBasicEventListener::eA_Default;

	switch (msg)
	{
	case WM_SYSKEYDOWN:
		result = pBasicEventListener->OnSysKeyDown(hMainWnd, wParam, lParam);
		break;
	case WM_SYSCHAR:
		result = pBasicEventListener->OnSycChar(hMainWnd);
		break;
	case WM_SYSCOMMAND:
		result = pBasicEventListener->OnSysCommand(hMainWnd, wParam);
		break;
	case WM_HOTKEY:
		result = pBasicEventListener->OnHotKey(hMainWnd);
		break;
	}

	return result != IBasicEventListener::eA_Default;
}

void Engine::PreditorEngine::Load(const InitParams& params)
{
	if (m_hPreyDll)
		throw std::logic_error("DLL already loaded");
	m_hSystemMSWSock = nullptr;
	g_InitParams = params;

	// Load system mswsock.dll so Chairloader.Loader doesn't run
	m_hSystemMSWSock = DllHandle(LoadLibraryExA("mswsock.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32), &FreeLibrary);

	// Change workdir to engine root
	SetCurrentDirectoryW(params.enginePath.GetGamePath().c_str());

	// Add game directory to DLL search path
	fs::path binariesPath = params.enginePath.GetGamePath() / params.enginePath.GetGameBinDir();
	AddDllDirectory(binariesPath.c_str());

	// Load the DLL
	fs::path dllPath = binariesPath / "PreyDll.dll";
	DllHandle hPreyDll = DllHandle(LoadLibraryExW(dllPath.c_str(), nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS), &FreeLibrary);

	if (!hPreyDll)
	{
		std::string err = GetLastErrorAsString();
		throw std::runtime_error("Failed to load PreyDll.dll\n" + err);
	}

	if (!params.minimal)
	{
		// Load Chairloader
		fs::path chairPath = binariesPath / "Chairloader.dll";
		DllHandle hChairDll = DllHandle(LoadLibraryExW(chairPath.c_str(), nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS), &FreeLibrary);

		if (!hChairDll)
		{
			std::string err = GetLastErrorAsString();
			throw std::runtime_error("Failed to load Chairloader.dll\n" + err);
		}

		// Init Preditor API
		auto pFunc = reinterpret_cast<Chair_GetPreditorAPI_Func>(GetProcAddress(hChairDll.get(), PREDITOR_API_EXPORT_FUNC_NAME));
		if (!pFunc)
			throw std::runtime_error("Chairloader.dll doesn't export " + std::string(PREDITOR_API_EXPORT_FUNC_NAME));

		int chairApiVersion = -1;
		m_pChair = pFunc(PREDITOR_API_VERSION, &chairApiVersion);

		// Validate version
		if (!m_pChair)
		{
			if (chairApiVersion != PREDITOR_API_VERSION)
			{
				throw std::runtime_error(fmt::format("Preditor API version mismatch!\nPreditor: {}\nChairloader: {}",
					PREDITOR_API_VERSION, chairApiVersion));
			}
			else
			{
				throw std::runtime_error("Chairloader returned nullptr IChairToPreditor");
			}
		}

		m_pChair->SetIPreditorToChair(this);
		m_hChairDll = std::move(hChairDll);
	}

	m_hPreyDll = std::move(hPreyDll);

	ApplyBasePatches();
	if (params.minimal)
		ApplyMinimalPatches(params);
	else
		ApplyFullPatches();
	InstallHooks();
}

bool Engine::PreditorEngine::Start(const InitParams& params)
{
	if (m_bWasEverStarted)
		std::abort();
	m_bWasEverStarted = true;

	g_ProgressCallback = params.progressCallback;

	SSystemInitParams startupParams;
	startupParams.hInstance = GetModuleHandle(0);
	startupParams.pUserCallback = &g_SystemUserCallback;
	startupParams.sLogFileName = "PreditorEngine.log";
	cry_strcpy(startupParams.szSystemCmdLine, GetCommandLineA());
	cry_strcpy(startupParams.szUserPath, params.userPath.u8string().c_str());
	cry_strcpy(startupParams.szLanguageName, "english");
	startupParams.pArkDlcSystem = CArkUglySteamDlcSystem::Instantiate();

	if (params.minimal)
	{
		startupParams.bSkipRenderer = true;
		startupParams.bSkipInput = true;
	}

	CGameStartup* pStartup = Prey_CreateGameStartup();
	HardwareMousePatch::SetIBasicEventListener(&pStartup->m_basicEventListener);
	bool initResult = pStartup->Init(startupParams);
	g_ProgressCallback = ProgressCallback();

	if (!initResult)
	{
		pStartup->Shutdown();
		return false;
	}

	m_pGameStartup = pStartup;
	::ShowCursor(1); // CGameStartup::Init calls with 0
	return true;
}

void Engine::PreditorEngine::Shutdown()
{
	if (m_pGameStartup)
	{
		m_pGameStartup->Shutdown();
		m_pGameStartup = nullptr;
		gEnv = nullptr;
	}

	if (m_hPreyDll)
	{
		HookTransaction ht;
		PreyFunctionSystem::RemoveHooks();
		ht.Commit();

		m_hPreyDll = nullptr;
	}

	m_hSystemMSWSock = nullptr;
}

void Engine::PreditorEngine::SetAppImGui()
{
	Application::Get()->SetAppImGui(m_pImGui);
	m_pImGui->BeginFrame();
}

bool Engine::PreditorEngine::Update()
{
	if (!m_pGameStartup)
		return true;

	if (g_InitParams.minimal)
	{
		// Only update the system
		return gEnv->pSystem->Update();
	}
	else
	{
		unsigned updateFlags = m_pSimulationController->GetUpdateFlags();
		m_pSimulationController->BeginUpdate();
		int result = m_pGameStartup->Update(true, updateFlags);
		m_pSimulationController->EndUpdate();
		return result;
	}
}

ITexture* Engine::PreditorEngine::GetViewportTexture()
{
	return EngineSwapChainPatch::GetBackbuffer();
}

IChairToPreditor* Engine::PreditorEngine::GetIChairToPreditor()
{
	return m_pChair;
}

Engine::ISimulationController* Engine::PreditorEngine::GetSimController()
{
	return m_pSimulationController.get();
}

void Engine::PreditorEngine::SetGameInputEnabled(bool state)
{
	m_bGameInput = state;
	m_pImGui->SetGameInputEnabled(state);
	HardwareMousePatch::SetWindowFocused(state);
}

bool Engine::PreditorEngine::IsGameInputEnabled()
{
	return m_bGameInput;
}

bool Engine::PreditorEngine::SetGameViewportRect(ImGuiID viewportId, Vec2i min, Vec2i max)
{
	return HardwareMousePatch::SetGameViewportBounds(viewportId, min, max);
}

IChairloaderMod* Engine::PreditorEngine::GetMod()
{
	return &g_PreditorAsMod;
}

bool Engine::PreditorEngine::HandleInputEvent(const SInputEvent& event)
{
	// Always pass gamepad input
	if (event.deviceType == eIDT_Gamepad)
		return false;

	if (m_bGameInput)
	{
		// The game can process it
		return false;
	}
	else
	{
		// No input to the game
		return true;
	}
}

bool Engine::PreditorEngine::HandleInputEventPreGame(const SInputEvent& event)
{
	// Always pass gamepad input
	if (event.deviceType == eIDT_Gamepad)
		return false;

	IViewportWindow* pVPWin = gPreditor->pViewportWindow;
	IViewport* pVP = pVPWin ? pVPWin->GetCurrentViewport() : nullptr;

	if (pVP)
		return !pVP->EnableMouseEvents();

	return false;
}

void Engine::PreditorEngine::ApplyBasePatches()
{
	// Init function system
	PreyFunctionSystem::Init((uintptr_t)m_hPreyDll.get());

	g_CSystem_CreateSystemVars_Hook.SetHookFunc(&CSystem_CreateSystemVars_Hook);
	g_CSystem_ChangeUserPath_Hook.SetHookFunc(&CSystem_ChangeUserPath_Hook);
	g_CSystem_LoadConfiguration_Hook.SetHookFunc(&CSystem_LoadConfiguration_Hook);
	g_CSystem_OpenBasicPaks_Hook.SetHookFunc(&CSystem_OpenBasicPaks_Hook);
}

void Engine::PreditorEngine::ApplyFullPatches()
{
	PreditorImGui::InitHooks();
	EngineSwapChainPatch::InitHooks();
	GameViewportPatch::InitHooks();
	MainWindowResizePatch::InitHooks();
	HardwareMousePatch::InitHooks();

	uint8_t* dllBase = (uint8_t*)m_hPreyDll.get();

	// CD3D9Renderer::ChangeResolution: Remove log when resizing the viewport
	mem::Nop(dllBase + 0xF2259D, 0xF225A0 - 0xF2259D); // Changing resolution...
	mem::Nop(dllBase + 0xF22D91, 0xF22D94 - 0xF22D91); // Window resolution: %dx%dx%d (%s)
	mem::Nop(dllBase + 0xF22DB3, 0xF22DB6 - 0xF22DB3); // Render resolution: %dx%d

	// CSystem::Update: Remove FPS throttling when window is unfocused
	// jnz loc_7F0000DC8DA1-> jmp loc_7F0000DC8DA1
	uint8_t throttlePatch[] = { 0xE9, 0xFE, 0x00 };
	mem::Patch(dllBase + 0xDC8C9E, throttlePatch, 3);

	// CCryAction::PostUpdate: Remove p3DEngine->PrepareOcclusion calls because SceneViewport changes the camera
	mem::Nop(dllBase + 0x5C6AA7, 0x5C6AAA - 0x5C6AA7);
	mem::Nop(dllBase + 0x5C6C50, 0x5C6C53 - 0x5C6C50);
}

void Engine::PreditorEngine::ApplyMinimalPatches(const InitParams& params)
{
	uint8_t* dllBase = (uint8_t*)m_hPreyDll.get();

	// CSystem::CSystem: Disable CHardwareMouse
	uint8_t byte = 0xEB;
	mem::Patch(dllBase + 0xDD41E8, &byte, 1);

	// CSystem::Update: nop pRenderer->GetPixelAspectRatio
	mem::Nop(dllBase + 0xDC8E4A, 0x40);

	// CSystem::Init: Disable CSharedFlashPlayerResources::Init
	mem::Nop(dllBase + 0xDD3D63, 0x1A);

	// CSystem::Init: Init ScriptSystem without renderer
	mem::Nop(dllBase + 0xDD4689, 0x1A);

	// CGameStartup::Init: Remove SetWindowLongPtrA call
	mem::Nop(dllBase + 0x1739C32, 0x1A);

	// OnHFOVChanged: Nop the whole thing until ret
	mem::Nop(dllBase + 0x16F8CB0, 0x11D);

	// CGame::Init: Skip CUIManager
	mem::Nop(dllBase + 0x16D0B2A, 0x14);
	mem::Nop(dllBase + 0x16D0B4B, 0x05);

	// CGame::Init
	mem::Nop(dllBase + 0x16D0C93, 0x03);	// Skip CGame::LoadActionMaps
	mem::Nop(dllBase + 0x16D0E39, 0x05);	// Skip ArkGame::Init

	// CGame::InitGameType: Remove pHardwareMouse calls
	mem::Nop(dllBase + 0x16D1A0C, 0x16D1A12 - 0x16D1A0C);
	mem::Nop(dllBase + 0x16D1CB7, 0x16D1CBD - 0x16D1CB7);

	// CGame::InitGameType: Remove p3DEngine call
	uint8_t opcode_ret = 0xC3;
	mem::Nop(dllBase + 0x16D1D47, 0x16D1D4A - 0x16D1D47);
	mem::Patch(dllBase + 0x16D1D54, &opcode_ret, 1);

	// ArkGame::CompleteInit: Don't do anything
	mem::Patch(dllBase + 0x116CE30, &opcode_ret, 1);

	// CLevelSystem::OnLoadingProgress Remove p3DEngine call
	mem::Nop(dllBase + 0x356F49, 0x356F52 - 0x356F49);

	// CCryAction::CompleteInit
	mem::Nop(dllBase + 0x5BDEF7, 0x5BDF0B - 0x5BDEF7); // Remove CMaterialEffects
	mem::Nop(dllBase + 0x5BE020, 0x5BE039 - 0x5BE020); // Remove p3DEngine->GetMaterialManager
	mem::Nop(dllBase + 0x5BE07C, 0x5BE07E - 0x5BE07C); // Skip a bunch of code


	mem::Nop(dllBase + 0x49DD5A, 0x49DD5F - 0x49DD5A); // skip game:start node constructor
	mem::Nop(dllBase + 0x49DD70, 0x49DD79 - 0x49DD70); // skip game:start node constructor

	mem::Nop(dllBase + 0x179447B, 0x1794480 - 0x179447B); // skip CTacticalScanNode Hud Event Register Call

	mem::Nop(dllBase + 0x11C92D1, 0x11C9300 - 0x11C92D1); // skip CArkFlowNodeMimicPlayerEvent UI Calls

	if (params.caseSensitivePaks)
	{
		// ZipDir::CacheFactory::BuildFileEntryMap: Remove tolower call
		// This will break opening files in paks by name.
		uint8_t toLowerPatch[] = { 0x89, 0xC8 }; // mov eax, ecx
		mem::Nop(dllBase + 0xE42A43, 0xE42A49 - 0xE42A43);
		mem::Patch(dllBase + 0xE42A43, toLowerPatch, std::size(toLowerPatch));
	}
}

void Engine::PreditorEngine::InstallHooks()
{
	HookTransaction ht;
	PreyFunctionSystem::InstallHooks();
	ht.Commit();
}
