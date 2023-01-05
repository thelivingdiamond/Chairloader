#include <WindowManager/WindowManager.h>
#include <App/AppImGui.h>
#include <Preditor/Project/ProjectManager.h>
#include <Preditor/IChairloaderToolsPreditor.h>
#include <Preditor/IPreditorEngine.h>
#include "ProjectStage.h"
#include "GameViewport.h"

ProjectStage::ProjectStage()
{
}

ProjectStage::~ProjectStage()
{
}

void ProjectStage::Start() {
    m_pFlowgraphEditor = std::make_unique<FlowgraphEditor>();
    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(IPreditorEngine::Get()->GetIChairToPreditor());
    m_pGameViewport = WindowManager::Get().Create<GameViewport>();
}

void ProjectStage::Update() {
    ProjectManager::GetUserSettings()->Update();
}

void ProjectStage::ShowUI(bool* bOpen) {
    DrawMainMenuBar();

    m_pChairTools->Update();

    //ImGui::PushFont(AppImGui::getPrettyFont());
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

void ProjectStage::DrawMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Quit"))
                gEnv->pSystem->Quit();
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window"))
        {
            m_pChairTools->ShowWindowMenu();
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}
