#pragma once
#include <Preditor/Input/Common.h>

struct IKeyMap;
struct IKeyAction;
struct IKeyActionSet;

struct IKeyboardInputSystem
{
    //! Path to user key binds rlative to project user directory.
    static constexpr char BIND_CONFIG_PATH[] = "PreditorKeyBinds.xml";

    virtual ~IKeyboardInputSystem() {}

    //! @returns the key map.
    virtual IKeyMap* GetKeyMap() = 0;

    //! Finds an action set by its name.
    //! @returns action set or nullptr.
    virtual IKeyActionSet* FindActionSet(std::string_view name) = 0;

    //! Finds an action by its path.
    //! @returns action or nullptr.
    virtual IKeyAction* FindAction(std::string_view path, bool silent = false) = 0;

    //! Reloads keybinds from the config file.
    virtual void ReloadKeybinds() = 0;

    //! Updates the current modifier key mask.
    virtual void UpdateModMask(ModifierKeyMask modMask) = 0;

    //! Called when a key is pressed down.
    virtual void OnKeyDown(EKeyId keyId) = 0;

    //! Called when a key is released.
    virtual void OnKeyUp(EKeyId keyId) = 0;
};
