#pragma once
#include <Manager/ILogger.h>

struct Mod; // TODO 2023-12-30: This is a type internal to ChairManager
struct ModConfig;

//! Interface for basic ChairManager functionality.
//! Used by ChairManager modules that are shared with Preditor.
struct IChairManager : public ILogger
{
    virtual ~IChairManager() {}

    //! @returns path to the config directory (Mods/config).
    virtual fs::path GetConfigPath() = 0;

    //! @returns path to the mod directory. Throws if mod doesn't exist.
    virtual fs::path GetModPath(const std::string& modName) = 0;

    //! @returns the list of names of installed mods.
    virtual std::vector<std::string> GetModNames() = 0;

    //! @returns the list of names of installed legacy mods.
    virtual std::vector<std::string> GetLegacyModNames() = 0;

    //! @returns The list of all Chairloader mods.
    virtual const std::vector<Mod>& GetMods() const = 0;

    //! @returns the mod display name or empty string if not found.
    virtual std::string GetModDisplayName(const std::string& modName) = 0;

    //! @returns The mod config of nullptr if not found.
    virtual const ModConfig* GetModConfig(const std::string& modName) const = 0;

    //! @returns whether the mod is enabled.
    virtual bool IsModEnabled(const std::string& modName) = 0;
};
