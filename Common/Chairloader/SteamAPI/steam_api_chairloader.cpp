#include <Chairloader/SteamAPI/IChairSteamAPI.h>

S_API HSteamUser SteamAPI_GetHSteamUser()
{
    return gCL->pSteamAPI->GetHSteamUser();
}

S_API void S_CALLTYPE SteamAPI_RegisterCallback(class CCallbackBase* pCallback, int iCallback)
{
    gCL->pSteamAPI->RegisterCallback(pCallback, iCallback);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallback(class CCallbackBase* pCallback)
{
    gCL->pSteamAPI->UnregisterCallback(pCallback);
}

S_API void S_CALLTYPE SteamAPI_RegisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    gCL->pSteamAPI->RegisterCallResult(pCallback, hAPICall);
}

S_API void S_CALLTYPE SteamAPI_UnregisterCallResult(class CCallbackBase* pCallback, SteamAPICall_t hAPICall)
{
    gCL->pSteamAPI->UnregisterCallResult(pCallback, hAPICall);
}

S_API bool S_CALLTYPE SteamAPI_IsSteamRunning()
{
    return gCL->pSteamAPI->IsSteamRunning();
}

S_API HSteamUser Steam_GetHSteamUserCurrent()
{
    return gCL->pSteamAPI->GetHSteamUserCurrent();
}

S_API const char* SteamAPI_GetSteamInstallPath()
{
    return gCL->pSteamAPI->GetSteamInstallPath();
}

S_API HSteamPipe SteamAPI_GetHSteamPipe()
{
    return gCL->pSteamAPI->GetHSteamPipe();
}

S_API void* S_CALLTYPE SteamInternal_CreateInterface(const char* ver)
{
    return gCL->pSteamAPI->Internal_CreateInterface(ver);
}

CSteamAPIContext& SteamInternal_ModuleContext()
{
    return gCL->pSteamAPI->GetContext();
}
