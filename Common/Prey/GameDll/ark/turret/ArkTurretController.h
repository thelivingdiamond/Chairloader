// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkNpc;
struct IEntity;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/turret/ArkTurretController.h
class ArkTurretController // Id=801AB1F Size=176
{
public:
	enum class ETurretControlStage
	{
		Idle = 0,
		Starting = 1,
		InitialMove = 2,
		HoldingInPlace = 3,
		Recovering_FollowOwnerPath = 4,
		Recovering_MovingToOwner = 5,
		Recovering_RotatingToPosition = 6,
		Recovering_ReturningToPoint = 7,
		Debug = 8,
	};

	unsigned m_controlledTurretId;
	unsigned m_originalTurretFactionIndex;
	uint64_t m_turretFactionId;
	int m_controllerId;
	int m_controlPointIndex;
	float m_heightNoiseTimer;
	float m_rotationNoiseTimer;
	ArkTurretController::ETurretControlStage m_turretControlStage;
	Vec3 m_nextUpdateDesiredPosition;
	Quat m_nextUpdateDesiredRotation;
	Vec3 m_lastTurretPos;
	Vec3 m_lastTurretStuckPos;
	float m_stuckTestTurretDistanceTravelled;
	ArkSimpleTimer m_stuckTestTimer;
	ArkSimpleTimer m_pathTraceTimer;
	ArkSimpleTimer m_targetPositionTooCloseToNpcTimer;
	bool m_bTurretStuck;
	float m_timeStuck;
	float m_timeOutOfDesiredRange;
	std::vector<int> m_constraintIds;
	float m_currentLerpSpeed;
	std::list<Vec3,std::allocator<Vec3>> m_lastOwnerLocations;
	static float s_breakDistanceSq;
	static float s_startRecoveryDistanceSq;
	static float s_lerpMaxSpeed;
	static float s_lerpObstructedMaxSpeed;
	static float s_lerpAcceleration;
	static float s_lerpObstructedAcceleration;
	static float s_turretFloatAmplitude;
	static float s_turretFloatSpeed;
	static float s_turretFloatMaxNoiseAngle;
	static float s_turretFloatNoiseAngleSpeed;
	static float s_turretDropStunDuration;
	static float s_avoidOwnerRadius;
	static float s_approximateTurretRadius;
	static float s_ownerHalfHeight;
	static float s_stuckTestMaxTime;
	static float s_stuckTestMinDistanceSq;
	static float s_adjustedMinMoveSpeed;
	static float s_minTimeBetweenTraces;
	static float s_targetPositionTooCloseTime;
	static float s_expectedTurretHeight;
	static float s_formationResetHoldDistSq;
	static float s_maxStuckTimeAllowed;
	static float s_maxTimeOutOfRangeAllowed;
	static float s_distBetweenLastOwnerLocations;
	static float s_rotatingToPointGiveUpDistanceSq;
	static float s_returningToPointGiveUpDistanceSq;
	static float s_followPathHeightAdjustment;
	static float s_turretTooCloseRadius;
	static uint64_t s_maxNumOwnerPosListEntries;
	
