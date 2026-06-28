// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasNearbyMoonRocks
// Header:  Prey/GameDll/ark/npc/ability/prereq/hasnearbymoonrocks/ArkNpcAbilityPrereq_HasNearbyMoonRocks.h
class ArkNpcAbilityPrereq_HasNearbyMoonRocks : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasNearbyMoonRocks,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	int m_numRocksWithLoSRequired;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasNearbyMoonRocks();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasNearbyMoonRocks& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12614F0);
	static inline auto FArkNpcAbilityPrereq_HasNearbyMoonRocks = PreyFunction<void(ArkNpcAbilityPrereq_HasNearbyMoonRocks* const _this)>(0x12614C0);
};
#endif // MOONCRASH
