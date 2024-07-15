#pragma once

struct ImGuiDockNode;

namespace FGE
{

struct Flowgraph;
class FlowgraphWindow;

class FlowgraphTab
{
public:
    //! Shows the tab window.
    void ShowTab(ImGuiDockNode* pDockNode);

private:
    FlowgraphWindow* m_pWindow = nullptr;
    std::unique_ptr<Flowgraph> m_pFG;
    std::string m_TabName;
    bool m_bFirstDraw = true;
    bool m_bShowNodeList = true;
    bool m_bResetPan = false;

    //! Shows the window contents.
    void ShowContents();

    void ShowNodeList();
    void ShowToolbar();
    void ShowGraph();
};

} // namespace FGE
