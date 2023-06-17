//
// Created by theli on 10/28/2022.
//

#include <ImGuiFileDialog/ImGuiFileDialog.h>
#include "ConfigValidationStage.h"
#include "App/AppImGui.h"
#include "ImGui/imgui_stdlib.h"
#include "ProjectSelectStage.h"
#include "PreditorApp.h"

void ConfigValidationStage::Start()
{
    try
    {
        m_uiState = ConfigUIState::Welcome;
        m_pConfig = std::make_unique<PreditorConfig>();

        bool cfgLoaded = m_pConfig->LoadFromXml();
        if (cfgLoaded)
        {
            if (m_pConfig->ValidateConfig())
            {
                // Config is valid, can go on
                OnFinish();
            }
        }

        // Read vars from the config
        m_GamePath = m_pConfig->GetRawGamePath().u8string();
    }
    catch (const std::exception& e)
    {
        m_uiState = ConfigUIState::FatalError;
        m_error = e.what();
    }
}

void ConfigValidationStage::ShowUI(bool* bOpen)
{
    switch (m_uiState) {
    case ConfigUIState::Welcome:
        ShowWelcomeWindow(bOpen);
        break;
    case ConfigUIState::GamePaths:
        ShowGamePathsWindow(bOpen);
        break;
    case ConfigUIState::Done:
        ShowDoneWindow(bOpen);
        break;
    case ConfigUIState::Error:
        ShowErrorWindow(bOpen);
        break;
    case ConfigUIState::FatalError:
        ShowFatalErrorWindow(bOpen);
        break;
    default:
        assert(false);
        break;
    }
}

void ConfigValidationStage::Error(const std::string& error) {
    m_error = error;
    SetState(ConfigUIState::Error);
}

void ConfigValidationStage::OnFinish()
{
    PreditorApp::Get()->OnConfigValidated(std::move(m_pConfig));
    SetStageFinished(std::make_unique<ProjectSelectStage>());
}


void ConfigValidationStage::ShowWelcomeWindow(bool* bOpen)
{
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
    {
        ImGui::Text("Welcome to the Preditor configuration window!");
        ImGui::Text("This window will help you configure the Preditor to work with your game installation.");
        ImGui::Text("Please click the button below to continue.");

        if (ImGui::Button("Continue"))
            SetState(ConfigUIState::GamePaths);
    }
    ImGui::End();
}

void ConfigValidationStage::ShowGamePathsWindow(bool* bOpen)
{
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
    {
        ImGui::Text("Please enter the path to your game installation.");
        ImGui::Text("This is the base folder of the game.");
        ImGui::Text("For example: C:\\Program Files (x86)\\Steam\\steamapps\\common\\Prey");
        
        if (ImGui::InputText("##GamePath", &m_GamePath))
            m_pConfig->SetRawGamePath(fs::u8path(m_GamePath), nullptr);
        ImGui::SameLine();

        if (ImGui::Button(ICON_MD_MORE_HORIZ "##GAMEPATHSELECTION"))
            ImGuiFileDialog::Instance()->OpenModal("SelectGamePathDialog", "Select Game Directory", nullptr, ".");

        ImGui::NewLine();
        ImGui::NewLine();

        if (ImGui::Button("Continue"))
        {
            if (!m_pConfig->ValidateConfig(&m_error))
            {
                Error(m_error);
            }
            else
            {
                m_pConfig->SaveToXml();
                SetState(ConfigUIState::Done);
            }
        }
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(ImGui::GetWindowPos()), ImGuiCond_Appearing);
    if (ImGuiFileDialog::Instance()->Display("SelectGamePathDialog"))
    {
        if (ImGuiFileDialog::Instance()->IsOk())
        {
            m_GamePath = ImGuiFileDialog::Instance()->GetCurrentPath();
            m_pConfig->SetRawGamePath(fs::u8path(m_GamePath), nullptr);
        }

        ImGuiFileDialog::Instance()->Close();
    }
}

void ConfigValidationStage::ShowErrorWindow(bool* bOpen)
{
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
    {
        ImGui::Text("There was an error with the selected paths. Please try again.");
        ImGui::Text("%s", m_error.c_str());

        if (ImGui::Button("Continue"))
        {
            SetState(ConfigUIState::GamePaths);
        }
    }

    ImGui::End();
}

void ConfigValidationStage::ShowDoneWindow(bool* bOpen)
{
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
    {
        ImGui::Text("The configuration is now complete. You can now close this window.");
        if (ImGui::Button("Close")) {
            OnFinish();
        }
    }
    ImGui::End();
}

void ConfigValidationStage::ShowFatalErrorWindow(bool* bOpen)
{
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
    if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
    {
        ImGui::Text("There was an error with your Preditor installation.");
        ImGui::Text("%s", m_error.c_str());
        ImGui::NewLine();

        if (ImGui::Button("Exit"))
        {
            SetStageFinished(nullptr);
        }
    }

    ImGui::End();
}
