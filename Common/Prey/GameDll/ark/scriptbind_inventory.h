// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ScriptBind_Inventory.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <Prey/GameDll/ark/ScriptHandle.h>

class ArkInventory;
class ICrySizer;
struct IFunctionHandler;
struct ISystem;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_inventory.h
class CScriptBind_Inventory : public CScriptableBase // Id=8016544 Size=96
{
public:
	CScriptBind_Inventory(ISystem *_pSystem);
	void AttachTo(ArkInventory *_pInventory) { FAttachTo(this,_pInventory); }
	void DetachFrom(ArkInventory const *_pInventory) { FDetachFrom(this,_pInventory); }
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	int RemoveItem(IFunctionHandler *_pH, ScriptHandle _entityId) { return FRemoveItem(this,_pH,_entityId); }
	int IsEmpty(IFunctionHandler *_pH) { return FIsEmpty(this,_pH); }
	int GetAllItems(IFunctionHandler *_pH) { return FGetAllItems(this,_pH); }
	int SetDimensions(IFunctionHandler *_pH, int _inventorySizeEnum) { return FSetDimensions(this,_pH,_inventorySizeEnum); }
	int SetPreventStorage(IFunctionHandler *_pH, bool _bPreventStorage) { return FSetPreventStorage(this,_pH,_bPreventStorage); }
	void RegisterGlobals() { FRegisterGlobals(this); }
	void RegisterMethods() { FRegisterMethods(this); }
	
#if 0
	void Release();
	ArkInventory *GetInventory(IFunctionHandler *arg0);
#endif
	
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_Inventory *const _this, ArkInventory *_pInventory)>(0x15C75D0);
	static inline auto FDetachFrom = PreyFunction<void(CScriptBind_Inventory *const _this, ArkInventory const *_pInventory)>(0x15C7720);
	static inline auto FGetMemoryUsage = PreyFunction<void(CScriptBind_Inventory const *const _this, ICrySizer *pSizer)>(0xA39190);
	static inline auto FRemoveItem = PreyFunction<int(CScriptBind_Inventory *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x15C7FE0);
	static inline auto FIsEmpty = PreyFunction<int(CScriptBind_Inventory *const _this, IFunctionHandler *_pH)>(0x15C7A90);
	static inline auto FGetAllItems = PreyFunction<int(CScriptBind_Inventory *const _this, IFunctionHandler *_pH)>(0x15C77C0);
	static inline auto FSetDimensions = PreyFunction<int(CScriptBind_Inventory *const _this, IFunctionHandler *_pH, int _inventorySizeEnum)>(0x15C8020);
	static inline auto FSetPreventStorage = PreyFunction<int(CScriptBind_Inventory *const _this, IFunctionHandler *_pH, bool _bPreventStorage)>(0x15C8060);
	static inline auto FRegisterGlobals = PreyFunction<void(CScriptBind_Inventory *const _this)>(0x15C7B80);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptBind_Inventory *const _this)>(0x15C7D90);
};

