#pragma once
#include <Preditor/SceneEditor/ISceneEditor.h>

struct ILevelSceneEditor : public ISceneEditor
{
    static std::unique_ptr<ILevelSceneEditor> CreateLevelEditor();

    //! Creates entities for level objects.
    virtual void LoadEntities() = 0;

    //! Called when entering the play mode.
    virtual void OnEnterPlayMode() = 0;

    //! Called when exiting the play mode.
    virtual void OnExitPlayMode() = 0;
};
