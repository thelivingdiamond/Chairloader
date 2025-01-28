#include <shellapi.h>
#include <Prey/CryCore/Platform/WindowsUtils.h>
#include <Chairloader/Private/LoaderApi.h>
#include <Chairloader/Hooks/HookTransaction.h>
#include "ChairloaderLoader.h"

//! List of suffixes that point to Whiplash DLLs.
constexpr const wchar_t* WHIPLASH_PATHS[] = {
    L"Whiplash\\Binaries\\Danielle\\x64\\Release\\PreyDll.dll",
    L"Whiplash\\Binaries\\Danielle\\x64-Epic\\Release\\PreyDll.dll",
    L"Whiplash\\Binaries\\Danielle\\Gaming.Desktop.x64\\Release\\PreyDll.dll",
};

class NonFatalException : public std::runtime_error
{
public:
    NonFatalException(const std::string& s) : std::runtime_error(s) {}
};

ChairloaderLoader g_Loader;

EChairloaderInitResult ChairloaderLoader::Init()
{
    try
    {
        std::string errorText;

        if (!FindOrigGameDll())
        {
            ShowMsgBox(MB_OK | MB_ICONERROR, "Module '{}' not found.", ORIG_GAME_DLL_NAME);
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
            ShowMsgBox(MB_OK | MB_ICONERROR, "Failed to parse command line.");
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

        if (!IsVersionSupported(m_OrigGameDllInfo))
        {
            // Original Game DLL not supported. Load Chairloader's Game DLL
            if (!LoadChairGameDll(errorText))
            {
                ShowMsgBox(
                    MB_OK | MB_ICONERROR,
                    fmt::format("Failed to load {}: {}", CHAIR_GAME_DLL_NAME, errorText));
                return EChairloaderInitResult::Failed;
            }

            // Check that it's supported
            if (!IsVersionSupported(m_ChairGameDllInfo))
            {
                ShowMsgBox(
                    MB_OK | MB_ICONERROR,
                    fmt::format(
                        "{} is not supported by Chairloader.\n"
                        "Patch the game in Chairloader Mod Manager.",
                        CHAIR_GAME_DLL_NAME));

                // Fatal error because a new DLL was loaded
                return EChairloaderInitResult::Fatal;
            }
        }

        if (!LoadChairloader(errorText))
        {
            ShowMsgBox(MB_OK | MB_ICONERROR, "Failed to load {}:\n{}", CHAIRLOADER_DLL_NAME, errorText);
            return EChairloaderInitResult::Fatal;
        }

        return EChairloaderInitResult::Ok;
    }
    catch (const NonFatalException& e)
    {
        ShowMsgBox(MB_OK | MB_ICONERROR, "Failed to load Chairloader: {}", e.what());
        return EChairloaderInitResult::Failed;
    }
    catch (const std::exception& e)
    {
        ShowMsgBox(MB_OK | MB_ICONERROR, "Unexpected exception: {}", e.what());
        return EChairloaderInitResult::Fatal;
    }
}

void ChairloaderLoader::Shutdown()
{
    if (m_hChairDll)
    {
        FreeLibrary(m_hChairDll);
        m_hChairDll = nullptr;
    }

    if (m_ChairGameDllInfo)
    {
        // Loaded by this DLL
        if (m_EntryMainHook.IsHooked())
        {
            HookTransaction tr;
            m_EntryMainHook.RemoveHook();
            tr.Commit();
        }

        FreeLibrary(m_ChairGameDllInfo.hModule);
        m_ChairGameDllInfo.SetHandle(nullptr);
    }

    if (m_OrigGameDllInfo)
    {
        // Not loaded by this DLL - not unloaded too
        m_OrigGameDllInfo.SetHandle(nullptr);
    }
}

bool ChairloaderLoader::FindOrigGameDll()
{
    LogDebug("FindOrigGameDll");
    CRY_ASSERT(!m_OrigGameDllInfo);
    HMODULE hModule = GetModuleHandle(ORIG_GAME_DLL_NAME);

    if (hModule)
    {
        LogDebug("hModule = {:p}", (void*)hModule);
        m_OrigGameDllInfo.SetHandle(hModule);
        return true;
    }

    return false;
}

bool ChairloaderLoader::IsWhiplash()
{
    CRY_ASSERT(m_OrigGameDllInfo);

    // Check if the loaded PreyDll.dll is from Mooncrash.
    wchar_t preyDllPath[MAX_PATH] = {};
    int pathLen = GetModuleFileNameW(m_OrigGameDllInfo.hModule, preyDllPath, std::size(preyDllPath));

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
        {
            LogDebug("Chairloader disabled by command line {}", i);
            return false;
        }
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

bool ChairloaderLoader::IsVersionSupported(const GameModuleInfo& gameDll)
{
    for (const GameVersionInfo& versionInfo : m_SupportedVersions)
    {
        bool isSupported = gameDll.CompareTestString(versionInfo.testString, versionInfo.testStringOffset);

        if (isSupported)
        {
            LogDebug("[{:p}] {} - Supported", (void*)gameDll.hModule, versionInfo.name);
            return true;
        }
        else
        {
            LogDebug("[{:p}] {} - Not Supported", (void*)gameDll.hModule, versionInfo.name);
        }
    }

    return false;
}

bool ChairloaderLoader::LoadChairGameDll(std::string& outError)
{
    LogDebug("LoadChairGameDll");
    CRY_ASSERT(!m_ChairGameDllInfo);
    CRY_ASSERT(m_OrigGameDllInfo);

    std::vector<wchar_t> buf(2048);
    size_t bufLen = GetModuleFileNameW(m_OrigGameDllInfo.hModule, buf.data(), buf.size());

    if (bufLen == 0)
    {
        outError = "Failed to get Game DLL path";
        return false;
    }

    if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
    {
        outError = "Game DLL path is too long";
        return false;
    }

    fs::path origDllPath = fs::path(std::wstring_view(buf.data(), bufLen));
    fs::path chairDllPath = origDllPath.parent_path() / CHAIR_GAME_DLL_NAME;

    if (!fs::exists(chairDllPath))
    {
        outError = fmt::format("File {} not found. Rerun ChairManager.");
        return false;
    }

    HMODULE hChairGameDll = LoadLibraryExW(chairDllPath.c_str(), nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);

    if (!hChairGameDll)
    {
        outError = WindowsErrorToString(::GetLastError());
        return false;
    }

    LogDebug("hChairGameDll = {:p}", (void*)hChairGameDll);
    m_ChairGameDllInfo.SetHandle(hChairGameDll);

    // Hook EntryMain
    {
        auto* pfnEntryMain = reinterpret_cast<FnEntryMain*>(GetProcAddress(g_Loader.m_OrigGameDllInfo.hModule, ENTRY_MAIN));

        if (!pfnEntryMain)
        {
            LogDebug("{} not found in hOrigGameDll", ENTRY_MAIN);
            return false;
        }

        HookTransaction tr;
        m_EntryMainHook.InstallHook(pfnEntryMain, &ChairEntryMain);
        tr.Commit();
    }

    return true;
}

bool ChairloaderLoader::LoadChairloader(std::string& outError)
{
    LogDebug("LoadChairloader");
    CRY_ASSERT(m_OrigGameDllInfo);
    CRY_ASSERT(!m_hChairDll);

    HMODULE hGameDll = m_ChairGameDllInfo ? m_ChairGameDllInfo.hModule : m_OrigGameDllInfo.hModule;
    HMODULE hChairDll = LoadLibraryExA(CHAIRLOADER_DLL_NAME, nullptr, LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    
    if (!hChairDll)
    {
        outError = WindowsErrorToString(::GetLastError());
        return false;
    }

    // Init Chairloader
    auto* pfnChairInit = reinterpret_cast<FnChairloaderInit*>(GetProcAddress(hChairDll, FN_CHAIRLOADER_INIT));

    if (!pfnChairInit)
    {
        outError = fmt::format("{} not found in {}", FN_CHAIRLOADER_INIT, CHAIRLOADER_DLL_NAME);
        return false;
    }

    LogDebug("Initializing Chairloader");
    bool initResult = pfnChairInit(hGameDll);

    if (!initResult)
    {
        outError = "Chairloader failed to initialize";
        return false;
    }

    LogDebug("hChairDll = {:p}", (void*)hChairDll);
    m_hChairDll = hChairDll;
    return true;
}

int ChairloaderLoader::ChairEntryMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nCmdShow)
{
    CRY_ASSERT(g_Loader.m_ChairGameDllInfo);

    auto* pfnEntryMain = reinterpret_cast<FnEntryMain*>(GetProcAddress(g_Loader.m_ChairGameDllInfo.hModule, ENTRY_MAIN));

    if (!pfnEntryMain)
    {
        LogDebug("{} not found in hChairGameDllInfo", ENTRY_MAIN);
        return 1;
    }

    LogDebug("Starting up {} instead of {}", CHAIR_GAME_DLL_NAME, ORIG_GAME_DLL_NAME);
    return pfnEntryMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

void ChairloaderLoader::ShowMsgBoxV(UINT type, std::string_view format, fmt::format_args args)
{
    std::string text = fmt::vformat(format, args);
    std::wstring wtext;
    Unicode::Convert(wtext, text);
    MessageBoxW(nullptr, wtext.c_str(), MSGBOX_CAPTION, type);
}

void ChairloaderLoader::LogDebugV(std::string_view format, fmt::format_args args)
{
    std::string text = "[Chairloader.Loader] " + fmt::vformat(format, args) + "\n";
    std::wstring wtext;
    Unicode::Convert(wtext, text);
    OutputDebugStringW(wtext.c_str());
}
