// Header file automatically created from a PDB.
#pragma once

class IAction;

// SActorTargetParams
// Header:  _unknown/SActorTargetParams.h
// Include: Prey/CryAction/IMovementController.h
struct SActorTargetParams
{ // Size=80 (0x50)
	enum class type_uninitialized
	{
		UNINITIALIZED = 0,
	};

	Vec3 location;
	Vec3 direction;
	float speed;
	float directionTolerance;
	float directionStartDistance;
	float startArcAngle;
	float startWidth;
	EStance stance;
	unsigned* pQueryStart;
	unsigned* pQueryEnd;
	_smart_ptr<IAction> pAction;
	float prepareRadius;
	bool projectEnd;
	bool navSO;
	bool completeWhenActivated;

#if 0
	SActorTargetParams();
	SActorTargetParams(SActorTargetParams::type_uninitialized _arg0_);
#endif
};

