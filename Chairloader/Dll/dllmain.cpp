// dllmain.cpp : Defines the entry point for the DLL application.
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Chairloader/PreditorAPI.h>
#include "Chairloader.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        Chairloader::CreateInstance(hModule);
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
