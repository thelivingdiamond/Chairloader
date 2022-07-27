// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ArkInventory.h>

// Header: FromCpp
// Prey/GameDll/ark/ArkAuxiliaryInventory.h
class ArkAuxiliaryInventory : public ArkInventory // Id=8017042 Size=136
{
public:
	virtual unsigned PlaceItem(unsigned _itemId, int _x, int _y);
	virtual void RemoveItem(unsigned _itemId);
	
	static inline auto FPlaceItem = PreyFunction<unsigned(ArkAuxiliaryInventory *const _this, unsigned _itemId, int _x, int _y)>(0x114C1B0);
	static inline auto FRemoveItem = PreyFunction<void(ArkAuxiliaryInventory *const _this, unsigned _itemId)>(0x114C1E0);
};

