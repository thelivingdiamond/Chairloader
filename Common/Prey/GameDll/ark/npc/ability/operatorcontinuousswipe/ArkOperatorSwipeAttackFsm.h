// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/ArkOperatorLaserHelper.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcLookDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkOperatorSwipeState_Base.h>
#include <_unknown/ArkOperatorSwipeState_Charging.h>

class ArkNpc;
class ArkOperatorSwipeAttackFsm;
struct ArkOperatorSwipeFsm_Config;
struct IEntity;

// ArkOperatorSwipeState_Swipe
// Header:  Prey/GameDll/ark/npc/ability/operatorcontinuousswipe/ArkOperatorSwipeAttackFsm.h
class ArkOperatorSwipeState_Swipe : public ArkOperatorSwipeState_Base
{ // Size=504 (0x1F8)
public:
	ArkNpcSpeedDesire m_speedDesire;
	ArkNpcFacingDesire m_facingDesire;
	ArkNpcLookDesire m_aimDesire;
	Vec3 m_currentTarget;
	float m_stateChangeDelayTimer;
	float m_newSwipePositionDelayTimer;
	float m_targetHalfHeight;

	void Update(ArkOperatorSwipeAttackFsm& _fsm, const float _frameTime) { FUpdate(this, _fsm, _frameTime); }
	void SetNewSwipePosition(ArkOperatorSwipeAttackFsm& _fsm) { FSetNewSwipePosition(this, _fsm); }

#if 0
	ArkOperatorSwipeState_Swipe();
	void Enter(ArkOperatorSwipeAttackFsm& _arg0_);
	void Exit(ArkOperatorSwipeAttackFsm& _arg0_);
#endif

	static inline auto FUpdate = PreyFunction<void(ArkOperatorSwipeState_Swipe* const _this, ArkOperatorSwipeAttackFsm& _fsm, const float _frameTime)>(0x1258C40);
	static inline auto FSetNewSwipePosition = PreyFunction<void(ArkOperatorSwipeState_Swipe* const _this, ArkOperatorSwipeAttackFsm& _fsm)>(0x1258500);
};

// ArkOperatorSwipeFsmBase_template_<void>
// Header:  Prey/GameDll/ark/npc/ability/operatorcontinuousswipe/ArkOperatorSwipeAttackFsm.h
class ArkOperatorSwipeFsmBase_template_<void>
{ // Size=688 (0x2B0)
public:
	// ArkOperatorSwipeFsmBase_template_<void>::StateSelector<1>
	// Header:  Prey/GameDll/ark/npc/ability/operatorcontinuousswipe/ArkOperatorSwipeAttackFsm.h
	struct StateSelector<1>
	{ // Size=1 (0x1)
		using StateType = ArkOperatorSwipeState_Charging;

	#if 0
		static ArkOperatorSwipeState_Charging& Get(ArkOperatorSwipeFsmBase_template_<void>& _arg0_);
		static const ArkOperatorSwipeState_Charging& Get(const ArkOperatorSwipeFsmBase_template_<void>& _arg0_);
	#endif
	};

	using EStateId = EStrafeStateId;
	using BaseStateType = ArkOperatorSwipeState_Base;

	static constexpr const uint64_t k_stateCount = 3;
	EStrafeStateId m_currentStateId;
	ArkOperatorSwipeState_Charging m_chargingState;
	ArkOperatorSwipeState_Swipe m_swipeState;

