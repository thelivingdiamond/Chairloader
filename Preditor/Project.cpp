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
    m_pFlowgraphEditor = std::make_unique<FlowgraphEditor>();
}

void Project::Update() {

}

void Project::ShowUI(bool *bOpen) {
    ImGui::PushFont(AppImGui::getPrettyFont());
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    if(ImGui::Begin(WINDOW_TITLE.c_str(), bOpen, WINDOW_FLAGS)){
        drawToolbar();
        ImGui::Text("Project Path: %s", m_ProjectPath.string().c_str());
    }
    ImGui::End();
    ImGui::PopFont();

    if(m_pFlowgraphEditor) {
        if(m_pFlowgraphEditor->isShown() && !m_pFlowgraphEditor->isInitialized()){
            m_pFlowgraphEditor->Init();
        }
        m_pFlowgraphEditor->ShowUI();
    }
}

void Project::drawToolbar() {
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(8, 8));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);
    if(ImGui::BeginChild("Toolbar", ImVec2(ImGui::GetWindowWidth(), ImGui::GetFrameHeightWithSpacing()), false)){
        if(ImGui::Button(ICON_MD_SHARE "##FLOWGRAPHEDITOR")){
            m_pFlowgraphEditor->setShown(!m_pFlowgraphEditor->isShown());
        }
        ImGui::EndChild();
    }
    ImGui::PopStyleVar(2);
}
