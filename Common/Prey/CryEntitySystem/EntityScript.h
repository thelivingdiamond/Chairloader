// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/EntityScript.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>

enum class EScriptStateFunctions;
struct IScriptSystem;
struct IScriptTable;
struct SScriptFuncHandle;
struct SScriptStateFunctions;

struct IEntityScript
{
	virtual ~IEntityScript() {}
	// Releases IEntityScript interface.
	virtual void Release() = 0;

	virtual void GetMemoryUsage(ICrySizer* pSizer) const {}
};

struct SEntityScriptEvent
{
	string                       name;
	HSCRIPTFUNCTION              func;
	IEntityClass::EventValueType valueType;
	unsigned char                bOutput : 1;
	unsigned char                bOldEvent : 1;
};

// SScriptState
// Header:  CryEngine/cryentitysystem/EntityScript.h
// Include: Prey/CryEntitySystem/EntityScript.h
struct SScriptState
{ // Size=24 (0x18)
	string name;
	SScriptStateFunctions* pStateFuns[2];

	~SScriptState();

#if 0
	SScriptState();
	void Free(IScriptSystem* _arg0_);
	bool IsStateFunctionImplemented(EScriptStateFunctions _arg0_) const;
#endif

	static inline auto FBitNotSScriptState = PreyFunction<void(SScriptState* const _this)>(0x92C530);
};

// CEntityScript
// Header:  CryEngine/cryentitysystem/EntityScript.h
// Include: Prey/CryEntitySystem/EntityScript.h
class CEntityScript : public IEntityScript
{ // Size=192 (0xC0)
public:
	IScriptSystem* m_pScriptSystem;
	SmartScriptTable m_pEntityTable;
	SmartScriptTable m_pPropertiesTable;
	string m_sTableName;
	string m_sScriptFilename;
	SScriptFuncHandle* m_pOnSpawnFunc;
	SScriptFuncHandle* m_pOnDestroyFunc;
	SScriptFuncHandle* m_pOnInitFunc[2];
	SScriptFuncHandle* m_pOnShutDown[2];
	SScriptFuncHandle* m_pOnReset;
	SScriptFuncHandle* m_pOnTransformFromEditorDone;
	SScriptState m_defaultState;
	std::vector<SScriptState> m_states;
	std::vector<SEntityScriptEvent> m_events;
	bool m_bScriptLoaded;
	bool m_bDefaultOnly;

	CEntityScript();
	virtual ~CEntityScript();
	virtual bool Init(const char* sTableName, const char* sScriptFilename);
	virtual void Release();
	virtual bool LoadScript(bool bForceReload);
	int GetStateId(const char* sStateName) const { return FGetStateId(this, sStateName); }
	const char* GetStateName(int nStateId) const { return FGetStateName(this, nStateId); }
	SScriptState* GetState(int nStateId) { return FGetStateOv0(this, nStateId); }
	void CallStateFunction(SScriptState* pState, IScriptTable* pThis, EScriptStateFunctions function) { FCallStateFunction(this, pState, pThis, function); }
	void Call_OnInit(IScriptTable* pThis, bool isReload) { FCall_OnInit(this, pThis, isReload); }
	void Call_OnShutDown(IScriptTable* pThis) { FCall_OnShutDown(this, pThis); }
	void Call_OnReset(IScriptTable* pThis, bool toGame) { FCall_OnReset(this, pThis, toGame); }
	void Call_OnTransformFromEditorDone(IScriptTable* pThis) { FCall_OnTransformFromEditorDone(this, pThis); }
	const SEntityScriptEvent* FindEvent(const char* sEvent) const { return FFindEvent(this, sEvent); }
	void CallEvent(IScriptTable* pThis, const char* sEvent, float fValue) { FCallEventOv4(this, pThis, sEvent, fValue); }
	void CallEvent(IScriptTable* pThis, const char* sEvent, bool bValue) { FCallEventOv3(this, pThis, sEvent, bValue); }
	void CallEvent(IScriptTable* pThis, const char* sEvent, const char* sValue) { FCallEventOv2(this, pThis, sEvent, sValue); }
	void CallEvent(IScriptTable* pThis, const char* sEvent, IScriptTable* pTable) { FCallEventOv1(this, pThis, sEvent, pTable); }
	void CallEvent(IScriptTable* pThis, const char* sEvent, const Vec3& vValue) { FCallEventOv0(this, pThis, sEvent, vValue); }
	void Clear() { FClear(this); }
	void EnumStates() { FEnumStates(this); }
	void LoadEvents() { FLoadEvents(this); }
	void InitializeStateTable(IScriptTable* pStateTable, SScriptStateFunctions* scriptState) { FInitializeStateTable(this, pStateTable, scriptState); }
	void InitializeNamedStates(IScriptTable* pTable, int nStateNum) { FInitializeNamedStates(this, pTable, nStateNum); }
	void ParseInOutEvents(IScriptTable* pEventsTable, std::vector<SEntityScriptEvent>& events, bool bOutput) { FParseInOutEvents(this, pEventsTable, events, bOutput); }

#if 0
	IScriptSystem* GetScriptSystem() const;
	IScriptTable* GetScriptTable() const;
	IScriptTable* GetPropertiesTable() const;
	SScriptState* GetState(const char* _arg0_);
	bool ShouldExecuteCall(int _arg0_) const;
	int GetEventCount() const;
	const SEntityScriptEvent& GetEvent(int _arg0_) const;
	uint64_t CountInOutEvents(IScriptTable* _arg0_, std::vector<SEntityScriptEvent>& _arg1_, bool _arg2_);
#endif

