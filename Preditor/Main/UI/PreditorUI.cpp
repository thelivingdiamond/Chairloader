#include <Prey/CrySystem/Profiling.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/IChairloaderToolsPreditor.h>
#include "PreditorUI.h"
#include "SimControlWindow.h"

Main::PreditorUI::PreditorUI()
{
    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(gPreditor->pEngine->GetIChairToPreditor());

    m_pViewportWindow = IViewportWindow::CreateInstance();
    gPreditor->pViewportWindow = m_pViewportWindow.get();

    m_pSimControlWindow = WindowManager::Get().Create<SimControlWindow>();
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
}

void Main::PreditorUI::ShowMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
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
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}
