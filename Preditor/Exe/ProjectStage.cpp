#include <WindowManager/WindowManager.h>
#include <App/AppImGui.h>
#include "ProjectStage.h"
#include "Project.h"
#include "ProjectManager.h"
#include "GameViewport.h"

void ProjectStage::Start() {
    m_pFlowgraphEditor = std::make_unique<FlowgraphEditor>();
    m_pGameViewport = WindowManager::Get().Create<GameViewport>();
}

void ProjectStage::Update() {

}

void ProjectStage::ShowUI(bool* bOpen) {
    //ImGui::PushFont(AppImGui::getPrettyFont());
    ImGui::SetNextWindowSize(WINDOW_SIZE, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    if (ImGui::Begin(WINDOW_TITLE.c_str(), bOpen, WINDOW_FLAGS)) {
        DrawToolbar();
        Project* pProject = ProjectManager::GetProject();
        ImGui::Text("Project Name: %s", pProject->GetName().c_str());
        ImGui::Text("Project Path: %s", pProject->GetPath().u8string().c_str());
    }
    ImGui::End();
    //ImGui::PopFont();

    if (m_pFlowgraphEditor) {
        if (m_pFlowgraphEditor->isShown() && !m_pFlowgraphEditor->isInitialized()) {
            m_pFlowgraphEditor->Init();
        }
        m_pFlowgraphEditor->ShowUI();
    }

    ImGui::ShowDemoWindow();
}

void ProjectStage::DrawToolbar() {
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(8, 8));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2.0f);
    if (ImGui::BeginChild("Toolbar", ImVec2(ImGui::GetWindowWidth(), ImGui::GetFrameHeightWithSpacing()), false)) {
        if (ImGui::Button(ICON_MD_SHARE "##FLOWGRAPHEDITOR")) {
            m_pFlowgraphEditor->setShown(!m_pFlowgraphEditor->isShown());
        }
        ImGui::EndChild();
    }
    ImGui::PopStyleVar(2);
}
