// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/player/IArkEtherDuplicateListener.h
class IArkEtherDuplicateListener // Id=80152A8 Size=8
{
public:
	virtual void OnEtherDuplicateCreated(const unsigned arg0);
	virtual void OnEtherDuplicateDestroyed(const unsigned _etherDuplicate);
	
	static inline auto FOnEtherDuplicateDestroyed = PreyFunction<void(IArkEtherDuplicateListener *const _this, const unsigned _etherDuplicate)>(0xA13080);
};

