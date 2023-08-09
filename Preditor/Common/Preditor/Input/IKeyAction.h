#pragma once
#include <Preditor/Input/Common.h>
#include <Preditor/ListenerSet.h>

struct IKeyAction;
struct IKeyActionSet;

struct KeyActionEventArgs
{
    IKeyAction* pAction = nullptr;

    //! Whether the action is pressed or released.
    bool isPressed = false;
};

//! An action that can be triggered by pressing one of key combinations.
//! Can also be polled by the program (whether it's currently pressed, whether it was first pressed this frame)
//! Most actions can't be bound to modifier keys. But sometimes they need to be. In that case, IsModifier() == true,
//! it can be bound to a key as usual, or can be bound to a single modifier key with no other modifiers.
struct IKeyAction
{
    using ActionListener = std::function<void(const KeyActionEventArgs&)>;

    virtual ~IKeyAction() {}

    //! @returns the name of the action in the set.
    virtual const std::string& GetName() = 0;

    //! @returns a UI shortcut string (like "Ctrl+V").
    virtual const std::string& GetUIShortcut() = 0;

    //! @returns the parent action set.
    virtual IKeyActionSet* GetActionSet() = 0;

    //! Adds/removes a press listener.
    //! @{
    virtual ListenerId AddListener(const ActionListener& listener) = 0;
    virtual bool RemoveListener(ListenerId id) = 0;
    //! @}

    //! @returns whether the action is currently active.
    virtual bool IsHeldDown() = 0;

    //! @returns whether the action was activated this frame.
    virtual bool IsPressed() = 0;

    //! @returns whether this is a modifier action.
    virtual bool IsModifier() = 0;

    //! Whether the action has modifiers.
    //! If not, modifiers are not checked when triggering the action.
    virtual bool CanHaveModifiers() = 0;

    //! Whether the action is enabled in game mode.
    //! In game mode, most Preditor actions are disabled so the user can control the game
    //! without removing something in the editor.
    virtual bool IsEnabledInGame() = 0;
};
