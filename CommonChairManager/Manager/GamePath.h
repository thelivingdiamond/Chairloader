//
// Created by theli on 1/14/2023.
//

#ifndef CHAIRLOADER_GAMEPATH_H
#define CHAIRLOADER_GAMEPATH_H


class GamePath {
public:
    enum GamePlatform{
        steam,
        gog,
        epic,
        microsoft,
        unknown
    };

//! Paths to game binaries
//! @{
    const char* GetGameBinDir();
    const char* GetGameExePath();
    const char* GetGameDllPath();
    const char* GetGameDllPDBPath();
    const char* GetGameDllBackupPath();
//! @}

//! Path to Chairloader files for installation (relative to ModLoader)
    const char* GetChairloaderBinSrcPath();

    std::vector<const char*> GetRequiredGameFiles();

//! Chairloader files in GetGameExePath that are required for Chairloader
    std::vector<const char*> GetRequiredChairloaderBinaries();

//! Required directories in the game dir for Chairloader to work
    std::vector<const char*> GetRequiredChairloaderDirs();

//! Path to the Chairloader patch file
    const char * GetChairloaderPatchPath();


//! Sets the game store platform, used to determine the appropriate game path
    void SetGamePlatform(GamePlatform platform);

//! Returns the game store platform
    GamePlatform GetGamePlatform();

//! Checks if supplied path is a valid Prey path.
//! In particular, checks if all files in GetRequiredGameFiles exist.
//! @param  path    The path in question
//! @param  error   Output variable with validation error text. Empty if no error.
//! @returns whether the path is a valid game path.
    bool ValidateGamePath(const fs::path& path, std::string* error = nullptr);

//! Like ValidateGamePath but for Prey.exe path
//! @param  path    The path in question
//! @param  error   Output variable with validation error text. Empty if no error.
//! @returns whether the path is a valid exe path.
    bool ValidateExePath(const fs::path& path, std::string* error = nullptr);

//! Extracts game path from exe path. Call ValidateExePath first.
    fs::path ExePathToGamePath(const fs::path& exePath);

private:
    GamePlatform gPlatform = unknown;
};


#endif //CHAIRLOADER_GAMEPATH_H
