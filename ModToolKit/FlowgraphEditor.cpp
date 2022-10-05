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

static ed::EditorContext* g_Context = nullptr;
class CGameStartup;

FlowgraphEditor::FlowgraphEditor() {
    ed::Config config;
    config.SettingsFile = "Simple.json";
    config.CanvasSizeMode = ed::CanvasSizeMode::FitHorizontalView;
    g_Context = ed::CreateEditor(&config);
//    CAutoRegFlowNodeBase* nodePtr = *CAutoRegFlowNodeBase::m_pFirst.Get();
    // create an instance of every node and place them in m_FlowNodes
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
                newPin.Kind = ed::PinKind::Input;
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
                newPin.Kind = ed::PinKind::Output;
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
            static Node node("Test Node", m_PrototypeNodes[20], ImVec2(200, 200));
            static Node node2("Test Node2", m_PrototypeNodes[21], ImVec2(200, 200));
            static bool nodesAdded;
            if(!nodesAdded) {
                node.initializePins();
                node2.initializePins();
                m_Nodes.emplace_back(node);
                m_Nodes.emplace_back(node2);
                nodesAdded = true;
            }
            if(ImGui::BeginTabItem("Flow Graph")) {
                if(ImGui::BeginChild("Flow Graph Canvas", ImVec2(ImGui::GetContentRegionAvail().x * 0.8f,0), true)) {
                    ed::SetCurrentEditor(g_Context);
                    ed::Begin("My Editor", ImVec2(0.0, 0.0f));
                    ed::EnableShortcuts(true);
                    // Start drawing nodes.
                    for (auto &flowNode: m_Nodes) {
                        drawNode(flowNode);
                    }
//                drawNode(node);
                    for (auto &edge: m_Edges) {
                        drawEdge(edge);
                    }
                    handleEdges();
                    ed::End();
                    ed::SetCurrentEditor(nullptr);
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
//                                Node newNode();
                                    m_Nodes.emplace_back(Node{ProtoNode.Class, ProtoNode, ImVec2(0, 0)});
                                    m_Nodes.back().initializePins();
                                }
                            }
                        }
                        ImGui::EndTable();
                    }
                    if(ImGui::Button("Clear Nodes")){
                        m_Nodes.clear();
                        m_Edges.clear();
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
    if (!node.PosSet) {
        ed::SetNodePosition(node.ID, node.Pos);
        node.PosSet = true;
    }
    ed::BeginNode(node.ID);
    ImGui::Text("%s", node.Name.c_str());
    ImGui::Text("class: %s", node.Class.c_str());
    ImGui::NewLine();
//    ed::SetNodePosition(node.ID, node.Pos);
//    ImGui::BeginGroup();
    if(ImGui::BeginTable("Node Pins", 2, ImGuiTableFlags_SizingFixedFit)) {
        ImGui::TableSetupColumn("Input", ImGuiTableColumnFlags_WidthFixed, max(node.inputWidestText, 0.1f));
        ImGui::TableSetupColumn("Output", ImGuiTableColumnFlags_WidthFixed, max(0.1f, max(node.outputWidestText, ed::GetNodeSize(node.ID).x - node.inputWidestText - 30.0f)));
        size_t i = 0;
        while(true){
            if(i >= node.Inputs.size() && i >= node.Outputs.size()){
                break;
            }
            if(i < node.Inputs.size()){
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ed::BeginPin(node.Inputs[i].ID, ed::PinKind::Input);
                ed::PinPivotAlignment(ImVec2(0.0f, 0.5f));
                ed::PinPivotSize(ImVec2(0, 0));
                ImGui::Text("<- %s", node.Inputs[i].Name.c_str());
                ed::EndPin();
            } else {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text(" ");
            }
            if(i < node.Outputs.size()){
                ImGui::TableNextColumn();
                ed::BeginPin(node.Outputs[i].ID, ed::PinKind::Output);
                ed::PinPivotAlignment(ImVec2(1.0f, 0.5f));
                ed::PinPivotSize(ImVec2(0, 0));
                auto columnWidth = ImGui::GetColumnWidth();
                auto textSize = ImGui::CalcTextSize((node.Outputs[i].Name + " ->").c_str());
//                ImGui::Indent((node.outputWidestText - textSize.x));
//                if(columnWidth - textSize.x > 0){
//                    ImGui::Indent(columnWidth - textSize.x - 3.0f);
//                }
                ImGui::Text("%s ->", node.Outputs[i].Name.c_str());
//                ImGui::Unindent();
                ed::EndPin();
            } else {
                ImGui::TableNextColumn();
                ImGui::Text(" ");
            }
            i++;
        }
//        for (auto &inputPin: node.Inputs) {
//            ed::BeginPin(inputPin.ID, ed::PinKind::Input);
//            ed::PinPivotAlignment(ImVec2(0.0f, 0.5f));
//            ed::PinPivotSize(ImVec2(0, 0));
//            ImGui::Text("-> %s", inputPin.Name.c_str());
//            ed::EndPin();
//        }
        auto nodeSize = ed::GetNodeSize(node.ID);
//        for (auto &outputPin: node.Outputs) {
//            ed::BeginPin(outputPin.ID, ed::PinKind::Output);
//            ed::PinPivotAlignment(ImVec2(1.0f, 0.5f));
//            ed::PinPivotSize(ImVec2(0, 0));
//            // right align text using the nodes outputWidestText and the nodes size and cursor position to right align to the edge
//    //        auto textSize = ImGui::CalcTextSize((outputPin.Name).c_str());
//    //        auto cursorPos = ImGui::GetCursorPos().x;
//    //        auto nodePos = ed::GetNodePosition(node.ID).x;
//    //        auto offset = cursorPos - nodePos;
//    //        auto value1 = offset + node.outputWidestText;
//    //        float cursorOffset = 0.0f;
//    //        if (value1 + 30.0f < nodeSize.x ) {
//    //            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
//    ////            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + nodeSize.x - node.outputWidestText - 30.0f);
//    //        } else {
//    //            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
//    //        }
//    //        ImGui::Indent((node.outputWidestText - textSize.x) + cursorOffset);
//            ImGui::Text("%s ->", outputPin.Name.c_str());
//            ImGui::Unindent();
//            ImGui::PopStyleColor();
//            ed::EndPin();
//        }
        ImGui::EndTable();
    }

//    ImGui::EndGroup();
    ed::EndNode();
}

