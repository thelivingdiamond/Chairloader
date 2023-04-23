//
// Created by theli on 4/18/2023.
//

#include <gtest/gtest.h>
#include <LuaUtils.h>
#include <pugixml.hpp>

TEST(LuaUtilsTest, AddXmlNodeAsVariables) {
    lua_State *luaState = luaL_newstate();
    luaL_openlibs(luaState);

    pugi::xml_document doc;
    std::string docString = R"(
    <?xml version="1.0" encoding="UTF-8"?>
    <Author.Test>
        <test type="bool">true</test>
        <test2 type="int">5</test2>
        <test3 type="float">5.5</test3>
        <test4 type="string">"Hello World!"</test4>
        <test5 type="xmlnode">
            <test6 type="bool">true</test6>
            <test7 type="int">5</test7>
            <test8 type="xmlnode">
                <test9 type="bool">true</test9>
                <test10 type="int">5</test10>
            </test8>
        </test5>
    </Author.Test>)";
    pugi::xml_parse_result result = doc.load_string(docString.c_str());

    ASSERT_TRUE(result);
    LuaUtils::AddXmlNodeAsVariables(luaState, doc.child("Author.Test"), "Author.Test");

    int value = luaL_dostring(luaState, "print(G.Author.Test.test)");
    EXPECT_TRUE(LuaUtils::report_errors(luaState, value));

    value = luaL_dostring(luaState, "function dump(o)\n"
                                    "   if type(o) == 'table' then\n"
                                    "      local s = '{ '\n"
                                    "      for k,v in pairs(o) do\n"
                                    "         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n"
                                    "         s = s .. '['..k..'] = ' .. dump(v) .. ','\n"
                                    "      end\n"
                                    "      return s .. '} '\n"
                                    "   else\n"
                                    "      return tostring(o)\n"
                                    "   end\n"
                                    "end\n"
                                    "print(\"G\", dump(G))");
    EXPECT_TRUE(LuaUtils::report_errors(luaState, value));


    value = luaL_dostring(luaState, "print(G.Author.Test.test5.test8.test10)");
    EXPECT_TRUE(LuaUtils::report_errors(luaState, value));
    auto ref = luabridge::LuaRef(luaState);
    printf("ref: %s\n", ref.tostring().c_str());

    lua_getglobal(luaState, "G");
    lua_getfield(luaState, -1, "Author");
    lua_getfield(luaState, -1, "Test");
    lua_getfield(luaState, -1, "test");
    bool test = lua_toboolean(luaState, -1);
    lua_pop(luaState, 1);
    lua_getfield(luaState, -1, "test2");
    int test2 = lua_tointeger(luaState, -1);
    lua_pop(luaState, 1);
    lua_getfield(luaState, -1, "test3");
    float test3 = lua_tonumber(luaState, -1);
    lua_pop(luaState, 1);
    lua_getfield(luaState, -1, "test4");
    std::string test4 = lua_tostring(luaState, -1);
    lua_pop(luaState, 1);
    lua_getfield(luaState, -1, "test5");
    lua_getfield(luaState, -1, "test6");
    bool test6 = lua_toboolean(luaState, -1);
    lua_pop(luaState, 1);
    lua_getfield(luaState, -1, "test7");
    int test7 = lua_tointeger(luaState, -1);
    lua_pop(luaState, 1);
    lua_getfield(luaState, -1, "test8");
    lua_getfield(luaState, -1, "test9");
    bool test9 = lua_toboolean(luaState, -1);
    lua_pop(luaState, 1);
    lua_getfield(luaState, -1, "test10");
    int test10 = lua_tointeger(luaState, -1);

    ASSERT_TRUE(test);
    ASSERT_EQ(test2, 5);
    ASSERT_EQ(test3, 5.5f);
    ASSERT_EQ(test4, "\"Hello World!\"");
    ASSERT_TRUE(test6);
    ASSERT_EQ(test7, 5);
    ASSERT_TRUE(test9);
    ASSERT_EQ(test10, 5);
    int status = luaL_loadstring(luaState, "return G.Author.Test.test2");
    LuaUtils::report_errors(luaState, status);
    status = lua_pcall(luaState, 0, 1, 0);
    if(!LuaUtils::report_errors(luaState, status)) {
        int test2_2 = lua_tointeger(luaState, -1);
        lua_pop(luaState, 1);
        ASSERT_EQ(test2, test2_2);
    }

    lua_close(luaState);
}


TEST(LuaUtilsTest, SandBoxTest) {
    std::string luaString = R"(
    -- Global table of mod config values
    -- import local mod config values as global variables, but not in the global table G

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

    -- global variables
    x = 10
    z = 20

    -- set the environment for the loaded code to the sandbox
    local f = load(code, "sandbox code", "t", sandbox)
    result = f()
    )";


    lua_State *luaState = luaL_newstate();
    luaL_openlibs(luaState);

    // create the code variable in the global environment so that it can be accessed by the sandbox, and then set it to the code to be run, i.e.
    std::string localCode = R"(
    local code = [[ return "Apple Bottom " .. tostring(x + z)]]
    )";
    std::string expression = R"(local expr = [[return x+z > 10]])";
    luaL_Buffer b;
    luaL_buffinit(luaState, &b);
    luaL_addstring(&b, localCode.c_str());
    luaL_addstring(&b, luaString.c_str());
    luaL_addstring(&b, expression.c_str());
    luaL_pushresult(&b);
    luabridge::getGlobalNamespace(luaState).beginNamespace("G").endNamespace();
    int value = luaL_dostring(luaState, lua_tostring(luaState, -1));
    bool success = LuaUtils::report_errors(luaState, value);
    if(success) {
//    retrieve the result of the sandboxed code
        lua_getglobal(luaState, "result");
        if (luabridge::isInstance<bool>(luaState, -1)) {
            bool success = luabridge::Stack<bool>::get(luaState, -1);
            printf("success bool: %s", success ? "true" : "false");
        } else if (luabridge::isInstance<int>(luaState, -1)) {
            int success = luabridge::Stack<int>::get(luaState, -1);
            printf("success int: %d", success);
        } else if (luabridge::isInstance<std::string>(luaState, -1)) {
            std::string success = luabridge::Stack<std::string>::get(luaState, -1);
            printf("success string: %s", success.c_str());
        } else {
            printf("success default: %s", lua_tostring(luaState, -1));
        }
    } else {
        printf("failed");
    }
}


TEST(LuaUtilsTest, CPPSandboxSetup){
    // set up the sandbox environment through cpp

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    // Load and run the Lua code
    luaL_dostring(L, "foo = 42");
    luaL_dostring(L, "print(foo)");

    // Try to set a global variable, which should result in an error
    luaL_dostring(L, "bar = 1");

    lua_close(L);

}
