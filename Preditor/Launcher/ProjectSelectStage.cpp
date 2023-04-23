//
// Created by theli on 10/28/2022.
//

#include <Preditor/Project/IProject.h>
#include <ImGuiFileDialog/ImGuiFileDialog.h>
#include "ProjectSelectStage.h"
#include "ImGui/imgui.h"
#include "App/AppImGui.h"
#include "Preditor.h"
#include "ImGui/imgui_stdlib.h"
#include "LoadGameStage.h"
#include "ProjectHistory.h"

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
                m_newProjectOpen = false;
            }
        }
        ImGui::End();
    }
    else if (!m_newProjectOpen)
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
                            initiateLoadOrCreateProject(project, true);
                    }
                }

                ImGui::EndTable();
            }

            // snap the buttons to the bottom of the window
            ImGui::SetCursorPosY(
                ImGui::GetWindowHeight() - ImGui::GetFrameHeight() - ImGui::GetStyle().ItemSpacing.y * 2);

            if (ImGui::Button("New Project"))
                m_newProjectOpen = true;
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
                    initiateLoadOrCreateProject(fs::u8path(ImGuiFileDialog::Instance()->GetCurrentPath()), true);
                }

                ImGuiFileDialog::Instance()->Close();
            }
        }

        ImGui::End();
    }
    else if (m_newProjectOpen)
    {
        if (ImGui::Begin("Create New Project", &m_newProjectOpen, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("New Project");
            ImGui::Separator();

            ImGui::InputText("Project Name", &m_newProjectName);

            ImGui::InputText("Project Path", &m_newProjectPath);
            ImGui::SameLine();
            if (ImGui::Button(ICON_MD_MORE_HORIZ "##Browse")) {
                ImGuiFileDialog::Instance()->OpenModal("ProjectSelectStage::NewProject", "Select Project Directory", nullptr, ".");
            }

            ImGui::Checkbox("Create Project Folder", &m_createModFolder);

            if (ImGui::Button("Create"))
            {
                fs::path projectPath = fs::u8path(m_newProjectPath);

                if (m_createModFolder)
                    projectPath /= m_newProjectName;

                fs::create_directories(projectPath);
                initiateLoadOrCreateProject(projectPath, false);
                m_newProjectOpen = false;
            }
            ImGui::SameLine();

            if (ImGui::Button("Cancel##NewProject"))
                m_newProjectOpen = false;
        }
        ImGui::End();

        if (ImGuiFileDialog::Instance()->Display("ProjectSelectStage::NewProject"))
        {
            if (ImGuiFileDialog::Instance()->IsOk())
                m_newProjectPath = ImGuiFileDialog::Instance()->GetCurrentPath();

            ImGuiFileDialog::Instance()->Close();
        }
    }
}

void ProjectSelectStage::initiateLoadOrCreateProject(const fs::path& path, bool loadExisting)
{
    if (!path.is_absolute())
        m_loadProjectPath = fs::absolute(path);
    else
        m_loadProjectPath = path;

    if (m_loadProjectPath.filename() == IProject::PROJECT_FILE_NAME)
        m_loadProjectPath = m_loadProjectPath.parent_path();

    try
    {
        if (!loadExisting)
        {
            // Create the directory for the project
            fs::create_directory(m_loadProjectPath);

            // Create project file
            fs::path filePath = m_loadProjectPath / IProject::PROJECT_FILE_NAME;
            pugi::xml_document doc;
            if (!doc.save_file(filePath.c_str()))
                throw std::runtime_error("Failed to create project file.");
        }

        ProjectHistory::AddToHistory(m_loadProjectPath);
        Preditor::Get()->GetPahts().SetProjectDirPath(m_loadProjectPath);
        SetStageFinished(std::make_unique<LoadGameStage>(nullptr));
    }
    catch (const std::exception& e)
    {
        m_ErrorText = e.what();
        m_ShowError = true;
    }
}
