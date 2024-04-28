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

#include <variant>
#include <LuaBridge/LuaBridge.h>
#include <ChairMerger/Export.h>


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

    void CHAIRMERGER_EXPORT AddXmlNodeAsVariables(lua_State *luaState, pugi::xml_node node, std::string modName, bool bGlobal = true);

    void CHAIRMERGER_EXPORT CreateModNameTable(lua_State *luaState, std::string modName);

    std::string CHAIRMERGER_EXPORT EvaulateWildcardExpression(std::string modName, std::string wildcardExpression);


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
result = tostring(f())
)";

    static inline const std::string GetExpressionCodeString(std::string expression) {
        // check if there is a return statement in the expression, if not, add one
        if (expression.find("return") == std::string::npos) {
            return "code = [[ return (" + expression + ") ]]\n";
        } else {
            return "code = [[ " + expression + " ]]\n";
        }

    }


    static inline std::string MakeValidVariableName(std::string name) {
        // A valid lua variable name must start with a letter or underscore, and can only contain letters, numbers, and underscores
        // If the name starts with a number, we must prepend an underscore
        if(name[0] >= '0' && name[0] <= '9'){
            name = "_" + name;
        }

        // now we need to replace all spaces with underscores
        std::replace(name.begin(), name.end(), ' ', '_');

        // any non alpha-numeric characters must be removed (except underscores)
        name.erase(std::remove_if(name.begin(), name.end(), [](char c) {
            return !std::isalnum(c) && c != '_';
        } ), name.end());

        return name;
    }

    void CHAIRMERGER_EXPORT AddVariableWithPath(lua_State *luaState, std::string path, std::string value, char delimiter = '.');
};


#endif //CHAIRLOADER_LUAUTILS_H