	~ArkOperatorSwipeFsmBase_template_<void>();

#if 0
	ArkOperatorSwipeState_Base& GetState(const EStrafeStateId _arg0_);
	const ArkOperatorSwipeState_Base& GetState(const EStrafeStateId _arg0_) const;
	bool CanTransitionTo(const EStrafeStateId _arg0_) const;
	bool Initiate(const EStrafeStateId _arg0_);
	bool Terminate();
	bool SetCurrentState(const EStrafeStateId _arg0_);
	bool SetCurrentStateIfNot(const EStrafeStateId _arg0_);
	EStrafeStateId GetCurrentStateId() const;
	ArkOperatorSwipeState_Base& GetCurrentState();
	const ArkOperatorSwipeState_Base& GetCurrentState() const;
	bool CurrentStateIs(const EStrafeStateId _arg0_) const;
	bool CurrentStateIsNot(const EStrafeStateId _arg0_) const;
	ArkOperatorSwipeFsmBase_template_<void>();
	void RestoreCurrentState(const EStrafeStateId _arg0_);
	void EnterState(const EStrafeStateId _arg0_);
	void ExitCurrentState();
#endif

	static inline auto FBitNotArkOperatorSwipeFsmBase_template_LessvoidGreater = PreyFunction<void(ArkOperatorSwipeFsmBase_template_<void>* const _this)>(0x1257E60);
};

// ArkOperatorSwipeAttackFsm
// Header:  Prey/GameDll/ark/npc/ability/operatorcontinuousswipe/ArkOperatorSwipeAttackFsm.h
class ArkOperatorSwipeAttackFsm : public ArkOperatorSwipeFsmBase_template_<void>
{ // Size=1608 (0x648)
public:
	const ArkOperatorSwipeFsm_Config* m_pConfig;
	ArkNpc* m_pNpc;
	unsigned m_targetEntityId;
	ArkOperatorLaserHelper m_laserHelper;
	ArkNpcMovementDesire m_movementDesire;
	float m_abilityDurationTimer;
	float m_abilityLostLosTimer;
	float m_abilityAccuracy;
	bool m_bCanSeeTarget;
	bool m_bFailed;

	ArkOperatorSwipeAttackFsm();
	~ArkOperatorSwipeAttackFsm();
	void Initialize(ArkNpc& _npc, const ArkOperatorSwipeFsm_Config& _config) { FInitialize(this, _npc, _config); }
	void Initiate(unsigned _targetEntityId) { FInitiate(this, _targetEntityId); }
	void Terminate() { FTerminate(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	bool IsFinished() const { return FIsFinished(this); }

#if 0
	const ArkOperatorSwipeFsm_Config& GetConfig() const;
	ArkOperatorLaserHelper& GetLaser();
	ArkNpc& GetNpc() const;
	IEntity* GetTargetEntity() const;
	float GetAccuracy() const;
	bool IsPositionForward(const Vec3& _arg0_) const;
	bool CanSeeTarget() const;
	void SetAbilityFailed();
	void UpdateAccuracy(float _arg0_);
	void UpdateLaser(float _arg0_);
	void UpdateCanSeeTarget(float _arg0_);
#endif

	static inline auto FArkOperatorSwipeAttackFsm = PreyFunction<void(ArkOperatorSwipeAttackFsm* const _this)>(0x1257CE0);
	static inline auto FBitNotArkOperatorSwipeAttackFsm = PreyFunction<void(ArkOperatorSwipeAttackFsm* const _this)>(0x1257ED0);
	static inline auto FInitialize = PreyFunction<void(ArkOperatorSwipeAttackFsm* const _this, ArkNpc& _npc, const ArkOperatorSwipeFsm_Config& _config)>(0x1258250);
	static inline auto FInitiate = PreyFunction<void(ArkOperatorSwipeAttackFsm* const _this, unsigned _targetEntityId)>(0x1258340);
	static inline auto FTerminate = PreyFunction<void(ArkOperatorSwipeAttackFsm* const _this)>(0x1258690);
	static inline auto FUpdate = PreyFunction<void(ArkOperatorSwipeAttackFsm* const _this, float _frameTime)>(0x1258750);
	static inline auto FIsFinished = PreyFunction<bool(const ArkOperatorSwipeAttackFsm* const _this)>(0x12584B0);
};
#endif // MOONCRASH
