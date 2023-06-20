#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CryScriptSystem/IScriptSystem.h>
#include <Prey/CryEntitySystem/EntitySystem.h>
#include <Prey/CryEntitySystem/EntityScript.h>
#include <Prey/CryEntitySystem/ScriptBind_Entity.h>
#include "Lua/LuaModManager.h"
#include "Lua/ScriptBind_Chairloader.h"

#define SCRIPT_ONRESET "OnReset"
#define SCRIPT_ONTRANSFORMATION_FROMEDITOR_DONE "OnTransformFromEditorDone"
#define SCRIPT_PROPERTIES_TABLE "Properties"

namespace
{

auto g_CEntityScript_LoadScript_Hook = CEntityScript::FLoadScript.MakeHook();
auto g_CScriptBind_Entity_DelegateCalls_Hook = CScriptBind_Entity::FDelegateCalls.MakeHook();

LuaModManager* g_pInstance = nullptr;
CEntityScript* g_pCurrentEntityScript = nullptr;

bool CEntityScript_LoadScript_Hook(CEntityScript* const _this, bool bForceReload)
{
    if (_this->m_pEntityTable && !bForceReload)
        return true;

    _this->Clear();

    if (!_this->m_pScriptSystem->ExecuteFile(_this->m_sScriptFilename, true, bForceReload))
        return false;

    if (!_this->m_pScriptSystem->GetGlobalValue(_this->m_sTableName, _this->m_pEntityTable))
        return false;

    g_pInstance->HookEntityTable(_this);

    //////////////////////////////////////////////////////////////////////////
    // Delegate call from entity script table to the global entity binded methods.
    //////////////////////////////////////////////////////////////////////////
    auto pEntitySystem = static_cast<CEntitySystem*>(gEnv->pEntitySystem);
    pEntitySystem->m_pEntityScriptBinding->DelegateCalls(_this->m_pEntityTable);

    _this->m_pPropertiesTable = _this->m_pScriptSystem->CreateTable(true);
    _this->m_pPropertiesTable->AddRef();
    if (!_this->m_pEntityTable->GetValue(SCRIPT_PROPERTIES_TABLE, _this->m_pPropertiesTable))
    {
        SAFE_RELEASE(_this->m_pPropertiesTable);
    }

    // Precache of OnReset function.
    _this->m_pEntityTable->GetValue(SCRIPT_ONRESET, _this->m_pOnReset);

    // Precache of OnTransformFromEditorDone function.
    _this->m_pEntityTable->GetValue(SCRIPT_ONTRANSFORMATION_FROMEDITOR_DONE, _this->m_pOnTransformFromEditorDone);

    // Enumerate all states.
    _this->EnumStates();

    // Load all events in entity script.
    _this->LoadEvents();

    _this->m_bScriptLoaded = true;
    return true;
}

} // namespace

LuaModManager::LuaModManager()
{
    assert(!g_pInstance);
    g_pInstance = this;
    g_CEntityScript_LoadScript_Hook.SetHookFunc(&CEntityScript_LoadScript_Hook);
}

LuaModManager::~LuaModManager()
{
    // Call OnShutdown in all mods
    for (auto& mod : m_Mods)
    {
        if (mod->pOnInit)
            Script::Call(m_pScriptSystem, mod->pOnShutdown, mod->modTable);
    }

    assert(g_pInstance == this);
    g_pInstance = nullptr;
}

void LuaModManager::PreGameInit()
{
    Init();
    RegisterMods();
}

void LuaModManager::PostGameInit()
{
    // Call OnGameInit in all mods
    for (auto& mod : m_Mods)
    {
        if (mod->pOnGameInit)
            Script::Call(m_pScriptSystem, mod->pOnGameInit, mod->modTable);
    }
}

bool LuaModManager::RegisterModFromXML(pugi::xml_node modNode)
{
    auto modName = boost::get<std::string>(gCL->conf->getNodeConfigValue(modNode, "modName"));
    std::string mainPath = GetMainPath(modName);

    if (!gEnv->pCryPak->IsFileExist(mainPath.c_str()))
        return false;

    // Create the entry. It may be removed if something fails during loading
    auto modEntry = std::make_unique<LuaMod>();
    modEntry->modName = modName;
    m_ModsByName[modName] = modEntry.get();
    m_Mods.emplace_back(std::move(modEntry));
    return true;
}

