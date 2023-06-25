#pragma once

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

} // namespace Assets
