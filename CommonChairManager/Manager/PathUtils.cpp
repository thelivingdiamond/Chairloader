#include "PathUtils.h"

bool PathUtils::ValidateGamePath(const fs::path& path, std::string* error)
{
    try
    {
        if (error) error->clear();

        if (path.empty())
        {
            if (error) *error = "Path is empty";
            return false;
        }

        for (const char* name : REQUIRED_GAME_FILES)
        {
            if (!fs::exists(path / name))
            {
                if (error) *error = '"' + std::string(name) + "\" was not found in game's directory";
                return false;
            }
        }

        return true;
    }
    catch (const std::exception& e)
    {
        // Catch filesystem errors
        if (error) *error = e.what();
        return false;
    }
}

bool PathUtils::ValidateExePath(const fs::path& path, std::string* error)
{
    if (error) error->clear();

    if (path.empty())
    {
        if (error) *error = "Path is empty";
        return false;
    }

    fs::path gamePath = ExePathToGamePath(path);
    if (gamePath.empty())
    {
        if (error) *error = "Path is too short";
        return false;
    }

    return ValidateGamePath(gamePath, error);
}

fs::path PathUtils::ExePathToGamePath(const fs::path& exePath)
{
    // Binaries\Danielle\x64\Release\Prey.exe
    return exePath.parent_path().parent_path().parent_path().parent_path().parent_path();
}
