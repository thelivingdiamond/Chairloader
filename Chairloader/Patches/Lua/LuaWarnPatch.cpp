#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/CryScriptSystem/ScriptSystem.h>
#include <Prey/CryScriptSystem/ScriptTable.h>
#include "Lua/LuaWarnPatch.h"

// TODO 2023-06-07: Add proper Lua headers
#define LUA_REGISTRYINDEX	(-10000)
#define LUA_MULTRET	(-1)
#define lua_getref(L,ref)       lua_rawgeti(L, LUA_REGISTRYINDEX, (ref))
#define lua_pop(L,n)		lua_settop(L, -(n)-1)
#define lua_tostring(L,i)	lua_tolstring(L, (i), NULL)

namespace
{

std::unique_ptr<IChairLogger> g_pLuaLog;
PreyFunction<void(IConsoleCmdArgs* pArgs)> g_ReloadScriptCmd(0x0D12360);

PreyFunction<const char* (lua_State* L, int idx, size_t* len)> lua_tolstring(0xD2CD60);
PreyFunction<int(lua_State* L, const char* buff, size_t sz, const char* name)> luaL_loadbuffer(0xD2DEE0);
PreyFunction<int(lua_State* L)> lua_gettop(0xD2BED0);
PreyFunction<int(lua_State* L, int idx)> lua_settop(0xD2CB70);
PreyFunction<void(lua_State* L, int idx, int n)> lua_rawgeti(0xD2C720);
PreyFunction<void(lua_State* L, int idx)> lua_insert(0xD2BF80);
PreyFunction<int(lua_State* L, int idx)> lua_setfenv(0xD2C980);
PreyFunction<int(lua_State* L, int nargs, int nresults, int errfunc)> lua_pcall(0xD2C280);
PreyFunction<void(lua_State* L, int idx)> lua_remove(0xD2C860);
PreyFunction<void(lua_State* L, int e)> lua_storedebuginfo(0xD41210);
PreyFunction<int(lua_State* L)> lua_isstoredebuginfo(0xD41050);

auto g_ReloadScriptCmd_Hook = g_ReloadScriptCmd.MakeHook();
auto g_CScriptSystem_ErrorHandler_Hook = CScriptSystem::FErrorHandler.MakeHook();
auto g_CScriptSystem_ExecuteBuffer_Hook = CScriptSystem::FExecuteBuffer.MakeHook();
auto g_CScriptSystem_RaiseError_Hook = CScriptSystem::FRaiseError.MakeHook();
auto g_lua_storedebuginfo_Hook = lua_storedebuginfo.MakeHook();

void PushTable(IScriptTable* pTable)
{
	((CScriptTable*)pTable)->PushRef();
};

void lua_storedebuginfo_Hook(lua_State* L, int e)
{
	static bool isSet = false;

	if (!isSet)
	{
		isSet = true;

		// On first call (during CScriptSystem::Init) check -lua_storedebug cmd line arg
		const ICmdLineArg* pArg = gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "lua_storedebug");
		if (pArg && pArg->GetIValue())
		{
			g_lua_storedebuginfo_Hook.InvokeOrig(L, 1);
			return;
		}
	}

	g_lua_storedebuginfo_Hook.InvokeOrig(L, e);
}

void ReloadScriptCmd_Hook(IConsoleCmdArgs* pArgs)
{
    if (pArgs->GetArgCount() < 2)
        g_pLuaLog->LogWarning("No file specified for reload");

    g_ReloadScriptCmd_Hook.InvokeOrig(pArgs);
}

int CScriptSystem_ErrorHandler_Hook(lua_State* L)
{
	// Ignore errors if debugging is not enabled
	if (!lua_isstoredebuginfo(L))
		return 0;

    const char* sErr = lua_tostring(L, 1);
    if (sErr)
        g_pLuaLog->LogError("{}", sErr);

    return g_CScriptSystem_ErrorHandler_Hook.InvokeOrig(L);
}

bool CScriptSystem_ExecuteBuffer_Hook(CScriptSystem* _this, const char* sBuffer, uint64_t nSize, const char* sBufferDescription, IScriptTable* pEnv)
{
	lua_State*& L = _this->L;
	int status;

	{
		status = luaL_loadbuffer(L, sBuffer, nSize, sBufferDescription);
	}

	if (status == 0)
	{
		// parse OK?
		int base = lua_gettop(L);  // function index.
		lua_getref(L, (int)(INT_PTR)_this->m_pErrorHandlerFunc);
		lua_insert(L, base);  // put it under chunk and args

		if (pEnv)
		{
			PushTable(pEnv);
			lua_setfenv(L, -2);
		}

		status = lua_pcall(L, 0, LUA_MULTRET, base); // call main
		lua_remove(L, base);                         // remove error handler function.
	}

	if (status != 0)
	{
		const char* sErr = lua_tostring(L, -1);
		if (!sErr)
			sErr = "(null)";

		if (sBufferDescription && strlen(sBufferDescription) != 0)
			g_pLuaLog->LogError("Failed to execute file {}: {}", sBufferDescription, sErr);
		else
			g_pLuaLog->LogError("Error executing lua {}", sErr);

		assert(_this->GetStackSize() > 0);
		lua_pop(L, 1);
		return false;
	}

	return true;
}

void CScriptSystem_RaiseError_Hook(CScriptSystem* const _this, const char* format, ...)
{
	va_list arglist;
	char sBuf[2048];
	int nCurrentLine = 0;
	const char* sSourceFile = "undefined";

	va_start(arglist, format);
	cry_vsprintf(sBuf, format, arglist);
	va_end(arglist);

	g_pLuaLog->LogError("{}", sBuf);

	_this->TraceScriptError(sSourceFile, nCurrentLine, sBuf);
}

} // namespace

void LuaWarnPatch::InitSystem()
{
    g_pLuaLog = gCL->cl->CreateLogger();
    g_pLuaLog->SetName("Lua");

	g_lua_storedebuginfo_Hook.SetHookFunc(&lua_storedebuginfo_Hook);
    g_ReloadScriptCmd_Hook.SetHookFunc(&ReloadScriptCmd_Hook);
    g_CScriptSystem_ErrorHandler_Hook.SetHookFunc(&CScriptSystem_ErrorHandler_Hook);
	g_CScriptSystem_ExecuteBuffer_Hook.SetHookFunc(&CScriptSystem_ExecuteBuffer_Hook);
	g_CScriptSystem_RaiseError_Hook.SetHookFunc((void(*)(CScriptSystem* const _this, const char* format))&CScriptSystem_RaiseError_Hook); // Uses variadic args - have to hack around it
}
