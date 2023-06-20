#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class LuaModManager;

class ScriptBind_Chairloader : public CScriptableBase
{
public:
    ScriptBind_Chairloader(LuaModManager* pManager);

private:
    LuaModManager* m_pManager = nullptr;
    std::unique_ptr<IChairLogger> m_pLuaLog;

    //! Prints text into the log.
    int Log(IFunctionHandler* pH, const char* text);

    //! Prints a warning into the log.
    int LogWarning(IFunctionHandler* pH, const char* text);

    //! Prints a warning into the log.
    int LogError(IFunctionHandler* pH, const char* text);

    //! Checks if a mod is installed and enabled.
    //! The mod doesn't have to be a Lua mod.
    //! @param  pH
    //! @param  modName Full mod name.
    //! @returns whether a mod is installed and enabled.
    int IsModInstalled(IFunctionHandler* pH, const char* modName);

    //! @returns the export table for a given mod. If mod not found, returns nil.
    int GetModExportTable(IFunctionHandler* pH, const char* modName);
};
