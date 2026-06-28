// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkSpatialManagerEntry.h>
#include <_unknown/IArkSaveLoadListener.h>

class ArkNpc;
enum EEntityAspects;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkNpcSpawner
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawner.h
class CArkNpcSpawner : public CGameObjectExtensionHelper<CArkNpcSpawner, IGameObjectExtension>, public IArkSaveLoadListener
{ // Size=120 (0x78)
public:
	uint64_t m_pendingSpawnCount;
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_NpcSpawner> m_spatialManagerEntry;
	unsigned m_lastSpawnedEntityId;
	std::pair<string, string> m_managedByEncounter;

	CArkNpcSpawner();
	virtual ~CArkNpcSpawner();
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _rParams);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _rParams);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _rCtx, int _updateSlot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void OnFirstTimeInLevel();
	IEntity* SpawnNpcEntity(unsigned _fromStartGameEntityId) { return FSpawnNpcEntity(this, _fromStartGameEntityId); }
	void TrackSpawnedEntity(IEntity* pSpawnedEntity) { FTrackSpawnedEntity(this, pSpawnedEntity); }
	void RequestSpawn() { FRequestSpawn(this); }
	void SetManagedByEncounter(const string& profile_name, const string& encounter_name) { FSetManagedByEncounter(this, profile_name, encounter_name); }
	virtual IEntityArchetype* GetEntityArchetype() const;
	virtual void InitializeNpc(ArkNpc& _npc);
	virtual void SetupSpawnedNpcCharacter();
	bool ShouldSpawnOnGameStart() const { return FShouldSpawnOnGameStart(this); }

#if 0
	const std::pair<string, string>& GetManagingEncounter() const;
	const unsigned GetLastSpawnedEntityId() const;
	IEntity* DoSpawnNpcEntity(unsigned _arg0_);
	void ProcessResetEvent(SEntityEvent& _arg0_);
	void ProcessScriptEvent(SEntityEvent& _arg0_);
	void ProcessSpawnScriptEvent(SEntityEvent& _arg0_);
	void ProcessStartGameEvent(SEntityEvent& _arg0_);
	void ProcessDoneEvent(SEntityEvent& _arg0_);
#endif

	static inline auto FCArkNpcSpawner = PreyFunction<void(CArkNpcSpawner* const _this)>(0x163AA80);
	static inline auto FBitNotCArkNpcSpawner = PreyFunction<void(CArkNpcSpawner* const _this)>(0x163ABB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkNpcSpawner* const _this, ICrySizer* _pSizer)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CArkNpcSpawner* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FPostInit = PreyFunction<void(CArkNpcSpawner* const _this, IGameObject* _pGameObject)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(CArkNpcSpawner* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkNpcSpawner* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkNpcSpawner* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkNpcSpawner* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkNpcSpawner* const _this, TSerialize _signature)>(0x163B510);
	static inline auto FRelease = PreyFunction<void(CArkNpcSpawner* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkNpcSpawner* const _this, TSerialize _ser)>(0x163B270);
	static inline auto FNetSerialize = PreyFunction<bool(CArkNpcSpawner* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t profile, int _pflags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkNpcSpawner* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkNpcSpawner* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkNpcSpawner* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkNpcSpawner* const _this, SEntityUpdateContext& _rCtx, int _updateSlot)>(0x163C030);
	static inline auto FHandleEvent = PreyFunction<void(CArkNpcSpawner* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkNpcSpawner* const _this, SEntityEvent& _event)>(0x163B7C0);
	static inline auto FSetChannelId = PreyFunction<void(CArkNpcSpawner* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkNpcSpawner* const _this, bool _auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CArkNpcSpawner* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkNpcSpawner* const _this)>(0x1333E90);
	static inline auto FOnFirstTimeInLevel = PreyFunction<void(IArkSaveLoadListener* const _this)>(0x163B790);
	static inline auto FSpawnNpcEntity = PreyFunction<IEntity* (CArkNpcSpawner* const _this, unsigned _fromStartGameEntityId)>(0x163BDF0);
	static inline auto FTrackSpawnedEntity = PreyFunction<void(CArkNpcSpawner* const _this, IEntity* pSpawnedEntity)>(0x163C010);
	static inline auto FRequestSpawn = PreyFunction<void(CArkNpcSpawner* const _this)>(0x163B990);
	static inline auto FSetManagedByEncounter = PreyFunction<void(CArkNpcSpawner* const _this, const string& profile_name, const string& encounter_name)>(0x163BA00);
	static inline auto FGetEntityArchetype = PreyFunction<IEntityArchetype* (const CArkNpcSpawner* const _this)>(0x1334780);
	static inline auto FInitializeNpc = PreyFunction<void(CArkNpcSpawner* const _this, ArkNpc& _npc)>(0x163B540);
	static inline auto FSetupSpawnedNpcCharacter = PreyFunction<void(CArkNpcSpawner* const _this)>(0x163BA30);
	static inline auto FShouldSpawnOnGameStart = PreyFunction<bool(const CArkNpcSpawner* const _this)>(0x163BC80);
};
#endif // MOONCRASH
