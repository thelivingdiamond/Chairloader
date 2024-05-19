//
// Created by theli on 1/14/2023.
//

#include "GamePath.h"

//! Paths to game binaries and files, platform specific
//steam, gog, epic, microsoft

constexpr char STEAM_GAME_BIN_DIR[] = "Binaries/Danielle/x64/Release";
constexpr char STEAM_GAME_EXE_PATH[] = "Binaries/Danielle/x64/Release/Prey.exe";
constexpr char STEAM_GAME_DLL_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll";
constexpr char STEAM_GAME_DLL_PDB_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.pdb";
constexpr char STEAM_GAME_DLL_BACKUP_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll.chairloader_backup";

constexpr char EPIC_GAME_BIN_DIR[] = "Binaries/Danielle/x64-Epic/Release";
constexpr char EPIC_GAME_EXE_PATH[] = "Binaries/Danielle/x64-Epic/Release/Prey.exe";
constexpr char EPIC_GAME_DLL_PATH[] = "Binaries/Danielle/x64-Epic/Release/PreyDll.dll";
constexpr char EPIC_GAME_DLL_PDB_PATH[] = "Binaries/Danielle/x64-Epic/Release/PreyDll.pdb";
constexpr char EPIC_GAME_DLL_BACKUP_PATH[] = "Binaries/Danielle/x64-Epic/Release/PreyDll.dll.chairloader_backup";

constexpr char GOG_GAME_BIN_DIR[] = "Binaries/Danielle/x64-GOG/Release";
constexpr char GOG_GAME_EXE_PATH[] = "Binaries/Danielle/x64-GOG/Release/Prey.exe";
constexpr char GOG_GAME_DLL_PATH[] = "Binaries/Danielle/x64-GOG/Release/PreyDll.dll";
constexpr char GOG_GAME_DLL_PDB_PATH[] = "Binaries/Danielle/x64-GOG/Release/PreyDll.pdb";
constexpr char GOG_GAME_DLL_BACKUP_PATH[] = "Binaries/Danielle/x64-GOG/Release/PreyDll.dll.chairloader_backup";

constexpr char MICRO_GAME_BIN_DIR[] = "Binaries/Danielle/Gaming.Desktop.x64/Release";
constexpr char MICRO_GAME_EXE_PATH[] = "Binaries/Danielle/Gaming.Desktop.x64/Release/Prey.exe";
constexpr char MICRO_GAME_DLL_PATH[] = "Binaries/Danielle/Gaming.Desktop.x64/Release/PreyDll.dll";
constexpr char MICRO_GAME_DLL_PDB_PATH[] = "Binaries/Danielle/Gaming.Desktop.x64/Release/PreyDll.pdb";
constexpr char MICRO_GAME_DLL_BACKUP_PATH[] = "Binaries/Danielle/Gaming.Desktop.x64/Release/PreyDll.dll.chairloader_backup";

constexpr char CHAIRLOADER_BIN_SRC_PATH_STR[] = "Release";

static std::vector<const char*> REQUIRED_CHAIRLOADER_BINARIES_ARRAY = {
        "Chairloader.dll",
        "mswsock.dll",
};

static std::vector<const char*> REQUIRED_GAME_FILES_ARRAY = {
        "",
        "Engine",
        "GameSDK",
};


//! Required directories in the game dir for Chairloader to work
static std::vector<const char*> REQUIRED_CHAIRLOADER_DIRS_ARRAY = {
        "Mods/config",
        "Mods/Legacy",
};

//! Path to the Chairloader patch file
constexpr char CHAIRLOADER_PATCH_PATH_STR[] = "GameSDK/Precache/patch_chairloader.pak";



