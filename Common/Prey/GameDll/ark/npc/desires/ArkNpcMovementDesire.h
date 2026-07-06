// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/MovementStyle.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireTarget.h>
#include <_unknown/ArkDelegate.h>
#include <_unknown/ArkNpcDesireBase.h>
#include <_unknown/MovementRequestResult.h>

enum class EArkNpcMovementDesirePriority;

// ArkNpcMovementDesire
// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
class ArkNpcMovementDesire : public ArkNpcDesireBase<ArkNpcMovementDesireManager,ArkNpcMovementDesire,enum EArkNpcMovementDesirePriority>
{ // Size=248 (0xF8)
public:
	// ArkNpcMovementDesire::DestinationParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class DestinationParam
	{ // Size=8 (0x8)
	public:
		const ArkNpcDesireTarget& m_destination;

		DestinationParam(const ArkNpcDesireTarget& _destination);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FDestinationParam = PreyFunction<void(ArkNpcMovementDesire::DestinationParam* const _this, const ArkNpcDesireTarget& _destination)>(0x14124F0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::DestinationParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646D00);
	};

	// ArkNpcMovementDesire::EnableNavMeshQueryParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class EnableNavMeshQueryParam
	{ // Size=12 (0xC)
	public:
		float m_navQueryHorizontalRadius;
		float m_navQueryBelowThreshold;
		float m_navQueryAboveThreshold;

		EnableNavMeshQueryParam();
		EnableNavMeshQueryParam(float _navQueryHorizontalRadius, float _navQueryBelowThreshold, float _navQueryAboveThreshold);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FEnableNavMeshQueryParamOv1 = PreyFunction<void(ArkNpcMovementDesire::EnableNavMeshQueryParam* const _this)>(0x1646C00);
		static inline auto FEnableNavMeshQueryParamOv0 = PreyFunction<void(ArkNpcMovementDesire::EnableNavMeshQueryParam* const _this, float _navQueryHorizontalRadius, float _navQueryBelowThreshold, float _navQueryAboveThreshold)>(0x1646BE0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::EnableNavMeshQueryParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646E10);
	};

