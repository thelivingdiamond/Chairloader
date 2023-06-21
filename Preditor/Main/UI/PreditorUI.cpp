#include <Prey/CrySystem/Profiling.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include "PreditorUI.h"
#include "SimControlWindow.h"

Main::PreditorUI::PreditorUI()
{
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
}

void Main::PreditorUI::ShowMainMenuBar()
{

}
