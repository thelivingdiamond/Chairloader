//
// Created by theli on 9/25/2022.
//
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include "FlowgraphEditor.h"
#include <Prey/CryAction/Ark/IArkGlobalActionManager.h>
#include <Prey/CryAction/flowsystem/Nodes/FlowBaseNode.h>
#include <Prey/CryAction/flowsystem/flowsystem.h>
#include "ImGui/imgui_stdlib.h"

class CGameStartup;

FlowgraphEditor::FlowgraphEditor() {
    ImNodes::CreateContext();
    auto flowSystem = static_cast<CFlowSystem*>(gEnv->pFlowSystem);

    for(auto & typeEntry: flowSystem->m_typeNameToIdMap) {
        auto info = new IFlowNode::SActivationInfo();
        //TODO: Fix timer nodes
        if(std::string(typeEntry.first.c_str()) == ("Entity:TacticalScan") ||
        std::string(typeEntry.first.c_str()) == ("Ark:PlayerMimicEvent") ||
        std::string(typeEntry.first.c_str()) == ("Game:Start") ||
        std::string(typeEntry.first.c_str()) == ("Time:Timer")) {
            continue;
        }
        PrototypeNode newNode;
        newNode.Class = typeEntry.first.c_str();
        auto node = flowSystem->CreateNodeOfType(info, typeEntry.second);
        SFlowNodeConfig nodeConfig{};
        if(node.get() == nullptr) {
            continue;
        }
        node->GetConfiguration(nodeConfig);
        if(nodeConfig.sDescription != nullptr)
            newNode.Description = nodeConfig.sDescription;
        int i = 0;
        auto inputPort = &nodeConfig.pInputPorts[i];
        if(inputPort != nullptr) {
            while (inputPort->name != nullptr) {
                PrototypePin newPin;
                if(inputPort->name != nullptr)
                    newPin.Name = inputPort->name;
                if(inputPort->humanName != nullptr)
                    newPin.HumanName = inputPort->humanName;
                if(inputPort->description != nullptr)
                    newPin.Description = inputPort->description;
                newPin.Kind = PinKind::Input;
                if(inputPort->sUIConfig != nullptr)
                    newPin.sUIConfig = inputPort->sUIConfig;
                newNode.ProtoInputs.emplace_back(newPin);
                inputPort = &nodeConfig.pInputPorts[++i];
            }
        }
        i = 0;
        auto outputPort = &nodeConfig.pOutputPorts[i];
        if(outputPort != nullptr) {
            while (outputPort->name != nullptr) {
                PrototypePin newPin;
                if(outputPort->name != nullptr)
                    newPin.Name = outputPort->name;
                if(outputPort->humanName != nullptr)
                    newPin.HumanName = outputPort->humanName;
                if(outputPort->description != nullptr)
                    newPin.Description = outputPort->description;
                newPin.Kind = PinKind::Output;
                newPin.Type = outputPort->type;
                newNode.ProtoOutputs.emplace_back(newPin);
                outputPort = &nodeConfig.pOutputPorts[++i];
            }
        }
        m_PrototypeNodes.emplace_back(newNode);
        node.ReleaseOwnership();
//        node->Release();
        delete info;
    }

}

