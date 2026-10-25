// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryExtension/ICryUnknown.h>

struct CryGUID;
class ICrySizer;
struct SAnimationPoseModifierParams;

// IAnimationPoseModifier
// Header:  _unknown/IAnimationPoseModifier.h
// Include: Prey/CryAnimation/IAnimationPoseModifier.h
struct IAnimationPoseModifier : public ICryUnknown
{ // Size=8 (0x8)
	virtual ~IAnimationPoseModifier();
	virtual bool Prepare(const SAnimationPoseModifierParams& params) = 0;
	virtual bool Execute(const SAnimationPoseModifierParams& params) = 0;
	virtual void Synchronize() = 0;
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;

#if 0
	static const CryGUID& IID();
#endif
};