bool GamePath::ValidateGamePath(const fs::path& path, std::string* error)
{
    try
    {
        if (error) error->clear();

        if (path.empty())
        {
            if (error) *error = "Path is empty";
            return false;
        }

        auto platform = DeduceGamePlatform(path);
        if(platform == GamePlatform::Unknown)
        {
            if (error) *error = "Unknown game platform";
            return false;
        }

        for (const char* name : GetRequiredGameFiles(platform))
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

bool GamePath::ValidateExePath(const fs::path& path, std::string* error)
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

fs::path GamePath::ExePathToGamePath(const fs::path& exePath)
{
    // Binaries\Danielle\x64\Release\Prey.exe
    return exePath.parent_path().parent_path().parent_path().parent_path().parent_path();
}

void GamePath::SetGamePlatform(GamePath::GamePlatform platform) {
    m_Platform = platform;
}

bool GamePath::TrySetGamePath(const fs::path& path, std::string* error)
{
    bool isValid = ValidateGamePath(path, error);
    if (!isValid)
        return false;

    GamePlatform plat = DeduceGamePlatform(path);
    assert(plat != GamePlatform::Unknown);

    m_Path = path;
    m_Platform = plat;
    return true;
}

const char *GamePath::GetGameBinDir() const {
    return GetGameBinDir(m_Platform);
}

const char *GamePath::GetGameExePath() const {
    return GetGameExePath(m_Platform);
}

const char *GamePath::GetGameDllPath() const {
    return GetGameDllPath(m_Platform);
}

const char *GamePath::GetGameDllPDBPath() const {
    return GetGameDllPDBPath(m_Platform);
}

const char *GamePath::GetGameDllBackupPath() const {
    return GetGameDllBackupPath(m_Platform);
}

const char *GamePath::GetChairloaderBinSrcPath() const {
    return CHAIRLOADER_BIN_SRC_PATH_STR;
}

std::vector<const char *> GamePath::GetRequiredGameFiles() const {
    return GetRequiredGameFiles(m_Platform);
}

std::vector<const char *> GamePath::GetRequiredGameFiles(GamePath::GamePlatform platform) {
    auto copyArray = REQUIRED_GAME_FILES_ARRAY;
    copyArray[0] = GetGameExePath(platform);
    return copyArray;
}


std::vector<const char *> GamePath::GetRequiredChairloaderBinaries() const {
    return REQUIRED_CHAIRLOADER_BINARIES_ARRAY;
}

std::vector<const char *> GamePath::GetRequiredChairloaderDirs() const {
    return REQUIRED_CHAIRLOADER_DIRS_ARRAY;
}

const char *GamePath::GetChairloaderPatchPath() const {
    return CHAIRLOADER_PATCH_PATH_STR;
}

GamePath::GamePlatform GamePath::DeduceGamePlatform(const fs::path &path) {
    if (path.empty()) {
        return GamePlatform::Unknown;
    }
    if (fs::exists(path / STEAM_GAME_EXE_PATH)) {
        return GamePlatform::Steam;
    }
    if (fs::exists(path / GOG_GAME_EXE_PATH)) {
        return GamePlatform::Gog;
    }
    if (fs::exists(path / EPIC_GAME_EXE_PATH)) {
        return GamePlatform::Epic;
    }
    if (fs::exists(path / MICRO_GAME_EXE_PATH)) {
        return GamePlatform::Microsoft;
    }

    return GamePlatform::Unknown;
}

const char *GamePath::GetGameBinDir(GamePath::GamePlatform platform) {
    switch(platform){
        case GamePlatform::Steam:
            return STEAM_GAME_BIN_DIR;
        case GamePlatform::Gog:
            return GOG_GAME_BIN_DIR;
        case GamePlatform::Epic:
            return EPIC_GAME_BIN_DIR;
        case GamePlatform::Microsoft:
            return MICRO_GAME_BIN_DIR;
        case GamePlatform::Unknown:
            return "";
    }
    return "";
}

const char *GamePath::GetGameExePath(GamePath::GamePlatform platform) {
    switch(platform){
        case GamePlatform::Steam:
            return STEAM_GAME_EXE_PATH;
        case GamePlatform::Gog:
            return GOG_GAME_EXE_PATH;
        case GamePlatform::Epic:
            return EPIC_GAME_EXE_PATH;
        case GamePlatform::Microsoft:
            return MICRO_GAME_EXE_PATH;
        case GamePlatform::Unknown:
            return "";
    }
    return "";
}

const char *GamePath::GetGameDllPath(GamePath::GamePlatform platform) {
    switch(platform){
        case GamePlatform::Steam:
            return STEAM_GAME_DLL_PATH;
        case GamePlatform::Gog:
            return GOG_GAME_DLL_PATH;
        case GamePlatform::Epic:
            return EPIC_GAME_DLL_PATH;
        case GamePlatform::Microsoft:
            return MICRO_GAME_DLL_PATH;
        case GamePlatform::Unknown:
            return "";
    }
    return "";
}

const char *GamePath::GetGameDllPDBPath(GamePath::GamePlatform platform) {
    switch(platform){
        case GamePlatform::Steam:
            return STEAM_GAME_DLL_PDB_PATH;
        case GamePlatform::Gog:
            return GOG_GAME_DLL_PDB_PATH;
        case GamePlatform::Epic:
            return EPIC_GAME_DLL_PDB_PATH;
        case GamePlatform::Microsoft:
            return MICRO_GAME_DLL_PDB_PATH;
        case GamePlatform::Unknown:
            return "";
    }
    return "";
}

const char *GamePath::GetGameDllBackupPath(GamePath::GamePlatform platform) {
    switch(platform){
        case GamePlatform::Steam:
            return STEAM_GAME_DLL_BACKUP_PATH;
        case GamePlatform::Gog:
            return GOG_GAME_DLL_BACKUP_PATH;
        case GamePlatform::Epic:
            return EPIC_GAME_DLL_BACKUP_PATH;
        case GamePlatform::Microsoft:
            return MICRO_GAME_DLL_BACKUP_PATH;
        case GamePlatform::Unknown:
            return "";
    }
    return "";
}

const char *GamePath::GetGamePlatformString(GamePath::GamePlatform platform) {
switch(platform){
        case GamePlatform::Steam:
            return "Steam";
        case GamePlatform::Gog:
            return "Gog";
        case GamePlatform::Epic:
            return "Epic";
        case GamePlatform::Microsoft:
            return "Microsoft";
        case GamePlatform::Unknown:
            return "Unknown";
    }
    return "";
}

const char *GamePath::GetGamePlatformString() const {
    return GetGamePlatformString(m_Platform);
}
