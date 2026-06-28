// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/ability/operatorcontinuousswipe/ArkOperatorSwipeAttackFsm.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>
#include <_unknown/ArkOperatorSwipeFsm_Config.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_OperatorSwipeAttack;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_OperatorSwipeAttack
// Header:  Prey/GameDll/ark/npc/ability/operatorcontinuousswipe/ArkNpcAbility_OperatorSwipeAttack.h
class ArkNpcAbilityInstance_OperatorSwipeAttack : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=1648 (0x670)
public:
	ArkOperatorSwipeAttackFsm m_fsm;
	ArkNpc* m_pNpc;
	const ArkNpcAbility_OperatorSwipeAttack* m_pAbility;
	uint64_t m_contextId;

	virtual ~ArkNpcAbilityInstance_OperatorSwipeAttack();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_OperatorSwipeAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1257C90);
};

// ArkNpcAbility_OperatorSwipeAttack
// Header:  Prey/GameDll/ark/npc/ability/operatorcontinuousswipe/ArkNpcAbility_OperatorSwipeAttack.h
class ArkNpcAbility_OperatorSwipeAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>
{ // Size=64 (0x40)
public:
	ArkOperatorSwipeFsm_Config m_config;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_OperatorSwipeAttack();

#if 0
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg3_) const;
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorSwipeAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorSwipeAttack& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_OperatorSwipeAttack& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_OperatorSwipeAttack& _arg0_) const;
	void Done(ArkNpcAbilityInstance_OperatorSwipeAttack& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1257A80);
	static inline auto FArkNpcAbility_OperatorSwipeAttack = PreyFunction<void(ArkNpcAbility_OperatorSwipeAttack* const _this)>(0x12579B0);
};
#endif // MOONCRASH
