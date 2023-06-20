#pragma once

//! ScriptWarning (that logs Lua errors) is removed in release builds of CryEngine.
//! This patch adds logging to CryScriptSystem.dll.
class LuaWarnPatch
{
public:
    static void InitSystem();
};
