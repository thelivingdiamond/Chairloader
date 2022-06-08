#include <string>
#include <windows.h>
#include <detours/detours.h>
#include "mswsock_proxy.h"

namespace {
constexpr uintptr_t OFFSET_CGAME_INIT = 0x16D0A90;

class CGame;
class IGameFramework;
using CGame_Init = char(__fastcall *)(CGame *thisPtr, IGameFramework *pFramework);

CGame_Init pfnGameInit;

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

char __fastcall CGameInitHook(CGame *thisPtr, IGameFramework *pFramework) {
    int ret = pfnGameInit(thisPtr, pFramework);

    HMODULE loader = LoadLibraryA("ChairLoader.dll");
    if (!loader) {
        std::string text = "Failed to load ChairLoader\n" + GetLastErrorAsString();
        MessageBoxA(nullptr, text.c_str(), "ChairLoader Loader Error", MB_OK | MB_ICONERROR);
        return 0;
    }

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

