// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <_unknown/CGameObjectExtensionHelper.h>

struct ArkInteractionTestResult;
class ArkInventory;
class ArkSafeScriptTable;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum EEntityAspects;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkAlienGiblet
// Header:  Prey/GameDll/ark/npc/ArkAlienGiblet.h
class CArkAlienGiblet : public CGameObjectExtensionHelper<CArkAlienGiblet, IGameObjectExtension>, public IArkPlayerInteractionListener
{ // Size=448 (0x1C0)
public:
	unsigned m_ownerId;
	unsigned m_masterGibId;
	ArkSimpleTimer m_interactTimer;
	ArkSimpleTimer m_gibFlingTimer;
	bool m_bHasFlingQueued;
	Vec3 m_fling;
	bool m_bIsArticulated;
	uint64_t m_characterId;
	EArkGibletType m_type;
	bool m_bIsExplosive;
	bool m_bUseLargeFogFragments;
	bool m_bHasStartedExplosionTelegraph;
	float m_explosionFlingForce;
	ArkSimpleTimer m_timeToExplosion;
	ArkSimpleTimer m_timeToExplosionTelegraph;
	ArkLooseEffect m_explosiveGibEffect;
	ArkLooseEffect m_explosionTelegraphEffect;
	ArkFireAndForgetEffect m_explosionEffect;
	ArkAudioTrigger m_explosionTrigger;
	ArkAudioTrigger m_explosionTelegraphTrigger;

	CArkAlienGiblet();
	virtual ~CArkAlienGiblet();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual const void* GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	virtual void OnInteractionInfoChanged(unsigned _targetId);
	void SetOwnerId(unsigned _ownerId) { FSetOwnerId(this, _ownerId); }
	void SetMasterGib(unsigned _masterGibId) { FSetMasterGib(this, _masterGibId); }
	void SetAttributes() { FSetAttributes(this); }
	void SetType(EArkGibletType _gibletType) { FSetType(this, _gibletType); }
	EArkGibletType GetType() { return FGetType(this); }
	void QueueFling(const Vec3 _flingDir, float _flingForce) { FQueueFling(this, _flingDir, _flingForce); }
	void SetInventory(const ArkInventory& _inventory) { FSetInventory(this, _inventory); }
	void SetAsExplosiveGib() { FSetAsExplosiveGib(this); }
	void PhysicalizeAsStaticWithCriticalItem() { FPhysicalizeAsStaticWithCriticalItem(this); }
	void UpdateExplosiveGib(float _elapsedTime) { FUpdateExplosiveGib(this, _elapsedTime); }
	void Physicalize() { FPhysicalize(this); }
	void AttachVfx() { FAttachVfx(this); }

#if 0
	unsigned GetOwnerId() const;
	unsigned GetMasterGib() const;
	void Explode();
	ArkSafeScriptTable GetPropertiesTable() const;
	void LoadModel();
	ArkInventory* GetInventory() const;
#endif

	static inline auto FCArkAlienGibletOv1 = PreyFunction<void(CArkAlienGiblet* const _this)>(0x127AD50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkAlienGiblet* const _this, ICrySizer* _s)>(0x127B570);
	static inline auto FInit = PreyFunction<bool(CArkAlienGiblet* const _this, IGameObject* _pGameObject)>(0x127B5A0);
	static inline auto FPostInit = PreyFunction<void(CArkAlienGiblet* const _this, IGameObject* _pGameObject)>(0x127C170);
	static inline auto FInitClient = PreyFunction<void(CArkAlienGiblet* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkAlienGiblet* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkAlienGiblet* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkAlienGiblet* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkAlienGiblet* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(CArkAlienGiblet* const _this)>(0x127C200);
	static inline auto FFullSerialize = PreyFunction<void(CArkAlienGiblet* const _this, TSerialize _ser)>(0x127B110);
	static inline auto FNetSerialize = PreyFunction<bool(CArkAlienGiblet* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0x13B0900);
	static inline auto FPostSerialize = PreyFunction<void(CArkAlienGiblet* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkAlienGiblet* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkAlienGiblet* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkAlienGiblet* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x127CD90);
	static inline auto FHandleEvent = PreyFunction<void(CArkAlienGiblet* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkAlienGiblet* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(CArkAlienGiblet* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkAlienGiblet* const _this, bool _auth)>(0x1333E90);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkAlienGiblet* const _this)>(0x1CBB0B0);
	static inline auto FPostUpdate = PreyFunction<void(CArkAlienGiblet* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkAlienGiblet* const _this)>(0x1333E90);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x127B680);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x127CD30);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x127C090);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x127C100);
	static inline auto FOnStartLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x127B6E0);
	static inline auto FOnStopLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x127B780);
	static inline auto FOnInteractionInfoChanged = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x127B6D0);
	static inline auto FSetOwnerId = PreyFunction<void(CArkAlienGiblet* const _this, unsigned _ownerId)>(0x127CBB0);
	static inline auto FSetMasterGib = PreyFunction<void(CArkAlienGiblet* const _this, unsigned _masterGibId)>(0x127CB60);
	static inline auto FSetAttributes = PreyFunction<void(CArkAlienGiblet* const _this)>(0x127C890);
	static inline auto FSetType = PreyFunction<void(CArkAlienGiblet* const _this, EArkGibletType _gibletType)>(0x127CD20);
	static inline auto FGetType = PreyFunction<EArkGibletType(CArkAlienGiblet* const _this)>(0x127B590);
	static inline auto FQueueFling = PreyFunction<void(CArkAlienGiblet* const _this, const Vec3 _flingDir, float _flingForce)>(0x127C1B0);
	static inline auto FSetInventory = PreyFunction<void(CArkAlienGiblet* const _this, const ArkInventory& _inventory)>(0x127CA00);
	static inline auto FSetAsExplosiveGib = PreyFunction<void(CArkAlienGiblet* const _this)>(0x127C240);
	static inline auto FPhysicalizeAsStaticWithCriticalItem = PreyFunction<void(CArkAlienGiblet* const _this)>(0x127BAD0);
	static inline auto FUpdateExplosiveGib = PreyFunction<void(CArkAlienGiblet* const _this, float _elapsedTime)>(0x127CEB0);
	static inline auto FPhysicalize = PreyFunction<void(CArkAlienGiblet* const _this)>(0x127B7B0);
	static inline auto FAttachVfx = PreyFunction<void(CArkAlienGiblet* const _this)>(0x127AEF0);
};
#endif // MOONCRASH
