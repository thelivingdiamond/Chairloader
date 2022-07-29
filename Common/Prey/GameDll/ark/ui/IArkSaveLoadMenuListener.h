// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IArkSaveLoadMenuListener.h
class IArkSaveLoadMenuListener // Id=80191E3 Size=8
{
public:
	virtual void OnSaveLoadMenuClose(EArkSaveLoadMode arg0, bool arg1) = 0;
	virtual void OnLoadingStart() = 0;
	virtual void OnLoadSuccess() = 0;
	virtual bool OnLoadFail() = 0;
};

