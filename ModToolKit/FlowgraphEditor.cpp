//
// Created by theli on 9/25/2022.
//
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include "FlowgraphEditor.h"
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryAction/Ark/IArkGlobalActionManager.h>
#include <Prey/CryAction/flowsystem/Nodes/FlowBaseNode.h>

static ed::EditorContext* g_Context = nullptr;
class CGameStartup;

FlowgraphEditor::FlowgraphEditor() {
    ed::Config config;
    config.SettingsFile = "Simple.json";
    g_Context = ed::CreateEditor(&config);
//    CAutoRegFlowNodeBase* nodePtr = *CAutoRegFlowNodeBase::m_pFirst.Get();
//    while(nodePtr) {
////        REGISTER_FLOW_NODE(nodePtr->m_sClassName, nodePtr);
//
//    }
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
        if(ImGui::BeginTable("Nodes", 2, ImGuiTableFlags_ScrollY, ImVec2(0, ImGui::GetContentRegionAvail().y * 0.8f))){
            while(nodePtr != nullptr){
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%p", nodePtr);
                ImGui::TableNextColumn();
                ImGui::Text("%s", nodePtr->m_sClassName);
                nodePtr = nodePtr->m_pNext;
            }
            ImGui::EndTable();
        }
        static bool registerFirstNode = true;
        nodePtr = *CAutoRegFlowNodeBase::m_pFirst.Get();
        auto baseNodePtr = (CAutoRegFlowNode<bool>*)nodePtr;
        if(registerFirstNode){
//            REGISTER_FLOW_NODE(nodePtr, Flow);
            registerFirstNode = false;
        }
        ImGui::Text("BaseNode: %p", baseNodePtr);
        ImGui::Text("BaseNode->instance: %p", baseNodePtr->m_pInstance.get());
//        ed::SetCurrentEditor(g_Context);
//        ed::Begin("My Editor", ImVec2(0.0, 0.0f));
//        int uniqueId = 1;
//        // Start drawing nodes.
//        ed::BeginNode(uniqueId++);
//        ImGui::Text("Node A");
//        ed::BeginPin(uniqueId++, ed::PinKind::Input);
//        ImGui::Text("-> In");
//        ed::EndPin();
//        ImGui::SameLine();
//        ed::BeginPin(uniqueId++, ed::PinKind::Output);
//        ImGui::Text("Out ->");
//        ed::EndPin();
//        ed::EndNode();
//        ed::End();
//        ed::SetCurrentEditor(nullptr);
    }
//    ImGui::Text("%p", CAutoRegFlowNodeBase::m_pFirst.Get());
    ImGui::End();
}

void FlowgraphEditor::Update() {

}
