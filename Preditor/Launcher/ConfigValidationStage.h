//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_CONFIGVALIDATIONSTAGE_H
#define CHAIRLOADER_CONFIGVALIDATIONSTAGE_H

#include "ImGui/imgui.h"
#include "App/AppStage.h"

class ConfigValidationStage : public AppStage
{
public:
    void Start() override;
    void ShowUI(bool* bOpen) override;

private:
    const ImVec2 WINDOW_SIZE = ImVec2(800, 300);
    static constexpr ImGuiWindowFlags WINDOW_FLAGS =
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoDocking;
    static constexpr char WINDOW_TITLE[] = "Preditor Configuration";

    enum class ConfigUIState {
        None,
        Welcome,
        GamePaths,
        Error,
        Done,
        FatalError,
    };

    std::unique_ptr<PreditorConfig> m_pConfig;
    ConfigUIState m_uiState = ConfigUIState::None;
    std::string m_error;

    std::string m_GamePath;

    //! Switches to a new state.
    void SetState(ConfigUIState state) { m_uiState = state; }

    //! Switches to the error state. Allows to go back.
    void Error(const std::string& error);

    //! Called when config is successfully validated.
    void OnFinish();

    void ShowWelcomeWindow(bool* bOpen);
    void ShowGamePathsWindow(bool* bOpen);
    void ShowErrorWindow(bool* bOpen);
    void ShowDoneWindow(bool* bOpen);
    void ShowFatalErrorWindow(bool* bOpen);
};


#endif //CHAIRLOADER_CONFIGVALIDATIONSTAGE_H
