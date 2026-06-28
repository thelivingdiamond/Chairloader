// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkGameNoiseInfo.h
struct ArkGameNoiseInfo // Id=8014310 Size=24
{
	uint64_t m_type;
	unsigned m_referenceEntityId;
	Vec3 m_referencePos;
	
	ArkGameNoiseInfo(uint64_t _type);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkGameNoiseInfo
// Header:  Prey/GameDll/ark/perception/ArkGameNoiseInfo.h
struct ArkGameNoiseInfo
{ // Size=24 (0x18)
	uint64_t m_type;
	unsigned m_referenceEntityId;
	Vec3 m_referencePos;

	ArkGameNoiseInfo(uint64_t _type);

	static inline auto FArkGameNoiseInfoOv2 = PreyFunction<void(ArkGameNoiseInfo* const _this, uint64_t _type)>(0x13587E0);
};
#endif // !MOONCRASH
