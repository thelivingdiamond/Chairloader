// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/IArkSaveLoadListener.h>

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

// ArkTurretSpawner
// Header:  Prey/GameDll/ark/turret/ArkTurretSpawner.h
class ArkTurretSpawner : public CGameObjectExtensionHelper<ArkTurretSpawner, IGameObjectExtension>, public IArkSaveLoadListener
{ // Size=88 (0x58)
public:
	std::pair<string, string> m_managedByEncounter;

	ArkTurretSpawner();
	virtual ~ArkTurretSpawner();
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
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
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
	IEntity* SpawnTurret() { return FSpawnTurret(this); }
	void SetManagedByEncounter(const string& profile_name, const string& encounter_name) { FSetManagedByEncounter(this, profile_name, encounter_name); }
	void TrackSpawnedEntity(IEntity* pSpawnedEntity) { FTrackSpawnedEntity(this, pSpawnedEntity); }
	virtual IEntityArchetype* GetEntityArchetype() const;
	bool ShouldSpawnOnGameStart() const { return FShouldSpawnOnGameStart(this); }
	IEntity* DoSpawnTurret() { return FDoSpawnTurret(this); }

#if 0
	const std::pair<string, string>& GetManagingEncounter();
	void SetupEditorCharacter();
	void ProcessResetEvent(SEntityEvent& _arg0_);
	void ProcessScriptEvent(SEntityEvent& _arg0_);
	void ProcessStartGameEvent(SEntityEvent& _arg0_);
#endif

	static inline auto FArkTurretSpawnerOv1 = PreyFunction<void(ArkTurretSpawner* const _this)>(0x13CE520);
	static inline auto FBitNotArkTurretSpawner = PreyFunction<void(ArkTurretSpawner* const _this)>(0x13CE640);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretSpawner* const _this, ICrySizer* _pSizer)>(0xE98E40);
	static inline auto FInit = PreyFunction<bool(ArkTurretSpawner* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FPostInit = PreyFunction<void(ArkTurretSpawner* const _this, IGameObject* _pGameObject)>(0x1333E90);
	static inline auto FInitClient = PreyFunction<void(ArkTurretSpawner* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(ArkTurretSpawner* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkTurretSpawner* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkTurretSpawner* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _rParams)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkTurretSpawner* const _this, TSerialize _signature)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(ArkTurretSpawner* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(ArkTurretSpawner* const _this, TSerialize _ser)>(0x13CEDC0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkTurretSpawner* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkTurretSpawner* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkTurretSpawner* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkTurretSpawner* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkTurretSpawner* const _this, SEntityUpdateContext& _rCtx, int _updateSlot)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkTurretSpawner* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(ArkTurretSpawner* const _this, SEntityEvent& _event)>(0x13CF190);
	static inline auto FSetChannelId = PreyFunction<void(ArkTurretSpawner* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkTurretSpawner* const _this, bool _auth)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(ArkTurretSpawner* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkTurretSpawner* const _this)>(0x1333E90);
	static inline auto FOnFirstTimeInLevel = PreyFunction<void(IArkSaveLoadListener* const _this)>(0x13CF160);
	static inline auto FSpawnTurret = PreyFunction<IEntity* (ArkTurretSpawner* const _this)>(0x13CF350);
	static inline auto FSetManagedByEncounter = PreyFunction<void(ArkTurretSpawner* const _this, const string& profile_name, const string& encounter_name)>(0x13CF320);
	static inline auto FTrackSpawnedEntity = PreyFunction<void(ArkTurretSpawner* const _this, IEntity* pSpawnedEntity)>(0x13CF3D0);
	static inline auto FGetEntityArchetype = PreyFunction<IEntityArchetype* (const ArkTurretSpawner* const _this)>(0x13CF060);
	static inline auto FShouldSpawnOnGameStart = PreyFunction<bool(const ArkTurretSpawner* const _this)>(0x163BC80);
	static inline auto FDoSpawnTurret = PreyFunction<IEntity* (ArkTurretSpawner* const _this)>(0x13CEA10);
};
#endif // MOONCRASH
