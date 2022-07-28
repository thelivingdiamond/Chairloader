// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkInventory.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

class ArkItemSystem;
struct IArkItem;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class XmlNodeRef;

// Header: Exact
// Prey/GameDll/ArkInventory.h
class ArkInventory : public CGameObjectExtensionHelper<ArkInventory,IGameObjectExtension>, public IArkPlayerInteractionListener, public IEntityEventListener, public IArkInventory // Id=801521B Size=136
{
public:
	static constexpr const int k_defaultExternalInventoryWidth = 6;
	static constexpr const int k_tinyExternalInventoryWidth = 1;
	static constexpr const int k_tinyExternalInventoryHeight = 1;
	static constexpr const int k_smallExternalInventoryHeight = 2;
	static constexpr const int k_mediumExternalInventoryHeight = 4;
	static constexpr const int k_largeExternalInventoryHeight = 8;
	static constexpr const int k_chipSetHeight = 100;
	
	enum class EArkGridSizes
	{
		tinyExternal = 0,
		smallExternal = 1,
		mediumExternal = 2,
		largeExternal = 3,
		chipSet = 4,
		player = 5,
		overflow = 6,
	};

	struct StorageCell // Id=8015232 Size=20
	{
		unsigned m_entityId;
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		
#if 0
		void Serialize(TSerialize arg0);
		int GetMaxX() const;
		int GetMaxY() const;
		bool Intersects(ArkInventory::StorageCell const &arg0) const;
		void InvalidateLocation();
		bool operator<(ArkInventory::StorageCell const &arg0) const;
		bool operator==(unsigned arg0) const;
#endif
	};

	bool m_bSortDirty;
	bool m_bSerializeOpen;
	bool m_bPreventStorage;
	bool m_bTakesTrash;
	ArkInventory::EArkGridSizes m_size;
	std::vector<ArkInventory::StorageCell> m_storedItems;
	ArkSimpleTimer m_lookAtTimer;
	
	enum class InventorySort
	{
		none = 0,
		name = 1,
		category = 2,
		size = 3,
		last = 4,
	};

	ArkInventory::InventorySort m_currentSort;
	
