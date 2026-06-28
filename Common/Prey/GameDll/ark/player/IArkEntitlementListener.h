// Auto-merged: identical in PreyDll (base) and Mooncrash (DLC); no MOONCRASH guard needed.
// Header file automatically created from a PDB.
#pragma once

// IArkEntitlementListener
// Header:  Prey/GameDll/ark/player/IArkEntitlementListener.h
struct IArkEntitlementListener
{ // Size=8 (0x8)
	virtual void OnEntitlementChanged(uint64_t _entitlement, bool _bGranted) = 0;
};
