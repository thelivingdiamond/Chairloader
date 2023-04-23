//
// Created by theli on 4/10/2023.
//

#ifndef CHAIRLOADER_MODCONFIG_H
#define CHAIRLOADER_MODCONFIG_H
#include <variant>

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
    std::string getConfigValueString(std::string name) const {
        return configNode.child(name.c_str()).text().as_string();
    }
    std::variant<int, unsigned int, float, bool, int64_t, uint64_t, std::string, pugi::xml_node> getConfigValue(std::string name){
        auto node = configNode.child(name.c_str());
        if(node.empty()){
            return std::string();
        }
        if(node.attribute("type").empty()){
            return std::string();
        }
        auto type = node.attribute("type").as_string();
        if(strcmp(type, "int") == 0){
            return node.text().as_int();
        } else if(strcmp(type, "uint") == 0){
            return node.text().as_uint();
        } else if(strcmp(type, "float") == 0){
            return node.text().as_float();
        } else if(strcmp(type, "bool") == 0){
            return node.text().as_bool();
        } else if(strcmp(type, "int64") == 0){
            return node.text().as_llong();
        } else if(strcmp(type, "uint64") == 0){
            return node.text().as_ullong();
        } else if(strcmp(type, "string") == 0){
            return node.text().as_string();
        } else if(strcmp(type, "node") == 0){
            return node;
        } else {
            return std::string();
        }
    }

    std::string getConfigType(std::string name) const {
        auto node = configNode.child(name.c_str());
        if(node.empty()){
            return std::string();
        }
        if(node.attribute("type").empty()){
            return std::string();
        }
        return node.attribute("type").as_string();
    }

    void setConfigValue(std::string name, std::string value) {
        configNode.child(name.c_str()).text().set(value.c_str());
        dirty = true;
    }
    bool saveConfig() {
        dirty = false;
        return configDoc->save_file(configPath.string().c_str());
    }
    pugi::xml_parse_result loadConfig() {
        auto result = configDoc->load_file(configPath.string().c_str());
        configNode = configDoc->first_child();
        return result;
    }
};
#endif //CHAIRLOADER_MODCONFIG_H
