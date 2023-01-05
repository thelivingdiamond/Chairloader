// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IMovementController.h>

class CMovementRequest;
struct SMovementState;
struct SStanceState;
struct SStanceStateQuery;

// ArkPlayerMovementController
// Header:  Prey/GameDll/ark/player/ArkPlayerMovementController.h
class ArkPlayerMovementController : public IMovementController
{ // Size=8 (0x8)
public:
	virtual bool RequestMovement(CMovementRequest& _request);
	virtual void GetMovementState(SMovementState& _state);
	virtual bool GetStanceState(const SStanceStateQuery& _query, SStanceState& _state);

	static inline auto FRequestMovement = PreyFunction<bool(ArkPlayerMovementController* const _this, CMovementRequest& _request)>(0xDD23F0);
	static inline auto FGetMovementState = PreyFunction<void(ArkPlayerMovementController* const _this, SMovementState& _state)>(0x156E050);
	static inline auto FGetStanceState = PreyFunction<bool(ArkPlayerMovementController* const _this, const SStanceStateQuery& _query, SStanceState& _state)>(0xDD23F0);
};

