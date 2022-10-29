#include "ConfigManager.h"
#include "ImGui/imgui_stdlib.h"
#include "IconsMaterialDesign.h"
#include "App/AppImGui.h"
#include "ModLoader/PathUtils.h"


static ConfigManager* g_pApp;

ConfigManager::ConfigManager() {
    g_pApp = this;
}

ConfigManager *ConfigManager::Get() {
    return g_pApp;
}

void ConfigManager::LoadFromXML() {
    m_configFile = std::make_shared<pugi::xml_document>();
    createConfigFile();
    if(!m_configFile){
        m_configFile->load_file(m_configFilePath.c_str());
        m_configNode = m_configFile->child("ModToolKitConfig");
    }
    m_bConfigFileValid = validateConfigFile();
    if(!m_bConfigFileValid){
        showConfigWindow();
    }
	m_gamePath = R"(C:\Program Files (x86)\Steam\steamapps\common\Prey)";
    m_PreyFilesPath = R"(C:\Users\theli\Documents\Prey Modding\ChairLoader\ChairloaderModLoader\Data\PreyFiles)";
}

void ConfigManager::SaveToXML() {
    if(!m_configFile) return;
    m_configFile->save_file(m_configFilePath.c_str());
}

void ConfigManager::Init() {

}

void ConfigManager::Update() {
}

void ConfigManager::ShowUI() {
}

void ConfigManager::createConfigFile() {
    if(!fs::exists(m_configFilePath)) {
        m_configFile->reset();
        m_configFile->append_child("ModToolKitConfig");
        m_configNode = m_configFile->child("ModToolKitConfig");
        if(!m_configFile->save_file(m_configFilePath.c_str())){
            throw std::runtime_error("Could not create config file!");
        }
    }
}

bool ConfigManager::validateConfigFile() {
    for(auto& node : m_importantNodes){
        if(!m_configNode.first_element_by_path(node.c_str())){
            return false;
        }
    }
    return true;
}

void ConfigManager::showConfigWindow() {
}

bool ConfigManager::validateConfigPaths(std::string &error) {
    bool valid = false;
    valid = PathUtils::ValidateGamePath(m_gamePath, &error);
    if(!fs::exists(m_PreyFilesPath)){
        error = "Prey Files Path does not exist";
        valid = false;
    }
    return valid;
}
