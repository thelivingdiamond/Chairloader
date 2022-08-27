#pragma once

namespace PathUtils
{

//! Paths to game binaries
//! @{
constexpr char GAME_EXE_PATH[] = "Binaries/Danielle/x64/Release/Prey.exe";
constexpr char GAME_DLL_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll";
constexpr char GAME_DLL_PDB_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.pdb";
constexpr char GAME_DLL_BACKUP_PATH[] = "Binaries/Danielle/x64/Release/PreyDll.dll.chairloader_backup";
//! @}

constexpr const char* REQUIRED_GAME_FILES[] = {
    GAME_EXE_PATH,
    "Engine",
    "GameSDK",
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
