// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_HitReactShift;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_HitReactShift
// Header:  Prey/GameDll/ark/npc/ability/hitreactshift/ArkNpcAbility_HitReactShift.h
class ArkNpcAbilityInstance_HitReactShift : public ArkNpcAbilityInstance, public ArkNpcBodyStateObserver_Busy
{ // Size=784 (0x310)
public:
	const ArkNpcAbility_HitReactShift* m_pAbility;
	ArkNpc* m_pNpc;
	unsigned m_targetEntityId;
	ArkSimpleTimer m_delayBeforeShiftTimer;
	uint64_t m_contextId;
	ArkNpcSpeedDesire m_speedDesire;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;

	virtual ~ArkNpcAbilityInstance_HitReactShift();
	virtual void OnNpcBodyStateStateExit_Busy();

#if 0
	ArkNpcAbilityInstance_HitReactShift();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1327B90);
};

// ArkNpcAbility_HitReactShift
// Header:  Prey/GameDll/ark/npc/ability/hitreactshift/ArkNpcAbility_HitReactShift.h
class ArkNpcAbility_HitReactShift : public ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>
{ // Size=16 (0x10)
public:
	float m_stopDistance;
	float m_delayBeforeShift;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_HitReactShift();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_HitReactShift& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_HitReactShift& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_HitReactShift& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_HitReactShift& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_HitReactShift& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_HitReactShift& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_HitReactShift& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_HitReactShift& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_HitReactShift& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1327920);
	static inline auto FArkNpcAbility_HitReactShift = PreyFunction<void(ArkNpcAbility_HitReactShift* const _this)>(0x1327830);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_HitReactShift* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_HitReactShift& _abilityInstance)>(0x1327BA0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_HitReactShift* const _this, ArkNpcAbilityInstance_HitReactShift& _abilityInstance)>(0x1327B20);
};
#endif // MOONCRASH
