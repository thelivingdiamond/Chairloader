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

    //! Tries to set the path to game directory and the platform.
    //! Checks that game files exist and deduces platform based on which binaries exist.
    //! @param  path    Path to game root.
    //! @returns whether path and platform were set successfully.
    bool TrySetGamePath(const fs::path& path, std::string* error = nullptr);

//! Paths to game binaries
//! @{
    const char* GetGameBinDir();
    static const char* GetGameBinDir(GamePlatform platform);
    const char* GetGameExePath();
    static const char* GetGameExePath(GamePlatform platform);
    const char* GetGameDllPath();
    static const char* GetGameDllPath(GamePlatform platform);
    const char* GetGameDllPDBPath();
    static const char* GetGameDllPDBPath(GamePlatform platform);
    const char* GetGameDllBackupPath();
    static const char* GetGameDllBackupPath(GamePlatform platform);

//! @}

//! Path to Chairloader files for installation (relative to ModLoader)
    const char* GetChairloaderBinSrcPath();
    std::vector<const char*> GetRequiredGameFiles();

    static std::vector<const char*> GetRequiredGameFiles(GamePlatform platform);

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

    static const char* GetGamePlatformString(GamePlatform platform);

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

    //! Deduces the game platform from game root path by checking which files exist.
    //! @returns the platform or GamePlatform::Unknown.
    static GamePlatform DeduceGamePlatform(const fs::path& path);

//! Get the path to the game directory
    const fs::path& GetGamePath(){
        return m_Path;
    }

protected:
    friend class ChairManager;
//! Set the path to the game directory
    void SetGamePath(const fs::path& path) {
        m_Path = path;
    }

private:
    GamePlatform m_Platform = GamePlatform::Unknown;
    fs::path m_Path;
};


#endif //CHAIRLOADER_GAMEPATH_H