	ArkInventory();
	virtual ~ArkInventory();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual void PostReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int __formal);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &__formal);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *__formal) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual bool AddItem(unsigned _itemId);
	virtual void RemoveItem(unsigned _itemId);
	virtual void RemoveItem(uint64_t _archetypeId, int _quantity);
	void RemoveAllItems() { FRemoveAllItems(this); }
	void Clear() { FClear(this); }
	virtual void NotifyOfItemCountChange(unsigned _itemId) const;
	virtual unsigned GetItemAtLocation(int _x, int _y, unsigned _ignoreId) const;
	virtual std::pair<int,int> GetLocationOfItem(unsigned _itemId) const;
	virtual unsigned GetNextItem(int _x, int _y, unsigned _ignoreId) const;
	unsigned GetSmallestFromArchetypes(std::vector<unsigned __int64> const &_archetypes) const { return FGetSmallestFromArchetypes(this,_archetypes); }
	virtual unsigned PlaceItem(unsigned _itemId, int _x, int _y);
	virtual bool CanPlaceItem(unsigned _itemId, int _x, int _y, bool _bAllowDisplacement) const;
	virtual bool TryPlaceItem(unsigned _itemId, int _x, int _y);
	virtual bool CanPackItem(unsigned _itemId) const;
	bool CanPackItem(int _width, int _height) const { return FCanPackItemOv0(this,_width,_height); }
	std::vector<unsigned int> Sort() { return FSortOv1(this); }
	std::vector<unsigned int> Sort(std::function<bool __cdecl(IArkItem const *,IArkItem const *)> _compare) { return FSortOv0(this,_compare); }
	string GetSortLabel() const { return FGetSortLabel(this); }
	virtual int GetWidth() const;
	virtual int GetMaxWidth() const;
	virtual int GetHeight() const;
	void SetSize(ArkInventory::EArkGridSizes _size) { FSetSize(this,_size); }
	virtual unsigned GetOwnerId() const;
	virtual bool GetTakesTrash() const;
	virtual bool Contains(unsigned _entityId) const;
	virtual std::vector<unsigned int> GetItemIDs() const;
	virtual std::vector<IArkItem *> GetItemsOfArchetype(uint64_t _archetypeId) const;
	virtual int GetCountOfArchetype(uint64_t _archetypeId) const;
	int GetCountWithMetaTags(std::vector<unsigned __int64> const &_tags) const { return FGetCountWithMetaTags(this,_tags); }
	virtual bool IsEmpty() const;
	bool ContainsPlotCriticalItem() const { return FContainsPlotCriticalItem(this); }
	bool CanQuickLoot() const { return FCanQuickLoot(this); }
	void OpenQuickLoot(unsigned _targetId) { FOpenQuickLoot(this,_targetId); }
	virtual void NotifyAdded(unsigned _itemId, unsigned _originalId) const;
	void SerializeForLevelChange(TSerialize _ser) { FSerializeForLevelChange(this,_ser); }
	void PostSerializeForLevelChange() { FPostSerializeForLevelChange(this); }
	virtual std::vector<unsigned int> GetOverlappingItems(const unsigned _itemId, const int _x, const int _y, const int _width, const int _height) const;
	std::vector<unsigned int> GetOverlappingItems(ArkInventory::StorageCell const &_cell) const { return FGetOverlappingItemsOv0(this,_cell); }
	void OnExternalInventoryUIClose() { FOnExternalInventoryUIClose(this); }
	void PlayOpenAnimation() { FPlayOpenAnimation(this); }
	void PlayCloseAnimation() { FPlayCloseAnimation(this); }
	virtual void DoMetricsSnapshot(XmlNodeRef const &_node) const;
	wstring GetName() const { return FGetName(this); }
	std::pair<bool,unsigned int> PlaceItemQuietly(unsigned _itemId, int _x, int _y) { return FPlaceItemQuietly(this,_itemId,_x,_y); }
	bool RemoveItemQuietly(unsigned _itemId) { return FRemoveItemQuietly(this,_itemId); }
	bool PackItem(unsigned _itemId) { return FPackItem(this,_itemId); }
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	boost::optional<std::pair<int,int> > GetValidFreeCellLocation(int _width, int _height) const { return FGetValidFreeCellLocation(this,_width,_height); }
	static bool LootableSort(IArkItem const *_pItem1, IArkItem const *_pItem2) { return FLootableSort(_pItem1,_pItem2); }
	void PlayAnimation(string const &_animName) { FPlayAnimation(this,_animName); }
	
#if 0
	ArkInventory::EArkGridSizes GetSize() const;
	void SetTakesTrash(bool arg0);
	bool GetPreventStorage() const;
	void SetPreventStorage(const bool arg0);
	std::vector<IArkItem *> GetItemsWithMetaTags(std::vector<unsigned __int64> const &arg0) const;
	bool IsLocked() const;
	bool IsOpen() const;
	bool IsPlayerInventory() const;
	static ArkItemSystem &GetArkItemSystem();
	std::vector<ArkInventory::StorageCell> GetFreeCells() const;
	bool ValidateEntities() const;
	bool IsSortable() const;
