// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryGame/IGameFramework.h>

class CEquipmentManager;
struct IArkItem;
struct IConsoleCmdArgs;
struct IEntityArchetype;
struct ILevel;
struct ILevelInfo;

// Header: FromCpp
// Prey/GameDll/ark/ArkItemSystem.h
class ArkItemSystem : public ILevelSystemListener // Id=8015233 Size=248
{
public:
	static const char *k_defaultArkItemScript;
	static const char *k_arkItemConfigFile;
	static const char *k_pickupsLibrary;
	static const char *k_specialWeaponsLibrary;
	
	struct IArkItemCreator : public IGameObjectExtensionCreatorBase // Id=8015234 Size=8
	{
	};

	template <typename T>
	struct CArkItemCreator : public IArkItemCreator // Id=801D0EE Size=8
	{
		CArkItemCreator() = default;

		virtual std::shared_ptr<IGameObjectExtension> Create()
		{
			return ComponentCreate_DeleteWithRelease<T>();
		}

		virtual void GetGameObjectExtensionRMIData(void** _ppRMI, uint64_t* _nCount)
		{
			T::GetGameObjectExtensionRMIData(_ppRMI, _nCount);
		}
	};

	std::map<string, ArkItemSystem::IArkItemCreator *> m_creators;
	std::unordered_map<unsigned int, IArkItem *> m_items;
	std::unique_ptr<CEquipmentManager> m_pEquipmentManager;
	std::vector<string> m_classes;
	std::unordered_map<string,string> m_projectileToPickup;
	std::unordered_map<uint64_t, std::vector<uint64_t>> m_notValidForRandom;
	
