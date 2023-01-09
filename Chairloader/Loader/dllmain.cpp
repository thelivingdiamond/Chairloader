#include <string>
#include <windows.h>
#include "mswsock_proxy.h"

namespace {
HMODULE g_CLModule = nullptr;

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

void LoadChairLoader()
{
    // Parse the console args
    {
        int argc = 0;
        wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);
        bool disableChair = false;

        for (int i = 0; i < argc; i++)
        {
            if (!_wcsicmp(argv[i], L"-nochair"))
                disableChair = true;
        }

        LocalFree(argv);

        if (disableChair)
            return; // Disabled via cmd line
    }

    HMODULE hPreyDll = GetModuleHandle("PreyDll.dll");
    if (!hPreyDll)
    {
        MessageBoxA(nullptr, "PreyDll.dll is not loaded.", "Chairloader Loader Error", MB_OK | MB_ICONERROR);
        std::abort();
    }

    {
        // Mooncrash is loaded by the same Prey.exe so it will also load mswsock.dll.
        // Check if the loaded PreyDll.dll is from Mooncrash.
        wchar_t* mooncrashPaths[] = {
            L"Whiplash\\Binaries\\Danielle\\x64\\Release\\PreyDll.dll",
            L"Whiplash\\Binaries\\Danielle\\x64-Epic\\Release\\PreyDll.dll",
        };
        wchar_t preyDllPath[MAX_PATH] = {};
        int pathLen = GetModuleFileNameW(hPreyDll, preyDllPath, std::size(preyDllPath));

        // Convert slashes to backslashes (just in case)
        for (wchar_t& c : preyDllPath)
        {
            if (c == '/')
                c = '\\';
        }

        for (wchar_t* prefix : mooncrashPaths)
        {
            int prefixLen = wcslen(prefix);
            if (pathLen >= prefixLen && !_wcsicmp(prefix, preyDllPath + pathLen - prefixLen))
            {
                // Loading Mooncrash, don't load Chairloader
                return;
            }
        }
    }

    g_CLModule = LoadLibraryExA("ChairLoader.dll", nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    if (!g_CLModule) {
        std::string text = "Failed to load ChairLoader\n" + GetLastErrorAsString();
        MessageBoxA(nullptr, text.c_str(), "Chairloader Loader Error", MB_OK | MB_ICONERROR);
        std::abort();
    }
}

void ShutdownChairLoader()
{
    if (g_CLModule)
    {
        FreeLibrary(g_CLModule);
        g_CLModule = nullptr;
    }
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
        LoadChairLoader();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        ShutdownChairLoader();
        MSWSProxy_Shutdown();
        break;
    }
    return TRUE;
}

