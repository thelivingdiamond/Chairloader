#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/GameDll/GameStartup.h>
#include <ChairLoader/PreyFunction.h>
#include <ImGui/imgui.h>
#include <ModLoader/PathUtils.h>
#include <mem.h>
#include <detours/detours.h>
#include "LoadGameStage.h"
#include "GameModule.h"
#include "ModToolKit.h"

static auto Prey_CreateSystemInterface = PreyFunction<ISystem* (const SSystemInitParams& startupParams)>(0xDA2010);
static auto CSystem_CreateSystemVars = PreyFunction<void(CSystem* const _this)>(0xDCF790);
static auto CreateGameStartup = PreyFunction<CGameStartup*()>(0x16FD6B0);
static FunctionHook<void(CSystem* const _this)> g_CSystem_CreateSystemVars_Hook;

void CSystem_CreateSystemVars_Hook(CSystem* const _this)
{
	g_CSystem_CreateSystemVars_Hook.InvokeOrig(_this);
	fs::path gameSdkPath = ModToolKit::Get()->GetConfig().gamePath / "GameSDK";
	_this->GetIConsole()->GetCVar("sys_game_folder")->Set(gameSdkPath.u8string().c_str());

	// Enable dedicated server mode
	_this->m_bDedicatedServer = true;
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

LoadGameStage::LoadGameStage(GameModule* pModule, ISystemUserCallback* pSystemUserCallback)
{
	m_pMod = pModule;
	m_pSystemUserCallback = pSystemUserCallback;
}

void LoadGameStage::Start()
{
	try
	{
		LoadDLL();
		InitGame();
		SetStageFinished();
	}
	catch (const std::exception& e)
	{
		m_ErrorText = e.what();
	}
}

void LoadGameStage::ShowUI()
{
	if (m_ErrorText.empty())
	{
		// Progress dialog
		int flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
		ImGui::SetNextWindowSize(ImVec2(480, 72));
		if (ImGui::Begin("Initializing Game...###LoadGameStage", nullptr, flags))
		{
			ImGui::Text("%s", m_ProgressText.c_str());
			ImGui::ProgressBar((float)m_ProgressCount / MAX_PROGRESS);
		}
		ImGui::End();
	}
	else
	{
		// Error dialog
		ImGui::SetNextWindowSize(ImVec2(480, 200));
		if (ImGui::Begin("Initialization Failed###LoadGameStage", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings))
		{
			ImGui::TextWrapped("The Mod Toolkit failed to load.\n\n%s", m_ErrorText.c_str());
		}
		ImGui::End();
	}
}

void LoadGameStage::UpdateProgressText(const std::string& text)
{
	m_ProgressText = text;
	m_ProgressCount++;
	ModToolKit::Get()->RefreshUI();
}

void LoadGameStage::LoadDLL()
{
	UpdateProgressText("Loading PreyDll.dll...");

	// Load system mswsock.dll so ChairloaderLoader doesn't run
	LoadLibraryExA("mswsock.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);

	// Add game directory to DLL search path
	fs::path binDir = ModToolKit::Get()->GetConfig().gamePath / PathUtils::GAME_BIN_DIR;
	AddDllDirectory(binDir.c_str());

	// Load the DLL
	fs::path dllPath = ModToolKit::Get()->GetConfig().gamePath / PathUtils::GAME_DLL_PATH;
	m_pMod->hModule = LoadLibraryExW(dllPath.c_str(), nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);

	if (!m_pMod->hModule)
	{
		std::string err = GetLastErrorAsString();
		throw std::runtime_error("Failed to load PreyDll.dll\n" + err);
	}

	PreyFunctionSystem::Init((uintptr_t)m_pMod->hModule);

	// CSystem::CSystem: Disable CHardwareMouse
	uint8_t* dllBase = (uint8_t*)m_pMod->hModule;
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

	DetourTransactionBegin();
	g_CSystem_CreateSystemVars_Hook.InstallHook(CSystem_CreateSystemVars.Get(), &CSystem_CreateSystemVars_Hook);
	DetourTransactionCommit();
}

void LoadGameStage::InitGame()
{
	UpdateProgressText("Starting the game engine...");
	ModToolKit::Get()->RefreshUI();

	SSystemInitParams startupParams;
	startupParams.hInstance = GetModuleHandle(0);
	startupParams.pUserCallback = m_pSystemUserCallback;
	startupParams.sLogFileName = "CryEngine.log";
	cry_strcpy(startupParams.szSystemCmdLine, GetCommandLineA());
	cry_strcpy(startupParams.szLanguageName, "english");
	startupParams.bSkipRenderer = true;
	startupParams.bSkipInput = true;
	//startupParams.bEditor = true; // Not sure does anything useful

	CGameStartup* pStartup = CreateGameStartup();
	if (!pStartup->Init(startupParams))
	{
		pStartup->Shutdown();
		throw std::runtime_error("Engine failed to initialize");
	}

	m_pGameStartup = pStartup;
	::ShowCursor(1); // CGameStartup::Init calls with 0
}
