#pragma once
#include <WindowManager/IManagedWindow.h>

struct ImGuiDockNode;

namespace FGE
{

class PreditorFlowgraph;
class FlowgraphTab;

//! Main Flowgraph Editor window.
//! Consists of multiple ImGui windows with explicit docking.
//! Uses IManagedWindow instead of ManagedWindow to draw multiple windows at the same time.
class FlowgraphWindow : public IManagedWindow
{
public:
    FlowgraphWindow(PreditorFlowgraph* pFGE);
    ~FlowgraphWindow();

    //! Sets whether the window is being displayed.
    void SetVisible(bool state);
    bool IsVisible() const { return m_bVisible; }

    //! Sets the currently active tab.
    void SetCurrentTab(FlowgraphTab* pCurrentTab) { m_pCurrentTab = pCurrentTab; }

    //! Opens the node info popup.
    void OpenNodeInfoPopup() { m_bOpenNodeInfoPopup = true; }

    // IManagedWindow
    virtual bool UpdateWindow() override;

private:
    bool m_bVisible = false;
    bool m_bOpenNodeInfoPopup = false;
    PreditorFlowgraph* m_pFGE = nullptr;
    ImGuiID m_DockSpaceId = 0;

    std::vector<std::unique_ptr<FlowgraphTab>> m_Tabs;
    FlowgraphTab* m_pCurrentTab = nullptr;

    void ShowMainWindow();
    void ShowMenuBar();

    void ShowNodeList();
    void ShowNodeProperties();
    void ShowEditorTabs();
};

} // namespace FGE
