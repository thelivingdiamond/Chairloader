#pragma once
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
    static constexpr char GAME_DLL_NAME[] = "PreyDll.dll";
    static constexpr char CHAIRLOADER_DLL_NAME[] = "Chairloader.dll";

    //! The Game DLL module.
    GameModuleInfo m_GameDllInfo;

    //! The Chairloader DLL module.
    HMODULE m_hChairDll = nullptr;

    //! The list of command line arguments.
    std::vector<std::string> m_CmdLineArgs;

    //! The list of versions supported by Chairloader.
    std::vector<GameVersionInfo> m_SupportedVersions;

    //! Finds the loaded Game DLL.
    bool FindGameDll();

    //! @returns Whether currently launching Whiplash.
    bool IsWhiplash();

    //! Fills m_CmdLineArgs with command line arguments.
    bool ParseCommandLine();

    //! Checks whether Chairloader DLL is enabled.
    bool IsChairloaderEnabled();

    //! Reads the list of supported versions.
    bool ReadSupportedVersions(std::string& outError);

    //! Checks if the current Game DLL is supported.
    bool IsVersionSupported();

    //! Loads the Chairloader DLL. Can either fully succeed or fully fail.
    bool LoadChairloader(std::string& outError);

    static void ShowMsgBoxV(UINT type, std::string_view format, fmt::format_args args);
    
    template <typename... Args>
    inline void ShowMsgBox(UINT type, std::string_view format, const Args &...args) { ShowMsgBoxV(type, format, fmt::make_format_args(args...)); }
};

extern ChairloaderLoader g_Loader;
