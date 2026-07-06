// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <_unknown/CGameObjectExtensionHelper.h>

class ArkInventory;
class ArkSafeScriptTable;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum EEntityAspects;
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
{ // Size=384 (0x180)
public:
	enum class Category
	{
		none = 0,
		weapons = 1,
		consumable = 2,
		junk = 3,
		special = 4,
	};

	int m_maxRandomCount;
	int m_minRandomCount;
	bool m_bFabricating;
	IArkItem::EArkQualityTier m_quality;
	int m_count;
	int m_startingCount;
	unsigned m_ownerId;
	bool m_bHideOnSerialize;
	bool m_bPhysicalizeStatic;
	bool m_bPhysicsAwake;
	bool m_bAddToInventory;
	int m_maxStackSize;
	ArkAudioTrigger m_pickupAudioTrigger;
	uint64_t m_lootRequirement;
	bool m_bFavorite;
	bool m_bJunk;
	uint64_t m_associatedEntitlement;
	uint64_t m_selectedArchetype;
	string m_pickupModel;
	string m_pickupMaterial;
	string m_equippedModel;
	string m_equippedMaterial;
	float m_pickupLerpSpeed;
	string m_inventoryDescription;
	string m_inventoryDescriptionAdditional;
	string m_inventoryName;
	wstring m_descKeyword;
	wstring m_descKeyword2;
	int m_baseDuration;
	uint64_t m_consumeSignalId;
	uint64_t m_consumeSignalId2;
	uint64_t m_consumeSignalPkgId;
	uint64_t m_consumeInboundSignalModPkgId;
	float m_signalDescScale;
	float m_signalDescScale2;
	string m_inventoryIcon;
	string m_hudIcon;
	string m_stylizedIcon;
	int m_inventoryWidth;
	int m_inventoryHeight;
	CArkItem::Category m_category;
	bool m_bStackable;
	string m_consumeVerb;
	float m_dropHeightOffset;
	float m_dropDistance;
	float m_dropRotationMin;
	float m_dropRotationMax;
	bool m_bIsGrenade;
	bool m_bIsUsable;
	bool m_bIsConsumable;
	string m_type;
	bool m_bIsUnlimited;
	bool m_bIsImportant;
	bool m_bRandomizeQuality;
	bool m_bRandomizeBasedOnFabPlans;
	bool m_bLockQuality;
	int m_dismantleCount;
	bool m_bPlotCritical;
	uint64_t m_randomSeed;
	EArkPsiPowers m_psiPower;

	CArkItem();
	virtual ~CArkItem();
	static CArkItem* GetItemFromEntityId(const unsigned _entityId) { return FGetItemFromEntityId(_entityId); }
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual bool Init(IGameObject* pGameObject);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void SerializeLTL(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual const void* GetRMIBase() const;
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual bool GiveOwner(const unsigned _pickerId);
	virtual bool GiveOwner(ArkInventory* _pInventory);
	virtual bool PickUp(const unsigned _pickerId, bool _bScaleOnLerp);
	virtual IEntity* Drop(int _dropCount, const Vec3* const _altPosition);
	bool CanCollect(const ArkInventory& _inventory) const { return FCanCollect(this, _inventory); }
	virtual bool CanPlayerCollect() const;
	virtual int GetCount() const;
	virtual wstring GetUICount() const;
	static wstring GetUICount(uint64_t _archetype, int _count) { return FGetUICountOv0(_archetype, _count); }
	virtual void ResetCount(int _count);
	virtual bool IsStackFull() const;
	bool CanCombine(const CArkItem& _other) const { return FCanCombine(this, _other); }
	virtual bool Combine(IArkItem& _other, bool _bRemoveOnSuccess);
	void RandomizeStackCount(int _min, int _max) { FRandomizeStackCount(this, _min, _max); }
	virtual const char* GetType() const;
	virtual const char* GetName() const;
	virtual uint64_t GetArchetype() const;
	virtual wstring GetDescription() const;
	virtual const char* GetIcon() const;
	virtual const char* GetHUDIcon() const;
	const char* GetStylizedIcon() const { return FGetStylizedIcon(this); }
	virtual std::pair<int, int> GetInventoryDimensions() const;
	virtual bool IsStackable() const;
	virtual int GetMaxStackSize() const;
	virtual bool IsGrenade() const;
	virtual bool IsEquippable() const;
	virtual bool CanEquipFromInventory() const;
	virtual unsigned GetEquipId() const;
	void SetFavorite(bool _bFavorite) { FSetFavorite(this, _bFavorite); }
	virtual bool IsFavorite() const;
	virtual void SetTrash(bool _bTrash);
	virtual bool IsTrash() const;
	CArkItem::Category GetCategory() const { return FGetCategory(this); }
	virtual void SetLootRequirement(uint64_t _abilityId);
	virtual bool CanLoot() const;
	virtual bool CanUse() const;
	virtual bool CanDismiss() const;
	virtual void Use();
	virtual void UseFromWorld();
	virtual void UseFromInventory();
	virtual void Consume(int _count);
	virtual bool CanConsume() const;
	virtual bool CanConsumeFromWorld() const;
	virtual bool IsWeapon() const;
	virtual bool IsEqual(const IArkItem& other) const;
	virtual bool IsArchetype(const IEntityArchetype& _archetype) const;
	virtual bool IsArchetype(const uint64_t _archetypeId) const;
	virtual bool HasMetaTags(const std::vector<uint64_t>& _tags) const;
	virtual bool HasSpawnedPet() const;
	bool IsPlotCritical() const { return FIsPlotCritical(this); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	bool CanPickUp() const { return FCanPickUp(this); }
	virtual unsigned GetOwnerId() const;
	static ArkInventory* GetOwnerInventory(const unsigned _ownerId) { return FGetOwnerInventory(_ownerId); }
	virtual void OnInventoryTransfer(const ArkInventory& _source, const ArkInventory& _target);
	virtual wstring GetDisplayName(int _count) const;
	uint64_t GetLootRequirement() const { return FGetLootRequirement(this); }
	void SetPhysicalizeAsStatic(bool _bStatic, bool _bPhysicalize) { FSetPhysicalizeAsStatic(this, _bStatic, _bPhysicalize); }
	CArkItem& Clone(int _count) const { return FClone(this, _count); }
	void RemoveEntity() { FRemoveEntity(this); }
	void RemoveFromInventory() { FRemoveFromInventory(this); }
	virtual ArkInventory* GetInventory(const unsigned _ownerId) const;
	static int GetFabricationCount(IEntityArchetype* const _pArchetype) { return FGetFabricationCount(_pArchetype); }
	static string GetHudIcon(const uint64_t _archetypeId) { return FGetHudIcon(_archetypeId); }
	static bool CanCollectArchetype(IEntityArchetype* const _pArchetype, const ArkInventory& _inventory) { return FCanCollectArchetype(_pArchetype, _inventory); }
	void NotifyPlayerAcquired(int _count) const { FNotifyPlayerAcquired(this, _count); }
	void RandomizeQualityTier() { FRandomizeQualityTier(this); }
	virtual void SetQualityTier(IArkItem::EArkQualityTier _tier);
	virtual bool CanSetQualityTier() const;
	void UpdateMaterial(bool _bFirstPerson) { FUpdateMaterialOv1(this, _bFirstPerson); }
	void UpdateMaterial(bool _bFirstPerson, bool _bIsCharacter) { FUpdateMaterialOv0(this, _bFirstPerson, _bIsCharacter); }
	static wstring GetQualityName(IArkItem::EArkQualityTier _qualityTier) { return FGetQualityName(_qualityTier); }
	void Physicalize() { FPhysicalize(this); }
	ArkSafeScriptTable GetPropertiesTable() const { alignas(ArkSafeScriptTable) std::byte _return_buf_[sizeof(ArkSafeScriptTable)]; return *FGetPropertiesTable(this, reinterpret_cast<ArkSafeScriptTable*>(_return_buf_)); }
	void SetFromProperties() { FSetFromProperties(this); }
	void SetPickupModel() { FSetPickupModel(this); }
	virtual const char* GetPickupModel() const;
	virtual const char* GetPickupMaterial() const;
	virtual const char* GetEquippedMaterial() const;
	virtual void SetupModel(bool _bFirstPerson);
	virtual void LoadCachedProperties();
	static bool CanPlayerCollectArchetype(IEntityArchetype* const _pArchetype) { return FCanPlayerCollectArchetype(_pArchetype); }
	void LerpToPlayer(bool _bRemoveEntity, bool _bScale) { FLerpToPlayerOv1(this, _bRemoveEntity, _bScale); }
	void LerpToPlayer(std::function<void __cdecl(void)> _expiredCallback, bool _bDisableCollision, bool _bScale) { FLerpToPlayerOv0(this, _expiredCallback, _bDisableCollision, _bScale); }
	float CalculateModifiedSignal(uint64_t _pkgId, uint64_t _signalId, const std::vector<uint64_t>& _modifiers) const { return FCalculateModifiedSignal(this, _pkgId, _signalId, _modifiers); }
	void RemotePickUp() { FRemotePickUp(this); }
	bool CanStackAny(const ArkInventory& _inventory) const { return FCanStackAnyOv0(this, _inventory); }
	bool TryGiveStacked(ArkInventory* _pInventory, bool _bRemoveOnSuccess) { return FTryGiveStacked(this, _pInventory, _bRemoveOnSuccess); }
	bool TryGiveInventory(ArkInventory* _pInventory) { return FTryGiveInventory(this, _pInventory); }
	Vec3 GetLerpTargetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetLerpTargetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	void OnTargetLerperExpired(const float _normalizedPitch, bool _bRemoveEntity) { FOnTargetLerperExpired(this, _normalizedPitch, _bRemoveEntity); }
	void OnLerpDrop() { FOnLerpDrop(this); }
	void OnUsedFromWorld() { FOnUsedFromWorld(this); }
	void InitializeCount() { FInitializeCount(this); }

#if 0
	void PostSerializeLTL();
	static std::pair<int, int> GetInventoryDimensions(uint64_t _arg0_);
	static std::pair<int, int> GetInventoryDimensions(unsigned _arg0_);
	bool IsImportant() const;
	void SetFabricating(const bool _arg0_);
	bool IsFood() const;
	bool IsConsumable() const;
	string GetConsumeVerb() const;
	int GetStartingCount() const;
	void SetStartingCount(int _arg0_);
	bool IsDeleteOnPlayerPickup() const;
	void SetOwnerId(const unsigned _arg0_);
	bool GetPhysicalizeAsStatic() const;
	void SetPhysicsAwake(bool _arg0_);
	void SetAssociatedEntitlement(const uint64_t _arg0_);
	uint64_t GetAssociatedEntitlement() const;
	int GetDismantleCount() const;
	bool IsQualityTierLocked() const;
	IArkItem::EArkQualityTier GetQualityTier() const;
	void SetSeed(uint64_t _arg0_);
	uint64_t GetSeed() const;
	bool CanStackAny(unsigned _arg0_) const;
	void ForcePhysicsAwake();
#endif

	static inline auto FCArkItemOv1 = PreyFunction<void(CArkItem* const _this)>(0x10DE050);
	static inline auto FBitNotCArkItem = PreyFunction<void(CArkItem* const _this)>(0x10DE1E0);
	static inline auto FGetItemFromEntityId = PreyFunction<CArkItem* (const unsigned _entityId)>(0x10E1530);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkItem* const _this, ICrySizer* pSizer)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CArkItem* const _this, IGameObject* pGameObject)>(0x10E1E20);
	static inline auto FPostInit = PreyFunction<void(CArkItem* const _this, IGameObject* pGameObject)>(0x10E4E30);
	static inline auto FInitClient = PreyFunction<void(CArkItem* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkItem* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkItem* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkItem* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkItem* const _this, TSerialize signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkItem* const _this)>(0x10E51D0);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x10E0340);
	static inline auto FSerializeLTL = PreyFunction<void(CArkItem* const _this, TSerialize _ser)>(0x10E56E0);
	static inline auto FNetSerialize = PreyFunction<bool(CArkItem* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags)>(0x13B0900);
	static inline auto FPostSerialize = PreyFunction<void(CArkItem* const _this)>(0x10E4EA0);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkItem* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkItem* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkItem* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x10E5F90);
	static inline auto FHandleEvent = PreyFunction<void(CArkItem* const _this, const SGameObjectEvent& event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkItem* const _this, SEntityEvent& _event)>(0x10E5040);
	static inline auto FSetChannelId = PreyFunction<void(CArkItem* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkItem* const _this, bool auth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkItem* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(CArkItem* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkItem* const _this)>(0x1333E90);
	static inline auto FGiveOwnerOv1 = PreyFunction<bool(CArkItem* const _this, const unsigned _pickerId)>(0x10E1A70);
	static inline auto FGiveOwnerOv0 = PreyFunction<bool(CArkItem* const _this, ArkInventory* _pInventory)>(0x10E1B00);
	static inline auto FPickUp = PreyFunction<bool(CArkItem* const _this, const unsigned _pickerId, bool _bScaleOnLerp)>(0x10E4970);
	static inline auto FDrop = PreyFunction<IEntity* (CArkItem* const _this, int _dropCount, const Vec3* const _altPosition)>(0x10DF4D0);
	static inline auto FCanCollect = PreyFunction<bool(const CArkItem* const _this, const ArkInventory& _inventory)>(0x10DE5E0);
	static inline auto FCanPlayerCollect = PreyFunction<bool(const CArkItem* const _this)>(0x10DED00);
	static inline auto FGetCount = PreyFunction<int(const CArkItem* const _this)>(0x10E05B0);
	static inline auto FGetUICountOv1 = PreyFunction<wstring*(const CArkItem* const _this, wstring* _return_value_)>(0x10E19B0);
	static inline auto FGetUICountOv0 = PreyFunction<wstring(uint64_t _archetype, int _count)>(0x10E1910);
	static inline auto FResetCount = PreyFunction<void(CArkItem* const _this, int _count)>(0x10E5600);
	static inline auto FIsStackFull = PreyFunction<bool(const CArkItem* const _this)>(0x10E25A0);
	static inline auto FCanCombine = PreyFunction<bool(const CArkItem* const _this, const CArkItem& _other)>(0x10DE9D0);
	static inline auto FCombine = PreyFunction<bool(CArkItem* const _this, IArkItem& _other, bool _bRemoveOnSuccess)>(0x10DF340);
	static inline auto FRandomizeStackCount = PreyFunction<void(CArkItem* const _this, int _min, int _max)>(0x10E5180);
	static inline auto FGetType = PreyFunction<const char* (const CArkItem* const _this)>(0x5D8F00);
	static inline auto FGetName = PreyFunction<const char* (const CArkItem* const _this)>(0x11E6C10);
	static inline auto FGetArchetype = PreyFunction<uint64_t(const CArkItem* const _this)>(0x11E6CB0);
	static inline auto FGetDescription = PreyFunction<wstring*(const CArkItem* const _this, wstring* _return_value_)>(0x10E05C0);
	static inline auto FGetIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x5D8F30);
	static inline auto FGetHUDIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x10E11F0);
	static inline auto FGetStylizedIcon = PreyFunction<const char* (const CArkItem* const _this)>(0x10E18F0);
	static inline auto FGetInventoryDimensionsOv2 = PreyFunction<std::pair<int, int>*(const CArkItem* const _this, std::pair<int, int>* _return_value_)>(0x10E1510);
	static inline auto FIsStackable = PreyFunction<bool(const CArkItem* const _this)>(0x10E25C0);
	static inline auto FGetMaxStackSize = PreyFunction<int(const CArkItem* const _this)>(0xA55490);
	static inline auto FIsGrenade = PreyFunction<bool(const CArkItem* const _this)>(0x10E2580);
	static inline auto FIsEquippable = PreyFunction<bool(const CArkItem* const _this)>(0x10E24F0);
	static inline auto FCanEquipFromInventory = PreyFunction<bool(const CArkItem* const _this)>(0x10DEC60);
	static inline auto FGetEquipId = PreyFunction<unsigned(const CArkItem* const _this)>(0x10E1030);
	static inline auto FSetFavorite = PreyFunction<void(CArkItem* const _this, bool _bFavorite)>(0x10E5860);
	static inline auto FIsFavorite = PreyFunction<bool(const CArkItem* const _this)>(0x10E2530);
	static inline auto FSetTrash = PreyFunction<void(CArkItem* const _this, bool _bTrash)>(0x10E59D0);
	static inline auto FIsTrash = PreyFunction<bool(const CArkItem* const _this)>(0x9EDA10);
	static inline auto FGetCategory = PreyFunction<CArkItem::Category(const CArkItem* const _this)>(0x10E0570);
	static inline auto FSetLootRequirement = PreyFunction<void(CArkItem* const _this, uint64_t _abilityId)>(0x10E58D0);
	static inline auto FCanLoot = PreyFunction<bool(const CArkItem* const _this)>(0x10DEC70);
	static inline auto FCanUse = PreyFunction<bool(const CArkItem* const _this)>(0x10DEFA0);
	static inline auto FCanDismiss = PreyFunction<bool(const CArkItem* const _this)>(0x10DEAF0);
	static inline auto FUse = PreyFunction<void(CArkItem* const _this)>(0x10E62E0);
	static inline auto FUseFromWorld = PreyFunction<void(CArkItem* const _this)>(0x10E6490);
	static inline auto FUseFromInventory = PreyFunction<void(CArkItem* const _this)>(0x10E6300);
	static inline auto FConsume = PreyFunction<void(CArkItem* const _this, int _count)>(0x10DF410);
	static inline auto FCanConsume = PreyFunction<bool(const CArkItem* const _this)>(0x10DEA80);
	static inline auto FCanConsumeFromWorld = PreyFunction<bool(const CArkItem* const _this)>(0x10DEAB0);
	static inline auto FIsWeapon = PreyFunction<bool(const CArkItem* const _this)>(0x13B0900);
	static inline auto FIsEqual = PreyFunction<bool(const CArkItem* const _this, const IArkItem& other)>(0x10E2470);
	static inline auto FIsArchetypeOv1 = PreyFunction<bool(const CArkItem* const _this, const IEntityArchetype& _archetype)>(0x10E2430);
	static inline auto FIsArchetypeOv0 = PreyFunction<bool(const CArkItem* const _this, const uint64_t _archetypeId)>(0x10E2460);
	static inline auto FHasMetaTags = PreyFunction<bool(const CArkItem* const _this, const std::vector<uint64_t>& _tags)>(0x10E1DB0);
	static inline auto FHasSpawnedPet = PreyFunction<bool(const CArkItem* const _this)>(0x10E1DD0);
	static inline auto FIsPlotCritical = PreyFunction<bool(const CArkItem* const _this)>(0x10E2590);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x10E3DA0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x10E4D00);
	static inline auto FCanPickUp = PreyFunction<bool(const CArkItem* const _this)>(0x10DECC0);
	static inline auto FGetOwnerId = PreyFunction<unsigned(const CArkItem* const _this)>(0x10E1790);
	static inline auto FGetOwnerInventory = PreyFunction<ArkInventory* (const unsigned _ownerId)>(0x10E17A0);
	static inline auto FOnInventoryTransfer = PreyFunction<void(CArkItem* const _this, const ArkInventory& _source, const ArkInventory& _target)>(0x10E3F20);
	static inline auto FGetDisplayName = PreyFunction<wstring*(const CArkItem* const _this, wstring* _return_value_, int _count)>(0x10E0DE0);
	static inline auto FGetLootRequirement = PreyFunction<uint64_t(const CArkItem* const _this)>(0xB48DC0);
	static inline auto FSetPhysicalizeAsStatic = PreyFunction<void(CArkItem* const _this, bool _bStatic, bool _bPhysicalize)>(0x10E58E0);
	static inline auto FClone = PreyFunction<CArkItem& (const CArkItem* const _this, int _count)>(0x10DF100);
	static inline auto FRemoveEntity = PreyFunction<void(CArkItem* const _this)>(0x10E5310);
	static inline auto FRemoveFromInventory = PreyFunction<void(CArkItem* const _this)>(0x10E5370);
	static inline auto FGetInventory = PreyFunction<ArkInventory* (const CArkItem* const _this, const unsigned _ownerId)>(0x10E1460);
	static inline auto FGetFabricationCount = PreyFunction<int(IEntityArchetype* const _pArchetype)>(0x10E1090);
	static inline auto FGetHudIcon = PreyFunction<string(const uint64_t _archetypeId)>(0x10E1210);
	static inline auto FCanCollectArchetype = PreyFunction<bool(IEntityArchetype* const _pArchetype, const ArkInventory& _inventory)>(0x10DE630);
	static inline auto FNotifyPlayerAcquired = PreyFunction<void(const CArkItem* const _this, int _count)>(0x10E3AB0);
	static inline auto FRandomizeQualityTier = PreyFunction<void(CArkItem* const _this)>(0x10E5080);
	static inline auto FSetQualityTier = PreyFunction<void(CArkItem* const _this, IArkItem::EArkQualityTier _tier)>(0x10E59C0);
	static inline auto FCanSetQualityTier = PreyFunction<bool(const CArkItem* const _this)>(0x10DEDA0);
	static inline auto FUpdateMaterialOv1 = PreyFunction<void(CArkItem* const _this, bool _bFirstPerson)>(0x10E6200);
	static inline auto FUpdateMaterialOv0 = PreyFunction<void(CArkItem* const _this, bool _bFirstPerson, bool _bIsCharacter)>(0x10E60F0);
	static inline auto FGetQualityName = PreyFunction<wstring(IArkItem::EArkQualityTier _qualityTier)>(0x10E1870);
	static inline auto FPhysicalize = PreyFunction<void(CArkItem* const _this)>(0x10E4540);
	static inline auto FGetPropertiesTable = PreyFunction<ArkSafeScriptTable*(const CArkItem* const _this, ArkSafeScriptTable* _return_value_)>(0x10E1850);
	static inline auto FSetFromProperties = PreyFunction<void(CArkItem* const _this)>(0x10E58C0);
	static inline auto FSetPickupModel = PreyFunction<void(CArkItem* const _this)>(0x10E5900);
	static inline auto FGetPickupModel = PreyFunction<const char* (const CArkItem* const _this)>(0x5105A0);
	static inline auto FGetPickupMaterial = PreyFunction<const char* (const CArkItem* const _this)>(0x1B7C8C0);
	static inline auto FGetEquippedMaterial = PreyFunction<const char* (const CArkItem* const _this)>(0xAB5630);
	static inline auto FSetupModel = PreyFunction<void(CArkItem* const _this, bool _bFirstPerson)>(0x10E59E0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem* const _this)>(0x10E28A0);
	static inline auto FCanPlayerCollectArchetype = PreyFunction<bool(IEntityArchetype* const _pArchetype)>(0x10DED70);
	static inline auto FLerpToPlayerOv1 = PreyFunction<void(CArkItem* const _this, bool _bRemoveEntity, bool _bScale)>(0x10E27A0);
	static inline auto FLerpToPlayerOv0 = PreyFunction<void(CArkItem* const _this, std::function<void __cdecl(void)> _expiredCallback, bool _bDisableCollision, bool _bScale)>(0x10E25D0);
	static inline auto FCalculateModifiedSignal = PreyFunction<float(const CArkItem* const _this, uint64_t _pkgId, uint64_t _signalId, const std::vector<uint64_t>& _modifiers)>(0x10DE420);
	static inline auto FRemotePickUp = PreyFunction<void(CArkItem* const _this)>(0x10E5240);
	static inline auto FCanStackAnyOv0 = PreyFunction<bool(const CArkItem* const _this, const ArkInventory& _inventory)>(0x10DEE30);
	static inline auto FTryGiveStacked = PreyFunction<bool(CArkItem* const _this, ArkInventory* _pInventory, bool _bRemoveOnSuccess)>(0x10E5CC0);
	static inline auto FTryGiveInventory = PreyFunction<bool(CArkItem* const _this, ArkInventory* _pInventory)>(0x10E5C10);
	static inline auto FGetLerpTargetPosition = PreyFunction<Vec3*(const CArkItem* const _this, Vec3* _return_value_)>(0x10E1560);
	static inline auto FOnTargetLerperExpired = PreyFunction<void(CArkItem* const _this, const float _normalizedPitch, bool _bRemoveEntity)>(0x10E4320);
	static inline auto FOnLerpDrop = PreyFunction<void(CArkItem* const _this)>(0x10E42F0);
	static inline auto FOnUsedFromWorld = PreyFunction<void(CArkItem* const _this)>(0x10E43B0);
	static inline auto FInitializeCount = PreyFunction<void(CArkItem* const _this)>(0x10E2130);
};
#endif // !MOONCRASH
