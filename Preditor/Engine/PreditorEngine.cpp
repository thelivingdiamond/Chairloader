#include <detours/detours.h>
#include <mem.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/GameDll/GameStartup.h>
#include <imgui.h>
#include "PreditorEngine.h"
#include "DebuggerConsoleOutput.h"
#include "ArkUglySteamDlcSystem.h"

namespace
{

//----------------------------------------------------------------------------
// Globals
//----------------------------------------------------------------------------
PreditorEngine g_PreditorEngine;
PreditorEngine::ProgressCallback g_ProgressCallback;
PreditorEngine::InitParams g_InitParams;
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
// Function pointers
//----------------------------------------------------------------------------
auto Prey_CreateSystemInterface = PreyFunction<ISystem* (const SSystemInitParams& startupParams)>(0xDA2010);
auto Prey_CreateGameStartup = PreyFunction<CGameStartup* ()>(0x16FD6B0);

//----------------------------------------------------------------------------
// Hooks
//----------------------------------------------------------------------------
auto g_CSystem_CreateSystemVars_Hook = CSystem::FCreateSystemVars.MakeHook();
auto g_CSystem_ChangeUserPath_Hook = CSystem::FChangeUserPath.MakeHook();

void CSystem_CreateSystemVars_Hook(CSystem* const _this)
{
	g_CSystem_CreateSystemVars_Hook.InvokeOrig(_this);
	_this->GetIConsole()->GetCVar("sys_game_folder")->Set(g_InitParams.gameSdkPath.string().c_str());

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
	std::string path = g_InitParams.userPath.string();
	_this->m_env->pCryPak->SetAlias("%USER%", path.c_str(), true);
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

IPreditorEngine* IPreditorEngine::Get() { return &g_PreditorEngine; }

void PreditorEngine::Load(const InitParams& params)
{
	if (m_hPreyDll)
		throw std::logic_error("DLL already loaded");
	m_hSystemMSWSock = nullptr;
	g_InitParams = params;

	if (params.minimal)
	{
		// Minimal must not load Chairloader
		// Load system mswsock.dll so ChairloaderLoader doesn't run
		m_hSystemMSWSock = DllHandle(LoadLibraryExA("mswsock.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32), &FreeLibrary);
	}

	// Change workdir to engine root
	SetCurrentDirectoryW(params.enginePath.c_str());

	// Add game directory to DLL search path
	AddDllDirectory(params.engineBinariesPath.c_str());

	// Load the DLL
	fs::path dllPath = params.engineBinariesPath / "PreyDll.dll";
	DllHandle hPreyDll = DllHandle(LoadLibraryExW(dllPath.c_str(), nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS), &FreeLibrary);

	if (!hPreyDll)
	{
		std::string err = GetLastErrorAsString();
		throw std::runtime_error("Failed to load PreyDll.dll\n" + err);
	}

	if (!params.minimal)
	{
		// See if Chairloader is loaded
		HMODULE hChair = GetModuleHandleA("Chairloader.dll");
		if (!hChair)
			throw std::runtime_error("Chairloader failed to load");
	}

	m_hPreyDll = std::move(hPreyDll);

	ApplyBasePatches();
	if (params.minimal)
		ApplyMinimalPatches();
	else
		ApplyFullPatches();
	InstallHooks();
}

bool PreditorEngine::Start(const InitParams& params)
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
	cry_strcpy(startupParams.szUserPath, params.userPath.string().c_str());
	cry_strcpy(startupParams.szLanguageName, "english");
	startupParams.pArkDlcSystem = CArkUglySteamDlcSystem::Instantiate();

	if (params.minimal)
	{
		startupParams.bSkipRenderer = true;
		startupParams.bSkipInput = true;
	}

	CGameStartup* pStartup = Prey_CreateGameStartup();
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

void PreditorEngine::Shutdown()
{
	if (m_pGameStartup)
	{
		m_pGameStartup->Shutdown();
		m_pGameStartup = nullptr;
		gEnv = nullptr;
	}

	if (m_hPreyDll)
	{
		DetourTransactionBegin();
		PreyFunctionSystem::RemoveHooks();
		DetourTransactionCommit();

		m_hPreyDll = nullptr;
	}

	m_hSystemMSWSock = nullptr;
}

void PreditorEngine::Update()
{
	if (!m_pGameStartup)
		return;

	if (g_InitParams.minimal)
	{
		// Only update the system
		gEnv->pSystem->Update();
	}
	else
	{
		static bool gameMode = true;
		static bool runPhysics = false;
		if (ImGui::Begin("Engine Test"))
		{
			ImGui::Checkbox("Game Mode", &gameMode);
			ImGui::BeginDisabled(gameMode);
			ImGui::Checkbox("Run Physics/AI", &runPhysics);
			ImGui::EndDisabled();
		}
		ImGui::End();

		unsigned updateFlags = 0;

		if (!gameMode)
		{
			updateFlags |= ESYSUPDATE_EDITOR;
			if (runPhysics)
				updateFlags |= ESYSUPDATE_EDITOR_AI_PHYSICS;
		}

		m_pGameStartup->Update(true, updateFlags);
	}
}

void PreditorEngine::ApplyBasePatches()
{
	// Init function system
	PreyFunctionSystem::Init((uintptr_t)m_hPreyDll.get());

	g_CSystem_CreateSystemVars_Hook.SetHookFunc(&CSystem_CreateSystemVars_Hook);
	g_CSystem_ChangeUserPath_Hook.SetHookFunc(&CSystem_ChangeUserPath_Hook);
}

void PreditorEngine::ApplyFullPatches()
{
}

void PreditorEngine::ApplyMinimalPatches()
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

	// CGame::Init: Skip ArkGame::Init
	mem::Nop(dllBase + 0x16D0E39, 0x05);

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
}

void PreditorEngine::InstallHooks()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	PreyFunctionSystem::InstallHooks();
	DetourTransactionCommit();
}