	ArkItemSystem();
	virtual ~ArkItemSystem();
	void Init() { FInit(this); }
	void ScanXML(string const &_filename, bool _bReloading) { FScanXML(this,_filename,_bReloading); }
	void LoadEquipmentPacks() { FLoadEquipmentPacks(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void AddItem(unsigned _itemId, IArkItem &_item) { FAddItem(this,_itemId,_item); }
	void RemoveItem(unsigned _itemId) { FRemoveItem(this,_itemId); }
	IArkItem *GetItem(unsigned _itemId) const { return FGetItem(this,_itemId); }
	virtual void OnLevelNotFound(const char *_levelName);
	virtual void OnLoadingStart(ILevelInfo *_pLevel);
	virtual void OnLoadingLevelEntitiesStart(ILevelInfo *pLevel);
	virtual void OnLoadingComplete(ILevel *_pLevel);
	virtual void OnLoadingError(ILevelInfo *_pLevel, const char *_error);
	virtual void OnLoadingProgress(ILevelInfo *_pLevel, int _progressAmount);
	virtual void OnUnloadComplete(ILevel *_pLevel);
	IEntityArchetype *GetArchetype(const char *_className, const char *_typeName) const { return FGetArchetype(this,_className,_typeName); }
	std::vector<IEntityArchetype *> GetPickupArchetypes() const { return FGetPickupArchetypes(this); }
	std::vector<IEntityArchetype *> GetArchetypesForClass(const char *_className) const { return FGetArchetypesForClass(this,_className); }
	std::vector<IEntityArchetype *> GetRandomizableArchetypes(uint64_t _archetypeId) const { return FGetRandomizableArchetypes(this,_archetypeId); }
	void RemoveFromRandomizable(uint64_t _randomArchetype, uint64_t _archetypeId) { FRemoveFromRandomizable(this,_randomArchetype,_archetypeId); }
	void ClearInvalidArchetypes(uint64_t _randomArchetype) { FClearInvalidArchetypes(this,_randomArchetype); }
	string GetAmmoPickupClassName(string const &_ammoClassName) const { return FGetAmmoPickupClassName(this,_ammoClassName); }
	std::vector<unsigned int> GiveArchetype(unsigned _pickerId, const char *_archetypeName, int _quantity) const { return FGiveArchetypeOv2(this,_pickerId,_archetypeName,_quantity); }
	std::vector<unsigned int> GiveArchetype(unsigned _pickerId, uint64_t _archetypeId, int _quantity) const { return FGiveArchetypeOv1(this,_pickerId,_archetypeId,_quantity); }
	std::vector<unsigned int> GiveArchetype(unsigned _pickerId, IEntityArchetype *_pArchetype, int _quantity) const { return FGiveArchetypeOv0(this,_pickerId,_pArchetype,_quantity); }
	int GiveEntitlementItem(unsigned _inventoryId, uint64_t _archetypeId, int _quantity, uint64_t _associatedEntitlement) const { return FGiveEntitlementItem(this,_inventoryId,_archetypeId,_quantity,_associatedEntitlement); }
	void Reload() { FReload(this); }
	static void GiveItemCmd(IConsoleCmdArgs *_pArgs) { FGiveItemCmd(_pArgs); }
	static void GiveEquipmentPackCmd(IConsoleCmdArgs *_pArgs) { FGiveEquipmentPackCmd(_pArgs); }
	static void ReloadXmlCmd(IConsoleCmdArgs *_pArgs) { FReloadXmlCmd(_pArgs); }
	
#if 0
	CEquipmentManager *GetEquipmentManager() const;
	std::vector<string> const &GetItemClasses() const;
#endif
	
	static inline auto FBitNotArkItemSystem = PreyFunction<void(ArkItemSystem *const _this)>(0x1440750);
	static inline auto FInit = PreyFunction<void(ArkItemSystem *const _this)>(0x14427E0);
	static inline auto FScanXML = PreyFunction<void(ArkItemSystem *const _this, string const &_filename, bool _bReloading)>(0x1443110);
	static inline auto FLoadEquipmentPacks = PreyFunction<void(ArkItemSystem *const _this)>(0x1442980);
	static inline auto FSerialize = PreyFunction<void(ArkItemSystem *const _this, TSerialize _ser)>(0x14437D0);
	static inline auto FAddItem = PreyFunction<void(ArkItemSystem *const _this, unsigned _itemId, IArkItem &_item)>(0x1440C30);
	static inline auto FRemoveItem = PreyFunction<void(ArkItemSystem *const _this, unsigned _itemId)>(0x14430F0);
	static inline auto FGetItem = PreyFunction<IArkItem *(ArkItemSystem const *const _this, unsigned _itemId)>(0x1441450);
	static inline auto FOnLevelNotFound = PreyFunction<void(ArkItemSystem *const _this, const char *_levelName)>(0xA13080);
	static inline auto FOnLoadingStart = PreyFunction<void(ArkItemSystem *const _this, ILevelInfo *_pLevel)>(0x14429B0);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(ArkItemSystem *const _this, ILevelInfo *pLevel)>(0xA13080);
	static inline auto FOnLoadingComplete = PreyFunction<void(ArkItemSystem *const _this, ILevel *_pLevel)>(0xA13080);
	static inline auto FOnLoadingError = PreyFunction<void(ArkItemSystem *const _this, ILevelInfo *_pLevel, const char *_error)>(0xA13080);
	static inline auto FOnLoadingProgress = PreyFunction<void(ArkItemSystem *const _this, ILevelInfo *_pLevel, int _progressAmount)>(0xA13080);
	static inline auto FOnUnloadComplete = PreyFunction<void(ArkItemSystem *const _this, ILevel *_pLevel)>(0xA13080);
	static inline auto FGetArchetype = PreyFunction<IEntityArchetype *(ArkItemSystem const *const _this, const char *_className, const char *_typeName)>(0x1440FA0);
	static inline auto FGetPickupArchetypes = PreyFunction<std::vector<IEntityArchetype *>(ArkItemSystem const *const _this)>(0x1441510);
	static inline auto FGetArchetypesForClass = PreyFunction<std::vector<IEntityArchetype *>(ArkItemSystem const *const _this, const char *_className)>(0x14411D0);
	static inline auto FGetRandomizableArchetypes = PreyFunction<std::vector<IEntityArchetype *>(ArkItemSystem const *const _this, uint64_t _archetypeId)>(0x14415E0);
	static inline auto FRemoveFromRandomizable = PreyFunction<void(ArkItemSystem *const _this, uint64_t _randomArchetype, uint64_t _archetypeId)>(0x1443090);
	static inline auto FClearInvalidArchetypes = PreyFunction<void(ArkItemSystem *const _this, uint64_t _randomArchetype)>(0x1440DB0);
	static inline auto FGetAmmoPickupClassName = PreyFunction<string(ArkItemSystem const *const _this, string const &_ammoClassName)>(0x1440DE0);
	static inline auto FGiveArchetypeOv2 = PreyFunction<std::vector<unsigned int>(ArkItemSystem const *const _this, unsigned _pickerId, const char *_archetypeName, int _quantity)>(0x1442000);
	static inline auto FGiveArchetypeOv1 = PreyFunction<std::vector<unsigned int>(ArkItemSystem const *const _this, unsigned _pickerId, uint64_t _archetypeId, int _quantity)>(0x1442090);
	static inline auto FGiveArchetypeOv0 = PreyFunction<std::vector<unsigned int>(ArkItemSystem const *const _this, unsigned _pickerId, IEntityArchetype *_pArchetype, int _quantity)>(0x1441AB0);
	static inline auto FGiveEntitlementItem = PreyFunction<int(ArkItemSystem const *const _this, unsigned _inventoryId, uint64_t _archetypeId, int _quantity, uint64_t _associatedEntitlement)>(0x14421E0);
	static inline auto FReload = PreyFunction<void(ArkItemSystem *const _this)>(0x1442DE0);
	static inline auto FGiveItemCmd = PreyFunction<void(IConsoleCmdArgs *_pArgs)>(0x14426A0);
	static inline auto FGiveEquipmentPackCmd = PreyFunction<void(IConsoleCmdArgs *_pArgs)>(0x1442640);
	static inline auto FReloadXmlCmd = PreyFunction<void(IConsoleCmdArgs *_pArgs)>(0x1443060);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>

class CEquipmentManager;
struct IArkItem;
struct IConsoleCmdArgs;
struct IEntityArchetype;
struct ILevel;
struct ILevelInfo;
class XmlNodeRef;

// ArkItemSystem
// Header:  Prey/GameDll/ark/ArkItemSystem.h
class ArkItemSystem : public ILevelSystemListener
{ // Size=232 (0xE8)
public:
	// ArkItemSystem::IArkItemCreator
	// Header:  Prey/GameDll/ark/ArkItemSystem.h
	struct IArkItemCreator : public IGameObjectExtensionCreatorBase
	{ // Size=8 (0x8)
	};

	static inline auto k_defaultArkItemScript = PreyGlobal<const char*>(0x23E6750);
	static inline auto k_arkItemConfigFile = PreyGlobal<const char*>(0x23E6758);
	static inline auto k_pickupsLibrary = PreyGlobal<const char*>(0x23E6760);
	static inline auto k_specialWeaponsLibrary = PreyGlobal<const char*>(0x23E6768);
	std::map<string, ArkItemSystem::IArkItemCreator*> m_creators;
	std::unordered_map<unsigned int, IArkItem*> m_items;
	std::unique_ptr<CEquipmentManager> m_pEquipmentManager;
	std::vector<string> m_classes;
	std::unordered_map<string, string> m_projectileToPickup;
	int m_numFabPlansCollected;
	std::array<int, 5> m_qualityWeights;
	std::array<int, 5> m_requiredFabPlans;

	ArkItemSystem();
	virtual ~ArkItemSystem();
	void Init() { FInit(this); }
	void LoadConfig(const XmlNodeRef _node) { FLoadConfig(this, _node); }
	void ScanXML(const string& _filename, bool _bReloading) { FScanXML(this, _filename, _bReloading); }
	void LoadEquipmentPacks() { FLoadEquipmentPacks(this); }
	void AddItem(unsigned _itemId, IArkItem& _item) { FAddItem(this, _itemId, _item); }
	void RemoveItem(unsigned _itemId) { FRemoveItem(this, _itemId); }
	IArkItem* GetItem(unsigned _itemId) const { return FGetItem(this, _itemId); }
	virtual void OnLevelNotFound(const char* _levelName);
	virtual void OnLoadingStart(ILevelInfo* _pLevel);
	virtual void OnLoadingLevelEntitiesStart(ILevelInfo* pLevel);
	virtual void OnLoadingComplete(ILevel* _pLevel);
	virtual void OnLoadingError(ILevelInfo* _pLevel, const char* _error);
	virtual void OnLoadingProgress(ILevelInfo* _pLevel, int _progressAmount);
	virtual void OnUnloadComplete(ILevel* _pLevel);
	IEntityArchetype* GetArchetype(const char* _className, const char* _typeName) const { return FGetArchetype(this, _className, _typeName); }
	std::vector<IEntityArchetype*> GetPickupArchetypes() const { alignas(std::vector<IEntityArchetype*>) std::byte _return_buf_[sizeof(std::vector<IEntityArchetype*>)]; return *FGetPickupArchetypes(this, reinterpret_cast<std::vector<IEntityArchetype*>*>(_return_buf_)); }
	std::vector<IEntityArchetype*> GetArchetypesForClass(const char* _className) const { alignas(std::vector<IEntityArchetype*>) std::byte _return_buf_[sizeof(std::vector<IEntityArchetype*>)]; return *FGetArchetypesForClass(this, reinterpret_cast<std::vector<IEntityArchetype*>*>(_return_buf_), _className); }
	string GetAmmoPickupClassName(const string& _ammoClassName) const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetAmmoPickupClassName(this, reinterpret_cast<string*>(_return_buf_), _ammoClassName); }
	std::vector<unsigned int> GiveArchetype(unsigned _pickerId, const char* _archetypeName, int _quantity, IArkItem::EArkQualityTier _quality) const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGiveArchetypeOv2(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_), _pickerId, _archetypeName, _quantity, _quality); }
	std::vector<unsigned int> GiveArchetype(unsigned _pickerId, uint64_t _archetypeId, int _quantity, IArkItem::EArkQualityTier _quality) const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGiveArchetypeOv1(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_), _pickerId, _archetypeId, _quantity, _quality); }
	std::vector<unsigned int> GiveArchetype(unsigned _pickerId, IEntityArchetype* _pArchetype, int _quantity, IArkItem::EArkQualityTier _quality) const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGiveArchetypeOv0(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_), _pickerId, _pArchetype, _quantity, _quality); }
	static std::vector<unsigned int> SpawnLoot(unsigned _ownerId, uint64_t _lootTableId) { return FSpawnLoot(_ownerId, _lootTableId); }
	int GiveEntitlementItem(unsigned _inventoryId, uint64_t _archetypeId, int _quantity, uint64_t _associatedEntitlement) const { return FGiveEntitlementItem(this, _inventoryId, _archetypeId, _quantity, _associatedEntitlement); }
	IArkItem::EArkQualityTier GetQualityTier(uint64_t _id, bool _bBasedOnFabPlans) const { return FGetQualityTier(this, _id, _bBasedOnFabPlans); }
	void Reload() { FReload(this); }
	static void GiveItemCmd(IConsoleCmdArgs* _pArgs) { FGiveItemCmd(_pArgs); }
	static void GiveEquipmentPackCmd(IConsoleCmdArgs* _pArgs) { FGiveEquipmentPackCmd(_pArgs); }
	static void ReloadXmlCmd(IConsoleCmdArgs* _pArgs) { FReloadXmlCmd(_pArgs); }

