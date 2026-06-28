// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/playerIArkCombatFocusListener.h
class IArkCombatFocusListener // Id=80154E1 Size=8
{
public:
	virtual void OnCombatFocusChanged(bool arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkCombatFocusListener
// Header:  Prey/GameDll/ark/playerIArkCombatFocusListener.h
class IArkCombatFocusListener
{ // Size=8 (0x8)
public:
	virtual void OnCombatFocusChanged(bool _bActive) = 0;
};
#endif // !MOONCRASH
