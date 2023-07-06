//
// Created by theli on 9/13/2022.
//

#include <Manager/IChairManager.h>
#include <Manager/ConfigManager.h>
// #include "ChairManager.h"
#include "../Chairloader/Common/GUIUtils.h"

// init needs to
// - load all config files
// - be repeatable
void ConfigManager::init(IChairManager* pChair) {
    m_pChair = pChair;
    m_modConfigs.clear();
    loadConfigs();
    m_IsDirty = false;
}

ModConfig& ConfigManager::operator[](std::string modName){
    std::scoped_lock lock(m_modConfigsMutex);
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

ModConfig &ConfigManager::getModConfig(std::string modName) {
    return (*this)[modName];
}

ModConfig &ConfigManager::operator[](const char *modName) {
    return (*this)[std::string(modName)];
}

bool ConfigManager::isConfigPresent(const std::string& modName){
    try {
        fs::path cfgPath = m_pChair->GetConfigPath() / fs::u8path(modName + ".xml");
        return fs::exists(cfgPath);
    } catch (fs::filesystem_error& e) {
        m_pChair->Log(severityLevel::error, "Error checking for config file: %s", e.what());
        return false;
    }
}

void ConfigManager::copyDefaultConfig(const std::string& modName){
    try{
        fs::path cfgPath = m_pChair->GetConfigPath() / fs::u8path(modName + ".xml");
        fs::path defaultCfgPath = m_pChair->GetModPath(modName) / fs::u8path(modName + "_default.xml");

        if(fs::exists(defaultCfgPath)){
            fs::copy_file(defaultCfgPath, cfgPath, fs::copy_options::overwrite_existing);
        } else {
            m_pChair->Log(severityLevel::warning, "Default config file for mod %s not found! Creating empty config file", modName.c_str());
            pugi::xml_document doc;
            doc.append_child(modName.c_str());
            doc.save_file(cfgPath.c_str());
        }
    } catch (fs::filesystem_error& e) {
        m_pChair->Log(severityLevel::error, "Failed to copy default config for mod %s : %s", modName.c_str(), e.what());
    }
}


void ConfigManager::loadConfig(const std::string& modName){
    if(!isConfigPresent(modName)){
        copyDefaultConfig(modName);
    }
    fs::path configPath = m_pChair->GetConfigPath() / fs::u8path(modName + ".xml");
    pugi::xml_document doc;
    auto result = doc.load_file(configPath.string().c_str());
    if(result){
        // check if the config already exists
        // if so swap it with the new one, otherwise add it
        bool found = false;
        for(auto& config : m_modConfigs){
            if(config.modName == modName){
                config = ModConfig(modName, doc, configPath);
                found = true;
                break;
            }
        }
        if(!found)
            m_modConfigs.emplace_back(modName, doc, configPath);
    } else {
        m_pChair->Log(severityLevel::error, "Failed to load config for mod %s with Error: %s", modName.c_str(), result.description());
    }
}


//! Load all config files, copying default config files if they don't exist
void ConfigManager::loadConfigs(){
    auto modList = m_pChair->GetModNames();
    for(auto& modName : modList){
        if(!isConfigPresent(modName)){
            copyDefaultConfig(modName);
        }
        loadConfig(modName);
    }
}

//! Save all dirty configs
void ConfigManager::saveDirtyConfigs() {
    for(auto& config : m_modConfigs){
        if(config.dirty){
            if(!config.saveConfig()){
                m_pChair->Log(severityLevel::error, "Failed to save config for mod %s", config.modName.c_str());
            }
        }
    }

    m_IsDirty = false;
}

//! Save all configs
void ConfigManager::saveConfigs() {
    for(auto& config : m_modConfigs){
        if(!config.saveConfig()){
            m_pChair->Log(severityLevel::error, "Failed to save config for mod %s", config.modName.c_str());
        }
    }
}




void ConfigManager::draw() {
   if(ImGui::BeginTabItem("Mod Config")){
       std::scoped_lock lock(m_modConfigsMutex);
       if(ImGui::BeginTabBar("##Mod Configs", ImGuiTabBarFlags_TabListPopupButton | ImGuiTabBarFlags_FittingPolicyScroll)){
           for(auto& config : m_modConfigs){
               std::string modName = config.modName;
               if(config.configNode.first_child() == nullptr){
                   continue;
               }
               auto displayName = m_pChair->GetModDisplayName(config.modName);
               if(displayName.empty()){
                   displayName = config.modName;
               }
               if(ImGui::BeginTabItem((displayName + "##" + config.modName).c_str())){
                   static bool open_reset_popup = false;
                   // create a sort of toolbar where we can add stuff like presets and a reset to default button
                   ImGui::BeginChild("##Mod Config", ImGui::GetContentRegionAvail(), false, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
                   if(ImGui::BeginMenuBar()) {
                       ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x * 0.35f);
                       //TODO: add presets and only show this dropdown if the mod has presets
                       if(false) {
                           if (ImGui::BeginCombo("##Presets", "Default")) {
                               ImGui::EndCombo();
                           }
                       }
                       // add a vertical separator
                       if(ImGui::Button(("Reset To Default##" + config.modName).c_str())){
                           open_reset_popup = true;
                       }
                       ImGui::EndMenuBar();
                   }
                   drawXMLConfigNode(config.configNode);
                   if(open_reset_popup){
                       ImGui::OpenPopup(("Reset To Default?##" + config.modName).c_str());
                       open_reset_popup = false;
                   }
                   if(ImGui::BeginPopupModal(("Reset To Default?##" + config.modName).c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize)){
                       ImGui::Text("Are you sure you want to reset the config for %s to default?", config.modName.c_str());
                       ImGui::Separator();
                       if(ImGui::Button("Yes")){
                           copyDefaultConfig(modName);
                           loadConfig(modName);
                           ImGui::CloseCurrentPopup();
                       }
                       ImGui::SameLine();
                       if(ImGui::Button("No")){
                           ImGui::CloseCurrentPopup();
                       }
                       ImGui::EndPopup();
                   }

                   ImGui::EndChild();
                   ImGui::EndTabItem();
               }
           }
           ImGui::EndTabBar();
       }
       ImGui::EndTabItem();
   }
}

void ConfigManager::drawXMLConfigNode(pugi::xml_node node) {
    auto tree_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen;
    // if node is a leaf node, remove the open on arrow and double click flags and add the leaf flag
    if(node.first_child().empty() || node.first_child().type() == pugi::node_pcdata){
        tree_flags &= ~ImGuiTreeNodeFlags_OpenOnArrow;
        tree_flags &= ~ImGuiTreeNodeFlags_OpenOnDoubleClick;
        tree_flags &= ~ImGuiTreeNodeFlags_DefaultOpen;
        tree_flags |= ImGuiTreeNodeFlags_Leaf;
    }
    bool open = ImGui::TreeNodeEx(node.name(), tree_flags);
    if(open){
        ImGui::Separator();
        if(ImGui::BeginTable("ConfigTable", 2, ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_NoClip | ImGuiTableFlags_RowBg)) {
            ImGui::TableSetupColumn("Key", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoClip);
            ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch | ImGuiTableColumnFlags_NoClip);
//            ImGui::TableHeadersRow();
            for (auto &child: node.children()) {
                if (child.type() == pugi::node_pcdata) {
                    continue;
                }
                auto size = std::distance(child.children().begin(), child.children().end());
//                if(size == 1 && child.first_child().type() == pugi::node_pcdata){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    std::string ChildValue = child.text().as_string();
                    drawXMLValueInput(child);
//                } else if(size > 0){
//                    ImGui::TableNextRow();
//                    ImGui::TableNextColumn();
//                    drawXMLConfigNode(child);
//                    ImGui::TableNextColumn();
//                }
            }
            ImGui::EndTable();
        }
        ImGui::TreePop();
    }
}

