#pragma once

// Commonly used includes for key input in Preditor.
#include <Preditor/Input/IKeyAction.h>
#include <Preditor/Input/IKeyActionSet.h>
#include <Preditor/Input/IKeyboardInputSystem.h>

struct IKeyboardInputSystem;
struct IMouseInputSystem;
class ManagedWindow;

struct IPreditorInput
{
    virtual ~IPreditorInput() {}

    //! @returns a new IPreditorInput instance.
    static std::unique_ptr<IPreditorInput> CreateInstance();

    //! @returns the input debugger window.
    virtual std::shared_ptr<ManagedWindow> GetDebugWindow() = 0;

    //! @returns the keyboard input system.
    virtual IKeyboardInputSystem* GetKeyboard() = 0;

    //! @returns the mouse input system.
    virtual IMouseInputSystem* GetMouse() = 0;

    //! Updates the input system. Any events are queued until an update.
    virtual void Update() = 0;

    //! Finds an action by its path.
    //! @returns action or nullptr.
    IKeyAction* FindAction(std::string_view path, bool silent = false)
    {
        return GetKeyboard()->FindAction(path, silent);
    }
};
