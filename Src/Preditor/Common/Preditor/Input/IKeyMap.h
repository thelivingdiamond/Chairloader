#pragma once
#include <Preditor/Input/Common.h>

//! The map of keys on the keyboard.
struct IKeyMap
{
    virtual ~IKeyMap() {}

    //! Gets the key info for a key.
    //! @returns KeyInfo or nullptr if key not found.
    virtual const KeyInfo* GetKeyInfo(EKeyId id) = 0;

    //! Finds a key by its internal name.
    //! @returns KeyInfo or nullptr if key not found.
    virtual const KeyInfo* FindKeyByName(std::string_view name) = 0;

    //! @returns modifier key info by id.
    virtual const ModifierKeyInfo& GetModifierInfo(EModifierId id) = 0;
};
