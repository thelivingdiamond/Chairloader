#pragma once
#include "App/AppStage.h"
#include "FlowgraphEditor.h"

class GameViewport;

class ProjectStage : public AppStage
{
public:
    void Start() override;
    void Update() override;
    void ShowUI(bool* bOpen) override;

private:
    ImVec2 WINDOW_SIZE = ImVec2(1500, 750);
    ImGuiWindowFlags WINDOW_FLAGS = ImGuiWindowFlags_NoCollapse;
    std::string WINDOW_TITLE = "Project Window";
    void DrawToolbar();

    std::unique_ptr<FlowgraphEditor> m_pFlowgraphEditor;
    bool m_bFlowgraphEditorOpen = false;

    std::shared_ptr<GameViewport> m_pGameViewport;
};