void FlowgraphEditor::drawEdge(Edge &edge) {
    ed::Link(edge.ID, edge.pinOut, edge.pinIn);
}

void FlowgraphEditor::handleEdges() {
    // Handle creation action, returns true if editor want to create new object (node or link)
    if (ed::BeginCreate())
    {
        ed::PinId inputPinId, outputPinId;
        if (ed::QueryNewLink(&inputPinId, &outputPinId))
        {
            // QueryNewLink returns true if editor want to create new link between pins.
            //
            // Link can be created only for two valid pins, it is up to you to
            // validate if connection make sense. Editor is happy to make any.
            //
            // Link always goes from input to output. User may choose to drag
            // link from output pin or input pin. This determine which pin ids
            // are valid and which are not:
            //   * input valid, output invalid - user started to drag new ling from input pin
            //   * input invalid, output valid - user started to drag new ling from output pin
            //   * input valid, output valid   - user dragged link over other pin, can be validated

           if(inputPinId && outputPinId){
               auto inputPin = getPin(inputPinId);
               auto outputPin = getPin(outputPinId);
                // ed::AcceptNewItem() return true when user release mouse button.
               if ((inputPin.ID && outputPin.ID) &&
                   (inputPin.Kind != outputPin.Kind) &&
                   (inputPin.Parent_Node->ID != outputPin.Parent_Node->ID)) // both are valid, let's accept link
               {
                if (ed::AcceptNewItem()) {
                        // Since we accepted new link, lets add one to our list of links.
                        m_Edges.emplace_back(Edge{ed::LinkId(GetUniqueID()), outputPinId, inputPinId});
//                    // Draw new link.
//                    ed::Link(m_Links.back().Id, m_Links.back().InputId, m_Links.back().OutputId);
                }
               } else {
                   ed::RejectNewItem(ImVec4(1, 0, 0, 1), 1.0f);
//                   ImGui::OpenPopup("Error");
//                   if(ImGui::BeginPopupContextItem("Error")) {
//                       ImGui::Text("Invalid connection");
//                       ImGui::EndPopup();
//                   }
               }
                // You may choose to reject connection between these nodes
                // by calling ed::RejectNewItem(). This will allow editor to give
                // visual feedback by changing link thickness and color.
            }
        }
    }
    ed::EndCreate(); // Wraps up object creation action handling.


    // Handle deletion action
    if (ed::BeginDelete())
    {
        // There may be many links marked for deletion, let's loop over them.
        ed::LinkId deletedLinkId;
        while (ed::QueryDeletedLink(&deletedLinkId))
        {
            // If you agree that link can be deleted, accept deletion.
            if (ed::AcceptDeletedItem())
            {
                // Then remove link from your data.
                int i = 0;
                for (auto& edge : m_Edges)
                {
                    if (edge.ID == deletedLinkId)
                    {
                        m_Edges.erase(m_Edges.begin() + i);
                        break;
                    }
                    i++;
                }
            }

            // You may reject link deletion by calling:
            // ed::RejectDeletedItem();
        }
    }
    ed::EndDelete(); // Wrap up deletion action

}

