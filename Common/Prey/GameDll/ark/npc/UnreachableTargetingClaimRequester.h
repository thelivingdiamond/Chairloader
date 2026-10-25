// Header file automatically created from a PDB.
#pragma once

// UnreachableTargetingClaimRequester
// Header:  _unknown/UnreachableTargetingClaimRequester.h
struct UnreachableTargetingClaimRequester
{ // Size=40 (0x28)
	unsigned m_claimingEntityId;
	Vec3 m_claimedPointPos;
	Vec3 m_avoidPoint;
	float m_avoidPointRadius;
	int m_areaIndex;
	int m_searchId;

#if 0
	UnreachableTargetingClaimRequester();
	UnreachableTargetingClaimRequester(int _arg0_, int _arg1_, Vec3 _arg2_, unsigned _arg3_);
	void ClearClaimInfo();
#endif
};

