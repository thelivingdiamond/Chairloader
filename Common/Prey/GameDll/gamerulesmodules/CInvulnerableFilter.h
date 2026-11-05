// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/CryFlags.h>

struct HitInfo;

// CInvulnerableFilter
// Header:  _unknown/CInvulnerableFilter.h
class CInvulnerableFilter
{ // Size=8 (0x8)
public:
	enum EReason
	{
		eReason_InTutorial = 1,
		eReason_TrainRide = 2,
	};

	float m_minHealthThreshold;
	CCryFlags<unsigned int> m_enableState;

#if 0
	CInvulnerableFilter();
	void Init();
	bool FilterIncomingDamage(const HitInfo& _arg0_, const float _arg1_) const;
	void AddInvulnerableReason(const CInvulnerableFilter::EReason _arg0_);
	void RemoveInvulnerableReason(const CInvulnerableFilter::EReason _arg0_);
	bool IsEnabled() const;
#endif
};

