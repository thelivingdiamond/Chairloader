// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/arkitem.h>

class IArkInventory;

// Header: FromCpp
// Prey/GameDll/ark/ArkCraftingIngredient.h
class ArkCraftingIngredient : public CArkItem // Id=80176EB Size=416
{
public:
	string m_scrapsIcon;
	float m_minScrapScale;
	float m_maxScrapScale;
	float m_xlMaxScrapScale;
	int m_xlMaxScaleCount;
	string m_scrapsPickupModel;
	string m_scrapsPickupMaterial;
	string m_scrapsDescription;
	bool m_bForceScrap;
	
	static ArkCraftingIngredient *GetCraftingIngredientFromId(unsigned _entityId) { return FGetCraftingIngredientFromId(_entityId); }
	static int GetScrapsPerIngredient() { return FGetScrapsPerIngredient(); }
	static wstring GetDisplayCount(int _amount, bool _bEmptyIfZero) { return FGetDisplayCount(_amount,_bEmptyIfZero); }
	static bool IsCraftingIngredient(uint64_t _archetype) { return FIsCraftingIngredient(_archetype); }
	ArkCraftingIngredient();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool PickUp(const unsigned _pickerId, bool _bScale);
	virtual bool GiveOwner(IArkInventory *_pInventory);
	virtual const char *GetIcon() const;
	virtual wstring GetDescription() const;
	virtual void ResetCount(int _count);
	void ForceToScrap() { FForceToScrap(this); }
	virtual void LoadCachedProperties();
	virtual const char *GetPickupModel() const;
	virtual const char *GetPickupMaterial() const;
	virtual ~ArkCraftingIngredient();
	
#if 0
	bool IsScraps() const;
	float GetIngredientCount() const;
#endif
	
	static inline auto FGetCraftingIngredientFromId = PreyFunction<ArkCraftingIngredient *(unsigned _entityId)>(0x10B2C90);
	static inline auto FGetScrapsPerIngredient = PreyFunction<int()>(0x1152940);
	static inline auto FGetDisplayCount = PreyFunction<wstring(int _amount, bool _bEmptyIfZero)>(0x1152810);
	static inline auto FIsCraftingIngredient = PreyFunction<bool(uint64_t _archetype)>(0x1152980);
	static inline auto FFullSerialize = PreyFunction<void(ArkCraftingIngredient *const _this, TSerialize _ser)>(0x1152700);
	static inline auto FPickUp = PreyFunction<bool(ArkCraftingIngredient *const _this, const unsigned _pickerId, bool _bScale)>(0x1153170);
	static inline auto FGiveOwner = PreyFunction<bool(ArkCraftingIngredient *const _this, IArkInventory *_pInventory)>(0x1152950);
	static inline auto FGetIcon = PreyFunction<const char *(ArkCraftingIngredient const *const _this)>(0x1152880);
	static inline auto FGetDescription = PreyFunction<wstring(ArkCraftingIngredient const *const _this)>(0x1152750);
	static inline auto FResetCount = PreyFunction<void(ArkCraftingIngredient *const _this, int _count)>(0x11531A0);
	static inline auto FForceToScrap = PreyFunction<void(ArkCraftingIngredient *const _this)>(0x11526C0);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkCraftingIngredient *const _this)>(0x11529A0);
	static inline auto FGetPickupModel = PreyFunction<const char *(ArkCraftingIngredient const *const _this)>(0x1152900);
	static inline auto FGetPickupMaterial = PreyFunction<const char *(ArkCraftingIngredient const *const _this)>(0x11528C0);
};

