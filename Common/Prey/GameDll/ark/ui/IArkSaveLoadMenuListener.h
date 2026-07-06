// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum class EArkSaveLoadMode;

// IArkSaveLoadMenuListener
// Header:  Prey/GameDll/ark/ui/IArkSaveLoadMenuListener.h
class IArkSaveLoadMenuListener
{ // Size=8 (0x8)
public:
	virtual void OnSaveLoadMenuClose(EArkSaveLoadMode _mode, bool _bLoading) = 0;
	virtual void OnLoadingStart() = 0;
	virtual void OnLoadSuccess() = 0;
	virtual bool OnLoadFail() = 0;
};
#endif // !MOONCRASH