Node &FlowgraphEditor::getNode(ed::NodeId id) {
    static Node emptyNode;
    for(auto &node : m_Nodes){
        if(node.ID == id){
            return node;
        }
    }
    return emptyNode;
}

Pin &FlowgraphEditor::getPin(ed::PinId id) {
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

Edge &FlowgraphEditor::getEdge(ed::LinkId id) {
    static Edge emptyEdge = {};
    for(auto &edge : m_Edges){
        if(edge.ID == id){
            return edge;
        }
    }
    return emptyEdge;
}

void FlowgraphEditor::loadXMLFlowgraph(fs::path path) {
    if(!fs::exists(path)){
        return;
    }
    m_Nodes.clear();
    m_Edges.clear();
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
        ed::NodeId nodeID = node.attribute("Id").as_int();
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
        nodePos.x = std::stof(xSubStr) - 1000.0f;
        nodePos.y = std::stof(ySubStr);
        if(nodeID.Get() > uniqueID){
            uniqueID = nodeID.Get();
        }
        m_Nodes.emplace_back(Node(nodeClass, proto, nodePos, nodeID));
        ed::SetNodePosition(nodeID, nodePos);
        m_Nodes.back().initializePins();
        //TODO: parse inputs subnode
    }
    for(auto & edge: FlowGraph.child("Edges")){
        ed::LinkId edgeID = GetUniqueID();
        ed::NodeId nodeInID = edge.attribute("nodeIn").as_int();
        ed::NodeId nodeOutID = edge.attribute("nodeOut").as_int();
        std::string portIn = edge.attribute("portIn").as_string();
        std::string portOut = edge.attribute("portOut").as_string();
        bool enabled = edge.attribute("enabled").as_bool();
        auto nodeIn = getNode(nodeInID);
        auto nodeOut = getNode(nodeOutID);
        if(nodeIn && nodeOut){
            auto inputPin = nodeIn.getPin(portIn);
            auto outputPin = nodeOut.getPin(portOut);
            if(inputPin && outputPin){
                m_Edges.emplace_back(Edge(edgeID, outputPin.ID, inputPin.ID));
            }
        }
    }
}
