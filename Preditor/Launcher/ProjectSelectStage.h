//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_PROJECTSELECTSTAGE_H
#define CHAIRLOADER_PROJECTSELECTSTAGE_H
#include "App/AppStage.h"
#include "ImGui/imgui.h"

class ProjectSelectStage : public AppStage {
public:
    ProjectSelectStage();
    void ShowUI(bool * bOpen) override;

private:
    const ImVec2 WINDOW_SIZE = ImVec2(800, 600);
    static constexpr ImGuiWindowFlags WINDOW_FLAGS =
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoDocking |
        ImGuiWindowFlags_NoBringToFrontOnFocus;
    static constexpr char WINDOW_TITLE[] = "Project Select";

    std::vector<fs::path> m_History;
    fs::path m_loadProjectPath;
    void initiateLoadOrCreateProject(const fs::path& path, bool loadExisting);

    std::string m_newProjectPath;
    std::string m_newProjectName;
    bool m_createModFolder = true;

    bool m_newProjectOpen = false;
    bool m_ShowError = false;
    std::string m_ErrorText;
};


#endif //CHAIRLOADER_PROJECTSELECTSTAGE_H
