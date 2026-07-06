// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/Ark/IArkDialogLoadListener.h
class IArkDialogLoadListener // Id=80020CB Size=8
{
public:
	virtual void OnLoad(unsigned arg0, bool arg1) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkDialogLoadListener
// Header:  Prey/Ark/IArkDialogLoadListener.h
class IArkDialogLoadListener
{ // Size=8 (0x8)
public:
	virtual void OnLoad(unsigned _controlId, bool _bSuccess) = 0;
};
#endif // !MOONCRASH
