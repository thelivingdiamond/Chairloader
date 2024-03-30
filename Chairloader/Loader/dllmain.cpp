#include <string>
#include "ChairloaderLoader.h"
#include "mswsock_proxy.h"
#include <Prey/CryCore/Platform/platform_impl.inl>

// TODO 2024-03-30: Remove this
struct ChairloaderGlobalEnvironment* gCL;

static void InitChairloader()
{
    EChairloaderInitResult result = g_Loader.Init();

    switch (result)
    {
    case EChairloaderInitResult::Ok:
    case EChairloaderInitResult::Skipped:
        // Nothing to do
        break;
    case EChairloaderInitResult::Failed:
        MessageBoxW(nullptr,
            L"Game will be launched without DLL mod support.\n"
            L"Merged mods will continue to work.",
            ChairloaderLoader::MSGBOX_CAPTION,
            MB_OK | MB_ICONERROR);
        break;
    case EChairloaderInitResult::Fatal:
        MessageBoxW(nullptr,
            L"Fatal error has occured in Chairloader Loader.\n"
            L"Game will now exit.",
            ChairloaderLoader::MSGBOX_CAPTION,
            MB_OK | MB_ICONERROR);

        ExitProcess(-451);
        break;
    }
}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MSWSProxy_Init();
        InitChairloader();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        g_Loader.Shutdown();
        MSWSProxy_Shutdown();
        break;
    }
    return TRUE;
}
