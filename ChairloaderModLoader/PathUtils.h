#pragma once

namespace PathUtils
{

//! Paths to game binaries
//! @{
constexpr char GAME_BIN_DIR[] = "Binaries/Danielle/x64/Release";
constexpr char GAME_EXE_PATH[] = "Binaries/Danielle/x64/Release/Prey.exe";
constexpr char GAME_DLL_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll";
constexpr char GAME_DLL_PDB_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.pdb";
constexpr char GAME_DLL_BACKUP_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll.chairloader_backup";
//! @}

//! Path to Chairloader files for installation (relative to ModLoader)
constexpr char CHAIRLOADER_BIN_SRC_PATH[] = "Release";

constexpr const char* REQUIRED_GAME_FILES[] = {
    GAME_EXE_PATH,
    "Engine",
    "GameSDK",
};

//! Chairloader files in GAME_EXE_PATH that are required for Chairloader
constexpr const char* REQUIRED_CHAIRLOADER_BINARIES[] = {
    "Chairloader.dll",
    "mswsock.dll",
};

//! Required directories in the game dir for Chairloader to work
constexpr const char* REQUIRED_CHAIRLOADER_DIRS[] = {
    "Mods/Config",
    "Mods/Legacy",
};

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

}
