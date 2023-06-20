// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>
#include <Prey/CryScriptSystem/ScriptBindings/ScriptBinding.h>
#include <Prey/CryScriptSystem/ScriptSystem.h>
#include <Prey/CrySystem/ISystem.h>

class CLUADbg;
class CScriptTimerMgr;
enum ELuaDebugMode;
enum ESystemEvent;
struct ICVar;
class ICrySizer;
struct IScriptTable;
struct ISerialize;
struct ISystem;
struct SLuaStackEntry;
struct SScriptFuncHandle;
struct ScriptAnyValue;
struct lua_State;

// CScriptSystem
// Header:  CryEngine/cryscriptsystem/ScriptSystem.h
class CScriptSystem : public IScriptSystem, public ISystemEventListener
{ // Size=17368 (0x43D8)
public:
	static inline auto s_mpScriptSystem = PreyGlobal<CScriptSystem*>(0x2976CF0);
	lua_State* L;
	ICVar* m_cvar_script_debugger;
	ICVar* m_cvar_script_coverage;
	int m_nTempArg;
	int m_nTempTop;
	IScriptTable* m_pUserDataMetatable;
	IScriptTable* m_pPreCacheBufferTable;
	std::vector<string> m_vecPreCached;
	SScriptFuncHandle* m_pErrorHandlerFunc;
	std::set<string, stl::less_stricmp<string>> m_dqLoadedFiles;
	CScriptBindings m_stdScriptBinds;
	ISystem* m_pSystem;
	float m_fGCFreq;
	float m_lastGCTime;
	int m_nLastGCCount;
	int m_forceReloadCount;
	CScriptTimerMgr* m_pScriptTimerMgr;
	static constexpr const int MAX_CALLDEPTH = 32;
	int m_nCallDepth;
	CryStackStringT<char,512> m_sCallDescriptions[32];
	string m_sLastBreakSource;
	int m_nLastBreakLine;
	CLUADbg* m_pLuaDebugger;

