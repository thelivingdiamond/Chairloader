//
// Created by theli on 4/18/2023.
//

#ifndef CHAIRLOADER_LUAUTILS_H
#define CHAIRLOADER_LUAUTILS_H

#pragma once

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <LuaBridge/LuaBridge.h>
#include <variant>


namespace LuaUtils {
    inline bool report_errors(lua_State *luaState, int status) {
        if (status == 0) {
            return true;
        }

        std::cerr << "[LUA ERROR] " << lua_tostring(luaState, -1) << std::endl;

        // remove error message from Lua state
        lua_pop(luaState, 1);
        return false;
    }

    void AddXmlNodeAsVariables(lua_State *luaState, pugi::xml_node node, std::string modName, bool bGlobal = true);

    void CreateModNameTable(lua_State *luaState, std::string modName);

    std::string EvaulateWildcardExpression(std::string modName, std::string wildcardExpression);


    static inline const std::string SandboxString =
R"(
-- create a new environment for the sandbox
local sandbox = {}

-- set the metatable for the sandbox environment to make variables read-only
debug.setmetatable(sandbox, {
        __index = function(_, key)
        return _G[key]
        end,
        __newindex = function(_, key, value)
        error("Attempt to write to global variable '" .. key .. "'", 2)
        end,
        __metatable = false
})
-- set the environment for the loaded code to the sandbox
local f = load(code, "sandbox code", "t", sandbox)
-- run the code in the sandbox environment
-- store the result in a global variable so we can access it later
result = f()
)";

    static inline const std::string GetExpressionCodeString(std::string expression) {
        // check if there is a return statement in the expression, if not, add one
        if (expression.find("return") == std::string::npos) {
            return "code = [[ return (" + expression + ") ]]\n";
        } else {
            return "code = [[ " + expression + " ]]\n";
        }

    }
};


#endif //CHAIRLOADER_LUAUTILS_H
