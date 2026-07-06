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

// CArkNpcSpawnCystoid
// Header:  Prey/GameDll/ark/npc/ArkNpcSpawnCystoid.h
class CArkNpcSpawnCystoid : public CGameObjectExtensionHelper<CArkNpcSpawnCystoid, IGameObjectExtension>
{ // Size=96 (0x60)
public:
	uint64_t m_pendingSpawnCount;
	unsigned m_lastSpawnedEntityId;
	std::pair<string, string> m_managedByEncounter;

	CArkNpcSpawnCystoid();
	virtual ~CArkNpcSpawnCystoid();
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
	IEntity* SpawnCystoid(unsigned _fromStartGameEntityId) { return FSpawnCystoid(this, _fromStartGameEntityId); }
	void TrackSpawnedEntity(IEntity* pSpawnedEntity) { FTrackSpawnedEntity(this, pSpawnedEntity); }
	void RequestSpawn() { FRequestSpawn(this); }
	void SetManagedByEncounter(const string& profile_name, const string& encounter_name) { FSetManagedByEncounter(this, profile_name, encounter_name); }
	void SetupModel() { FSetupModel(this); }
	IEntityArchetype* GetEntityArchetype() const { return FGetEntityArchetype(this); }

#if 0
	const std::pair<string, string>& GetManagingEncounter();
	const unsigned GetLastSpawnedEntityId() const;
	IEntity* DoSpawnCystoid(unsigned _arg0_);
	void ProcessResetEvent(SEntityEvent& _arg0_);
	void ProcessScriptEvent(SEntityEvent& _arg0_);
	void ProcessSpawnScriptEvent(SEntityEvent& _arg0_);
	void ProcessStartGameEvent(SEntityEvent& _arg0_);
#endif

	static inline auto FCArkNpcSpawnCystoidOv1 = PreyFunction<void(CArkNpcSpawnCystoid* const _this)>(0x13339D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkNpcSpawnCystoid* const _this, ICrySizer* _pSizer)>(0x1333E90);
	static inline auto FInit = PreyFunction<bool(CArkNpcSpawnCystoid* const _this, IGameObject* _pGameObject)>(0x1334890);
	static inline auto FPostInit = PreyFunction<void(CArkNpcSpawnCystoid* const _this, IGameObject* _pGameObject)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(CArkNpcSpawnCystoid* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(CArkNpcSpawnCystoid* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(CArkNpcSpawnCystoid* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkNpcSpawnCystoid* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkNpcSpawnCystoid* const _this, TSerialize _signature)>(0x1333E50);
	static inline auto FRelease = PreyFunction<void(CArkNpcSpawnCystoid* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(CArkNpcSpawnCystoid* const _this, TSerialize _ser)>(0x1333B50);
	static inline auto FNetSerialize = PreyFunction<bool(CArkNpcSpawnCystoid* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t profile, int _pflags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(CArkNpcSpawnCystoid* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkNpcSpawnCystoid* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkNpcSpawnCystoid* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(CArkNpcSpawnCystoid* const _this, SEntityUpdateContext& _rCtx, int _updateSlot)>(0x13342A0);
	static inline auto FHandleEvent = PreyFunction<void(CArkNpcSpawnCystoid* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkNpcSpawnCystoid* const _this, SEntityEvent& _event)>(0x1333EA0);
	static inline auto FSetChannelId = PreyFunction<void(CArkNpcSpawnCystoid* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(CArkNpcSpawnCystoid* const _this, bool _auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(CArkNpcSpawnCystoid* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkNpcSpawnCystoid* const _this)>(0x1333E90);
	static inline auto FSpawnCystoid = PreyFunction<IEntity* (CArkNpcSpawnCystoid* const _this, unsigned _fromStartGameEntityId)>(0x13340F0);
	static inline auto FTrackSpawnedEntity = PreyFunction<void(CArkNpcSpawnCystoid* const _this, IEntity* pSpawnedEntity)>(0x1334280);
	static inline auto FRequestSpawn = PreyFunction<void(CArkNpcSpawnCystoid* const _this)>(0x1334070);
	static inline auto FSetManagedByEncounter = PreyFunction<void(CArkNpcSpawnCystoid* const _this, const string& profile_name, const string& encounter_name)>(0x13340C0);
	static inline auto FSetupModel = PreyFunction<void(CArkNpcSpawnCystoid* const _this)>(0x1334A90);
	static inline auto FGetEntityArchetype = PreyFunction<IEntityArchetype* (const CArkNpcSpawnCystoid* const _this)>(0x1334780);
};
#endif // MOONCRASH
