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
#include <boost/algorithm/string.hpp>

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
    if(ImGui::BeginChild("Node List", ImVec2(ImGui::GetContentRegionAvail().x * 0.2f, 0), true)) {
        ImGui::Text("Node List");
        ImGui::Separator();
        if(ImGui::BeginTable("Node List", 2, 0, ImGui::GetContentRegionAvail())) {
            ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
//            ImGui::TableHeadersRow();
            for (auto& node : m_Nodes) {
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                if(ImGui::Selectable(std::to_string(node.second.ID).c_str(), ImNodes::IsNodeSelected(node.second.ID), ImGuiSelectableFlags_SpanAllColumns)){
                    if((ImGui::IsKeyDown(ImGui::GetKeyIndex(ImGuiKey_LeftShift)) || ImGui::IsKeyDown(ImGui::GetKeyIndex(ImGuiKey_RightShift)))){
                        if(ImNodes::IsNodeSelected(node.second.ID)){
                            const int num_selected = ImNodes::NumSelectedNodes();
                            if (num_selected > 0) {
                                static std::vector<int> selected_nodes;
                                selected_nodes.resize(static_cast<size_t>(num_selected));
                                ImNodes::GetSelectedNodes(selected_nodes.data());
                                ImNodes::ClearNodeSelection();
                                for (int i = 0; i < num_selected; ++i) {
                                    if(selected_nodes[i] != node.second.ID){
                                        ImNodes::SelectNode(selected_nodes[i]);
                                    }
                                }
                            }
                        } else {
                            ImNodes::SelectNode(node.second.ID);
                        }
                    } else {
                        if(ImNodes::NumSelectedNodes() > 1){
                            ImNodes::ClearNodeSelection();
                            ImNodes::SelectNode(node.second.ID);
                        } else {
                            if(ImNodes::IsNodeSelected(node.second.ID)){
                                ImNodes::ClearNodeSelection();
                            } else {
                                ImNodes::SelectNode(node.second.ID);
                            }
                        }
                    }
                }
                if(ImGui::IsItemClicked(ImGuiMouseButton_Left) && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)){
                    ImNodes::EditorContextMoveToNode(node.second.ID);
                }
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", node.second.Name.c_str());
            }
            ImGui::EndTable();
//            if(ImGui::IsMouseClicked(ImGuiMouseButton_Left)){
//                ImNodes::ClearNodeSelection();
//            }
        }
    }
    ImGui::EndChild();
    ImGui::SameLine();
    ImNodes::EditorContextSet(m_Context);
    ImNodes::BeginNodeEditor();
    ImNodes::MiniMap(0.2f, ImNodesMiniMapLocation_TopRight);
    if(m_bResetPan){
        ImNodes::EditorContextResetPanning(m_ResetPos);
        m_bResetPan = false;
    }
    for(auto &node : m_Nodes){
        node.second.draw();
    }
    for(auto &edge : m_Edges){
        drawEdge(edge.second);
    }
    if(ImNodes::IsEditorHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Right)){
        FlowgraphEditor::setShowNodePopup(true);
    }
    ImNodes::EndNodeEditor();
//    ImNodes::EditorContextFree(m_Context);
    update();
}


void FlowGraph::drawTab() {
    if(ImGui::BeginTabItem(m_Name.c_str())){
        FlowgraphEditor::getInstance()->setCurrentFlowgraph(this);
        draw();
        ImGui::EndTabItem();
    }
}

void FlowGraph::drawEdge(Edge& edge){
    ImNodes::Link(edge.ID, edge.pinOut, edge.pinIn);
}