void ConfigManager::setDirty(const std::string& modName, bool dirty) {
//    std::scoped_lock lock(m_modConfigsMutex);
    auto config = std::find(m_modConfigs.begin(), m_modConfigs.end(), modName);
    if(config != m_modConfigs.end()){
        config->dirty = dirty;
    } else {
        m_pChair->Log(severityLevel::warning, "Failed to set dirty flag for mod %s, mod not found", modName.c_str());
    }

    if (dirty)
        m_IsDirty = true;
}

void ConfigManager::drawXMLValueInput(pugi::xml_node node) {
    if(node.type() == pugi::node_pcdata){
        return;
    }
    if(node.attribute("display_name")){
        ImGui::Text("%s", node.attribute("display_name").value());
    } else {
        ImGui::Text("%s", node.name());
    }
    if(node.attribute("description")){
        std::string description = node.attribute("description").value();
        if(!description.empty()){
            ImGui::SameLine();
            ImGuiUtils::HelpMarker(description.c_str());
        }
    }
    ImGui::TableNextColumn();
    std::string type;
    if(!node.attribute("type")){
        type = "string";
    } else {
        type = node.attribute("type").as_string();
        if(type.empty())
            type = "string";
    }

    if(type == "string"){
        std::string value = node.text().as_string();
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::InputText(("##" + node.path()).c_str(), &value, ImGuiInputTextFlags_EnterReturnsTrue)){
            node.text().set(value.c_str());
            setDirty(node.root().first_child().name(), true);
        }
        ImGui::PopItemWidth();
    } else if(type == "int"){
        int value = node.text().as_int();
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::InputScalar(("##" + node.path()).c_str(), ImGuiDataType_S32, &value, nullptr, nullptr, "%d", ImGuiInputTextFlags_EnterReturnsTrue)){
            node.text().set(value);
            setDirty(node.root().first_child().name(), true);
        }
        ImGui::PopItemWidth();
    } else if (type == "uint"){
        unsigned int value = node.text().as_uint();
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::InputScalar(("##" + node.path()).c_str(), ImGuiDataType_U32, &value, nullptr, nullptr, "%lu", ImGuiInputTextFlags_EnterReturnsTrue)){
            node.text().set(value);
            setDirty(node.root().first_child().name(), true);
        }
        ImGui::PopItemWidth();
    } else if (type == "int64"){
int64_t value = node.text().as_llong();
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::InputScalar(("##" + node.path()).c_str(), ImGuiDataType_S64, &value, nullptr, nullptr, "%lld", ImGuiInputTextFlags_EnterReturnsTrue)){
            node.text().set(value);
            setDirty(node.root().first_child().name(), true);
        }
        ImGui::PopItemWidth();
    } else if (type == "uint64"){
        uint64_t value = node.text().as_ullong();
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::InputScalar(("##" + node.path()).c_str(), ImGuiDataType_U64, &value, nullptr, nullptr, "%llu", ImGuiInputTextFlags_EnterReturnsTrue)){
            node.text().set(value);
            setDirty(node.root().first_child().name(), true);
        }
        ImGui::PopItemWidth();
    } else if(type == "float"){
        float value = node.text().as_float();
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::InputFloat(("##" + node.path()).c_str(), &value, 0.1f, 1.0f, "%.3f", ImGuiInputTextFlags_EnterReturnsTrue)){
            node.text().set(value);
            setDirty(node.root().first_child().name(), true);
        }
        ImGui::PopItemWidth();
    } else if(type == "bool"){
        bool value = node.text().as_bool();
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::Checkbox(("##" + node.path()).c_str(), &value)){
            node.text().set(value);
            setDirty(node.root().first_child().name(), true);
        }
        ImGui::PopItemWidth();
    } else if(type == "enum"){
        std::string value = node.child("selected").text().as_string();
        std::string selectedName;
        std::vector<pugi::xml_node> options;
        for(auto& option : node.children("option")){
            options.push_back(option);
            if(option.text().as_string() == value){
                if(option.attribute("name")){
                    selectedName = option.attribute("name").as_string();
                } else {
                    selectedName = option.text().as_string();
                }
            }
        }
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::BeginCombo(("##" + node.path()).c_str(), value.c_str())){
        for(auto& option : options){
                std::string optionValue = option.text().as_string();
                std::string name;
                bool selected = optionValue == value;
                if(option.attribute("name")){
                    name = option.attribute("name").as_string();
                } else {
                    name = optionValue;
                }
                if(ImGui::Selectable(name.c_str(), selected)){
                    node.child("selected").text().set(optionValue.c_str());
                    setDirty(node.root().first_child().name(), true);
                }
                if(selected){
                    ImGui::SetItemDefaultFocus();
                }
                if(option.attribute("description")){
                    if(ImGui::IsItemHovered()){
                        ImGui::BeginTooltip();
                        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                        ImGui::TextUnformatted(option.attribute("description").as_string());
                        ImGui::PopTextWrapPos();
                        ImGui::EndTooltip();
                    }
                }
            }
            ImGui::EndCombo();
        }
        ImGui::TableSetColumnIndex(0);
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + ImGui::GetTextLineHeight()/2);
        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
        ImGui::TextWrapped("%s", selectedName.c_str());
        ImGui::PopStyleColor();
        ImGui::TableSetColumnIndex(1);
    } else if (type == "xmlnode"){
        ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
        if(ImGui::TreeNode(node.path().c_str())){
            for(auto& child : node.children()){
                ImGui::TableNextColumn();
                drawXMLValueInput(child);
            }
            ImGui::TreePop();
        }
        ImGui::PopItemWidth();
//        drawXMLConfigNode(node);
    }
}


