#pragma once
#include <Preditor/SceneEditor/ISceneEditor.h>

namespace GameEditor
{

class GameViewportHandler;

//! Runtime entity editing.
class GameEditMode : public ISceneEditor
{
public:
    GameEditMode();
    ~GameEditMode();

    // ISceneEditor
    virtual SelectionManager* GetSelection() override { return nullptr; } // TODO 2023-06-17
    virtual IViewportHandler* GetViewport() override;
    virtual IObjectManipulator* GetManipulator() override { return nullptr; } // TODO 2023-06-17
    virtual IEditToolManager* GetToolManager() override { return m_pEditToolManager.get(); }
    virtual UndoBuffer* GetUndoBuffer() override { return nullptr; } // TODO 2023-06-17
    virtual void OnEnabled() override;
    virtual void OnDisabled() override;
    virtual void ShowInspector() override;

private:
    std::unique_ptr<GameViewportHandler> m_pViewportHandler;
    std::unique_ptr<IEditToolManager> m_pEditToolManager;
};

} // namespace GameEditor
