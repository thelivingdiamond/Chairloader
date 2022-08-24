// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/MovementRequest.h>
#include <Prey/CryAISystem/MovementRequestID.h>

// Header: MadeUp
// _unknown/MovementRequestResult.h
struct MovementRequestResult // Id=8002229 Size=12
{
	enum class Result
	{
		Success = 0,
		Failure = 1,
		ReachedDestination = 0,
	};

	enum class FailureReason
	{
		NoReason = 0,
		CouldNotFindValidStart = 1,
		CouldNotFindValidDestination = 2,
		CouldNotFindPathToRequestedDestination = 3,
		CouldNotMoveAlongDesignerDesignedPath = 4,
		FailedToProduceSuccessfulPlanAfterMaximumNumberOfAttempts = 5,
		CouldNotFindPathAroundObstacles = 6,
		FailedShift = 7,
		PathingModeForced = 8,
		FacingRestricted = 9,
		StuckOnObstacle = 10,
		StuckOnNpc = 11,
		StuckOnGloo = 12,
	};

	MovementRequestID requestID;
	MovementRequestResult::Result result;
	MovementRequestResult::FailureReason failureReason;
	
#if 0
	bool operator==(MovementRequestResult::Result const &arg0) const;
	bool operator bool() const;
#endif
};

