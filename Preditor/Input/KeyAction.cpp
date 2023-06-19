#include "KeyAction.h"
#include "KeyActionSet.h"
#include "KeyboardInputSystem.h"

Input::KeyAction::KeyAction(KeyActionSet* pParent, pugi::xml_node xml)
{
    m_pParent = pParent;
    m_pSystem = pParent->GetParent();
    m_Name = xml.attribute("name").as_string();
    m_IsEnabledInGame = xml.attribute("enableInGame").as_bool(pParent->IsEnabledInGame());

    pugi::xml_attribute canHaveModifiers = xml.attribute("canHaveModifiers");
    if (canHaveModifiers)
    {
        if (pParent->CanHaveModifiers())
        {
            m_CanHaveModifiers = canHaveModifiers.as_bool(true);
        }
        else
        {
            CryWarning("[KeyAction] {}.{}: ignoring canHaveModifiers as action set has it set to false",
                m_pParent->GetName(), GetName());
            m_CanHaveModifiers = false;
        }
    }
    else
    {
        // Inherit it
        m_CanHaveModifiers = pParent->CanHaveModifiers();
    }
}

void Input::KeyAction::ResetPressed()
{
    if (m_PressedFrame != NOT_PRESSED_FRAME)
    {
        for (unsigned& i : m_HeldBinds)
            i = NOT_PRESSED_BIND;

        m_PressedFrame = NOT_PRESSED_FRAME;
        InvokeListeners(false);
    }
}

void Input::KeyAction::OnKeyDown(unsigned bindId)
{
    // Register the bind
    for (unsigned& i : m_HeldBinds)
    {
        if (i == NOT_PRESSED_BIND)
        {
            i = bindId;
            break;
        }
    }

    // Notify listeners
    if (m_PressedFrame == NOT_PRESSED_FRAME)
    {
        if constexpr (PREDITOR_INPUT_DEBUG)
            CryLog("[KeyAction] Down: {}.{}, {}", m_pParent->GetName(), GetName(), bindId);

        m_PressedFrame = m_pSystem->GetFrameIndex();
        InvokeListeners(true);
    }
}

void Input::KeyAction::OnKeyUp(unsigned bindId)
{
    // Unregister the bind
    int pressCount = 0;
    for (unsigned& i : m_HeldBinds)
    {
        if (i == bindId)
            i = NOT_PRESSED_BIND;
        else if (i != NOT_PRESSED_BIND)
            pressCount++;
    }

    if (pressCount == 0 && m_PressedFrame != NOT_PRESSED_FRAME)
    {
        if constexpr (PREDITOR_INPUT_DEBUG)
            CryLog("[KeyAction] Up: {}.{}, {}", m_pParent->GetName(), GetName(), bindId);

        m_PressedFrame = NOT_PRESSED_FRAME;
        InvokeListeners(false);
    }
}

bool Input::KeyAction::IsPressed()
{
    return m_PressedFrame == m_pSystem->GetFrameIndex();
}

void Input::KeyAction::InvokeListeners(bool isPressed)
{
    if (m_Listeners.IsNotEmpty())
    {
        KeyActionEventArgs args;
        args.pAction = this;
        args.isPressed = isPressed;
        m_Listeners.Invoke(args);
    }
}
