// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/SActorIKLimbInfo.h>

// SActorFileModelInfo
// Header:  _unknown/SActorFileModelInfo.h
struct SActorFileModelInfo
{ // Size=56 (0x38)
	using TIKLimbInfoVec = std::vector<SActorIKLimbInfo>;

	string sFileName;
	string sClientFileName;
	string sShadowFileName;
	bool bUseFacialFrameRateLimiting;
	std::vector<SActorIKLimbInfo> IKLimbInfo;

#if 0
	SActorFileModelInfo();
#endif
};