#if 0
	CEquipmentManager* GetEquipmentManager() const;
	const std::vector<string>& GetItemClasses() const;
	void PrecacheAssets();
	void UpdateNumFabPlans(int _arg0_);
#endif

	static inline auto FArkItemSystem = PreyFunction<void(ArkItemSystem* const _this)>(0x1555ED0);
	static inline auto FBitNotArkItemSystem = PreyFunction<void(ArkItemSystem* const _this)>(0x1556090);
	static inline auto FInit = PreyFunction<void(ArkItemSystem* const _this)>(0x1557BA0);
	static inline auto FLoadConfig = PreyFunction<void(ArkItemSystem* const _this, const XmlNodeRef _node)>(0x1557D40);
	static inline auto FScanXML = PreyFunction<void(ArkItemSystem* const _this, const string& _filename, bool _bReloading)>(0x1558210);
	static inline auto FLoadEquipmentPacks = PreyFunction<void(ArkItemSystem* const _this)>(0x1557E90);
	static inline auto FAddItem = PreyFunction<void(ArkItemSystem* const _this, unsigned _itemId, IArkItem& _item)>(0x15563E0);
	static inline auto FRemoveItem = PreyFunction<void(ArkItemSystem* const _this, unsigned _itemId)>(0x15581F0);
	static inline auto FGetItem = PreyFunction<IArkItem* (const ArkItemSystem* const _this, unsigned _itemId)>(0x1556B40);
	static inline auto FOnLevelNotFound = PreyFunction<void(ArkItemSystem* const _this, const char* _levelName)>(0x1333E90);
	static inline auto FOnLoadingStart = PreyFunction<void(ArkItemSystem* const _this, ILevelInfo* _pLevel)>(0x1557EC0);
	static inline auto FOnLoadingLevelEntitiesStart = PreyFunction<void(ArkItemSystem* const _this, ILevelInfo* pLevel)>(0x1333E90);
	static inline auto FOnLoadingComplete = PreyFunction<void(ArkItemSystem* const _this, ILevel* _pLevel)>(0x1333E90);
	static inline auto FOnLoadingError = PreyFunction<void(ArkItemSystem* const _this, ILevelInfo* _pLevel, const char* _error)>(0x1333E90);
	static inline auto FOnLoadingProgress = PreyFunction<void(ArkItemSystem* const _this, ILevelInfo* _pLevel, int _progressAmount)>(0x1333E90);
	static inline auto FOnUnloadComplete = PreyFunction<void(ArkItemSystem* const _this, ILevel* _pLevel)>(0x1333E90);
	static inline auto FGetArchetype = PreyFunction<IEntityArchetype* (const ArkItemSystem* const _this, const char* _className, const char* _typeName)>(0x1556720);
	static inline auto FGetPickupArchetypes = PreyFunction<std::vector<IEntityArchetype*>*(const ArkItemSystem* const _this, std::vector<IEntityArchetype*>* _return_value_)>(0x1556C00);
	static inline auto FGetArchetypesForClass = PreyFunction<std::vector<IEntityArchetype*>*(const ArkItemSystem* const _this, std::vector<IEntityArchetype*>* _return_value_, const char* _className)>(0x1556950);
	static inline auto FGetAmmoPickupClassName = PreyFunction<string*(const ArkItemSystem* const _this, string* _return_value_, const string& _ammoClassName)>(0x1556560);
	static inline auto FGiveArchetypeOv2 = PreyFunction<std::vector<unsigned int>*(const ArkItemSystem* const _this, std::vector<unsigned int>* _return_value_, unsigned _pickerId, const char* _archetypeName, int _quantity, IArkItem::EArkQualityTier _quality)>(0x1557390);
	static inline auto FGiveArchetypeOv1 = PreyFunction<std::vector<unsigned int>*(const ArkItemSystem* const _this, std::vector<unsigned int>* _return_value_, unsigned _pickerId, uint64_t _archetypeId, int _quantity, IArkItem::EArkQualityTier _quality)>(0x1557420);
	static inline auto FGiveArchetypeOv0 = PreyFunction<std::vector<unsigned int>*(const ArkItemSystem* const _this, std::vector<unsigned int>* _return_value_, unsigned _pickerId, IEntityArchetype* _pArchetype, int _quantity, IArkItem::EArkQualityTier _quality)>(0x1556DF0);
	static inline auto FSpawnLoot = PreyFunction<std::vector<unsigned int>(unsigned _ownerId, uint64_t _lootTableId)>(0x15588C0);
	static inline auto FGiveEntitlementItem = PreyFunction<int(const ArkItemSystem* const _this, unsigned _inventoryId, uint64_t _archetypeId, int _quantity, uint64_t _associatedEntitlement)>(0x1557580);
	static inline auto FGetQualityTier = PreyFunction<IArkItem::EArkQualityTier(const ArkItemSystem* const _this, uint64_t _id, bool _bBasedOnFabPlans)>(0x1556CD0);
	static inline auto FReload = PreyFunction<void(ArkItemSystem* const _this)>(0x1557F20);
	static inline auto FGiveItemCmd = PreyFunction<void(IConsoleCmdArgs* _pArgs)>(0x1557A40);
	static inline auto FGiveEquipmentPackCmd = PreyFunction<void(IConsoleCmdArgs* _pArgs)>(0x15579E0);
	static inline auto FReloadXmlCmd = PreyFunction<void(IConsoleCmdArgs* _pArgs)>(0x15581C0);
};

