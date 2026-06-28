// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>

class ArkNpc;
class ArkNpcAbilityInstance_Sidestep;
class ArkNpcAbilityParams;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbility_Sidestep
// Header:  Prey/GameDll/ark/npc/ability/sidestep/ArkNpcAbility_Sidestep.h
class ArkNpcAbility_Sidestep : public ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>
{ // Size=16 (0x10)
public:
	string m_fragmentName;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_Sidestep();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_Sidestep& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_Sidestep& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Sidestep& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Sidestep& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Sidestep& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Sidestep& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_Sidestep& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_Sidestep& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_Sidestep& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_Sidestep& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_Sidestep& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_Sidestep& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_Sidestep& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x126BA40);
	static inline auto FArkNpcAbility_Sidestep = PreyFunction<void(ArkNpcAbility_Sidestep* const _this)>(0x126B870);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_Sidestep* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_Sidestep& _abilityInstance)>(0x126BC10);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_Sidestep* const _this, ArkNpcAbilityInstance_Sidestep& _abilityInstance)>(0x1266970);
};
#endif // MOONCRASH
