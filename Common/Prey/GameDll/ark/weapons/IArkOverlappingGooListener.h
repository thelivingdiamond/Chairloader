// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/weapons/IArkOverlappingGooListener.h
class IArkOverlappingGooListener // Id=8018FB7 Size=8
{
public:
	virtual void OnGooStatusChanged(bool arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkOverlappingGooListener
// Header:  Prey/GameDll/ark/weapons/IArkOverlappingGooListener.h
class IArkOverlappingGooListener
{ // Size=8 (0x8)
public:
	virtual void OnGooStatusChanged(bool _bHasGoo) = 0;
};
#endif // !MOONCRASH
