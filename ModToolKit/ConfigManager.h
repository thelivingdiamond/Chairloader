#pragma once

#include "pch.h"
#include "App/AppModule.h"
#include "pugixml.hpp"
#include "ImGui/imgui.h"

class ConfigValidationStage;

class ConfigManager: public AppModule
{
public:

    ConfigManager();

    static ConfigManager* Get();

    void Init() override;

    void Update() override;

    void ShowUI() override;

    fs::path getGamePath() { return m_gamePath; }

    void showConfigWindow();

    void LoadFromXML();
	void SaveToXML();
    bool isConfigValid() { return m_bConfigFileValid; }

    bool validateConfigPaths(std::string &error);

protected:
    fs::path m_gamePath, m_PreyFilesPath;
    const fs::path m_configFilePath = "./ModToolKitConfig.xml";

    std::shared_ptr<pugi::xml_document> m_configFile;
    pugi::xml_node m_configNode;
    void createConfigFile();

    const std::vector<std::string> m_importantNodes = {
        "Paths",
        "Paths/GamePath",
        "Paths/PreyFilesPath",
    };
    bool m_bConfigFileValid = false;
    bool validateConfigFile();

    friend ConfigValidationStage;
};
