// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryAISystem/MovementRequest.h>

// Header: MadeUp
// _unknown/MovementRequestStatus.h
struct MovementRequestStatus // Id=800222B Size=296
{
	struct BlockInfo // Id=800222C Size=8
	{
		const char *name;
	};

	using BlockInfos = StaticDynArray<MovementRequestStatus::BlockInfo,32>;
	
	enum class ID
	{
		NotQueued = 0,
		Queued = 1,
		FindingPath = 2,
		ExecutingPlan = 3,
	};

	BlockInfos blockInfos;
	unsigned currentBlockIndex;
	MovementRequestStatus::ID id;
	int numReattempts;
	
#if 0
	MovementRequestStatus::ID operator enum MovementRequestStatus::ID() const;
#endif
};

