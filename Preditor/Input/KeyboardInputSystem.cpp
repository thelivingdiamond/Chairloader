#include "KeyboardInputSystem.h"
#include "KeyBind.h"

Input::KeyboardInputSystem::KeyboardInputSystem()
{
    LoadActionSets();
    ReloadKeybinds();
}

void Input::KeyboardInputSystem::Update()
{
    m_CurrentFrame++;

    // Process events
    for (const KeyEventArgs& keyEvent : m_EventQueue)
        ProcessKeyEvent(keyEvent);

    m_EventQueue.clear();
}

IKeyActionSet* Input::KeyboardInputSystem::FindActionSet(std::string_view name)
{
    auto it = m_ActionSetsByName.find(name);
    if (it != m_ActionSetsByName.end())
        return it->second;
    else
        return nullptr;
}

IKeyAction* Input::KeyboardInputSystem::FindAction(std::string_view path, bool silent)
{
    size_t dot = path.find('.');

    if (dot != std::string_view::npos)
    {
        std::string_view actionSetName = path.substr(0, dot);
        std::string_view actionName = path.substr(dot + 1);

        IKeyActionSet* pActionSet = FindActionSet(actionSetName);
        if (pActionSet)
        {
            IKeyAction* pAction = pActionSet->FindAction(actionName);
            if (pAction)
                return pAction;
        }
    }

    if (!silent)
        CryError("KeyboardInputSystem: Action '{}' not found", path);

    return nullptr;
}

void Input::KeyboardInputSystem::ReloadKeybinds()
{
    // Unpress all keys
    for (auto& pActionSet : m_ActionSets)
        pActionSet->ResetPressed();

    m_KeyBinds.clear();
    m_KeyBinds.resize(m_KeyMap.GetKeyCount());
    m_NextBindId = 1;

    LoadDefaultKeybinds();
    LoadUserKeybinds();

    // Sort binds by priority
    for (KeyBindList& list : m_KeyBinds)
    {
        auto fnCompare = [](KeyActionBind& lhs, KeyActionBind& rhs)
        {
            // Priority
            int lhsPrio = lhs.GetActionSet()->GetPriority();
            int rhsPrio = rhs.GetActionSet()->GetPriority();
            if (lhsPrio > rhsPrio)
                return true;
            else if (lhsPrio < rhsPrio)
                return false;

            // Modifier count
            int lhsCount = CountModifiers(lhs.GetModMask());
            int rhsCount = CountModifiers(rhs.GetModMask());
            return lhsCount > lhsCount;
        };

        std::sort(list.bindList.begin(), list.bindList.end(), fnCompare);
    }
}

void Input::KeyboardInputSystem::UpdateModMask(ModifierKeyMask modMask)
{
    m_ModMask = modMask;
}

void Input::KeyboardInputSystem::OnKeyDown(EKeyId keyId)
{
    m_EventQueue.push_back(KeyEventArgs{ keyId, true });
}

void Input::KeyboardInputSystem::OnKeyUp(EKeyId keyId)
{
    m_EventQueue.push_back(KeyEventArgs{ keyId, false });
}

void Input::KeyboardInputSystem::LoadActionSets()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file((gPreditor->pConfig->GetPreditorRoot() / ACTION_SETS_PATH).c_str());

    if (!result)
        CryFatalError("KeyboardInputSystem: Failed to load {}: {}", ACTION_SETS_PATH, result.description());

    m_DefaultPriority = doc.first_child().attribute("defaultPriority").as_int(50);

    for (pugi::xml_node node : doc.first_child())
    {
        m_ActionSets.emplace_back(std::make_unique<KeyActionSet>(this, node));
    }

    for (auto& pActionSet : m_ActionSets)
    {
        if (auto it = m_ActionSetsByName.find(pActionSet->GetName()); it != m_ActionSetsByName.end())
            CryFatalError("KeyboardInputSystem: duplicate action set '{}'", pActionSet->GetName());
        m_ActionSetsByName[pActionSet->GetName()] = pActionSet.get();
    }
}

void Input::KeyboardInputSystem::LoadDefaultKeybinds()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file((gPreditor->pConfig->GetPreditorRoot() / ACTION_SETS_PATH).c_str());

    if (!result)
    {
        CryError("KeyboardInputSystem: Failed to load {}: {}", ACTION_SETS_PATH, result.description());
        return;
    }

    // Action set
    for (pugi::xml_node actionSetNode : doc.first_child())
    {
        const char* actionSetName = actionSetNode.attribute("name").as_string();
        KeyActionSet* pActionSet = static_cast<KeyActionSet*>(FindActionSet(actionSetName));

        if (!pActionSet)
        {
            CryError("LoadDefaultKeybinds: Action set '{}' not found", actionSetName);
            continue;
        }

        // Actions
        for (pugi::xml_node actionNode : actionSetNode)
        {
            const char* actionName = actionNode.attribute("name").as_string();
            KeyAction* pAction = static_cast<KeyAction*>(pActionSet->FindAction(actionName));

            if (!pActionSet)
            {
                CryError("LoadDefaultKeybinds: Action '{}.{}' not found", actionSetName, actionName);
                continue;
            }

            // Binds
            for (pugi::xml_node bindNode : actionNode.children("Bind"))
            {
                KeyBind bind;
                const char* keyName = bindNode.attribute("key").as_string();
                
                if (!bind.TryParse(keyName, &m_KeyMap))
                {
                    CryError("LoadDefaultKeybinds: Action '{}.{}': invalid bind '{}'", actionSetName, actionName, keyName);
                    continue;
                }

                AddBind(bind, pAction);
            }
        }
    }
}

void Input::KeyboardInputSystem::LoadUserKeybinds()
{
    // TODO 2023-06-18
}

void Input::KeyboardInputSystem::AddBind(const KeyBind& bind, KeyAction* pAction)
{
    assert(bind.pKey);
    KeyBindList& list = m_KeyBinds[bind.pKey->internalIdx];
    list.bindList.emplace_back(m_NextBindId, bind, pAction);
    m_NextBindId++;
}

Input::KeyboardInputSystem::KeyBindList* Input::KeyboardInputSystem::GetBindList(EKeyId keyId)
{
    const KeyInfo* pKey = m_KeyMap.GetKeyInfo(keyId);
    if (!pKey)
        return nullptr;
    return &m_KeyBinds[pKey->internalIdx];
}

void Input::KeyboardInputSystem::ProcessKeyEvent(const KeyEventArgs& ev)
{
    KeyBindList* pList = GetBindList(ev.keyId);
    if (!pList)
        return;

    if (ev.isPressed)
    {
        // Notify the first valid action
        for (KeyActionBind& bind : pList->bindList)
        {
            if (!bind.GetAction()->CanHaveModifiers() || bind.GetModMask() == m_ModMask)
            {
                KeyActionSet* pActionSet = bind.GetActionSet();

                if (pActionSet->IsActive())
                {
                    bind.GetAction()->OnKeyDown(bind.GetBindId());
                    break;
                }
            }
        }
    }
    else
    {
        // Notify all enabled actions
        for (KeyActionBind& bind : pList->bindList)
        {
            KeyActionSet* pActionSet = bind.GetActionSet();

            if (pActionSet->IsActive())
                bind.GetAction()->OnKeyUp(bind.GetBindId());
        }
    }
}

int Input::KeyboardInputSystem::CountModifiers(ModifierKeyMask mask)
{
    int count = 0;

    if (mask & MODIFIER_MASK_CTRL)
        count++;
    if (mask & MODIFIER_MASK_ALT)
        count++;
    if (mask & MODIFIER_MASK_SHIFT)
        count++;

    return count;
}
