//
// Created by theli on 10/5/2022.
//

#include "Flowgraph.h"
#include "ImNodes/imnodes.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_stdlib.h"
#include <pugixml.hpp>
#include <filesystem>
#include "FlowgraphEditor.h"

Node * FlowGraph::getNode(int64_t id) {
    if (m_Nodes.find(id) != m_Nodes.end()) {
        return &m_Nodes[id];
    }
    return nullptr;
}

Pin * FlowGraph::getPin(int64_t id) {
    if (m_pPins.find(id) != m_pPins.end()) {
        return m_pPins[id];
    }
    return nullptr;
}

Edge * FlowGraph::getEdge(int64_t id) {
    if (m_Edges.find(id) != m_Edges.end()) {
        return &m_Edges[id];
    }
    return nullptr;
}

void FlowGraph::draw() {
    ImNodes::BeginNodeEditor();
    ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
    for(auto &node : m_Nodes){
        node.second.draw();
    }
    for(auto &edge : m_Edges){
        drawEdge(edge.second);
    }
    ImNodes::EndNodeEditor();
}


void FlowGraph::drawTab() {
    if(ImGui::BeginTabItem(name.c_str())){
        FlowgraphEditor::getInstance()->setCurrentFlowgraph(this);
        draw();
        ImGui::EndTabItem();
    }
}

void FlowGraph::drawEdge(Edge& edge){
    ImNodes::Link(edge.ID, edge.pinOut, edge.pinIn);
}


void FlowGraph::update() {
    //! handle edge creation
    {
        int start_attr, end_attr;
        if (ImNodes::IsLinkCreated(&start_attr, &end_attr)) {
            addEdge(start_attr, end_attr);
        }
    }
    //! handle edge deletion
    {
        int link_id;
        if (ImNodes::IsLinkDestroyed(&link_id)) {
            removeEdge(link_id);
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
                removeEdge(link_id);
                selected_links.pop_back();
            }
        }
    }
    //! handle edge hovering and deletion
    {
        int link_id;
        if (ImNodes::IsLinkHovered(&link_id)) {
            if (ImGui::IsKeyPressed(ImGuiKey_X)) {
                removeEdge(link_id);
                ImNodes::ClearNodeSelection();
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
                removeNode(node_id);
                selected_nodes.pop_back();
            }
        }
    }
    //! handle node hovering (to set flag for color reasons)
    {
        static int hovered_node = -1;
        int node_id;
        if(ImNodes::IsNodeHovered(&node_id)){
            if(hovered_node != node_id){
                if(hovered_node != -1){
                    m_Nodes[hovered_node].isHovered = false;
                }
                hovered_node = node_id;
            }
            auto hoveredNode = getNode(node_id);
            if(hoveredNode) {
                hoveredNode->isHovered = true;
                ImGui::BeginTooltip();
                ImGui::Text("Node ID: %d", node_id);
                ImGui::Text("X to delete");
                auto node = getNode(node_id);
                for (auto &input: node->Inputs) {
                    ImGui::Text("Input: %s, %d", input.Name.c_str(), input.numberOfConnections);
                }
                for (auto &output: node->Outputs) {
                    ImGui::Text("Output: %s, %d", output.Name.c_str(), output.numberOfConnections);
                }
                ImGui::EndTooltip();
            }
        }
    }
}

bool FlowGraph::loadXML(fs::path path) {
    if(!fs::exists(path)){
        return false;
    }
    m_Nodes.clear();
    m_Edges.clear();
    uniqueID = 1 << 16;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(path.string().c_str());
    if(!result){
        return false;
    }
    pugi::xml_node FlowGraph = doc.first_child();
    if(!FlowGraph){
        return false;
    }
    for(auto & node: FlowGraph.child("Nodes")){
        std::string nodeClass = node.attribute("Class").as_string();
        int64_t nodeID = node.attribute("Id").as_int();
        std::string position = node.attribute("pos").as_string();
        // position is in format x,y,z
        // we only want x and y
        ImVec2 nodePos = {0,0};
//        PrototypeNode* prototype = nullptr;
        auto prototype = FlowgraphEditor::getInstance()->getPrototypes().find(nodeClass);
        if(prototype == FlowgraphEditor::getInstance()->getPrototypes().end()){
            CryError("Could not find prototype for node %s", nodeClass.c_str());
            continue;
        }
        auto proto = prototype->second;
        auto xSubStr = position.substr(0, position.find(","));
        auto ySubStr = position.substr(position.find(",")+1, position.find(","));
        nodePos.x = std::stof(xSubStr);
        nodePos.y = std::stof(ySubStr);
        if(nodeID > uniqueID){
            uniqueID = nodeID;
        }
        std::map<std::string, std::string> setValues;
        for(auto &value : node.child("Inputs").attributes()){
            setValues[value.name()] = value.as_string();
        }
        addNode(nodeClass, proto, nodePos, nodeID, setValues);
    }
    for(auto & edge: FlowGraph.child("Edges")){
        int64_t edgeID = GetUniqueID();
        int64_t nodeInID = edge.attribute("nodeIn").as_int();
        int64_t nodeOutID = edge.attribute("nodeOut").as_int();
        std::string portIn = edge.attribute("portIn").as_string();
        std::string portOut = edge.attribute("portOut").as_string();
        bool enabled = edge.attribute("enabled").as_bool();
        auto nodeIn = getNode(nodeInID);
        auto nodeOut = getNode(nodeOutID);
        if(nodeIn && nodeOut && enabled){
            auto inputPin = nodeIn->getPin(portIn);
            auto outputPin = nodeOut->getPin(portOut);
            if(inputPin && outputPin){
                addEdge(inputPin->ID, outputPin->ID, edgeID);
            }
        }
    }
    return true;
}

