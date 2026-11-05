// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAnimation/IAnimationPoseModifier.h>

struct CryGUID;

// IAnimationOperatorQueue
// Header:  _unknown/IAnimationOperatorQueue.h
// Include: Prey/CryAnimation/IAnimationPoseModifier.h
struct IAnimationOperatorQueue : public IAnimationPoseModifier
{ // Size=8 (0x8)
	enum EOp
	{
		eOp_Override = 0,
		eOp_OverrideRelative = 1,
		eOp_OverrideWorld = 2,
		eOp_Additive = 3,
		eOp_AdditiveRelative = 4,
	};

	virtual ~IAnimationOperatorQueue();
	virtual void PushPosition(unsigned jointIndex, IAnimationOperatorQueue::EOp eOp, const Vec3& value) = 0;
	virtual void PushOrientation(unsigned jointIndex, IAnimationOperatorQueue::EOp eOp, const Quat& value) = 0;
	virtual void PushStoreRelative(unsigned jointIndex, QuatT& output) = 0;
	virtual void PushStoreAbsolute(unsigned jointIndex, QuatT& output) = 0;
	virtual void PushStoreWorld(unsigned jointIndex, QuatT& output) = 0;
	virtual void PushComputeAbsolute() = 0;
	virtual void Clear() = 0;

#if 0
	static const CryGUID& IID();
#endif
};

