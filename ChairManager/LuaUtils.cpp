//
// Created by theli on 4/18/2023.
//

#include "LuaUtils.h"



// for a given xml node tree, we need to reconstruct the xml structure using namespaces and variables
// this is a recursive function
// the very first node should be a namespace, and subsequent nodes should be variables
// the type is stored in the "type" attribute
// the value is in the text of the node

//* Example:
// <Test>
//     <test type="bool">true</test>
//     <test2 type="int">5</test2>
//     <test3 type="float">5.5</test3>
//     <test4 type="string">"Hello World!"</test4>
//     <test5 type="xmlnode">
//         <test6 type="bool">true</test6>
//         <test7 type="int">5</test7>
//     </test5>
// </Test>

// this should turn into the following lua variables:
// Test = {}
// Test.test = true
// Test.test2 = 5
// Test.test3 = 5.5
// Test.test4 = "Hello World!"
// Test.test5 = {}
// Test.test5.test6 = true
// Test.test5.test7 = 5


void convertXmlNodeToLuaTable(lua_State* L, pugi::xml_node node, luabridge::LuaRef& table)
{
    // Traverse the XML node to extract the data you want to convert to Lua variables.
    for (auto child : node.children()) {
        std::string name = child.name();
        std::string type = child.attribute("type").value();

        if(type == "xmlnode"){
            // If the child node has child nodes, create a new Lua table and call this function recursively.
            luabridge::LuaRef childTable = luabridge::newTable(L);
            convertXmlNodeToLuaTable(L, child, childTable);

            // Set the child node's name and the Lua table as a key-value pair in the parent table.
            table[name.c_str()] = childTable;
        } else if (type == "bool"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            bool value = child.text().as_bool();
            table[name.c_str()] = value;
        } else if (type == "int"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            auto value = child.text().as_int();
            table[name.c_str()] = value;
        } else if (type == "uint"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            auto value = child.text().as_uint();
            table[name.c_str()] = value;
        } else if (type == "int64"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            auto value = child.text().as_string();
            table[name.c_str()] = value;
        } else if (type == "uint64"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            auto value = child.text().as_string();
            table[name.c_str()] = value;
        } else if (type == "float"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            auto value = child.text().as_float();
            table[name.c_str()] = value;
        } else if (type == "string"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            std::string value = child.text().as_string();
            table[name.c_str()] = value;
        //TODO: typed enums
        } else if (type == "enum"){
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            std::string value = child.child("selected").text().as_string();
            table[name.c_str()] = value;
            luabridge::LuaRef enumTable = luabridge::newTable(L);
            int i = 0;
            for(auto& enumChild: child.children("option")){
                std::string enumName = "option" + std::to_string(i++);
                std::string enumValue = enumChild.text().as_string();
                enumTable[enumName.c_str()] = enumValue;
            }
            table[(name + "_enum").c_str()] = enumTable;
        } else {
            // If the child node has no child nodes, set its value as a key-value pair in the parent table.
            std::string value = child.text().as_string();
            table[name.c_str()] = value;
        }
    }
}


