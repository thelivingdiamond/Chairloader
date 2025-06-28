// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
//#include <Prey/CryAISystem/INavigationSystem.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
//#include <Prey/CryParticleSystem/IParticles.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
//#include <Prey/GameDll/ark/ai/ArkOffMeshLinkHelper.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/iface/IArkGravShaft.h>
#include <Prey/GameDll/ark/iface/IArkLightListener.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>

class ICrySizer;
struct IEntity;
struct IGameObject;
struct IParticleEmitter;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/ark/arkgravshaftentity.h
class CArkGravShaftEntity : public CGameObjectExtensionHelper<CArkGravShaftEntity,IGameObjectExtension>, public IParticleEffectListener, public IArkRepairableListener, public IArkLightListener, public IArkGravShaft // Id=801550B Size=568
{
public:
	struct ArkContainedEntity // Id=801550E Size=32
	{
		unsigned m_entityId;
		bool m_bIsBouncing;
		std::vector<int> m_particleSlots;
		
#if 0
		unsigned GetEntityId() const;
		std::vector<int> const &GetParticleSlots() const;
		bool IsBouncing() const;
		void ClearParticleEmitterSlots();
		bool IsPlayer() const;
		void AddParticleEmitterSlot(const int arg0);
		bool operator==(const unsigned &arg0) const;
		void SetBouncing(const bool arg0);
#endif
	};

	ArkSimpleTimer m_clearGlooTimer;
	OBB m_boundsOBB;
	std::vector<CArkGravShaftEntity::ArkContainedEntity> m_containedEntities;
	std::vector<unsigned int> m_waitingNpcEntityIds;
	Vec3 m_shaftDim;
	Vec3 m_direction;
	Vec3 m_stopPosition;
	Vec3 m_enterDirection;
	Vec3 m_exitDirection;
	Vec3 m_baseDirection;
	Vec3 m_baseEnterDirection;
	Vec3 m_baseExitDirection;
	Vec3 m_baseCenterWorldPos;
	float m_speed;
	float m_exitSpeed;
	float m_exitHeight;
	float m_portalHeight;
	float m_centeringSpeed;
	float m_particleLifetime;
	float m_shaftAmbientVolume;
	float m_particleMetersPerSec;
	float m_shaftPowerOnOffVolume;
	float m_bounceSpeedMultiplier;
	float m_ambientSoundEffectRadiusMultiplier;
	uint64_t m_postProcessEffectId;
	string m_particleEffectPath;
	string m_objectParticleEffectPath;
	string m_firstPersonParticleEffectPath;
	ArkAudioTrigger m_enterShaftAudioTrigger;
	ArkAudioTrigger m_exitShaftAudioTrigger;
	ArkAudioTrigger m_bounceAudioTrigger;
	ArkAudioTrigger m_powerOnAudioTrigger;
	ArkAudioTrigger m_powerOffAudioTrigger;
	IParticleEmitter *m_pOnParticleEmitter;
	_smart_ptr<IParticleEffect> m_pMainParticleEffect;
	_smart_ptr<IParticleEffect> m_pObjectParticleEffect;
	_smart_ptr<IParticleEffect> m_pFirstPersonParticleEffect;
	ArkRepairableLite m_repairable;
	bool m_bRebuildLinks;
	float m_updateEditorPosTimer;
	ArkOffMeshLinkHelper m_navLinks;
	unsigned m_playerNightmareAvoidanceFieldId;
	bool m_bEnabled;
	bool m_bDisrupted;
	bool m_bBiDirectional;
	bool m_bReversed;
	static std::vector<CArkGravShaftEntity *> s_gravShafts;
	
