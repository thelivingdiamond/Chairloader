#include "PathUtils.h"

static PathUtils::GamePlatform gPlatform = PathUtils::GamePlatform::steam;


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

const char* GAME_BIN_DIR_STR = STEAM_GAME_BIN_DIR;
const char* GAME_EXE_PATH_STR = STEAM_GAME_EXE_PATH;
const char* GAME_DLL_PATH_STR = STEAM_GAME_DLL_PATH;
const char* GAME_DLL_PDB_PATH_STR = STEAM_GAME_DLL_PDB_PATH;
const char* GAME_DLL_BACKUP_PATH_STR = STEAM_GAME_DLL_BACKUP_PATH;

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

        for (const char* name : REQUIRED_GAME_FILES())
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

void PathUtils::SetGamePlatform(PathUtils::GamePlatform platform) {
    gPlatform = platform;
    switch(platform){
        case steam:
            GAME_BIN_DIR_STR = STEAM_GAME_BIN_DIR;
            GAME_EXE_PATH_STR = STEAM_GAME_EXE_PATH;
            GAME_DLL_PATH_STR = STEAM_GAME_DLL_PATH;
            GAME_DLL_PDB_PATH_STR = STEAM_GAME_DLL_PDB_PATH;
            GAME_DLL_BACKUP_PATH_STR = STEAM_GAME_DLL_BACKUP_PATH;
            REQUIRED_GAME_FILES_ARRAY[0] = GAME_EXE_PATH_STR;
            break;
        case gog:
            GAME_BIN_DIR_STR = GOG_GAME_BIN_DIR;
            GAME_EXE_PATH_STR = GOG_GAME_EXE_PATH;
            GAME_DLL_PATH_STR = GOG_GAME_DLL_PATH;
            GAME_DLL_PDB_PATH_STR = GOG_GAME_DLL_PDB_PATH;
            GAME_DLL_BACKUP_PATH_STR = GOG_GAME_DLL_BACKUP_PATH;
            REQUIRED_GAME_FILES_ARRAY[0] = GAME_EXE_PATH_STR;
            break;
        case epic:
            GAME_BIN_DIR_STR = EPIC_GAME_BIN_DIR;
            GAME_EXE_PATH_STR = EPIC_GAME_EXE_PATH;
            GAME_DLL_PATH_STR = EPIC_GAME_DLL_PATH;
            GAME_DLL_PDB_PATH_STR = EPIC_GAME_DLL_PDB_PATH;
            GAME_DLL_BACKUP_PATH_STR = EPIC_GAME_DLL_BACKUP_PATH;
            REQUIRED_GAME_FILES_ARRAY[0] = GAME_EXE_PATH_STR;
            break;
        case microsoft:
            GAME_BIN_DIR_STR = MICRO_GAME_BIN_DIR;
            GAME_EXE_PATH_STR = MICRO_GAME_EXE_PATH;
            GAME_DLL_PATH_STR = MICRO_GAME_DLL_PATH;
            GAME_DLL_PDB_PATH_STR = MICRO_GAME_DLL_PDB_PATH;
            GAME_DLL_BACKUP_PATH_STR = MICRO_GAME_DLL_BACKUP_PATH;
            REQUIRED_GAME_FILES_ARRAY[0] = GAME_EXE_PATH_STR;
            break;
        case unknown:
            GAME_BIN_DIR_STR = "";
            GAME_EXE_PATH_STR = "";
            GAME_DLL_PATH_STR = "";
            GAME_DLL_PDB_PATH_STR = "";
            GAME_DLL_BACKUP_PATH_STR = "";
            REQUIRED_GAME_FILES_ARRAY[0] = "";
            break;
    }
}

PathUtils::GamePlatform PathUtils::GetGamePlatform() {
    return gPlatform;
}


const char *PathUtils::GAME_BIN_DIR() {
    return GAME_BIN_DIR_STR;
}

const char *PathUtils::GAME_EXE_PATH() {
    return GAME_EXE_PATH_STR;
}

const char *PathUtils::GAME_DLL_PATH() {
    return GAME_DLL_PATH_STR;
}

const char *PathUtils::GAME_DLL_PDB_PATH() {
    return GAME_DLL_PDB_PATH_STR;
}

const char *PathUtils::GAME_DLL_BACKUP_PATH() {
    return GAME_DLL_BACKUP_PATH_STR;
}
constexpr char CHAIRLOADER_BIN_SRC_PATH_STR[] = "Release";

const char *PathUtils::CHAIRLOADER_BIN_SRC_PATH() {
    return CHAIRLOADER_BIN_SRC_PATH_STR;
}



std::vector<const char *> PathUtils::REQUIRED_GAME_FILES() {
    return REQUIRED_GAME_FILES_ARRAY;
}

std::vector<const char *> PathUtils::REQUIRED_CHAIRLOADER_BINARIES() {
    return REQUIRED_CHAIRLOADER_BINARIES_ARRAY;
}

std::vector<const char *> PathUtils::REQUIRED_CHAIRLOADER_DIRS() {
    return REQUIRED_CHAIRLOADER_DIRS_ARRAY;
}

const char *PathUtils::CHAIRLOADER_PATCH_PATH() {
    return CHAIRLOADER_PATCH_PATH_STR;
}
