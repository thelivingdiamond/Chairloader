// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
//#include <Prey/CryAISystem/GoalPipeXMLReader.h>
#include <Prey/CryAISystem/IAgent.h>
#include <Prey/CryAISystem/MovementStyle.h>

class XmlNodeRef;

// Header: Exact
// CryEngine/crycommon/MovementStyle.h
class MovementStyle // Id=8001394 Size=240
{
public:
	enum class Stance
	{
		Relaxed = 0,
		Alerted = 1,
		Stand = 2,
		Crouch = 3,
		Corrupted = 4,
		InvestigateAnomaly = 5,
		InvestigateDanger = 6,
		InvestigateVision = 7,
		Hunt = 8,
		GunUp = 9,
		Charge = 10,
	};

	enum class Speed
	{
		Walk = 0,
		Run = 1,
		Sprint = 2,
	};

	enum class ShiftAnimation
	{
		None = 0,
		ShiftInAndOut = 1,
		ShiftInOnly = 2,
		ShiftOutOnly = 3,
		Attack = 4,
	};

	enum class ShiftType
	{
		Normal = 0,
		Lurk = 1,
	};

	enum class JumpStyle
	{
		None = 0,
		ForwardJump = 1,
		WallJump = 2,
		AnyJump = 3,
	};

	enum class JumpGoal
	{
		FromStart = 0,
		FromStartImmediate = 1,
		ToEnd = 2,
		ToEndImmediate = 3,
	};

	enum class HoverStyle
	{
		MaintainFloorHeight = 0,
		MaintainCurrentHeight = 1,
		IgnoreHeight = 2,
	};

	enum class OutsideNavigationStyle
	{
		None = 0,
		Allow = 1,
		Force = 2,
	};

	MovementStyle::Stance m_stance;
	MovementStyle::Speed m_speed;
	float m_speedLiteral;
	bool m_hasSpeedLiteral;
	EBodyOrientationMode m_bodyOrientationMode;
	SAIActorTargetRequest m_exactPositioningRequest;
	bool m_movingToCover;
	bool m_movingAlongDesignedPath;
	bool m_turnTowardsMovementDirectionBeforeMoving;
	bool m_strafe;
	bool m_hasExactPositioningRequest;
	bool m_glanceInMovementDirection;
	float m_accelLiteral;
	bool m_hasAccelLiteral;
	float m_decelLiteral;
	bool m_hasDecelLiteral;
	bool m_bHasTargetPOI;
	Vec3 m_targetPOI;
	unsigned m_targetPOIId;
	bool m_bShift;
	float m_shiftDistBefore;
	float m_shiftDistAfter;
	float m_shiftTelegraphTime;
	MovementStyle::ShiftAnimation m_shiftAnim;
	MovementStyle::ShiftType m_shiftType;
	MovementStyle::JumpStyle m_jumpStyle;
	MovementStyle::JumpGoal m_jumpGoal;
	float m_jumpGoalDist;
	float m_jumpTargetDist;
	MovementStyle::HoverStyle m_hoverStyle;
	EArkObstacleAvoidanceUrgency m_obstacleAvoidUrgency;
	MovementStyle::OutsideNavigationStyle m_outsideNavigation;
	bool m_bContinueMoving;
	
	MovementStyle();
	void ReadFromXml(XmlNodeRef const &node) { FReadFromXml(this,node); }
	
#if 0
	void ConstructDictionariesIfNotAlreadyDone();
	void SetStance(MovementStyle::Stance arg0);
	void SetSpeed(MovementStyle::Speed arg0);
	void SetSpeedLiteral(float arg0);
	void SetBodyOrientationMode(EBodyOrientationMode arg0);
	void SetMovingToCover(const bool arg0);
	void SetTurnTowardsMovementDirectionBeforeMoving(const bool arg0);
	void SetMovingAlongDesignedPath(const bool arg0);
	void SetExactPositioningRequest(SAIActorTargetRequest const *const arg0);
	void SetStrafe(bool arg0);
	MovementStyle::Stance GetStance() const;
	MovementStyle::Speed GetSpeed() const;
	bool HasSpeedLiteral() const;
	float GetSpeedLiteral() const;
	EBodyOrientationMode GetBodyOrientationMode() const;
	bool IsMovingToCover() const;
	bool IsMovingAlongDesignedPath() const;
	bool ShouldTurnTowardsMovementDirectionBeforeMoving() const;
	bool ShouldStrafe() const;
	bool ShouldGlanceInMovementDirection() const;
	SAIActorTargetRequest const *GetExactPositioningRequest() const;
	bool HasAccelLiteral() const;
	float GetAccelLiteral() const;
	void SetAccelLiteral(float arg0);
	bool HasDecelLiteral() const;
	float GetDecelLiteral() const;
	void SetDecelLiteral(float arg0);
	bool HasTargetPOI() const;
	Vec3 GetTargetPOI() const;
	unsigned GetTargetPOIId() const;
	void SetTargetPOI(Vec3 const &arg0, unsigned arg1);
	bool IsShift() const;
	bool GetShift(float &arg0, float &arg1, MovementStyle::ShiftAnimation &arg2, float &arg3, MovementStyle::ShiftType &arg4) const;
	void SetShift(float arg0, float arg1, MovementStyle::ShiftAnimation arg2, float arg3, MovementStyle::ShiftType arg4);
	void ClearShift();
	bool IsShiftAttack() const;
	bool GetJump(MovementStyle::JumpStyle &arg0, MovementStyle::JumpGoal &arg1, float &arg2, float &arg3) const;
	void SetJump(MovementStyle::JumpStyle arg0, MovementStyle::JumpGoal arg1, float arg2, float arg3);
	void ClearJump();
	MovementStyle::HoverStyle GetHoverStyle() const;
	void SetHoverStyle(MovementStyle::HoverStyle arg0);
	MovementStyle::OutsideNavigationStyle GetOutsideNavigation() const;
	void SetOutsideNavigation(MovementStyle::OutsideNavigationStyle arg0);
	bool ContinueMoving() const;
	void SetContinueMoving(bool arg0);
	EArkObstacleAvoidanceUrgency GetObstacleAvoidanceUrgency() const;
	void SetObstacleAvoidanceUrgency(EArkObstacleAvoidanceUrgency arg0);
#endif
	
	static inline auto FReadFromXml = PreyFunction<void(MovementStyle *const _this, XmlNodeRef const &node)>(0x636BD0);
};

#if 0
// Header: Exact
// CryEngine/crycommon/movementstyle.h
struct MovementStyleDictionaryCollection // Id=80069DE Size=96
{
	CXMLAttrReader<enum MovementStyle::Speed> speeds;
	CXMLAttrReader<enum MovementStyle::Stance> stances;
	CXMLAttrReader<enum EBodyOrientationMode> bodyOrientations;
	CXMLAttrReader<bool> booleans;
	
	MovementStyleDictionaryCollection();
};
#endif

