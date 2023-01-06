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

    WindowManager::Get().Update();
    m_pChairTools->Update();

    if (m_pFlowgraphEditor) {
        if (m_pFlowgraphEditor->isShown() && !m_pFlowgraphEditor->isInitialized()) {
            m_pFlowgraphEditor->Init();
        }
        m_pFlowgraphEditor->ShowUI();
    }

    ImGui::ShowDemoWindow();
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

            bool flowEditorVisible = m_pFlowgraphEditor->isShown();
            if (ImGui::MenuItem(ICON_MD_SHARE " FlowGraph Editor", nullptr, &flowEditorVisible)) {
                m_pFlowgraphEditor->setShown(flowEditorVisible);
            }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}
