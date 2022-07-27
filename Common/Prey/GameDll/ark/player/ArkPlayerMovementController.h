// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IMovementController.h>

class CMovementRequest;
struct SMovementState;
struct SStanceState;
struct SStanceStateQuery;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerMovementController.h
class ArkPlayerMovementController : public IMovementController // Id=80174F6 Size=8
{
public:
	virtual bool RequestMovement(CMovementRequest &_request);
	virtual void GetMovementState(SMovementState &_state);
	virtual bool GetStanceState(SStanceStateQuery const &_query, SStanceState &_state);
	virtual ~ArkPlayerMovementController();
	
	static inline auto FRequestMovement = PreyFunction<bool(ArkPlayerMovementController *const _this, CMovementRequest &_request)>(0xDD23F0);
	static inline auto FGetMovementState = PreyFunction<void(ArkPlayerMovementController *const _this, SMovementState &_state)>(0x156E050);
	static inline auto FGetStanceState = PreyFunction<bool(ArkPlayerMovementController *const _this, SStanceStateQuery const &_query, SStanceState &_state)>(0xDD23F0);
};

