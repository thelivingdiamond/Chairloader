#include <Manager/GamePath.h>
#include "ConfigManager.h"
#include "ImGui/imgui_stdlib.h"
#include "App/AppImGui.h"
#include "Preditor.h"

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
    m_gamePath = m_configNode.child("Paths").child("GamePath").text().as_string();
    m_PreyFilesPath = m_configNode.child("Paths").child("PreyFilesPath").text().as_string();
    m_bConfigFileValid = validateConfigFile();
    if(!m_bConfigFileValid){
        showConfigWindow();
    }
}

void ConfigManager::SaveToXML() {
    if(!m_configFile) return;
    m_configNode.child("Paths").child("GamePath").text().set(m_gamePath.u8string().c_str());
    m_configNode.child("Paths").child("PreyFilesPath").text().set(m_PreyFilesPath.u8string().c_str());
    m_configFile->save_file(GetConfigPath().c_str());
}

void ConfigManager::Init() {
    AppModule::Init();
}

void ConfigManager::Update() {
}

void ConfigManager::ShowUI() {
}

void ConfigManager::createConfigFile() {
    fs::path configPath = GetConfigPath();
    if(!fs::exists(configPath)) {
        m_configFile->reset();
        m_configFile->append_child("ModToolKitConfig");
        m_configNode = m_configFile->child("ModToolKitConfig");
        m_configNode.append_child("Paths");
        m_configNode.append_child("Projects");
        m_configNode.child("Paths").append_child("GamePath");
        m_configNode.child("Paths").append_child("PreyFilesPath");
        if(!m_configFile->save_file(configPath.c_str())){
            throw std::runtime_error("Could not create config file!");
        }
    } else {
        m_configFile->load_file(configPath.c_str());
        m_configNode = m_configFile->child("ModToolKitConfig");
    }
}

bool ConfigManager::validateConfigFile() {
    for(auto& node : m_criticalNodes){
        if(!m_configNode.first_element_by_path(node.c_str())){
            return false;
        }
    }
    return true;
}

fs::path ConfigManager::GetConfigPath()
{
    return Preditor::Get()->GetProgramPath() / CONFIG_FILE_NAME;
}

void ConfigManager::showConfigWindow() {
}

bool ConfigManager::validateConfigPaths(std::string &error) {
    bool valid = true;

    valid &= GamePath::ValidateGamePath(m_gamePath, &error);

    if(!fs::exists(m_PreyFilesPath)){
        error = "Prey Files Path does not exist";
        valid = false;
    }

    return valid;
}
