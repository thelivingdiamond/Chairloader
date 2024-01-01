#pragma once
#include <Preditor/SceneEditor/ISceneEditor.h>

class EntityHierarchy;
class EntityInspector;

namespace GameEditor
{

class EntityManipulator;
class EntitySelectionManager;
class GameViewportHandler;

//! Runtime entity editing.
class GameEditMode : public ISceneEditor
{
public:
    GameEditMode();
    ~GameEditMode();

    // ISceneEditor
    virtual SelectionManager* GetSelection() override;
    virtual IViewportHandler* GetViewport() override;
    virtual IObjectManipulator* GetManipulator() override;
    virtual IEditToolManager* GetToolManager() override { return m_pEditToolManager.get(); }
    virtual UndoBuffer* GetUndoBuffer() override { return nullptr; } // TODO 2023-06-17
    virtual const char* GetObjectName(SceneObjectId id) override;
    virtual void OnEnabled() override;
    virtual void OnDisabled() override;
    virtual void ShowHierarchy() override;
    virtual void ShowInspector() override;

private:
    std::unique_ptr<EntitySelectionManager> m_pSelection;
    std::unique_ptr<GameViewportHandler> m_pViewportHandler;
    std::unique_ptr<EntityManipulator> m_pEntityManipulator;
    std::unique_ptr<IEditToolManager> m_pEditToolManager;
    std::unique_ptr<EntityHierarchy> m_pEntityHierarchy;
    std::unique_ptr<EntityInspector> m_pEntityInspector;
};

} // namespace GameEditor