// config name specification:
// If the config is in the local mod space, i.e. for the specified mod it is of the form:
// <modName>.<configPath>.<configValue>
// If the config is in the global mod space, i.e. for all mods it is of the form:
// $.<modName>.<configPath>.<configValue>
// For now only put variables of type bool into the map

// When specifying a mod path for a config, it should be equivalent to the chain of xml names separated by dots
std::unordered_map<std::string, bool> ConfigManager::getModSpaceBooleanVariables(const std::string &modName) {
    std::unordered_map<std::string, bool> variables;
    for (auto &config : m_modConfigs) {
        if (config.modName == modName) {
            auto variableSpace = getModVariableSpace(config.configNode, {"bool"});
            for (auto &variable : variableSpace) {
                auto variableName = variable.first.substr(1);
                variables[variableName] = variable.second;
            }
        } else {
            auto variableSpace = getModVariableSpace(config.configNode, {"bool"});
            for (auto &variable : variableSpace) {
                auto variableName = "$." + variable.first.substr(1);
                variables[variableName] = variable.second;
            }
        }
    }
    return variables;
}

std::vector<std::pair<std::string, bool>> ConfigManager::getModVariableSpace(pugi::xml_node node, const std::set<std::string> &allowedTypes) {
std::vector<std::pair<std::string, bool>> variables;
    for (auto &child : node.children()) {
        if (allowedTypes.find(child.attribute("type").as_string()) != allowedTypes.end()) {
            variables.emplace_back(child.path('.'), child.text().as_bool());
        }
        auto childVariables = getModVariableSpace(child, allowedTypes);
        variables.insert(variables.end(), childVariables.begin(), childVariables.end());
    }
    return variables;
}
