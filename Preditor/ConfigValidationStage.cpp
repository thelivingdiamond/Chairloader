//
// Created by theli on 10/28/2022.
//

#include "ConfigValidationStage.h"
#include "ConfigManager.h"
#include "App/AppImGui.h"
#include "IconsMaterialDesign.h"

ConfigValidationStage::~ConfigValidationStage() {

}

void ConfigValidationStage::Start() {
    m_bShow = true;
    setState(ConfigUIState::Welcome);
}

void ConfigValidationStage::Update() {
}

void ConfigValidationStage::ShowUI(bool *bOpen) {
    ImGui::PushFont(AppImGui::getPrettyFont());
    switch(m_uiState){
        case ConfigUIState::Welcome:
            showWelcomeWindow();
            break;
        case ConfigUIState::GamePaths:
            showGamePathsWindow();
            break;
        case ConfigUIState::Done:
            showDoneWindow();
            break;
        case ConfigUIState::Error:
            showErrorWindow();
            break;
        case ConfigUIState::None:
        default:
            SetStageFinished();
            break;
    }
    ImGui::PopFont();
    if(!m_bShow && m_uiState != ConfigUIState::None){
        *bOpen = false;
    }
}

ConfigValidationStage::ConfigValidationStage() {
    m_configManager = ConfigManager::Get();

}


void ConfigValidationStage::showWelcomeWindow() {
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if(ImGui::Begin(WINDOW_TITLE.c_str(), &m_bShow, WINDOW_FLAGS)){
        ImGui::Text("Welcome to the ModToolKit configuration window!");
        ImGui::Text("This window will help you configure the ModToolKit to work with your game installation.");
        ImGui::Text("Please click the button below to continue.");
        if(ImGui::Button("Continue")){
            setState(ConfigUIState::GamePaths);
        }
    }
    ImGui::End();
}

void ConfigValidationStage::showGamePathsWindow() {
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if(ImGui::Begin(WINDOW_TITLE.c_str(), &m_bShow, WINDOW_FLAGS)){
        ImGui::Text("Please enter the path to your game installation.");
        ImGui::Text("This is the base folder of the game.");
        ImGui::Text("For example: C:\\Program Files (x86)\\Steam\\steamapps\\common\\Prey");
        ImGui::BeginDisabled();
        ImGui::InputText("##GamePath",  m_configManager->m_gamePath.u8string().data(), ImGuiInputTextFlags_ReadOnly);
        ImGui::EndDisabled();
        ImGui::SameLine();
        if(ImGui::Button(ICON_MD_MORE_HORIZ "##GAMEPATHSELECTION")){
            //TODO: import the file dialog
        }
        ImGui::NewLine();
        ImGui::NewLine();
        ImGui::Text("Please enter the path to the PreyFiles folder. This is where the necessary unpacked assets are located.");
        ImGui::Text("This is included with the Chairloader release currently. TODO: unpack files from the game installation.");
        ImGui::BeginDisabled();
        ImGui::InputText("##PREYFILESPATH", m_configManager->m_PreyFilesPath.u8string().data(), ImGuiInputTextFlags_ReadOnly);
        ImGui::EndDisabled();
        ImGui::SameLine();
        if(ImGui::Button(ICON_MD_MORE_HORIZ "##PREYFILESSELECTION")){

        }
        ImGui::NewLine();
        if(ImGui::Button("Continue")){
            if(!m_configManager->validateConfigPaths(m_error)){
                error(m_error);
            } else {
                setState(ConfigUIState::Done);
            }
        }
        if(ImGui::Button("Error")){
            error("This is an error");
        }
    }
    ImGui::End();
}

void ConfigValidationStage::showErrorWindow() {
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if (ImGui::Begin(WINDOW_TITLE.c_str(), &m_bShow, WINDOW_FLAGS)) {
        ImGui::Text("There was an error with the selected paths. Please try again.");
        ImGui::Text("%s", m_error.c_str());
        if (ImGui::Button("Continue")) {
            setState(ConfigUIState::GamePaths);
        }
    }
    ImGui::End();
}

void ConfigValidationStage::showDoneWindow() {
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if (ImGui::Begin(WINDOW_TITLE.c_str(), &m_bShow, WINDOW_FLAGS)) {
        ImGui::Text("The configuration is now complete. You can now close this window.");
        if (ImGui::Button("Close")) {
            setState(ConfigUIState::None);
            SetStageFinished();
            m_bShow = false;
        }
    }
    ImGui::End();
}

void ConfigValidationStage::error(const std::string &error) {
    m_error = error;
    setState(ConfigUIState::Error);
}


