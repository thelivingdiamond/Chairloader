#pragma once
#include <Preditor/Input/IKeyActionSet.h>
#include "KeyAction.h"

namespace Input
{

class KeyboardInputSystem;

class KeyActionSet final : public IKeyActionSet
{
public:
    KeyActionSet(KeyboardInputSystem* pParent, pugi::xml_node xml);

    //! Clears pressed state.
    void ResetPressed();

    //! @returns the parent input system.
    KeyboardInputSystem* GetParent() { return m_pParent; }

    bool IsEnabledInGame() { return m_IsEnabledInGame; }

    // IActionSet
    virtual const std::string& GetName() override { return m_Name; }
    virtual void SetActive(bool state) override;
    virtual bool IsActive() override { return m_IsActive; }
    virtual int GetPriority() override { return m_Priority; }
    virtual bool CanHaveModifiers() override { return m_CanHaveModifiers; }
    virtual IKeyAction* FindAction(std::string_view name) override;

private:
    KeyboardInputSystem* m_pParent = nullptr;
    std::string m_Name;
    int m_Priority = -1;
    bool m_CanHaveModifiers = true;
    bool m_IsEnabledInGame = true;
    bool m_IsActive = false;
    std::vector<KeyAction> m_Actions;
    std::map<std::string, KeyAction*, std::less<>> m_ActionsByName;
};

} // namespace Input
