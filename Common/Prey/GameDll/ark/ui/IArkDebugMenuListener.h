// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IArkDebugMenuListener.h
class IArkDebugMenuListener // Id=80191AE Size=8
{
public:
	virtual void OnToggleDebugMenu(bool arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkDebugMenuListener
// Header:  Prey/GameDll/ark/ui/IArkDebugMenuListener.h
class IArkDebugMenuListener
{ // Size=8 (0x8)
public:
	virtual void OnToggleDebugMenu(bool _bEnable) = 0;
};
#endif // !MOONCRASH
