//
// Created by theli on 10/28/2022.
//

#include "ProjectSelectStage.h"
#include "ImGui/imgui.h"
#include "App/AppImGui.h"
#include "Preditor.h"

void ProjectSelectStage::Update() {

}

void ProjectSelectStage::ShowUI(bool *bOpen) {
    if(Preditor::Get()->GetConfig().isShown()) return;
    ImGui::PushFont(AppImGui::getPrettyFont());
    bool bShow = true;
    ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_Once);
    if(ImGui::Begin("Project Select", &bShow, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize)) {
        ImGui::Text("TODO: Project Select");
        // snap the buttons to the bottom of the window
        ImGui::SetCursorPosY(ImGui::GetWindowHeight() - ImGui::GetFrameHeight() - ImGui::GetStyle().ItemSpacing.y * 2);
        if(ImGui::Button("New Project")){
            SetStageFinished();
        }
        ImGui::SameLine();
        ImGui::Button("Open Project");
    }
    ImGui::End();
    ImGui::PopFont();
    if(!bShow) {
        *bOpen = false;
    }
}

void ProjectSelectStage::Start() {

}
