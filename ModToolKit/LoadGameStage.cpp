#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <ChairLoader/PreyFunction.h>
#include <ImGui/imgui.h>
#include <ModLoader/PathUtils.h>
#include <Prey/CryGame/IGameStartup.h>
#include <Prey/CryGame/IGameRef.h>
#include <mem.h>
#include <detours/detours.h>
#include "LoadGameStage.h"
#include "GameModule.h"
#include "ModToolKit.h"
//#include "Prey/GameDll/ark/ArkGame.h"
#include <Prey/CryAction/CryAction.h>
#include <Prey/CrySystem/IEngineModule.h>

static auto Prey_CreateSystemInterface = PreyFunction<ISystem* (const SSystemInitParams& startupParams)>(0xDA2010);
static auto prey_createGameStartup = PreyFunction<IGameStartup*()>(0x16FD6B0);
static auto prey_createGameFramework = PreyFunction<void()> (0x05CF2A0);
static auto prey_runGame = PreyFunction<int64_t(const char*)>(0x009D090);

static auto CSystem_CreateSystemVars = PreyFunction<void(CSystem* const _this)>(0xDCF790);
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
		InitSystem();
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

	DetourTransactionBegin();
	g_CSystem_CreateSystemVars_Hook.InstallHook(CSystem_CreateSystemVars.Get(), &CSystem_CreateSystemVars_Hook);
	DetourTransactionCommit();
}

static auto Prey_CryInitModule_CryScriptSystem = PreyFunction<std::shared_ptr<IEngineModule>&(std::shared_ptr<IEngineModule>&)>(0x0D0C0E0);
static auto Prey_CryInitModule_CryFont = PreyFunction<std::shared_ptr<IEngineModule>&(std::shared_ptr<IEngineModule>&)>(0x09B3FC0);
static auto Prey_CryInitMdoule_CryEntitySystem = PreyFunction<std::shared_ptr<IEngineModule>&(std::shared_ptr<IEngineModule>&)>(0x900D50);

void LoadGameStage::InitSystem()
{
	UpdateProgressText("Initializing CrySystem...");
	ModToolKit::Get()->RefreshUI();

	SSystemInitParams startupParams;
	startupParams.hInstance = GetModuleHandle(0);
	startupParams.pUserCallback = m_pSystemUserCallback;
	startupParams.sLogFileName = "CrySystem.log";
	cry_strcpy(startupParams.szSystemCmdLine, GetCommandLineA());
	cry_strcpy(startupParams.szLanguageName, "english");
//	startupParams.bSkipFont = true;
	startupParams.bSkipRenderer = true;
	startupParams.bSkipNetwork = true;
	startupParams.bSkipWebsocketServer = true;
	startupParams.bSkipInput = true;
	startupParams.bShaderCacheGen = true; // Skips some UI code
//    startupParams.b
//    startupParams.bTestMode = true; // Skips some UI code
//    cry_strcpy(startupParams.szUserPath, ModToolKit::Get()->GetConfig().gamePath.u8string().c_str());

	m_pMod->pSystem = Prey_CreateSystemInterface(startupParams);
	if (!m_pMod->pSystem)
		throw std::runtime_error("CrySystem failed to initialize");
////    prey_createGameFramework();
    gEnv->pSystem = m_pMod->pSystem;
    startupParams.pSystem = m_pMod->pSystem;
    assert(gEnv->pSystem);
//    std::shared_ptr<IEngineModule> pScriptSystem;
//    pScriptSystem = Prey_CryInitModule_CryScriptSystem(pScriptSystem);
//    if (!pScriptSystem)
//        throw std::runtime_error("CryScriptSystem failed to initialize");
//////    SSystemGlobalEnvironment env;
//    pScriptSystem->Initialize(*gEnv, startupParams);
//    auto pFlowSystem = gEnv->pSystem->GetIFlowSystem();
//    gEnv->pScriptSystem = (IScriptSystem*)pScriptSystem.get();
//    std::shared_ptr<IEngineModule> pFont;
//    pFont = Prey_CryInitModule_CryFont(pFont);
//    if (!pFont)
//        throw std::runtime_error("CryFont failed to initialize");
//    std::shared_ptr<IEngineModule> pEntitySystem;
//    pEntitySystem = Prey_CryInitMdoule_CryEntitySystem(pEntitySystem);
//    if (!pEntitySystem)
//        throw std::runtime_error("CryEntitySystem failed to initialize");
//    gEnv->pEntitySystem = (IEntitySystem*)pEntitySystem.get();
//    pEntitySystem->Initialize(*gEnv, startupParams);

//    pFont->Initialize(*gEnv, startupParams);
//    gEnv->pCryFont = (ICryFont*)pFont.get();
//    auto pScriptSystemInterface = (IScriptSystem*)(pScriptSystem.get());
//    gEnv->pScriptSystem = (IScriptSystem*)(pScriptSystem.get());
//    static CCryAction* pCryAction = new CCryAction();
//    pCryAction->Init(startupParams);
//    prey_createGameFramework();
//    startupParams.pSystem = m_pMod->pSystem;
//    auto pGameStartup = (IGameStartup*)prey_createGameStartup();
////    startupParams.pGameStartup = pGameStartup;
//    IGameRef ref;
//    IGameRef pGameRef =  pGameStartup->FInit2(pGameStartup, ref, startupParams);
//    if (!pGameRef.m_ptr || !*pGameRef.m_ptr)
//        throw std::runtime_error("CryGame failed to initialize");
////    gEnv->pGame = *pGameRef.m_ptr;
}
