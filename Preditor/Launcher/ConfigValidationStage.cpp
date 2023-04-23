//
// Created by theli on 10/28/2022.
//

#include <ImGuiFileDialog/ImGuiFileDialog.h>
#include "ConfigValidationStage.h"
#include "ConfigManager.h"
#include "App/AppImGui.h"
#include "ImGuiFileDialog/ImGuiFileDialog.h"
#include "ImGui/imgui_stdlib.h"
#include "ProjectSelectStage.h"
#include "Preditor.h"


ConfigValidationStage::~ConfigValidationStage() {

}

void ConfigValidationStage::Start() {
    std::string error;
    if(!m_configManager->validateConfigPaths(error)){
        m_bShow = true;
        setState(ConfigUIState::Welcome);
    } else {
        m_bShow = false;
        setState(ConfigUIState::Done);
    }
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
        default:
            assert(false);
            break;
    }
    ImGui::PopFont();

    if(!m_bShow){
        if(m_uiState == ConfigUIState::Done) {
            Preditor::Get()->OnConfigValidated();
            SetStageFinished(std::make_unique<ProjectSelectStage>());
        }
        else {
            *bOpen = false;
        }
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
        static std::string gamePath;
        gamePath = m_configManager->m_gamePath.u8string();
        if(ImGui::InputText("##GamePath",  &gamePath)){
            m_configManager->m_gamePath = gamePath;
        }
        ImGui::SameLine();
        if(ImGui::Button(ICON_MD_MORE_HORIZ "##GAMEPATHSELECTION")){
            ImGuiFileDialog::Instance()->OpenModal("SelectGamePathDialog", "Select Game Directory", nullptr, ".");
        }
        ImGui::NewLine();
        ImGui::NewLine();
        ImGui::Text("Please enter the path to the PreyFiles folder. This is where the necessary unpacked assets are located.");
        ImGui::Text("This is included with the Chairloader release currently. TODO: unpack files from the game installation.");
        static std::string preyFilesPath;
        preyFilesPath = m_configManager->m_PreyFilesPath.u8string();
        if(ImGui::InputText("##PREYFILESPATH", &preyFilesPath)){
            m_configManager->m_PreyFilesPath = preyFilesPath;
        }
        ImGui::SameLine();
        if(ImGui::Button(ICON_MD_MORE_HORIZ "##PREYFILESSELECTION")){
            ImGuiFileDialog::Instance()->OpenModal("SelectPreyFilesPathDialog", "Select Prey Files Directory", nullptr, ".");
        }
        ImGui::NewLine();
        if(ImGui::Button("Continue")){
            if(!m_configManager->validateConfigPaths(m_error)){
                error(m_error);
            } else {
                setState(ConfigUIState::Done);
                m_configManager->SaveToXML();
            }
        }
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(ImGui::GetWindowPos()), ImGuiCond_Appearing);
    if (ImGuiFileDialog::Instance()->Display("SelectGamePathDialog")) {
        if (ImGuiFileDialog::Instance()->IsOk()) {
            ConfigManager::Get()->m_gamePath = fs::u8path(ImGuiFileDialog::Instance()->GetCurrentPath());
        }
        ImGuiFileDialog::Instance()->Close();
    }

    ImGui::SetNextWindowPos(ImVec2(ImGui::GetWindowPos()), ImGuiCond_Appearing);
    if (ImGuiFileDialog::Instance()->Display("SelectPreyFilesPathDialog")) {
        if (ImGuiFileDialog::Instance()->IsOk()) {
            ConfigManager::Get()->m_PreyFilesPath = fs::u8path(ImGuiFileDialog::Instance()->GetCurrentPath());
        }
        ImGuiFileDialog::Instance()->Close();
    }
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
            m_bShow = false;
        }
    }
    ImGui::End();
}

void ConfigValidationStage::error(const std::string &error) {
    m_error = error;
    setState(ConfigUIState::Error);
}


