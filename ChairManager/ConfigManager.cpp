//
// Created by theli on 9/13/2022.
//

#include "ConfigManager.h"
#include "ChairManager.h"

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

bool ConfigManager::isConfigPresent(const std::string& modName){
    try {
        return fs::exists(ChairManager::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml"));
    } catch (fs::filesystem_error& e) {
        ChairManager::Get().log(severityLevel::error, "Error checking for config file: %s", e.what());
        return false;
    }
}

void ConfigManager::copyDefaultConfig(const std::string& modName){
    try{
        if(fs::exists(ChairManager::Get().GetGamePath() / "Mods" / modName / (modName + "_default.xml"))){
            fs::copy_file(ChairManager::Get().GetGamePath() / "Mods" / modName / (modName + "_default.xml"), ChairManager::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml"), fs::copy_options::overwrite_existing);
        } else {
            ChairManager::Get().log(severityLevel::warning, "Default config file for mod %s not found! Creating empty config file", modName.c_str());
            pugi::xml_document doc;
            doc.append_child(modName.c_str());
            doc.save_file((ChairManager::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml")).string().c_str());
        }
    } catch (fs::filesystem_error& e) {
        ChairManager::Get().log(severityLevel::error, "Failed to copy default config for mod %s : %s", modName.c_str(), e.what());
    }
}


void ConfigManager::loadConfig(const std::string& modName){
    if(!isConfigPresent(modName)){
        copyDefaultConfig(modName);
    }
    fs::path configPath = ChairManager::Get().GetGamePath() / "Mods" / "Config" / (modName + ".xml");
    pugi::xml_document doc;
    auto result = doc.load_file(configPath.string().c_str());
    if(result){
        m_modConfigs.emplace_back(modName, doc, configPath);
    } else {
        ChairManager::Get().log(severityLevel::error, "Failed to load config for mod %s with Error: %s", modName.c_str(), result.description());
    }
}


//! Load all config files, copying default config files if they don't exist
void ConfigManager::loadConfigs(){
    auto modList = ChairManager::Get().GetMods();
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
                ChairManager::Get().log(severityLevel::error, "Failed to save config for mod %s", config.modName.c_str());
            }
        }
    }
}

//! Save all configs
void ConfigManager::saveConfigs() {
    for(auto& config : m_modConfigs){
        if(!config.saveConfig()){
            ChairManager::Get().log(severityLevel::error, "Failed to save config for mod %s", config.modName.c_str());
        }
    }
}




void ConfigManager::draw() {
   if(ImGui::BeginTabItem("Mod Config")){
       if(ImGui::BeginTabBar("##Mod Configs", ImGuiTabBarFlags_TabListPopupButton | ImGuiTabBarFlags_FittingPolicyScroll)){
              for(auto& config : m_modConfigs){
                  if(config.configNode.first_child() == nullptr){
                      continue;
                  }
                  auto displayName = ChairManager::Get().GetDisplayName(config.modName);
                  if(displayName.empty()){
                      displayName = config.modName;
                  }
                if(ImGui::BeginTabItem((displayName + "##" + config.modName).c_str())){
                    drawXMLConfigNode(config.configNode);
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
        if(ImGui::BeginTable("ConfigTable", 2, ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_NoClip)) {
            ImGui::TableSetupColumn("Key", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoClip);
            ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch | ImGuiTableColumnFlags_NoClip);
//            ImGui::TableHeadersRow();
            for (auto &child: node.children()) {
                if (child.type() == pugi::node_pcdata) {
                    continue;
                }
//                if(child.first_child().type() == pugi::node_pcdata )
                auto size = std::distance(child.children().begin(), child.children().end());
                if(size == 1 && child.first_child().type() == pugi::node_pcdata){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("%s", child.name());
                    ImGui::TableNextColumn();
                    std::string ChildValue = child.text().as_string();
                    ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - ImGui::GetCursorPosX());
                    if (ImGui::InputText(("##" + child.path()).c_str(), &ChildValue, ImGuiInputTextFlags_EnterReturnsTrue)) {
                        child.text().set(ChildValue.c_str());
                        setDirty(child.root().first_child().name(), true);
                    }
                    ImGui::PopItemWidth();
                } else if(size > 0){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    drawXMLConfigNode(child);
                    ImGui::TableNextColumn();
                }
            }
            ImGui::EndTable();
        }
        ImGui::TreePop();
    }
}

void ConfigManager::setDirty(const std::string& modName, bool dirty) {
    auto config = std::find(m_modConfigs.begin(), m_modConfigs.end(), modName);
    if(config != m_modConfigs.end()){
        config->dirty = dirty;
    } else {
        ChairManager::Get().log(severityLevel::warning, "Failed to set dirty flag for mod %s, mod not found", modName.c_str());
    }
}
