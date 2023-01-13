#pragma once

namespace PathUtils
{
    enum GamePlatform{
        steam,
        gog,
        epic,
        microsoft,
        unknown
    };

//! Paths to game binaries
//! @{
const char* GAME_BIN_DIR();
const char* GAME_EXE_PATH();
const char* GAME_DLL_PATH();
const char* GAME_DLL_PDB_PATH();
const char* GAME_DLL_BACKUP_PATH();
//! @}

//! Path to Chairloader files for installation (relative to ModLoader)
const char* CHAIRLOADER_BIN_SRC_PATH();

std::vector<const char*> REQUIRED_GAME_FILES();

//! Chairloader files in GAME_EXE_PATH that are required for Chairloader
std::vector<const char*> REQUIRED_CHAIRLOADER_BINARIES();

//! Required directories in the game dir for Chairloader to work
std::vector<const char*> REQUIRED_CHAIRLOADER_DIRS();

//! Path to the Chairloader patch file
const char * CHAIRLOADER_PATCH_PATH();


//! Checks if supplied path is a valid Prey path.
//! In particular, checks if all files in REQUIRED_GAME_FILES exist.
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


void SetGamePlatform(GamePlatform platform);


GamePlatform GetGamePlatform();

}