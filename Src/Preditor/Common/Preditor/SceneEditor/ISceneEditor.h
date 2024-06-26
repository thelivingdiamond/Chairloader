#pragma once
#include <Preditor/SceneEditor/Common.h>

struct IViewportHandler;
struct IObjectManipulator;
struct IEditToolManager;
class SelectionManager;
class UndoBuffer;

//! An edit mode.
struct ISceneEditor
{
    static std::unique_ptr<ISceneEditor> CreateGameEditor();

    virtual ~ISceneEditor() {}

    //! @returns the selection manager.
    virtual SelectionManager* GetSelection() = 0;

    //! @returns the viewport handler.
    virtual IViewportHandler* GetViewport() = 0;

    //! @returns the object manipulator.
    virtual IObjectManipulator* GetManipulator() = 0;

    //! @returns the tool manager.
    virtual IEditToolManager* GetToolManager() = 0;

    //! @returns the undo buffer.
    virtual UndoBuffer* GetUndoBuffer() = 0;

    //! @returns name of the object. nullptr of ID is invalid.
    virtual const char* GetObjectName(SceneObjectId id) = 0;

    //! Called when the scene editor is enabled.
    virtual void OnEnabled() = 0;

    //! Called when the scene editor is disabled.
    virtual void OnDisabled() = 0;

    //! Shows the hierarchy window contents.
    virtual void ShowHierarchy() = 0;

    //! Shows the inspector contents.
    virtual void ShowInspector() = 0;
};
