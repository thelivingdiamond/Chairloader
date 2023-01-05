// Header file automatically created from a PDB.
#pragma once

// IArkEtherDuplicateListener
// Header:  Prey/GameDll/ark/player/IArkEtherDuplicateListener.h
class IArkEtherDuplicateListener
{ // Size=8 (0x8)
public:
	virtual void OnEtherDuplicateCreated(const unsigned _arg0_);
	virtual void OnEtherDuplicateDestroyed(const unsigned _etherDuplicate);

	static inline auto FOnEtherDuplicateDestroyed = PreyFunction<void(IArkEtherDuplicateListener* const _this, const unsigned _etherDuplicate)>(0xA13080);
};

