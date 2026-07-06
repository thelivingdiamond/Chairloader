// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkInventoryListener.h
class IArkInventoryListener // Id=8015644 Size=8
{
public:
	virtual void OnItemAdded(unsigned arg0, unsigned arg1) = 0;
	virtual void OnItemRemoved(unsigned arg0) = 0;
	virtual void OnItemCountChanged(unsigned _itemId) {}
	
	static inline auto FOnItemCountChanged = PreyFunction<void(IArkInventoryListener *const _this, unsigned _itemId)>(0xA13080);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IArkInventoryListener
// Header:  Prey/GameDll/ark/iface/IArkInventoryListener.h
class IArkInventoryListener
{ // Size=8 (0x8)
public:
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId, bool _bPrimaryInventory) = 0;
	virtual void OnItemRemoved(unsigned _itemId, bool _bPrimaryInventory) = 0;
	virtual void OnItemCountChanged(unsigned _itemId, bool _bPrimaryInventory);

	static inline auto FOnItemCountChanged = PreyFunction<void(IArkInventoryListener* const _this, unsigned _itemId, bool _bPrimaryInventory)>(0x1333E90);
};
#endif // !MOONCRASH
