#include <Prey/CrySystem/Profiling.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/Assets/IAssetSystem.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include <Preditor/EditTools/IEditToolManager.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/IChairloaderToolsPreditor.h>
#include "UI/PreditorUI.h"
#include "UI/FileBrowser.h"
#include "UI/HierarchyWindow.h"
#include "UI/InspectorWindow.h"
#include "UI/SelectionWindow.h"
#include "UI/SimControlWindow.h"
#include "UI/ArkLibraryExplorer.h"

namespace
{

//! Shows a menu item that toggles the window visibility.
//! @param	label		Item label.
//! @param	shortcut	Keyboard shortcut.
//! @returns true if the state has changed.
template<typename T>
inline bool ShowToggleMenuItem(std::weak_ptr<T>& pWindowWeak, const char* label, const char* shortcut = nullptr)
{
    std::shared_ptr<T> pWindow = pWindowWeak.lock();
    bool isVisible = pWindow ? pWindow->IsVisible() : false;

    if (ImGui::MenuItem(label, shortcut, &isVisible))
    {
        if (!pWindow)
        {
            pWindow = WindowManager::Get().Create<T>();
            pWindowWeak = pWindow;
        }

        pWindow->SetVisible(isVisible);
        return true;
    }
    else
    {
        return false;
    }
}

} // namespace

Main::PreditorUI::PreditorUI()
{
    m_pChairTools = IChairloaderToolsPreditor::CreateInstance(gPreditor->pEngine->GetIChairToPreditor());

    m_pViewportWindow = IViewportWindow::CreateInstance();
    gPreditor->pViewportWindow = m_pViewportWindow.get();

    m_pSimControlWindow = WindowManager::Get().Create<SimControlWindow>();
    m_pToolSelectionWindow = IEditToolManager::CreateToolSelectionWindow();

    m_pProjectBrowser = WindowManager::Get().Create<FileBrowser>();
    m_pProjectBrowser->SetTitle("Project Browser");
    m_pProjectBrowser->SetPersistentID("ProjectBrowser");
    m_pProjectBrowser->SetRootPath(gPreditor->pPaths->GetProjectDirPath().u8string());

    m_pAssetBrowser = WindowManager::Get().Create<FileBrowser>();
    m_pAssetBrowser->SetTitle("Asset Browser");
    m_pAssetBrowser->SetPersistentID("AssetBrowser");

    m_pInspectorWindow = WindowManager::Get().Create<InspectorWindow>();
    m_pHierarchyWindow = WindowManager::Get().Create<HierarchyWindow>();
    m_pSelectionWindow = WindowManager::Get().Create<SelectionWindow>();
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

#if 0
    if (ImGui::Begin("Timer Debug"))
    {
        ITimer* pTimer = gEnv->pTimer;

        ImGui::Text("GetAsyncTime: %.3f", pTimer->GetAsyncTime().GetSeconds());
        ImGui::Text("GetAsyncCurTime: %.3f", pTimer->GetAsyncCurTime());
        ImGui::Text("GetRealFrameTime: %.3f", pTimer->GetRealFrameTime());
        ImGui::Text("IsTimerEnabled: %d", pTimer->IsTimerEnabled());
        ImGui::Text("GetFrameRate: %.3f", pTimer->GetFrameRate());

        for (int i = 0; i < ITimer::ETIMER_LAST; i++)
        {
            ITimer::ETimer timer = (ITimer::ETimer)i;
            ImGui::Text("TIMER %d", i);
            ImGui::Text("GetCurrTime: %.3f", pTimer->GetCurrTime(timer));
            ImGui::Text("GetFrameStartTime: %.3f", pTimer->GetFrameStartTime(timer).GetSeconds());
            ImGui::Text("GetFrameTime: %.3f", pTimer->GetFrameTime(timer));
            ImGui::Text("GetTimeScale: %.3f", pTimer->GetTimeScale(timer));
            ImGui::Text("IsTimerPaused: %d", pTimer->IsTimerPaused(timer));
        }
    }
    ImGui::End();
#endif
}

void Main::PreditorUI::ShowMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            gPreditor->pAssetSystem->ShowMainMenu();
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
            ImGui::Separator();

            m_pToolSelectionWindow->ShowToggleMenuItem("Tool Selection");
            m_pSelectionWindow->ShowToggleMenuItem("Object Selection List");
            m_pInspectorWindow->ShowToggleMenuItem("Inspector");
            m_pHierarchyWindow->ShowToggleMenuItem("Hierarchy");
            ImGui::Separator();

            m_pProjectBrowser->ShowToggleMenuItem("Project File Browser");
            m_pAssetBrowser->ShowToggleMenuItem("Game File Browser");
            ShowToggleMenuItem(m_pArkLibraryExplorer, "Ark Library Explorer");

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}
