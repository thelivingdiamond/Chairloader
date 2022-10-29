//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_CONFIGVALIDATIONSTAGE_H
#define CHAIRLOADER_CONFIGVALIDATIONSTAGE_H

#include "ImGui/imgui.h"
#include "pch.h"
#include "App/AppStage.h"
#include "ConfigManager.h"

class ConfigValidationStage : public AppStage {
public:
    ~ConfigValidationStage() override;

    ConfigValidationStage();

    void Start() override;

    void Update() override;

    void ShowUI(bool *bOpen) override;
private:
    bool m_bShow = false;

    enum class ConfigUIState {
        None,
        Welcome,
        GamePaths,
        Error,
        Done,
    };
    ConfigUIState m_uiState = ConfigUIState::None;
    std::string m_error;
    void setState(ConfigUIState state) { m_uiState = state; }
    void error(const std::string &error);

    ImVec2 WINDOW_SIZE = ImVec2(800, 300);
    ImGuiWindowFlags WINDOW_FLAGS = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
    std::string WINDOW_TITLE = "Mod Tool Kit Configuration";

    void showWelcomeWindow();

    void showGamePathsWindow();

    void showErrorWindow();

    void showDoneWindow();

    ConfigManager* m_configManager;
};


#endif //CHAIRLOADER_CONFIGVALIDATIONSTAGE_H