// xmlnode, bool, int, uint, int64, uint64, float, string, enum(of type)
void LuaUtils::AddXmlNodeAsVariables(lua_State *luaState, pugi::xml_node node, std::string modName, bool bGlobal) {
    if(bGlobal) {
        // Create a new Lua table with the name of the mod.
        luabridge::LuaRef table = luabridge::newTable(luaState);
        // Call the recursive function to convert the XML node to a Lua table.
        convertXmlNodeToLuaTable(luaState, node, table);
        // Set the the mod name table i.e. G.com.example.mod as a global variable.
        CreateModNameTable(luaState, modName);

        // add the table to the mod name table
        auto g = luabridge::getGlobal(luaState, "G");
        // mod name may contain . characters, which are not allowed in lua variable names. So we must parse each part of the name to be a subtable
        // for example, if the mod name is "com.example.mod", we need to get the following table:
        // G.com.example.mod
        std::vector<std::string> modNameParts;
        std::string delimiter = ".";
        size_t pos = 0;
        std::string token;
        while ((pos = modName.find(delimiter)) != std::string::npos) {
            token = modName.substr(0, pos);
            modNameParts.push_back(token);
            modName.erase(0, pos + delimiter.length());
        }

        luabridge::LuaRef modNameTable = luabridge::getGlobal(luaState, "G");
        for (auto part: modNameParts) {
            modNameTable = modNameTable[part.c_str()];
            if (modNameTable.isNil())
                throw std::runtime_error("mod name table is nil");
        }
        modNameTable[modName] = table;
    } else {
        for(auto& child: node.children()){
            std::string name = child.name();
            std::string type = child.attribute("type").value();

            if(type == "xmlnode"){
                // If the child node has child nodes, create a new Lua table and call this function recursively.
                luabridge::LuaRef childTable = luabridge::newTable(luaState);
                convertXmlNodeToLuaTable(luaState, child, childTable);
                luabridge::setGlobal(luaState, childTable, name.c_str());
            } else if (type == "bool"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                bool value = child.text().as_bool();
                luabridge::setGlobal(luaState, value, name.c_str());
            } else if (type == "int"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                auto value = child.text().as_int();
                luabridge::setGlobal(luaState, value, name.c_str());
            } else if (type == "uint"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                auto value = child.text().as_uint();
                luabridge::setGlobal(luaState, value, name.c_str());
            } else if (type == "int64"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                std::string value = child.text().as_string();
                luabridge::setGlobal(luaState, value, name.c_str());
            } else if (type == "uint64"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                std::string value = child.text().as_string();
                luabridge::setGlobal(luaState, value, name.c_str());
            } else if (type == "float"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                auto value = child.text().as_float();
                luabridge::setGlobal(luaState, value, name.c_str());
            } else if (type == "string"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                std::string value = child.text().as_string();
                luabridge::setGlobal(luaState, value, name.c_str());
                //TODO: typed enums
            } else if (type == "enum"){
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                std::string value = child.child("selected").text().as_string();
                luabridge::setGlobal(luaState, value, name.c_str());
                // add the enum values in name_enum table
                luabridge::LuaRef enumTable = luabridge::newTable(luaState);
                int i = 0;
                for(auto& enumChild: child.children("option")){
                    std::string enumName = "option" + std::to_string(i++);
                    std::string enumValue = enumChild.text().as_string();
                    enumTable[enumName.c_str()] = enumValue;
                }
                luabridge::setGlobal(luaState, enumTable, (name + "_enum").c_str());
            } else {
                // If the child node has no child nodes, set its value as a key-value pair in the parent table.
                std::string value = child.text().as_string();
               luabridge::setGlobal(luaState, value, name.c_str());
            }
        }
    }
}

void LuaUtils::CreateModNameTable(lua_State *luaState, std::string modName) {
    // the mod name may contain . characters, which are not allowed in lua variable names. So we must parse each part of the name to be a subtable
    // for example, if the mod name is "com.example.mod", we need to create the following table:
    // G.com = {}
    // G.com.example = {}
    // G.com.example.mod = {}

    // first, we need to split the mod name into its parts
    std::vector<std::string> modNameParts;
    std::string delimiter = ".";

    size_t pos = 0;
    std::string token;
    while ((pos = modName.find(delimiter)) != std::string::npos) {
        token = modName.substr(0, pos);
        modNameParts.push_back(token);
        modName.erase(0, pos + delimiter.length());
    }
    modNameParts.push_back(modName);

    // now we need to double check we have a global table called G
    luabridge::LuaRef globalTable = luabridge::getGlobal(luaState, "G");
    if(globalTable.isNil()){
        globalTable = luabridge::newTable(luaState);
        luabridge::setGlobal(luaState, globalTable, "G");
    }

    auto table = luabridge::getGlobal(luaState, "G");
    for(int i = 0; i < modNameParts.size(); i++){
        table[modNameParts[i].c_str()] = luabridge::newTable(luaState);
        table = table[modNameParts[i].c_str()];
    }
}

void LuaUtils::AddVariableWithPath(lua_State *luaState, std::string path, std::string value, char delimiter) {
    // the path will be a string like "Ark.Game.Mission.MissionName" and we need to get, or create tables up to the last part of the path, and then add the value to that table under the last part of the path

    // first, we need to split the path into its parts
    std::vector<std::string> pathParts;

    size_t pos = 0;
    std::string token;
    while ((pos = path.find(delimiter)) != std::string::npos) {
        token = path.substr(0, pos);
        pathParts.push_back(token);
        path.erase(0, pos + 1);
    }
    pathParts.push_back(path);

    // now iterate through the path parts, creating tables as needed until we get to the last part, where we add the value
    // start with the first part of the path
    auto table = luabridge::getGlobal(luaState, pathParts[0].c_str());
    // if the table doesn't exist, create it
    if(table.isNil()){
        table = luabridge::newTable(luaState);
        luabridge::setGlobal(luaState, table, pathParts[0].c_str());
    }
    // iterate through the rest of the path parts, except the last one
    for(int i = 1; i < pathParts.size() - 1; i++){
        // if the table doesn't exist, create it
        if(table[pathParts[i].c_str()].isNil()){
            table[pathParts[i].c_str()] = luabridge::newTable(luaState);
        }
        // set the table to the next part of the path
        table = table[pathParts[i].c_str()];
    }

    // now we can add the value to the table
    table[pathParts[pathParts.size() - 1].c_str()] = value;

    // success! (hopefully)

}

