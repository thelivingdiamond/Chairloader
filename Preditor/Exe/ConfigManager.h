#pragma once

#include "pch.h"
#include "Manager/GamePath.h"
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

    GamePath& getGamePath() { return m_gamePath; }
    fs::path& getPreyFilesPath() { return m_PreyFilesPath; }
    pugi::xml_node& getConfigNode() { return m_configNode; }

    void showConfigWindow();

    void LoadFromXML();
	void SaveToXML();
    bool isConfigValid() { return m_bConfigFileValid; }

    bool validateConfigPaths(std::string &error);

protected:
    static constexpr char CONFIG_FILE_NAME[] = "ModToolKitConfig.xml";
    GamePath m_gamePath;
    fs::path m_PreyFilesPath;

    std::shared_ptr<pugi::xml_document> m_configFile;
    pugi::xml_node m_configNode;
    void createConfigFile();

    const std::vector<std::string> m_criticalNodes = {
        "Paths",
        "Paths/GamePath",
        "Paths/PreyFilesPath",
    };
    const std::vector<std::string> m_importantNodes = {
            "Projects",
    };
    bool m_bConfigFileValid = false;
    bool validateConfigFile();

    fs::path GetConfigPath();

    friend ConfigValidationStage;
};
