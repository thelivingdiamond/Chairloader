#pragma once
#include "App/AppStage.h"
#include "FlowgraphEditor.h"

struct IChairloaderToolsPreditor;
class GameViewport;

class ProjectStage : public AppStage, public ISystemEventListener
{
public:
    ProjectStage();
    ~ProjectStage();

    void Start() override;
    void Update() override;
    void ShowUI(bool* bOpen) override;

    // ISystemEventListener
    void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;

private:
    std::unique_ptr<FlowgraphEditor> m_pFlowgraphEditor;
    bool m_bFlowgraphEditorOpen = false;

    std::unique_ptr<IChairloaderToolsPreditor> m_pChairTools;
    std::shared_ptr<GameViewport> m_pGameViewport;

    void DrawMainMenuBar();
};
