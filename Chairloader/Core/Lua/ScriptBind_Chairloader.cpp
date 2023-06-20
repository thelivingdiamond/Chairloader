#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderCore.h>
#include "Lua/LuaModManager.h"
#include "Lua/ScriptBind_Chairloader.h"

ScriptBind_Chairloader::ScriptBind_Chairloader(LuaModManager* pManager)
{
    CScriptableBase::Init(gEnv->pSystem->GetIScriptSystem(), gEnv->pSystem);
    SetGlobalName("Chairloader");
    m_pManager = pManager;
    m_pLuaLog = gCL->cl->CreateLogger();
    m_pLuaLog->SetName("Lua");

#undef SCRIPT_REG_CLASSNAME
#define SCRIPT_REG_CLASSNAME &ScriptBind_Chairloader::

    SCRIPT_REG_TEMPLFUNC(Log, "text");
    SCRIPT_REG_TEMPLFUNC(LogWarning, "text");
    SCRIPT_REG_TEMPLFUNC(LogError, "text");
    SCRIPT_REG_TEMPLFUNC(IsModInstalled, "modName");
    SCRIPT_REG_TEMPLFUNC(GetModExportTable, "modName");
}

int ScriptBind_Chairloader::Log(IFunctionHandler* pH, const char* text)
{
    m_pLuaLog->Log(EChairLogType::Message, text, strlen(text));
    return pH->EndFunction();
}

int ScriptBind_Chairloader::LogWarning(IFunctionHandler* pH, const char* text)
{
    m_pLuaLog->Log(EChairLogType::Warning, text, strlen(text));
    return pH->EndFunction();
}

int ScriptBind_Chairloader::LogError(IFunctionHandler* pH, const char* text)
{
    m_pLuaLog->Log(EChairLogType::Error, text, strlen(text));
    return pH->EndFunction();
}

int ScriptBind_Chairloader::IsModInstalled(IFunctionHandler* pH, const char* modName)
{
    bool isInstalled = gChair->GetCore()->IsModInstalled(modName);
    return pH->EndFunction(isInstalled);
}

int ScriptBind_Chairloader::GetModExportTable(IFunctionHandler* pH, const char* modName)
{
    auto it = m_pManager->m_ModsByName.find(modName);

    if (it == m_pManager->m_ModsByName.end())
        return pH->EndFunction();

    return it->second->exportTable;
}
