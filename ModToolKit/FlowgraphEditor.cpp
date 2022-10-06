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


FlowgraphEditor::FlowgraphEditor() {
    m_pFlowgraphEditorInstance = this;
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
        if(ImGui::BeginTabBar("Editor Tabs")) {
            CAutoRegFlowNodeBase* nodePtr = *CAutoRegFlowNodeBase::m_pFirst.Get();
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
                    testGraph.draw();
                    testGraph.update();

                }
                ImGui::EndChild();
                ImGui::SameLine();
                if(ImGui::BeginChild("Prototype Node Selection List", ImVec2(0,0), true)) {
                    static std::string path;
                    ImGui::InputText("Path", &path);
                    if(ImGui::Button("Load XML File")){
                        if(p_CurrentFlowGraph) {
                            auto success = p_CurrentFlowGraph->loadXML(path);
                            CRY_ASSERT(success);
                        }
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
    for(auto & graph : m_FlowGraphs){
        graph.update();
    }
}

FlowgraphEditor::~FlowgraphEditor() {
    ImNodes::DestroyContext();

}

