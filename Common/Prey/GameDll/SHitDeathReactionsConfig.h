// Header file automatically created from a PDB.
#pragma once

class IAnimationDatabase;
class ICrySizer;

// SHitDeathReactionsConfig
// Header:  _unknown/SHitDeathReactionsConfig.h
struct SHitDeathReactionsConfig
{ // Size=48 (0x30)
	int iCollisionBoneId;
	float fCollisionRadius;
	float fCollisionVerticalOffset;
	float fCollMaxHorzAngleSin;
	float fCollMaxMovAngleCos;
	float fCollReactionStartDist;
	float fMaximumReactionTime;
	float fEndRagdollTime;
	unsigned manqTargetCRC;
	unsigned fragmentID;
	const IAnimationDatabase* piOptionalAnimationADB;

#if 0
	SHitDeathReactionsConfig();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif
};

