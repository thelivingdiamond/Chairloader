// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkInventoryListener.h
class IArkInventoryListener // Id=8015644 Size=8
{
public:
#ifndef MOONCRASH
	virtual void OnItemAdded(unsigned arg0, unsigned arg1) = 0;
#else
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId, bool _bPrimaryInventory) = 0;
#endif
#ifndef MOONCRASH
	virtual void OnItemRemoved(unsigned arg0) = 0;
#else
	virtual void OnItemRemoved(unsigned _itemId, bool _bPrimaryInventory) = 0;
#endif
#ifndef MOONCRASH
	virtual void OnItemCountChanged(unsigned _itemId) {}
#else
	virtual void OnItemCountChanged(unsigned _itemId, bool _bPrimaryInventory);
#endif
	
#ifndef MOONCRASH
	static inline auto FOnItemCountChanged = PreyFunction<void(IArkInventoryListener *const _this, unsigned _itemId)>(0xA13080);
#else
	static inline auto FOnItemCountChanged = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId, bool _bPrimaryInventory)>(0x1333E90);
#endif
};
