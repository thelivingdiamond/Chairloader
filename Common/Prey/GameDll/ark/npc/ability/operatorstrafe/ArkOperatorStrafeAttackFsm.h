// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/ArkOperatorLaserHelper.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcSpeedDesire.h>
#include <_unknown/ArkOperatorStrafeState_Base.h>
#include <_unknown/ArkOperatorStrafeState_Charging.h>
#include <_unknown/ArkOperatorStrafeState_PreAbilityFacing.h>

class ArkNpc;
class ArkOperatorStrafeAttackFsm;
struct ArkOperatorStrafeFsm_Config;
struct IEntity;

// ArkOperatorStrafeState_Strafe
// Header:  Prey/GameDll/ark/npc/ability/operatorstrafe/ArkOperatorStrafeAttackFsm.h
class ArkOperatorStrafeState_Strafe : public ArkOperatorStrafeState_Base
{ // Size=504 (0x1F8)
public:
	ArkNpcMovementDesire m_movementDesire;
	ArkNpcSpeedDesire m_speedDesire;
	ArkNpcFacingDesire m_facingDesire;

	void Enter(ArkOperatorStrafeAttackFsm& _fsm) { FEnter(this, _fsm); }

#if 0
	ArkOperatorStrafeState_Strafe();
	void Update(ArkOperatorStrafeAttackFsm& _arg0_, const float _arg1_);
	void Exit(ArkOperatorStrafeAttackFsm& _arg0_);
#endif

	static inline auto FEnter = PreyFunction<void(ArkOperatorStrafeState_Strafe* const _this, ArkOperatorStrafeAttackFsm& _fsm)>(0x125B380);
};

// ArkOperatorStrafeFsmBase_template_<void>
// Header:  Prey/GameDll/ark/npc/ability/operatorstrafe/ArkOperatorStrafeAttackFsm.h
class ArkOperatorStrafeFsmBase_template_<void>
{ // Size=1360 (0x550)
public:
	// ArkOperatorStrafeFsmBase_template_<void>::StateSelector<1>
	// Header:  Prey/GameDll/ark/npc/ability/operatorstrafe/ArkOperatorStrafeAttackFsm.h
	struct StateSelector<1>
	{ // Size=1 (0x1)
		using StateType = ArkOperatorStrafeState_PreAbilityFacing;

	#if 0
		static ArkOperatorStrafeState_PreAbilityFacing& Get(ArkOperatorStrafeFsmBase_template_<void>& _arg0_);
		static const ArkOperatorStrafeState_PreAbilityFacing& Get(const ArkOperatorStrafeFsmBase_template_<void>& _arg0_);
	#endif
	};

	using EStateId = ESwipeStateId;
	using BaseStateType = ArkOperatorStrafeState_Base;

	static constexpr const uint64_t k_stateCount = 4;
	ESwipeStateId m_currentStateId;
	ArkOperatorStrafeState_PreAbilityFacing m_facingState;
	ArkOperatorStrafeState_Charging m_chargingState;
	ArkOperatorStrafeState_Strafe m_strafeState;

	~ArkOperatorStrafeFsmBase_template_<void>();

#if 0
	ArkOperatorStrafeState_Base& GetState(const ESwipeStateId _arg0_);
	const ArkOperatorStrafeState_Base& GetState(const ESwipeStateId _arg0_) const;
	bool CanTransitionTo(const ESwipeStateId _arg0_) const;
	bool Initiate(const ESwipeStateId _arg0_);
	bool Terminate();
	bool SetCurrentState(const ESwipeStateId _arg0_);
	bool SetCurrentStateIfNot(const ESwipeStateId _arg0_);
	ESwipeStateId GetCurrentStateId() const;
	ArkOperatorStrafeState_Base& GetCurrentState();
	const ArkOperatorStrafeState_Base& GetCurrentState() const;
	bool CurrentStateIs(const ESwipeStateId _arg0_) const;
	bool CurrentStateIsNot(const ESwipeStateId _arg0_) const;
	ArkOperatorStrafeFsmBase_template_<void>();
	void RestoreCurrentState(const ESwipeStateId _arg0_);
	void EnterState(const ESwipeStateId _arg0_);
	void ExitCurrentState();
#endif

	static inline auto FBitNotArkOperatorStrafeFsmBase_template_LessvoidGreater = PreyFunction<void(ArkOperatorStrafeFsmBase_template_<void>* const _this)>(0x125AA80);
};

// ArkOperatorStrafeAttackFsm
// Header:  Prey/GameDll/ark/npc/ability/operatorstrafe/ArkOperatorStrafeAttackFsm.h
class ArkOperatorStrafeAttackFsm : public ArkOperatorStrafeFsmBase_template_<void>
{ // Size=2048 (0x800)
public:
	const ArkOperatorStrafeFsm_Config* m_pConfig;
	ArkNpc* m_pNpc;
	unsigned m_targetEntityId;
	ArkOperatorLaserHelper m_laserHelper;
	Vec3 m_strafeDestination;
	Vec3 m_strafeDirection;
	bool m_bFinished;

	ArkOperatorStrafeAttackFsm();
	~ArkOperatorStrafeAttackFsm();
	void Initialize(ArkNpc& _npc, const ArkOperatorStrafeFsm_Config& _config) { FInitialize(this, _npc, _config); }
	void Initiate(unsigned _targetEntityId) { FInitiate(this, _targetEntityId); }
	void Terminate() { FTerminate(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	bool IsFinished() const { return FIsFinished(this); }
	bool CalculateStrafe() { return FCalculateStrafe(this); }

#if 0
	const ArkOperatorStrafeFsm_Config& GetConfig() const;
	ArkOperatorLaserHelper& GetLaser();
	ArkNpc& GetNpc() const;
	const Vec3& GetStrafeDestination() const;
	const Vec3& GetStrafeDirection() const;
	IEntity* GetTargetEntity() const;
	void SetAbilityFinished();
	void UpdateLaser(float _arg0_);
#endif

	static inline auto FArkOperatorStrafeAttackFsm = PreyFunction<void(ArkOperatorStrafeAttackFsm* const _this)>(0x125A8E0);
	static inline auto FBitNotArkOperatorStrafeAttackFsm = PreyFunction<void(ArkOperatorStrafeAttackFsm* const _this)>(0x125AB20);
	static inline auto FInitialize = PreyFunction<void(ArkOperatorStrafeAttackFsm* const _this, ArkNpc& _npc, const ArkOperatorStrafeFsm_Config& _config)>(0x125B5C0);
	static inline auto FInitiate = PreyFunction<void(ArkOperatorStrafeAttackFsm* const _this, unsigned _targetEntityId)>(0x125B5D0);
	static inline auto FTerminate = PreyFunction<void(ArkOperatorStrafeAttackFsm* const _this)>(0x125B690);
	static inline auto FUpdate = PreyFunction<void(ArkOperatorStrafeAttackFsm* const _this, float _frameTime)>(0x125B6D0);
	static inline auto FIsFinished = PreyFunction<bool(const ArkOperatorStrafeAttackFsm* const _this)>(0x125B650);
	static inline auto FCalculateStrafe = PreyFunction<bool(ArkOperatorStrafeAttackFsm* const _this)>(0x125B0B0);
};
#endif // MOONCRASH
