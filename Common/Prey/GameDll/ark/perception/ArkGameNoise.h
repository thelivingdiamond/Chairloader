// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

namespace ArkGameNoise
{

// Header: Override
// Prey/GameDll/ark/perception/ArkGameNoise.h
struct Params // Id=800200B Size=16
{
	uint64_t m_type;
	uint64_t m_loudness;
	
#if 0
	bool IsValid() const;
#endif
};

} // namespace ArkGameNoise
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

namespace ArkGameNoise
{

// ArkGameNoise::Params
// Header:  Prey/GameDll/ark/perception/ArkGameNoise.h
struct Params
{ // Size=16 (0x10)
	uint64_t m_type;
	uint64_t m_loudness;

#if 0
	Params();
	bool IsValid() const;
#endif
};


} // namespace ArkGameNoise
#endif // !MOONCRASH
