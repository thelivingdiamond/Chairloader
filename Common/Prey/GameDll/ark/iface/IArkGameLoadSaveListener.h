// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkGameLoadSaveListener.h
class IArkGameLoadSaveListener // Id=801666D Size=8
{
public:
	virtual void OnLoadSaveError(ELoadGameResult arg0) = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum ELoadGameResult;

// IArkGameLoadSaveListener
// Header:  Prey/GameDll/ark/iface/IArkGameLoadSaveListener.h
class IArkGameLoadSaveListener
{ // Size=8 (0x8)
public:
	virtual void OnLoadSaveError(ELoadGameResult _result) = 0;
};
#endif // !MOONCRASH
