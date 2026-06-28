// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
	virtual void Update(SEntityUpdateContext &_ctx, int );
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *) const;
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
	static inline auto FUpdate = PreyFunction<void(ArkInventory *const _this, SEntityUpdateContext &_ctx, int )>(0x10AE8B0);
	static inline auto FPostUpdate = PreyFunction<void(ArkInventory *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkInventory *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkInventory *const _this, SGameObjectEvent const &)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkInventory *const _this, SEntityEvent &_event)>(0x10AD520);
	static inline auto FSetChannelId = PreyFunction<void(ArkInventory *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkInventory *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkInventory const *const _this, ICrySizer *)>(0xA13080);
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

class ArkItemSystem;
enum EEntityAspects;
struct IArkItem;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class XmlNodeRef;

// ArkInventory
// Header:  Prey/GameDll/ArkInventory.h
class ArkInventory
	: public CGameObjectExtensionHelper<ArkInventory, IGameObjectExtension>
	, public IArkPlayerInteractionListener
	, public IEntityEventListener
{ // Size=128 (0x80)
public:
	enum class EArkGridSizes
	{
		tinyExternal = 0,
		smallExternal = 1,
		mediumExternal = 2,
		largeExternal = 3,
		chipSet = 4,
		player = 5,
		overflow = 6,
		store = 7,
	};

	enum class InventorySort
	{
		none = 0,
		name = 1,
		category = 2,
		size = 3,
		quality = 4,
		last = 5,
	};

	// ArkInventory::StorageCell
	// Header:  Prey/GameDll/ArkInventory.h
	struct StorageCell
	{ // Size=20 (0x14)
		unsigned m_entityId;
		int m_x;
		int m_y;
		int m_width;
		int m_height;

	#if 0
		StorageCell();
		StorageCell(unsigned _arg0_, int _arg1_, int _arg2_, int _arg3_, int _arg4_);
		void Serialize(TSerialize _arg0_);
		int GetMaxX() const;
		int GetMaxY() const;
		bool Intersects(const ArkInventory::StorageCell& _arg0_) const;
		void InvalidateLocation();
		bool operator<(const ArkInventory::StorageCell& _arg0_) const;
		bool operator==(unsigned _arg0_) const;
	#endif
	};

	static constexpr const int k_defaultExternalInventoryWidth = 6;
	static constexpr const int k_tinyExternalInventoryWidth = 1;
	static constexpr const int k_tinyExternalInventoryHeight = 1;
	static constexpr const int k_smallExternalInventoryHeight = 2;
	static constexpr const int k_mediumExternalInventoryHeight = 4;
	static constexpr const int k_largeExternalInventoryHeight = 8;
	static constexpr const int k_chipSetHeight = 100;
	bool m_bSortDirty;
	bool m_bSerializeOpen;
	bool m_bPreventStorage;
	bool m_bTakesTrash;
	ArkInventory::EArkGridSizes m_size;
	std::vector<ArkInventory::StorageCell> m_storedItems;
	ArkSimpleTimer m_lookAtTimer;
	ArkInventory::InventorySort m_currentSort;

	static ArkInventory::EArkGridSizes GetGridSizeFromString(const char* _string) { return FGetGridSizeFromString(_string); }
	ArkInventory();
	virtual ~ArkInventory();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int __unnamed1);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& __unnamed1);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* __unnamed1) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	bool AddItem(unsigned _itemId) { return FAddItem(this, _itemId); }
	virtual void RemoveItem(unsigned _itemId);
	void RemoveItem(uint64_t _archetypeId, int _quantity) { FRemoveItemOv0(this, _archetypeId, _quantity); }
	void RemoveAllItems() { FRemoveAllItems(this); }
	void Clear() { FClear(this); }
	void NotifyOfItemCountChange(unsigned _itemId) const { FNotifyOfItemCountChange(this, _itemId); }
	unsigned GetItemAtLocation(int _x, int _y, unsigned _ignoreId) const { return FGetItemAtLocation(this, _x, _y, _ignoreId); }
	std::pair<int, int> GetLocationOfItem(unsigned _itemId) const { alignas(std::pair<int, int>) std::byte _return_buf_[sizeof(std::pair<int, int>)]; return *FGetLocationOfItem(this, reinterpret_cast<std::pair<int, int>*>(_return_buf_), _itemId); }
	unsigned GetNextItem(int _x, int _y, unsigned _ignoreId) const { return FGetNextItem(this, _x, _y, _ignoreId); }
	unsigned GetSmallestFromArchetypes(const std::vector<uint64_t>& _archetypes) const { return FGetSmallestFromArchetypes(this, _archetypes); }
	virtual unsigned PlaceItem(unsigned _itemId, int _x, int _y);
	bool CanPlaceItem(unsigned _itemId, int _x, int _y, bool _bAllowDisplacement) const { return FCanPlaceItem(this, _itemId, _x, _y, _bAllowDisplacement); }
	bool TryPlaceItem(unsigned _itemId, int _x, int _y) { return FTryPlaceItem(this, _itemId, _x, _y); }
	bool CanPackItem(unsigned _itemId) const { return FCanPackItemOv1(this, _itemId); }
	bool CanPackItem(int _width, int _height) const { return FCanPackItemOv0(this, _width, _height); }
	std::vector<unsigned int> Sort() { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FSortOv1(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_)); }
	std::vector<unsigned int> Sort(std::function<bool __cdecl(IArkItem const *,IArkItem const *)> _compare) { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FSortOv0(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_), _compare); }
	string GetSortLabel() const { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetSortLabel(this, reinterpret_cast<string*>(_return_buf_)); }
	int GetWidth() const { return FGetWidth(this); }
	int GetMaxWidth() const { return FGetMaxWidth(this); }
	int GetHeight() const { return FGetHeight(this); }
	void SetSize(ArkInventory::EArkGridSizes _size) { FSetSize(this, _size); }
	unsigned GetOwnerId() const { return FGetOwnerId(this); }
	bool Contains(unsigned _entityId) const { return FContains(this, _entityId); }
	std::vector<unsigned int> GetItemIDs() const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGetItemIDs(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_)); }
	std::vector<IArkItem*> GetItemsOfArchetype(uint64_t _archetypeId) const { alignas(std::vector<IArkItem*>) std::byte _return_buf_[sizeof(std::vector<IArkItem*>)]; return *FGetItemsOfArchetype(this, reinterpret_cast<std::vector<IArkItem*>*>(_return_buf_), _archetypeId); }
	int GetCountOfArchetype(uint64_t _archetypeId) const { return FGetCountOfArchetype(this, _archetypeId); }
	int GetCountWithMetaTags(const std::vector<uint64_t>& _tags) const { return FGetCountWithMetaTags(this, _tags); }
	bool IsEmpty() const { return FIsEmpty(this); }
	bool ContainsPlotCriticalItem() const { return FContainsPlotCriticalItem(this); }
	bool CanQuickLoot() const { return FCanQuickLoot(this); }
	void OpenQuickLoot(unsigned _targetId) { FOpenQuickLoot(this, _targetId); }
	void NotifyAdded(unsigned _itemId, unsigned _originalId) const { FNotifyAdded(this, _itemId, _originalId); }
	void SerializeForLevelChange(TSerialize _ser) { FSerializeForLevelChange(this, _ser); }
	void PostSerializeForLevelChange() { FPostSerializeForLevelChange(this); }
	std::vector<unsigned int> GetOverlappingItems(const unsigned _itemId, const int _x, const int _y, const int _width, const int _height) const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGetOverlappingItemsOv1(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_), _itemId, _x, _y, _width, _height); }
	std::vector<unsigned int> GetOverlappingItems(const ArkInventory::StorageCell& _cell) const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGetOverlappingItemsOv0(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_), _cell); }
	void OnExternalInventoryUIClose() { FOnExternalInventoryUIClose(this); }
	void PlayOpenAnimation(const bool _bSerializing) { FPlayOpenAnimation(this, _bSerializing); }
	void PlayCloseAnimation() { FPlayCloseAnimation(this); }
	wstring GetName() const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetName(this, reinterpret_cast<wstring*>(_return_buf_)); }
	virtual bool IsPrimaryInventory() const;
	std::pair<bool, unsigned int> PlaceItemQuietly(unsigned _itemId, int _x, int _y) { alignas(std::pair<bool, unsigned int>) std::byte _return_buf_[sizeof(std::pair<bool, unsigned int>)]; return *FPlaceItemQuietly(this, reinterpret_cast<std::pair<bool, unsigned int>*>(_return_buf_), _itemId, _x, _y); }
	bool RemoveItemQuietly(unsigned _itemId) { return FRemoveItemQuietly(this, _itemId); }
	bool PackItem(unsigned _itemId) { return FPackItem(this, _itemId); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	void InitHelper(IGameObject* _pGameObject) { FInitHelper(this, _pGameObject); }
	void DestructorHelper() { FDestructorHelper(this); }
	boost::optional<std::pair<int,int> > GetValidFreeCellLocation(int _width, int _height) const { alignas(boost::optional<std::pair<int,int> >) std::byte _return_buf_[sizeof(boost::optional<std::pair<int,int> >)]; return *FGetValidFreeCellLocation(this, reinterpret_cast<boost::optional<std::pair<int,int> >*>(_return_buf_), _width, _height); }
	static bool LootableSort(const IArkItem* _pItem1, const IArkItem* _pItem2) { return FLootableSort(_pItem1, _pItem2); }
	void PlayAnimation(const string& _animName, const bool _bSerializing) { FPlayAnimation(this, _animName, _bSerializing); }

#if 0
	ArkInventory::EArkGridSizes GetSize() const;
	bool GetTakesTrash() const;
	void SetTakesTrash(bool _arg0_);
	bool GetPreventStorage() const;
	void SetPreventStorage(const bool _arg0_);
	std::vector<IArkItem*> GetItemsWithMetaTags(const std::vector<uint64_t>& _arg0_) const;
	bool IsLocked() const;
	bool IsOpen() const;
	void DoMetricsSnapshot(const XmlNodeRef& _arg0_) const;
	bool IsPlayerInventory() const;
	static ArkItemSystem& GetArkItemSystem();
	std::vector<ArkInventory::StorageCell> GetFreeCells() const;
	bool ValidateEntities() const;
	bool IsSortable() const;
#endif

	static inline auto FGetGridSizeFromString = PreyFunction<ArkInventory::EArkGridSizes(const char* _string)>(0x10D9AF0);
	static inline auto FArkInventoryOv1 = PreyFunction<void(ArkInventory* const _this)>(0x1825E50);
	static inline auto FBitNotArkInventory = PreyFunction<void(ArkInventory* const _this)>(0x10D8900);
	static inline auto FInit = PreyFunction<bool(ArkInventory* const _this, IGameObject* _pGameObject)>(0x10DAA60);
	static inline auto FInitClient = PreyFunction<void(ArkInventory* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(ArkInventory* const _this, IGameObject* pGameObject)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(ArkInventory* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkInventory* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkInventory* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkInventory* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(ArkInventory* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(ArkInventory* const _this, TSerialize _ser)>(0x10D9670);
	static inline auto FNetSerialize = PreyFunction<bool(ArkInventory* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkInventory* const _this)>(0x10DBB80);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkInventory* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkInventory* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkInventory* const _this, SEntityUpdateContext& _ctx, int __unnamed1)>(0x10DD320);
	static inline auto FPostUpdate = PreyFunction<void(ArkInventory* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkInventory* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkInventory* const _this, const SGameObjectEvent& __unnamed1)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(ArkInventory* const _this, SEntityEvent& _event)>(0x10DBF60);
	static inline auto FSetChannelId = PreyFunction<void(ArkInventory* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkInventory* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkInventory* const _this, ICrySizer* __unnamed1)>(0x1333E90);
	static inline auto FOnStartLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x10DB020);
	static inline auto FOnStopLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x10DB1B0);
	static inline auto FAddItem = PreyFunction<bool(ArkInventory* const _this, unsigned _itemId)>(0x10D8FD0);
	static inline auto FRemoveItemOv1 = PreyFunction<void(ArkInventory* const _this, unsigned _itemId)>(0x10DC250);
	static inline auto FRemoveItemOv0 = PreyFunction<void(ArkInventory* const _this, uint64_t _archetypeId, int _quantity)>(0x10DC060);
	static inline auto FRemoveAllItems = PreyFunction<void(ArkInventory* const _this)>(0x10DBF80);
	static inline auto FClear = PreyFunction<void(ArkInventory* const _this)>(0x10D9390);
	static inline auto FNotifyOfItemCountChange = PreyFunction<void(const ArkInventory* const _this, unsigned _itemId)>(0x10DADE0);
	static inline auto FGetItemAtLocation = PreyFunction<unsigned(const ArkInventory* const _this, int _x, int _y, unsigned _ignoreId)>(0x10D9C30);
	static inline auto FGetLocationOfItem = PreyFunction<std::pair<int, int>*(const ArkInventory* const _this, std::pair<int, int>* _return_value_, unsigned _itemId)>(0x10D9EB0);
	static inline auto FGetNextItem = PreyFunction<unsigned(const ArkInventory* const _this, int _x, int _y, unsigned _ignoreId)>(0x10D9FF0);
	static inline auto FGetSmallestFromArchetypes = PreyFunction<unsigned(const ArkInventory* const _this, const std::vector<uint64_t>& _archetypes)>(0x10DA310);
	static inline auto FPlaceItem = PreyFunction<unsigned(ArkInventory* const _this, unsigned _itemId, int _x, int _y)>(0x10DB370);
	static inline auto FCanPlaceItem = PreyFunction<bool(const ArkInventory* const _this, unsigned _itemId, int _x, int _y, bool _bAllowDisplacement)>(0x10D9060);
	static inline auto FTryPlaceItem = PreyFunction<bool(ArkInventory* const _this, unsigned _itemId, int _x, int _y)>(0x10DD2C0);
	static inline auto FCanPackItemOv1 = PreyFunction<bool(const ArkInventory* const _this, unsigned _itemId)>(0x10D9000);
	static inline auto FCanPackItemOv0 = PreyFunction<bool(const ArkInventory* const _this, int _width, int _height)>(0x10D8FE0);
	static inline auto FSortOv1 = PreyFunction<std::vector<unsigned int>*(ArkInventory* const _this, std::vector<unsigned int>* _return_value_)>(0x10DD210);
	static inline auto FSortOv0 = PreyFunction<std::vector<unsigned int>*(ArkInventory* const _this, std::vector<unsigned int>* _return_value_, std::function<bool __cdecl(IArkItem const *,IArkItem const *)> _compare)>(0x10DCC50);
	static inline auto FGetSortLabel = PreyFunction<string*(const ArkInventory* const _this, string* _return_value_)>(0x10DA4D0);
	static inline auto FGetWidth = PreyFunction<int(const ArkInventory* const _this)>(0x10DA9A0);
	static inline auto FGetMaxWidth = PreyFunction<int(const ArkInventory* const _this)>(0x10D9EF0);
	static inline auto FGetHeight = PreyFunction<int(const ArkInventory* const _this)>(0x10D9B60);
	static inline auto FSetSize = PreyFunction<void(ArkInventory* const _this, ArkInventory::EArkGridSizes _size)>(0x10E59C0);
	static inline auto FGetOwnerId = PreyFunction<unsigned(const ArkInventory* const _this)>(0x10DA2F0);
	static inline auto FContains = PreyFunction<bool(const ArkInventory* const _this, unsigned _entityId)>(0x10D9420);
	static inline auto FGetItemIDs = PreyFunction<std::vector<unsigned int>*(const ArkInventory* const _this, std::vector<unsigned int>* _return_value_)>(0x10D9D50);
	static inline auto FGetItemsOfArchetype = PreyFunction<std::vector<IArkItem*>*(const ArkInventory* const _this, std::vector<IArkItem*>* _return_value_, uint64_t _archetypeId)>(0x10D9E00);
	static inline auto FGetCountOfArchetype = PreyFunction<int(const ArkInventory* const _this, uint64_t _archetypeId)>(0x10D98B0);
	static inline auto FGetCountWithMetaTags = PreyFunction<int(const ArkInventory* const _this, const std::vector<uint64_t>& _tags)>(0x10D99A0);
	static inline auto FIsEmpty = PreyFunction<bool(const ArkInventory* const _this)>(0x10DACA0);
	static inline auto FContainsPlotCriticalItem = PreyFunction<bool(const ArkInventory* const _this)>(0x10D9450);
	static inline auto FCanQuickLoot = PreyFunction<bool(const ArkInventory* const _this)>(0x10D9230);
	static inline auto FOpenQuickLoot = PreyFunction<void(ArkInventory* const _this, unsigned _targetId)>(0x10DB200);
	static inline auto FNotifyAdded = PreyFunction<void(const ArkInventory* const _this, unsigned _itemId, unsigned _originalId)>(0x10DAD30);
	static inline auto FSerializeForLevelChange = PreyFunction<void(ArkInventory* const _this, TSerialize _ser)>(0x10DC510);
	static inline auto FPostSerializeForLevelChange = PreyFunction<void(ArkInventory* const _this)>(0x10DBE00);
	static inline auto FGetOverlappingItemsOv1 = PreyFunction<std::vector<unsigned int>*(const ArkInventory* const _this, std::vector<unsigned int>* _return_value_, const unsigned _itemId, const int _x, const int _y, const int _width, const int _height)>(0x10DA2A0);
	static inline auto FGetOverlappingItemsOv0 = PreyFunction<std::vector<unsigned int>*(const ArkInventory* const _this, std::vector<unsigned int>* _return_value_, const ArkInventory::StorageCell& _cell)>(0x10DA1D0);
	static inline auto FOnExternalInventoryUIClose = PreyFunction<void(ArkInventory* const _this)>(0x10DAED0);
	static inline auto FPlayOpenAnimation = PreyFunction<void(ArkInventory* const _this, const bool _bSerializing)>(0x10DB9B0);
	static inline auto FPlayCloseAnimation = PreyFunction<void(ArkInventory* const _this)>(0x10DB7F0);
	static inline auto FGetName = PreyFunction<wstring*(const ArkInventory* const _this, wstring* _return_value_)>(0x10D9F10);
	static inline auto FIsPrimaryInventory = PreyFunction<bool(const ArkInventory* const _this)>(0x1A302A0);
	static inline auto FPlaceItemQuietly = PreyFunction<std::pair<bool, unsigned int>*(ArkInventory* const _this, std::pair<bool, unsigned int>* _return_value_, unsigned _itemId, int _x, int _y)>(0x10DB460);
	static inline auto FRemoveItemQuietly = PreyFunction<bool(ArkInventory* const _this, unsigned _itemId)>(0x10DC3F0);
	static inline auto FPackItem = PreyFunction<bool(ArkInventory* const _this, unsigned _itemId)>(0x10DB2E0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x10DAE90);
	static inline auto FInitHelper = PreyFunction<void(ArkInventory* const _this, IGameObject* _pGameObject)>(0x10DAB90);
	static inline auto FDestructorHelper = PreyFunction<void(ArkInventory* const _this)>(0x10D9610);
	static inline auto FGetValidFreeCellLocation = PreyFunction<boost::optional<std::pair<int,int> >*(const ArkInventory* const _this, boost::optional<std::pair<int,int> >* _return_value_, int _width, int _height)>(0x10DA600);
	static inline auto FLootableSort = PreyFunction<bool(const IArkItem* _pItem1, const IArkItem* _pItem2)>(0x10DACB0);
	static inline auto FPlayAnimation = PreyFunction<void(ArkInventory* const _this, const string& _animName, const bool _bSerializing)>(0x10DB700);
};
#endif // !MOONCRASH
