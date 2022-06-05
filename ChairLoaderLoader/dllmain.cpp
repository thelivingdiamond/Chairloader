#include <windows.h>
#include <detours/detours.h>
#include "mswsock_proxy.h"

namespace {
constexpr uintptr_t OFFSET_CGAME_INIT = 0x16D0A90;

class CGame;
class IGameFramework;
using CGame_Init = char(__fastcall *)(CGame *thisPtr, IGameFramework *pFramework);

CGame_Init pfnGameInit;

char __fastcall CGameInitHook(CGame *thisPtr, IGameFramework *pFramework) {
    int ret = pfnGameInit(thisPtr, pFramework);
    LoadLibraryA("ChairLoader.dll");
    return ret;
}

void InstallHooks() {
    HMODULE prey = LoadLibraryA("PreyDll.dll");
    pfnGameInit = reinterpret_cast<CGame_Init>((uintptr_t)prey + OFFSET_CGAME_INIT);
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(LPVOID &)pfnGameInit, (PBYTE)CGameInitHook);
    DetourTransactionCommit();
}
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MSWSProxy_Init();
        InstallHooks();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        MSWSProxy_Shutdown();
        break;
    }
    return TRUE;
}

