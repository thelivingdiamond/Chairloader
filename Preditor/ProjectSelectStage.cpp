//
// Created by theli on 10/28/2022.
//

#include "ProjectSelectStage.h"
#include "ImGui/imgui.h"
#include "App/AppImGui.h"
#include "Preditor.h"
#include "ImFileDialog/ImFileDialog.h"
#include "ImGui/imgui_stdlib.h"

void ProjectSelectStage::Update() {
    if(m_bLoadProject){
        ProjectManager::Get()->setProjectDirectory(m_loadProjectPath);
        SetStageFinished();
    }
}

void ProjectSelectStage::ShowUI(bool *bOpen) {
    if(Preditor::Get()->GetConfig().isShown()) return;
    ImGui::PushFont(AppImGui::getPrettyFont());
    bool bShow = true;
    if(!m_newProjectOpen) {
        ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_Once);
        if (ImGui::Begin(WINDOW_TITLE.c_str(), &bShow, WINDOW_FLAGS)) {
            ImGui::Text("Previous Projects");
            if (ImGui::BeginTable("Previous Projects", 1, ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_RowBg)) {
                ImGui::TableSetupColumn("Project Path");
                for (auto &project: ProjectManager::Get()->getPreviousProjects()) {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    if(ImGui::Selectable(project.u8string().c_str())){
                        initiateLoadProject(project);
                    }
                }
                if (ProjectManager::Get()->getPreviousProjects().empty()) {
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    ImGui::Text("No previous projects found");
                }
                ImGui::EndTable();
            }
            // snap the buttons to the bottom of the window
            ImGui::SetCursorPosY(
                    ImGui::GetWindowHeight() - ImGui::GetFrameHeight() - ImGui::GetStyle().ItemSpacing.y * 2);
            if (ImGui::Button("New Project")) {
                m_newProjectOpen = true;
            }
            ImGui::SameLine();
            if (ImGui::Button("Open Project")) {
                ifd::FileDialog::Instance().Open("ProjectSelectStage::OpenProject", "Select Project Directory", "", ".");
            }
            ImGui::SameLine();
            if (ImGui::Button("Quit")) {
                Preditor::Get()->QuitApp();
            }
            if(ifd::FileDialog::Instance().IsDone("ProjectSelectStage::OpenProject")){
                if(ifd::FileDialog::Instance().HasResult()){
                    initiateLoadProject(ifd::FileDialog::Instance().GetResult());
                }
                ifd::FileDialog::Instance().Close();
            }
        }
        ImGui::End();
    }

    if(m_newProjectOpen) {
        if (ImGui::Begin("Create New Project", &m_newProjectOpen, ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::Text("New Project");
            ImGui::Separator();
            static std::string m_projectPath;
            m_projectPath = m_newProjectPath.u8string();
            ImGui::InputText("Project Name", &m_newProjectName);
            if (ImGui::InputText("Project Path", &m_projectPath)) {
                m_newProjectPath = m_projectPath;
            }
            ImGui::SameLine();
            if (ImGui::Button(ICON_MD_MORE_HORIZ "##Browse")) {
                ifd::FileDialog::Instance().Open("ProjectSelectStage::NewProject", "Select Project Directory", "", ".");
            }
            ImGui::Checkbox("Create Project Folder", &m_createModFolder);
            if (ImGui::Button("Create")) {
                if(m_createModFolder){
                    m_newProjectPath /= m_newProjectName;
                }
                fs::create_directories(m_newProjectPath);
                initiateLoadProject(m_newProjectPath);
                m_newProjectOpen = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel##NewProject")) {
                m_newProjectOpen = false;
            }
        }
        ImGui::End();
        if (ifd::FileDialog::Instance().IsDone("ProjectSelectStage::NewProject")) {
            if (ifd::FileDialog::Instance().HasResult()) {
                m_newProjectPath = ifd::FileDialog::Instance().GetResult();
            }
            ifd::FileDialog::Instance().Close();
        }
    }

    ImGui::PopFont();
    if(!bShow) {
        *bOpen = false;
    }
}

void ProjectSelectStage::Start() {

}

void ProjectSelectStage::initiateLoadProject(const fs::path &path) {
    if(!path.is_absolute()){
        m_loadProjectPath = fs::absolute(path);
    } else {
        m_loadProjectPath = path;
    }
    m_bLoadProject = true;
}
