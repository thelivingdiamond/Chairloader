#include <Prey/CryCore/Platform/CryWindows.h>
#include "SteamAPI/ArkSteamDlcSystem.h"
#include "SteamAPI/ArkSteamRewardSystem.h"
#include "SteamAPI/ChairSteamAPI.h"

std::unique_ptr<ChairSteamAPI> ChairSteamAPI::CreateInstance()
{
    HMODULE hModule = LoadLibraryA(DLL_NAME);

    if (!hModule)
    {
        CryLog("{} not found. Not running Steam version.");
        return nullptr;
    }

    char path[MAX_PATH];
    GetModuleFileNameA(hModule, path, sizeof(path));
    CryLog("Found Steam API: {}", path);
    return std::make_unique<ChairSteamAPI>(hModule);
}

ChairSteamAPI::ChairSteamAPI(void* hModuleVoid)
{
    assert(!gCL->pSteamAPI);
    gCL->pSteamAPI = this;
    m_hModule = hModuleVoid;
    LoadFuncs();

    if (!IsSteamRunning())
        CryFatalError("Steam is not running");

    InitSteam();
}

ChairSteamAPI::~ChairSteamAPI()
{
    m_pShutdown();

    if (m_hModule)
    {
        FreeLibrary((HMODULE)m_hModule);
        m_hModule = nullptr;
    }

    assert(gCL->pSteamAPI == this);
    gCL->pSteamAPI = nullptr;
}

void ChairSteamAPI::ReplaceArkSystems()
{
    // Existing systems are owned by CSystem. It will destroy them in ShutDown.
    delete gEnv->pArkRewardSystem;
    delete gEnv->pArkDlcSystem;
    gEnv->pArkRewardSystem = new ArkSteamRewardSystem();
    gEnv->pArkDlcSystem = new ArkSteamDlcSystem();
    gEnv->pArkDlcSystem->InitEnv(gEnv);
}

void ChairSteamAPI::Update()
{
    m_pRunCallbacks();
}

void ChairSteamAPI::LoadFuncs()
{
    std::vector<std::string> errorFuncList;

    auto fnGetFunc = [&](auto& pFuncStorage, const char* name)
    {
        using FuncT = typename std::remove_reference_t<decltype(pFuncStorage)>;
        pFuncStorage = (FuncT)GetProcAddress((HMODULE)m_hModule, name);

        if (!pFuncStorage)
            errorFuncList.push_back(name);
    };

    // IChairSteamAPI funcs
    fnGetFunc(m_pGetHSteamUser, "SteamAPI_GetHSteamUser");
    fnGetFunc(m_pRegisterCallback, "SteamAPI_RegisterCallback");
    fnGetFunc(m_pUnregisterCallback, "SteamAPI_UnregisterCallback");
    fnGetFunc(m_pRegisterCallResult, "SteamAPI_RegisterCallResult");
    fnGetFunc(m_pUnregisterCallResult, "SteamAPI_UnregisterCallResult");
    fnGetFunc(m_pIsSteamRunning, "SteamAPI_IsSteamRunning");
    fnGetFunc(m_pGetHSteamUserCurrent, "Steam_GetHSteamUserCurrent");
    fnGetFunc(m_pGetSteamInstallPath, "SteamAPI_GetSteamInstallPath");
    fnGetFunc(m_pGetHSteamPipe, "SteamAPI_GetHSteamPipe");
    fnGetFunc(m_pCreateInterface, "SteamInternal_CreateInterface");

    // Internal funcs
    fnGetFunc(m_pInit, "SteamAPI_Init");
    fnGetFunc(m_pShutdown, "SteamAPI_Shutdown");
    fnGetFunc(m_pContextInit, "SteamInternal_ContextInit");
    fnGetFunc(m_pRunCallbacks, "SteamAPI_RunCallbacks");

    if (!errorFuncList.empty())
    {
        // Fail fatally because
        // a) this shouldn't happen
        // b) achievements will suddenly stop tracking for players
        std::string msg;

        for (const std::string& i : errorFuncList)
            msg += i + "\n";

        CryFatalError("Failed to load functions from {}:\n{}", DLL_NAME, msg);
    }
}

void ChairSteamAPI::InitSteam()
{
    if (!m_pInit())
        CryFatalError("SteamAPI_Init failed");

    // Initialize the context

    // SteamInternal_ContextInit takes a base pointer for the equivalent of
    // struct { void (*pFn)(void* pCtx); uintp counter; CSteamAPIContext ctx; }
    // Do not change layout of 2 + sizeof... or add non-pointer aligned data!
    // NOTE: declaring "static CSteamAPIConext" creates a large function
    // which queries the initialization status of the object. We know that
    // it is pointer-aligned and fully memset with zeros, so just alias a
    // static buffer of the appropriate size and call it a CSteamAPIContext.
    static void* s_CallbackCounterAndContext[2 + sizeof(CSteamAPIContext) / sizeof(void*)] = { (void*)&SteamInternal_OnContextInit, 0 };
    m_pContext = (CSteamAPIContext*)m_pContextInit(s_CallbackCounterAndContext);

    if (!m_pContext)
        CryFatalError("SteamInternal_ContextInit returned nullptr");

    CryLog("Steam AppID = {}", SteamUtils()->GetAppID());
}
