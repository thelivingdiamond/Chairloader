#pragma once
#include "KeyAction.h"
#include "KeyActionSet.h"
#include "KeyBind.h"

namespace Input
{

//! Binds a specific key combination (key + modifiers) to an action.
class KeyActionBind
{
public:
    KeyActionBind(unsigned bindId, const KeyBind& bind, KeyAction* pAction);

    //! @returns unique action bind ID.
    unsigned GetBindId() { return m_BindId; }

    //! @returns the action to which the key is bound.
    KeyAction* GetAction() { return m_pAction; }

    //! @returns action's set.
    KeyActionSet* GetActionSet() { return m_pActionSet; }

    //! @returns the bind's key id.
    EKeyId GetKeyId() { return m_KeyId; }

    //! @returns the bind's mod mask.
    ModifierKeyMask GetModMask() { return m_ModMask; }

private:
    KeyAction* m_pAction = nullptr;
    KeyActionSet* m_pActionSet = nullptr;
    unsigned m_BindId = 0;
    EKeyId m_KeyId = eKI_Unknown;
    ModifierKeyMask m_ModMask = MODIFIER_MASK_NONE;
};

} // namespace Input
