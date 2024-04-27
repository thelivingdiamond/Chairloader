#pragma once
#include <random>
#include <ChairMerger/AttributeWildcard.h>
#include <ChairMerger/Export.h>
#include <ChairMerger/LuaUtils.h>
#include <Manager/ILogger.h>
#include <Manager/ModConfig.h>

struct IChairManager;

class CHAIRMERGER_EXPORT WildcardResolver
{
public:
    struct Callbacks
    {
        std::function<bool(const std::string& modName)> fnIsModEnabled;
    };

    WildcardResolver(ILogger* pLogger, const Callbacks& callbacks, std::mt19937& rng, const std::string& modName);
    ~WildcardResolver();

    //! Adds a mod config to Lua as a new global table.
    void AddModConfig(const std::string& modName, const pugi::xml_node& configNode);
    void AddModConfig(const ModConfig& modConfig);

    //! Adds a mod config properties as global variables.
    void AddGlobalModConfig(const std::string& modName, const pugi::xml_node& configNode);
    void AddGlobalModConfig(const ModConfig& modConfig);

    //! Adds an Name -> Id map to the Lua.
    //! Name looks like "Ark.Game.Mission.MissionName".
    //! Tables are created for each part of the name.
    void AddIdNameMap(const std::map<std::string, uint64_t>& nameMap);

    //! Resolves wildcards for an XML document.
    void ResolveDocumentWildcards(pugi::xml_node docNode);

private:
    ILogger* m_pLog = nullptr;
    Callbacks m_Callbacks;
    std::mt19937* m_pRng = nullptr;
    std::string m_ModName;
    std::unique_ptr<lua_State, decltype(&lua_close)> m_pLuaState;

    void InitLuaState();
    void AddLuaFuncs();

    //! Recursive function to descend an xml node tree and find all attribute wildcards
    void ResolveAttributeWildcards(pugi::xml_node node);

    //! Updates wildcard based on attribute contents.
    bool GetAttributeWildcardValue(AttributeWildcard& wildcard);
};
