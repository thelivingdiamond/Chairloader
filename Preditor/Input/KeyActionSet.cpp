#include "KeyActionSet.h"
#include "KeyboardInputSystem.h"

Input::KeyActionSet::KeyActionSet(KeyboardInputSystem* pParent, pugi::xml_node xml)
{
    m_pParent = pParent;
    m_Name = xml.attribute("name").as_string();
    m_Priority = xml.attribute("priority").as_int(pParent->GetDefaultPriority());
    m_CanHaveModifiers = xml.attribute("canHaveModifiers").as_bool(true);
    m_IsEnabledInGame = xml.attribute("enableInGame").as_bool(false);

    for (pugi::xml_node node : xml)
    {
        m_Actions.emplace_back(this, node);
    }

    for (KeyAction& actions : m_Actions)
    {
        if (auto it = m_ActionsByName.find(actions.GetName()); it != m_ActionsByName.end())
            CryFatalError("KeyActionSet: duplicate action '{}.{}'", GetName(), actions.GetName());
        m_ActionsByName[actions.GetName()] = &actions;
    }

    SetActive(xml.attribute("startActive").as_bool(true));
}

void Input::KeyActionSet::ResetPressed()
{
    for (KeyAction& action : m_Actions)
        action.ResetPressed();
}

void Input::KeyActionSet::SetActive(bool state)
{
    if (m_IsActive != state)
    {
        if constexpr (PREDITOR_INPUT_DEBUG)
            CryLog("[KeyActionSet] [{}] Active: {}", GetName(), state);

        m_IsActive = state;

        // Unpress actions when deactivating
        if (!state)
            ResetPressed();
    }
}

IKeyAction* Input::KeyActionSet::FindAction(std::string_view name)
{
    auto it = m_ActionsByName.find(name);
    if (it != m_ActionsByName.end())
        return it->second;
    else
        return nullptr;
}
