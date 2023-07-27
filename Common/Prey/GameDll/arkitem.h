// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/ArkScriptTable.h>

class ArkSafeScriptTable;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum EEntityAspects;
class IArkInventory;
struct IArkItem;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkItem
// Header:  Prey/GameDll/ArkItem.h
class CArkItem : public CGameObjectExtensionHelper<CArkItem, IArkItem>, public IArkPlayerInteractionListener
{ // Size=360 (0x168)
public:
	enum class Category
	{
		none = 0,
		weapons = 1,
		consumable = 2,
		junk = 3,
		special = 4,
	};

	int m_maxRandomCount = 1;
	int m_minRandomCount = 1;
	bool m_bFabricating = false;
	int m_count = 1;
	unsigned m_ownerId = 0;
	bool m_bIsRandom = false;
	bool m_bUniqueRandom = false;
	bool m_bHideOnSerialize = false;
	bool m_bPhysicalizeStatic = false;
	bool m_bAddToInventory = false;
	int m_maxStackSize = 0;
	ArkAudioTrigger m_pickupAudioTrigger;
	uint64_t m_lootRequirement = 0;
	bool m_bFavorite = false;
	bool m_bJunk = false;
	uint64_t m_associatedEntitlement = 0;
	uint64_t m_selectedArchetype = 0;
	string m_pickupModel;
	string m_pickupMaterial;
	string m_equippedModel;
	string m_equippedMaterial;
	float m_pickupLerpSpeed = 0.0f;
	string m_inventoryDescription;
	string m_inventoryName;
	wstring m_descKeyword;
	wstring m_descKeyword2;
	int m_baseDuration = 0.0f;
	uint64_t m_consumeSignalId = 0;
	uint64_t m_consumeSignalId2 = 0;
	uint64_t m_consumeSignalPkgId = 0;
	uint64_t m_consumeInboundSignalModPkgId = 0;
	float m_signalDescScale = 1.0f;
	float m_signalDescScale2 = 0.0f;
	string m_inventoryIcon;
	string m_hudIcon;
	string m_stylizedIcon;
	int m_inventoryWidth = 1;
	int m_inventoryHeight = 1;
	CArkItem::Category m_category = Category::none;
	bool m_bStackable = false;
	string m_consumeVerb;
	float m_dropHeightOffset = 0;
	float m_dropDistance = 0;
	float m_dropRotationMin = 0;
	float m_dropRotationMax = 0;
	bool m_bIsGrenade = false;
	bool m_bIsUsable = false;
	bool m_bIsConsumable = false;
	string m_type;
	bool m_bIsUnlimited = false;
	bool m_bIsImportant = false;
	int m_dismantleCount = 0;
	bool m_bPlotCritical = false;