	CArkGravShaftEntity();
	virtual ~CArkGravShaftEntity();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	virtual void OnCreateEmitter(IParticleEmitter *_pEmitter);
	virtual void OnDeleteEmitter(IParticleEmitter *_pEmitter);
	virtual void OnStartup();
	virtual void OnStartDisrupt();
	virtual void OnStopDisrupt();
	virtual IArkGravShaft::EntityState GetEntityState(unsigned _id) const;
	virtual bool WaitToEnter(unsigned _id) const;
	virtual void SetWaiting(unsigned _id, bool _bWaiting);
	virtual bool GetLinkPositionEnter(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentTypeId, Vec3 &_enterPos) const;
	virtual bool GetLinkPositionExit(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentTypeId, Vec3 &_exitPos) const;
	virtual Vec3 GetEnterDirection() const;
	virtual Vec3 GetExitDirection() const;
	virtual float GetTravelDirection() const;
	virtual bool IsActive() const;
	bool IsGoingTo0G() const { return FIsGoingTo0G(this); }
	static void OnPlayerStartMimicking(const unsigned _mimicEntityId) { FOnPlayerStartMimicking(_mimicEntityId); }
	static void OnPlayerStopMimicking(const unsigned _mimicEntityId) { FOnPlayerStopMimicking(_mimicEntityId); }
	void InitArea() { FInitArea(this); }
	void InitProperties() { FInitProperties(this); }
	void InitPhysicsParams() { FInitPhysicsParams(this); }
	void SpawnParticleEmitter() { FSpawnParticleEmitterOv1(this); }
	void ReverseTravelDirection() { FReverseTravelDirection(this); }
	void ClearGloo() const { FClearGloo(this); }
	void QueryEntitiesInShaft() { FQueryEntitiesInShaft(this); }
	void BounceEntity(CArkGravShaftEntity::ArkContainedEntity &_containedEntity) const { FBounceEntity(this,_containedEntity); }
	bool UpdateEntityPhysics(CArkGravShaftEntity::ArkContainedEntity &_containedEntity, const float _frameTime) const { return FUpdateEntityPhysics(this,_containedEntity,_frameTime); }
	void PlayShaftEffects() { FPlayShaftEffects(this); }
	void StopAllAudio() { FStopAllAudio(this); }
	void PlayEntityEnterEffects(CArkGravShaftEntity::ArkContainedEntity &_containedEntity) { FPlayEntityEnterEffects(this,_containedEntity); }
	void InitializeActiveState() { FInitializeActiveState(this); }
	void InitializePlayerMovementState() const { FInitializePlayerMovementState(this); }
	void ClearLinks() { FClearLinks(this); }
	void RebuildLinks() { FRebuildLinks(this); }
	std::tuple<Vec3,Vec3> CalculateLinkPositions(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentID) const { return FCalculateLinkPositions(this,_navAgentID); }
	void OnNavMeshChange() { FOnNavMeshChange(this); }
	void EnablePlayerNightmareAvoidanceField(bool _bEnable) { FEnablePlayerNightmareAvoidanceField(this,_bEnable); }
	void ExecuteLuaEvent(const char *_pEventName, IEntity const *const _pContainedEntity) const { FExecuteLuaEvent(this,_pEventName,_pContainedEntity); }
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	Vec3 GetHeightTestPos(IEntity *pEntity, Vec3 const &_position) const { return FGetHeightTestPos(this,pEntity,_position); }
	void SetDisrupted(const bool _bDisrupted) { FSetDisrupted(this,_bDisrupted); }
	void UpdateFloorPos(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentId, Vec3 &_pos) const { FUpdateFloorPos(this,_navAgentId,_pos); }
	bool StartUsing(CArkGravShaftEntity::ArkContainedEntity &_containedEntity) { return FStartUsing(this,_containedEntity); }
	void StopUsing(CArkGravShaftEntity::ArkContainedEntity &_containedEntity) { FStopUsing(this,_containedEntity); }
	void EnableLinkedLights(const bool _bEnable) const { FEnableLinkedLights(this,_bEnable); }
	
#if 0
	bool IsGoingTo1G() const;
	void SpawnParticleEmitter(CArkGravShaftEntity::ArkContainedEntity &arg0) const;
	void CacheParticleEffects();
	void ReleaseCachedParticleEffects();
	void DestroyParticleEffect();
	void DestroyParticleEffect(CArkGravShaftEntity::ArkContainedEntity &arg0) const;
	void PlayShaftPowerOnEffects();
	void PlayShaftPowerOffEffects();
	void PlayShaftAudio();
	void PlayInitialShaftAudio();
	void PlayEntityExitEffects(CArkGravShaftEntity::ArkContainedEntity &arg0);
	Vec3 GetXYPosInShaft(Vec3 const &arg0) const;
	float GetHeightInShaft(Vec3 const &arg0) const;
	void SetEnabled(const bool arg0);
	void DrawDebug() const;
	void AddMimicEntity(const unsigned arg0);
	void RemoveMimicEntity(const unsigned arg0);
#endif
	
