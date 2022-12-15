//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_PROJECT_H
#define CHAIRLOADER_PROJECT_H
#pragma once

#include "pch.h"
#include "App/AppStage.h"
#include "ImGui/imgui.h"
#include "FlowgraphEditor.h"

// this class will be used to store all the data for a project
// should contain a path to the project, and a list of all the files in the project
// will draw the main window
// needs to be able to load and hide all the modules like the flowgraph editor

class Project : public AppStage {
public:
    void Start() override;

    void Update() override;

    void ShowUI(bool *bOpen) override;
private:
    fs::path m_ProjectPath;

    ImVec2 WINDOW_SIZE = ImVec2(1500, 750);
    ImGuiWindowFlags WINDOW_FLAGS = ImGuiWindowFlags_NoCollapse;
    std::string WINDOW_TITLE = "Project Window";
    void drawToolbar();

    std::unique_ptr<FlowgraphEditor> m_pFlowgraphEditor;
    bool m_bFlowgraphEditorOpen = false;
};


#endif //CHAIRLOADER_PROJECT_H
