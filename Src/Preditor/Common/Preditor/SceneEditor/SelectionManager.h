#pragma once
#include <Preditor/SceneEditor/Common.h>

//! Abstract list of selected objects.
class SelectionManager : NoCopy
{
public:
    SelectionManager();
    virtual ~SelectionManager();

    //! @returns whether the object is selected.
    bool IsSelected(SceneObjectId id);

    //! @returns the currently active object. May be invalid even when there are objects.
    SceneObjectId GetActiveObject() { return m_ActiveObject; }

    //! @returns the list of selected objects.
    const auto& GetList() { return m_Objects; }

    //! @returns the set of selected objects.
    const auto& GetSet() { return m_ObjectSet; }

    //! Adds an object to selection. Safe to call when object is selected.
    //! @param  id          Object ID.
    //! @param  isActive    Whether the object becomes a new active object.
    void AddToSelection(SceneObjectId id, bool isActive = true);

    //! Removes an object from the selection.
    void RemoveFromSelection(SceneObjectId id);

    //! Clears all selected objects.
    void ClearSelection();

    //! Sets INVALID_SCENE_OBJECT as the active object. Doesn't change selection.
    void ClearActiveObject();

    //! Validates that all objects IDs are still valid.
    //! Invalid objects will be deselected.
    void ValidateSelection();

protected:
    //! @returns whether the object ID points to a valid object.
    virtual bool ValidateObject(SceneObjectId id);

    //! Called when an object becomes selected.
    virtual void OnSelected(SceneObjectId id) {}

    //! Called when an object becomes deselected.
    virtual void OnDeselected(SceneObjectId id) {}

    //! Called when an object becomes the new active object.
    //! @param  id  Object ID or INVALID_SCENE_OBJECT.
    virtual void OnMadeActive(SceneObjectId id) {}

private:
    std::vector<SceneObjectId> m_Objects;
    std::set<SceneObjectId> m_ObjectSet;
    SceneObjectId m_ActiveObject = INVALID_SCENE_OBJECT;
};
