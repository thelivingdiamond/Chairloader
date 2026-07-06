// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>

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

// CArkNpcSpawnTyphonNest
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnTyphonNest.h
class CArkNpcSpawnTyphonNest : public CGameObjectExtensionHelper<CArkNpcSpawnTyphonNest, IGameObjectExtension>
{ // Size=96 (0x60)
public:
	uint64_t m_pendingSpawnCount;
	unsigned m_lastSpawnedEntityId;
	std::pair<string, string> m_managedByEncounter;

	CArkNpcSpawnTyphonNest();
	virtual ~CArkNpcSpawnTyphonNest();
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
	IEntity* SpawnTyphonNest(unsigned _fromStartGameEntityId) { return FSpawnTyphonNest(this, _fromStartGameEntityId); }
	void TrackSpawnedEntity(IEntity* pSpawnedEntity) { FTrackSpawnedEntity(this, pSpawnedEntity); }
	void RequestSpawn() { FRequestSpawn(this); }
	void SetManagedByEncounter(const string& profile_name, const string& encounter_name) { FSetManagedByEncounter(this, profile_name, encounter_name); }
	void SetupModel() { FSetupModel(this); }
	IEntityArchetype* GetEntityArchetype() const { return FGetEntityArchetype(this); }

#if 0
	const std::pair<string, string>& GetManagingEncounter() const;
	const unsigned GetLastSpawnedEntityId() const;
	IEntity* DoSpawnTyphonNest(unsigned _arg0_);
	void ProcessResetEvent(SEntityEvent& _arg0_);
	void ProcessScriptEvent(SEntityEvent& _arg0_);
	void ProcessSpawnScriptEvent(SEntityEvent& _arg0_);
	void ProcessStartGameEvent(SEntityEvent& _arg0_);
#endif

	static inline auto FCArkNpcSpawnTyphonNestOv1 = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this)>(0x1334300);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkNpcSpawnTyphonNest* const _this, ICrySizer* _pSizer)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CArkNpcSpawnTyphonNest* const _this, IGameObject* _pGameObject)>(0x1334890);
	static inline auto FPostInit = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, IGameObject* _pGameObject)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkNpcSpawnTyphonNest* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkNpcSpawnTyphonNest* const _this, TSerialize _signature)>(0x1334850);
	static inline auto FRelease = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, TSerialize _ser)>(0x1334480);
	static inline auto FNetSerialize = PreyFunction<bool(CArkNpcSpawnTyphonNest* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t profile, int _pflags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkNpcSpawnTyphonNest* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, SEntityUpdateContext& _rCtx, int _updateSlot)>(0x1334D50);
	static inline auto FHandleEvent = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, SEntityEvent& _event)>(0x13348C0);
	static inline auto FSetChannelId = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, bool _auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this)>(0x1333E90);
	static inline auto FSpawnTyphonNest = PreyFunction<IEntity* (CArkNpcSpawnTyphonNest* const _this, unsigned _fromStartGameEntityId)>(0x1334B80);
	static inline auto FTrackSpawnedEntity = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, IEntity* pSpawnedEntity)>(0x1334D30);
	static inline auto FRequestSpawn = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this)>(0x1334070);
	static inline auto FSetManagedByEncounter = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this, const string& profile_name, const string& encounter_name)>(0x13340C0);
	static inline auto FSetupModel = PreyFunction<void(CArkNpcSpawnTyphonNest* const _this)>(0x1334A90);
	static inline auto FGetEntityArchetype = PreyFunction<IEntityArchetype* (const CArkNpcSpawnTyphonNest* const _this)>(0x1334780);
};
#endif // MOONCRASH
