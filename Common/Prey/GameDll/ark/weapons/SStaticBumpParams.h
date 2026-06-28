// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/weapons/SStaticBumpParams.h
struct SStaticBumpParams // Id=801D539 Size=12
{
	float time;
	float shift;
	float rotation;
	
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

// SStaticBumpParams
// Header:  Prey/GameDll/ark/weapons/SStaticBumpParams.h
struct SStaticBumpParams
{ // Size=12 (0xC)
	float time;
	float shift;
	float rotation;

#if 0
	void Serialize(Serialization::IArchive& _arg0_);
#endif
};
#endif // !MOONCRASH
