// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight
// Header:  Prey/GameDll/ark/npc/ability/prereq/haslineofsight/ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight.h
class ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	string m_firingStartAttachmentName;
	float m_requiredTimeWithLineOfSight;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1261390);
	static inline auto FArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight = PreyFunction<void(ArkNpcAbilityPrereq_HasPhysicalRangedLineOfSight* const _this)>(0x12611F0);
};
#endif // MOONCRASH
