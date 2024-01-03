#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CEntityScript;
class ScriptBind_Chairloader;

namespace Manager
{
struct ModInfo;
}

//! Manager for mods that use custom Lua scripts.
class LuaModManager : NoCopy
{
public:
    LuaModManager();
    ~LuaModManager();

    void PreGameInit();
    void PostGameInit();

    //! Tries to add a mod to the manager. Checks if it has Lua scripts.
    //! @returns true if it was registered.
    bool RegisterModFromXML(const Manager::ModInfo& modInfo, int loadOrder);

    //! Hooks the entity's script table.
    void HookEntityTable(CEntityScript* pEntityScript);

private:
    //! Chairloader main script.
    static constexpr char CHAIR_SCRIPT_PATH[] = "Scripts/Chairloader/main.lua";

    //! Internal Lua table name. Set in the main script.
    static constexpr char INTERNAL_TABLE_NAME[] = "Chairloader_Internal";

    //! Path to the mod scripts directory.
    static constexpr char MOD_SCRIPTS_DIR[] = "Scripts/Mods";

    //! Name of the main script file.
    static constexpr char MOD_MAIN_SCRIPT[] = "main.lua";

    //! Name of the variable with current mod table.
    static constexpr char CURRENT_MOD_VAR[] = "ChairloaderCurrentMod";

    struct LuaMod
    {
        std::string modName;
        SmartScriptTable modTable;
        SmartScriptTable exportTable;
        bool isTableRegistered = false;

        HSCRIPTFUNCTION pOnRegister = nullptr;
        HSCRIPTFUNCTION pOnInit = nullptr;
        HSCRIPTFUNCTION pOnGameInit = nullptr;
        HSCRIPTFUNCTION pOnShutdown = nullptr;
        HSCRIPTFUNCTION pHookEntities = nullptr;
    };

    IScriptSystem* m_pScriptSystem = nullptr;
    std::unique_ptr<ScriptBind_Chairloader> m_pScriptBind;

    SmartScriptTable m_pInternalTable;
    HSCRIPTFUNCTION m_pfnHookEntityTable = nullptr;

    std::vector<std::unique_ptr<LuaMod>> m_Mods;
    std::map<std::string, LuaMod*> m_ModsByName;

    //! Init after ScriptSystem is initialized.
    void Init();

    //! Loads mod script files.
    void RegisterMods();

    //! Registers the mod table.
    void RegisterModTable(LuaMod* mod, SmartScriptTable modTable);

    //! @returns the path to main script for a given mod.
    static std::string GetMainPath(const std::string& modName);

    friend class ScriptBind_Chairloader;
};
