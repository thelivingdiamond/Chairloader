#pragma once
#include <Preditor/Input/IPreditorInput.h>
#include "InputDebuggerWindow.h"
#include "KeyboardInputSystem.h"
#include "MouseInputSystem.h"

namespace Input
{

class PreditorInput : public IPreditorInput
{
public:
    PreditorInput();
    ~PreditorInput();

    // IPreditorInput
    virtual std::shared_ptr<ManagedWindow> GetDebugWindow() override { return m_pDbgWindow; }
    virtual IKeyboardInputSystem* GetKeyboard() override { return &m_Keyboard; }
    virtual IMouseInputSystem* GetMouse() override { return &m_Mouse; }
    virtual void Update() override;

private:
    KeyboardInputSystem m_Keyboard;
    MouseInputSystem m_Mouse;
    std::shared_ptr<InputDebuggerWindow> m_pDbgWindow;
};

} // namespace Input
