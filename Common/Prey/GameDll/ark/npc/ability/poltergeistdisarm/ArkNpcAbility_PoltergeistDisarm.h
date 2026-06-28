// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/anim/arknpcmultistageanimactions.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_PoltergeistDisarm;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
class CNpcMultiStageAction;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
enum class EArkNpcFacingDesireCallbackEvent;

// ArkNpcAbilityInstance_PoltergeistDisarm
// Header:  Prey/GameDll/ark/npc/ability/poltergeistdisarm/ArkNpcAbility_PoltergeistDisarm.h
class ArkNpcAbilityInstance_PoltergeistDisarm
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=536 (0x218)
public:
	enum class EState
	{
		none = 0,
		facing = 1,
		intro = 2,
		struggle = 3,
		outro = 4,
	};

	const ArkNpcAbility_PoltergeistDisarm* m_pAbility;
	ArkNpc* m_pNpc;
	int m_fragmentId;
	uint64_t m_contextId;
	ArkNpcAbilityInstance_PoltergeistDisarm::EState m_state;
	unsigned m_targetEntityId;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcMovementDesire m_movementDesire;
	float m_facingTimer;
	float m_appearanceTimer;
	_smart_ptr<CNpcMultiStageAction> m_pAnimAction;
	int m_imputModeHandle;

	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	void FacingDesireCallback(const EArkNpcFacingDesireCallbackEvent _event) { FFacingDesireCallback(this, _event); }

#if 0
	ArkNpcAbilityInstance_PoltergeistDisarm();
	void OnNpcAnimActionMiddle(ArkNpcAnimAction& _arg0_);
	void OnNpcAnimActionEnd(ArkNpcAnimAction& _arg0_);
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x125C6A0);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1333E90);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x125C660);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x125C660);
	static inline auto FFacingDesireCallback = PreyFunction<void(ArkNpcAbilityInstance_PoltergeistDisarm* const _this, const EArkNpcFacingDesireCallbackEvent _event)>(0x125C440);
};

// ArkNpcAbility_PoltergeistDisarm
// Header:  Prey/GameDll/ark/npc/ability/poltergeistdisarm/ArkNpcAbility_PoltergeistDisarm.h
class ArkNpcAbility_PoltergeistDisarm : public ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>
{ // Size=40 (0x28)
public:
	string m_fragmentName;
	float m_facingTimeout;
	float m_appearanceDelay;
	float m_duration;
	float m_impulse;
	float m_playerFacingAngle;
	float m_playerFacingDuration;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_PoltergeistDisarm();
	bool BeginAnimSequence(ArkNpcAbilityInstance_PoltergeistDisarm& _abilityInstance) const { return FBeginAnimSequence(this, _abilityInstance); }
	void Exit(ArkNpcAbilityInstance_PoltergeistDisarm& _abilityInstance) const { FExit(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_PoltergeistDisarm& _abilityInstance) const { FDone(this, _abilityInstance); }
	bool IsPlayerReadyToDisarm() const { return FIsPlayerReadyToDisarm(this); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_PoltergeistDisarm& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg1_) const;
	void OnNpcBodyStateStateExit_Animated(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_, const ArkNpcBodyState_Animated& _arg1_) const;
	void OnNpcBodyStateStateExit_Busy(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_) const;
	void OnNpcAnimActionMiddle(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_, ArkNpcAnimAction& _arg1_) const;
	void OnNpcAnimActionEnd(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_, ArkNpcAnimAction& _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_, ArkNpcAnimAction& _arg1_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_, ArkNpcAnimAction& _arg1_, EActionFailure _arg2_) const;
	void FacingDesireCallback(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_, const EArkNpcFacingDesireCallbackEvent _arg1_) const;
	void BeginStruggle(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_) const;
	void Disarm(ArkNpcAbilityInstance_PoltergeistDisarm& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x125BD30);
	static inline auto FArkNpcAbility_PoltergeistDisarm = PreyFunction<void(ArkNpcAbility_PoltergeistDisarm* const _this)>(0x125B9E0);
	static inline auto FBeginAnimSequence = PreyFunction<bool(const ArkNpcAbility_PoltergeistDisarm* const _this, ArkNpcAbilityInstance_PoltergeistDisarm& _abilityInstance)>(0x125BBA0);
	static inline auto FExit = PreyFunction<void(const ArkNpcAbility_PoltergeistDisarm* const _this, ArkNpcAbilityInstance_PoltergeistDisarm& _abilityInstance)>(0x125C2F0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_PoltergeistDisarm* const _this, ArkNpcAbilityInstance_PoltergeistDisarm& _abilityInstance)>(0x125C190);
	static inline auto FIsPlayerReadyToDisarm = PreyFunction<bool(const ArkNpcAbility_PoltergeistDisarm* const _this)>(0x125C4C0);
};

// PoltergeistDisarmAnimAction
// Header:  Prey/GameDll/ark/npc/ability/poltergeistdisarm/ArkNpcAbility_PoltergeistDisarm.h
class PoltergeistDisarmAnimAction : public CNpcMultiStageDurationAction
{ // Size=208 (0xD0)
public:
	ArkNpcAbilityInstance_PoltergeistDisarm* m_pAbilityInstance;

	virtual void OnMiddle();
	virtual void OnEnd();

#if 0
	PoltergeistDisarmAnimAction(ArkNpc& _arg0_, int _arg1_, float _arg2_, ArkNpcAbilityInstance_PoltergeistDisarm& _arg3_);
#endif

	static inline auto FOnMiddle = PreyFunction<void(PoltergeistDisarmAnimAction* const _this)>(0x125C5B0);
	static inline auto FOnEnd = PreyFunction<void(PoltergeistDisarmAnimAction* const _this)>(0x125C540);
};
#endif // MOONCRASH