	CScriptSystem();
	virtual ~CScriptSystem();
	bool Init(ISystem* pSystem, bool bStdLibs, int nStackSize) { return FInit(this, pSystem, bStdLibs, nStackSize); }
	virtual void Update();
	virtual void SetGCFrequency(const float fRate);
	virtual void SetEnvironment(SScriptFuncHandle* scriptFunction, IScriptTable* pEnv);
	virtual IScriptTable* GetEnvironment(SScriptFuncHandle* scriptFunction);
	bool _ExecuteFile(const char* sFileName, bool bRaiseError, IScriptTable* pEnv) { return F_ExecuteFile(this, sFileName, bRaiseError, pEnv); }
	virtual bool ExecuteFile(const char* sFileName, bool bRaiseError, bool bForceReload, IScriptTable* pEnv);
	virtual bool ExecuteBuffer(const char* sBuffer, uint64_t nSize, const char* sBufferDescription, IScriptTable* pEnv);
	virtual void UnloadScript(const char* sFileName);
	virtual void UnloadScripts();
	virtual bool ReloadScript(const char* sFileName, bool bRaiseError);
	virtual bool ReloadScripts();
	virtual void DumpLoadedScripts();
	virtual IScriptTable* CreateTable(bool bEmpty);
	virtual int BeginCall(SScriptFuncHandle* hFunc);
	virtual int BeginCall(const char* sFuncName);
	virtual int BeginCall(const char* sTableName, const char* sFuncName);
	virtual int BeginCall(IScriptTable* pTable, const char* sFuncName);
	virtual bool EndCall();
	virtual bool EndCallAny(ScriptAnyValue& any);
	virtual bool EndCallAnyN(int n, ScriptAnyValue* anys);
	virtual SScriptFuncHandle* GetFunctionPtr(const char* sFuncName);
	virtual SScriptFuncHandle* GetFunctionPtr(const char* sTableName, const char* sFuncName);
	virtual void ReleaseFunc(SScriptFuncHandle* f);
	virtual SScriptFuncHandle* AddFuncRef(SScriptFuncHandle* f);
	virtual bool CompareFuncRef(SScriptFuncHandle* f1, SScriptFuncHandle* f2);
	virtual ScriptAnyValue CloneAny(const ScriptAnyValue& any);
	virtual void ReleaseAny(const ScriptAnyValue& any);
	virtual void PushFuncParamAny(const ScriptAnyValue& any);
	virtual void SetGlobalAny(const char* sKey, const ScriptAnyValue& any);
	virtual bool GetGlobalAny(const char* sKey, ScriptAnyValue& any);
	virtual IScriptTable* CreateUserData(void* ptr, uint64_t size);
	virtual void ForceGarbageCollection();
	virtual int GetCGCount();
	virtual void SetGCThreshhold(int nKb);
	virtual void Release();
	virtual void ShowDebugger(const char* pszSourceFile, int iLine, const char* pszReason);
	virtual int AddBreakPoint(const char* sFile, int nLineNumber);
	virtual IScriptTable* GetLocalVariables(int nLevel);
	virtual IScriptTable* GetCallsStack();
	virtual void DumpCallStack();
	virtual void DebugContinue();
	virtual void DebugStepNext();
	virtual void DebugStepInto();
	virtual void DebugDisable();
	virtual BreakState GetBreakState();
	virtual void GetMemoryStatistics(ICrySizer* pSizer) const;
	virtual void GetScriptHash(const char* sPath, const char* szKey, unsigned& dwHash);
	virtual void PostInit();
	virtual void RaiseError(const char* format, ...);
	virtual void LoadScriptedSurfaceTypes(const char* sFolder, bool bReload);
	virtual void SerializeTimers(ISerialize* pSer);
	virtual void ResetTimers();
	virtual int GetStackSize();
	virtual unsigned GetScriptAllocSize();
	virtual void* Allocate(uint64_t sz);
	virtual uint64_t Deallocate(void* ptr);
	void PushAny(const ScriptAnyValue& var) { FPushAny(this, var); }
	bool PopAny(ScriptAnyValue& var) { return FPopAny(this, var); }
	bool ToAny(ScriptAnyValue& var, int index) { return FToAny(this, var, index); }
	bool ToVec3(Vec3& vec, int tableIndex) { return FToVec3(this, vec, tableIndex); }
	bool GetRecursiveAny(IScriptTable* pTable, const char* sKey, ScriptAnyValue& any) { return FGetRecursiveAny(this, pTable, sKey, any); }
	void TraceScriptError(const char* file, int line, const char* errorStr) { FTraceScriptError(this, file, line, errorStr); }
	void LogStackTrace() { FLogStackTrace(this); }
	void GetCallStack(std::vector<SLuaStackEntry>& callstack) { FGetCallStack(this, callstack); }
	bool IsCallStackEmpty() { return FIsCallStackEmpty(this); }
	virtual SScriptFuncHandle* CompileBuffer(const char* sBuffer, uint64_t nSize, const char* sBufferDesc);
	virtual int PreCacheBuffer(const char* sBuffer, uint64_t nSize, const char* sBufferDesc);
	virtual int BeginPreCachedBuffer(int iIndex);
	virtual void ClearPreCachedBuffer();
	virtual std::vector<string> ReportErrors(std::vector<string>& filenames) const;
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	void ExposedCallstackPush(const char* sFunction, int nLine, const char* sSource) { FExposedCallstackPush(this, sFunction, nLine, sSource); }
	void ExposedCallstackPop() { FExposedCallstackPop(this); }
	bool EndCallN(int nReturns) { return FEndCallN(this, nReturns); }
	static int ErrorHandler(lua_State* L) { return FErrorHandler(L); }
	void EnableDebugger(ELuaDebugMode eDebugMode) { FEnableDebugger(this, eDebugMode); }
	static void DebugModeChange(ICVar* cvar) { FDebugModeChange(cvar); }
	static void CodeCoverageChange(ICVar* cvar) { FCodeCoverageChange(cvar); }

#if 0
	void RegisterErrorHandler();
	void PushVec3(const Vec3& _arg0_);
	void PushTable(IScriptTable* _arg0_);
	void AttachTable(IScriptTable* _arg0_);
	lua_State* GetLuaState() const;
	CScriptTimerMgr* GetScriptTimerMgr();
	void DumpStateToFile(const char* _arg0_);
	void ExposedCallstackClear();
	void CreateMetatables();
	void EnableCodeCoverage(bool _arg0_);
	void AddFileToList(const char* _arg0_);
	void RemoveFileFromList(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<CryStringT<char> > > >& _arg0_);
#endif

