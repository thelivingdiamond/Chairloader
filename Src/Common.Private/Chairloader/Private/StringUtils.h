#pragma once

//! Trims a string view. Removes all chars declared in spaces from start and end.
//! @param  s       Input string. Must not be a temporary.
//! @param  space   String of space characters.
std::string_view TrimStringView(std::string_view s, const char* spaces = " \r\n\t\v");
