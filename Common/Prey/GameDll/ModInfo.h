// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>

// ModInfo
// Header:  Prey/GameDll/ModInfo.h
struct ModInfo
{ // Size=1976 (0x7B8)
	CryFixedStringT<256> keyName;
	CryFixedStringT<256> displayName;
	EModInfoType modType;
	CryFixedStringT<256> description;
	CryFixedStringT<256> mainImage;
	CryFixedStringT<256> logoImage;
	CryFixedStringT<256> author;
	CryFixedStringT<256> website;
	int versionMajor;
	int versionMinor;

	ModInfo();

#if 0
	bool operator<(const ModInfo& _arg0_) const;
#endif

	static inline auto FModInfoOv2 = PreyFunction<void(ModInfo* const _this)>(0x1892340);
};
#endif // MOONCRASH
