//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_PROJECTSELECTSTAGE_H
#define CHAIRLOADER_PROJECTSELECTSTAGE_H

#include "pch.h"
#include "App/AppStage.h"
#include "ImGui/imgui.h"

class ProjectSelectStage : public AppStage {
public:
    void Update() override;
    void ShowUI(bool * bOpen) override;
    void Start() override;
private:
    ImVec2 WINDOW_SIZE = ImVec2(800, 600);
    ImGuiWindowFlags WINDOW_FLAGS = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoBringToFrontOnFocus;
    std::string WINDOW_TITLE = "Project Select";

    fs::path m_loadProjectPath;
    void initiateLoadOrCreateProject(const fs::path& path, bool loadExisting);

    fs::path m_newProjectPath;
    std::string m_newProjectName;
    bool m_createModFolder = true;

    bool m_newProjectOpen = false;
    bool m_ShowError = false;
    std::string m_ErrorText;
};


#endif //CHAIRLOADER_PROJECTSELECTSTAGE_H
