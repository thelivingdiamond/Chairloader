// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntityProxy.h>
#include <Prey/CryPhysics/physinterface.h>
#include <_unknown/SActorFileModelInfo.h>
#include <_unknown/SActorGameParams.h>

class ICrySizer;
class SmartScriptTable;

// SLuaCache_ActorGameParams
// Header:  Prey/GameDll/actorluacache.h
struct SLuaCache_ActorGameParams : public _reference_target<int>
{ // Size=5000 (0x1388)
	SActorGameParams gameParams;
	bool bIsCached;

	bool CacheFromTable(SmartScriptTable pEntityTable) { return FCacheFromTable(this, pEntityTable); }

#if 0
	SLuaCache_ActorGameParams();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FCacheFromTable = PreyFunction<bool(SLuaCache_ActorGameParams* const _this, SmartScriptTable pEntityTable)>(0x10BF960);
};

// SLuaCache_ActorPhysicsParams
// Header:  Prey/GameDll/actorluacache.h
struct SLuaCache_ActorPhysicsParams : public _reference_target<int>
{ // Size=320 (0x140)
	SEntityPhysicalizeParams params;
	pe_player_dimensions playerDim;
	pe_player_dynamics playerDyn;
	bool bIsCached;

	bool CacheFromTable(SmartScriptTable pEntityTable, const char* szEntityClassName) { return FCacheFromTable(this, pEntityTable, szEntityClassName); }

#if 0
	SLuaCache_ActorPhysicsParams();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FCacheFromTable = PreyFunction<bool(SLuaCache_ActorPhysicsParams* const _this, SmartScriptTable pEntityTable, const char* szEntityClassName)>(0x10BF9D0);
};

// SLuaCache_ActorProperties
// Header:  Prey/GameDll/actorluacache.h
struct SLuaCache_ActorProperties : public _reference_target<int>
{ // Size=80 (0x50)
	SActorFileModelInfo fileModelInfo;
	float fPhysicMassMult;
	bool bIsCached;

	bool CacheFromTable(SmartScriptTable pEntityTable, SmartScriptTable pProperties) { return FCacheFromTable(this, pEntityTable, pProperties); }

#if 0
	SLuaCache_ActorProperties();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FCacheFromTable = PreyFunction<bool(SLuaCache_ActorProperties* const _this, SmartScriptTable pEntityTable, SmartScriptTable pProperties)>(0x10BFA60);
};
#endif // MOONCRASH
