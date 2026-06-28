// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_LookedAtForLongEnough;

// ArkNpcAbilityPrereq_LookedAtForLongEnough
// Header:  Prey/GameDll/ark/npc/ability/prereq/lookedatforlongenough/ArkNpcAbilityPrereq_LookedAtForLongEnough.h
class ArkNpcAbilityPrereq_LookedAtForLongEnough : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_LookedAtForLongEnough,ArkNpcAbilityPrereqInstance_LookedAtForLongEnough,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	float m_requiredTimeLookedAt;
	float m_lookAtConeAngle;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_LookedAtForLongEnough();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_LookedAtForLongEnough& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg2_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_LookedAtForLongEnough& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1262B00);
	static inline auto FArkNpcAbilityPrereq_LookedAtForLongEnough = PreyFunction<void(ArkNpcAbilityPrereq_LookedAtForLongEnough* const _this)>(0x1262A60);
};
#endif // MOONCRASH
