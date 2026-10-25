// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAnimation/IAnimationPoseModifier.h>

struct CryGUID;
struct ICharacterInstance;

// ITransformationPinning
// Header:  _unknown/ITransformationPinning.h
struct ITransformationPinning : public IAnimationPoseModifier
{ // Size=8 (0x8)
	virtual ~ITransformationPinning();
	virtual void SetBlendWeight(float factor) = 0;
	virtual void SetJoint(unsigned jntID) = 0;
	virtual void SetSource(ICharacterInstance* source) = 0;

#if 0
	static const CryGUID& IID();
#endif
};

