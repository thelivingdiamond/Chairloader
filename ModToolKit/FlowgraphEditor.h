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


class IFlowNode;

class FlowgraphEditor {
public:
    FlowgraphEditor();
    ~FlowgraphEditor();
    void Draw(bool *bDraw);
    void Update();
    static FlowgraphEditor* getInstance(){ return m_pFlowgraphEditorInstance;}

    std::vector<PrototypeNode>& getPrototypes(){ return m_PrototypeNodes; }
private:
//    std::vector<_smart_ptr<IFlowNode>> m_FlowNodes;
    std::vector<PrototypeNode> m_PrototypeNodes;
    std::vector<FlowGraph> m_FlowGraphs;
    FlowGraph* p_CurrentFlowGraph = nullptr;

    // XML Load and save
    void loadXMLFlowgraph(fs::path path);
    static inline FlowgraphEditor* m_pFlowgraphEditorInstance = nullptr;
};


#endif //CHAIRLOADER_FLOWGRAPHEDITOR_H
