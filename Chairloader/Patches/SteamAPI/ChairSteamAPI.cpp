#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryInput/dxinput.h>
#include <Prey/CryInput/inputcvars.h>
#include <Prey/CryGame/Game.h>
#include <Prey/GameDll/ui/UIManager.h>
#include <mem.h>
#include "SteamAPI/ArkSteamDlcSystem.h"
#include "SteamAPI/ArkSteamRewardSystem.h"
#include "SteamAPI/ChairSteamAPI.h"
#include "SteamAPI/SteamInputDevice.h"

//! Steam App ID file name.
constexpr char STEAM_APP_ID_FILE[] = "steam_appid.txt";

//! Prey's Steam App ID.
constexpr int STEAM_APP_ID = 480490;

//! Used in steam_api_chairloader.cpp only in Chairloader.
IChairSteamAPI* g_pIChairSteamAPI = nullptr;

static auto g_CDXInput_AddInputDevice_Hook = CDXInput::FAddInputDevice.MakeHook();

bool CDXInput_AddInputDevice_Hook(CBaseInput* const _this, IInputDevice* pDevice)
{
    if (pDevice->GetDeviceType() == eIDT_Gamepad)
    {
        // Init Steam Controller before any other gamepad
        static bool bTriedToInitSteamController = false;
        static bool bSteamControllerInited = false;

        if (!bTriedToInitSteamController)
        {
            // Try to initialize Steam Controller in this call
            bTriedToInitSteamController = true;
            bool useSteamController = (*g_pInputCVars)->i_useSteamController;

            if (gCL->pSteamAPI && useSteamController)
            {
                if (g_CDXInput_AddInputDevice_Hook.InvokeOrig(_this, new SteamInputDevice(*_this)))
                {
                    // Successfully initialized Steam Controller
                    bSteamControllerInited = true;
                }
                else
                {
                    // Failed to init, use DirectInput
                    CryLog("Failed to initialize SteamController. Using DXInput instead.");
                }
            }
        }

        if (bSteamControllerInited)
        {
            // Skip all other gamepads if have SteamController
            delete pDevice;
            return true;
        }
    }

    // Continue normally
    return g_CDXInput_AddInputDevice_Hook.InvokeOrig(_this, pDevice);
}

std::unique_ptr<ChairSteamAPI> ChairSteamAPI::CreateInstance()
{
    HMODULE hModule = nullptr;

    // Try Steam
    hModule = LoadLibraryA(DLL_NAME);
    if (hModule)
    {
        char path[MAX_PATH];
        GetModuleFileNameA(hModule, path, sizeof(path));
        CryLog("Found Steam API: {}", path);
        return std::make_unique<ChairSteamAPI>(hModule, false);
    }

    // Try GOG
    hModule = LoadLibraryA(GOG_DLL_NAME);
    if (hModule)
    {
        char path[MAX_PATH];
        GetModuleFileNameA(hModule, path, sizeof(path));
        CryLog("Found Galaxy API: {}", path);
        return std::make_unique<ChairSteamAPI>(hModule, true);
    }

    CryLog("{} or {} not found. Not running Steam/GOG version.", DLL_NAME, GOG_DLL_NAME);
    return nullptr;
}

ChairSteamAPI::ChairSteamAPI(void* hModuleVoid, bool isGog)
{
    assert(!g_pIChairSteamAPI);
    assert(!gCL->pSteamAPI);
    m_bIsGog = isGog;
    
    m_hModule = hModuleVoid;
    LoadFuncs();

    if (!isGog)
    {
        CreateSteamAppId();

        if (!IsSteamRunning())
            CryFatalError("Steam is not running");
    }

    if (!InitSteam())
        return;

    if (!isGog)
    {
        // Steam API is only available for Steam version
        // GOG's wrapper is too limited.
        gCL->pSteamAPI = this;
    }

    // CArkEntitlementSystem::Init
    // Remove EntitlementGranted call for Whiplash.
    // Since Steam API is available, it will be granted by the DLC system.
    mem::Nop((uint8_t*)(gCL->cl->GetPreyDllBase() + 0xD5B5BF), 0xD5B5C4 - 0xD5B5BF);
}

ChairSteamAPI::~ChairSteamAPI()
{
    m_pShutdown();

    if (m_hModule)
    {
        FreeLibrary((HMODULE)m_hModule);
        m_hModule = nullptr;
    }

    assert(!g_pIChairSteamAPI || g_pIChairSteamAPI == this);
    assert(!gCL->pSteamAPI || gCL->pSteamAPI == this);
    g_pIChairSteamAPI = nullptr;
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

    if (!m_bIsGog)
    {
        // IChairSteamAPI funcs
        fnGetFunc(m_pRegisterCallResult, "SteamAPI_RegisterCallResult");
        fnGetFunc(m_pUnregisterCallResult, "SteamAPI_UnregisterCallResult");
        fnGetFunc(m_pIsSteamRunning, "SteamAPI_IsSteamRunning");
        fnGetFunc(m_pGetHSteamUserCurrent, "Steam_GetHSteamUserCurrent");
        fnGetFunc(m_pGetSteamInstallPath, "SteamAPI_GetSteamInstallPath");
    }

    // IChairSteamAPI funcs available in GOG wrapper
    fnGetFunc(m_pGetHSteamUser, "SteamAPI_GetHSteamUser");
    fnGetFunc(m_pRegisterCallback, "SteamAPI_RegisterCallback");
    fnGetFunc(m_pUnregisterCallback, "SteamAPI_UnregisterCallback");
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

        const char* dllName = m_bIsGog ? GOG_DLL_NAME : DLL_NAME;
        CryFatalError("Failed to load functions from {}:\n{}", dllName, msg);
    }
}

void ChairSteamAPI::CreateSteamAppId()
{
    fs::path appIdPath = fs::current_path() / STEAM_APP_ID_FILE;

    if (!fs::exists(appIdPath))
    {
        std::ofstream file(appIdPath);
        file << STEAM_APP_ID << "\n";
    }
}

bool ChairSteamAPI::InitSteam()
{
    if (!m_pInit())
    {
        if (m_bIsGog)
        {
            // Non-fatal because GOG must be DRM-free.
            CryError("Galaxy API init failed. Achievements in GOG Galaxy will not work.");
        }
        else
        {
            // Fatal because see LoadFuncs
            CryFatalError("SteamAPI_Init failed");
        }

        return false;
    }

    // Initialize the context
    assert(!g_pIChairSteamAPI);
    g_pIChairSteamAPI = this;

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
    {
        if (m_bIsGog)
            CryError("SteamInternal_ContextInit returned nullptr. Achievements in GOG Galaxy will not work.");
        else
            CryFatalError("SteamInternal_ContextInit returned nullptr");

        g_pIChairSteamAPI = nullptr;
        return false;
    }

    CryLog("Steam AppID = {}", SteamUtils()->GetAppID());

    if (!m_bIsGog)
    {
        // Steam Controller support
        g_CDXInput_AddInputDevice_Hook.SetHookFunc(&CDXInput_AddInputDevice_Hook);
    }

    return true;
}
