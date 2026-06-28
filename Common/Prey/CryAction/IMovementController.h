// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once
#include <Prey/CryMath/Cry_Math.h>

class CMovementRequest;
struct SMovementState;
struct SStanceStateQuery;
struct SStanceState;
struct IExactPositioningListener;
struct SExactPositioningTarget;

struct IMovementController
{
	virtual ~IMovementController() {}
	// Description:
	//    Request some movement;
	//    If the request cannot be fulfilled, returns false, and request
	//    is updated to be a similar request that could be fulfilled
	//    (calling code is then free to inspect this, and call RequestMovement
	//    again to set a new movement)
	virtual bool RequestMovement(CMovementRequest &request) = 0;
	// Description:
	//    Fetch the current movement state of the entity
	virtual void GetMovementState(SMovementState &state) = 0;
	// Description:
	//    Returns the description of the stance as if the specified stance would be set right now.
	//		If the parameter 'defaultPose' is set to false, the current aim and look target info is used to
	//		calculate the stance info, else a default pose facing along positive Y-axis is returned.
	//		Returns false if the description cannot be queried.
	virtual bool        GetStanceState(const SStanceStateQuery &query, SStanceState &state) = 0;

	virtual inline Vec2 GetDesiredMoveDir() const { return Vec2(0, 1); }

	virtual void        SetExactPositioningListener(IExactPositioningListener *pExactPositioningListener) {}

	// Note: this will not return an exactpositioning target if the request is still pending
	virtual const SExactPositioningTarget *GetExactPositioningTarget() { return NULL; }

	virtual void CancelMovementTransition() = 0;
	virtual void BlockMovementTransitions() = 0;
	virtual void UnblockMovementTransitions() = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>

class CMovementRequest;
struct IExactPositioningListener;
struct SExactPositioningTarget;
struct SMovementState;
struct SStanceState;
struct SStanceStateQuery;

// IMovementController
// Header:  CryEngine/cryaction/IMovementController.h
// Include: Prey/CryAction/IMovementController.h
struct IMovementController
{ // Size=8 (0x8)
	virtual ~IMovementController();
	virtual bool RequestMovement(CMovementRequest& request) = 0;
	virtual void GetMovementState(SMovementState& state) = 0;
	virtual bool GetStanceState(const SStanceStateQuery& query, SStanceState& state) = 0;
	virtual Vec2 GetDesiredMoveDir() const;
	virtual void SetExactPositioningListener(IExactPositioningListener* pExactPositioningListener);
	virtual const SExactPositioningTarget* GetExactPositioningTarget();
	virtual void CancelMovementTransition();
	virtual void BlockMovementTransitions();
	virtual void UnblockMovementTransitions();

	static inline auto FGetDesiredMoveDir = PreyFunction<Vec2*(const IMovementController* const _this, Vec2* _return_value_)>(0x1674930);
	static inline auto FSetExactPositioningListener = PreyFunction<void(IMovementController* const _this, IExactPositioningListener* pExactPositioningListener)>(0x1333E90);
	static inline auto FGetExactPositioningTarget = PreyFunction<const SExactPositioningTarget* (IMovementController* const _this)>(0x1CBB0B0);
	static inline auto FCancelMovementTransition = PreyFunction<void(IMovementController* const _this)>(0x1333E90);
	static inline auto FBlockMovementTransitions = PreyFunction<void(IMovementController* const _this)>(0x1333E90);
	static inline auto FUnblockMovementTransitions = PreyFunction<void(IMovementController* const _this)>(0x1333E90);
};

// SStanceState
// Header:  CryEngine/cryaction/IMovementController.h
// Include: Prey/CryAction/IMovementController.h
struct SStanceState
{ // Size=164 (0xA4)
	Vec3 pos;
	Vec3 entityDirection;
	Vec3 animationBodyDirection;
	Vec3 upDirection;
	Vec3 weaponPosition;
	Vec3 aimDirection;
	Vec3 fireDirection;
	Vec3 eyePosition;
	Vec3 eyeDirection;
	float lean;
	float peekOver;
	AABB m_StanceSize;
	AABB m_ColliderSize;

	SStanceState();

	static inline auto FSStanceStateOv2 = PreyFunction<void(SStanceState* const _this)>(0x417CE0);
};

// SMovementState
// Header:  CryEngine/cryaction/IMovementController.h
// Include: Prey/CryAction/IMovementController.h
struct SMovementState : public SStanceState
{ // Size=244 (0xF4)
	Vec3 fireTarget;
	EStance stance;
	Vec3 animationEyeDirection;
	Vec3 movementDirection;
	Vec3 lastMovementDirection;
	float desiredSpeed;
	float minSpeed;
	float normalSpeed;
	float maxSpeed;
	float slopeAngle;
	bool atMoveTarget;
	bool isAlive;
	bool isAiming;
	bool isFiring;
	bool isVisible;
	bool isMoving;

	SMovementState();

	static inline auto FSMovementStateOv2 = PreyFunction<void(SMovementState* const _this)>(0x417C50);
};
#endif // !MOONCRASH