// ArkItemSystem::CArkItemCreator<ArkCraftingIngredient>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<ArkCraftingIngredient> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<ArkCraftingIngredient>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826490);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<ArkCraftingIngredient>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<ArkNeuromod>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<ArkNeuromod> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<ArkNeuromod>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x18264F0);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<ArkNeuromod>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<ArkWeaponDoubleWrench>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<ArkWeaponDoubleWrench> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<ArkWeaponDoubleWrench>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826550);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<ArkWeaponDoubleWrench>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<ArkWeaponSword>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<ArkWeaponSword> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<ArkWeaponSword>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x18266B0);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<ArkWeaponSword>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<ArkWeaponWrench>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<ArkWeaponWrench> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<ArkWeaponWrench>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826730);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<ArkWeaponWrench>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkItem>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkItem> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkItem>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x18268F0);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkItem>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeapon>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeapon> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeapon>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826950);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeapon>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponDiscRifle>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponDiscRifle> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponDiscRifle>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x18269D0);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponDiscRifle>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponGooGun>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponGooGun> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponGooGun>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826A50);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponGooGun>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponGrenade>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponGrenade> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponGrenade>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826AD0);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponGrenade>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponInstalaser>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponInstalaser> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponInstalaser>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826B50);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponInstalaser>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponRapidFire>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponRapidFire> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponRapidFire>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826BD0);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponRapidFire>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponRecyclizer>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponRecyclizer> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponRecyclizer>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826C50);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponRecyclizer>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponShotgun>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponShotgun> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponShotgun>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826CD0);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponShotgun>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};

// ArkItemSystem::CArkItemCreator<CArkWeaponStunGun>
// Header:  Prey/GameDll/ark/ArkItemSystem.h
struct CArkItemCreator<CArkWeaponStunGun> : public ArkItemSystem::IArkItemCreator
{ // Size=8 (0x8)
	virtual std::shared_ptr<IGameObjectExtension> Create();
	virtual void GetGameObjectExtensionRMIData(void* * _ppRMI, uint64_t* _nCount);

	static inline auto FCreate = PreyFunction<std::shared_ptr<IGameObjectExtension>*(ArkItemSystem::CArkItemCreator<CArkWeaponStunGun>* const _this, std::shared_ptr<IGameObjectExtension>* _return_value_)>(0x1826D50);
	static inline auto FGetGameObjectExtensionRMIData = PreyFunction<void(ArkItemSystem::CArkItemCreator<CArkWeaponStunGun>* const _this, void* * _ppRMI, uint64_t* _nCount)>(0x1829C50);
};
#endif // !MOONCRASH
