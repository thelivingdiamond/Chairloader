//
// Created by theli on 1/6/2023.
//

#include <Chairloader/IChairloaderDll.h>
#include "ChairVarManager.h"
static ChairVarManager* g_pChairVarManager = nullptr;

void ChairVarManager::RegisterCVar(ICVar *cvar, const std::string &modName) {
    if((cvar->GetFlags() & VF_DUMPTOCHAIR) == 0){
        CryWarning("Cannot register CVar {} to ChairVarManager, it does not have the VF_DUMPTOCHAIR flag set.", cvar->GetName());
        return;
    }
    if (m_cvars.find(modName) == m_cvars.end()) {
        m_cvars[modName] = std::vector<CVarSaveData>();
    }
    // find the cvar in the list
    CVarSaveData* data = nullptr;
    std::string name = cvar->GetName();
    for(auto& cvarData : m_cvars[modName]){
        if(cvarData.cvarName == name){
            data = &cvarData;
            break;
        }
    }
    if (data != nullptr) {
        cvar->Set(data->cvarValue.c_str());
        data->pCvar = cvar;
        return;
    }
    m_cvars[modName].push_back({modName, cvar->GetName(), cvar->GetString(), cvar});
}

void ChairVarManager::UnregisterCVar(ICVar *cvar) {
    for (auto& mod : m_cvars) {
        auto cvarEntry = std::find_if(mod.second.begin(), mod.second.end(), [cvar](const CVarSaveData& data) {
            return data.cvarName == cvar->GetName();
        });
        if (cvarEntry != mod.second.end()) {
            mod.second.erase(cvarEntry);
            return;
        }
    }
}

void ChairVarManager::UnregisterCVar(const std::string &name) {
    for (auto& mod : m_cvars) {
        auto cvarEntry = std::find_if(mod.second.begin(), mod.second.end(), [name](const CVarSaveData& data) {
            return data.cvarName == name;
        });
        if (cvarEntry != mod.second.end()) {
            mod.second.erase(cvarEntry);
            return;
        }
    }
}

static void SaveCvarCommand(IConsoleCmdArgs*){
    if(g_pChairVarManager != nullptr){
        g_pChairVarManager->SaveConfig();
    }
}

void ChairVarManager::InitSystem() {
    LoadConfig();
    g_pChairVarManager = this;
    REGISTER_COMMAND("chair_savecvars", &SaveCvarCommand, VF_NULL, "Saves the Chairloader CVar config file");
    REGISTER_CVAR2("ch_chvar_save_interval", &m_SaveInterval, m_SaveInterval, VF_DUMPTOCHAIR, "The interval in seconds between auto saving the Chairloader CVar config file");
    REGISTER_CVAR2("ch_chvar_save_timer", &m_SaveTimer, m_SaveTimer, VF_NULL, "The timer in seconds until the Chairloader CVar config file is auto saved");
}

void ChairVarManager::ShutdownGame() {
    SaveConfig();
}

void ChairVarManager::LoadConfig() {
    fs::path configPath = gChair->GetModsPath() / m_configPathFromMods;
    auto success = m_config.load_file(configPath.c_str());
    if(!success) {
        m_configNode = m_config.append_child("Chairloader_CVars");
        m_config.save_file(configPath.c_str());
        CryWarning("Chairloader_CVars.xml not found, creating new file.");
    } else {
        m_configNode = m_config.child("Chairloader_CVars");
    }
    if(!m_configNode) {
        m_configNode = m_config.append_child("Chairloader_CVars");
        m_config.save_file(configPath.c_str());
        CryWarning("Chairloader_CVars.xml is corrupted, creating new file.");
    }
    for(auto& modChild: m_configNode.children("Mod")){
        std::string modName = modChild.attribute("name").value();
        m_cvars[modName] = std::vector<CVarSaveData>();
        for(auto& cvarChild: modChild.children("CVar")){
            std::string cvarName = cvarChild.attribute("name").value();
            std::string cvarValue = cvarChild.attribute("value").value();
            m_cvars[modName].push_back({modName, cvarName, cvarValue});
        }
    }
    CryLog("Loaded Chairloader_CVars.xml");
}

void ChairVarManager::SaveConfig() {
    if(!m_configNode) {
        m_configNode = m_config.append_child("Chairloader_CVars");
    }
    for(auto& mod: m_cvars){
        auto modNode = m_configNode.find_child_by_attribute("Mod", "name", mod.first.c_str());
        if(!modNode) {
            modNode = m_configNode.append_child("Mod");
            modNode.append_attribute("name") = mod.first.c_str();
        }
        for(auto& cvar: mod.second){
            if(cvar.pCvar == nullptr)
                continue;
            auto cvarNode = modNode.find_child_by_attribute("CVar", "name", cvar.pCvar->GetName());
            if(!cvarNode) {
                cvarNode = modNode.append_child("CVar");
                cvarNode.append_attribute("name") = cvar.pCvar->GetName();
            }
            if(!cvarNode.attribute("value")) {
                cvarNode.append_attribute("value") = cvar.pCvar->GetString();
            } else {
                cvarNode.attribute("value") = cvar.pCvar->GetString();
            }
        }
    }
    fs::path configPath = gChair->GetModsPath() / m_configPathFromMods;
    auto success = m_config.save_file(configPath.c_str());
    if(!success) {
        CryWarning("Failed to save Chairloader_CVars.xml");
    } else {
        CryLog("Saved Chairloader_CVars.xml");
    }
}

void ChairVarManager::UpdateSystem() {
    if(m_SaveInterval > 0){
        m_SaveTimer += gEnv->pTimer->GetFrameTime();
        if(m_SaveTimer >= m_SaveInterval){
            SaveConfig();
            m_SaveTimer = 0;
        }
    }
}
