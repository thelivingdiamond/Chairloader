// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IUIControlSchemeListener.h
#ifdef MOONCRASH
enum EControlScheme;
#endif
struct IUIControlSchemeListener // Id=80147D2 Size=8
{
	virtual ~IUIControlSchemeListener() = default;
	virtual bool OnControlSchemeChanged(EControlScheme arg0) = 0;
};