void LuaModManager::HookEntityTable(CEntityScript* pEntityScript)
{
    Script::Call(m_pScriptSystem, m_pfnHookEntityTable, pEntityScript->m_sTableName.c_str(), pEntityScript->m_pEntityTable);
}

void LuaModManager::Init()
{
    m_pScriptSystem = gEnv->pScriptSystem;
    m_pScriptBind = std::make_unique<ScriptBind_Chairloader>(this);

    // Load Chairloader script
    // Must be loaded after ScriptBind_Chairloader as it extends it.
    bool execSuccess = gEnv->pScriptSystem->ExecuteFile(CHAIR_SCRIPT_PATH, true, false);
    if (!execSuccess)
    {
        CryFatalError("Failed to execute {}. See log for details.", CHAIR_SCRIPT_PATH);
        return;
    }

    // Get internal Chairloader funcs
    if (!m_pScriptSystem->GetGlobalValue(INTERNAL_TABLE_NAME, m_pInternalTable))
    {
        CryFatalError("Failed to get the internal table.");
        return;
    }

    m_pInternalTable->GetValue("HookEntityTable", m_pfnHookEntityTable);

    if (!m_pfnHookEntityTable)
    {
        CryFatalError("Missing HookEntityTable");
        return;
    }

    // Remove the table from global list since it's internal
    m_pScriptSystem->SetGlobalToNull(INTERNAL_TABLE_NAME);
}

void LuaModManager::RegisterMods()
{
    std::vector<LuaMod*> brokenMods;

    for (auto& mod : m_Mods)
    {
        // Run the script
        std::string mainPath = GetMainPath(mod->modName);
        bool execSuccess = gEnv->pScriptSystem->ExecuteFile(mainPath.c_str(), true, false);
        if (!execSuccess)
        {
            CryError("Failed to execute {}", mainPath);
            brokenMods.push_back(mod.get());
            continue;
        }

        // Get the table
        SmartScriptTable modTable;
        gEnv->pScriptSystem->GetGlobalValue(CURRENT_MOD_VAR, modTable);

        if (!modTable)
        {
            CryError("Lua mod {} didn't set {}", mod->modName, CURRENT_MOD_VAR);
            brokenMods.push_back(mod.get());
            continue;
        }

        RegisterModTable(mod.get(), modTable);
        gEnv->pScriptSystem->SetGlobalToNull(CURRENT_MOD_VAR);
    }

    // Remove broken mods
    for (LuaMod* mod : brokenMods)
    {
        m_ModsByName.erase(mod->modName);
        auto it = std::find_if(m_Mods.begin(), m_Mods.end(), [&](auto& i) { return i.get() == mod; });
        m_Mods.erase(it);
        // mod is now dangling!
    }

    // Call OnInit in all mods
    for (auto& mod : m_Mods)
    {
        if (mod->pOnInit)
            Script::Call(m_pScriptSystem, mod->pOnInit, mod->modTable);
    }

    // Call HookEntities in all mods
    for (auto& mod : m_Mods)
    {
        if (mod->pHookEntities)
            Script::Call(m_pScriptSystem, mod->pHookEntities, mod->modTable);
    }
}

void LuaModManager::RegisterModTable(LuaMod* mod, SmartScriptTable modTable)
{
    mod->modTable = modTable;
    mod->isTableRegistered = true;

    modTable->GetValue("PublicExport", mod->exportTable);

    modTable->GetValue("OnRegister", mod->pOnRegister);
    modTable->GetValue("OnInit", mod->pOnInit);
    modTable->GetValue("OnGameInit", mod->pOnGameInit);
    modTable->GetValue("OnShutdown", mod->pOnShutdown);
    modTable->GetValue("HookEntities", mod->pHookEntities);

    if (mod->pOnRegister)
        Script::Call(m_pScriptSystem, mod->pOnRegister, mod->modTable);

    CryLog("Registered Lua mod: {}", mod->modName);
}

std::string LuaModManager::GetMainPath(const std::string& modName)
{
    return fmt::format("{}/{}/{}", MOD_SCRIPTS_DIR, modName, MOD_MAIN_SCRIPT);
}