bool FlowGraph::addNode(std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id) {
    if( id < 0){
        id = GetUniqueID();
    }
    Node newNode (proto.Class, proto, pos, id);
    if(m_Nodes.insert(std::pair(id, newNode)).second){
        m_Nodes.at(id).initializePins();
        for(auto &input : m_Nodes.at(id).Inputs){
            m_pPins.insert(std::pair(input.ID, &input));
        }
        for(auto &output : m_Nodes.at(id).Outputs){
            m_pPins.insert(std::pair(output.ID, &output));
        }
        return true;
    }
    return false;
}

bool FlowGraph::addNode(std::string name, PrototypeNode::NodeClass &protoClass, ImVec2 pos, int64_t id) {
    auto proto = FlowgraphEditor::getInstance()->getPrototypes().find(protoClass);
    if(proto != FlowgraphEditor::getInstance()->getPrototypes().end()){
        return addNode(name, proto->second, pos, id);
    }
    return false;
}

bool FlowGraph::addNode(std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id, std::map<std::string, std::string> &defaultInputs) {
    if( id < 0){
        id = GetUniqueID();
    }
    Node newNode (proto.Class, proto, pos, id, defaultInputs);
    if(m_Nodes.insert(std::pair(id, newNode)).second){
        m_Nodes.at(id).initializePins();
        for(auto &input : m_Nodes.at(id).Inputs){
            m_pPins.insert(std::pair(input.ID, &input));
        }
        for(auto &output : m_Nodes.at(id).Outputs){
            m_pPins.insert(std::pair(output.ID, &output));
        }
        return true;
    }
    return false;
}

bool FlowGraph::addNode(std::string name, PrototypeNode::NodeClass &protoClass, ImVec2 pos, int64_t id, std::map<std::string, std::string> &defaultInputs) {
    auto proto = FlowgraphEditor::getInstance()->getPrototypes().find(protoClass);
    if(proto != FlowgraphEditor::getInstance()->getPrototypes().end()){
        return addNode(name, proto->second, pos, id, defaultInputs);
    }
    return false;
}

bool FlowGraph::removeNode(int64_t id){
    auto node = getNode(id);
    if(node){
        for(auto &input : node->Inputs){
            for(auto &link : m_Edges){
                if(link.second.pinIn == input.ID || link.second.pinOut == input.ID){
                    removeEdge(link.second.ID);
                }
            }
        }
        for(auto &output : node->Outputs){
            for(auto &link : m_Edges){
                if(link.second.pinIn == output.ID || link.second.pinOut == output.ID){
                    removeEdge(link.second.ID);
                }
            }
        }
        m_Nodes.erase(id);
        return true;
    }
}

bool FlowGraph::addEdge(int64_t startPin, int64_t endPin, int64_t id) {
    if(id < 0){
        id = GetUniqueID();
    }
    if(m_pPins.find(startPin) != m_pPins.end() && m_pPins.find(endPin) != m_pPins.end()){
        auto startNode = m_pPins.at(startPin)->Parent_Node;
        auto endNode = m_pPins.at(endPin)->Parent_Node;
        //TODO: determine if selfcest is allowed
        if(startNode && endNode && startNode->ID != endNode->ID){
            if(m_Edges.insert(std::pair(id, Edge(id, startPin, endPin, startNode->ID, endNode->ID))).second){
                m_pPins.at(startPin)->addLink();
                m_pPins.at(endPin)->addLink();
                return true;
            }
        }
    }
    return false;
}

bool FlowGraph::removeEdge(int64_t id) {
    if(m_Edges.find(id) != m_Edges.end()){
        auto edge = m_Edges.at(id);
        m_pPins.at(edge.pinIn)->removeLink();
        m_pPins.at(edge.pinOut)->removeLink();
        m_Edges.erase(id);
        return true;
    }
    return false;
}
