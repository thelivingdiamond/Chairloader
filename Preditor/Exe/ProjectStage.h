#pragma once
#include "App/AppStage.h"
#include "FlowgraphEditor.h"

struct IChairloaderToolsPreditor;
class GameViewport;

class ProjectStage : public AppStage
{
public:
    ProjectStage();
    ~ProjectStage();

    void Start() override;
    void Update() override;
    void ShowUI(bool* bOpen) override;

private:
    ImGuiWindowFlags WINDOW_FLAGS = ImGuiWindowFlags_NoCollapse;
    std::string WINDOW_TITLE = "Project Window";
    void DrawToolbar();

    std::unique_ptr<FlowgraphEditor> m_pFlowgraphEditor;
    bool m_bFlowgraphEditorOpen = false;

    std::unique_ptr<IChairloaderToolsPreditor> m_pChairTools;
    std::shared_ptr<GameViewport> m_pGameViewport;

    void DrawMainMenuBar();
};
