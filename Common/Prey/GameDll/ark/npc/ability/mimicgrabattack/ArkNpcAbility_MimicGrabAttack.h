// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcCollisionObserver.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_MimicGrabAttack;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct EventPhysCollision;

// ArkNpcAbilityInstance_MimicGrabAttack
// Header:  Prey/GameDll/ark/npc/ability/mimicgrabattack/ArkNpcAbility_MimicGrabAttack.h
class ArkNpcAbilityInstance_MimicGrabAttack
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
	, public ArkNpcCollisionObserver
{ // Size=384 (0x180)
public:
	enum class State
	{
		windUp = 0,
		jumping = 1,
		grabbing = 2,
		failed = 3,
		finished = 4,
	};

	const ArkNpcAbility_MimicGrabAttack* m_pAbility;
	ArkNpc* m_pNpc;
	int m_jumpFragmentId;
	int m_grabFragmentId;
	uint64_t m_contextId;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	unsigned m_targetEntityId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcAbilityInstance_MimicGrabAttack::State m_state;

	virtual ~ArkNpcAbilityInstance_MimicGrabAttack();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcCollision(ArkNpc& _npc, const EventPhysCollision& _collisionEvent);

#if 0
	ArkNpcAbilityInstance_MimicGrabAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1257800);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x1257580);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1257750);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12577B0);
	static inline auto FOnNpcCollision = PreyFunction<void(ArkNpcCollisionObserver* const _this, ArkNpc& _npc, const EventPhysCollision& _collisionEvent)>(0x1257820);
};

// ArkNpcAbility_MimicGrabAttack
// Header:  Prey/GameDll/ark/npc/ability/mimicgrabattack/ArkNpcAbility_MimicGrabAttack.h
class ArkNpcAbility_MimicGrabAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>
{ // Size=48 (0x30)
public:
	string m_jumpFragmentName;
	string m_grabFragmentName;
	float m_jumpAbortDistance;
	float m_jumpAbortCosAngle;
	uint64_t m_grabDamageSignal;
	float m_grabDuration;
	float m_grabDamageCooldown;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_MimicGrabAttack();
	void Done(ArkNpcAbilityInstance_MimicGrabAttack& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MimicGrabAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_MimicGrabAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_MimicGrabAttack& _arg3_) const;
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance_MimicGrabAttack& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_MimicGrabAttack& _arg1_) const;
	void Update(ArkNpc& _arg0_, const float _arg1_, ArkNpcAbilityInstance_MimicGrabAttack& _arg2_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_, EActionFailure _arg1_) const;
	void OnNpcAnimActionJumpStart(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_) const;
	void OnNpcAnimActionJumpAborted(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_) const;
	void OnNpcAnimActionJumpSuccessful(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_) const;
	void OnNpcAnimActionJumpMissed(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_MimicGrabAttack& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12570F0);
	static inline auto FArkNpcAbility_MimicGrabAttack = PreyFunction<void(ArkNpcAbility_MimicGrabAttack* const _this)>(0x1256EF0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_MimicGrabAttack* const _this, ArkNpcAbilityInstance_MimicGrabAttack& _abilityInstance)>(0x12574E0);
};
#endif // MOONCRASH
