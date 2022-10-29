//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_PROJECT_H
#define CHAIRLOADER_PROJECT_H

#include "pch.h"
#include "App/AppStage.h"
#include "ImGui/imgui.h"

// this class will be used to store all the data for a project
// should contain a path to the project, and a list of all the files in the project
// will draw the main window
// needs to be able to load and hide all the modules like the flowgraph editor

class Project : public AppStage {
public:
    void Start() override;

    void Update() override;

    void ShowUI(bool *bOpen) override;
};


#endif //CHAIRLOADER_PROJECT_H
