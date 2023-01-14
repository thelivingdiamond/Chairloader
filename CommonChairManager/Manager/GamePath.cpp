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

constexpr char GOG_GAME_BIN_DIR[] = "Binaries/Danielle/x64/Release";
constexpr char GOG_GAME_EXE_PATH[] = "Binaries/Danielle/x64/Release/Prey.exe";
constexpr char GOG_GAME_DLL_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll";
constexpr char GOG_GAME_DLL_PDB_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.pdb";
constexpr char GOG_GAME_DLL_BACKUP_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll.chairloader_backup";

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

        for (const char* name : GetRequiredGameFiles())
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
    gPlatform = platform;
}

GamePath::GamePlatform GamePath::GetGamePlatform() {
    return gPlatform;
}


const char *GamePath::GetGameBinDir() {
    switch(gPlatform){
        case steam:
            return STEAM_GAME_BIN_DIR;
        case gog:
            return GOG_GAME_BIN_DIR;
        case epic:
            return EPIC_GAME_BIN_DIR;
        case microsoft:
            return MICRO_GAME_BIN_DIR;
        case unknown:
            return "";
    }
}

const char *GamePath::GetGameExePath() {
    switch(gPlatform){
        case steam:
            return STEAM_GAME_EXE_PATH;
        case gog:
            return GOG_GAME_EXE_PATH;
        case epic:
            return EPIC_GAME_EXE_PATH;
        case microsoft:
            return MICRO_GAME_EXE_PATH;
        case unknown:
            return "";
    }
}

const char *GamePath::GetGameDllPath() {
    switch(gPlatform){
        case steam:
            return STEAM_GAME_DLL_PATH;
        case gog:
            return GOG_GAME_DLL_PATH;
        case epic:
            return EPIC_GAME_DLL_PATH;
        case microsoft:
            return MICRO_GAME_DLL_PATH;
        case unknown:
            return "";
    }
}

const char *GamePath::GetGameDllPDBPath() {
    switch(gPlatform){
        case steam:
            return STEAM_GAME_DLL_PDB_PATH;
        case gog:
            return GOG_GAME_DLL_PDB_PATH;
        case epic:
            return EPIC_GAME_DLL_PDB_PATH;
        case microsoft:
            return MICRO_GAME_DLL_PDB_PATH;
        case unknown:
            return "";
    }
}

const char *GamePath::GetGameDllBackupPath() {
    switch(gPlatform){
        case steam:
            return STEAM_GAME_DLL_BACKUP_PATH;
        case gog:
            return GOG_GAME_DLL_BACKUP_PATH;
        case epic:
            return EPIC_GAME_DLL_BACKUP_PATH;
        case microsoft:
            return MICRO_GAME_DLL_BACKUP_PATH;
        case unknown:
            return "";
    }
}

const char *GamePath::GetChairloaderBinSrcPath() {
    return CHAIRLOADER_BIN_SRC_PATH_STR;
}

std::vector<const char *> GamePath::GetRequiredGameFiles() {
    REQUIRED_GAME_FILES_ARRAY[0] = GetGameBinDir();
    return REQUIRED_GAME_FILES_ARRAY;
}

std::vector<const char *> GamePath::GetRequiredChairloaderBinaries() {
    return REQUIRED_CHAIRLOADER_BINARIES_ARRAY;
}

std::vector<const char *> GamePath::GetRequiredChairloaderDirs() {
    return REQUIRED_CHAIRLOADER_DIRS_ARRAY;
}

const char *GamePath::GetChairloaderPatchPath() {
    return CHAIRLOADER_PATCH_PATH_STR;
}