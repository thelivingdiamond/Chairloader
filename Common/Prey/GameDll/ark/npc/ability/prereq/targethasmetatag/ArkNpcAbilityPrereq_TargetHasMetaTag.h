// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_TargetHasMetaTag
// Header:  Prey/GameDll/ark/npc/ability/prereq/targethasmetatag/ArkNpcAbilityPrereq_TargetHasMetaTag.h
class ArkNpcAbilityPrereq_TargetHasMetaTag : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TargetHasMetaTag,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=40 (0x28)
public:
	uint64_t m_requiredTag;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_TargetHasMetaTag();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_TargetHasMetaTag& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132FD30);
	static inline auto FArkNpcAbilityPrereq_TargetHasMetaTag = PreyFunction<void(ArkNpcAbilityPrereq_TargetHasMetaTag* const _this)>(0x132FCB0);
};
#endif // MOONCRASH
