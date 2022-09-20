//
// Created by theli on 9/13/2022.
//
#pragma once



/*
<X Param="{{ configValue }}" /> <!-- Current mod's config -->
<X Param="{{ $.modAuthor.modName.configValue }}"/> <!-- Reference a different mod. modAuthor.modName is actually "modName" from ModInfo.xml. $ is like some global object -->
<X chair_apply_if="$.modAuthor.modName.modEnabled" /> <!-- Check if different mod is installed and enabled. Allows for some basic interop between XML mods -->
<X chair_apply_if="{{ configValue }}"/> <!-- apply if some other config value -->
 */

//! the purpose of this class is to load, edit, and manage config files for mods
class ConfigManager {
public:
    struct ModConfig {
        std::shared_ptr<pugi::xml_document> configDoc;
        pugi::xml_node configNode;
        fs::path configPath;
        std::string modName;
        std::string displayName;
        bool dirty = false;
        ModConfig() = default;
        ModConfig(const ModConfig& other) {
            configDoc = other.configDoc;
            configNode = other.configNode;
            configPath = other.configPath;
            modName = other.modName;
        }
        ModConfig& operator=(const ModConfig& other) {
            configDoc = other.configDoc;
            configNode = other.configNode;
            configPath = other.configPath;
            modName = other.modName;
            return *this;
        }
        ModConfig(std::string modName, pugi::xml_document& doc, fs::path path) {
            this->modName = modName;
            configDoc = std::make_shared<pugi::xml_document>();
            configDoc->reset(doc);
            configNode = configDoc->first_child();
            configPath = path;
        }
        // == operator
        bool operator==(const ModConfig& other) const {
            return modName == other.modName;
        }
        bool operator==(const std::string& other) const {
            return modName == other;
        }
        std::string getConfigValue(std::string name) const {
            return configNode.child(name.c_str()).text().as_string();
        }
        void setConfigValue(std::string name, std::string value) {
            configNode.child(name.c_str()).text().set(value.c_str());
            dirty = true;
        }
        bool saveConfig() const {
            return configDoc->save_file(configPath.string().c_str());
        }
        pugi::xml_parse_result loadConfig() {
            auto result = configDoc->load_file(configPath.string().c_str());
            configNode = configDoc->first_child();
            return result;
        }
    };
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
    static void copyDefaultConfig(std::string modName);

    //! checks if a config file exists in the Config/ directory
    static bool isConfigPresent(std::string modName);

    void setDirty(std::string modName, bool dirty);

    void draw();
private:
    std::vector<ModConfig> m_modConfigs;


    void loadConfig(std::string modName);
    void loadConfigs();
    void drawXMLConfigNode(pugi::xml_node node);

};
