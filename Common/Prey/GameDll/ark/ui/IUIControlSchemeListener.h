// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IUIControlSchemeListener.h
struct IUIControlSchemeListener // Id=80147D2 Size=8
{
	virtual ~IUIControlSchemeListener() = default;
	virtual bool OnControlSchemeChanged(EControlScheme arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum EControlScheme;

// IUIControlSchemeListener
// Header:  Prey/GameDll/ark/ui/IUIControlSchemeListener.h
struct IUIControlSchemeListener
{ // Size=8 (0x8)
	virtual ~IUIControlSchemeListener();
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme) = 0;
};
#endif // !MOONCRASH
