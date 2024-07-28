#include <Prey/CryCore/Platform/CryWindows.h>
#include <Manager/GamePath.h>
#include <mem.h>
#include "SavePathPatch.h"

static PreyGlobal<char> g_SavePathString(0x1C746C0);

template <typename... Args>
static void EarlyFatalError(std::string_view format, const Args& ...args)
{
    std::string s = fmt::vformat(format, fmt::make_format_args(args...));
    printf("Early fatal error:\n%s\n", s.c_str());
    std::abort();
}

void SavePathPatch::ApplyPatch()
{
    if (GetModuleHandleA("Preditor.exe"))
    {
        // Ignore Preditor. It's EXE is located in a different place.
        // It overrides the save path anyway.
        return;
    }

    // Find EXE path
    std::vector<wchar_t> pathBuf(512);
    DWORD pathLen = GetModuleFileNameW(GetModuleHandleW(nullptr), pathBuf.data(), pathBuf.size());
    fs::path exePath = fs::path(std::wstring_view(pathBuf.data(), pathLen));

    // Set game path
    GamePath gamePath;
    std::string gamePathError;
    if (!gamePath.ValidateExePath(exePath))
        EarlyFatalError("Failed to detect game platform.\nEXE path validation failed: {}", gamePathError);
    if (!gamePath.TrySetGamePath(GamePath::ExePathToGamePath(exePath)))
        EarlyFatalError("Failed to detect game platform.\nSet game path failed: {}", gamePathError);

    // Decide whether to patch
    std::string_view patchedString;

    switch (gamePath.GetGamePlatform())
    {
    case GamePath::GamePlatform::Epic:
        patchedString = std::string_view();
        break;
    case GamePath::GamePlatform::Microsoft:
        patchedString = "Arkane Studios/Prey_MS";
        break;
    default:
        patchedString = "Arkane Studios/Prey";
        break;
    }

    if (patchedString.empty())
        return;

    constexpr char expectedString[] = "Arkane Studios/Prey_Epic/%s";

    if (patchedString.size() > sizeof(expectedString))
        EarlyFatalError("Patch string is too long");

    printf("Changing save file path to %s\n", patchedString.data());
    if (memcmp(expectedString, g_SavePathString.Get(), sizeof(expectedString)))
        EarlyFatalError("Save path string pointer is invalid");

    mem::Patch((uint8_t*)g_SavePathString.Get(), (uint8_t*)patchedString.data(), patchedString.size() + 1);
}
