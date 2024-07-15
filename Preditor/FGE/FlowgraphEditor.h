//
// Created by theli on 9/25/2022.
//
#pragma once
#include <future>
#include <pugixml.hpp>
#include <Preditor/FGE/IFlowgraphEditor.h>
#include <WindowManager/ManagedWindow.h>
#include "ImNodes/imnodes.h"

#include "Flowgraph.h"

class ImGuiDockNode;
class IFlowNode;
struct Node;

namespace FGE
{
class PreditorFlowgraph;
}

class FlowgraphEditor : public ManagedWindow, public IFlowgraphEditor
{
public:
    FlowgraphEditor(FGE::PreditorFlowgraph* pMainFG);
    ~FlowgraphEditor() override;

    ImGuiDockNode* getDockNode() { return m_DockNode; }
    void setShowNodePopup(bool bShow) { m_bShowNodePopup = bShow; }

    // IFlowgraphEditor
    virtual ManagedWindow* GetWindow() override { return this; }

protected:
    // ManagedWindow
    virtual void ShowContents() override;

private:
    FGE::PreditorFlowgraph* m_pMainFG = nullptr;
    bool m_IsFirstShow = true; //!< Whether the window is appearing for the first time.
    std::vector<FlowGraph*> m_FlowGraphs;
    FlowGraph* p_CurrentFlowGraph = nullptr;

    // XML Load and save
    static inline bool m_bShowNodePopup = false;
    void DrawNodeEditorTabs();
    void DrawNodeGraphList();
    void DrawNodeProperties();
    static const inline std::string m_DockspaceName = "FlowgraphEditorDockspace";
    ImGuiDockNode* m_DockNode;
};
