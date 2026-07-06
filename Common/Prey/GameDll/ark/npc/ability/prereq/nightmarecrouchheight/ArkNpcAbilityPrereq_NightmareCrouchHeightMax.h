// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_NightmareCrouchHeightMax
// Header:  Prey/GameDll/ark/npc/ability/prereq/nightmarecrouchheight/ArkNpcAbilityPrereq_NightmareCrouchHeightMax.h
class ArkNpcAbilityPrereq_NightmareCrouchHeightMax : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_NightmareCrouchHeightMax,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	float m_height;
	float m_testHorizontal;
	float m_testDown;
	float m_testUp;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_NightmareCrouchHeightMax();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_NightmareCrouchHeightMax& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12633C0);
	static inline auto FArkNpcAbilityPrereq_NightmareCrouchHeightMax = PreyFunction<void(ArkNpcAbilityPrereq_NightmareCrouchHeightMax* const _this)>(0x1263390);
};
#endif // MOONCRASH
