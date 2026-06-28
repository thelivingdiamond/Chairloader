// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_LaunchCystoids;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;

// ArkNpcAbilityInstance_LaunchCystoids
// Header:  Prey/GameDll/ark/npc/ability/launchcystoids/ArkNpcAbility_LaunchCystoids.h
class ArkNpcAbilityInstance_LaunchCystoids
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcAnimActionObserver
{ // Size=648 (0x288)
public:
	const ArkNpcAbility_LaunchCystoids* m_pAbility;
	ArkNpc* m_pNpc;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	unsigned m_targetEntityId;
	ELaunchCystoidsAttackStage m_attackStage;
	ArkSimpleTimer m_cystoidLaunchTimer;
	ArkSimpleTimer m_castTimer;
	int m_fragmentId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcSpeedDesire m_speedDesire;
	ArkInterval<float> m_launchTimeInterval;
	int m_numCystoidsLaunched;
	int m_maxNumCystoidLaunches;
	bool m_bAnimFinishedBeforeAbility;

	virtual ~ArkNpcAbilityInstance_LaunchCystoids();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);

#if 0
	ArkNpcAbilityInstance_LaunchCystoids();
#endif

	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1256B00);
	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1256B20);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1256A60);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x1256AC0);
};

// ArkNpcAbility_LaunchCystoids
// Header:  Prey/GameDll/ark/npc/ability/launchcystoids/ArkNpcAbility_LaunchCystoids.h
class ArkNpcAbility_LaunchCystoids : public ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>
{ // Size=88 (0x58)
public:
	string m_fragmentName;
	string m_mindControlledCystoidArchetype;
	string m_cystoidArchetype;
	float m_spawnDistance;
	float m_spawnRadius;
	float m_spawnMaxAngle;
	float m_minTimeBetweenSpawns;
	float m_maxTimeBetweenSpawns;
	int m_minNumCystoids;
	int m_maxNumCystoids;
	float m_expectedRangeMin;
	float m_expectedRangeMax;
	float m_forceAtMinRange;
	float m_forceAtMaxRange;
	float m_launchAngleFloor;
	float m_relativeSpawnHeight;
	float m_castTime;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_LaunchCystoids();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_LaunchCystoids& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void LaunchCystoid(ArkNpcAbilityInstance_LaunchCystoids& _abilityInstance) const { FLaunchCystoid(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_LaunchCystoids& _abilityInstance) const { FDone(this, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_LaunchCystoids& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_LaunchCystoids& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_LaunchCystoids& _arg3_) const;
	void Update(ArkNpc& _arg0_, float _arg1_, ArkNpcAbilityInstance_LaunchCystoids& _arg2_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_LaunchCystoids& _arg1_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_LaunchCystoids& _arg0_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_LaunchCystoids& _arg0_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_LaunchCystoids& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_LaunchCystoids& _arg0_, EActionFailure _arg1_) const;
	void Exit(ArkNpcAbilityInstance_LaunchCystoids& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x1255F00);
	static inline auto FArkNpcAbility_LaunchCystoids = PreyFunction<void(ArkNpcAbility_LaunchCystoids* const _this)>(0x1255B50);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_LaunchCystoids* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_LaunchCystoids& _abilityInstance)>(0x1256B30);
	static inline auto FLaunchCystoid = PreyFunction<void(const ArkNpcAbility_LaunchCystoids* const _this, ArkNpcAbilityInstance_LaunchCystoids& _abilityInstance)>(0x12562D0);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_LaunchCystoids* const _this, ArkNpcAbilityInstance_LaunchCystoids& _abilityInstance)>(0x1256230);
};
#endif // MOONCRASH
