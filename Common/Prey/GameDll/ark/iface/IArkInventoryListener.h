// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/iface/IArkInventoryListener.h
class IArkInventoryListener // Id=8015644 Size=8
{
public:
	virtual void OnItemAdded(unsigned arg0, unsigned arg1) = 0;
	virtual void OnItemRemoved(unsigned arg0) = 0;
	virtual void OnItemCountChanged(unsigned _itemId);
	
	static inline auto FOnItemCountChanged = PreyFunction<void(IArkInventoryListener *const _this, unsigned _itemId)>(0xA13080);
};

