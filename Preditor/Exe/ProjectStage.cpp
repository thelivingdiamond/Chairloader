#include <Prey/CrySystem/Profiling.h>
#include <Prey/CryGame/Game.h>
#include <Prey/CryGame/IGameFramework.h>
#include <WindowManager/WindowManager.h>
#include <App/AppImGui.h>
#include <Preditor/Project/ProjectManager.h>
#include <Preditor/IChairloaderToolsPreditor.h>
#include <Preditor/IPreditorEngine.h>
#include "ProjectStage.h"
#include "GameViewport.h"
#include "EntityHierarchyWindow.h"
#include "InspectorWindow.h"

ProjectStage::ProjectStage()
{
    gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this);
}

ProjectStage::~ProjectStage()
{
    if (gEnv && gEnv->pSystem)
        gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);
}

void ProjectStage::Start() {
    m_pFlowgraphEditor = std::make_unique<FlowgraphEditor>();
    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(IPreditorEngine::Get()->GetIChairToPreditor());
    m_pGameViewport = WindowManager::Get().Create<GameViewport>();
    m_pEntHierWindow = WindowManager::Get().Create<EntityHierarchyWindow>();
    m_pInspectorWindow = WindowManager::Get().Create<InspectorWindow>();
}

void ProjectStage::Update() {
    ProjectManager::GetUserSettings()->Update();
}

void ProjectStage::ShowUI(bool* bOpen) {
    CRY_PROFILE_MARKER("ProjectStage::ShowUI");
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

void ProjectStage::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
    if (event == ESYSTEM_EVENT_ACTIVATE)
    {
        if (wparam)
        {
            // Main window now active
            m_pChairTools->CheckModulesForChanges();
        }
    }
}

void ProjectStage::DrawMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Reload level", nullptr, nullptr, g_pGame->GetIGameFramework()->IsGameStarted()))
                m_pChairTools->ReloadLevel();

            if (ImGui::MenuItem("Reload mods"))
                m_pChairTools->ReloadMods();
            ImGui::Separator();

            if (ImGui::MenuItem("Quit"))
                gEnv->pSystem->Quit();
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window"))
        {
            ShowWindowMenuItem("Entities", m_pEntHierWindow.get());
            ShowWindowMenuItem("Inspector", m_pInspectorWindow.get());
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

void ProjectStage::ShowWindowMenuItem(const char* label, ManagedWindow* window)
{
    bool isVisible = window->IsVisible();
    if (ImGui::MenuItem(label, nullptr, &isVisible))
        window->SetVisible(isVisible);
}
