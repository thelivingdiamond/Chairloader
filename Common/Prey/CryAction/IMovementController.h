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