	CArkItem() = default;
	virtual ~CArkItem() = default;
	static CArkItem* GetItemFromEntityId(const unsigned _entityId) { return FGetItemFromEntityId(_entityId); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	virtual bool Init(IGameObject* pGameObject) { return FInit(this, pGameObject); }
	virtual void PostInit(IGameObject* pGameObject) { FPostInit(this, pGameObject); }
	virtual void InitClient(int channelId) { FInitClient(this, channelId); }
	virtual void PostInitClient(int channelId) { FPostInitClient(this, channelId); }
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params) { return FReloadExtension(this, pGameObject, params); }
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params) { FPostReloadExtension(this, pGameObject, params); }
	virtual bool GetEntityPoolSignature(TSerialize signature) { return FGetEntityPoolSignature(this, signature); }
	virtual void Release() { FRelease(this); }
	virtual void FullSerialize(TSerialize _ser) { FFullSerialize(this, _ser); }
	virtual void SerializeLTL(TSerialize _ser) { FSerializeLTL(this, _ser); }
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags) { return FNetSerialize(this, ser, aspect, profile, pflags); }
	virtual void PostSerialize() { FPostSerialize(this); }
	virtual void SerializeSpawnInfo(TSerialize ser) { FSerializeSpawnInfo(this, ser); }
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo() { alignas(_smart_ptr<ISerializableInfo>) std::byte _return_buf_[sizeof(_smart_ptr<ISerializableInfo>)]; return *FGetSpawnInfo(this, reinterpret_cast<_smart_ptr<ISerializableInfo>*>(_return_buf_)); }
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot) { FUpdate(this, _ctx, _updateSlot); }
	virtual void HandleEvent(const SGameObjectEvent& event) { FHandleEvent(this, event); }
	virtual void ProcessEvent(SEntityEvent& _event) { FProcessEvent(this, _event); }
	virtual void SetChannelId(uint16_t id) { FSetChannelId(this, id); }
	virtual void SetAuthority(bool auth) { FSetAuthority(this, auth); }
	virtual const void* GetRMIBase() const { return FGetRMIBase(this); }
	virtual void PostUpdate(float frameTime) { FPostUpdate(this, frameTime); }
	virtual void PostRemoteSpawn() { FPostRemoteSpawn(this); }
	virtual bool GiveOwner(const unsigned _pickerId) { return FGiveOwnerOv1(this, _pickerId); }
	virtual bool GiveOwner(IArkInventory* _pInventory) { return FGiveOwnerOv0(this, _pInventory); }
	virtual bool PickUp(const unsigned _pickerId, bool _bScaleOnLerp) { return FPickUp(this, _pickerId, _bScaleOnLerp); }
	virtual void Drop(int _dropCount, const Vec3* const _altPosition) { FDrop(this, _dropCount, _altPosition); }
	bool CanCollect(const IArkInventory& _inventory) const { return FCanCollect(this, _inventory); }
	virtual bool CanPlayerCollect() const { return FCanPlayerCollect(this); }
	virtual int GetCount() const { return FGetCount(this); }
	virtual wstring GetUICount() const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetUICountOv1(this, reinterpret_cast<wstring*>(_return_buf_)); }
	static wstring GetUICount(uint64_t _archetype, int _count) { return FGetUICountOv0(_archetype, _count); }
	virtual void ResetCount(int _count) { FResetCount(this, _count); }
	virtual bool IsStackFull() const { return FIsStackFull(this); }
	bool CanCombine(const CArkItem& _other) const { return FCanCombine(this, _other); }
	virtual bool Combine(IArkItem& _other, bool _bRemoveOnSuccess) { return FCombine(this, _other, _bRemoveOnSuccess); }
	void RandomizeStackCount() { FRandomizeStackCount(this); }
	virtual const char* GetType() const { return FGetType(this); }
	virtual const char* GetName() const { return FGetName(this); }
	virtual uint64_t GetArchetype() const { return FGetArchetype(this); }
	virtual wstring GetDescription() const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetDescription(this, reinterpret_cast<wstring*>(_return_buf_)); }
	virtual const char* GetIcon() const { return FGetIcon(this); }
	virtual const char* GetHUDIcon() const { return FGetHUDIcon(this); }
	const char* GetStylizedIcon() const { return FGetStylizedIcon(this); }
	virtual std::pair<int, int> GetInventoryDimensions() const { alignas(std::pair<int, int>) std::byte _return_buf_[sizeof(std::pair<int, int>)]; return *FGetInventoryDimensions(this, reinterpret_cast<std::pair<int, int>*>(_return_buf_)); }
	virtual bool IsStackable() const { return FIsStackable(this); }
	virtual int GetMaxStackSize() const { return FGetMaxStackSize(this); }
	virtual bool IsGrenade() const { return FIsGrenade(this); }
	virtual bool IsEquippable() const { return FIsEquippable(this); }
	virtual bool CanEquipFromInventory() const { return FCanEquipFromInventory(this); }
	virtual unsigned GetEquipId() const { return FGetEquipId(this); }
	void SetFavorite(bool _bFavorite) { FSetFavorite(this, _bFavorite); }
	virtual bool IsFavorite() const { return FIsFavorite(this); }
	virtual void SetTrash(bool _bTrash) { FSetTrash(this, _bTrash); }
	virtual bool IsTrash() const { return FIsTrash(this); }
	CArkItem::Category GetCategory() const { return FGetCategory(this); }
	virtual void SetLootRequirement(uint64_t _abilityId) { FSetLootRequirement(this, _abilityId); }
	virtual bool CanLoot() const { return FCanLoot(this); }
	virtual bool CanUse() const { return FCanUse(this); }
	virtual void Use() { FUse(this); }
	virtual void UseFromWorld() { FUseFromWorld(this); }
	virtual void UseFromInventory() { FUseFromInventory(this); }
	virtual void Consume(int _count) { FConsume(this, _count); }
	virtual bool CanConsume() const { return FCanConsume(this); }
	virtual bool CanConsumeFromWorld() const { return FCanConsumeFromWorld(this); }
	virtual bool IsWeapon() const { return FIsWeapon(this); }
	virtual bool IsEqual(const IArkItem& other) const { return FIsEqual(this, other); }
	virtual bool IsArchetype(const IEntityArchetype& _archetype) const { return FIsArchetypeOv1(this, _archetype); }
	virtual bool IsArchetype(const uint64_t _archetypeId) const { return FIsArchetypeOv0(this, _archetypeId); }
	virtual bool HasMetaTags(const std::vector<uint64_t>& _tags) const { return FHasMetaTags(this, _tags); }
	bool IsPlotCritical() const { return FIsPlotCritical(this); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity) { return FOnInteraction(this, _interaction, _mode, _pEntity); }
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const { return FPopulateInteractionInfo(this, _pEntity, _interactionArray); }
	bool CanPickUp() const { return FCanPickUp(this); }
	virtual unsigned GetOwnerId() const { return FGetOwnerId(this); }
	static IArkInventory* GetOwnerInventory(const unsigned _ownerId) { return FGetOwnerInventory(_ownerId); }
	virtual void OnInventoryTransfer(const IArkInventory& _source, const IArkInventory& _target) { FOnInventoryTransfer(this, _source, _target); }
	virtual wstring GetDisplayName(int _count) const { alignas(wstring) std::byte _return_buf_[sizeof(wstring)]; return *FGetDisplayName(this, reinterpret_cast<wstring*>(_return_buf_), _count); }
	uint64_t GetLootRequirement() const { return FGetLootRequirement(this); }
	void SetPhysicalizeAsStatic(bool _bStatic, bool _bPhysicalize) { FSetPhysicalizeAsStatic(this, _bStatic, _bPhysicalize); }
	CArkItem& Clone(int _count) const { return FClone(this, _count); }
	void RemoveEntity() { FRemoveEntity(this); }
	void RemoveFromInventory() { FRemoveFromInventory(this); }
	virtual IArkInventory* GetInventory(const unsigned _ownerId) const { return FGetInventory(this, _ownerId); }
	static int GetFabricationCount(IEntityArchetype* const _pArchetype) { return FGetFabricationCount(_pArchetype); }
	static string GetHudIcon(const uint64_t _archetypeId) { return FGetHudIcon(_archetypeId); }
	void NotifyPlayerAcquired(int _count) const { FNotifyPlayerAcquired(this, _count); }
	ArkSafeScriptTable GetPropertiesTable() const { alignas(ArkSafeScriptTable) std::byte _return_buf_[sizeof(ArkSafeScriptTable)]; return *FGetPropertiesTable(this, reinterpret_cast<ArkSafeScriptTable*>(_return_buf_)); }
	void SetPickupModel() { FSetPickupModel(this); }
	void Physicalize() { FPhysicalize(this); }
	virtual const char* GetPickupModel() const { return FGetPickupModel(this); }
	virtual const char* GetPickupMaterial() const { return FGetPickupMaterial(this); }
	virtual void SetupModel(bool _bFirstPerson) { FSetupModel(this, _bFirstPerson); }
	virtual void LoadCachedProperties() { FLoadCachedProperties(this); }
	static bool CanPlayerCollectArchetype(IEntityArchetype* const _pArchetype) { return FCanPlayerCollectArchetype(_pArchetype); }
	void LerpToPlayer(bool _bRemoveEntity, bool _bScale) { FLerpToPlayerOv1(this, _bRemoveEntity, _bScale); }
	void LerpToPlayer(std::function<void __cdecl(void)> _expiredCallback, bool _bDisableCollision, bool _bScale) { FLerpToPlayerOv0(this, _expiredCallback, _bDisableCollision, _bScale); }
	float CalculateModifiedSignal(uint64_t _pkgId, uint64_t _signalId, const std::vector<uint64_t>& _modifiers) const { return FCalculateModifiedSignal(this, _pkgId, _signalId, _modifiers); }
	void RemotePickUp() { FRemotePickUp(this); }
	void SelectArchetype() { FSelectArchetype(this); }
	bool TryGiveStacked(IArkInventory* _pInventory, bool _bRemoveOnSuccess) { return FTryGiveStacked(this, _pInventory, _bRemoveOnSuccess); }
	bool TryGiveInventory(IArkInventory* _pInventory) { return FTryGiveInventory(this, _pInventory); }
	Vec3 GetLerpTargetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetLerpTargetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	void OnTargetLerperExpired(const float _normalizedPitch, bool _bRemoveEntity) { FOnTargetLerperExpired(this, _normalizedPitch, _bRemoveEntity); }
	void OnLerpDrop() { FOnLerpDrop(this); }
	void OnUsedFromWorld() { FOnUsedFromWorld(this); }
	void InitializeCount() { FInitializeCount(this); }

