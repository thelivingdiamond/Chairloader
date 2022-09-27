//
// Created by theli on 9/25/2022.
//
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include "FlowgraphEditor.h"
#include <Prey/CryFlowGraph/IFlowSystem.h>

static ed::EditorContext* g_Context = nullptr;

FlowgraphEditor::FlowgraphEditor() {
    ed::Config config;
    config.SettingsFile = "Simple.json";
    g_Context = ed::CreateEditor(&config);
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
        ed::SetCurrentEditor(g_Context);
        ed::Begin("My Editor", ImVec2(0.0, 0.0f));
        int uniqueId = 1;
        // Start drawing nodes.
        ed::BeginNode(uniqueId++);
        ImGui::Text("Node A");
        ed::BeginPin(uniqueId++, ed::PinKind::Input);
        ImGui::Text("-> In");
        ed::EndPin();
        ImGui::SameLine();
        ed::BeginPin(uniqueId++, ed::PinKind::Output);
        ImGui::Text("Out ->");
        ed::EndPin();
        ed::EndNode();
        ed::End();
        ed::SetCurrentEditor(nullptr);
    }
    ImGui::End();
}

void FlowgraphEditor::Update() {

}
