#pragma once
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include <Preditor/MouseGuard.h>
#include "Shared3DCursor.h"

struct ILevelSceneEditor;

namespace Main
{

//! Instantiates editors when loading/changing levels.
//! Handles switching between Level Editor and Game Editor when entering Play Mode.
class SceneEditorManager
    : public ISceneEditorManager
    , public ISystemEventListener
    , NoCopy
{
public:
    SceneEditorManager();
    ~SceneEditorManager();

    // ISceneEditorManager
    virtual bool IsLevelEditorLoaded() override { return m_pLevelEditor != nullptr; }
    virtual EEditMode GetMode() override { return m_CurrentMode; }
    virtual EPlayMode GetPlayMode() override { return m_CurrentPlayMode; }
    virtual void SetPlayMode(EPlayMode playMode) override;
    virtual ISceneEditor* GetEditor() override { return m_pCurrentEditor; }
    virtual Shared3DCursor* Get3DCursor() override { return &m_3DCursor; }

    // ISystemEventListener
    virtual void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;

private:
    Shared3DCursor m_3DCursor;
    std::unique_ptr<ILevelSceneEditor> m_pLevelEditor;
    std::unique_ptr<ISceneEditor> m_pGameEditor;

    EEditMode m_CurrentMode = EEditMode::None;
    EPlayMode m_CurrentPlayMode = EPlayMode::Edit;
    ISceneEditor* m_pCurrentEditor = nullptr;
    MouseGuard m_LoadingMouseGuard;

    //! On next level load, load the editor.
    bool m_NextLoadIsInEditor = false;

    //! "map_edit" command handler.
    static void MapEditCmd(IConsoleCmdArgs* pArgs);

    //! Resets the internal state. Makes the object act like no level is loaded.
    void Reset();

    //! ESYSTEM_EVENT_LEVEL_LOAD_END event handler.
    void OnLevelLoad();

    //! Sets the editor instance.
    void SetEditor(ISceneEditor* pEditor, EEditMode editMode);
};

} // namespace Main
