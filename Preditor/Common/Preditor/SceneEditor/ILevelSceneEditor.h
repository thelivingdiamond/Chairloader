#pragma once
#include <Preditor/SceneEditor/ISceneEditor.h>

struct ILevelSceneEditor : public ISceneEditor
{
    static std::unique_ptr<ILevelSceneEditor> CreateLevelEditor();

    virtual void OnEnterPlayMode() = 0;
    virtual void OnExitPlayMode() = 0;
};
