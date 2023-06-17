#pragma once
#include <Preditor/SceneEditor/ISceneEditor.h>

namespace GameEditor
{

//! Runtime entity editing.
class GameEditMode : public ISceneEditor
{
public:
    // ISceneEditor
    virtual SelectionManager* GetSelection() override { return nullptr; } // TODO 2023-06-17
    virtual IViewportHandler* GetViewport() override { return nullptr; } // TODO 2023-06-17
    virtual IObjectManipulator* GetManipulator() override { return nullptr; } // TODO 2023-06-17
    virtual IToolManager* GetToolManager() override { return nullptr; } // TODO 2023-06-17
    virtual UndoBuffer* GetUndoBuffer() override { return nullptr; } // TODO 2023-06-17
    virtual void OnEnabled() override;
    virtual void OnDisabled() override;
    virtual void ShowInspector() override;

private:

};

} // namespace GameEditor
