// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_RecycleAttack;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_RecycleAttack
// Header:  Prey/GameDll/ark/npc/ability/recycleattack/ArkNpcAbility_RecycleAttack.h
class ArkNpcAbilityInstance_RecycleAttack
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=608 (0x260)
public:
	const ArkNpcAbility_RecycleAttack* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcSpeedDesire m_speedDesire;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	float m_abilityTimer;
	float m_applyPackageTimer;
	float m_coneFullLength;
	bool m_bRecyclerActive;
	bool m_bTransitionCompleted;

	virtual ~ArkNpcAbilityInstance_RecycleAttack();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimFragmentStarted(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_RecycleAttack();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1265C20);
	static inline auto FOnNpcAnimFragmentStarted = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1265C10);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1265BD0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1265BD0);
};

// ArkNpcAbility_RecycleAttack
// Header:  Prey/GameDll/ark/npc/ability/recycleattack/ArkNpcAbility_RecycleAttack.h
class ArkNpcAbility_RecycleAttack : public ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>
{ // Size=152 (0x98)
public:
	string m_suctionAttachment;
	string m_entityGravityEffectName;
	string m_overrideRecycleClasses;
	float m_abilityDuration;
	float m_applyPackageTime;
	float m_gravitationalPullRadius;
	float m_gravitationalPull;
	float m_playerGravitationalPullRadius;
	float m_playerGravitationalPull;
	float m_vibrationAmount;
	float m_vibrationRadius;
	float m_raiseForce;
	float m_raiseRadius;
	uint64_t m_recyclePackageId;
	uint64_t m_recycleKillPackageId;
	float m_recyclingRadius;
	float m_recyclingKillRadius;
	float m_recyclingImpulse;
	ArkInterval<float> m_percentRecycleRange;
	float m_maxTotalScraps;
	float m_maxIngredientsPerType;
	float m_maxTotalIngredients;
	float m_percentScrapPool;
	float m_coneStartRadius;
	float m_coneEndRadius;
	float m_coneStartToEndLength;
	float m_areaRadius;
	float m_turnSpeedOverride;
	float m_stopDistanceFromTarget;
	bool m_bHideCenterObject;
	bool m_bStopOnTargetRecycled;
	bool m_bIgnoreHostilityToTarget;
	bool m_bIgnoreAttentionToTarget;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_RecycleAttack();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_RecycleAttack& _abilityInstance) const { return FPerformOv0(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_RecycleAttack& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	void Interrupt(ArkNpc& _npc, ArkNpcAbilityInstance_RecycleAttack& _abilityInstance) const { FInterrupt(this, _npc, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_RecycleAttack& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, ArkNpcAbilityInstance& _arg3_) const;
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RecycleAttack& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RecycleAttack& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RecycleAttack& _arg3_) const;
	void OnNpcAnimActionFragmentStarted(ArkNpcAbilityInstance_RecycleAttack& _arg0_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_RecycleAttack& _arg0_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_RecycleAttack& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_RecycleAttack& _arg0_) const;
	void Exit(ArkNpcAbilityInstance_RecycleAttack& _arg0_) const;
	void StartRecycler(ArkNpcAbilityInstance_RecycleAttack& _arg0_) const;
	void StopRecycler(ArkNpcAbilityInstance_RecycleAttack& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1265830);
	static inline auto FArkNpcAbility_RecycleAttack = PreyFunction<void(ArkNpcAbility_RecycleAttack* const _this)>(0x1265580);
	static inline auto FPerformOv0 = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_RecycleAttack* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_RecycleAttack& _abilityInstance)>(0x1265C30);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_RecycleAttack* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_RecycleAttack& _abilityInstance)>(0x1266120);
	static inline auto FInterrupt = PreyFunction<void(const ArkNpcAbility_RecycleAttack* const _this, ArkNpc& _npc, ArkNpcAbilityInstance_RecycleAttack& _abilityInstance)>(0x12658C0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_RecycleAttack* const _this, ArkNpcAbilityInstance_RecycleAttack& _abilityInstance)>(0x1265A30);
};
#endif // MOONCRASH
