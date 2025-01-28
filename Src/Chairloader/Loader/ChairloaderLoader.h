#pragma once
#include <Chairloader/Hooks/FunctionHook.h>
#include "GameModuleInfo.h"
#include "GameVersionInfo.h"

enum class EChairloaderInitResult
{
    //! Chairloader was loaded.
    Ok,

    //! Chairloader failed to load.
    Failed,

    //! Game is in an inconsistent state and must be killed.
    Fatal,

    //! Loading was skipped
    Skipped,
};

class ChairloaderLoader
{
public:
    static constexpr wchar_t MSGBOX_CAPTION[] = L"Chairloader Loader Error";

    EChairloaderInitResult Init();
    void Shutdown();

private:
    using FnEntryMain = int(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nCmdShow);

    static constexpr char ORIG_GAME_DLL_NAME[] = "PreyDll.dll";
    static constexpr char CHAIR_GAME_DLL_NAME[] = "PreyDll.Chairloader.dll";
    static constexpr char CHAIRLOADER_DLL_NAME[] = "Chairloader.dll";
    static constexpr char ENTRY_MAIN[] = "EntryMain";

    //! The original Game DLL module.
    GameModuleInfo m_OrigGameDllInfo;

    //! The Chairloader Game DLL module.
    GameModuleInfo m_ChairGameDllInfo;

    //! Hook of original Game DLL's EntryMain.
    FunctionHook<int(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nCmdShow)> m_EntryMainHook;

    //! The Chairloader DLL module.
    HMODULE m_hChairDll = nullptr;

    //! The list of command line arguments.
    std::vector<std::string> m_CmdLineArgs;

    //! The list of versions supported by Chairloader.
    std::vector<GameVersionInfo> m_SupportedVersions;

    //! Finds the loaded Game DLL.
    bool FindOrigGameDll();

    //! @returns Whether currently launching Whiplash.
    bool IsWhiplash();

    //! Fills m_CmdLineArgs with command line arguments.
    bool ParseCommandLine();

    //! Checks whether Chairloader DLL is enabled.
    bool IsChairloaderEnabled();

    //! Reads the list of supported versions.
    bool ReadSupportedVersions(std::string& outError);

    //! Checks if the current Game DLL is supported.
    bool IsVersionSupported(const GameModuleInfo& gameDll);

    //! Loads Chairloader Game DLL.
    bool LoadChairGameDll(std::string& outError);

    //! Loads the Chairloader DLL. Can either fully succeed or fully fail.
    bool LoadChairloader(std::string& outError);

    //! Hook of orig Game DLL's EntryMain.
    //! Calls Chair GameDLL's EntryMain.
    static int ChairEntryMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nCmdShow);

    static void ShowMsgBoxV(UINT type, std::string_view format, fmt::format_args args);
    
    template <typename... Args>
    static inline void ShowMsgBox(UINT type, std::string_view format, const Args &...args) { ShowMsgBoxV(type, format, fmt::make_format_args(args...)); }

    static void LogDebugV(std::string_view format, fmt::format_args args);

    template <typename... Args>
    static inline void LogDebug(std::string_view format, const Args &...args) { LogDebugV(format, fmt::make_format_args(args...)); }
};

extern ChairloaderLoader g_Loader;
