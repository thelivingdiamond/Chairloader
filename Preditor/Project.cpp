//
// Created by theli on 10/28/2022.
//

#include "Project.h"
#include "ProjectManager.h"
#include "App/AppImGui.h"

void Project::Start() {
    if(!ProjectManager::Get()) return;
    m_ProjectPath = ProjectManager::Get()->getProjectDirectory();
    if(m_ProjectPath.empty()) return;
    if(!fs::exists(m_ProjectPath)) return;
    if(!fs::is_directory(m_ProjectPath)) return;
}

void Project::Update() {

}

void Project::ShowUI(bool *bOpen) {
    ImGui::PushFont(AppImGui::getPrettyFont());
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    if(ImGui::Begin(WINDOW_TITLE.c_str(), bOpen, WINDOW_FLAGS)){
        ImGui::Text("Project Path: %s", m_ProjectPath.string().c_str());
    }
    ImGui::End();
    ImGui::PopFont();
}
