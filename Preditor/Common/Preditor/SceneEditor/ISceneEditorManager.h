#pragma once
#include <Preditor/SceneEditor/Common.h>

struct ISceneEditor;

//! Manages different edit modes.
struct ISceneEditorManager
{
    virtual ~ISceneEditorManager() {}

    //! @returns whether currently editing/playing a level.
    virtual bool IsLevelEditorLoaded() = 0;

    //! @returns current scene edit mode.
    virtual EEditMode GetMode() = 0;

    //! @returns current play mode state.
    virtual EPlayMode GetPlayMode() = 0;
    virtual void SetPlayMode(EPlayMode playMode) = 0;

    //! @returns current scene editor.
    virtual ISceneEditor* GetEditor() = 0;
};