void FlowgraphEditor::Draw(bool *bDraw) {
//    ImGui::ShowDemoWindow(bDraw);
    gEnv->pFlowSystem;
    ImGui::SetNextWindowSize(ImVec2(800,500), ImGuiCond_FirstUseEver);
    if(ImGui::Begin("Flowgraph Editor", bDraw, ImGuiWindowFlags_MenuBar)) {
        if(ImGui::BeginMenuBar()){
            if(ImGui::BeginMenu("File")){
                if(ImGui::MenuItem("Load File")){

                }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        std::vector<IArkGlobalAction const *> actions;
        ImGui::Text("pGame: %p", gEnv->pGame);
        ImGui::Text("pSystem: %p", gEnv->pSystem);
        static CGameStartup* pGameStartup;
        if(ImGui::Button("FUCK THINGS UP")){

        }
        auto pSystem = (CSystem*)gEnv->pSystem;
        if(gEnv->pFlowSystem != nullptr) {
            actions = gEnv->pFlowSystem->GetIArkGlobalActionManager().GetActions();
        } else {
            ImGui::Text("FlowSystem not found");
        }
        for(auto action : actions){
            ImGui::Text("%s", action->GetFileName().c_str());

        }
        CAutoRegFlowNodeBase* nodePtr = *CAutoRegFlowNodeBase::m_pFirst.Get();
        if(ImGui::BeginTabBar("Editor Tabs")) {
            if(ImGui::BeginTabItem("Auto Reg Flow Node List")) {
                int i = 0;
                if (ImGui::BeginTable("Nodes", 2, ImGuiTableFlags_ScrollY,
                                      ImVec2(0, ImGui::GetContentRegionAvail().y * 0.8f))) {
                    while (nodePtr != nullptr) {
                        i++;
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("%p", nodePtr);
                        ImGui::TableNextColumn();
                        if(ImGui::Selectable(nodePtr->m_sClassName)){
//                            auto info = new IFlowNode::SActivationInfo();
//                            auto node = nodePtr->Create(info);
//                            m_FlowNodes.emplace_back(node);
                        }
                        nodePtr = nodePtr->m_pNext;
                    }
                    ImGui::EndTable();
                }
                ImGui::Text("Node Count: %d", i);
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem("Prototype Node List")) {
                if (ImGui::BeginTable("Nodes", 2, ImGuiTableFlags_ScrollY,
                                      ImVec2(0, ImGui::GetContentRegionAvail().y * 0.8f))) {
                    for(auto &node : m_PrototypeNodes){
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        if(ImGui::Selectable(node.Class.c_str())){
//                            auto info = new IFlowNode::SActivationInfo();
//                            auto node = nodePtr->Create(info);
//                            m_FlowNodes.emplace_back(node);
                        }
                        ImGui::TableNextColumn();
                        ImGui::TextWrapped("%s", node.Description.c_str());
                    }
                    ImGui::EndTable();
                }
                ImGui::Text("Node Count: %u", m_PrototypeNodes.size());
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem("Flow Graph")) {
                if(ImGui::BeginChild("Flow Graph Canvas", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f,0), true)) {
                    static FlowGraph testGraph;
                    p_CurrentFlowGraph = &testGraph;
                    static Node node("Test Node", m_PrototypeNodes[20], ImVec2(200, 200));
                    static Node node2("Test Node2", m_PrototypeNodes[21], ImVec2(200, 200));
                    static bool nodesAdded;
                    if(!nodesAdded) {
                        node.initializePins();
                        node2.initializePins();
                        testGraph.m_Nodes.emplace_back(node);
                        testGraph.m_Nodes.emplace_back(node2);
                        nodesAdded = true;
                    }
                    testGraph.drawFlowGraph();

                }
                ImGui::EndChild();
                ImGui::SameLine();
                if(ImGui::BeginChild("Prototype Node Selection List", ImVec2(0,0), true)) {
                    static std::string path;
                    ImGui::InputText("Path", &path);
                    if(ImGui::Button("Load XML File")){
                        loadXMLFlowgraph(path);
                    }
                    static ImGuiTextFilter filter;
                    filter.Draw();
                    if (ImGui::BeginTable("Nodes", 1, ImGuiTableFlags_ScrollY,
                                          ImVec2(0, ImGui::GetContentRegionAvail().y * 0.8f))) {
                        for(auto &ProtoNode : m_PrototypeNodes){
                            if(filter.PassFilter(ProtoNode.Class.c_str())) {
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                if (ImGui::Selectable(ProtoNode.Class.c_str())) {
                                    if(p_CurrentFlowGraph != nullptr){
                                        p_CurrentFlowGraph->addNodeFromPrototype(ProtoNode);
                                    }
                                }
                            }
                        }
                        ImGui::EndTable();
                    }
                    if(ImGui::Button("Clear Nodes")){
//                        m_Nodes.clear();
//                        m_Edges.clear();
                    }

                }
                ImGui::EndChild();
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem("Type name to id map")){
                auto flowSystem = static_cast<CFlowSystem*>(gEnv->pFlowSystem);
                if(ImGui::BeginTable("Nodes", 2, ImGuiTableFlags_ScrollY, ImVec2(0, ImGui::GetContentRegionAvail().y * 0.8f))) {
                    for(auto & entry : flowSystem->m_typeNameToIdMap){
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            ImGui::Text("%s", entry.first.c_str());
                            ImGui::TableNextColumn();
                            ImGui::Text("%d", entry.second);
                    }
                    ImGui::EndTable();
                }
                ImGui::Text("Node Count: %llu", flowSystem->m_typeNameToIdMap.size());
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
//        static bool registerFirstNode = true;
//        nodePtr = *CAutoRegFlowNodeBase::m_pFirst.Get();
//        auto baseNodePtr = (CAutoRegFlowNode<bool>*)nodePtr;
//        if(registerFirstNode){
////            REGISTER_FLOW_NODE(nodePtr, Flow);
//            registerFirstNode = false;
//        }
//        ImGui::Text("BaseNode: %p", baseNodePtr);
//        ImGui::Text("BaseNode->instance: %p", baseNodePtr->m_pInstance.get());
    }
//    ImGui::Text("%p", CAutoRegFlowNodeBase::m_pFirst.Get());
    ImGui::End();
}

void FlowgraphEditor::Update() {

}

void FlowgraphEditor::drawNode(Node& node) {

}

void FlowgraphEditor::drawEdge(Edge &edge) {

}

void FlowgraphEditor::handleEdges() {


}


void FlowgraphEditor::loadXMLFlowgraph(fs::path path) {
    if(!fs::exists(path)){
        return;
    }
//    m_Nodes.clear();
//    m_Edges.clear();
    uniqueID = 1 << 16;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(path.string().c_str());
    if(!result){
        return;
    }
    pugi::xml_node FlowGraph = doc.first_child();
    if(!FlowGraph){
        return;
    }
    for(auto & node: FlowGraph.child("Nodes")){
        std::string nodeClass = node.attribute("Class").as_string();
        uint64_t nodeID = node.attribute("Id").as_int();
        std::string position = node.attribute("pos").as_string();
        // position is in format x,y,z
        // we only want x and y
        ImVec2 nodePos = {0,0};
        PrototypeNode* prototype = nullptr;
        for(auto &proto : m_PrototypeNodes){
            if(proto.Class == nodeClass){
                prototype = &proto;
                break;
            }
        }
        if(!prototype){
            continue;
        }
        auto &proto = *prototype;
        auto xSubStr = position.substr(0, position.find(","));
        auto ySubStr = position.substr(position.find(",")+1, position.find(","));
        nodePos.x = std::stof(xSubStr);
        nodePos.y = std::stof(ySubStr);
        if(nodeID > uniqueID){
            uniqueID = nodeID;
        }
//        m_Nodes.emplace_back(Node(nodeClass, proto, nodePos, nodeID));
//        m_Nodes.back().initializePins();
        //TODO: parse inputs subnode
    }
    for(auto & edge: FlowGraph.child("Edges")){
         uint64_t edgeID = GetUniqueID();
         uint64_t nodeInID = edge.attribute("nodeIn").as_int();
         uint64_t nodeOutID = edge.attribute("nodeOut").as_int();
        std::string portIn = edge.attribute("portIn").as_string();
        std::string portOut = edge.attribute("portOut").as_string();
        bool enabled = edge.attribute("enabled").as_bool();
//        auto nodeIn = getNode(nodeInID);
//        auto nodeOut = getNode(nodeOutID);
//        if(nodeIn && nodeOut){
//            auto inputPin = nodeIn.getPin(portIn);
//            auto outputPin = nodeOut.getPin(portOut);
//            if(inputPin && outputPin){
////                m_Edges.emplace_back(Edge(edgeID, outputPin.ID, inputPin.ID));
//            }
//        }
    }
}

FlowgraphEditor::~FlowgraphEditor() {
    ImNodes::DestroyContext();

}

Node &FlowGraph::getNode(uint64_t id) {
    static Node emptyNode;
    for(auto &node : m_Nodes){
        if(node.ID == id){
            return node;
        }
    }
    return emptyNode;
}

Pin &FlowGraph::getPin(uint64_t id) {
    static Pin emptyPin = {};
    for(auto &node : m_Nodes){
        for(auto &pin : node.Inputs){
            if(pin.ID == id){
                return pin;
            }
        }
        for(auto &pin : node.Outputs){
            if(pin.ID == id){
                return pin;
            }
        }
    }
    return emptyPin;
}

Edge &FlowGraph::getEdge(uint64_t id) {
    static Edge emptyEdge = {};
    for(auto &edge : m_Edges){
        if(edge.ID == id){
            return edge;
        }
    }
    return emptyEdge;
}

void FlowGraph::drawFlowGraph() {
    ImNodes::BeginNodeEditor();
    ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
    for(auto &node : m_Nodes){
        drawNode(node);
    }
    for(auto &edge : m_Edges){
        drawEdge(edge);
    }
    ImNodes::EndNodeEditor();
    //! handle edge creation
    {
        int start_attr, end_attr;
        if (ImNodes::IsLinkCreated(&start_attr, &end_attr)) {
            uint64_t edgeID = GetUniqueID();
            m_Edges.emplace_back(Edge(edgeID, start_attr, end_attr));
        }
    }
    //! handle edge deletion
    {
        int link_id;
        if (ImNodes::IsLinkDestroyed(&link_id)) {
            for (auto it = m_Edges.begin(); it != m_Edges.end(); it++) {
                if (it->ID == link_id) {
                    m_Edges.erase(it);
                    break;
                }
            }
        }
    }
    //! handle edge selection and deletion
    {
        const int num_selected = ImNodes::NumSelectedLinks();
        if (num_selected > 0 && ImGui::IsKeyReleased(ImGuiKey_X)) {
            static std::vector<int> selected_links;
            selected_links.resize(static_cast<size_t>(num_selected));
            ImNodes::GetSelectedLinks(selected_links.data());
            while (!selected_links.empty()) {
                int link_id = selected_links.back();
                for (auto it = m_Edges.begin(); it != m_Edges.end(); it++) {
                    if (it->ID == link_id) {
                        m_Edges.erase(it);
                        break;
                    }
                }
                selected_links.pop_back();
            }
        }
    }
    //! handle edge hovering and deletion
    {
        int link_id;
        if (ImNodes::IsLinkHovered(&link_id)) {
            if (ImGui::IsKeyPressed(ImGuiKey_X)) {
                for (auto it = m_Edges.begin(); it != m_Edges.end(); it++) {
                    if (it->ID == link_id) {
                        m_Edges.erase(it);
                        break;
                    }
                }
            }
        }
    }
    //! handle edge tooltips
    {
        int node_id;
        if(ImNodes::IsLinkHovered(&node_id)){
            ImGui::BeginTooltip();
            ImGui::Text("Edge ID: %d", node_id);
            ImGui::Text("X to delete");
            ImGui::EndTooltip();
        }
    }

    //! handle node deletion
    {
        const int num_selected = ImNodes::NumSelectedNodes();
        if (num_selected > 0 && ImGui::IsKeyReleased(ImGuiKey_X)) {
            static std::vector<int> selected_nodes;
            selected_nodes.resize(static_cast<size_t>(num_selected));
            ImNodes::GetSelectedNodes(selected_nodes.data());
            while (!selected_nodes.empty()) {
                int node_id = selected_nodes.back();
                for (auto it = m_Nodes.begin(); it != m_Nodes.end(); it++) {
                    if (it->ID == node_id) {
                        m_Nodes.erase(it);
                        break;
                    }
                }
                selected_nodes.pop_back();
            }
        }
    }
}


void FlowGraph::drawFlowGraphTab() {
   if(ImGui::BeginTabItem(name.c_str())){
       drawFlowGraph();
       ImGui::EndTabItem();
   }
}

void FlowGraph::drawNode(Node& node){
    ImNodes::BeginNode(node.ID);
    ImNodes::BeginNodeTitleBar();
    ImGui::Text("%s", node.Class.c_str());
    ImNodes::EndNodeTitleBar();
    for(auto &input : node.Inputs){
        ImNodes::BeginInputAttribute(input.ID);
        ImGui::Text("%s", input.Name.c_str());
        ImNodes::EndInputAttribute();
    }
    for(auto &output : node.Outputs){
        ImNodes::BeginOutputAttribute(output.ID);
        ImGui::Text("%s", output.Name.c_str());
        ImNodes::EndOutputAttribute();
    }
    ImNodes::EndNode();
}
void FlowGraph::drawEdge(Edge& edge){
    ImNodes::Link(edge.ID, edge.pinOut, edge.pinIn);
}

void FlowGraph::addNodeFromPrototype(PrototypeNode& proto, ImVec2 pos) {
    Node newNode (proto.Class, proto, pos);
    m_Nodes.emplace_back(newNode);
    m_Nodes.back().initializePins();
}

void FlowGraph::addNodeFromPrototype(PrototypeNode &proto, uint64_t id, ImVec2 pos) {
    Node newNode (proto.Class, proto, pos, id);
    m_Nodes.emplace_back(newNode);
    m_Nodes.back().initializePins();
}
