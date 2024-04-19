#pragma once
#include <Preditor/Input/IKeyAction.h>

namespace Input
{

class KeyActionSet;
class KeyboardInputSystem;
class KeyBind;

class KeyAction final : public IKeyAction
{
public:
    KeyAction(KeyActionSet* pParent, pugi::xml_node xml);

    //! Clears pressed state.
    void ResetPressed();

    //! Called when the bound key is pressed down.
    void OnKeyDown(unsigned bindId);

    //! Called when the bound key is released.
    void OnKeyUp(unsigned bindId);

    //! Removes the shortcut string.
    void ResetShortcut();

    //! Sets the shortcut.
    void SetShortcut(const KeyBind& bind);

    // IAction
    virtual const std::string& GetName() override { return m_Name; }
    virtual const std::string& GetUIShortcut() override { return m_UIShortcut; }
    virtual IKeyActionSet* GetActionSet() override { return m_pParent; }
    virtual ListenerId AddListener(const ActionListener& listener) override { return m_Listeners.Add(listener); }
    virtual bool RemoveListener(ListenerId id) override { return m_Listeners.Remove(id); }
    virtual bool IsHeldDown() override { return m_PressedFrame != NOT_PRESSED_FRAME; }
    virtual bool IsPressed() override;
    virtual bool IsModifier() override { return m_IsModifier; }
    virtual bool CanHaveModifiers() override { return m_CanHaveModifiers; }
    virtual bool IsEnabledInGame() override { return m_IsEnabledInGame; }

private:
    //! Frame index for not triggered action.
    static constexpr unsigned NOT_PRESSED_FRAME = 0;

    //! Bind index for not triggered action.
    static constexpr unsigned NOT_PRESSED_BIND = 0;

    //! Maximum number of binds that can trigger an action at the same time.
    static constexpr unsigned MAX_BINDS_PER_ACTION = 4;

    KeyboardInputSystem* m_pSystem = nullptr;
    IKeyActionSet* m_pParent = nullptr;
    std::string m_Name;
    std::string m_UIShortcut;
    bool m_IsModifier = false;
    bool m_CanHaveModifiers = true;
    bool m_IsEnabledInGame = true;
    ListenerSet<const KeyActionEventArgs&> m_Listeners;

    //! The frame that the action was triggered.
    unsigned m_PressedFrame = NOT_PRESSED_FRAME;

    //! IDs of binds that currently trigger the action.
    unsigned m_HeldBinds[MAX_BINDS_PER_ACTION] = { 0 };

    void InvokeListeners(bool isPressed);
};

} // namespace Input