	static inline auto FCScriptSystemOv1 = PreyFunction<void(CScriptSystem* const _this)>(0xD0D0B0);
	static inline auto FInit = PreyFunction<bool(CScriptSystem* const _this, ISystem* pSystem, bool bStdLibs, int nStackSize)>(0xD10B30);
	static inline auto FUpdate = PreyFunction<void(CScriptSystem* const _this)>(0xD13020);
	static inline auto FSetGCFrequency = PreyFunction<void(CScriptSystem* const _this, const float fRate)>(0xD12660);
	static inline auto FSetEnvironment = PreyFunction<void(CScriptSystem* const _this, SScriptFuncHandle* scriptFunction, IScriptTable* pEnv)>(0xD12600);
	static inline auto FGetEnvironment = PreyFunction<IScriptTable* (CScriptSystem* const _this, SScriptFuncHandle* scriptFunction)>(0xD10250);
	static inline auto F_ExecuteFile = PreyFunction<bool(CScriptSystem* const _this, const char* sFileName, bool bRaiseError, IScriptTable* pEnv)>(0xD133E0);
	static inline auto FExecuteFile = PreyFunction<bool(CScriptSystem* const _this, const char* sFileName, bool bRaiseError, bool bForceReload, IScriptTable* pEnv)>(0xD0F610);
	static inline auto FExecuteBuffer = PreyFunction<bool(CScriptSystem* const _this, const char* sBuffer, uint64_t nSize, const char* sBufferDescription, IScriptTable* pEnv)>(0xD0F4D0);
	static inline auto FUnloadScript = PreyFunction<void(CScriptSystem* const _this, const char* sFileName)>(0xD12EC0);
	static inline auto FUnloadScripts = PreyFunction<void(CScriptSystem* const _this)>(0xD12FE0);
	static inline auto FReloadScript = PreyFunction<bool(CScriptSystem* const _this, const char* sFileName, bool bRaiseError)>(0xD122F0);
	static inline auto FReloadScripts = PreyFunction<bool(CScriptSystem* const _this)>(0xD123F0);
	static inline auto FDumpLoadedScripts = PreyFunction<void(CScriptSystem* const _this)>(0xD0F030);
	static inline auto FCreateTable = PreyFunction<IScriptTable* (CScriptSystem* const _this, bool bEmpty)>(0xD0EF00);
	static inline auto FBeginCallOv3 = PreyFunction<int(CScriptSystem* const _this, SScriptFuncHandle* hFunc)>(0xD0DDF0);
	static inline auto FBeginCallOv2 = PreyFunction<int(CScriptSystem* const _this, const char* sFuncName)>(0xD0DF20);
	static inline auto FBeginCallOv1 = PreyFunction<int(CScriptSystem* const _this, const char* sTableName, const char* sFuncName)>(0xD0DE50);
	static inline auto FBeginCallOv0 = PreyFunction<int(CScriptSystem* const _this, IScriptTable* pTable, const char* sFuncName)>(0xD0DD60);
	static inline auto FEndCall = PreyFunction<bool(CScriptSystem* const _this)>(0xD0F1C0);
	static inline auto FEndCallAny = PreyFunction<bool(CScriptSystem* const _this, ScriptAnyValue& any)>(0xD0F1D0);
	static inline auto FEndCallAnyN = PreyFunction<bool(CScriptSystem* const _this, int n, ScriptAnyValue* anys)>(0xD0F230);
	static inline auto FGetFunctionPtrOv1 = PreyFunction<SScriptFuncHandle* (CScriptSystem* const _this, const char* sFuncName)>(0xD103A0);
	static inline auto FGetFunctionPtrOv0 = PreyFunction<SScriptFuncHandle* (CScriptSystem* const _this, const char* sTableName, const char* sFuncName)>(0xD102E0);
	static inline auto FReleaseFunc = PreyFunction<void(CScriptSystem* const _this, SScriptFuncHandle* f)>(0xD122D0);
	static inline auto FAddFuncRef = PreyFunction<SScriptFuncHandle* (CScriptSystem* const _this, SScriptFuncHandle* f)>(0xD0DA40);
	static inline auto FCompareFuncRef = PreyFunction<bool(CScriptSystem* const _this, SScriptFuncHandle* f1, SScriptFuncHandle* f2)>(0xD0EDB0);
	static inline auto FCloneAny = PreyFunction<ScriptAnyValue*(CScriptSystem* const _this, ScriptAnyValue* _return_value_, const ScriptAnyValue& any)>(0xD0EC10);
	static inline auto FReleaseAny = PreyFunction<void(CScriptSystem* const _this, const ScriptAnyValue& any)>(0xD122B0);
	static inline auto FPushFuncParamAny = PreyFunction<void(CScriptSystem* const _this, const ScriptAnyValue& any)>(0xD11BA0);
	static inline auto FSetGlobalAny = PreyFunction<void(CScriptSystem* const _this, const char* sKey, const ScriptAnyValue& any)>(0xD126C0);
	static inline auto FGetGlobalAny = PreyFunction<bool(CScriptSystem* const _this, const char* sKey, ScriptAnyValue& any)>(0xD10410);
	static inline auto FCreateUserData = PreyFunction<IScriptTable* (CScriptSystem* const _this, void* ptr, uint64_t size)>(0xD0EF50);
	static inline auto FForceGarbageCollection = PreyFunction<void(CScriptSystem* const _this)>(0xD0FBC0);
	static inline auto FGetCGCount = PreyFunction<int(CScriptSystem* const _this)>(0xD0FC50);
	static inline auto FSetGCThreshhold = PreyFunction<void(CScriptSystem* const _this, int nKb)>(0xA13080);
	static inline auto FRelease = PreyFunction<void(CScriptSystem* const _this)>(0xA97D40);
	static inline auto FShowDebugger = PreyFunction<void(CScriptSystem* const _this, const char* pszSourceFile, int iLine, const char* pszReason)>(0xD12770);
	static inline auto FAddBreakPoint = PreyFunction<int(CScriptSystem* const _this, const char* sFile, int nLineNumber)>(0xD0DA10);
	static inline auto FGetLocalVariables = PreyFunction<IScriptTable* (CScriptSystem* const _this, int nLevel)>(0xD10590);
	static inline auto FGetCallsStack = PreyFunction<IScriptTable* (CScriptSystem* const _this)>(0xD0FF40);
	static inline auto FDumpCallStack = PreyFunction<void(CScriptSystem* const _this)>(0xD0F000);
	static inline auto FDebugContinue = PreyFunction<void(CScriptSystem* const _this)>(0xA13080);
	static inline auto FDebugStepNext = PreyFunction<void(CScriptSystem* const _this)>(0xA13080);
	static inline auto FDebugStepInto = PreyFunction<void(CScriptSystem* const _this)>(0xA13080);
	static inline auto FDebugDisable = PreyFunction<void(CScriptSystem* const _this)>(0xA13080);
	static inline auto FGetBreakState = PreyFunction<BreakState(CScriptSystem* const _this)>(0x13F8580);
	static inline auto FGetMemoryStatistics = PreyFunction<void(const CScriptSystem* const _this, ICrySizer* pSizer)>(0xD106F0);
	static inline auto FGetScriptHash = PreyFunction<void(CScriptSystem* const _this, const char* sPath, const char* szKey, unsigned& dwHash)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(CScriptSystem* const _this)>(0xD11840);
	static inline auto FRaiseError = PreyFunction<void(CScriptSystem* const _this, const char* format)>(0xD11BC0);
	static inline auto FLoadScriptedSurfaceTypes = PreyFunction<void(CScriptSystem* const _this, const char* sFolder, bool bReload)>(0xD10FD0);
	static inline auto FSerializeTimers = PreyFunction<void(CScriptSystem* const _this, ISerialize* pSer)>(0xD125D0);
	static inline auto FResetTimers = PreyFunction<void(CScriptSystem* const _this)>(0xD125C0);
	static inline auto FGetStackSize = PreyFunction<int(CScriptSystem* const _this)>(0xD10B20);
	static inline auto FGetScriptAllocSize = PreyFunction<unsigned(CScriptSystem* const _this)>(0xD10B10);
	static inline auto FAllocate = PreyFunction<void* (CScriptSystem* const _this, uint64_t sz)>(0xD0DAC0);
	static inline auto FDeallocate = PreyFunction<uint64_t(CScriptSystem* const _this, void* ptr)>(0xD0EFC0);
	static inline auto FPushAny = PreyFunction<void(CScriptSystem* const _this, const ScriptAnyValue& var)>(0xD119E0);
	static inline auto FPopAny = PreyFunction<bool(CScriptSystem* const _this, ScriptAnyValue& var)>(0xD11800);
	static inline auto FToAny = PreyFunction<bool(CScriptSystem* const _this, ScriptAnyValue& var, int index)>(0xD127E0);
	static inline auto FToVec3 = PreyFunction<bool(CScriptSystem* const _this, Vec3& vec, int tableIndex)>(0xD12BB0);
	static inline auto FGetRecursiveAny = PreyFunction<bool(CScriptSystem* const _this, IScriptTable* pTable, const char* sKey, ScriptAnyValue& any)>(0xD108B0);
	static inline auto FTraceScriptError = PreyFunction<void(CScriptSystem* const _this, const char* file, int line, const char* errorStr)>(0xD12E20);
	static inline auto FLogStackTrace = PreyFunction<void(CScriptSystem* const _this)>(0xD10FE0);
	static inline auto FGetCallStack = PreyFunction<void(CScriptSystem* const _this, std::vector<SLuaStackEntry>& callstack)>(0xD0FC60);
	static inline auto FIsCallStackEmpty = PreyFunction<bool(CScriptSystem* const _this)>(0xD10FA0);
	static inline auto FCompileBuffer = PreyFunction<SScriptFuncHandle* (CScriptSystem* const _this, const char* sBuffer, uint64_t nSize, const char* sBufferDesc)>(0xD0EE50);
	static inline auto FPreCacheBuffer = PreyFunction<int(CScriptSystem* const _this, const char* sBuffer, uint64_t nSize, const char* sBufferDesc)>(0xD11890);
	static inline auto FBeginPreCachedBuffer = PreyFunction<int(CScriptSystem* const _this, int iIndex)>(0xD0DF80);
	static inline auto FClearPreCachedBuffer = PreyFunction<void(CScriptSystem* const _this)>(0xD0EB90);
	static inline auto FReportErrors = PreyFunction<std::vector<string>*(const CScriptSystem* const _this, std::vector<string>* _return_value_, std::vector<string>& filenames)>(0xD12490);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xD11790);
	static inline auto FExposedCallstackPush = PreyFunction<void(CScriptSystem* const _this, const char* sFunction, int nLine, const char* sSource)>(0xD0FA00);
	static inline auto FExposedCallstackPop = PreyFunction<void(CScriptSystem* const _this)>(0xD0F980);
	static inline auto FEndCallN = PreyFunction<bool(CScriptSystem* const _this, int nReturns)>(0xD0F2E0);
	static inline auto FErrorHandler = PreyFunction<int(lua_State* L)>(0xD0F370);
	static inline auto FEnableDebugger = PreyFunction<void(CScriptSystem* const _this, ELuaDebugMode eDebugMode)>(0xD0F0C0);
	static inline auto FDebugModeChange = PreyFunction<void(ICVar* cvar)>(0xD0EFD0);
	static inline auto FCodeCoverageChange = PreyFunction<void(ICVar* cvar)>(0xD0ED70);
};
