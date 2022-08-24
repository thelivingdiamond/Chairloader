// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/MovementRequest.h>
#include <Prey/CryAISystem/MovementStyle.h>
#include <Prey/CryCore/functor.h>
#include "MovementRequestResult.h"

// Header: Exact
// CryEngine/crycommon/MovementRequest.h
struct MovementRequest // Id=8002227 Size=304
{
	using Callback = Functor1<MovementRequestResult const &>;
	
	enum class Type
	{
		MoveTo = 0,
		Stop = 1,
		SwitchForm = 2,
		GoToNavMesh = 3,
	};

	MovementStyle style;
	Vec3 destination;
	MovementRequest::Type type;
	Functor1<MovementRequestResult const &> callback;
	unsigned entityID;
	unsigned dangersFlags;
	bool considerActorsAsPathObstacles;
	float lengthToTrimFromThePathEnd;
	
	MovementRequest();
};