#endif
	
	static inline auto FBitNotArkInventory = PreyFunction<void(ArkInventory *const _this)>(0x10A9860);
	static inline auto FInit = PreyFunction<bool(ArkInventory *const _this, IGameObject *_pGameObject)>(0x10AC390);
	static inline auto FInitClient = PreyFunction<void(ArkInventory *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkInventory *const _this, IGameObject *pGameObject)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(ArkInventory *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkInventory *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0x1B933B0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkInventory *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkInventory *const _this, TSerialize signature)>(0x1B933B0);
	static inline auto FRelease = PreyFunction<void(ArkInventory *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(ArkInventory *const _this, TSerialize _ser)>(0x10AB1D0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkInventory *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkInventory *const _this)>(0x10AD1B0);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkInventory *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkInventory *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkInventory *const _this, SEntityUpdateContext &_ctx, int __formal)>(0x10AE8B0);
	static inline auto FPostUpdate = PreyFunction<void(ArkInventory *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkInventory *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkInventory *const _this, SGameObjectEvent const &__formal)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkInventory *const _this, SEntityEvent &_event)>(0x10AD520);
	static inline auto FSetChannelId = PreyFunction<void(ArkInventory *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkInventory *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkInventory const *const _this, ICrySizer *__formal)>(0xA13080);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkInventory *const _this, unsigned _targetId)>(0x10AC820);
	static inline auto FOnStopLookingAt = PreyFunction<void(ArkInventory *const _this, unsigned _targetId)>(0x10AC890);
	static inline auto FAddItem = PreyFunction<bool(ArkInventory *const _this, unsigned _itemId)>(0x10A9F40);
	static inline auto FRemoveItemOv1 = PreyFunction<void(ArkInventory *const _this, unsigned _itemId)>(0x10AD630);
	static inline auto FRemoveItemOv0 = PreyFunction<void(ArkInventory *const _this, uint64_t _archetypeId, int _quantity)>(0x10AD7A0);
	static inline auto FRemoveAllItems = PreyFunction<void(ArkInventory *const _this)>(0x10AD540);
	static inline auto FClear = PreyFunction<void(ArkInventory *const _this)>(0x10AA320);
	static inline auto FNotifyOfItemCountChange = PreyFunction<void(ArkInventory const *const _this, unsigned _itemId)>(0x10AC600);
	static inline auto FGetItemAtLocation = PreyFunction<unsigned(ArkInventory const *const _this, int _x, int _y, unsigned _ignoreId)>(0x10AB6F0);
	static inline auto FGetLocationOfItem = PreyFunction<std::pair<int,int>(ArkInventory const *const _this, unsigned _itemId)>(0x10AB970);
	static inline auto FGetNextItem = PreyFunction<unsigned(ArkInventory const *const _this, int _x, int _y, unsigned _ignoreId)>(0x10ABA90);
	static inline auto FGetSmallestFromArchetypes = PreyFunction<unsigned(ArkInventory const *const _this, std::vector<unsigned __int64> const &_archetypes)>(0x10ABCA0);
	static inline auto FPlaceItem = PreyFunction<unsigned(ArkInventory *const _this, unsigned _itemId, int _x, int _y)>(0x10ACA60);
	static inline auto FCanPlaceItem = PreyFunction<bool(ArkInventory const *const _this, unsigned _itemId, int _x, int _y, bool _bAllowDisplacement)>(0x10A9FD0);
	static inline auto FTryPlaceItem = PreyFunction<bool(ArkInventory *const _this, unsigned _itemId, int _x, int _y)>(0x10AE840);
	static inline auto FCanPackItemOv1 = PreyFunction<bool(ArkInventory const *const _this, unsigned _itemId)>(0x10A9F70);
	static inline auto FCanPackItemOv0 = PreyFunction<bool(ArkInventory const *const _this, int _width, int _height)>(0x10A9F50);
	static inline auto FSortOv1 = PreyFunction<std::vector<unsigned int>(ArkInventory *const _this)>(0x10AE790);
	static inline auto FSortOv0 = PreyFunction<std::vector<unsigned int>(ArkInventory *const _this, std::function<bool __cdecl(IArkItem const *,IArkItem const *)> _compare)>(0x10AE210);
	static inline auto FGetSortLabel = PreyFunction<string(ArkInventory const *const _this)>(0x10ABE60);
	static inline auto FGetWidth = PreyFunction<int(ArkInventory const *const _this)>(0x10AC330);
	static inline auto FGetMaxWidth = PreyFunction<int(ArkInventory const *const _this)>(0x10AB9B0);
	static inline auto FGetHeight = PreyFunction<int(ArkInventory const *const _this)>(0x10AB650);
	static inline auto FSetSize = PreyFunction<void(ArkInventory *const _this, ArkInventory::EArkGridSizes _size)>(0x10AE200);
	static inline auto FGetOwnerId = PreyFunction<unsigned(ArkInventory const *const _this)>(0x10ABC80);
	static inline auto FGetTakesTrash = PreyFunction<bool(ArkInventory const *const _this)>(0x10ABF80);
	static inline auto FContains = PreyFunction<bool(ArkInventory const *const _this, unsigned _entityId)>(0x10AA3B0);
	static inline auto FGetItemIDs = PreyFunction<std::vector<unsigned int>(ArkInventory const *const _this)>(0x10AB810);
	static inline auto FGetItemsOfArchetype = PreyFunction<std::vector<IArkItem *>(ArkInventory const *const _this, uint64_t _archetypeId)>(0x10AB8C0);
	static inline auto FGetCountOfArchetype = PreyFunction<int(ArkInventory const *const _this, uint64_t _archetypeId)>(0x10AB410);
	static inline auto FGetCountWithMetaTags = PreyFunction<int(ArkInventory const *const _this, std::vector<unsigned __int64> const &_tags)>(0x10AB500);
	static inline auto FIsEmpty = PreyFunction<bool(ArkInventory const *const _this)>(0xA84110);
	static inline auto FContainsPlotCriticalItem = PreyFunction<bool(ArkInventory const *const _this)>(0x10AA3E0);
	static inline auto FCanQuickLoot = PreyFunction<bool(ArkInventory const *const _this)>(0x10AA1B0);
	static inline auto FOpenQuickLoot = PreyFunction<void(ArkInventory *const _this, unsigned _targetId)>(0x10AC8F0);
	static inline auto FNotifyAdded = PreyFunction<void(ArkInventory const *const _this, unsigned _itemId, unsigned _originalId)>(0x10AC500);
	static inline auto FSerializeForLevelChange = PreyFunction<void(ArkInventory *const _this, TSerialize _ser)>(0x10ADAC0);
	static inline auto FPostSerializeForLevelChange = PreyFunction<void(ArkInventory *const _this)>(0x10AD3C0);
	static inline auto FGetOverlappingItemsOv1 = PreyFunction<std::vector<unsigned int>(ArkInventory const *const _this, const unsigned _itemId, const int _x, const int _y, const int _width, const int _height)>(0x10ABC30);
	static inline auto FGetOverlappingItemsOv0 = PreyFunction<std::vector<unsigned int>(ArkInventory const *const _this, ArkInventory::StorageCell const &_cell)>(0x10ABB60);
	static inline auto FOnExternalInventoryUIClose = PreyFunction<void(ArkInventory *const _this)>(0x10AC6C0);
	static inline auto FPlayOpenAnimation = PreyFunction<void(ArkInventory *const _this)>(0x10AD000);
	static inline auto FPlayCloseAnimation = PreyFunction<void(ArkInventory *const _this)>(0x10ACE50);
	static inline auto FDoMetricsSnapshot = PreyFunction<void(ArkInventory const *const _this, XmlNodeRef const &_node)>(0x10AA520);
	static inline auto FGetName = PreyFunction<wstring(ArkInventory const *const _this)>(0x10AB9D0);
	static inline auto FPlaceItemQuietly = PreyFunction<std::pair<bool,unsigned int>(ArkInventory *const _this, unsigned _itemId, int _x, int _y)>(0x10ACAB0);
	static inline auto FRemoveItemQuietly = PreyFunction<bool(ArkInventory *const _this, unsigned _itemId)>(0x10AD9A0);
	static inline auto FPackItem = PreyFunction<bool(ArkInventory *const _this, unsigned _itemId)>(0x10AC9D0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkInventory *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x10AC680);
	static inline auto FGetValidFreeCellLocation = PreyFunction<boost::optional<std::pair<int,int> >(ArkInventory const *const _this, int _width, int _height)>(0x10ABF90);
	static inline auto FLootableSort = PreyFunction<bool(IArkItem const *_pItem1, IArkItem const *_pItem2)>(0x10AC4C0);
	static inline auto FPlayAnimation = PreyFunction<void(ArkInventory *const _this, string const &_animName)>(0x10ACD60);
};

