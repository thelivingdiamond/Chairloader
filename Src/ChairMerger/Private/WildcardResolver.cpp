#include <regex>
#include <Manager/IChairManager.h>
#include <ChairMerger/WildcardResolver.h>

WildcardResolver::WildcardResolver(IChairManager* pChair, std::mt19937& rng, const std::string& modName)
    : m_pLuaState(nullptr, nullptr)
{
    m_pChair = pChair;
    m_pRng = &rng;
    m_ModName = modName;
    InitLuaState();
    AddLuaFuncs();
}

WildcardResolver::~WildcardResolver()
{
}

void WildcardResolver::AddModConfig(const std::string& modName, const pugi::xml_node& configNode)
{
    LuaUtils::AddXmlNodeAsVariables(m_pLuaState.get(), configNode, modName);
}

void WildcardResolver::AddModConfig(const ModConfig& modConfig)
{
    AddModConfig(modConfig.modName, modConfig.configNode);
}

void WildcardResolver::AddGlobalModConfig(const std::string& modName, const pugi::xml_node& configNode)
{
    LuaUtils::AddXmlNodeAsVariables(m_pLuaState.get(), configNode, modName, false);
}

void WildcardResolver::AddGlobalModConfig(const ModConfig& modConfig)
{
    AddGlobalModConfig(modConfig.modName, modConfig.configNode);
}

void WildcardResolver::AddIdNameMap(const std::map<std::string, uint64_t>& nameMap)
{
    //    // profile this function to see if it's slow
    //    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& pair : nameMap)
    {
        LuaUtils::AddVariableWithPath(m_pLuaState.get(), pair.first, std::to_string(pair.second));
    }

    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //    ChairManager::Get().log(severityLevel::trace, "ChairMerger: Added id name map to lua in %llu milliseconds", elapsed.count());
}

void WildcardResolver::ResolveDocumentWildcards(pugi::xml_node docNode)
{
    ResolveAttributeWildcards(docNode);
}

void WildcardResolver::InitLuaState()
{
    m_pLuaState = std::unique_ptr<lua_State, decltype(&lua_close)>(luaL_newstate(), &lua_close);
    luaL_openlibs(m_pLuaState.get());
}

void WildcardResolver::AddLuaFuncs()
{
    lua_State* L = m_pLuaState.get();

    luabridge::getGlobalNamespace(L).addFunction("IsModEnabled",
        std::function([this](std::string modName)
        {
            return m_pChair->IsModEnabled(modName);
        }));

    luabridge::getGlobalNamespace(L).addFunction("Random",
        std::function([this](int min, int max)
        {
            std::uniform_int_distribution<int> distribution(min, max);
            return distribution(*m_pRng);
        }));

    luabridge::getGlobalNamespace(L).addFunction("RandomFloat",
        std::function([this](float min, float max)
        {
            std::uniform_real_distribution<float> distribution(min, max);
            return distribution(*m_pRng);
        }));
}

void WildcardResolver::ResolveAttributeWildcards(pugi::xml_node node)
{
    // iterate over all attributes
    for (auto& attribute : node.attributes())
    {
        AttributeWildcard wildcard;
        wildcard.attribute = attribute;
        wildcard.mod_name = m_ModName;

        if (GetAttributeWildcardValue(wildcard))
            attribute.set_value(wildcard.match_value.c_str());
    }

    // iterate over all child nodes
    for (auto& childNode : node.children())
    {
        // recursively descend the tree
        ResolveAttributeWildcards(childNode);
    }
}

/*! Attribute Wildcards
<X Param="{{ configValue }}" /> <!-- Current mod's config -->
<X Param="{{ $.modAuthor.modName.configValue }}"/> <!-- Reference a different mod. modAuthor.modName is actually "modName" from ModInfo.xml. $ indicates that we are looking in the global space -->
<X ch:apply_if="$.modAuthor.modName.modEnabled" /> <!-- Check if different mod is installed and enabled. Allows for some basic interop between XML mods -->
<X ch:apply_if="{{ configValue }}"/> <!-- apply if some other config value -->
<X ch:remove /> <!-- Remove this node from the XML -->
 <X ch:patch_mode/> <!-- Patch mode: will overwrite all attributes present in the mod node w/out any vanilla checking. -->
 */
bool WildcardResolver::GetAttributeWildcardValue(AttributeWildcard& wildcard)
{
    std::string_view attributeStringVal = wildcard.attribute.value();

    if (attributeStringVal.find("{{") == std::string::npos ||
        attributeStringVal.find("}}") == std::string::npos)
    {
        // No '{{ xxx }}' in the string, not a wildcard.
        wildcard.type = AttributeWildcard::wildcard_type::none;
        return false;
    }

    // Regex to determine if the attribute value is a wildcard
    std::regex re(R"(\{\{(.*)\}\})");
    std::smatch match;
    std::string value = wildcard.attribute.value();

    if (!std::regex_search(value, match, re))
    {
        m_pChair->Log(severityLevel::warning, "Could not find wildcard value in %s", value.c_str());
        wildcard.type = AttributeWildcard::wildcard_type::none;
        return false;
    }

    if (!match.ready())
    {
        // TODO 2023-07-06: No log?
        return false;
    }

    std::string wildcardName;
    wildcardName = match[1].str();

    // setup the lua buffer
    lua_State* L = m_pLuaState.get();
    luaL_Buffer b;
    luaL_buffinit(L, &b);
    luaL_addstring(&b, LuaUtils::GetExpressionCodeString(wildcardName).c_str());
    luaL_addstring(&b, LuaUtils::SandboxString.c_str());
    luaL_pushresult(&b);
    int code = luaL_dostring(L, lua_tostring(L, -1));
    bool success = LuaUtils::report_errors(L, code);
    std::string result;

    if (success)
    {
        lua_getglobal(L, "result");
        if (luabridge::isInstance<bool>(L, -1)) {
            result = luabridge::Stack<bool>::get(L, -1) ? "true" : "false";
            wildcard.match_value = result;
            wildcard.has_match_value = true;
        }
        else if (luabridge::isInstance<float>(L, -1)) {
            result = std::to_string(luabridge::Stack<float>::get(L, -1));
            wildcard.match_value = result;
            wildcard.has_match_value = true;
        }
        else if (luabridge::isInstance<int>(L, -1)) {
            result = std::to_string(luabridge::Stack<int>::get(L, -1));
            wildcard.match_value = result;
            wildcard.has_match_value = true;
        }
        else if (luabridge::isInstance<std::string>(L, -1)) {
            result = luabridge::Stack<std::string>::get(L, -1);
            wildcard.match_value = result;
            wildcard.has_match_value = true;
        }
        else if (luabridge::isInstance<unsigned int>(L, -1)) {
            result = std::to_string(luabridge::Stack<unsigned int>::get(L, -1));
            wildcard.match_value = result;
            wildcard.has_match_value = true;
        }
        else {
            m_pChair->Log(severityLevel::error, "Error evaluating lua expression: %s", wildcardName.c_str());
        }
    }
    else
    {
        m_pChair->Log(severityLevel::error, "Error evaluating lua expression: %s", wildcardName.c_str());
    }

    return wildcard.has_match_value;
}
