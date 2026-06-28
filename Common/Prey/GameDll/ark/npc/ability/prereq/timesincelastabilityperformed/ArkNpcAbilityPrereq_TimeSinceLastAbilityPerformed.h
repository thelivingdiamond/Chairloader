// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/prereq/arknpcabilityprereqtemplate.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed;

// ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed
// Header:  Prey/GameDll/ark/npc/ability/prereq/timesincelastabilityperformed/ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed.h
class ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed : public ArkNpcAbilityPrereqTemplate<ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed,ArkNpcAbilityPrereqLocalScopePolicy>
{ // Size=32 (0x20)
public:
	float m_requiredTimeSinceLastAbility;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed();

#if 0
	bool SortsBefore(const ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed& _arg0_) const;
	void Update(const ArkNpc* _arg0_, float _arg1_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg2_) const;
	bool Evaluate(const ArkNpc& _arg0_, const ArkNpcAbilityParams& _arg1_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg2_) const;
	void OnContextStarted(uint64_t _arg0_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg1_) const;
	void Serialize(TSerialize _arg0_, ArkNpcAbilityPrereqInstance_TimeSinceLastAbilityPerformed& _arg1_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1263AF0);
	static inline auto FArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed = PreyFunction<void(ArkNpcAbilityPrereq_TimeSinceLastAbilityPerformed* const _this)>(0x1263AA0);
};
#endif // MOONCRASH
