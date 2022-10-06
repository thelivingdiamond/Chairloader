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
    for(auto &node : m_Nodes){
        if(node.ID == id){
            return &node;
        }
    }
    return nullptr;
}

Pin * FlowGraph::getPin(int64_t id) {
    for(auto &node : m_Nodes){
        for(auto &pin : node.Inputs){
            if(pin.ID == id){
                return &pin;
            }
        }
        for(auto &pin : node.Outputs){
            if(pin.ID == id){
                return &pin;
            }
        }
    }
    return nullptr;
}

Edge * FlowGraph::getEdge(int64_t id) {
    for(auto &edge : m_Edges){
        if(edge.ID == id){
            return &edge;
        }
    }
    return nullptr;
}

void FlowGraph::draw() {
    ImNodes::BeginNodeEditor();
//    ImNodes::StyleColorsLight();
//    if (ImGui::IsWindowHovered(ImGuiHoveredFlags_RootAndChildWindows))
//    {
//        auto zoom = ImNodes::EditorContextGetZoom() + ImGui::GetIO().MouseWheel * 0.1f;
//        ImNodes::EditorContextSetZoom(zoom, ImGui::GetMousePos());
//    }
    ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
    for(auto &node : m_Nodes){
        drawNode(node);
    }
    for(auto &edge : m_Edges){
        drawEdge(edge);
    }
    ImNodes::EndNodeEditor();
}


void FlowGraph::drawTab() {
    if(ImGui::BeginTabItem(name.c_str())){
        draw();
        ImGui::EndTabItem();
    }
}

void FlowGraph::drawNode(Node& node){
    ImNodes::BeginNode(node.ID);
    if(!node.PosSet){
        ImNodes::SetNodeEditorSpacePos(node.ID, node.Pos);
        node.PosSet = true;
    }
    ImNodes::BeginNodeTitleBar();
    ImGui::Text("%s", node.Class.c_str());
    ImNodes::EndNodeTitleBar();
    for(auto &input : node.Inputs){
        ImNodes::BeginInputAttribute(input.ID);
        if(input.isLinked()) {
            ImGui::Text("%s", input.Name.c_str());
        } else {
            ImGui::Text("%s", input.Name.c_str());
            ImGui::SameLine();
            if(ImNodes::IsNodeSelected(node.ID) || node.isHovered){
                ImGui::PushStyleColor(ImGuiCol_FrameBg, ImGui::GetStyleColorVec4(ImGuiCol_FrameBgHovered));
            } else {
                ImGui::PushStyleColor(ImGuiCol_FrameBg, ImGui::GetStyleColorVec4(ImGuiCol_FrameBg));
            }
            ImGui::SetNextItemWidth(120);
            ImGui::InputText(("##input" + input.Name + std::to_string(input.ID)).c_str(), &input.value);
            ImGui::PopStyleColor();
        }
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

void FlowGraph::addNodeFromPrototype(PrototypeNode &proto, int64_t id, ImVec2 pos) {
    Node newNode (proto.Class, proto, pos, id);
    m_Nodes.emplace_back(newNode);
    m_Nodes.back().initializePins();
}

bool FlowGraph::isLinked(int64_t pinID) {
    for(auto &edge : m_Edges){
        if(edge.pinIn == pinID || edge.pinOut == pinID){
            return true;
        }
    }
    return false;
}

void FlowGraph::update() {
    //! handle edge creation
    {
        int start_attr, end_attr;
        if (ImNodes::IsLinkCreated(&start_attr, &end_attr)) {
            int64_t edgeID = GetUniqueID();
            auto startPin = getPin(start_attr);
            auto endPin = getPin(end_attr);
            startPin->addLink();
            endPin->addLink();
            m_Edges.emplace_back(Edge(edgeID, start_attr, end_attr, startPin->Parent_Node->ID, endPin->Parent_Node->ID));
        }
    }
    //! handle edge deletion
    {
        int link_id;
        if (ImNodes::IsLinkDestroyed(&link_id)) {
            for (auto it = m_Edges.begin(); it != m_Edges.end(); it++) {
                if (it->ID == link_id) {
                    auto startPin = getPin(it->pinIn);
                    auto endPin = getPin(it->pinOut);
                    startPin->removeLink();
                    endPin->removeLink();
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
                        auto startPin = getPin(it->pinIn);
                        auto endPin = getPin(it->pinOut);
                        startPin->removeLink();
                        endPin->removeLink();
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
                        auto startPin = getPin(it->pinIn);
                        auto endPin = getPin(it->pinOut);
                        startPin->removeLink();
                        endPin->removeLink();
                        m_Edges.erase(it);
                        break;
                    }
                }
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
                for (auto it = m_Nodes.begin(); it != m_Nodes.end(); it++) {
                    if (it->ID == node_id) {
                        m_Nodes.erase(it);
                        break;
                    }
                }
                // remove edges connected to this node
                for (auto it = m_Edges.begin(); it != m_Edges.end();) {
                    if (it->nodeIn == node_id || it->nodeOut == node_id) {
                        it = m_Edges.erase(it);
                    } else {
                        ++it;
                    }
                }
                selected_nodes.pop_back();
            }
        }
    }
    //! handle node hovering (to set flag for color reasons)
    {
        for(auto &node : m_Nodes){
            node.isHovered = false;
        }
        int node_id;
        if(ImNodes::IsNodeHovered(&node_id)){
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
        PrototypeNode* prototype = nullptr;
        for(auto &proto : FlowgraphEditor::getInstance()->getPrototypes()){
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
        std::map<std::string, std::string> setValues;
        for(auto &value : node.child("Inputs").attributes()){
            setValues[value.name()] = value.as_string();
        }
        m_Nodes.emplace_back(Node(nodeClass, proto, nodePos, nodeID));
        m_Nodes.back().defaultInputs = setValues;
        m_Nodes.back().initializePins();
        //TODO: parse inputs subnode
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
               nodeIn->getPin(portIn)->addLink();
               nodeOut->getPin(portOut)->addLink();
               m_Edges.emplace_back(Edge(edgeID, outputPin->ID, inputPin->ID, inputPin->Parent_Node->ID, outputPin->Parent_Node->ID));
            }
        }
    }
    return true;
}
