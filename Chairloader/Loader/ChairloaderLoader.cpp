#include <shellapi.h>
#include <Prey/CryCore/Platform/WindowsUtils.h>
#include "ChairloaderLoader.h"

//! List of suffixes that point to Whiplash DLLs.
constexpr const wchar_t* WHIPLASH_PATHS[] = {
    L"Whiplash\\Binaries\\Danielle\\x64\\Release\\PreyDll.dll",
    L"Whiplash\\Binaries\\Danielle\\x64-Epic\\Release\\PreyDll.dll",
};

ChairloaderLoader g_Loader;

EChairloaderInitResult ChairloaderLoader::Init()
{
    try
    {
        std::string errorText;

        if (!FindGameDll())
        {
            ShowMsgBox(MB_OK | MB_ICONERROR, "Module '{}' not found.", GAME_DLL_NAME);
            return EChairloaderInitResult::Failed;
        }

        if (IsWhiplash())
        {
            // Mooncrash is loaded by the same Prey.exe so it will also load mswsock.dll.
            // Mooncrash is not supported at the moment
            return EChairloaderInitResult::Skipped;
        }

        if (!ParseCommandLine())
        {
            ShowMsgBox(MB_OK | MB_ICONERROR, "Failed to parse command line.", GAME_DLL_NAME);
            return EChairloaderInitResult::Failed;
        }

        if (!IsChairloaderEnabled())
        {
            // Disabled by the user
            return EChairloaderInitResult::Skipped;
        }

        if (!ReadSupportedVersions(errorText))
        {
            ShowMsgBox(MB_OK | MB_ICONERROR, "Failed to load the list of supported versions:\n{}", errorText);
            return EChairloaderInitResult::Failed;
        }

        if (!IsVersionSupported())
        {
            ShowMsgBox(
                MB_OK | MB_ICONERROR,
                "Currently running version of the game is not supported.\n"
                "Patch the game in Chairloader Mod Manager.");
            return EChairloaderInitResult::Failed;
        }

        if (!LoadChairloader(errorText))
        {
            ShowMsgBox(MB_OK | MB_ICONERROR, "Failed to load {}:\n{}", CHAIRLOADER_DLL_NAME, errorText);
            return EChairloaderInitResult::Failed;
        }

        return EChairloaderInitResult::Ok;
    }
    catch (const std::exception& e)
    {
        ShowMsgBox(MB_OK | MB_ICONERROR, "Unexpected exception: {}", e.what());
        return EChairloaderInitResult::Fatal;
    }
}

void ChairloaderLoader::Shutdown()
{
    if (m_GameDllInfo)
    {
        // Not loaded by this DLL - not unloaded too
        m_GameDllInfo.SetHandle(nullptr);
    }

    if (m_hChairDll)
    {
        FreeLibrary(m_hChairDll);
        m_hChairDll = nullptr;
    }
}

bool ChairloaderLoader::FindGameDll()
{
    CRY_ASSERT(!m_GameDllInfo);
    HMODULE hModule = GetModuleHandle(GAME_DLL_NAME);

    if (hModule)
    {
        m_GameDllInfo.SetHandle(hModule);
        return true;
    }

    return false;
}

bool ChairloaderLoader::IsWhiplash()
{
    CRY_ASSERT(m_GameDllInfo);

    // Check if the loaded PreyDll.dll is from Mooncrash.
    wchar_t preyDllPath[MAX_PATH] = {};
    int pathLen = GetModuleFileNameW(m_GameDllInfo.hModule, preyDllPath, std::size(preyDllPath));

    // Convert slashes to backslashes (just in case)
    for (wchar_t& c : preyDllPath)
    {
        if (c == '/')
            c = '\\';
    }

    for (const wchar_t* suffix : WHIPLASH_PATHS)
    {
        int suffixLen = wcslen(suffix);
        if (pathLen >= suffixLen && !_wcsicmp(suffix, preyDllPath + pathLen - suffixLen))
        {
            return true;
        }
    }

    return false;
}

bool ChairloaderLoader::ParseCommandLine()
{
    int argc = 0;
    wchar_t** argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    m_CmdLineArgs.resize(argc);

    for (int i = 0; i < argc; i++)
    {
        std::wstring_view argWide = argv[i];
        std::string argUtf8;
        Unicode::Convert(argUtf8, argWide.begin(), argWide.end());
        m_CmdLineArgs[i] = std::move(argUtf8);
    }

    LocalFree(argv);
    return true;
}

bool ChairloaderLoader::IsChairloaderEnabled()
{
    for (const std::string& i : m_CmdLineArgs)
    {
        if (i == "-nochair")
            return false;
    }

    // Enabled by default
    return true;
}

bool ChairloaderLoader::ReadSupportedVersions(std::string& outError)
{
    CRY_ASSERT(m_SupportedVersions.empty());

    // Only one version is supported at the moment
    m_SupportedVersions.push_back(GameVersionInfo{
        "EGS-2021-08-18",
        "BuildTime: Aug 18 2021 20:20:55",
        0x1D8CBB8,
    });

    outError = "";
    return true;
}

bool ChairloaderLoader::IsVersionSupported()
{
    for (const GameVersionInfo& versionInfo : m_SupportedVersions)
    {
        bool isSupported = m_GameDllInfo.CompareTestString(versionInfo.testString, versionInfo.testStringOffset);
        if (isSupported)
            return true;
    }

    return false;
}

bool ChairloaderLoader::LoadChairloader(std::string& outError)
{
    CRY_ASSERT(m_GameDllInfo);
    CRY_ASSERT(!m_hChairDll);
    HMODULE hChairDll = LoadLibraryExA(CHAIRLOADER_DLL_NAME, nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    
    if (hChairDll)
    {
        m_hChairDll = hChairDll;
        return true;
    }

    outError = WindowsErrorToString(::GetLastError());
    return false;
}

void ChairloaderLoader::ShowMsgBoxV(UINT type, std::string_view format, fmt::format_args args)
{
    std::string text = fmt::vformat(format, args);
    std::wstring wtext;
    Unicode::Convert(wtext, text);
    MessageBoxW(nullptr, wtext.c_str(), MSGBOX_CAPTION, type);
}
