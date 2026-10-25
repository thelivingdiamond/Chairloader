// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IMovementController.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SActorFrameMovementParams;

// IActorMovementController
// Header:  _unknown/IActorMovementController.h
struct IActorMovementController : public IMovementController
{ // Size=8 (0x8)
	virtual void Reset() = 0;
	virtual void Update(float frameTime, SActorFrameMovementParams& params) = 0;
	virtual void PostUpdate(float frameTime) = 0;
	virtual void Release() = 0;
	virtual void Serialize(TSerialize& ser) = 0;
	virtual void ApplyControllerAcceleration(float& _arg0_, float& _arg1_, float _arg2_);
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;
};

