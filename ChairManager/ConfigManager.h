//
// Created by theli on 9/13/2022.
//
#pragma once
#include <mutex>
#include "ModConfig.h"


/*
<X Param="{{ configValue }}" /> <!-- Current mod's config -->
<X Param="{{ $.modAuthor.modName.configValue }}"/> <!-- Reference a different mod. modAuthor.modName is actually "modName" from ModInfo.xml. $ is like some global object -->
<X ch:apply_if="$.modAuthor.modName.modEnabled" /> <!-- Check if different mod is installed and enabled. Allows for some basic interop between XML mods -->
<X ch:apply_if="{{ configValue }}"/> <!-- apply if some other config value -->
<X ch:remove /> <!-- Remove this node from the XML -->
<X ch:patch_mode/> <!-- Patch mode: will overwrite all attributes present in the mod node w/out any vanilla checking. -->
 */

//! the purpose of this class is to load, edit, and manage config files for mods
class ConfigManager {
public:
    ConfigManager() = default;

    // init needs to
    // - load all config files
    // - be repeatable

    //! loads all config files
    void init();

    //! saves all configs
    void saveConfigs();
    //! saves all dirty configs
    void saveDirtyConfigs();

    //! gets a config struct for a mod
    ModConfig& getModConfig(std::string modName);
    ModConfig& operator[](std::string modName);
    ModConfig& operator[](const char * modName);
    size_t size() const{
        return m_modConfigs.size();
    }

    //! copies a config file from the default config directory to the mod's config directory, creates an empty config file if it doesn't exist
    static void copyDefaultConfig(const std::string &modName);

    //! checks if a config file exists in the Config/ directory
    static bool isConfigPresent(const std::string &modName);

    void setDirty(const std::string& modName, bool dirty);

    void draw();

    std::unordered_map<std::string, bool> getModSpaceBooleanVariables(const std::string& modName);

private:
    std::vector<ModConfig> m_modConfigs;
    std::mutex m_modConfigsMutex;

    void loadConfig(const std::string& modName);
    void loadConfigs();
    void drawXMLConfigNode(pugi::xml_node node);
    void drawXMLValueInput(pugi::xml_node node);

    std::vector<std::pair<std::string, bool>> getModVariableSpace(pugi::xml_node node, const std::set<std::string>& allowedTypes);

};
