#pragma once

#ifdef DEBUG_BUILD
// A macro because adds/removes class members.
#define ASSET_MERGE_DEBUG
#endif

namespace Assets
{

constexpr bool ASSETS_DEBUG = true;

using FileModTime = std::chrono::system_clock::duration;

inline char CharToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c = c - 'A' + 'a';

    return c;
}

inline void StrToLower(std::string& s)
{
    for (char& c : s)
    {
        c = CharToLower(c);
    }
}

inline pugi::xml_attribute EnsureAttr(pugi::xml_node node, const char* attrName)
{
    pugi::xml_attribute attr = node.attribute(attrName);

    if (!attr)
        attr = node.append_attribute(attrName);

    return attr;
}

//! Checks if a string ends with a substring.
inline bool EndsWith(std::string_view str, std::string_view substr)
{
    size_t len = substr.size();
    return str.size() >= len && str.substr(str.size() - len, len) == substr;
}

} // namespace Assets
