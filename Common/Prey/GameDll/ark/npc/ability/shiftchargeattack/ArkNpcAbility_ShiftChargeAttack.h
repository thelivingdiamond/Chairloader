// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_ShiftChargeAttack;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_ShiftChargeAttack
// Header:  Prey/GameDll/ark/npc/ability/shiftchargeattack/ArkNpcAbility_ShiftChargeAttack.h
class ArkNpcAbilityInstance_ShiftChargeAttack : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=768 (0x300)
public:
	const ArkNpcAbility_ShiftChargeAttack* m_pAbility;
	ArkNpc* m_pNpc;
	uint64_t m_contextId;
	ArkNpcSpeedDesire m_speedDesire;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;

	virtual ~ArkNpcAbilityInstance_ShiftChargeAttack();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_ShiftChargeAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x126A920);
};

// ArkNpcAbility_ShiftChargeAttack
// Header:  Prey/GameDll/ark/npc/ability/shiftchargeattack/ArkNpcAbility_ShiftChargeAttack.h
class ArkNpcAbility_ShiftChargeAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>
{ // Size=24 (0x18)
public:
	uint64_t m_damageSignalPackageId;
	float m_stopDistance;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_ShiftChargeAttack();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_ShiftChargeAttack& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_ShiftChargeAttack& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_ShiftChargeAttack& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_ShiftChargeAttack& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_ShiftChargeAttack& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_ShiftChargeAttack& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x126A760);
	static inline auto FArkNpcAbility_ShiftChargeAttack = PreyFunction<void(ArkNpcAbility_ShiftChargeAttack* const _this)>(0x126A640);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_ShiftChargeAttack* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_ShiftChargeAttack& _abilityInstance)>(0x126A930);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_ShiftChargeAttack* const _this, ArkNpcAbilityInstance_ShiftChargeAttack& _abilityInstance)>(0x126A8B0);
};
#endif // MOONCRASH
