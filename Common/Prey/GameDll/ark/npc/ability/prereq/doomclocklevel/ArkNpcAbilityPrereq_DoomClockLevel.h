// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance;

// ArkNpcAbilityPrereq_DoomClockLevel
// Header:  Prey/GameDll/ark/npc/ability/prereq/doomclocklevel/ArkNpcAbilityPrereq_DoomClockLevel.h
class ArkNpcAbilityPrereq_DoomClockLevel : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_DoomClockLevel,ArkNpcAbilityPrereqInstance,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	int m_minDoomClockLevel;
	int m_maxDoomClockLevel;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_DoomClockLevel();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_DoomClockLevel& _arg0_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance& _arg2_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x132CCB0);
	static inline auto FArkNpcAbilityPrereq_DoomClockLevel = PreyFunction<void(ArkNpcAbilityPrereq_DoomClockLevel* const _this)>(0x132CC60);
};
#endif // MOONCRASH
