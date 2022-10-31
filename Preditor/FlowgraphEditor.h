//
// Created by theli on 9/25/2022.
//

#ifndef CHAIRLOADER_FLOWGRAPHEDITOR_H
#define CHAIRLOADER_FLOWGRAPHEDITOR_H

struct Node;
#include <pugixml.hpp>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <filesystem>
#include "ImGui/imgui.h"
#include "ImNodes/imnodes.h"

#include "Flowgraph/Flowgraph.h"
#include "App/AppModule.h"

class ImGuiDockNode;
class IFlowNode;

class FlowgraphEditor : public AppModule{
public:
    const static inline float STYLE_SCALE = 1.5f;
    FlowgraphEditor();
    ~FlowgraphEditor() override;

    void Init() override;
    void ShowUI() override;
    void Update() override;

    static FlowgraphEditor* getInstance(){ return m_pFlowgraphEditorInstance;}
    void setCurrentFlowgraph(FlowGraph* flowgraph){ p_CurrentFlowGraph = flowgraph;}
    static void setShowNodePopup(bool bShow){ m_bShowNodePopup = bShow;}
    static std::string getDockspaceName() { return m_DockspaceName; }
    std::map<PrototypeNode::NodeClass,  std::shared_ptr<PrototypeNode>>& getPrototypes(){ return m_PrototypeNodes; }
    void addUnknownPrototype(PrototypeNode::NodeClass nodeClass);
    void addPinToPrototype(PrototypeNode::NodeClass nodeClass, PrototypePin pin);
    ImGuiDockNode* getDockNode(){ return m_DockNode; }
    void removeFlowgraph(FlowGraph* flowgraph);
    bool ShowEditor(bool m_bShow){ m_bDraw = m_bShow; return m_bDraw; }
private:
    bool m_bDraw = true;
//    std::vector<_smart_ptr<IFlowNode>> m_FlowNodes;
    std::map<PrototypeNode::NodeClass,  std::shared_ptr<PrototypeNode>> m_PrototypeNodes;
    std::vector<std::shared_ptr<FlowGraphXMLFile>> filesWithgraphNodes;
    std::vector<FlowGraph*> m_FlowGraphs;
    FlowGraph* p_CurrentFlowGraph = nullptr;
    void searchXmlDocuments(fs::path path);
    bool findGraphNodes(pugi::xml_node &node);

    // XML Load and save
    static inline FlowgraphEditor* m_pFlowgraphEditorInstance = nullptr;
    static inline bool m_bShowNodePopup = false;
    void DrawNodeEditorTabs();
    void DrawNodeGraphList();
    void DrawNodeProperties();
    static const inline std::string m_DockspaceName = "FlowgraphEditorDockspace";
    ImGuiDockNode* m_DockNode;
};


#endif //CHAIRLOADER_FLOWGRAPHEDITOR_H
