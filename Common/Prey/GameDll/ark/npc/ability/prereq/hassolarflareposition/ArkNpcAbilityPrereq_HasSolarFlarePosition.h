// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_HasSolarFlarePosition
// Header:  Prey/GameDll/ark/npc/ability/prereq/hassolarflareposition/ArkNpcAbilityPrereq_HasSolarFlarePosition.h
class ArkNpcAbilityPrereq_HasSolarFlarePosition : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_HasSolarFlarePosition,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=48 (0x30)
public:
	float m_maxRandomDistFromTargetX;
	float m_maxRandomDistFromTargetY;
	float m_heightOffset;
	string m_firingStartAttachmentName;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_HasSolarFlarePosition();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_HasSolarFlarePosition& _arg0_) const;
	bool EqualTo(const ArkNpcAbilityPrereq_HasSolarFlarePosition& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1261D30);
	static inline auto FArkNpcAbilityPrereq_HasSolarFlarePosition = PreyFunction<void(ArkNpcAbilityPrereq_HasSolarFlarePosition* const _this)>(0x1261C90);
};
#endif // MOONCRASH
