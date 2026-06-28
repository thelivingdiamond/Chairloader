// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/npc/ArkNpcAnimActionObserver.h>
#include <Prey/GameDll/ark/npc/ability/arknpcabilitytemplate.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <_unknown/ArkNpcAbilityInstance.h>
#include <_unknown/ArkNpcBodyStateObserver_Animated.h>
#include <_unknown/ArkNpcBodyStateObserver_Busy.h>
#include <_unknown/ThrowRockData.h>

class ArkNpc;
class ArkNpcAbilityParams;
class ArkNpcAbility_RockThrow;
class ArkNpcAnimAction;
class ArkNpcBodyState_Animated;
enum class EActionFailure;
enum class EArkNpcAbilityPerformanceResult;
struct IPhysicalEntity;

// ArkNpcAbilityInstance_RockThrow
// Header:  Prey/GameDll/ark/npc/ability/rockthrow/ArkNpcAbility_RockThrow.h
class ArkNpcAbilityInstance_RockThrow
	: public ArkNpcAbilityInstance
	, public ArkNpcBodyStateObserver_Busy
	, public ArkNpcBodyStateObserver_Animated
	, public ArkNpcAnimActionObserver
{ // Size=608 (0x260)
public:
	enum class EStage
	{
		PreThrowWait = 0,
		LiftingRocks = 1,
		Throwing = 2,
		WaitingToFinish = 3,
	};

	const ArkNpcAbility_RockThrow* m_pAbility;
	ArkNpc* m_pNpc;
	int m_fragmentId;
	_smart_ptr<ArkNpcAnimAction> m_pAnimAction;
	uint64_t m_contextId;
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	unsigned m_targetEntityId;
	ArkNpcAbilityInstance_RockThrow::EStage m_stage;
	std::vector<ThrowRockData> m_rockInfos;
	float m_preThrowTimer;
	float m_throwTimer;
	std::vector<int> m_constraintIds;
	Vec3 m_npcStartingDirection;
	Vec3 m_npcStartingPosition;
	bool m_bTargetingProxy;

	virtual ~ArkNpcAbilityInstance_RockThrow();
	virtual void OnNpcBodyStateStateExit_Busy();
	virtual void OnNpcBodyStateStateExit_Animated(const ArkNpcBodyState_Animated& _state);
	virtual void OnNpcAnimActionEnter(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionExit(ArkNpcAnimAction& _animAction);
	virtual void OnNpcAnimActionFail(ArkNpcAnimAction& _animAction, EActionFailure _actionFailure);
	virtual void OnNpcAnimActionEvent(ArkNpcAnimAction& _animAction, unsigned _eventCrc);

#if 0
	ArkNpcAbilityInstance_RockThrow();
#endif

	static inline auto FOnNpcBodyStateStateExit_Busy = PreyFunction<void(ArkNpcBodyStateObserver_Busy* const _this)>(0x1268730);
	static inline auto FOnNpcBodyStateStateExit_Animated = PreyFunction<void(ArkNpcBodyStateObserver_Animated* const _this, const ArkNpcBodyState_Animated& _state)>(0x1268720);
	static inline auto FOnNpcAnimActionEnter = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x1268640);
	static inline auto FOnNpcAnimActionExit = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction)>(0x12686E0);
	static inline auto FOnNpcAnimActionFail = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, EActionFailure _actionFailure)>(0x12686E0);
	static inline auto FOnNpcAnimActionEvent = PreyFunction<void(ArkNpcAnimActionObserver* const _this, ArkNpcAnimAction& _animAction, unsigned _eventCrc)>(0x1268650);
};

// ArkNpcAbility_RockThrow
// Header:  Prey/GameDll/ark/npc/ability/rockthrow/ArkNpcAbility_RockThrow.h
class ArkNpcAbility_RockThrow : public ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>
{ // Size=64 (0x40)
public:
	string m_fragmentName;
	string m_throwActionEvent;
	float m_preThrowDuration;
	float m_targetLeadTime;
	ArkAudioTrigger m_impulseAudioTrigger;
	float m_timeBetweenThrows;
	float m_minLiftHeight;
	float m_maxLiftHeight;
	int m_maxNumExpectedRocks;
	float m_minRockDistFromNpc;
	float m_maxRockDistFromNpc;

