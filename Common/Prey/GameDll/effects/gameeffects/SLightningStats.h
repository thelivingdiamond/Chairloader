// Header file automatically created from a PDB.
#pragma once

// SLightningStats
// Header:  _unknown/SLightningStats.h
struct SLightningStats
{ // Size=32 (0x20)
	// SLightningStats::SStat
	// Header:  _unknown/SLightningStats.h
	struct SStat
	{ // Size=8 (0x8)
		int m_current;
		int m_peak;

	#if 0
		SStat();
		void SetCurrent(int _arg0_);
		void Increment(int _arg0_);
		int GetCurrent() const;
		int GetPeak() const;
	#endif
	};

	SLightningStats::SStat m_activeSparks;
	SLightningStats::SStat m_memory;
	SLightningStats::SStat m_triCount;
	SLightningStats::SStat m_branches;

#if 0
	void Restart();
#endif
};

