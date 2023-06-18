#pragma once
#include <Preditor/Input/IKeyMap.h>

namespace Input
{

//! The map of keys on the keyboard.
class KeyMap final : public IKeyMap
{
public:
    KeyMap();

    // IKeyMap
    virtual const KeyInfo* GetKeyInfo(EKeyId id) override;
    virtual const KeyInfo* FindKeyByName(std::string_view name) override;
    virtual const ModifierKeyInfo& GetModifierInfo(EModifierId id) override;

private:
    static constexpr char KEY_MAP_PATH[] = "Preditor/KeyMap.xml";
    static constexpr EKeyId MAX_KEY = eKI_Mouse8;

    ModifierKeyInfo m_Modifiers[(int)EModifierId::ModifierCount];
    std::vector<KeyInfo> m_Keys;
    std::vector<KeyInfo*> m_IdToInfo;
    std::map<std::string, KeyInfo*, std::less<>> m_NameToInfo;

    void LoadKeyMap();
    void LoadModifiers();
};

} // namespace Input
