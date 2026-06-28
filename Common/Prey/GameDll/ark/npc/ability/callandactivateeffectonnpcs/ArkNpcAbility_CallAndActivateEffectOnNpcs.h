// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_CallAndActivateEffectOnNpcs;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs
// Header:  Prey/GameDll/ark/npc/ability/callandactivateeffectonnpcs/ArkNpcAbility_CallAndActivateEffectOnNpcs.h
class ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=744 (0x2E8)
public:
	const ArkNpcAbility_CallAndActivateEffectOnNpcs* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	int m_fragmentId;
	ArkNpcLookDesire m_lookDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;
	ECallAndActivateEffectOnNpcsStage m_currentAbilityStage;
	float m_callDurationTimer;
	bool m_bHasReducedCallDuration;

	virtual ~ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x124FCE0);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x13272A0);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x124FCA0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x124FCA0);
};

// ArkNpcAbility_CallAndActivateEffectOnNpcs
// Header:  Prey/GameDll/ark/npc/ability/callandactivateeffectonnpcs/ArkNpcAbility_CallAndActivateEffectOnNpcs.h
class ArkNpcAbility_CallAndActivateEffectOnNpcs : public ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>
{ // Size=64 (0x40)
public:
	float m_callDuration;
	float m_callSuccessCallReductionTime;
	float m_callEffectApplicationRadius;
	float m_castTime;
	uint64_t m_calleeInboundSignalModifierId;
	uint64_t m_callEffectGameEffectId;
	uint64_t m_callerEffectGameEffectId;
	uint64_t m_excludeGameEffectId;
	string m_fragmentName;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_CallAndActivateEffectOnNpcs();
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void CallNPCs(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _abilityInstance) const { FCallNPCs(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, const uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_, EActionFailure _arg1_) const;
	bool AllCalledNpcsInRange(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
	void InitiateCharge(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
	void ApplyGameEffectsToNPCs(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x124F900);
	static inline auto FArkNpcAbility_CallAndActivateEffectOnNpcs = PreyFunction<void(ArkNpcAbility_CallAndActivateEffectOnNpcs* const _this)>(0x124F510);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_CallAndActivateEffectOnNpcs* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _abilityInstance)>(0x124FCF0);
	static inline auto FCallNPCs = PreyFunction<void(const ArkNpcAbility_CallAndActivateEffectOnNpcs* const _this, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _abilityInstance)>(0x124F6C0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_CallAndActivateEffectOnNpcs* const _this, ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs& _abilityInstance)>(0x124FC00);
};
#endif // MOONCRASH
