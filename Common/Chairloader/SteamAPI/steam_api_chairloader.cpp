#include <Chairloader/SteamAPI/IChairSteamAPI.h>

#ifndef CHAIRLOADER_MOD_SDK
extern IChairSteamAPI* g_pIChairSteamAPI;
static CSteamAPIContext g_EmptyContext;
#endif

static inline IChairSteamAPI* GetIChairSteamAPI()
{
#ifdef CHAIRLOADER_MOD_SDK
    // Use the pointer from gCL
    return gCL->pSteamAPI;
#else
    // Use g_pIChairSteamAPI in Chairloader.
    // GOG integration partially emulates Steam API but not enough to expose it to mods.
    return g_pIChairSteamAPI;
#endif
}

S_API HSteamUser SteamAPI_GetHSteamUser()
{
    return GetIChairSteamAPI()->GetHSteamUser();
}

S_API void S_CALLTYPE SteamAPI_RegisterCallback(class CCallbackBase* pCallback, int iCallback)
{
    GetIChairSteamAPI()->RegisterCallback(pCallback, iCallback);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallback(class CCallbackBase* pCallback)
{
    GetIChairSteamAPI()->UnregisterCallback(pCallback);
}

S_API void S_CALLTYPE SteamAPI_RegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    GetIChairSteamAPI()->RegisterCallResult(pCallback, hAPICall);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    GetIChairSteamAPI()->UnregisterCallResult(pCallback, hAPICall);
}

S_API bool S_CALLTYPE SteamAPI_IsSteamRunning()
{
    return GetIChairSteamAPI()->IsSteamRunning();
}

S_API HSteamUser Steam_GetHSteamUserCurrent()
{
    return GetIChairSteamAPI()->GetHSteamUserCurrent();
}

S_API const char* SteamAPI_GetSteamInstallPath()
{
    return GetIChairSteamAPI()->GetSteamInstallPath();
}

S_API HSteamPipe SteamAPI_GetHSteamPipe()
{
    return GetIChairSteamAPI()->GetHSteamPipe();
}

S_API void* S_CALLTYPE SteamInternal_CreateInterface(const char* ver)
{
    return GetIChairSteamAPI()->Internal_CreateInterface(ver);
}

CSteamAPIContext& SteamInternal_ModuleContext()
{
#ifdef CHAIRLOADER_MOD_SDK
    // Use the pointer from gCL
    return GetIChairSteamAPI()->GetContext();
#else
    // Use g_pIChairSteamAPI in Chairloader.
    // GOG integration partially emulates Steam API but not enough to expose it to mods.
    return g_pIChairSteamAPI ? g_pIChairSteamAPI->GetContext() : g_EmptyContext;
#endif
}
