// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/weapons/SStaticWiggleParams.h
struct SStaticWiggleParams // Id=801D53E Size=8
{
	float frequency;
	float intensity;
	
#if 0
	void Serialize(Serialization::IArchive &arg0);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

namespace Serialization
{
class IArchive;
} // namespace Serialization

// SStaticWiggleParams
// Header:  Prey/GameDll/ark/weapons/SStaticWiggleParams.h
struct SStaticWiggleParams
{ // Size=8 (0x8)
	float frequency;
	float intensity;

#if 0
	void Serialize(Serialization::IArchive& _arg0_);
#endif
};
#endif // !MOONCRASH
