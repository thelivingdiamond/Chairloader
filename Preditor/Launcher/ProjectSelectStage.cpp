//
// Created by theli on 10/28/2022.
//

#include <Preditor/Main/IProject.h>
#include <ImGuiFileDialog/ImGuiFileDialog.h>
#include "ProjectSelectStage.h"
#include "ImGui/imgui.h"
#include "App/AppImGui.h"
#include "PreditorApp.h"
#include "ImGui/imgui_stdlib.h"
#include "LoadGameStage.h"
#include "ProjectHistory.h"
#include "ProjectCreateStage.h"

ProjectSelectStage::ProjectSelectStage()
{
    m_History = ProjectHistory::ReadHistory();
}

void ProjectSelectStage::ShowUI(bool* bOpen)
{
    if (m_ShowError)
    {
        ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
        if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
        {
            ImGui::TextColored(ImColor(255, 0, 0), "Error!");
            ImGui::NewLine();
            ImGui::TextWrapped("%s", m_ErrorText.c_str());
            ImGui::NewLine();

            if (ImGui::Button("Back"))
            {
                m_ShowError = false;
            }
        }
        ImGui::End();
    }
    else
    {
        ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
        if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
        {
            ImGui::Text("Previous Projects");

            if (ImGui::BeginTable("Previous Projects", 1, ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_RowBg))
            {
                ImGui::TableSetupColumn("Project Path");
                
                if (m_History.empty())
                {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("No previous projects found");
                }
                else
                {
                    for (const fs::path& project : m_History)
                    {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        if (ImGui::Selectable(project.u8string().c_str()))
                            initiateLoadProject(project);
                    }
                }

                ImGui::EndTable();
            }

            // snap the buttons to the bottom of the window
            ImGui::SetCursorPosY(
                ImGui::GetWindowHeight() - ImGui::GetFrameHeight() - ImGui::GetStyle().ItemSpacing.y * 2);

            if (ImGui::Button("New Project"))
            {
                SetStageFinished(std::make_unique<ProjectCreateStage>());
            }
            ImGui::SameLine();

            if (ImGui::Button("Open Project"))
            {
                ImGuiFileDialog::Instance()->OpenModal(
                    "ProjectSelectStage::OpenProject",
                    "Select Project Directory", nullptr, ".");
            }
            ImGui::SameLine();

            if (ImGui::Button("Quit"))
                SetStageFinished(nullptr);

            if (ImGuiFileDialog::Instance()->Display("ProjectSelectStage::OpenProject"))
            {
                if (ImGuiFileDialog::Instance()->IsOk())
                {
                    initiateLoadProject(fs::u8path(ImGuiFileDialog::Instance()->GetCurrentPath()));
                }

                ImGuiFileDialog::Instance()->Close();
            }
        }

        ImGui::End();
    }
}

void ProjectSelectStage::initiateLoadProject(const fs::path& path)
{
    if (!path.is_absolute())
        m_loadProjectPath = fs::absolute(path);
    else
        m_loadProjectPath = path;

    if (m_loadProjectPath.filename() == IProject::PROJECT_FILE_NAME)
        m_loadProjectPath = m_loadProjectPath.parent_path();

    try
    {
        ProjectHistory::AddToHistory(m_loadProjectPath);
        PreditorApp::Get()->GetPahts().SetProjectDirPath(m_loadProjectPath);
        SetStageFinished(std::make_unique<LoadGameStage>(nullptr));
    }
    catch (const std::exception& e)
    {
        m_ErrorText = e.what();
        m_ShowError = true;
    }
}
