#include "KeyActionBind.h"

Input::KeyActionBind::KeyActionBind(unsigned bindId, const KeyBind& bind, KeyAction* pAction)
{
    m_pAction = pAction;
    m_pActionSet = static_cast<KeyActionSet*>(pAction->GetActionSet());
    m_BindId = bindId;
    m_KeyId = bind.pKey->id;
    m_ModMask = bind.modifiers;
}
