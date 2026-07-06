// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_Earthquake;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_Earthquake
// Header:  Prey/GameDll/ark/npc/ability/earthquake/ArkNpcAbility_Earthquake.h
class ArkNpcAbilityInstance_Earthquake
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=360 (0x168)
public:
	const ArkNpcAbility_Earthquake* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	ArkNpcMovementDesire m_movementDesire;
	int m_fragmentId;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	float m_explodeDelayTimer;
	bool m_bExploding;

	virtual ~ArkNpcAbilityInstance_Earthquake();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_Earthquake();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1253E90);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1253EE0);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1253D60);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1253E50);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x1253D70);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1253E50);
};

// ArkNpcAbility_Earthquake
// Header:  Prey/GameDll/ark/npc/ability/earthquake/ArkNpcAbility_Earthquake.h
class ArkNpcAbility_Earthquake : public ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>
{ // Size=56 (0x38)
public:
	string m_fragmentName;
	string m_damageSourceAttachment;
	uint64_t m_damagePackageId;
	uint64_t m_cameraShakeId;
	float m_damageRadius;
	float m_damageImpulse;
	float m_damageMinimumDistanceScaleAmount;
	float m_explodeDelayDuration;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_Earthquake();
	void OnAnimAction_Explode(ArkNpc& _npc, ArkNpcAbilityInstance_Earthquake& _abilityInstance) const { FOnAnimAction_Explode(this, _npc, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_Earthquake& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_Earthquake& _arg3_) const;
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_Earthquake& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_Earthquake& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
	void OnStateExit_Animated(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
	void OnStateExit_Busy(ArkNpc& _arg0_, ArkNpcAbilityInstance_Earthquake& _arg1_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_Earthquake& _arg0_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_Earthquake& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_Earthquake& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_Earthquake& _arg0_) const;
	bool IsStopped(ArkNpcAbilityInstance_Earthquake& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12537F0);
	static inline auto FArkNpcAbility_Earthquake = PreyFunction<void(ArkNpcAbility_Earthquake* const _this)>(0x1253630);
	static inline auto FOnAnimAction_Explode = PreyFunction<void(const ArkNpcAbility_Earthquake* const _this, ArkNpc& _npc, ArkNpcAbilityInstance_Earthquake& _abilityInstance)>(0x1253C20);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_Earthquake* const _this, ArkNpcAbilityInstance_Earthquake& _abilityInstance)>(0x1253BA0);
};
#endif // MOONCRASH
