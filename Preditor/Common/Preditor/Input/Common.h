#pragma once
#include <Prey/CryInput/BaseInput.h>

//! A type of modifier key (Ctrl, Alt, Shift).
enum class EModifierId
{
    None,
    Ctrl,
    Alt,
    Shift,
    ModifierCount,
};

//! Info about a modifier key.
struct ModifierKeyInfo
{
    std::string name;
    std::string displayName;
};

//! A single key code info. Loaded from an XML.
struct KeyInfo
{
    //! Key ID
    EKeyId id = eKI_Unknown;

    //! Internal name - lower-case.
    std::string name;

    //! Display name. With case, may be different on different keyboard layouts.
    std::string displayName;

    //! Whether this is a modifier key.
    bool isModifier = false;

    //! Whether the key can have keybinds.
    bool isBindable = false;

    //! Windows virtual key code.
    uint32_t vkCode = 0;
};
