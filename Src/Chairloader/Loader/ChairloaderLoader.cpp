#include <shellapi.h>
#include <Prey/CryCore/Platform/WindowsUtils.h>
#include "ChairloaderLoader.h"

//! List of suffixes that point to Whiplash DLLs.
constexpr const wchar_t* WHIPLASH_PATHS[] = {
    L"Whiplash\\Binaries\\Danielle\\x64\\Release\\PreyDll.dll",
    L"Whiplash\\Binaries\\Danielle\\x64-Epic\\Release\\PreyDll.dll",
    L"Whiplash\\Binaries\\Danielle\\Gaming.Desktop.x64\\Release\\PreyDll.dll",
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

        if (!DetectFlavor())
        {
            ShowMsgBox(MB_OK | MB_ICONERROR, "Failed to read the path of '{}'.", GAME_DLL_NAME);
            return EChairloaderInitResult::Failed;
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
                "Currently running version of the game ({}) is not supported.\n"
                "Patch the game in Chairloader Mod Manager.",
                IsWhiplash() ? "Mooncrash" : "Prey");
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

bool ChairloaderLoader::DetectFlavor()
{
    CRY_ASSERT(m_GameDllInfo);

    wchar_t preyDllPath[MAX_PATH] = {};
    DWORD pathLen = GetModuleFileNameW(m_GameDllInfo.hModule, preyDllPath, (DWORD)std::size(preyDllPath));
    if (pathLen == 0 || pathLen >= std::size(preyDllPath))
        return false;

    // Convert slashes to backslashes (just in case)
    for (wchar_t& c : preyDllPath)
    {
        if (c == '/')
            c = '\\';
    }

    // Mooncrash ships its own PreyDll.dll under Whiplash\ and is launched by the same Prey.exe
    m_Flavor = EGameFlavor::Prey;
    for (const wchar_t* suffix : WHIPLASH_PATHS)
    {
        size_t suffixLen = wcslen(suffix);
        if (pathLen >= suffixLen && !_wcsicmp(suffix, preyDllPath + pathLen - suffixLen))
        {
            m_Flavor = EGameFlavor::Mooncrash;
            break;
        }
    }

    // Remember the directory: Chairloader.dll lives next to the game DLL it was built for
    std::wstring_view pathView(preyDllPath, pathLen);
    size_t slash = pathView.find_last_of(L'\\');
    m_GameDllDir = std::wstring(pathView.substr(0, slash == std::wstring_view::npos ? 0 : slash + 1));
    return !m_GameDllDir.empty();
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

    // The test string is the DLL's "BuildTime: ..." literal (tools/pe_find_string.py prints its RVA).
    switch (m_Flavor)
    {
    case EGameFlavor::Prey:
        m_SupportedVersions.push_back(GameVersionInfo{
            "EGS-2021-08-18",
            "BuildTime: Aug 18 2021 20:20:55",
            0x1D8CBB8,
        });
        break;
    case EGameFlavor::Mooncrash:
        m_SupportedVersions.push_back(GameVersionInfo{
            "Mooncrash-2021-08-18",
            "BuildTime: Aug 18 2021 20:04:57",
            0x1EC5BD8,
        });
        break;
    }

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
    // Load the Chairloader.dll that sits next to the loaded game DLL 
    std::wstring chairDllPath = m_GameDllDir;
    std::string chairDllName = CHAIRLOADER_DLL_NAME;
    std::wstring chairDllNameW;
    Unicode::Convert(chairDllNameW, chairDllName);
    chairDllPath += chairDllNameW;
    HMODULE hChairDll = LoadLibraryExW(chairDllPath.c_str(), nullptr,
        LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR | LOAD_LIBRARY_SEARCH_USER_DIRS | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    
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