void FlowGraph::update() {
    ImNodes::EditorContextSet(m_Context);
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
        if (num_selected > 0 && ImGui::IsKeyReleased(ImGuiKey_X) && !ImGui::GetIO().WantTextInput) {
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
            if (ImGui::IsKeyPressed(ImGuiKey_X)  && !ImGui::GetIO().WantTextInput) {
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
    //! handle node hovering (to set flag for color reasons)
    {
        static int hovered_node = -1;
        int node_id = -1;
        if(ImNodes::IsNodeHovered(&node_id)){
            if(hovered_node != node_id){
                if(hovered_node != -1){
                    if(m_Nodes.find(hovered_node) != m_Nodes.end()){
                        m_Nodes[hovered_node].isHovered = false;
                    }
                }
                hovered_node = node_id;
            }
            auto hoveredNode = getNode(node_id);
            if(hoveredNode) {
                hoveredNode->isHovered = true;
//                ImGui::BeginTooltip();
//                ImGui::Text("Node ID: %d", node_id);
//                ImGui::Text("X to delete");
//                auto node = getNode(node_id);
//                for (auto &input: node->Inputs) {
//                    ImGui::Text("Input: %s, %d", input.Name.c_str(), input.numberOfConnections);
//                }
//                for (auto &output: node->Outputs) {
//                    ImGui::Text("Output: %s, %d", output.Name.c_str(), output.numberOfConnections);
//                }
//                ImGui::EndTooltip();
            }
        }
    }

    //! handle node deletion
    {
        const int num_selected = ImNodes::NumSelectedNodes();
        if (num_selected > 0 && ImGui::IsKeyReleased(ImGuiKey_X)  && !ImGui::GetIO().WantTextInput) {
            static std::vector<int> selected_nodes;
            selected_nodes.resize(static_cast<size_t>(num_selected));
            ImNodes::GetSelectedNodes(selected_nodes.data());
            while (!selected_nodes.empty()) {
                int node_id = selected_nodes.back();
                removeNode(node_id);
                selected_nodes.pop_back();
            }
            ImNodes::ClearNodeSelection();
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
        if(nodeClass == "_commentbox" || nodeClass == "_comment") {
            addCommentBox(nodeClass, nodePos, node.attribute("Name").as_string(), nodeID);
        } else {
            addNode(nodeClass, proto, nodePos, nodeID, setValues);
        }
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
    Node newNode (proto.Class, proto, pos, id, this);
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
    Node newNode (proto.Class, proto, pos, id, defaultInputs, this);
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
        // erase the node with id
        m_Nodes.erase(id);
        return true;
    }
    return false;
}

bool FlowGraph::addEdge(int64_t startPin, int64_t endPin, int64_t id) {
    if(id < 0){
        id = GetUniqueID();
    }
    if(m_pPins.find(startPin) == m_pPins.end() || m_pPins.find(endPin) == m_pPins.end()) return false;
    auto startNode = m_pPins.at(startPin)->Parent_Node;
    auto endNode = m_pPins.at(endPin)->Parent_Node;
    //TODO: determine if selfcest is allowed - yes it is apparently
    if(!startNode || !endNode) return false;
//    if (startNode->ID == endNode->ID) return false;
    if(m_Edges.insert(std::pair(id, Edge(id, startPin, endPin, startNode->ID, endNode->ID))).second){
        m_pPins.at(startPin)->addLink();
        m_pPins.at(endPin)->addLink();
        return true;
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

void FlowGraph::resetPanning(ImVec2 pos){
    m_bResetPan = true;
    m_ResetPos = pos;
}


bool FlowGraph::addCommentBox(std::string name, ImVec2 pos, std::string comment, int64_t id){
    if(addNode(name, FlowgraphEditor::getInstance()->getPrototypes().at("_commentbox"), pos, id)){
        auto node = getNode(id);
        boost::replace_all(comment, "\\n", "\n");
        boost::replace_all(comment, "_", " ");
        if(node){
            node->comment = comment;
            return true;
        }
    }
    return false;
}

void FlowGraph::drawSelectedNodeProperties() {
    const int num_selected = ImNodes::NumSelectedNodes();
    if (num_selected == 1) {
        static std::vector<int> selected_nodes;
        selected_nodes.resize(static_cast<size_t>(num_selected));
        ImNodes::GetSelectedNodes(selected_nodes.data());
        auto node = getNode(selected_nodes[0]);
        if(node){
            drawNodeProperties(*node);
            m_nodePropertiesHeight = 0.3f;
        } else {
            ImGui::Text("Selected node not found");
            m_nodePropertiesHeight = 0.2f;
        }
    } else if (num_selected > 1) {
        ImGui::Text("Multiple nodes selected");
        m_nodePropertiesHeight = 0.2f;
    } else {
        ImGui::Text("No node selected");
        m_nodePropertiesHeight = 0.2f;
    }

}


void FlowGraph::drawNodeProperties(Node& node) {
    ImGui::Text("Node Properties");
    ImGui::Separator();
    if (ImGui::BeginChild("properties", ImVec2(0, ImGui::GetContentRegionAvail().y))) {
        ImGui::Text("Name: ");
        ImGui::SameLine();
        ImGui::InputText("##name", &node.Name);
        ImGui::Text("Class: %s", node.Class.c_str());
        ImGui::Text("ID: %lld", node.ID);
        ImGui::Text("Entity Node: %d", node.m_bEntity_Node);
        if(node.m_bEntity_Node){
            ImGui::InputText("Entity GUID", &node.entityGUID);
            ImGui::InputText("Entity GUID 64", &node.entityGUID64);
        }
        if(ImGui::TreeNode("Flags")){
            /*
             * EHYPER_NODE_ENTITY        = 0x0001,
                EHYPER_NODE_ENTITY_VALID  = 0x0002,
                EHYPER_NODE_GRAPH_ENTITY  = 0x0004,
                EHYPER_NODE_GRAPH_ENTITY2 = 0x0008,
                EHYPER_NODE_INSPECTED     = 0x0010,
                EHYPER_NODE_HIDE_UI       = 0x0100,
                EHYPER_NODE_CUSTOM_COLOR1 = 0x0200,
                EHYPER_NODE_UNREMOVEABLE  = 0x0400,
                */
            ImGui::Text("%s: %d", "EHYPER_NODE_ENTITY", node.mFlags & EHYPER_NODE_ENTITY);
            ImGui::Text("%s: %d", "EHYPER_NODE_ENTITY_VALID", node.mFlags & EHYPER_NODE_ENTITY_VALID);
            ImGui::Text("%s: %d", "EHYPER_NODE_GRAPH_ENTITY", node.mFlags & EHYPER_NODE_GRAPH_ENTITY);
            ImGui::Text("%s: %d", "EHYPER_NODE_GRAPH_ENTITY2", node.mFlags & EHYPER_NODE_GRAPH_ENTITY2);
            ImGui::Text("%s: %d", "EHYPER_NODE_INSPECTED", node.mFlags & EHYPER_NODE_INSPECTED);
            ImGui::Text("%s: %d", "EHYPER_NODE_HIDE_UI", node.mFlags & EHYPER_NODE_HIDE_UI);
            ImGui::Text("%s: %d", "EHYPER_NODE_CUSTOM_COLOR1", node.mFlags & EHYPER_NODE_CUSTOM_COLOR1);
            ImGui::Text("%s: %d", "EHYPER_NODE_UNREMOVEABLE", node.mFlags & EHYPER_NODE_UNREMOVEABLE);
            ImGui::TreePop();
        }
        if(ImGui::InputFloat2("Position (x,y)", &node.Pos.x, "%.1f") && !ImGui::IsItemEdited()){
            node.PosSet = false;
        }
//        ImGui::Text("Position: (%.2f, %.2f)", node.Pos.x, node.Pos.y);
        ImGui::Separator();
        if(!node.Inputs.empty()) {
            if (ImGui::CollapsingHeader("Inputs")) {
                for (auto &input: node.Inputs) {
                    ImGui::Text("Name: %s", input.Name.c_str());
                    if (input.numberOfConnections > 0) {
                        ImGui::Text("Connected");
                    } else {
                        ImGui::InputText(("value##" + input.Name).c_str(), &input.value);
                    }
                    ImGui::Text("ID: %lld", input.ID);
                    ImGui::SameLine();
                    ImGui::Text("Links: %d", input.numberOfConnections);
                    ImGui::Separator();
                }
            }
        }
        if(!node.Outputs.empty()) {
            if (ImGui::CollapsingHeader("Outputs:")) {
                for (auto &output: node.Outputs) {
                    ImGui::Text("Name: %s", output.Name.c_str());
                    ImGui::Text("ID: %lld", output.ID);
                    ImGui::SameLine();
                    ImGui::Text("Links: %d", output.numberOfConnections);
                    ImGui::Separator();
                }
            }
        }
        if(node.xmlNode){
            if (ImGui::CollapsingHeader("XML:")) {
                for(auto& attribute : node.xmlNode.attributes()){
                    static std::string value;
                    ImGui::Text("%s:", attribute.name());
                    ImGui::SameLine();
                    value = attribute.value();
                    if(ImGui::InputText(("##" + std::string(attribute.name())).c_str(), &value)){
                        node.xmlNode.attribute(attribute.name()) = value.c_str();
                    }
                }
            }
        }
    }
    ImGui::EndChild();
}

FlowGraph::FlowGraph() {
    m_Context = ImNodes::EditorContextCreate();
}

FlowGraph::~FlowGraph() {
}

bool FlowGraphXMLFile::loadFromXmlFile(fs::path path) {
    m_FilePlace = parseFilePlace(path);
    if(!fs::exists(path)) return false;
    if(path.filename().extension() != ".xml") return false;
    m_Path = path;
    auto result = m_Document.load_file(path.wstring().c_str());
    if(!result) return false;

    return false;
}

FilePlace FlowGraphXMLFile::parseFilePlace(fs::path path) {
    if(path.wstring().find(L"PreyFiles\\Levels") != wstring::npos){
        return FilePlace::Level;
    } else if(path.wstring().find(L"PreyFiles\\Ark") != wstring::npos){
        return FilePlace::Ark;
    } else if(path.wstring().find(L"PreyFiles\\Libs") != wstring::npos){
        return FilePlace::Libs;
    } else if(path.wstring().find(L"PreyFiles\\Prefabs") != wstring::npos){
        return FilePlace::Prefabs;
    }
    return FilePlace::Unknown;
}

FlowGraphXMLFile::FlowGraphXMLFile(fs::path path) {
    m_Path = path;
    m_FilePlace = parseFilePlace(m_Path);
    // parse the relative path to be everything after the last instance of PreyFiles
    m_RelativePath = m_Path.wstring().substr(m_Path.wstring().find(L"PreyFiles") + wstring(L"PreyFiles\\").length());
    auto result = m_Document.load_file(path.wstring().c_str());
    if(!result) return;
    if(m_FilePlace == FilePlace::Level){
        // determine which level, determine where in levels it is
        // this must be the mission file
        auto m_SeekPath = m_Path;
        auto rootDirectory = m_SeekPath.root_directory();
        while(m_SeekPath.parent_path() != m_SeekPath){
            m_SeekPath = m_SeekPath.parent_path();
            if(m_SeekPath.filename() == "level" || m_SeekPath.filename() == "FlowgraphModules"){
                m_LevelName = m_SeekPath.parent_path().filename();
                break;
            }
        }
//        m_RelativeLevelPath = m_SeekPath.wstring().substr(m_SeekPath.wstring().find(m_LevelName) + m_LevelName.wstring().length() + 1);
        if(m_Path.parent_path().filename() == "level") {
            auto objects = m_Document.first_child().child("Objects");
            m_RelativeLevelPath = (L"level" / m_Path.filename());
            for(auto object: objects.children()){
                if(object.child("FlowGraph")){
                    m_FlowGraphs.emplace_back(std::make_shared<FlowGraphFromXML>(object, m_Path, object.attribute("Name").as_string()));
                    m_FlowGraphs.back()->m_FlowGraphType = FlowGraphFromXML::FlowGraphType::Entity;
                    m_FlowGraphs.back()->m_FileInfo = FlowGraphFromXML::EntityFileInfo{object.attribute("Name").as_string(), object.attribute("EntityId").as_ullong()};
                }
            }
        } else if (m_Path.parent_path().filename() == "flowgraphobjectlists") {
            auto graph = m_Document.first_child();
            m_RelativeLevelPath = (L"flowgraphobjectlists" / m_Path.filename());
            m_FlowGraphs.emplace_back(std::make_shared<FlowGraphFromXML>(graph, m_Path, graph.attribute("moduleName").as_string()));
            m_FlowGraphs.back()->m_FlowGraphType = FlowGraphFromXML::FlowGraphType::FlowgraphObjectList;
        } else if (m_Path.parent_path().filename() == "FlowgraphModules") {
            auto graph = m_Document.first_child();
            m_RelativeLevelPath = (L"FlowgraphModules" / m_Path.filename());
            m_FlowGraphs.emplace_back(std::make_shared<FlowGraphFromXML>(graph, m_Path, graph.attribute("moduleName").as_string()));
            m_FlowGraphs.back()->m_FlowGraphType = FlowGraphFromXML::FlowGraphType::FlowgraphModule;
        }
    }
}

FlowGraphFromXML::FlowGraphFromXML(pugi::xml_node &node, fs::path path, std::string name) {
    m_Name = name;
    m_Path = path;
    m_RootNode = node;
    if(node.name() == std::string("FlowGraph") || node.name() == std::string("Graph")) {
        loadXML(node);
    } else {
        if(node.child("FlowGraph")){
            auto tempNode = node.child("FlowGraph");
            loadXML(tempNode);
        } else if(node.child("Graph")){
            auto tempNode = node.child("Graph");
            loadXML(tempNode);
        } else {
            CryError("FlowGraphFromXML::FlowGraphFromXML: Could not find FlowGraph or Graph node");
        }
    }
}

bool FlowGraphFromXML::loadXML(pugi::xml_node &RootNodeIn) {
    m_Nodes.clear();
    m_Edges.clear();
    uniqueID = 1 << 16;
    for(auto & node: RootNodeIn.child("Nodes")){
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
        position = position.substr(position.find(",") + 1);
        auto ySubStr = position.substr(0, position.find(","));
        nodePos.x = std::stof(xSubStr);
        nodePos.y = std::stof(ySubStr);
        if(nodeID > uniqueID){
            uniqueID = nodeID;
        }
        std::map<std::string, std::string> setValues;
//        if(!proto.m_bEntity_Node && node.attribute("EntityGUID")){
//            CryError("EntityGUID attribute found on non-entity node %s", nodeClass.c_str());
//        }
//        if(proto.m_bEntity_Node && !node.attribute("EntityGUID") && !proto.m_bDefault_Entity_node){
//            CryError("EntityGUID attribute not found on entity node %s", nodeClass.c_str());
//        }
        for(auto &value : node.child("Inputs").attributes()){
            setValues[value.name()] = value.as_string();
        }
        if(nodeClass == "_commentbox" || nodeClass == "_comment") {
            addCommentBox(nodeClass, nodePos, node.attribute("Name").as_string(), nodeID);
            m_Nodes.at(nodeID).xmlNode = node;
        } else {
            addNode(nodeClass, proto, nodePos, nodeID, setValues);
            m_Nodes.at(nodeID).xmlNode = node;
            m_Nodes.at(nodeID).entityGUID = node.attribute("EntityGUID").as_string();
            m_Nodes.at(nodeID).entityGUID64 = node.attribute("EntityGUID_64").as_string();
            if(m_Nodes.at(nodeID).m_bEntity_Node){
                m_Nodes.at(nodeID).getPin("entityId")->value = m_Nodes.at(nodeID).entityGUID64;
            }
        }
    }
    for(auto & edge: RootNodeIn.child("Edges")){
        int64_t edgeID = GetUniqueID();
        int64_t nodeInID = edge.attribute("nodeIn").as_int();
        int64_t nodeOutID = edge.attribute("nodeOut").as_int();
        std::string portIn = edge.attribute("portIn").as_string();
        std::string portOut = edge.attribute("portOut").as_string();
        bool enabled = edge.attribute("enabled").as_bool();
        auto nodeIn = getNode(nodeInID);
        auto nodeOut = getNode(nodeOutID);
        if(nodeIn && nodeOut && enabled){
            auto inputPin = nodeIn->getInputPin(portIn);
            auto outputPin = nodeOut->getOutputPin(portOut);
            if(!inputPin){
                inputPin = nodeIn->getPin(portIn);
            }
            if(!outputPin){
                outputPin = nodeOut->getPin(portOut);
            }
            if(inputPin && outputPin){
                addEdge(inputPin->ID, outputPin->ID, edgeID);
            }
        }
    }
    return true;
}
