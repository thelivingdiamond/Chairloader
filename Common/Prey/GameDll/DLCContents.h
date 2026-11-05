// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryString/CryFixedString.h>

// DLCContents
// Header:  _unknown/DLCContents.h
struct DLCContents
{ // Size=4416 (0x1140)
	std::vector<string> levels;
	unsigned bonusID;
	wchar_t name[32];
	CryFixedStringT<32> root;
	CryFixedStringT<2048> scoreRewardsPath;
	CryFixedStringT<2048> playlistsPath;
	CryFixedStringT<32> uniqueTag;
	CryFixedStringT<32> descriptionStr;
	unsigned uniqueID;
	unsigned messageID;

#if 0
	DLCContents();
#endif
};

