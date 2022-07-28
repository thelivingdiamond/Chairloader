// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkscripttable.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>

class IArkInventory;
struct IArkItem;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/arkitem.h
class CArkItem : public CGameObjectExtensionHelper<CArkItem,IArkItem>, public IArkPlayerInteractionListener // Id=8015F12 Size=360
{
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
	int m_count;
	unsigned m_ownerId;
	bool m_bIsRandom;
	bool m_bUniqueRandom;
	bool m_bHideOnSerialize;
	bool m_bPhysicalizeStatic;
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
	int m_dismantleCount;
	bool m_bPlotCritical;
	
	CArkItem();
	virtual ~CArkItem();
	static CArkItem *GetItemFromEntityId(const unsigned _entityId) { return FGetItemFromEntityId(_entityId); }
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	virtual bool Init(IGameObject *pGameObject);
	virtual void PostInit(IGameObject *pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual void PostReloadExtension(IGameObject *pGameObject, SEntitySpawnParams const &params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void SerializeLTL(TSerialize _ser);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void HandleEvent(SGameObjectEvent const &event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual const void *GetRMIBase() const;
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual bool GiveOwner(const unsigned _pickerId);
	virtual bool GiveOwner(IArkInventory *_pInventory);
	virtual bool PickUp(const unsigned _pickerId, bool _bScaleOnLerp);
	virtual void Drop(int _dropCount, Vec3 const *const _altPosition);
	bool CanCollect(IArkInventory const &_inventory) const { return FCanCollect(this,_inventory); }
	virtual bool CanPlayerCollect() const;
	virtual int GetCount() const;
	virtual wstring GetUICount() const;
	static wstring GetUICount(uint64_t _archetype, int _count) { return FGetUICountOv0(_archetype,_count); }
	virtual void ResetCount(int _count);
	virtual bool IsStackFull() const;
	bool CanCombine(CArkItem const &_other) const { return FCanCombine(this,_other); }
	virtual bool Combine(IArkItem &_other, bool _bRemoveOnSuccess);
	void RandomizeStackCount() { FRandomizeStackCount(this); }
	virtual const char *GetType() const;
	virtual const char *GetName() const;
	virtual uint64_t GetArchetype() const;
	virtual wstring GetDescription() const;
	virtual const char *GetIcon() const;
	virtual const char *GetHUDIcon() const;
	const char *GetStylizedIcon() const { return FGetStylizedIcon(this); }
	virtual std::pair<int,int> GetInventoryDimensions() const;
	virtual bool IsStackable() const;
	virtual int GetMaxStackSize() const;
	virtual bool IsGrenade() const;
	virtual bool IsEquippable() const;
	virtual bool CanEquipFromInventory() const;
	virtual unsigned GetEquipId() const;
	void SetFavorite(bool _bFavorite) { FSetFavorite(this,_bFavorite); }
	virtual bool IsFavorite() const;
	virtual void SetTrash(bool _bTrash);
	virtual bool IsTrash() const;
	CArkItem::Category GetCategory() const { return FGetCategory(this); }
	virtual void SetLootRequirement(uint64_t _abilityId);
	virtual bool CanLoot() const;
	virtual bool CanUse() const;
	virtual void Use();
	virtual void UseFromWorld();
	virtual void UseFromInventory();
	virtual void Consume(int _count);
	virtual bool CanConsume() const;
	virtual bool CanConsumeFromWorld() const;
	virtual bool IsWeapon() const;
	virtual bool IsEqual(IArkItem const &other) const;
	virtual bool IsArchetype(IEntityArchetype const &_archetype) const;
	virtual bool IsArchetype(const uint64_t _archetypeId) const;
	virtual bool HasMetaTags(std::vector<unsigned __int64> const &_tags) const;
	bool IsPlotCritical() const { return FIsPlotCritical(this); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	bool CanPickUp() const { return FCanPickUp(this); }
	virtual unsigned GetOwnerId() const;
	static IArkInventory *GetOwnerInventory(const unsigned _ownerId) { return FGetOwnerInventory(_ownerId); }
	virtual void OnInventoryTransfer(IArkInventory const &_source, IArkInventory const &_target);
	virtual wstring GetDisplayName(int _count) const;
	uint64_t GetLootRequirement() const { return FGetLootRequirement(this); }
	void SetPhysicalizeAsStatic(bool _bStatic, bool _bPhysicalize) { FSetPhysicalizeAsStatic(this,_bStatic,_bPhysicalize); }
	CArkItem &Clone(int _count) const { return FClone(this,_count); }
	void RemoveEntity() { FRemoveEntity(this); }
	void RemoveFromInventory() { FRemoveFromInventory(this); }
	virtual IArkInventory *GetInventory(const unsigned _ownerId) const;
	static int GetFabricationCount(IEntityArchetype *const _pArchetype) { return FGetFabricationCount(_pArchetype); }
	static string GetHudIcon(const uint64_t _archetypeId) { return FGetHudIcon(_archetypeId); }
	void NotifyPlayerAcquired(int _count) const { FNotifyPlayerAcquired(this,_count); }
	ArkSafeScriptTable GetPropertiesTable() const { return FGetPropertiesTable(this); }
	void SetPickupModel() { FSetPickupModel(this); }
	void Physicalize() { FPhysicalize(this); }
	virtual const char *GetPickupModel() const;
	virtual const char *GetPickupMaterial() const;
	virtual void SetupModel(bool _bFirstPerson);
	virtual void LoadCachedProperties();
	static bool CanPlayerCollectArchetype(IEntityArchetype *const _pArchetype) { return FCanPlayerCollectArchetype(_pArchetype); }
	void LerpToPlayer(bool _bRemoveEntity, bool _bScale) { FLerpToPlayerOv1(this,_bRemoveEntity,_bScale); }
	void LerpToPlayer(std::function<void __cdecl(void)> _expiredCallback, bool _bDisableCollision, bool _bScale) { FLerpToPlayerOv0(this,_expiredCallback,_bDisableCollision,_bScale); }
	float CalculateModifiedSignal(uint64_t _pkgId, uint64_t _signalId, std::vector<unsigned __int64> const &_modifiers) const { return FCalculateModifiedSignal(this,_pkgId,_signalId,_modifiers); }
	void RemotePickUp() { FRemotePickUp(this); }
	void SelectArchetype() { FSelectArchetype(this); }
	bool TryGiveStacked(IArkInventory *_pInventory, bool _bRemoveOnSuccess) { return FTryGiveStacked(this,_pInventory,_bRemoveOnSuccess); }
	bool TryGiveInventory(IArkInventory *_pInventory) { return FTryGiveInventory(this,_pInventory); }
	Vec3 GetLerpTargetPosition() const { return FGetLerpTargetPosition(this); }
	void OnTargetLerperExpired(const float _normalizedPitch, bool _bRemoveEntity) { FOnTargetLerperExpired(this,_normalizedPitch,_bRemoveEntity); }
	void OnLerpDrop() { FOnLerpDrop(this); }
	void OnUsedFromWorld() { FOnUsedFromWorld(this); }
	void InitializeCount() { FInitializeCount(this); }
	
#if 0
	void PostSerializeLTL();
	bool IsImportant() const;
	void SetFabricating(const bool arg0);
	bool IsFood() const;
	bool IsConsumable() const;
	string GetConsumeVerb() const;
	bool IsDeleteOnPlayerPickup() const;
	void SetOwnerId(const unsigned arg0);
	void SetAssociatedEntitlement(const uint64_t arg0);
	uint64_t GetAssociatedEntitlement() const;
	int GetDismantleCount() const;
	void SetFromProperties();
	bool CanStackAny(unsigned arg0) const;
	void ForcePhysicsAwake();
#endif
	
	static inline auto FBitNotCArkItem = PreyFunction<void(CArkItem *const _this)>(0x10AFD30);
	static inline auto FGetItemFromEntityId = PreyFunction<CArkItem *(const unsigned _entityId)>(0x10B2C90);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkItem const *const _this, ICrySizer *pSizer)>(0xA13080);
	static inline auto FInit = PreyFunction<bool(CArkItem *const _this, IGameObject *pGameObject)>(0x10B3340);
	static inline auto FPostInit = PreyFunction<void(CArkItem *const _this, IGameObject *pGameObject)>(0x10B5F10);
	static inline auto FInitClient = PreyFunction<void(CArkItem *const _this, int channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkItem *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkItem *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkItem *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkItem *const _this, TSerialize signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkItem *const _this)>(0x10B61C0);
	static inline auto FFullSerialize = PreyFunction<void(CArkItem *const _this, TSerialize _ser)>(0x10B1BB0);
	static inline auto FSerializeLTL = PreyFunction<void(CArkItem *const _this, TSerialize _ser)>(0x10B67F0);
	static inline auto FNetSerialize = PreyFunction<bool(CArkItem *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkItem *const _this)>(0x10B5F60);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkItem *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkItem *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkItem *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x10B7120);
	static inline auto FHandleEvent = PreyFunction<void(CArkItem *const _this, SGameObjectEvent const &event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(CArkItem *const _this, SEntityEvent &_event)>(0x10B6110);
	static inline auto FSetChannelId = PreyFunction<void(CArkItem *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkItem *const _this, bool auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkItem const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkItem *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkItem *const _this)>(0xA13080);
	static inline auto FGiveOwnerOv1 = PreyFunction<bool(CArkItem *const _this, const unsigned _pickerId)>(0x10B3130);
	static inline auto FGiveOwnerOv0 = PreyFunction<bool(CArkItem *const _this, IArkInventory *_pInventory)>(0x10B31C0);
	static inline auto FPickUp = PreyFunction<bool(CArkItem *const _this, const unsigned _pickerId, bool _bScaleOnLerp)>(0x10B5A50);
	static inline auto FDrop = PreyFunction<void(CArkItem *const _this, int _dropCount, Vec3 const *const _altPosition)>(0x10B0D40);
	static inline auto FCanCollect = PreyFunction<bool(CArkItem const *const _this, IArkInventory const &_inventory)>(0x10B00E0);
	static inline auto FCanPlayerCollect = PreyFunction<bool(CArkItem const *const _this)>(0x10B0450);
	static inline auto FGetCount = PreyFunction<int(CArkItem const *const _this)>(0xCECB0);
	static inline auto FGetUICountOv1 = PreyFunction<wstring(CArkItem const *const _this)>(0x10B3070);
	static inline auto FGetUICountOv0 = PreyFunction<wstring(uint64_t _archetype, int _count)>(0x10B2FD0);
	static inline auto FResetCount = PreyFunction<void(CArkItem *const _this, int _count)>(0x10B6410);
	static inline auto FIsStackFull = PreyFunction<bool(CArkItem const *const _this)>(0x10B3A50);
	static inline auto FCanCombine = PreyFunction<bool(CArkItem const *const _this, CArkItem const &_other)>(0x10B02A0);
	static inline auto FCombine = PreyFunction<bool(CArkItem *const _this, IArkItem &_other, bool _bRemoveOnSuccess)>(0x10B0BD0);
	static inline auto FRandomizeStackCount = PreyFunction<void(CArkItem *const _this)>(0x10B6180);
	static inline auto FGetType = PreyFunction<const char *(CArkItem const *const _this)>(0x116D850);
	static inline auto FGetName = PreyFunction<const char *(CArkItem const *const _this)>(0x12C8A0);
	static inline auto FGetArchetype = PreyFunction<uint64_t(CArkItem const *const _this)>(0x82E930);
	static inline auto FGetDescription = PreyFunction<wstring(CArkItem const *const _this)>(0x10B1DF0);
	static inline auto FGetIcon = PreyFunction<const char *(CArkItem const *const _this)>(0x9046A0);
	static inline auto FGetHUDIcon = PreyFunction<const char *(CArkItem const *const _this)>(0x10B2940);
	static inline auto FGetStylizedIcon = PreyFunction<const char *(CArkItem const *const _this)>(0x10B2FB0);
	static inline auto FGetInventoryDimensions = PreyFunction<std::pair<int,int>(CArkItem const *const _this)>(0x10B2C70);
	static inline auto FIsStackable = PreyFunction<bool(CArkItem const *const _this)>(0x10B3A70);
	static inline auto FGetMaxStackSize = PreyFunction<int(CArkItem const *const _this)>(0x1F21C0);
	static inline auto FIsGrenade = PreyFunction<bool(CArkItem const *const _this)>(0x10B3A30);
	static inline auto FIsEquippable = PreyFunction<bool(CArkItem const *const _this)>(0x10B39A0);
	static inline auto FCanEquipFromInventory = PreyFunction<bool(CArkItem const *const _this)>(0x10B03C0);
	static inline auto FGetEquipId = PreyFunction<unsigned(CArkItem const *const _this)>(0x10B2780);
	static inline auto FSetFavorite = PreyFunction<void(CArkItem *const _this, bool _bFavorite)>(0x10B6970);
	static inline auto FIsFavorite = PreyFunction<bool(CArkItem const *const _this)>(0x10B39E0);
	static inline auto FSetTrash = PreyFunction<void(CArkItem *const _this, bool _bTrash)>(0x10B6AC0);
	static inline auto FIsTrash = PreyFunction<bool(CArkItem const *const _this)>(0x10B3A80);
	static inline auto FGetCategory = PreyFunction<CArkItem::Category(CArkItem const *const _this)>(0x10B1DB0);
	static inline auto FSetLootRequirement = PreyFunction<void(CArkItem *const _this, uint64_t _abilityId)>(0x10B69D0);
	static inline auto FCanLoot = PreyFunction<bool(CArkItem const *const _this)>(0x10B03D0);
	static inline auto FCanUse = PreyFunction<bool(CArkItem const *const _this)>(0x10B0840);
	static inline auto FUse = PreyFunction<void(CArkItem *const _this)>(0x10B7260);
	static inline auto FUseFromWorld = PreyFunction<void(CArkItem *const _this)>(0x10B7410);
	static inline auto FUseFromInventory = PreyFunction<void(CArkItem *const _this)>(0x10B7280);
	static inline auto FConsume = PreyFunction<void(CArkItem *const _this, int _count)>(0x10B0C80);
	static inline auto FCanConsume = PreyFunction<bool(CArkItem const *const _this)>(0x10B0350);
	static inline auto FCanConsumeFromWorld = PreyFunction<bool(CArkItem const *const _this)>(0x10B0380);
	static inline auto FIsWeapon = PreyFunction<bool(CArkItem const *const _this)>(0xDD23F0);
	static inline auto FIsEqual = PreyFunction<bool(CArkItem const *const _this, IArkItem const &other)>(0x10B3920);
	static inline auto FIsArchetypeOv1 = PreyFunction<bool(CArkItem const *const _this, IEntityArchetype const &_archetype)>(0x10B38E0);
	static inline auto FIsArchetypeOv0 = PreyFunction<bool(CArkItem const *const _this, const uint64_t _archetypeId)>(0x10B3910);
	static inline auto FHasMetaTags = PreyFunction<bool(CArkItem const *const _this, std::vector<unsigned __int64> const &_tags)>(0x10B3320);
	static inline auto FIsPlotCritical = PreyFunction<bool(CArkItem const *const _this)>(0x10B3A40);
	static inline auto FOnInteraction = PreyFunction<bool(CArkItem *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x10B5000);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(CArkItem const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x10B5DE0);
	static inline auto FCanPickUp = PreyFunction<bool(CArkItem const *const _this)>(0x10B0410);
	static inline auto FGetOwnerId = PreyFunction<unsigned(CArkItem const *const _this)>(0x9921B0);
	static inline auto FGetOwnerInventory = PreyFunction<IArkInventory *(const unsigned _ownerId)>(0x10B2EF0);
	static inline auto FOnInventoryTransfer = PreyFunction<void(CArkItem *const _this, IArkInventory const &_source, IArkInventory const &_target)>(0x10B5160);
	static inline auto FGetDisplayName = PreyFunction<wstring(CArkItem const *const _this, int _count)>(0x10B25D0);
	static inline auto FGetLootRequirement = PreyFunction<uint64_t(CArkItem const *const _this)>(0xE70280);
	static inline auto FSetPhysicalizeAsStatic = PreyFunction<void(CArkItem *const _this, bool _bStatic, bool _bPhysicalize)>(0x10B69E0);
	static inline auto FClone = PreyFunction<CArkItem &(CArkItem const *const _this, int _count)>(0x10B09A0);
	static inline auto FRemoveEntity = PreyFunction<void(CArkItem *const _this)>(0x10B6300);
	static inline auto FRemoveFromInventory = PreyFunction<void(CArkItem *const _this)>(0x10B6360);
	static inline auto FGetInventory = PreyFunction<IArkInventory *(CArkItem const *const _this, const unsigned _ownerId)>(0x10B2BB0);
	static inline auto FGetFabricationCount = PreyFunction<int(IEntityArchetype *const _pArchetype)>(0x10B27E0);
	static inline auto FGetHudIcon = PreyFunction<string(const uint64_t _archetypeId)>(0x10B2960);
	static inline auto FNotifyPlayerAcquired = PreyFunction<void(CArkItem const *const _this, int _count)>(0x10B4E10);
	static inline auto FGetPropertiesTable = PreyFunction<ArkSafeScriptTable(CArkItem const *const _this)>(0x1646210);
	static inline auto FSetPickupModel = PreyFunction<void(CArkItem *const _this)>(0x10B6A00);
	static inline auto FPhysicalize = PreyFunction<void(CArkItem *const _this)>(0x10B56D0);
	static inline auto FGetPickupModel = PreyFunction<const char *(CArkItem const *const _this)>(0x155AD30);
	static inline auto FGetPickupMaterial = PreyFunction<const char *(CArkItem const *const _this)>(0x24DDE0);
	static inline auto FSetupModel = PreyFunction<void(CArkItem *const _this, bool _bFirstPerson)>(0x10B6AD0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkItem *const _this)>(0x10B3D20);
	static inline auto FCanPlayerCollectArchetype = PreyFunction<bool(IEntityArchetype *const _pArchetype)>(0x10B0490);
	static inline auto FLerpToPlayerOv1 = PreyFunction<void(CArkItem *const _this, bool _bRemoveEntity, bool _bScale)>(0x10B3C60);
	static inline auto FLerpToPlayerOv0 = PreyFunction<void(CArkItem *const _this, std::function<void __cdecl(void)> _expiredCallback, bool _bDisableCollision, bool _bScale)>(0x10B3A90);
	static inline auto FCalculateModifiedSignal = PreyFunction<float(CArkItem const *const _this, uint64_t _pkgId, uint64_t _signalId, std::vector<unsigned __int64> const &_modifiers)>(0x10AFF50);
	static inline auto FRemotePickUp = PreyFunction<void(CArkItem *const _this)>(0x10B6230);
	static inline auto FSelectArchetype = PreyFunction<void(CArkItem *const _this)>(0x10B64F0);
	static inline auto FTryGiveStacked = PreyFunction<bool(CArkItem *const _this, IArkInventory *_pInventory, bool _bRemoveOnSuccess)>(0x10B6E50);
	static inline auto FTryGiveInventory = PreyFunction<bool(CArkItem *const _this, IArkInventory *_pInventory)>(0x10B6DB0);
	static inline auto FGetLerpTargetPosition = PreyFunction<Vec3(CArkItem const *const _this)>(0x10B2CC0);
	static inline auto FOnTargetLerperExpired = PreyFunction<void(CArkItem *const _this, const float _normalizedPitch, bool _bRemoveEntity)>(0x10B54B0);
	static inline auto FOnLerpDrop = PreyFunction<void(CArkItem *const _this)>(0x10B5480);
	static inline auto FOnUsedFromWorld = PreyFunction<void(CArkItem *const _this)>(0x10B5540);
	static inline auto FInitializeCount = PreyFunction<void(CArkItem *const _this)>(0x10B3600);
};

