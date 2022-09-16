//
// Created by theli on 9/13/2022.
//

#include "ConfigManager.h"
#include "ModLoader.h"

// init needs to
// - load all config files
// - be repeatable
void ConfigManager::init() {
    saveDirtyConfigs();
    m_modConfigs.clear();
    loadConfigs();
}

ConfigManager::ModConfig& ConfigManager::operator[](std::string modName){
    auto it = std::find_if(m_modConfigs.begin(), m_modConfigs.end(), [&modName](const ModConfig& config) {
        return config.modName == modName;
    });
    if(it != m_modConfigs.end()) {
        return *it;
    } else {
        auto modConfig = new ModConfig();
        return *modConfig;
    }
}

ConfigManager::ModConfig &ConfigManager::getModConfig(std::string modName) {
    return (*this)[modName];
}

ConfigManager::ModConfig &ConfigManager::operator[](const char *modName) {
    return (*this)[std::string(modName)];
}

bool ConfigManager::isConfigPresent(std::string modName){
    try {
        return fs::exists(ModLoader::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml"));
    } catch (fs::filesystem_error& e) {
        ModLoader::Get().log(ModLoader::severityLevel::error, "Error checking for config file: %s", e.what());
        return false;
    }
}

void ConfigManager::copyDefaultConfig(std::string modName){
    try{
        if(fs::exists(ModLoader::Get().GetGamePath() / "Mods" / modName / (modName + "_default.xml"))){
            fs::copy_file(ModLoader::Get().GetGamePath() / "Mods" / modName / (modName + "_default.xml"), ModLoader::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml"), fs::copy_options::overwrite_existing);
        } else {
            ModLoader::Get().log(ModLoader::severityLevel::warning,  "Default config file for mod %s not found! Creating empty config file", modName.c_str());
            pugi::xml_document doc;
            doc.append_child(modName.c_str());
            doc.save_file((ModLoader::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml")).string().c_str());
        }
    } catch (fs::filesystem_error& e) {
        ModLoader::Get().log(ModLoader::severityLevel::error, "Failed to copy default config for mod %s : %s", modName.c_str(), e.what());
    }
}


void ConfigManager::loadConfig(std::string modName){
    if(!isConfigPresent(modName)){
        copyDefaultConfig(modName);
    }
    fs::path configPath = ModLoader::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml");
    pugi::xml_document doc;
    auto result = doc.load_file(configPath.string().c_str());
    if(result){
        m_modConfigs.emplace_back(modName, doc, configPath);
    } else {
        ModLoader::Get().log(ModLoader::severityLevel::error, "Failed to load config for mod %s with Error: %s", modName.c_str(), result.description());
    }
}


//! Load all config files, copying default config files if they don't exist
void ConfigManager::loadConfigs(){
    auto modList = ModLoader::Get().GetMods();
    for(auto& mod : modList){
        if(!isConfigPresent(mod.modName)){
            copyDefaultConfig(mod.modName);
        }
        loadConfig(mod.modName);
    }
}

//! Save all dirty configs
void ConfigManager::saveDirtyConfigs() {
    for(auto& config : m_modConfigs){
        if(config.dirty){
            if(!config.saveConfig()){
                ModLoader::Get().log(ModLoader::severityLevel::error, "Failed to save config for mod %s", config.modName.c_str());
            }
        }
    }
}

//! Save all configs
void ConfigManager::saveConfigs() {
    for(auto& config : m_modConfigs){
        if(!config.saveConfig()){
            ModLoader::Get().log(ModLoader::severityLevel::error, "Failed to save config for mod %s", config.modName.c_str());
        }
    }

}