#if 0
	void PostSerializeLTL();
	bool IsImportant() const;
	void SetFabricating(const bool _arg0_);
	bool IsFood() const;
	bool IsConsumable() const;
	string GetConsumeVerb() const;
	bool IsDeleteOnPlayerPickup() const;
	void SetOwnerId(const unsigned _arg0_);
	void SetAssociatedEntitlement(const uint64_t _arg0_);
	uint64_t GetAssociatedEntitlement() const;
	int GetDismantleCount() const;
	void SetFromProperties();
	bool CanStackAny(unsigned _arg0_) const;
	void ForcePhysicsAwake();
#endif

	static inline auto FCArkItemOv1 = PreyFunction<void(CArkItem* const _this)>(0x10AFBD0);
	static inline auto FBitNotCArkItem = PreyFunction<void(CArkItem* const _this)>(0x10AFD30);
	static inline auto FGetItemFromEntityId = PreyFunction<CArkItem * (const unsigned _entityId)>(0x10B2C90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer * pSizer)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject * pGameObject)>(0x10B3340);
	static inline auto FPostInit = PreyFunction<void(CArkItem* const _this, IGameObject * pGameObject)>(0x10B5F10);
	static inline auto FInitClient = PreyFunction<void(CArkItem* const _this, int channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkItem* const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkItem* const _this, IGameObject * pGameObject, const SEntitySpawnParams & params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkItem* const _this, IGameObject * pGameObject, const SEntitySpawnParams & params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkItem* const _this, TSerialize signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkItem* const _this)>(0x10B61C0);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x10B1BB0);
	static inline auto FSerializeLTL = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x10B67F0);
	static inline auto FNetSerialize = PreyFunction<bool(CArkItem* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkItem* const _this)>(0x10B5F60);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkItem* const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkItem* const _this, _smart_ptr<ISerializableInfo>*_return_value_)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext & _ctx, int _updateSlot)>(0x10B7120);
	static inline auto FHandleEvent = PreyFunction<void(CArkItem* const _this, const SGameObjectEvent & event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkItem* const _this, SEntityEvent & _event)>(0x10B6110);
	static inline auto FSetChannelId = PreyFunction<void(CArkItem* const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkItem* const _this, bool auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkItem* const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkItem* const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkItem* const _this)>(0xA13080);
	static inline auto FGiveOwnerOv1 = PreyFunction<bool(CArkItem* const _this, const unsigned _pickerId)>(0x10B3130);
	static inline auto FGiveOwnerOv0 = PreyFunction<bool(CArkItem* const _this, IArkInventory * _pInventory)>(0x10B31C0);
	static inline auto FPickUp = PreyFunction<bool(CArkItem* const _this, const unsigned _pickerId, bool _bScaleOnLerp)>(0x10B5A50);
	static inline auto FDrop = PreyFunction<void(CArkItem* const _this, int _dropCount, const Vec3* const _altPosition)>(0x10B0D40);
	static inline auto FCanCollect = PreyFunction<bool(const CArkItem* const _this, const IArkInventory & _inventory)>(0x10B00E0);
	static inline auto FCanPlayerCollect = PreyFunction<bool(const CArkItem* const _this)>(0x10B0450);
	static inline auto FGetCount = PreyFunction<int(const CArkItem* const _this)>(0xCECB0);
	static inline auto FGetUICountOv1 = PreyFunction<wstring * (const CArkItem* const _this, wstring * _return_value_)>(0x10B3070);
	static inline auto FGetUICountOv0 = PreyFunction<wstring(uint64_t _archetype, int _count)>(0x10B2FD0);
	static inline auto FResetCount = PreyFunction<void(CArkItem* const _this, int _count)>(0x10B6410);
	static inline auto FIsStackFull = PreyFunction<bool(const CArkItem* const _this)>(0x10B3A50);
	static inline auto FCanCombine = PreyFunction<bool(const CArkItem* const _this, const CArkItem & _other)>(0x10B02A0);
	static inline auto FCombine = PreyFunction<bool(CArkItem* const _this, IArkItem & _other, bool _bRemoveOnSuccess)>(0x10B0BD0);
	static inline auto FRandomizeStackCount = PreyFunction<void(CArkItem* const _this)>(0x10B6180);
	static inline auto FGetType = PreyFunction<const char* (const CArkItem* const _this)>(0x116D850);
	static inline auto FGetName = PreyFunction<const char* (const CArkItem* const _this)>(0x12C8A0);
	static inline auto FGetArchetype = PreyFunction<uint64_t(const CArkItem* const _this)>(0x82E930);
	static inline auto FGetDescription = PreyFunction<wstring * (const CArkItem* const _this, wstring * _return_value_)>(0x10B1DF0);
	static inline auto FGetIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x9046A0);
	static inline auto FGetHUDIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x10B2940);
	static inline auto FGetStylizedIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x10B2FB0);
	static inline auto FGetInventoryDimensions = PreyFunction<std::pair<int, int>* (const CArkItem* const _this, std::pair<int, int>* _return_value_)>(0x10B2C70);
	static inline auto FIsStackable = PreyFunction<bool(const CArkItem* const _this)>(0x10B3A70);
	static inline auto FGetMaxStackSize = PreyFunction<int(const CArkItem* const _this)>(0x1F21C0);
	static inline auto FIsGrenade = PreyFunction<bool(const CArkItem* const _this)>(0x10B3A30);
	static inline auto FIsEquippable = PreyFunction<bool(const CArkItem* const _this)>(0x10B39A0);
	static inline auto FCanEquipFromInventory = PreyFunction<bool(const CArkItem* const _this)>(0x10B03C0);
	static inline auto FGetEquipId = PreyFunction<unsigned(const CArkItem* const _this)>(0x10B2780);
	static inline auto FSetFavorite = PreyFunction<void(CArkItem* const _this, bool _bFavorite)>(0x10B6970);
	static inline auto FIsFavorite = PreyFunction<bool(const CArkItem* const _this)>(0x10B39E0);
	static inline auto FSetTrash = PreyFunction<void(CArkItem* const _this, bool _bTrash)>(0x10B6AC0);
	static inline auto FIsTrash = PreyFunction<bool(const CArkItem* const _this)>(0x10B3A80);
	static inline auto FGetCategory = PreyFunction<CArkItem::Category(const CArkItem* const _this)>(0x10B1DB0);
	static inline auto FSetLootRequirement = PreyFunction<void(CArkItem* const _this, uint64_t _abilityId)>(0x10B69D0);
	static inline auto FCanLoot = PreyFunction<bool(const CArkItem* const _this)>(0x10B03D0);
	static inline auto FCanUse = PreyFunction<bool(const CArkItem* const _this)>(0x10B0840);
	static inline auto FUse = PreyFunction<void(CArkItem* const _this)>(0x10B7260);
	static inline auto FUseFromWorld = PreyFunction<void(CArkItem* const _this)>(0x10B7410);
	static inline auto FUseFromInventory = PreyFunction<void(CArkItem* const _this)>(0x10B7280);
	static inline auto FConsume = PreyFunction<void(CArkItem* const _this, int _count)>(0x10B0C80);
	static inline auto FCanConsume = PreyFunction<bool(const CArkItem* const _this)>(0x10B0350);
	static inline auto FCanConsumeFromWorld = PreyFunction<bool(const CArkItem* const _this)>(0x10B0380);
	static inline auto FIsWeapon = PreyFunction<bool(const CArkItem* const _this)>(0xDD23F0);
	static inline auto FIsEqual = PreyFunction<bool(const CArkItem* const _this, const IArkItem & other)>(0x10B3920);
	static inline auto FIsArchetypeOv1 = PreyFunction<bool(const CArkItem* const _this, const IEntityArchetype & _archetype)>(0x10B38E0);
	static inline auto FIsArchetypeOv0 = PreyFunction<bool(const CArkItem* const _this, const uint64_t _archetypeId)>(0x10B3910);
	static inline auto FHasMetaTags = PreyFunction<bool(const CArkItem* const _this, const std::vector<uint64_t>&_tags)>(0x10B3320);
	static inline auto FIsPlotCritical = PreyFunction<bool(const CArkItem* const _this)>(0x10B3A40);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x10B5000);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>&_interactionArray)>(0x10B5DE0);
	static inline auto FCanPickUp = PreyFunction<bool(const CArkItem* const _this)>(0x10B0410);
	static inline auto FGetOwnerId = PreyFunction<unsigned(const CArkItem* const _this)>(0x9921B0);
	static inline auto FGetOwnerInventory = PreyFunction<IArkInventory * (const unsigned _ownerId)>(0x10B2EF0);
	static inline auto FOnInventoryTransfer = PreyFunction<void(CArkItem* const _this, const IArkInventory & _source, const IArkInventory & _target)>(0x10B5160);
	static inline auto FGetDisplayName = PreyFunction<wstring * (const CArkItem* const _this, wstring * _return_value_, int _count)>(0x10B25D0);
	static inline auto FGetLootRequirement = PreyFunction<uint64_t(const CArkItem* const _this)>(0xE70280);
	static inline auto FSetPhysicalizeAsStatic = PreyFunction<void(CArkItem* const _this, bool _bStatic, bool _bPhysicalize)>(0x10B69E0);
	static inline auto FClone = PreyFunction<CArkItem & (const CArkItem* const _this, int _count)>(0x10B09A0);
	static inline auto FRemoveEntity = PreyFunction<void(CArkItem* const _this)>(0x10B6300);
	static inline auto FRemoveFromInventory = PreyFunction<void(CArkItem* const _this)>(0x10B6360);
	static inline auto FGetInventory = PreyFunction<IArkInventory * (const CArkItem* const _this, const unsigned _ownerId)>(0x10B2BB0);
	static inline auto FGetFabricationCount = PreyFunction<int(IEntityArchetype* const _pArchetype)>(0x10B27E0);
	static inline auto FGetHudIcon = PreyFunction<string(const uint64_t _archetypeId)>(0x10B2960);
	static inline auto FNotifyPlayerAcquired = PreyFunction<void(const CArkItem* const _this, int _count)>(0x10B4E10);
	static inline auto FGetPropertiesTable = PreyFunction<ArkSafeScriptTable * (const CArkItem* const _this, ArkSafeScriptTable * _return_value_)>(0x1646210);
	static inline auto FSetPickupModel = PreyFunction<void(CArkItem* const _this)>(0x10B6A00);
	static inline auto FPhysicalize = PreyFunction<void(CArkItem* const _this)>(0x10B56D0);
	static inline auto FGetPickupModel = PreyFunction<const char* (const CArkItem* const _this)>(0x155AD30);
	static inline auto FGetPickupMaterial = PreyFunction<const char* (const CArkItem* const _this)>(0x24DDE0);
	static inline auto FSetupModel = PreyFunction<void(CArkItem* const _this, bool _bFirstPerson)>(0x10B6AD0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x10B3D20);
	static inline auto FCanPlayerCollectArchetype = PreyFunction<bool(IEntityArchetype* const _pArchetype)>(0x10B0490);
	static inline auto FLerpToPlayerOv1 = PreyFunction<void(CArkItem* const _this, bool _bRemoveEntity, bool _bScale)>(0x10B3C60);
	static inline auto FLerpToPlayerOv0 = PreyFunction<void(CArkItem* const _this, std::function<void __cdecl(void)> _expiredCallback, bool _bDisableCollision, bool _bScale)>(0x10B3A90);
	static inline auto FCalculateModifiedSignal = PreyFunction<float(const CArkItem* const _this, uint64_t _pkgId, uint64_t _signalId, const std::vector<uint64_t>&_modifiers)>(0x10AFF50);
	static inline auto FRemotePickUp = PreyFunction<void(CArkItem* const _this)>(0x10B6230);
	static inline auto FSelectArchetype = PreyFunction<void(CArkItem* const _this)>(0x10B64F0);
	static inline auto FTryGiveStacked = PreyFunction<bool(CArkItem* const _this, IArkInventory * _pInventory, bool _bRemoveOnSuccess)>(0x10B6E50);
	static inline auto FTryGiveInventory = PreyFunction<bool(CArkItem* const _this, IArkInventory * _pInventory)>(0x10B6DB0);
	static inline auto FGetLerpTargetPosition = PreyFunction<Vec3 * (const CArkItem* const _this, Vec3 * _return_value_)>(0x10B2CC0);
	static inline auto FOnTargetLerperExpired = PreyFunction<void(CArkItem* const _this, const float _normalizedPitch, bool _bRemoveEntity)>(0x10B54B0);
	static inline auto FOnLerpDrop = PreyFunction<void(CArkItem* const _this)>(0x10B5480);
	static inline auto FOnUsedFromWorld = PreyFunction<void(CArkItem* const _this)>(0x10B5540);
	static inline auto FInitializeCount = PreyFunction<void(CArkItem* const _this)>(0x10B3600);
};
