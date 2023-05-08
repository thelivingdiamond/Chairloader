#pragma once
#include <Chairloader/SteamAPI/steam_api.h>

//! Steam API DLL wrappers. The library is loaded by Chairloader.
struct IChairSteamAPI
{
    //! The name of Steam API DLL.
    static constexpr char DLL_NAME[] = "steam_api64.dll";

    virtual ~IChairSteamAPI() {}

    //! CSteamAPIContext is marked as deprecated but actually
    //! used internally by the API. Because Valve.
    //! @returns the Steam API context.
    virtual CSteamAPIContext& GetContext() = 0;

    //! @returns the SteamAPI DLL handle. Actual type is HMODULE.
    virtual void* GetDllHandle() = 0;

    //! Functions exported from steam_api64.dll
    //! @{
    virtual HSteamUser GetHSteamUser() = 0;
    virtual void RegisterCallback(CCallbackBase* pCallback, int iCallback) = 0;
    virtual void UnregisterCallback(CCallbackBase* pCallback) = 0;
    virtual void RegisterCallResult(CCallbackBase* pCallback, SteamAPICall_t hAPICall) = 0;
    virtual void UnregisterCallResult(CCallbackBase* pCallback, SteamAPICall_t hAPICall) = 0;
    virtual bool IsSteamRunning() = 0;
    virtual HSteamUser GetHSteamUserCurrent() = 0;
    virtual const char* GetSteamInstallPath() = 0;
    virtual HSteamPipe GetHSteamPipe() = 0;
    virtual void* Internal_CreateInterface(const char* ver) = 0;
    //! @}
};
