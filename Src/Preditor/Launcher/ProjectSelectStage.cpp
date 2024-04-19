//
// Created by theli on 10/28/2022.
//

#include <Preditor/Main/IProject.h>
#include <Preditor/FileHistory.h>
#include <WinShell/WinShell.h>
#include "ProjectSelectStage.h"
#include "ImGui/imgui.h"
#include "App/AppImGui.h"
#include "PreditorApp.h"
#include "ImGui/imgui_stdlib.h"
#include "LoadGameStage.h"
#include "ProjectCreateStage.h"

ProjectSelectStage::ProjectSelectStage()
{
    m_History = FileHistory::ReadHistory(gPreditor->pConfig->GetPreditorRoot() / PROJECT_HISTORY_FILE_PATH);
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
                    for (const std::string& project : m_History)
                    {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        if (ImGui::Selectable(project.c_str()))
                            initiateLoadProject(fs::u8path(project));
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
                WinShell::DialogOptions opts;
                opts.title = "Select Project Directory...";
                opts.flags |= WinShell::FL_PICK_FOLDERS;
                WinShell::ImShowFileOpenDialog("ProjectSelectStage::OpenProject", opts);
            }
            ImGui::SameLine();

            if (ImGui::Button("Quit"))
                SetStageFinished(nullptr);

            WinShell::DialogResult dialogResult;

            if (WinShell::ImUpdateFileOpenDialog("ProjectSelectStage::OpenProject", &dialogResult))
            {
                if (dialogResult.isOk)
                {
                    initiateLoadProject(dialogResult.filePath);
                }
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
        FileHistory::AddToHistory(gPreditor->pConfig->GetPreditorRoot() / PROJECT_HISTORY_FILE_PATH, m_loadProjectPath.u8string());
        PreditorApp::Get()->GetPahts().SetProjectDirPath(m_loadProjectPath);
        SetStageFinished(std::make_unique<LoadGameStage>(nullptr));
    }
    catch (const std::exception& e)
    {
        m_ErrorText = e.what();
        m_ShowError = true;
    }
}
