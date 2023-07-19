#pragma once
#include <Preditor/SceneEditor/ISceneEditor.h>

namespace LevelEditor
{

class ObjectSelectionManager;
class LevelViewportHandler;
class ObjectManager;

//! Runtime entity editing.
class LevelEditMode : public ISceneEditor
{
public:
    LevelEditMode();
    ~LevelEditMode();

    // ISceneEditor
    virtual SelectionManager* GetSelection() override;
    virtual IViewportHandler* GetViewport() override;
    virtual IObjectManipulator* GetManipulator() override { return nullptr; } // TODO 2023-06-17
    virtual IEditToolManager* GetToolManager() override { return m_pEditToolManager.get(); }
    virtual UndoBuffer* GetUndoBuffer() override { return nullptr; } // TODO 2023-06-17
    virtual const char* GetObjectName(SceneObjectId id) override;
    virtual void OnEnabled() override;
    virtual void OnDisabled() override;
    virtual void ShowHierarchy() override;
    virtual void ShowInspector() override;

private:
    GlobalLevel m_Global;
    std::unique_ptr<ObjectSelectionManager> m_pSelection;
    std::unique_ptr<LevelViewportHandler> m_pViewportHandler;
    std::unique_ptr<IEditToolManager> m_pEditToolManager;
    std::unique_ptr<ObjectManager> m_pObjectManager;
    ICVar* m_pCanSaveLoad = nullptr;

    //! Loads current level data.
    void LoadLevel();
};

} // namespace LevelEditor
