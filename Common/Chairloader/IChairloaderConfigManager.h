#pragma once
#include "IConfigNodeV1.h"
/**
 * \brief Interface for managing configuration files for mods.
 */
struct IChairloaderConfigManager {
    /**
     * \brief Retrieves the configuration node for a specific mod.
     * \param modName The name of the mod.
     * \return A reference to the configuration node.
     */
    virtual ConfigNodeRef<IConfigNodeV1> getModConfig(const std::string &modName) = 0;

    /**
     * \brief Marks the configuration of a mod as dirty or clean.
     * \param modName The name of the mod.
     * \param bDirty True to mark the configuration as dirty, false to mark it as clean.
     */
    virtual void setConfigDirty(std::string modName, bool bDirty) = 0;

    /**
     * \brief Checks if the configuration of a mod is marked as dirty.
     * \param modName The name of the mod.
     * \return True if the configuration is dirty, false otherwise.
     */
    virtual bool getConfigDirty(std::string modName) = 0;

    /**
     * \brief Loads the configuration file for a specific mod.
     *
     * If the configuration file exists in `Mods/config/`, it will load that file.
     * If not, it will check for a default configuration in the mod folder (`Mods/modName/modName_default.xml`).
     * If neither is found, it will create a default configuration file with only the root modName node.
     *
     * \param modName The name of the mod.
     * \return True if the configuration file was successfully loaded or created, false otherwise.
     */
    virtual bool loadModConfigFile(std::string modName) = 0;

    /**
     * \brief Saves the configuration file for a specific mod to disk.
     * \param modName The name of the mod.
     * \return True if the configuration file was successfully saved, false otherwise.
     */
    virtual bool saveModConfigFile(std::string modName) = 0;

    /**
     * \brief Retrieves the file path of the configuration file for a specific mod.
     * \param modName The name of the mod.
     * \return The file path of the configuration file.
     */
    virtual fs::path getConfigPath(std::string modName) = 0;

    /**
     * \brief Retrieves the file path of the default configuration file for a specific mod.
     * \param modName The name of the mod.
     * \return The file path of the default configuration file.
     */
    virtual fs::path getDefaultConfigPath(std::string modName) = 0;
};
