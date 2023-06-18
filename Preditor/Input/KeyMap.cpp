#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryString/UnicodeFunctions.h>
#include "KeyMap.h"

Input::KeyMap::KeyMap()
{
    LoadKeyMap();
    LoadModifiers();
    LoadDisplayNames();
}

const KeyInfo* Input::KeyMap::GetKeyInfo(EKeyId id)
{
    if (id < 0 || id > MAX_KEY)
        return nullptr;
    else
        return m_IdToInfo[id];
}

const KeyInfo* Input::KeyMap::FindKeyByName(std::string_view name)
{
    auto it = m_NameToInfo.find(name);

    if (it == m_NameToInfo.end())
        return nullptr;
    else
        return it->second;
}

const ModifierKeyInfo& Input::KeyMap::GetModifierInfo(EModifierId id)
{
    return m_Modifiers[(int)id];
}

void Input::KeyMap::LoadKeyMap()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file((gPreditor->pConfig->GetPreditorRoot() / KEY_MAP_PATH).c_str());

    if (!result)
        CryFatalError("KeyMap: Failed to load {}: {}", KEY_MAP_PATH, result.description());

    for (pugi::xml_node node : doc.first_child())
    {
        KeyInfo info;
        info.id = (EKeyId)node.attribute("id").as_uint(eKI_Unknown);
        info.name = node.attribute("name").as_string();
        info.isBindable = node.attribute("isBindable").as_bool();
        info.vkCode = node.attribute("vkCode").as_uint();

        if (info.id == eKI_Unknown)
            CryFatalError("KeyMap: Key with unknown id: {}", info.name);

        m_Keys.push_back(info);
    }

    m_Keys.shrink_to_fit();
    m_IdToInfo.resize(MAX_KEY);

    for (KeyInfo& keyInfo : m_Keys)
    {
        if (keyInfo.id < 0 || keyInfo.id >= MAX_KEY)
            CryFatalError("KeyMap: Key with invalid id: {} - {}", keyInfo.name, (int)keyInfo.id);
        m_IdToInfo[keyInfo.id] = &keyInfo;
        m_NameToInfo.insert({ keyInfo.name, &keyInfo });
    }
}

void Input::KeyMap::LoadModifiers()
{
    m_Modifiers[(int)EModifierId::Ctrl].name = "ctrl";
    m_Modifiers[(int)EModifierId::Alt].name = "alt";
    m_Modifiers[(int)EModifierId::Shift].name = "shift";

    // Set isModifier on keys
    std::string_view keys[] = {
        "lctrl", "rctrl",
        "lshift", "rshift",
        "lalt", "ralt",
    };

    for (std::string_view keyName : keys)
    {
        auto it = m_NameToInfo.find(keyName);

        if (it == m_NameToInfo.end())
            CryFatalError("KeyMap: modifier key '{}' not found", keyName);

        it->second->isModifier = true;
    }
}

void Input::KeyMap::LoadDisplayNames()
{
    for (KeyInfo& keyInfo : m_Keys)
    {
        if (!keyInfo.displayName.empty())
            continue;

        // Default
        keyInfo.displayName = keyInfo.name;

        if (keyInfo.vkCode == 0)
            CryFatalError("KeyMap: Virtual key code not set: {}", keyInfo.name);

        // Convert to scancode
        UINT scanCode = MapVirtualKeyW(keyInfo.vkCode, MAPVK_VK_TO_VSC);

        // Get string
        wchar_t keyName[32];
        if (!GetKeyNameTextW(scanCode << 16, keyName, std::size(keyName)))
        {
            CryError("KeyMap: GetKeyNameTextW failed: {}, {}", keyInfo.name, scanCode);
            continue;
        }

        wstring keyName2 = keyName;
        Unicode::Convert(keyInfo.displayName, keyName2);
    }

    m_Modifiers[(int)EModifierId::Ctrl].displayName = "Ctrl";
    m_Modifiers[(int)EModifierId::Alt].displayName = "Alt";
    m_Modifiers[(int)EModifierId::Shift].displayName = "Shift";
}
