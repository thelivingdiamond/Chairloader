// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/ability/corruptedexplode/ArkCorruptedExplodeFsm.h>

class ArkNpc;
class ArkNpcAbilityInstance;
class ArkNpcAbilityInstance_CorruptedExplode;
class ArkNpcAbilityParams;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbility_CorruptedExplode
// Header:  Prey/GameDll/ark/npc/ability/corruptedexplode/ArkNpcAbility_CorruptedExplode.h
class ArkNpcAbility_CorruptedExplode : public ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>
{ // Size=80 (0x50)
public:
	ArkCorruptedExplodeFsm_Config m_fsmConfig;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_CorruptedExplode();

#if 0
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_CorruptedExplode& _arg3_) const;
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedExplode& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedExplode& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CorruptedExplode& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_CorruptedExplode& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CorruptedExplode& _arg1_) const;
	void Exit(ArkNpcAbilityInstance_CorruptedExplode& _arg0_) const;
	void Done(ArkNpcAbilityInstance_CorruptedExplode& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12527F0);
	static inline auto FArkNpcAbility_CorruptedExplode = PreyFunction<void(ArkNpcAbility_CorruptedExplode* const _this)>(0x12526E0);
};
#endif // MOONCRASH