	static const char* ClassName() { return FClassName(); }
	ArkNpcAbility_RockThrow();
	EArkNpcAbilityPerformanceResult Perform(ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_RockThrow& _abilityInstance) const { return FPerform(this, _npc, _contextId, _params, _abilityInstance); }
	void Update(ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_RockThrow& _abilityInstance) const { FUpdate(this, _npc, _elapsedTime, _abilityInstance); }
	int SetupConstraint(IPhysicalEntity* _pOwnerPhysics, IPhysicalEntity* _pRockPhysics) const { return FSetupConstraint(this, _pOwnerPhysics, _pRockPhysics); }
	void SetUpLevitation(ArkNpcAbilityInstance_RockThrow& _abilityInstance) const { FSetUpLevitation(this, _abilityInstance); }
	bool TryThrowRock(const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance, ThrowRockData& _throwRockInfo) const { return FTryThrowRock(this, _npc, _abilityInstance, _throwRockInfo); }
	void OnThrowFailed(const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance, ThrowRockData& _throwRockInfo) const { FOnThrowFailed(this, _npc, _abilityInstance, _throwRockInfo); }
	void Exit(ArkNpcAbilityInstance_RockThrow& _abilityInstance) const { FExit(this, _abilityInstance); }
	void Done(ArkNpcAbilityInstance_RockThrow& _abilityInstance) const { FDone(this, _abilityInstance); }
	void UpdateLift(ArkNpcAbilityInstance_RockThrow& _abilityInstance, float _elapsedTime) const { FUpdateLift(this, _abilityInstance, _elapsedTime); }
	void UpdateLiftPoints(const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance) const { FUpdateLiftPoints(this, _npc, _abilityInstance); }
	void GenerateRockPositions(const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance) const { FGenerateRockPositions(this, _npc, _abilityInstance); }

#if 0
	void Initialize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RockThrow& _arg1_) const;
	void Finalize(ArkNpc& _arg0_, ArkNpcAbilityInstance_RockThrow& _arg1_) const;
	bool CanBePerformed(const ArkNpc& _arg0_, uint64_t _arg1_, const ArkNpcAbilityParams& _arg2_, const ArkNpcAbilityInstance_RockThrow& _arg3_) const;
	void Interrupt(ArkNpc& _arg0_, ArkNpcAbilityInstance_RockThrow& _arg1_) const;
	void OnStateExit_Busy(ArkNpcAbilityInstance_RockThrow& _arg0_) const;
	void OnStateExit_Animated(ArkNpcAbilityInstance_RockThrow& _arg0_) const;
	void OnNpcAnimActionEnter(ArkNpcAbilityInstance_RockThrow& _arg0_) const;
	void OnNpcAnimActionEvent(ArkNpcAbilityInstance_RockThrow& _arg0_, unsigned _arg1_) const;
	void OnNpcAnimActionExit(ArkNpcAbilityInstance_RockThrow& _arg0_) const;
	void OnNpcAnimActionFail(ArkNpcAbilityInstance_RockThrow& _arg0_, EActionFailure _arg1_) const;
	void StopAllLevitation(ArkNpcAbilityInstance_RockThrow& _arg0_) const;
	void UpdateRockInfos(ArkNpcAbilityInstance_RockThrow& _arg0_) const;
#endif

	static inline auto FClassName = PreyFunction<const char* ()>(0x12678B0);
	static inline auto FArkNpcAbility_RockThrow = PreyFunction<void(ArkNpcAbility_RockThrow* const _this)>(0x1267640);
	static inline auto FPerform = PreyFunction<EArkNpcAbilityPerformanceResult(const ArkNpcAbility_RockThrow* const _this, ArkNpc& _npc, uint64_t _contextId, const ArkNpcAbilityParams& _params, ArkNpcAbilityInstance_RockThrow& _abilityInstance)>(0x12688D0);
	static inline auto FUpdate = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, ArkNpc& _npc, float _elapsedTime, ArkNpcAbilityInstance_RockThrow& _abilityInstance)>(0x1269860);
	static inline auto FSetupConstraint = PreyFunction<int(const ArkNpcAbility_RockThrow* const _this, IPhysicalEntity* _pOwnerPhysics, IPhysicalEntity* _pRockPhysics)>(0x1268F60);
	static inline auto FSetUpLevitation = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, ArkNpcAbilityInstance_RockThrow& _abilityInstance)>(0x1268D40);
	static inline auto FTryThrowRock = PreyFunction<bool(const ArkNpcAbility_RockThrow* const _this, const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance, ThrowRockData& _throwRockInfo)>(0x12691E0);
	static inline auto FOnThrowFailed = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance, ThrowRockData& _throwRockInfo)>(0x1268750);
	static inline auto FExit = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, ArkNpcAbilityInstance_RockThrow& _abilityInstance)>(0x1267D90);
	static inline auto FDone = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, ArkNpcAbilityInstance_RockThrow& _abilityInstance)>(0x1267AE0);
	static inline auto FUpdateLift = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, ArkNpcAbilityInstance_RockThrow& _abilityInstance, float _elapsedTime)>(0x1269DA0);
	static inline auto FUpdateLiftPoints = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance)>(0x126A330);
	static inline auto FGenerateRockPositions = PreyFunction<void(const ArkNpcAbility_RockThrow* const _this, const ArkNpc& _npc, ArkNpcAbilityInstance_RockThrow& _abilityInstance)>(0x1267DD0);
};
#endif // MOONCRASH
