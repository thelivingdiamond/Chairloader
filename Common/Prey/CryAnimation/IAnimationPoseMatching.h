// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAnimation/IAnimationPoseModifier.h>

struct CryGUID;

// IAnimationPoseMatching
// Header:  _unknown/IAnimationPoseMatching.h
// Include: Prey/CryAnimation/IAnimationPoseModifier.h
struct IAnimationPoseMatching : public IAnimationPoseModifier
{ // Size=8 (0x8)
	virtual ~IAnimationPoseMatching();
	virtual void SetAnimations(const unsigned* pAnimationIds, unsigned count) = 0;
	virtual bool GetMatchingAnimation(unsigned& animationId) const = 0;
	virtual void SetPoseRootJointName(const char* pRootJointName) = 0;

#if 0
	static const CryGUID& IID();
#endif
};

