#pragma once

//! CFileTree::EnumerateScripts incorrectly uses FindFirst and FindNext,
//! causing it to skip the first file/subdirectory in a directory.
class LuaDbgFix
{
public:
    static void InitSystem();
};
