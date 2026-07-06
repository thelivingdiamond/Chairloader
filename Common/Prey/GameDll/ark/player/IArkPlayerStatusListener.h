// Auto-merged: identical in PreyDll (base) and Mooncrash (DLC); no MOONCRASH guard needed.
// Header file automatically created from a PDB.
#pragma once

// IArkPlayerStatusListener
// Header:  Prey/GameDll/ark/player/IArkPlayerStatusListener.h
class IArkPlayerStatusListener
{ // Size=8 (0x8)
public:
	virtual void OnStatusChanged(uint64_t _statusId, bool _bActive) = 0;
};
