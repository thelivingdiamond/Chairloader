// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/SGameWeaponSwayParams.h
struct SGameWeaponSwayParams // Id=8016D07 Size=48
{
	Vec3 inputMove;
	Ang3 inputRot;
	Vec3 aimDirection;
	Vec3 velocity;
	
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

// SGameWeaponSwayParams
// Header:  Prey/GameDll/SGameWeaponSwayParams.h
struct SGameWeaponSwayParams
{ // Size=48 (0x30)
	Vec3 inputMove;
	Ang3 inputRot;
	Vec3 aimDirection;
	Vec3 velocity;

#if 0
	SGameWeaponSwayParams();
	void Serialize(Serialization::IArchive& _arg0_);
#endif
};
#endif // !MOONCRASH
