#pragma once

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
};