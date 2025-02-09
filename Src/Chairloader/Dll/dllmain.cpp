// dllmain.cpp : Defines the entry point for the DLL application.
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Chairloader/Private/LoaderApi.h>
#include <Chairloader/PreditorAPI.h>
#include "Chairloader.h"

static HMODULE s_hThisDll;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        s_hThisDll = hModule;
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" DLL_EXPORT IChairToPreditor* Chair_GetPreditorAPI(int preditorVersion, int* chairVersion)
{
    *chairVersion = PREDITOR_API_VERSION;
    if (preditorVersion != PREDITOR_API_VERSION)
        return nullptr;
    return Chairloader::Get();
}

extern "C" DLL_EXPORT bool Chair_Init(void* hGameDll)
{
    try
    {
        Chairloader::CreateInstance(s_hThisDll, hGameDll);
        Chairloader::Get()->EarlyInit();
        return true;
    }
    catch (...)
    {
        return false;
    }
}

static_assert(std::is_same_v<FnChairloaderInit, decltype(Chair_Init)>, "Chair_Init not compatible with FnChairloaderInit");
