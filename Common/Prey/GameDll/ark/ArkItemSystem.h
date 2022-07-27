// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ILevelSystem.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkitemsystem.h>

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
#if 0
		virtual std::shared_ptr<IGameObjectExtension> Create();
		virtual void GetGameObjectExtensionRMIData(void** _ppRMI, uint64_t* _nCount);
		void CArkItemCreator();
		void CArkItemCreator(ArkItemSystem::CArkItemCreator const& arg0);
		void CArkItemCreator(ArkItemSystem::CArkItemCreator* arg0);
		virtual void ~CArkItemCreator();
#endif
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

