// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>

class CScriptSystem;
struct IScriptSystem;
struct IScriptTableDumpSink;
struct ScriptAnyValue;
struct lua_State;

// CScriptTable
// Header:  CryEngine/cryscriptsystem/ScriptTable.h
// Include: Prey/CryScriptSystem/ScriptTable.h
class CScriptTable : public IScriptTable
{ // Size=16 (0x10)
public:
	static inline auto L = PreyGlobal<lua_State*>(0x2977348);
	static inline auto m_pSS = PreyGlobal<CScriptSystem*>(0x2977350);
	int m_nRefCount;
	int m_nRef;

	virtual void AddRef();
	virtual void Release();
	virtual IScriptSystem* GetScriptSystem() const;
	virtual void Delegate(IScriptTable* pMetatable);
	virtual void* GetUserDataValue();
	virtual bool BeginSetGetChain();
	virtual void EndSetGetChain();
	virtual void SetValueAny(const char* sKey, const ScriptAnyValue& any, bool bChain);
	virtual bool GetValueAny(const char* sKey, ScriptAnyValue& any, bool bChain);
	virtual void SetAtAny(int nIndex, const ScriptAnyValue& any);
	virtual bool GetAtAny(int nIndex, ScriptAnyValue& any);
	virtual ScriptVarType GetValueType(const char* sKey);
	virtual ScriptVarType GetAtType(int nIdx);
	virtual IScriptTable::Iterator BeginIteration(bool resolvePrototypeTableAsWell);
	virtual bool MoveNext(IScriptTable::Iterator& iter);
	virtual void EndIteration(const IScriptTable::Iterator& iterr);
	virtual void Clear();
	virtual int Count();
	virtual bool Clone(IScriptTable* pSrcTable, bool bDeepCopy, bool bCopyByReference);
	virtual void Dump(IScriptTableDumpSink* p);
	virtual bool AddFunction(const IScriptTable::SUserFunctionDesc& fd);
	void CreateNew() { FCreateNew(this); }
	void Attach() { FAttach(this); }
	void DeleteThis() { FDeleteThis(this); }
	void PushRef() { FPushRefOv1(this); }
	// static void* operator new(uint64_t nSize) { return Foperator new(nSize); }
	// static void operator delete(void* ptr) { Foperator delete(ptr); }
	static int StdCFunction(lua_State* L) { return FStdCFunction(L); }
	static int StdCUserDataFunction(lua_State* L) { return FStdCUserDataFunction(L); }
	static void CloneTable_r(int srcTable, int trgTable) { FCloneTable_r(srcTable, trgTable); }
	static void ReferenceTable_r(int srcTable, int trgTable) { FReferenceTable_r(srcTable, trgTable); }

#if 0
	CScriptTable();
	int GetRef();
	void AttachToObject(IScriptTable* _arg0_);
	void Recreate();
	void SetMetatable(IScriptTable* _arg0_);
	void PushRef(IScriptTable* _arg0_);
	static void CloneTable(int _arg0_, int _arg1_);
#endif

	static inline auto FAddRef = PreyFunction<void(CScriptTable* const _this)>(0x49B5B0);
	static inline auto FRelease = PreyFunction<void(CScriptTable* const _this)>(0xD122A0);
	static inline auto FGetScriptSystem = PreyFunction<IScriptSystem* (const CScriptTable* const _this)>(0xD14AD0);
	static inline auto FDelegate = PreyFunction<void(CScriptTable* const _this, IScriptTable* pMetatable)>(0xD143E0);
	static inline auto FGetUserDataValue = PreyFunction<void* (CScriptTable* const _this)>(0xD14AE0);
	static inline auto FBeginSetGetChain = PreyFunction<bool(CScriptTable* const _this)>(0xD13F50);
	static inline auto FEndSetGetChain = PreyFunction<void(CScriptTable* const _this)>(0xD148E0);
	static inline auto FSetValueAny = PreyFunction<void(CScriptTable* const _this, const char* sKey, const ScriptAnyValue& any, bool bChain)>(0xD153D0);
	static inline auto FGetValueAny = PreyFunction<bool(CScriptTable* const _this, const char* sKey, ScriptAnyValue& any, bool bChain)>(0xD14B50);
	static inline auto FSetAtAny = PreyFunction<void(CScriptTable* const _this, int nIndex, const ScriptAnyValue& any)>(0xD15330);
	static inline auto FGetAtAny = PreyFunction<bool(CScriptTable* const _this, int nIndex, ScriptAnyValue& any)>(0xD14910);
	static inline auto FGetValueType = PreyFunction<ScriptVarType(CScriptTable* const _this, const char* sKey)>(0xD14C30);
	static inline auto FGetAtType = PreyFunction<ScriptVarType(CScriptTable* const _this, int nIdx)>(0xD149B0);
	static inline auto FBeginIteration = PreyFunction<IScriptTable::Iterator*(CScriptTable* const _this, IScriptTable::Iterator* _return_value_, bool resolvePrototypeTableAsWell)>(0xD13EB0);
	static inline auto FMoveNext = PreyFunction<bool(CScriptTable* const _this, IScriptTable::Iterator& iter)>(0xD14F90);
	static inline auto FEndIteration = PreyFunction<void(CScriptTable* const _this, const IScriptTable::Iterator& iterr)>(0xD148B0);
	static inline auto FClear = PreyFunction<void(CScriptTable* const _this)>(0xD13FA0);
	static inline auto FCount = PreyFunction<int(CScriptTable* const _this)>(0xD14320);
	static inline auto FClone = PreyFunction<bool(CScriptTable* const _this, IScriptTable* pSrcTable, bool bDeepCopy, bool bCopyByReference)>(0xD14080);
	static inline auto FDump = PreyFunction<void(CScriptTable* const _this, IScriptTableDumpSink* p)>(0xD14560);
	static inline auto FAddFunction = PreyFunction<bool(CScriptTable* const _this, const IScriptTable::SUserFunctionDesc& fd)>(0xD13C60);
	static inline auto FCreateNew = PreyFunction<void(CScriptTable* const _this)>(0xD14390);
	static inline auto FAttach = PreyFunction<void(CScriptTable* const _this)>(0xD13E70);
	static inline auto FDeleteThis = PreyFunction<void(CScriptTable* const _this)>(0xD14510);
	static inline auto FPushRefOv1 = PreyFunction<void(CScriptTable* const _this)>(0xD15190);
	// static inline auto Foperator new = PreyFunction<void* (uint64_t nSize)>(0xD13BC0);
	// static inline auto Foperator delete = PreyFunction<void(void* ptr)>(0xD13C10);
	static inline auto FStdCFunction = PreyFunction<int(lua_State* L)>(0xD15780);
	static inline auto FStdCUserDataFunction = PreyFunction<int(lua_State* L)>(0xD157E0);
	static inline auto FCloneTable_r = PreyFunction<void(int srcTable, int trgTable)>(0xD14200);
	static inline auto FReferenceTable_r = PreyFunction<void(int srcTable, int trgTable)>(0xD151E0);
};

