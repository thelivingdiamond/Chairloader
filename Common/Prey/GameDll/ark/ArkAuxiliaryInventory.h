// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
	virtual ~ArkAuxiliaryInventory();
	
	static inline auto FPlaceItem = PreyFunction<unsigned(ArkAuxiliaryInventory *const _this, unsigned _itemId, int _x, int _y)>(0x114C1B0);
	static inline auto FRemoveItem = PreyFunction<void(ArkAuxiliaryInventory *const _this, unsigned _itemId)>(0x114C1E0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ArkInventory.h>

struct IGameObject;

// ArkAuxiliaryInventory
// Header:  Prey/GameDll/ark/ArkAuxiliaryInventory.h
class ArkAuxiliaryInventory : public ArkInventory
{ // Size=128 (0x80)
public:
	virtual ~ArkAuxiliaryInventory();
	virtual bool Init(IGameObject* _pGameObject);
	virtual unsigned PlaceItem(unsigned _itemId, int _x, int _y);
	virtual void RemoveItem(unsigned _itemId);
	virtual bool IsPrimaryInventory() const;

	static inline auto FInit = PreyFunction<bool(ArkAuxiliaryInventory* const _this, IGameObject* _pGameObject)>(0x11930A0);
	static inline auto FPlaceItem = PreyFunction<unsigned(ArkAuxiliaryInventory* const _this, unsigned _itemId, int _x, int _y)>(0x11930B0);
	static inline auto FRemoveItem = PreyFunction<void(ArkAuxiliaryInventory* const _this, unsigned _itemId)>(0x11930E0);
	static inline auto FIsPrimaryInventory = PreyFunction<bool(const ArkAuxiliaryInventory* const _this)>(0x13B0900);
};
#endif // !MOONCRASH
