#pragma once
#include <Preditor/SceneEditor/ILevelSceneEditor.h>

namespace LevelEditor
{

class ObjectSelectionManager;
class LevelViewportHandler;
class ObjectManager;
class ObjectManipulator;
class Object;

//! Runtime entity editing.
class LevelEditMode : public ILevelSceneEditor
{
public:
    LevelEditMode();
    ~LevelEditMode();

    ObjectManager* GetObjectManager() const { return m_pObjectManager.get(); }

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

    // ILevelSceneEditor
    virtual void OnEnterPlayMode() override;
    virtual void OnExitPlayMode() override;

private:
    struct SInGameEntitySystemListener;

    GlobalLevel m_Global;
    std::unique_ptr<ObjectSelectionManager> m_pSelection;
    std::unique_ptr<LevelViewportHandler> m_pViewportHandler;
    std::unique_ptr<IEditToolManager> m_pEditToolManager;
    std::unique_ptr<ObjectManager> m_pObjectManager;
    std::unique_ptr<ObjectManipulator> m_pObjectManipulator;
    ICVar* m_pCanSaveLoad = nullptr;

    std::unique_ptr<SInGameEntitySystemListener> m_pEntitySystemListener;

    //! Loads current level data.
    void LoadLevel();

    //! Moves the player entity to where the scene camera is.
    void MovePlayerToSceneCamera();

    void ShowObjectInHierarchy(Object* pObj);

    void ResetEntities(bool isPlayMode);
    void NotifyGameModeChange(bool isPlayMode);
};

} // namespace LevelEditor
