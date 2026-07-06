// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/ability/operatorstrafe/ArkOperatorStrafeAttackFsm.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>
#include <_unknown/ArkOperatorStrafeFsm_Config.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_OperatorStrafeAttack;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_OperatorStrafeAttack
// Header:  Prey/GameDll/ark/npc/ability/operatorstrafe/ArkNpcAbility_OperatorStrafeAttack.h
class ArkNpcAbilityInstance_OperatorStrafeAttack : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=2088 (0x828)
public:
	const ArkNpcAbility_OperatorStrafeAttack* m_pAbility;
	ArkNpc* m_pNpc;
	uint64_t m_contextId;
	ArkOperatorStrafeAttackFsm m_fsm;

	virtual ~ArkNpcAbilityInstance_OperatorStrafeAttack();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_OperatorStrafeAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x125A620);
};

// ArkNpcAbility_OperatorStrafeAttack
// Header:  Prey/GameDll/ark/npc/ability/operatorstrafe/ArkNpcAbility_OperatorStrafeAttack.h
class ArkNpcAbility_OperatorStrafeAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>
{ // Size=24 (0x18)
public:
	ArkOperatorStrafeFsm_Config m_config;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_OperatorStrafeAttack();

#if 0
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg3_) const;
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_OperatorStrafeAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_OperatorStrafeAttack& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_OperatorStrafeAttack& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_OperatorStrafeAttack& _arg0_) const;
	void Done(ArkNpcAbilityInstance_OperatorStrafeAttack& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125A440);
	static inline auto FArkNpcAbility_OperatorStrafeAttack = PreyFunction<void(ArkNpcAbility_OperatorStrafeAttack* const _this)>(0x125A3A0);
};
#endif // MOONCRASH
