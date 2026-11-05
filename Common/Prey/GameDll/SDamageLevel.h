// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/itemstring.h>

class ICrySizer;

// SDamageLevel
// Header:  _unknown/SDamageLevel.h
struct SDamageLevel
{ // Size=32 (0x20)
	int max_health;
	int min_health;
	float scale;
	SharedString::CSharedString effect;
	SharedString::CSharedString helper;

#if 0
	SDamageLevel();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif
};

