// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer
// Header:  Prey/GameDll/ark/npc/ability/prereq/timesincelastdamagedplayer/ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer.h
class ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_seconds;
	bool m_bNegate;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1263C40);
	static inline auto FArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer = PreyFunction<void(ArkNpcAbilityPrereq_TimeSinceLastDamagedPlayer* const _this)>(0x1263BE0);
};
#endif // MOONCRASH
