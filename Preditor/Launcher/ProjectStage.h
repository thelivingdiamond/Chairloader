#pragma once
#include "App/SingletonAppStage.h"
#include "FlowgraphEditor.h"

struct IChairloaderToolsPreditor;
class ManagedWindow;
class GameViewport;
class EntityHierarchyWindow;
class InspectorWindow;
class SimControlWindow;

class ProjectStage : public SingletonAppStage<ProjectStage>, public ISystemEventListener
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
    std::shared_ptr<EntityHierarchyWindow> m_pEntHierWindow;
    std::shared_ptr<InspectorWindow> m_pInspectorWindow;
    std::shared_ptr<SimControlWindow> m_pSimControlWindow;

    void DrawMainMenuBar();
    void ShowWindowMenuItem(const char* label, ManagedWindow* window);
};
