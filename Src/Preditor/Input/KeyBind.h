#pragma once
#include <Preditor/Input/Common.h>

struct IKeyMap;

namespace Input
{

struct KeyBind
{
    std::string keyName;
    const KeyInfo* pKey = nullptr;
    ModifierKeyMask modifiers = MODIFIER_MASK_NONE;

    //! Parses a string into key name and modifiers.
    //! On unsuccessfully parse, object is not changed.
    //! @returns true if parsed successfully.
    bool TryParse(std::string_view bindStr, IKeyMap* pKeyMap = nullptr);

    //! Converts the bind into a string for serialization.
    std::string ToString();
};

} // namespace Input
