//
// Created by theli on 1/14/2023.
//

#ifndef CHAIRLOADER_GAMEPATH_H
#define CHAIRLOADER_GAMEPATH_H


class GamePath {
public:
    enum class GamePlatform{
        Steam,
        Gog,
        Epic,
        Microsoft,
        Unknown
    };

//! Paths to game binaries
//! @{
    const char* GetGameBinDir();
    const char* GetGameBinDir(GamePlatform platform);
    const char* GetGameExePath();
    const char* GetGameExePath(GamePlatform platform);
    const char* GetGameDllPath();
    const char* GetGameDllPath(GamePlatform platform);
    const char* GetGameDllPDBPath();
    const char* GetGameDllPDBPath(GamePlatform platform);
    const char* GetGameDllBackupPath();
    const char* GetGameDllBackupPath(GamePlatform platform);

//! @}

//! Path to Chairloader files for installation (relative to ModLoader)
    const char* GetChairloaderBinSrcPath();
    std::vector<const char*> GetRequiredGameFiles();

    std::vector<const char*> GetRequiredGameFiles(GamePlatform platform);

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
    const char* GetGamePlatformString();

    const char* GetGamePlatformString(GamePlatform platform);

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


    GamePlatform DeduceGamePlatform(const fs::path& path);

protected:
    friend class ChairManager;
//! Set the path to the game's executable
//! \param path The path to the game's executable
    void SetGamePath(const fs::path& path) {
        m_Path = path;
    }
//! Get the path to the game directory
//! \return the path to the game directory
    const fs::path& GetGamePath(){
        return m_Path;
    }

private:
    GamePlatform m_Platform = GamePlatform::Unknown;
    fs::path m_Path;
};


#endif //CHAIRLOADER_GAMEPATH_H
