#pragma once
#include <Preditor/Input/Common.h>

//! An action that can be triggered by pressing one of key combinations.
//! Can also be polled by the program (whether it's currently pressed, whether it was first pressed this frame)
//! Most actions can't be bound to modifier keys. But sometimes they need to be. In that case, IsModifier() == true,
//! it can be bound to a key as usual, or can be bound to a single modifier key with no other modifiers.
struct IAction
{
    virtual ~IAction() {}

    //! @returns the name of the action in the set.
    virtual const std::string& GetName() = 0;

    //! @returns a UI shortcut string (like "Ctrl+V").
    virtual const std::string& GetUIShortcut() = 0;

    //! Adds/removes a press listener.
    //! @{
    virtual void AddListener() = 0;
    virtual void RemoveListener() = 0;
    //! @}

    //! @returns whether the action is currently active.
    virtual bool IsHeldDown() = 0;

    //! @returns whether the action was activated this frame.
    virtual bool IsPressed() = 0;

    //! @returns whether this is a modifier action.
    virtual bool IsModifier() = 0;
};
