//
// Created by theli on 1/6/2023.
//

#ifndef CHAIRLOADER_CHAIRVARMANAGER_H
#define CHAIRLOADER_CHAIRVARMANAGER_H

#include "../Common/Chairloader/IChairVarManager.h"
#include <pugixml.hpp>

class ChairVarManager: public IChairVarManager {
public:
    void RegisterCVar(ICVar *cvar, const std::string &modName) override;

    void UnregisterCVar(ICVar *cvar) override;

    void UnregisterCVar(const std::string &name) override;

    void InitSystem() override;

    void ShutdownGame() override;

    void LoadConfig();

    void SaveConfig();
private:
    struct CVarSaveData {
        std::string modName;
        std::string cvarName;
        std::string cvarValue;
        ICVar* pCvar = nullptr;
    };

    std::map<std::string, std::vector<CVarSaveData>> m_cvars;

    const fs::path m_configPath = "Mods/config/Chairloader_CVars.xml";

    pugi::xml_document m_config;
    pugi::xml_node m_configNode;
};


#endif //CHAIRLOADER_CHAIRVARMANAGER_H
