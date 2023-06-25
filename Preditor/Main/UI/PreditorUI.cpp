#include <Prey/CrySystem/Profiling.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/Assets/IAssetSystem.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/IChairloaderToolsPreditor.h>
#include "PreditorUI.h"
#include "SimControlWindow.h"
#include "FileBrowser.h"

Main::PreditorUI::PreditorUI()
{
    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(gPreditor->pEngine->GetIChairToPreditor());

    m_pViewportWindow = IViewportWindow::CreateInstance();
    gPreditor->pViewportWindow = m_pViewportWindow.get();

    m_pSimControlWindow = WindowManager::Get().Create<SimControlWindow>();

    m_pProjectBrowser = WindowManager::Get().Create<FileBrowser>();
    m_pProjectBrowser->SetTitle("Project Browser");
    m_pProjectBrowser->SetPersistentID("ProjectBrowser");
    m_pProjectBrowser->SetRootPath(gPreditor->pPaths->GetProjectDirPath().u8string());

    m_pAssetBrowser = WindowManager::Get().Create<FileBrowser>();
    m_pAssetBrowser->SetTitle("Asset Browser");
    m_pAssetBrowser->SetPersistentID("AssetBrowser");
}

Main::PreditorUI::~PreditorUI()
{
}

void Main::PreditorUI::ShowUI()
{
    CRY_PROFILE_MARKER("PreditorUI::ShowUI");
    ShowMainMenuBar();

    WindowManager::Get().Update();
    m_pChairTools->Update();

    if (m_bImGuiDemo)
        ImGui::ShowDemoWindow();
}

void Main::PreditorUI::ShowMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Merge Assets"))
                gPreditor->pAssetSystem->RequestMerging();

            ImGui::Separator();

            if (ImGui::MenuItem("Quit"))
                gEnv->pSystem->Quit();
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Simulation"))
        {
            m_pSimControlWindow->ShowMenu();
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Window"))
        {
            m_pChairTools->ShowWindowMenu();
            ImGui::MenuItem("ImGui Demo", nullptr, &m_bImGuiDemo);
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}
