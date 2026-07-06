// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasSpaceForDoppelgangers
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasspacefordoppelgangers/ArkNpcAbilityPrereq_HasSpaceForDoppelgangers.h
class ArkNpcAbilityPrereq_HasSpaceForDoppelgangers : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSpaceForDoppelgangers,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=56 (0x38)
public:
	float m_spawnPointSearchArc;
	float m_searchHeight;
	float m_minSearchRangeMin;
	float m_minSearchRangeMax;
	float m_maxSearchRangeMin;
	float m_maxSearchRangeMax;
	float m_expectedDistanceToTargetMin;
	float m_expectedDistanceToTargetMax;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasSpaceForDoppelgangers();
	bool CalculateDoppelgangerSpawnPoints(const ArkNpc& _npc) const { return FCalculateDoppelgangerSpawnPoints(this, _npc); }

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasSpaceForDoppelgangers& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132EC80);
	static inline auto FArkNpcAbilityPrereq_HasSpaceForDoppelgangers = PreyFunction<void(ArkNpcAbilityPrereq_HasSpaceForDoppelgangers* const _this)>(0x132E820);
	static inline auto FCalculateDoppelgangerSpawnPoints = PreyFunction<bool(const ArkNpcAbilityPrereq_HasSpaceForDoppelgangers* const _this, const ArkNpc& _npc)>(0x132E890);
};
#endif // MOONCRASH
