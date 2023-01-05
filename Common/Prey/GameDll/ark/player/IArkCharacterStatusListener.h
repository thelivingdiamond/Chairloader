// Header file automatically created from a PDB.
#pragma once

// IArkCharacterStatusListener
// Header:  Prey/GameDll/ark/player/IArkCharacterStatusListener.h
class IArkCharacterStatusListener
{ // Size=8 (0x8)
public:
	virtual void OnCharacterStatusChanged(const uint64_t _characterId) = 0;
	virtual void OnCharacterDiscovered(const uint64_t _characterId, bool _bDiscovered) = 0;
};

