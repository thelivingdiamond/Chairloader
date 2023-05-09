#pragma once
#include <Chairloader/SteamAPI/IChairSteamAPI.h>

class ChairSteamAPI final : public IChairSteamAPI, NoCopy
{
public:
    //! Creates an instance of ChairSteamAPI if Steam API is available.
    //! @returns instance or nullptr.
    static std::unique_ptr<ChairSteamAPI> CreateInstance();

    //! @param  hModule DLL handle.
    //! @param  isGog   GOG version.
    ChairSteamAPI(void* hModule, bool isGog);
    ~ChairSteamAPI();

    //! Initializes various Ark???System that replace ones created in CSystem::Init.
    void ReplaceArkSystems();

    //! Runs Steam callbacks.
    void Update();

    // IChairSteamAPI
    virtual CSteamAPIContext& GetContext() override { return *m_pContext; }
    virtual void* GetDllHandle() override { return m_hModule; }

    virtual HSteamUser GetHSteamUser() override { return m_pGetHSteamUser(); }
    virtual void RegisterCallback(CCallbackBase* pCallback, int iCallback) override { return m_pRegisterCallback(pCallback, iCallback); }
    virtual void UnregisterCallback(CCallbackBase* pCallback) override { return m_pUnregisterCallback(pCallback); }
    virtual void RegisterCallResult(CCallbackBase* pCallback, SteamAPICall_t hAPICall) override { return m_pRegisterCallResult(pCallback, hAPICall); }
    virtual void UnregisterCallResult(CCallbackBase* pCallback, SteamAPICall_t hAPICall) override { return m_pUnregisterCallResult(pCallback, hAPICall); }
    virtual bool IsSteamRunning() override { return m_pIsSteamRunning(); }
    virtual HSteamUser GetHSteamUserCurrent() override { return m_pGetHSteamUserCurrent(); }
    virtual const char* GetSteamInstallPath() override { return m_pGetSteamInstallPath(); }
    virtual HSteamPipe GetHSteamPipe() override { return m_pGetHSteamPipe(); }
    virtual void* Internal_CreateInterface(const char* ver) { return m_pCreateInterface(ver); }

private:
    //! DLL handle.
    void* m_hModule = nullptr;

    //! Using GOG version's Steam API wrapper.
    bool m_bIsGog = false;

    //! The context pointer
    CSteamAPIContext* m_pContext = nullptr;

    //! DLL function pointers (in IChairSteamAPI)
    //! @{
    decltype(&SteamAPI_GetHSteamUser) m_pGetHSteamUser = nullptr;
    decltype(&SteamAPI_RegisterCallback) m_pRegisterCallback = nullptr;
    decltype(&SteamAPI_UnregisterCallback) m_pUnregisterCallback = nullptr;
    decltype(&SteamAPI_RegisterCallResult) m_pRegisterCallResult = nullptr;
    decltype(&SteamAPI_UnregisterCallResult) m_pUnregisterCallResult = nullptr;
    decltype(&SteamAPI_IsSteamRunning) m_pIsSteamRunning = nullptr;
    decltype(&Steam_GetHSteamUserCurrent) m_pGetHSteamUserCurrent = nullptr;
    decltype(&SteamAPI_GetSteamInstallPath) m_pGetSteamInstallPath = nullptr;
    decltype(&SteamAPI_GetHSteamPipe) m_pGetHSteamPipe = nullptr;
    decltype(&SteamInternal_CreateInterface) m_pCreateInterface = nullptr;
    //! @}
    
    //! DLL function pointers (used internally)
    //! @{
    decltype(&SteamAPI_Init) m_pInit = nullptr;
    decltype(&SteamAPI_Shutdown) m_pShutdown = nullptr;
    decltype(&SteamInternal_ContextInit) m_pContextInit = nullptr;
    decltype(&SteamAPI_RunCallbacks) m_pRunCallbacks = nullptr;
    //! @}

    //! Loads functions from the DLL.
    void LoadFuncs();

    //! Initializes Steam API.
    void InitSteam();
};