	static inline auto FBitNotCArkGravShaftEntity = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x1438210);
	static inline auto FUpdate = PreyFunction<void(CArkGravShaftEntity *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x143EAF0);
	static inline auto FProcessEvent = PreyFunction<void(CArkGravShaftEntity *const _this, SEntityEvent &_event)>(0x143CC60);
	static inline auto FInit = PreyFunction<bool(CArkGravShaftEntity *const _this, IGameObject *_pGameObject)>(0x143A0B0);
	static inline auto FInitClient = PreyFunction<void(CArkGravShaftEntity *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(CArkGravShaftEntity *const _this, IGameObject *_pGameObject)>(0x143CA00);
	static inline auto FPostInitClient = PreyFunction<void(CArkGravShaftEntity *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkGravShaftEntity *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkGravShaftEntity *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkGravShaftEntity *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143DF70);
	static inline auto FFullSerialize = PreyFunction<void(CArkGravShaftEntity *const _this, TSerialize _ser)>(0x1439920);
	static inline auto FNetSerialize = PreyFunction<bool(CArkGravShaftEntity *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143CB40);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkGravShaftEntity *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkGravShaftEntity *const _this)>(0x13883F0);
	static inline auto FPostUpdate = PreyFunction<void(CArkGravShaftEntity *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkGravShaftEntity *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(CArkGravShaftEntity *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FSetChannelId = PreyFunction<void(CArkGravShaftEntity *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkGravShaftEntity *const _this, bool _bAuth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkGravShaftEntity const *const _this, ICrySizer *_pS)>(0x141ABE0);
	static inline auto FOnCreateEmitter = PreyFunction<void(CArkGravShaftEntity *const _this, IParticleEmitter *_pEmitter)>(0xA13080);
	static inline auto FOnDeleteEmitter = PreyFunction<void(CArkGravShaftEntity *const _this, IParticleEmitter *_pEmitter)>(0x143C370);
	static inline auto FOnStartup = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143C750);
	static inline auto FOnStartDisrupt = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143C740);
	static inline auto FOnStopDisrupt = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143C780);
	static inline auto FGetEntityState = PreyFunction<IArkGravShaft::EntityState(CArkGravShaftEntity const *const _this, unsigned _id)>(0x1439AE0);
	static inline auto FWaitToEnter = PreyFunction<bool(CArkGravShaftEntity const *const _this, unsigned _id)>(0x143F580);
	static inline auto FSetWaiting = PreyFunction<void(CArkGravShaftEntity *const _this, unsigned _id, bool _bWaiting)>(0x143E460);
	static inline auto FGetLinkPositionEnter = PreyFunction<bool(CArkGravShaftEntity const *const _this, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentTypeId, Vec3 &_enterPos)>(0x1439DD0);
	static inline auto FGetLinkPositionExit = PreyFunction<bool(CArkGravShaftEntity const *const _this, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentTypeId, Vec3 &_exitPos)>(0x1439F20);
	static inline auto FGetEnterDirection = PreyFunction<Vec3(CArkGravShaftEntity const *const _this)>(0x1439AC0);
	static inline auto FGetExitDirection = PreyFunction<Vec3(CArkGravShaftEntity const *const _this)>(0x1439D00);
	static inline auto FGetTravelDirection = PreyFunction<float(CArkGravShaftEntity const *const _this)>(0x143A080);
	static inline auto FIsActive = PreyFunction<bool(CArkGravShaftEntity const *const _this)>(0x143C2D0);
	static inline auto FIsGoingTo0G = PreyFunction<bool(CArkGravShaftEntity const *const _this)>(0x143C300);
	static inline auto FOnPlayerStartMimicking = PreyFunction<void(const unsigned _mimicEntityId)>(0x143C3A0);
	static inline auto FOnPlayerStopMimicking = PreyFunction<void(const unsigned _mimicEntityId)>(0x143C5B0);
	static inline auto FInitArea = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143A1F0);
	static inline auto FInitProperties = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143ADF0);
	static inline auto FInitPhysicsParams = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143A400);
	static inline auto FSpawnParticleEmitterOv1 = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143E500);
	static inline auto FReverseTravelDirection = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143E130);
	static inline auto FClearGloo = PreyFunction<void(CArkGravShaftEntity const *const _this)>(0x1438EB0);
	static inline auto FQueryEntitiesInShaft = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143D460);
	static inline auto FBounceEntity = PreyFunction<void(CArkGravShaftEntity const *const _this, CArkGravShaftEntity::ArkContainedEntity &_containedEntity)>(0x1438540);
	static inline auto FUpdateEntityPhysics = PreyFunction<bool(CArkGravShaftEntity const *const _this, CArkGravShaftEntity::ArkContainedEntity &_containedEntity, const float _frameTime)>(0x143ED90);
	static inline auto FPlayShaftEffects = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143C960);
	static inline auto FStopAllAudio = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143E8C0);
	static inline auto FPlayEntityEnterEffects = PreyFunction<void(CArkGravShaftEntity *const _this, CArkGravShaftEntity::ArkContainedEntity &_containedEntity)>(0x143C790);
	static inline auto FInitializeActiveState = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143BF30);
	static inline auto FInitializePlayerMovementState = PreyFunction<void(CArkGravShaftEntity const *const _this)>(0x143C0D0);
	static inline auto FClearLinks = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x1439500);
	static inline auto FRebuildLinks = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143D800);
	static inline auto FCalculateLinkPositions = PreyFunction<std::tuple<Vec3,Vec3>(CArkGravShaftEntity const *const _this, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentID)>(0x1438C00);
	static inline auto FOnNavMeshChange = PreyFunction<void(CArkGravShaftEntity *const _this)>(0x143C390);
	static inline auto FEnablePlayerNightmareAvoidanceField = PreyFunction<void(CArkGravShaftEntity *const _this, bool _bEnable)>(0x14396A0);
	static inline auto FExecuteLuaEvent = PreyFunction<void(CArkGravShaftEntity const *const _this, const char *_pEventName, IEntity const *const _pContainedEntity)>(0x14397D0);
	static inline auto FOnBrokenChanged = PreyFunction<void(CArkGravShaftEntity *const _this, bool _bBroken, bool _bWasForced)>(0x143C360);
	static inline auto FGetHeightTestPos = PreyFunction<Vec3(CArkGravShaftEntity const *const _this, IEntity *pEntity, Vec3 const &_position)>(0x1439D20);
	static inline auto FSetDisrupted = PreyFunction<void(CArkGravShaftEntity *const _this, const bool _bDisrupted)>(0x143E2F0);
	static inline auto FUpdateFloorPos = PreyFunction<void(CArkGravShaftEntity const *const _this, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentId, Vec3 &_pos)>(0x143F310);
	static inline auto FStartUsing = PreyFunction<bool(CArkGravShaftEntity *const _this, CArkGravShaftEntity::ArkContainedEntity &_containedEntity)>(0x143E810);
	static inline auto FStopUsing = PreyFunction<void(CArkGravShaftEntity *const _this, CArkGravShaftEntity::ArkContainedEntity &_containedEntity)>(0x143E900);
	static inline auto FEnableLinkedLights = PreyFunction<void(CArkGravShaftEntity const *const _this, const bool _bEnable)>(0x1439580);
};

