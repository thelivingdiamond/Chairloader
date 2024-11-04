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
    const char* GetGameBinDir() const;
    static const char* GetGameBinDir(GamePlatform platform);
    const char* GetGameExePath() const;
    static const char* GetGameExePath(GamePlatform platform);
    const char* GetGameDllPath() const;
    static const char* GetGameDllPath(GamePlatform platform);
    const char* GetGameDllPDBPath() const;
    static const char* GetGameDllPDBPath(GamePlatform platform);
    const char* GetGameDllBackupPath() const;
    static const char* GetGameDllBackupPath(GamePlatform platform);

//! @}

//! Path to Chairloader files for installation (relative to ModLoader)
    const char* GetChairloaderBinSrcPath() const;
    std::vector<const char*> GetRequiredGameFiles() const;

    static std::vector<const char*> GetRequiredGameFiles(GamePlatform platform);

//! Chairloader files in GetGameExePath that are required for Chairloader
    std::vector<const char*> GetRequiredChairloaderBinaries() const;

//! Required directories in the game dir for Chairloader to work
    std::vector<const char*> GetRequiredChairloaderDirs() const;


//! Path to the Chairloader patch file
    const char* GetChairloaderPatchPath() const;

//! Returns the game store platform
    GamePlatform GetGamePlatform() const { return m_Platform; };
    const char* GetGamePlatformString() const;

    static const char* GetGamePlatformString(GamePlatform platform);

//! Checks if supplied path is a valid Prey path.
//! In particular, checks if all files in GetRequiredGameFiles exist.
//! @param  path    The path in question
//! @param  error   Output variable with validation error text. Empty if no error.
//! @returns whether the path is a valid game path.
    static bool ValidateGamePath(const fs::path& path, std::string* error = nullptr);

//! Like ValidateGamePath but for Prey.exe path
//! @param  path    The path in question
//! @param  error   Output variable with validation error text. Empty if no error.
//! @returns whether the path is a valid exe path.
    static bool ValidateExePath(const fs::path& path, std::string* error = nullptr);


//! Extracts game path from exe path. Call ValidateExePath first.
    static fs::path ExePathToGamePath(const fs::path& exePath);

    //! Deduces the game platform from game root path by checking which files exist.
    //! @returns the platform or GamePlatform::Unknown.
    static GamePlatform DeduceGamePlatform(const fs::path& path);

//! Get the path to the game directory
    const fs::path& GetGamePath() const {
        return m_Path;
    }

protected:
    friend class ChairManager;
//! Set the path to the game directory
    void SetGamePath(const fs::path& path) {
        m_Path = path;
        m_Platform = DeduceGamePlatform(path);
    }

private:
    GamePlatform m_Platform = GamePlatform::Unknown;
    fs::path m_Path;
};


#endif //CHAIRLOADER_GAMEPATH_H
