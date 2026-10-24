// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkGameLoadSaveListener.h
#ifdef MOONCRASH
enum ELoadGameResult;
#endif
class IArkGameLoadSaveListener // Id=801666D Size=8
{
public:
	virtual void OnLoadSaveError(ELoadGameResult arg0) = 0;
};
