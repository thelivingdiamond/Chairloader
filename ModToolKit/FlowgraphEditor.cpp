//
// Created by theli on 9/25/2022.
//
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include "FlowgraphEditor.h"
#include <Prey/CryAction/Ark/IArkGlobalActionManager.h>
#include <Prey/CryAction/flowsystem/Nodes/FlowBaseNode.h>


static ed::EditorContext* g_Context = nullptr;
class CGameStartup;

FlowgraphEditor::FlowgraphEditor() {
    ed::Config config;
    config.SettingsFile = "Simple.json";
    g_Context = ed::CreateEditor(&config);
    CAutoRegFlowNodeBase* nodePtr = *CAutoRegFlowNodeBase::m_pFirst.Get();
    // create an instance of every node and place them in m_FlowNodes
    while(nodePtr) {
        auto info = new IFlowNode::SActivationInfo();
        //TODO: Fix timer nodes
        if(std::string(nodePtr->m_sClassName).find("Timer") != std::string::npos) {
            nodePtr = nodePtr->m_pNext;
            continue;
        }
        PrototypeNode newNode;
        newNode.Class = nodePtr->m_sClassName;
        auto node = nodePtr->Create(info);
        SFlowNodeConfig config;
        node->GetConfiguration(config);
        newNode.Description = config.sDescription;
        int i = 0;
        auto inputPort = &config.pInputPorts[i];
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
                inputPort = &config.pInputPorts[++i];
            }
        }
        i = 0;
        auto outputPort = &config.pOutputPorts[i];
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
                outputPort = &config.pOutputPorts[++i];
            }
        }
        m_PrototypeNodes.emplace_back(newNode);
        node.ReleaseOwnership();
//        node->Release();
        nodePtr = nodePtr->m_pNext;
    }

}

void FlowgraphEditor::Draw(bool *bDraw) {
    ImGui::ShowDemoWindow(bDraw);
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
            if(ImGui::BeginTabItem("Flow Node List")) {
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
                m_Nodes.emplace_back(node);
                m_Nodes.emplace_back(node2);
                nodesAdded = true;
            }
            if(ImGui::BeginTabItem("Flow Graph")) {
                ed::SetCurrentEditor(g_Context);
                ed::Begin("My Editor", ImVec2(0.0, 0.0f));
                int uniqueId = 1;
                // Start drawing nodes.
                for(auto &flowNode : m_Nodes){
                    drawNode(flowNode);
                }
//                drawNode(node);
                for(auto &edge : m_Edges){
                    drawEdge(edge);
                }
                handleEdges();
                ed::End();
                ed::SetCurrentEditor(nullptr);
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
    if(!node.PosSet){
        ed::SetNodePosition(node.ID, node.Pos);
        node.PosSet = true;
    }
    ed::BeginNode(node.ID);
    ImGui::Text("%s", node.Name.c_str());
    ImGui::Text("class: %s", node.Class.c_str());
    ImGui::NewLine();
//    ed::SetNodePosition(node.ID, node.Pos);
   ImGui::BeginGroup();
    for (auto &inputPin: node.Inputs) {
        ed::BeginPin(inputPin.ID, ed::PinKind::Input);
        ed::PinPivotAlignment(ImVec2(1.0f, 0.5f));
        ed::PinPivotSize(ImVec2(0, 0));
        ImGui::Text("-> %s", inputPin.Name.c_str());
//        DrawPinIcon(output, IsPinLinked(output.ID), (int)(alpha * 255));
//        ImGui::Spring(0, ImGui::GetStyle().ItemSpacing.x / 2);
        ed::EndPin();
    }
    ImGui::EndGroup();
    ImGui::SameLine();
    ImGui::BeginGroup();
    for (auto &outputPin: node.Outputs) {
        ed::BeginPin(outputPin.ID, ed::PinKind::Output);
        ed::PinPivotAlignment(ImVec2(1.0f, 0.5f));
        ed::PinPivotSize(ImVec2(10, 10));
        ImGui::Text("%s ->", outputPin.Name.c_str());
        ed::EndPin();
    }
    ImGui::EndGroup();
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

            if (inputPinId && outputPinId) // both are valid, let's accept link
            {
                // ed::AcceptNewItem() return true when user release mouse button.
                if (ed::AcceptNewItem())
                {
                    // Since we accepted new link, lets add one to our list of links.
                    m_Edges.emplace_back(Edge{ ed::LinkId(GetUniqueID()), outputPinId, inputPinId });

//                    // Draw new link.
//                    ed::Link(m_Links.back().Id, m_Links.back().InputId, m_Links.back().OutputId);
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