	ArkTurretController();
	void StartControllingTurret(IEntity &_turretEntity, uint64_t _newTurretFaction, unsigned _controllingEntityId) { FStartControllingTurret(this,_turretEntity,_newTurretFaction,_controllingEntityId); }
	void StopControllingTurret() { FStopControllingTurret(this); }
	void SetupConstraint(IPhysicalEntity *_pOwnerPhysics, IPhysicalEntity *_pTurretPhysics) { FSetupConstraint(this,_pOwnerPhysics,_pTurretPhysics); }
	bool IsControllingTurret() const { return FIsControllingTurret(this); }
	Vec3 GetControlledTurretWorldPos() const { return FGetControlledTurretWorldPos(this); }
	void CalcTraceAdjustDesiredPos(Vec3 _startPos, Vec3 &_desiredTracePos, ArkNpc const &_npc, float _minTurretTraceAdjustmentRadius) const { FCalcTraceAdjustDesiredPos(this,_startPos,_desiredTracePos,_npc,_minTurretTraceAdjustmentRadius); }
	bool Update(ArkNpc const &_npc, Vec3 _npcCenter, Vec3 _desriredPos, Vec3 _desiredAimTarget, uint64_t _expectedTurretFactionId, float _turretTraceAdjustmentRadius, bool _bCanCheckTraces, float _elapsedTime) { return FUpdate(this,_npc,_npcCenter,_desriredPos,_desiredAimTarget,_expectedTurretFactionId,_turretTraceAdjustmentRadius,_bCanCheckTraces,_elapsedTime); }
	void SetControlPointIndex(int _controlPointIndex) { FSetControlPointIndex(this,_controlPointIndex); }
	bool HasControlPointIndex() const { return FHasControlPointIndex(this); }
	int GetControlPointIndex() const { return FGetControlPointIndex(this); }
	void SetId(int _id) { FSetId(this,_id); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize(ArkNpc const &_npc) { FPostSerialize(this,_npc); }
	void OnFormationChange() { FOnFormationChange(this); }
	void StartGrabberControl(IEntity &_turretEntity) { FStartGrabberControl(this,_turretEntity); }
	bool UpdateGrabberMovement(IEntity &_entity, ArkNpc const &_npc, Vec3 _target, Quat _desiredRotation, float _elapsedTime) { return FUpdateGrabberMovement(this,_entity,_npc,_target,_desiredRotation,_elapsedTime); }
	void StopGrabberControl(IEntity &_turretEntity) { FStopGrabberControl(this,_turretEntity); }
	void StartHoldingInPlace(IEntity &_turretEntity, Vec3 &_delta) { FStartHoldingInPlace(this,_turretEntity,_delta); }
	bool MoveGrabbedEntityToPoint(IEntity &_entity, Vec3 const &_target, Vec3 const &_delta, Quat const &_desiredRotation, const float _finishedMoveDistance, const float _frameTime, bool &out_bFinishedMovement) { return FMoveGrabbedEntityToPoint(this,_entity,_target,_delta,_desiredRotation,_finishedMoveDistance,_frameTime,out_bFinishedMovement); }
	void UpdateOwnerTracking(IEntity &_ownerEntity, bool _bLimitListSize) { FUpdateOwnerTracking(this,_ownerEntity,_bLimitListSize); }
	bool PushAwayFromOwner(IEntity &_entity, Vec3 _ownerPos) { return FPushAwayFromOwner(this,_entity,_ownerPos); }
	void ResetStuckTimers() { FResetStuckTimers(this); }
	void LoadConfig() { FLoadConfig(this); }
	
#if 0
	void RemoveConstraint(IPhysicalEntity *arg0);
	unsigned GetControlledTurretId() const;
	IEntity const *GetControlledTurretEntity() const;
	void Reset();
	bool IsHoldingInPlace() const;
	bool ShouldDropTurret() const;
	void UpdateTurretTransformAndVelocity(IEntity &arg0, const float arg1);
	bool IsPositionTooCloseToOwner(IEntity &arg0, Vec3 const &arg1, float arg2) const;
	bool IsTurretStuck(IEntity &arg0, IEntity &arg1, float arg2);
	bool IsTurretTooFar(Vec3 const &arg0) const;
	void ResetLerpValues();
#endif
	
	static inline auto FStartControllingTurret = PreyFunction<void(ArkTurretController *const _this, IEntity &_turretEntity, uint64_t _newTurretFaction, unsigned _controllingEntityId)>(0x133F910);
	static inline auto FStopControllingTurret = PreyFunction<void(ArkTurretController *const _this)>(0x1340040);
	static inline auto FSetupConstraint = PreyFunction<void(ArkTurretController *const _this, IPhysicalEntity *_pOwnerPhysics, IPhysicalEntity *_pTurretPhysics)>(0x133F730);
	static inline auto FIsControllingTurret = PreyFunction<bool(ArkTurretController const *const _this)>(0x133E7C0);
	static inline auto FGetControlledTurretWorldPos = PreyFunction<Vec3(ArkTurretController const *const _this)>(0x133E760);
	static inline auto FCalcTraceAdjustDesiredPos = PreyFunction<void(ArkTurretController const *const _this, Vec3 _startPos, Vec3 &_desiredTracePos, ArkNpc const &_npc, float _minTurretTraceAdjustmentRadius)>(0x133E230);
	static inline auto FUpdate = PreyFunction<bool(ArkTurretController *const _this, ArkNpc const &_npc, Vec3 _npcCenter, Vec3 _desriredPos, Vec3 _desiredAimTarget, uint64_t _expectedTurretFactionId, float _turretTraceAdjustmentRadius, bool _bCanCheckTraces, float _elapsedTime)>(0x1340420);
	static inline auto FSetControlPointIndex = PreyFunction<void(ArkTurretController *const _this, int _controlPointIndex)>(0x7062B0);
	static inline auto FHasControlPointIndex = PreyFunction<bool(ArkTurretController const *const _this)>(0x133E7B0);
	static inline auto FGetControlPointIndex = PreyFunction<int(ArkTurretController const *const _this)>(0xD9C610);
	static inline auto FSetId = PreyFunction<void(ArkTurretController *const _this, int _id)>(0x133F720);
	static inline auto FSerialize = PreyFunction<void(ArkTurretController *const _this, TSerialize _ser)>(0x133F4B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurretController *const _this, ArkNpc const &_npc)>(0x133F1F0);
	static inline auto FOnFormationChange = PreyFunction<void(ArkTurretController *const _this)>(0x133F1E0);
	static inline auto FStartGrabberControl = PreyFunction<void(ArkTurretController *const _this, IEntity &_turretEntity)>(0x133FCF0);
	static inline auto FUpdateGrabberMovement = PreyFunction<bool(ArkTurretController *const _this, IEntity &_entity, ArkNpc const &_npc, Vec3 _target, Quat _desiredRotation, float _elapsedTime)>(0x13410B0);
	static inline auto FStopGrabberControl = PreyFunction<void(ArkTurretController *const _this, IEntity &_turretEntity)>(0x1340250);
	static inline auto FStartHoldingInPlace = PreyFunction<void(ArkTurretController *const _this, IEntity &_turretEntity, Vec3 &_delta)>(0x133FF90);
	static inline auto FMoveGrabbedEntityToPoint = PreyFunction<bool(ArkTurretController *const _this, IEntity &_entity, Vec3 const &_target, Vec3 const &_delta, Quat const &_desiredRotation, const float _finishedMoveDistance, const float _frameTime, bool &out_bFinishedMovement)>(0x133EC90);
	static inline auto FUpdateOwnerTracking = PreyFunction<void(ArkTurretController *const _this, IEntity &_ownerEntity, bool _bLimitListSize)>(0x1342360);
	static inline auto FPushAwayFromOwner = PreyFunction<bool(ArkTurretController *const _this, IEntity &_entity, Vec3 _ownerPos)>(0x133F310);
	static inline auto FResetStuckTimers = PreyFunction<void(ArkTurretController *const _this)>(0x133F480);
	static inline auto FLoadConfig = PreyFunction<void(ArkTurretController *const _this)>(0x133E7D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkNpc;
struct IEntity;
struct IPhysicalEntity;

// ArkTurretController
// Header:  Prey/GameDll/ark/turret/ArkTurretController.h
class ArkTurretController
{ // Size=176 (0xB0)
public:
	enum class ETurretControlStage
	{
		Idle = 0,
		Starting = 1,
		InitialMove = 2,
		HoldingInPlace = 3,
		Recovering_FollowOwnerPath = 4,
		Recovering_MovingToOwner = 5,
		Recovering_RotatingToPosition = 6,
		Recovering_ReturningToPoint = 7,
		Debug = 8,
	};

	unsigned m_controlledTurretId;
	unsigned m_originalTurretFactionIndex;
	uint64_t m_turretFactionId;
	int m_controllerId;
	int m_controlPointIndex;
	float m_heightNoiseTimer;
	float m_rotationNoiseTimer;
	ArkTurretController::ETurretControlStage m_turretControlStage;
	Vec3 m_nextUpdateDesiredPosition;
	Quat m_nextUpdateDesiredRotation;
	Vec3 m_lastTurretPos;
	Vec3 m_lastTurretStuckPos;
	float m_stuckTestTurretDistanceTravelled;
	ArkSimpleTimer m_stuckTestTimer;
	ArkSimpleTimer m_pathTraceTimer;
	ArkSimpleTimer m_targetPositionTooCloseToNpcTimer;
	bool m_bTurretStuck;
	float m_timeStuck;
	float m_timeOutOfDesiredRange;
	std::vector<int> m_constraintIds;
	float m_currentLerpSpeed;
	std::list<Vec3_tpl<float>,std::allocator<Vec3_tpl<float> > > m_lastOwnerLocations;
	static inline auto s_breakDistanceSq = PreyGlobal<float>(0x23E3708);
	static inline auto s_startRecoveryDistanceSq = PreyGlobal<float>(0x23E370C);
	static inline auto s_lerpMaxSpeed = PreyGlobal<float>(0x23E3710);
	static inline auto s_lerpObstructedMaxSpeed = PreyGlobal<float>(0x23E3714);
	static inline auto s_lerpAcceleration = PreyGlobal<float>(0x23E3718);
	static inline auto s_lerpObstructedAcceleration = PreyGlobal<float>(0x23E371C);
	static inline auto s_turretFloatAmplitude = PreyGlobal<float>(0x23E3720);
	static inline auto s_turretFloatSpeed = PreyGlobal<float>(0x23E3724);
	static inline auto s_turretFloatMaxNoiseAngle = PreyGlobal<float>(0x23E3728);
	static inline auto s_turretFloatNoiseAngleSpeed = PreyGlobal<float>(0x23E372C);
	static inline auto s_turretDropStunDuration = PreyGlobal<float>(0x23E3730);
	static inline auto s_avoidOwnerRadius = PreyGlobal<float>(0x23E3734);
	static inline auto s_approximateTurretRadius = PreyGlobal<float>(0x23E3738);
	static inline auto s_ownerHalfHeight = PreyGlobal<float>(0x23E373C);
	static inline auto s_stuckTestMaxTime = PreyGlobal<float>(0x23E3740);
	static inline auto s_stuckTestMinDistanceSq = PreyGlobal<float>(0x23E3744);
	static inline auto s_adjustedMinMoveSpeed = PreyGlobal<float>(0x23E3748);
	static inline auto s_minTimeBetweenTraces = PreyGlobal<float>(0x23E374C);
	static inline auto s_targetPositionTooCloseTime = PreyGlobal<float>(0x23E3750);
	static inline auto s_expectedTurretHeight = PreyGlobal<float>(0x23E3754);
	static inline auto s_formationResetHoldDistSq = PreyGlobal<float>(0x23E3758);
	static inline auto s_maxStuckTimeAllowed = PreyGlobal<float>(0x23E375C);
	static inline auto s_maxTimeOutOfRangeAllowed = PreyGlobal<float>(0x23E3760);
	static inline auto s_distBetweenLastOwnerLocations = PreyGlobal<float>(0x23E3764);
	static inline auto s_rotatingToPointGiveUpDistanceSq = PreyGlobal<float>(0x23E3768);
	static inline auto s_returningToPointGiveUpDistanceSq = PreyGlobal<float>(0x23E376C);
	static inline auto s_followPathHeightAdjustment = PreyGlobal<float>(0x23E3770);
	static inline auto s_turretTooCloseRadius = PreyGlobal<float>(0x23E3774);
	static inline auto s_maxNumOwnerPosListEntries = PreyGlobal<uint64_t>(0x23E3778);

	ArkTurretController();
	void StartControllingTurret(IEntity& _turretEntity, uint64_t _newTurretFaction, unsigned _controllingEntityId) { FStartControllingTurret(this, _turretEntity, _newTurretFaction, _controllingEntityId); }
	void StopControllingTurret() { FStopControllingTurret(this); }
	void SetupConstraint(IPhysicalEntity* _pOwnerPhysics, IPhysicalEntity* _pTurretPhysics) { FSetupConstraint(this, _pOwnerPhysics, _pTurretPhysics); }
	bool IsControllingTurret() const { return FIsControllingTurret(this); }
	Vec3 GetControlledTurretWorldPos() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetControlledTurretWorldPos(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	unsigned GetControlledTurretId() const { return FGetControlledTurretId(this); }
	void CalcTraceAdjustDesiredPos(Vec3 _startPos, Vec3& _desiredTracePos, const ArkNpc& _npc, float _minTurretTraceAdjustmentRadius) const { FCalcTraceAdjustDesiredPos(this, _startPos, _desiredTracePos, _npc, _minTurretTraceAdjustmentRadius); }
	bool Update(const ArkNpc& _npc, Vec3 _npcCenter, Vec3 _desriredPos, Vec3 _desiredAimTarget, uint64_t _expectedTurretFactionId, float _turretTraceAdjustmentRadius, bool _bCanCheckTraces, float _elapsedTime) { return FUpdate(this, _npc, _npcCenter, _desriredPos, _desiredAimTarget, _expectedTurretFactionId, _turretTraceAdjustmentRadius, _bCanCheckTraces, _elapsedTime); }
	void SetControlPointIndex(int _controlPointIndex) { FSetControlPointIndex(this, _controlPointIndex); }
	bool HasControlPointIndex() const { return FHasControlPointIndex(this); }
	int GetControlPointIndex() const { return FGetControlPointIndex(this); }
	void SetId(int _id) { FSetId(this, _id); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize(const ArkNpc& _npc) { FPostSerialize(this, _npc); }
	void OnFormationChange() { FOnFormationChange(this); }
	void StartGrabberControl(IEntity& _turretEntity) { FStartGrabberControl(this, _turretEntity); }
	bool UpdateGrabberMovement(IEntity& _entity, const ArkNpc& _npc, Vec3 _target, Quat _desiredRotation, float _elapsedTime) { return FUpdateGrabberMovement(this, _entity, _npc, _target, _desiredRotation, _elapsedTime); }
	void StopGrabberControl(IEntity& _turretEntity) { FStopGrabberControl(this, _turretEntity); }
	void StartHoldingInPlace(IEntity& _turretEntity, Vec3& _delta) { FStartHoldingInPlace(this, _turretEntity, _delta); }
	bool MoveGrabbedEntityToPoint(IEntity& _entity, const Vec3& _target, const Vec3& _delta, const Quat& _desiredRotation, const float _finishedMoveDistance, const float _frameTime, bool& out_bFinishedMovement) { return FMoveGrabbedEntityToPoint(this, _entity, _target, _delta, _desiredRotation, _finishedMoveDistance, _frameTime, out_bFinishedMovement); }
	void UpdateOwnerTracking(IEntity& _ownerEntity, bool _bLimitListSize) { FUpdateOwnerTracking(this, _ownerEntity, _bLimitListSize); }
	bool PushAwayFromOwner(IEntity& _entity, const Vec3 _ownerPos) { return FPushAwayFromOwner(this, _entity, _ownerPos); }
	void ResetStuckTimers() { FResetStuckTimers(this); }
	void LoadConfig() { FLoadConfig(this); }

#if 0
	void RemoveConstraint(IPhysicalEntity* _arg0_);
	const IEntity* GetControlledTurretEntity() const;
	void Reset();
	bool IsHoldingInPlace() const;
	bool ShouldDropTurret() const;
	void UpdateTurretTransformAndVelocity(IEntity& _arg0_, const float _arg1_);
	bool IsPositionTooCloseToOwner(IEntity& _arg0_, const Vec3& _arg1_, float _arg2_) const;
	bool IsTurretStuck(IEntity& _arg0_, IEntity& _arg1_, float _arg2_);
	bool IsTurretTooFar(const Vec3& _arg0_) const;
	void ResetLerpValues();
#endif

	static inline auto FArkTurretControllerOv2 = PreyFunction<void(ArkTurretController* const _this)>(0x141A5E0);
	static inline auto FStartControllingTurret = PreyFunction<void(ArkTurretController* const _this, IEntity& _turretEntity, uint64_t _newTurretFaction, unsigned _controllingEntityId)>(0x141BD90);
	static inline auto FStopControllingTurret = PreyFunction<void(ArkTurretController* const _this)>(0x141C4D0);
	static inline auto FSetupConstraint = PreyFunction<void(ArkTurretController* const _this, IPhysicalEntity* _pOwnerPhysics, IPhysicalEntity* _pTurretPhysics)>(0x141BB10);
	static inline auto FIsControllingTurret = PreyFunction<bool(const ArkTurretController* const _this)>(0x141ABA0);
	static inline auto FGetControlledTurretWorldPos = PreyFunction<Vec3*(const ArkTurretController* const _this, Vec3* _return_value_)>(0x141AB40);
	static inline auto FGetControlledTurretId = PreyFunction<unsigned(const ArkTurretController* const _this)>(0x12A08E0);
	static inline auto FCalcTraceAdjustDesiredPos = PreyFunction<void(const ArkTurretController* const _this, Vec3 _startPos, Vec3& _desiredTracePos, const ArkNpc& _npc, float _minTurretTraceAdjustmentRadius)>(0x141A6B0);
	static inline auto FUpdate = PreyFunction<bool(ArkTurretController* const _this, const ArkNpc& _npc, Vec3 _npcCenter, Vec3 _desriredPos, Vec3 _desiredAimTarget, uint64_t _expectedTurretFactionId, float _turretTraceAdjustmentRadius, bool _bCanCheckTraces, float _elapsedTime)>(0x141C8B0);
	static inline auto FSetControlPointIndex = PreyFunction<void(ArkTurretController* const _this, int _controlPointIndex)>(0x141BB00);
	static inline auto FHasControlPointIndex = PreyFunction<bool(const ArkTurretController* const _this)>(0x141AB90);
	static inline auto FGetControlPointIndex = PreyFunction<int(const ArkTurretController* const _this)>(0x11883D0);
	static inline auto FSetId = PreyFunction<void(ArkTurretController* const _this, int _id)>(0x7CA210);
	static inline auto FSerialize = PreyFunction<void(ArkTurretController* const _this, TSerialize _ser)>(0x141B890);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurretController* const _this, const ArkNpc& _npc)>(0x141B5D0);
	static inline auto FOnFormationChange = PreyFunction<void(ArkTurretController* const _this)>(0x141B5C0);
	static inline auto FStartGrabberControl = PreyFunction<void(ArkTurretController* const _this, IEntity& _turretEntity)>(0x141C170);
	static inline auto FUpdateGrabberMovement = PreyFunction<bool(ArkTurretController* const _this, IEntity& _entity, const ArkNpc& _npc, Vec3 _target, Quat _desiredRotation, float _elapsedTime)>(0x141D540);
	static inline auto FStopGrabberControl = PreyFunction<void(ArkTurretController* const _this, IEntity& _turretEntity)>(0x141C6E0);
	static inline auto FStartHoldingInPlace = PreyFunction<void(ArkTurretController* const _this, IEntity& _turretEntity, Vec3& _delta)>(0x141C420);
	static inline auto FMoveGrabbedEntityToPoint = PreyFunction<bool(ArkTurretController* const _this, IEntity& _entity, const Vec3& _target, const Vec3& _delta, const Quat& _desiredRotation, const float _finishedMoveDistance, const float _frameTime, bool& out_bFinishedMovement)>(0x141B070);
	static inline auto FUpdateOwnerTracking = PreyFunction<void(ArkTurretController* const _this, IEntity& _ownerEntity, bool _bLimitListSize)>(0x141E7F0);
	static inline auto FPushAwayFromOwner = PreyFunction<bool(ArkTurretController* const _this, IEntity& _entity, const Vec3 _ownerPos)>(0x141B6F0);
	static inline auto FResetStuckTimers = PreyFunction<void(ArkTurretController* const _this)>(0x141B860);
	static inline auto FLoadConfig = PreyFunction<void(ArkTurretController* const _this)>(0x141ABB0);
};
#endif // !MOONCRASH