	// ArkNpcMovementDesire::DisableNavMeshQueryParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class DisableNavMeshQueryParam
	{ // Size=1 (0x1)
	public:
		DisableNavMeshQueryParam();
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FDisableNavMeshQueryParam = PreyFunction<void(ArkNpcMovementDesire::DisableNavMeshQueryParam* const _this)>(0x3DAC90);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::DisableNavMeshQueryParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646DF0);
	};

	// ArkNpcMovementDesire::ForcePathParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class ForcePathParam
	{ // Size=1 (0x1)
	public:
		bool m_bForce;

		ForcePathParam(bool _bForce);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FForcePathParam = PreyFunction<void(ArkNpcMovementDesire::ForcePathParam* const _this, bool _bForce)>(0x1646C40);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::ForcePathParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646E80);
	};

	// ArkNpcMovementDesire::ForceGoToNavMeshParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class ForceGoToNavMeshParam
	{ // Size=1 (0x1)
	public:
	#if 0
		ForceGoToNavMeshParam();
		bool Set(ArkNpcMovementDesire& _arg0_) const;
	#endif
	};

	// ArkNpcMovementDesire::StanceParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class StanceParam
	{ // Size=4 (0x4)
	public:
		MovementStyle::Stance m_stance;

		StanceParam(MovementStyle::Stance _stance);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FStanceParam = PreyFunction<void(ArkNpcMovementDesire::StanceParam* const _this, MovementStyle::Stance _stance)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::StanceParam* const _this, ArkNpcMovementDesire& _desire)>(0x1647030);
	};

	// ArkNpcMovementDesire::SpeedLiteralParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class SpeedLiteralParam
	{ // Size=4 (0x4)
	public:
		float m_overrideSpeedLiteral;

		SpeedLiteralParam(float _overrideSpeedLiteral);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FSpeedLiteralParam = PreyFunction<void(ArkNpcMovementDesire::SpeedLiteralParam* const _this, float _overrideSpeedLiteral)>(0x1646AB0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::SpeedLiteralParam* const _this, ArkNpcMovementDesire& _desire)>(0x1647010);
	};

	// ArkNpcMovementDesire::AccelLiteralParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class AccelLiteralParam
	{ // Size=4 (0x4)
	public:
		float m_overrideAccelLiteral;

		AccelLiteralParam(float _overrideAccelLiteral);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FAccelLiteralParam = PreyFunction<void(ArkNpcMovementDesire::AccelLiteralParam* const _this, float _overrideAccelLiteral)>(0x1646AB0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::AccelLiteralParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646CC0);
	};

	// ArkNpcMovementDesire::DecelLiteralParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class DecelLiteralParam
	{ // Size=4 (0x4)
	public:
		float m_overrideDecelLiteral;

	#if 0
		DecelLiteralParam(float _arg0_);
		bool Set(ArkNpcMovementDesire& _arg0_) const;
	#endif
	};

	// ArkNpcMovementDesire::StopDistanceParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class StopDistanceParam
	{ // Size=4 (0x4)
	public:
		float m_stopDistance;

		StopDistanceParam(float _stopDistance);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FStopDistanceParam = PreyFunction<void(ArkNpcMovementDesire::StopDistanceParam* const _this, float _stopDistance)>(0x1646AB0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::StopDistanceParam* const _this, ArkNpcMovementDesire& _desire)>(0x1647040);
	};

	// ArkNpcMovementDesire::UseExactPositionParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class UseExactPositionParam
	{ // Size=20 (0x14)
	public:
		bool m_bEnable;
		float m_rotationStartDist;
		Vec3 m_dirAtTarget;

		UseExactPositionParam(bool _bEnable, const Vec3& _dirAtTarget, float _rotationStartDist);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FUseExactPositionParamOv2 = PreyFunction<void(ArkNpcMovementDesire::UseExactPositionParam* const _this, bool _bEnable, const Vec3& _dirAtTarget, float _rotationStartDist)>(0x1646C80);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::UseExactPositionParam* const _this, ArkNpcMovementDesire& _desire)>(0x1647080);
	};

	// ArkNpcMovementDesire::ShiftParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class ShiftParam
	{ // Size=24 (0x18)
	public:
		bool m_bShift;
		float m_beforeShiftDist;
		float m_afterShiftDist;
		MovementStyle::ShiftAnimation m_shiftAnims;
		float m_telegraphTime;
		MovementStyle::ShiftType m_shiftType;

		ShiftParam(bool _bShift, float _beforeShiftDist, float _afterShiftDist, MovementStyle::ShiftAnimation _shiftAnims, float _telegraphTime, MovementStyle::ShiftType _shiftType);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FShiftParam = PreyFunction<void(ArkNpcMovementDesire::ShiftParam* const _this, bool _bShift, float _beforeShiftDist, float _afterShiftDist, MovementStyle::ShiftAnimation _shiftAnims, float _telegraphTime, MovementStyle::ShiftType _shiftType)>(0x1646C50);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::ShiftParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646F70);
	};

	// ArkNpcMovementDesire::JumpParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class JumpParam
	{ // Size=16 (0x10)
	public:
		MovementStyle::JumpStyle m_jumpStyle;
		MovementStyle::JumpGoal m_jumpGoal;
		float m_jumpDist;
		float m_goalPathDist;

		JumpParam(MovementStyle::JumpStyle _jumpStyle, MovementStyle::JumpGoal _jumpGoal, float _jumpDist, float _goalPathDist);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FJumpParam = PreyFunction<void(ArkNpcMovementDesire::JumpParam* const _this, MovementStyle::JumpStyle _jumpStyle, MovementStyle::JumpGoal _jumpGoal, float _jumpDist, float _goalPathDist)>(0x1646C20);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::JumpParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646EC0);
	};

	// ArkNpcMovementDesire::HoverParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class HoverParam
	{ // Size=4 (0x4)
	public:
		MovementStyle::HoverStyle m_style;

		HoverParam(MovementStyle::HoverStyle _style);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FHoverParam = PreyFunction<void(ArkNpcMovementDesire::HoverParam* const _this, MovementStyle::HoverStyle _style)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::HoverParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646EA0);
	};

	// ArkNpcMovementDesire::ContinueMovingParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class ContinueMovingParam
	{ // Size=1 (0x1)
	public:
		bool m_bEnable;

		ContinueMovingParam(bool _bEnable);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FContinueMovingParam = PreyFunction<void(ArkNpcMovementDesire::ContinueMovingParam* const _this, bool _bEnable)>(0x1646C40);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::ContinueMovingParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646CE0);
	};

	// ArkNpcMovementDesire::ScriptMoveParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class ScriptMoveParam
	{ // Size=1 (0x1)
	public:
		bool m_bScriptMove;

		ScriptMoveParam(bool _bEnable);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FScriptMoveParam = PreyFunction<void(ArkNpcMovementDesire::ScriptMoveParam* const _this, bool _bEnable)>(0x1646C40);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::ScriptMoveParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646F50);
	};

	// ArkNpcMovementDesire::ObstacleAvoidanceParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class ObstacleAvoidanceParam
	{ // Size=4 (0x4)
	public:
		EArkObstacleAvoidanceUrgency m_urgency;

		ObstacleAvoidanceParam(EArkObstacleAvoidanceUrgency _urgency);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FObstacleAvoidanceParam = PreyFunction<void(ArkNpcMovementDesire::ObstacleAvoidanceParam* const _this, EArkObstacleAvoidanceUrgency _urgency)>(0x156BBD0);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::ObstacleAvoidanceParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646F30);
	};

	// ArkNpcMovementDesire::ErrorParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class ErrorParam
	{ // Size=1 (0x1)
	public:
		bool m_bAllowTeleportToNavMesh;

		ErrorParam(bool _bAllowTeleportToNavMesh);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FErrorParam = PreyFunction<void(ArkNpcMovementDesire::ErrorParam* const _this, bool _bAllowTeleportToNavMesh)>(0x1646C40);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::ErrorParam* const _this, ArkNpcMovementDesire& _desire)>(0x1646E60);
	};

	// ArkNpcMovementDesire::StrafeParam
	// Header:  Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h
	class StrafeParam
	{ // Size=1 (0x1)
	public:
		bool m_bAllowStrafe;

		StrafeParam(bool _bAllowStrafe);
		bool Set(ArkNpcMovementDesire& _desire) const { return FSet(this, _desire); }

		static inline auto FStrafeParam = PreyFunction<void(ArkNpcMovementDesire::StrafeParam* const _this, bool _bAllowStrafe)>(0x1646C40);
		static inline auto FSet = PreyFunction<bool(const ArkNpcMovementDesire::StrafeParam* const _this, ArkNpcMovementDesire& _desire)>(0x1647060);
	};

	using Callback = ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)>;

	ArkNpcDesireTarget m_destination;
	bool m_bQueryNavSystem;
	float m_navQueryHorizontalRadius;
	float m_navQueryBelowThreshold;
	float m_navQueryAboveThreshold;
	bool m_bForcePath;
	bool m_bForceGoToNavMesh;
	int m_stance;
	float m_speedLiteral;
	float m_accelLiteral;
	float m_decelLiteral;
	float m_stopDistance;
	float m_resumeDistance;
	bool m_bUseExactPosition;
	float m_exactRotationStartDist;
	Vec3 m_exactDirection;
	bool m_bShift;
	float m_shiftDistBefore;
	float m_shiftDistAfter;
	float m_shiftTelegraphTime;
	MovementStyle::ShiftAnimation m_shiftAnims;
	MovementStyle::ShiftType m_shiftType;
	MovementStyle::JumpStyle m_jumpStyle;
	MovementStyle::JumpGoal m_jumpGoal;
	float m_jumpDist;
	float m_jumpGoalPathDist;
	MovementStyle::HoverStyle m_hoverStyle;
	EArkObstacleAvoidanceUrgency m_obstacleAvoidUrgency;
	bool m_bContinueMoving;
	bool m_bScriptMove;
	bool m_bAllowTeleportToNavMesh;
	MovementRequestResult::FailureReason m_lastFailure;
	ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)> m_callback;
	bool m_bAllowStrafe;

	ArkNpcMovementDesire(EArkNpcMovementDesirePriority _priority, const char* _dbgSource);
	void SetCallback(ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)> _callback) { FSetCallback(this, _callback); }
	void ClearCallback() { FClearCallback(this); }
	void SetResumeDistance(float _resumeDistance) { FSetResumeDistance(this, _resumeDistance); }

#if 0
	bool GetCanShift() const;
	MovementRequestResult::FailureReason GetLastFailureReason() const;
	const ArkNpcDesireTarget& GetDesireTarget();
#endif

	static inline auto FArkNpcMovementDesireOv1 = PreyFunction<void(ArkNpcMovementDesire* const _this, EArkNpcMovementDesirePriority _priority, const char* _dbgSource)>(0x1646AC0);
	static inline auto FSetCallback = PreyFunction<void(ArkNpcMovementDesire* const _this, ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)> _callback)>(0x16470F0);
	static inline auto FClearCallback = PreyFunction<void(ArkNpcMovementDesire* const _this)>(0x1646CA0);
	static inline auto FSetResumeDistance = PreyFunction<void(ArkNpcMovementDesire* const _this, float _resumeDistance)>(0x1647110);
};
#endif // MOONCRASH
