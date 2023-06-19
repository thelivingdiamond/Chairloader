#include "KeyActionBind.h"

Input::KeyActionBind::KeyActionBind(unsigned bindId, const KeyBind& bind, KeyAction* pAction)
{
    m_pAction = pAction;
    m_pActionSet = static_cast<KeyActionSet*>(pAction->GetActionSet());
    m_BindId = bindId;
    m_KeyId = bind.pKey->id;
    m_ModMask = bind.modifiers;

    if (bind.pKey->modifierId != EModifierId::None)
    {
        // When pressing a modifier key bind, the modifier bit for the key will be set
        // ModMask must include it.
        m_ModMask |= 1 << (((int)bind.pKey->modifierId) - 1);
    }
}
