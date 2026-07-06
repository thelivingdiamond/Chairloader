// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/weapons/IArkGlooIslandNavLinkManager.h
class IArkGlooIslandNavLinkManager // Id=80020DE Size=8
{
public:
	virtual unsigned GetNearbyGlooIslandEntityId(Vec3 const &arg0, float arg1) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkGlooIslandNavLinkManager
// Header:  Prey/GameDll/ark/weapons/IArkGlooIslandNavLinkManager.h
class IArkGlooIslandNavLinkManager
{ // Size=8 (0x8)
public:
	virtual unsigned GetNearbyGlooIslandEntityId(const Vec3& _pos, float _radius) = 0;
};
#endif // !MOONCRASH