	static inline auto FCEntityScriptOv1 = PreyFunction<void(CEntityScript* const _this)>(0x92C3A0);
	static inline auto FInit = PreyFunction<bool(CEntityScript* const _this, const char* sTableName, const char* sScriptFilename)>(0x92DFD0);
	static inline auto FRelease = PreyFunction<void(CEntityScript* const _this)>(0xA97D40);
	static inline auto FLoadScript = PreyFunction<bool(CEntityScript* const _this, bool bForceReload)>(0x92E7E0);
	static inline auto FGetStateId = PreyFunction<int(const CEntityScript* const _this, const char* sStateName)>(0x92DEC0);
	static inline auto FGetStateName = PreyFunction<const char* (const CEntityScript* const _this, int nStateId)>(0x92DF70);
	static inline auto FGetStateOv0 = PreyFunction<SScriptState* (CEntityScript* const _this, int nStateId)>(0x92DE60);
	static inline auto FCallStateFunction = PreyFunction<void(CEntityScript* const _this, SScriptState* pState, IScriptTable* pThis, EScriptStateFunctions function)>(0x9640D0);
	static inline auto FCall_OnInit = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis, bool isReload)>(0x92D200);
	static inline auto FCall_OnShutDown = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis)>(0x92D3B0);
	static inline auto FCall_OnReset = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis, bool toGame)>(0x92D380);
	static inline auto FCall_OnTransformFromEditorDone = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis)>(0x92D550);
	static inline auto FFindEvent = PreyFunction<const SEntityScriptEvent* (const CEntityScript* const _this, const char* sEvent)>(0x92DDA0);
	static inline auto FCallEventOv4 = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis, const char* sEvent, float fValue)>(0x92CDB0);
	static inline auto FCallEventOv3 = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis, const char* sEvent, bool bValue)>(0x92CFD0);
	static inline auto FCallEventOv2 = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis, const char* sEvent, const char* sValue)>(0x92C950);
	static inline auto FCallEventOv1 = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis, const char* sEvent, IScriptTable* pTable)>(0x92C710);
	static inline auto FCallEventOv0 = PreyFunction<void(CEntityScript* const _this, IScriptTable* pThis, const char* sEvent, const Vec3& vValue)>(0x92CB80);
	static inline auto FClear = PreyFunction<void(CEntityScript* const _this)>(0x92D600);
	static inline auto FEnumStates = PreyFunction<void(CEntityScript* const _this)>(0x92D8F0);
	static inline auto FLoadEvents = PreyFunction<void(CEntityScript* const _this)>(0x92E280);
	static inline auto FInitializeStateTable = PreyFunction<void(CEntityScript* const _this, IScriptTable* pStateTable, SScriptStateFunctions* scriptState)>(0x92E1A0);
	static inline auto FInitializeNamedStates = PreyFunction<void(CEntityScript* const _this, IScriptTable* pTable, int nStateNum)>(0x92E010);
	static inline auto FParseInOutEvents = PreyFunction<void(CEntityScript* const _this, IScriptTable* pEventsTable, std::vector<SEntityScriptEvent>& events, bool bOutput)>(0x92E980);
};

