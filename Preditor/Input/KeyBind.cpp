#include <Preditor/Input/IKeyMap.h>
#include "KeyBind.h"

bool Input::KeyBind::TryParse(std::string_view bindStr, IKeyMap* pKeyMap)
{
    std::string key;
    ModifierKeyMask mask = MODIFIER_MASK_NONE;

    size_t begin = 0;

    for (size_t i = 0; i <= bindStr.size(); i++)
    {
        char c = i < bindStr.size() ? bindStr[i] : '\0';

        if (c == '+' || c == '\0')
        {
            std::string_view segment = bindStr.substr(begin, i - begin);

            if (segment.empty())
                return false;

            if (segment == "ctrl")
            {
                mask |= MODIFIER_MASK_CTRL;
            }
            else if (segment == "alt")
            {
                mask |= MODIFIER_MASK_ALT;
            }
            else if (segment == "shift")
            {
                mask |= MODIFIER_MASK_SHIFT;
            }
            else if (key.empty())
            {
                key = segment;
            }
            else
            {
                // Duplicate key name
                return false;
            }

            begin = i + 1;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            // A valid char. Go to the next one
        }
        else
        {
            // Invalid char
            return false;
        }
    }

    if (pKeyMap)
    {
        // Try to find the key
        pKey = pKeyMap->FindKeyByName(key);
        if (!pKey)
        {
            // Key not found
            return false;
        }
    }
    else
    {
        pKey = nullptr;
    }

    keyName = key;
    modifiers = mask;
    return true;
}

std::string Input::KeyBind::ToString()
{
    std::string s;

    if (modifiers & MODIFIER_MASK_CTRL)
        s += "ctrl+";
    if (modifiers & MODIFIER_MASK_ALT)
        s += "alt+";
    if (modifiers & MODIFIER_MASK_SHIFT)
        s += "shift+";

    return s + keyName;
}
