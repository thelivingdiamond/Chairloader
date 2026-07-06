// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>

class CItem;
class ICrySizer;
struct IFunctionHandler;
struct IGameFramework;
struct ISystem;
union ScriptHandle;

// CScriptBind_Item
// Header:  Prey/GameDll/ScriptBind_Item.h
class CScriptBind_Item : public CScriptableBase
{ // Size=128 (0x80)
public:
	ISystem* m_pSystem;
	IGameFramework* m_pGameFW;
	SmartScriptTable m_stats;
	SmartScriptTable m_params;

	CScriptBind_Item(ISystem* pSystem, IGameFramework* pGameFramework);
	virtual ~CScriptBind_Item();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	void AttachTo(CItem* pItem) { FAttachTo(this, pItem); }
	int Reset(IFunctionHandler* pH) { return FReset(this, pH); }
	int CanPickUp(IFunctionHandler* pH, ScriptHandle userId) { return FCanPickUp(this, pH, userId); }
	int CanUse(IFunctionHandler* pH, ScriptHandle userId) { return FCanUse(this, pH, userId); }
	int CanUseVehicle(IFunctionHandler* pH, ScriptHandle userId) { return FCanUseVehicle(this, pH, userId); }
	int IsPickable(IFunctionHandler* pH) { return FIsPickable(this, pH); }
	int IsMounted(IFunctionHandler* pH) { return FIsMounted(this, pH); }
	int GetUsableText(IFunctionHandler* pH) { return FGetUsableText(this, pH); }
	int GetOwnerId(IFunctionHandler* pH) { return FGetOwnerId(this, pH); }
	int StartUse(IFunctionHandler* pH, ScriptHandle userId) { return FStartUse(this, pH, userId); }
	int StopUse(IFunctionHandler* pH, ScriptHandle userId) { return FStopUse(this, pH, userId); }
	int Use(IFunctionHandler* pH, ScriptHandle userId) { return FUse(this, pH, userId); }
	int IsUsed(IFunctionHandler* pH) { return FIsUsed(this, pH); }
	int GetMountedDir(IFunctionHandler* pH) { return FGetMountedDir(this, pH); }
	int SetMountedAngleLimits(IFunctionHandler* pH, float min_pitch, float max_pitch, float yaw_range) { return FSetMountedAngleLimits(this, pH, min_pitch, max_pitch, yaw_range); }
	int OnHit(IFunctionHandler* pH, SmartScriptTable hitTable) { return FOnHit(this, pH, hitTable); }
	int IsDestroyed(IFunctionHandler* pH) { return FIsDestroyed(this, pH); }
	int HasAccessory(IFunctionHandler* pH, const char* accessoryName) { return FHasAccessory(this, pH, accessoryName); }
	int AllowDrop(IFunctionHandler* pH) { return FAllowDrop(this, pH); }
	int DisallowDrop(IFunctionHandler* pH) { return FDisallowDrop(this, pH); }
	void RegisterMethods() { FRegisterMethods(this); }

#if 0
	void RegisterGlobals();
	CItem* GetItem(IFunctionHandler* _arg0_);
#endif

	static inline auto FCScriptBind_ItemOv1 = PreyFunction<void(CScriptBind_Item* const _this, ISystem* pSystem, IGameFramework* pGameFramework)>(0x1914C70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CScriptBind_Item* const _this, ICrySizer* pSizer)>(0x4A5BF0);
	static inline auto FAttachTo = PreyFunction<void(CScriptBind_Item* const _this, CItem* pItem)>(0x1914E00);
	static inline auto FReset = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1916290);
	static inline auto FCanPickUp = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, ScriptHandle userId)>(0x1914F60);
	static inline auto FCanUse = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, ScriptHandle userId)>(0x1915040);
	static inline auto FCanUseVehicle = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, ScriptHandle userId)>(0x77DB10);
	static inline auto FIsPickable = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1915770);
	static inline auto FIsMounted = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1915680);
	static inline auto FGetUsableText = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1915360);
	static inline auto FGetOwnerId = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1915260);
	static inline auto FStartUse = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, ScriptHandle userId)>(0x19163A0);
	static inline auto FStopUse = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, ScriptHandle userId)>(0x1916420);
	static inline auto FUse = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, ScriptHandle userId)>(0x19164A0);
	static inline auto FIsUsed = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1915860);
	static inline auto FGetMountedDir = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1915140);
	static inline auto FSetMountedAngleLimits = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, float min_pitch, float max_pitch, float yaw_range)>(0x1916300);
	static inline auto FOnHit = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, SmartScriptTable hitTable)>(0x1915950);
	static inline auto FIsDestroyed = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x1915590);
	static inline auto FHasAccessory = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH, const char* accessoryName)>(0x1915460);
	static inline auto FAllowDrop = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x77DB10);
	static inline auto FDisallowDrop = PreyFunction<int(CScriptBind_Item* const _this, IFunctionHandler* pH)>(0x77DB10);
	static inline auto FRegisterMethods = PreyFunction<void(CScriptBind_Item* const _this)>(0x1915B10);
};
#endif // MOONCRASH
