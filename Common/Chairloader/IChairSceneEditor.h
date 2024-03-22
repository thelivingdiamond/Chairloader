#pragma once

enum class EChairSceneEditor
{
    None,

    //! Legacy in-game editor mode.
    InGameEditor,

    //! Preditor.
    Preditor,
};

struct IChairSceneEditor
{
    virtual ~IChairSceneEditor() {}

    //! @returns The current editor type.
    virtual EChairSceneEditor GetEditorType() const = 0;

    //! @returns Whether the scene view is active.
    virtual bool IsInSceneView() const = 0;
};
