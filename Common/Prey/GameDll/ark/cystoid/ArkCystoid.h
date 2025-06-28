// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/attention/arkgenericattentionobject.h>
#include <Prey/GameDll/ark/cystoid/ArkCystoidSignalReceiver.h>
#include <Prey/GameDll/ark/cystoid/ArkCystoidPotentialTarget.h>
#include <Prey/GameDll/ark/player/IArkEtherDuplicateListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerCarryListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerCombatListener.h>

class ArkCystoidProperties;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IParticleEffect;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: Exact
// Prey/GameDll/ark/cystoid/ArkCystoid.h
class ArkCystoid : public CGameObjectExtensionHelper<ArkCystoid,IGameObjectExtension>, public IArkPlayerCarryListener, public IArkPlayerCombatListener, public IArkEtherDuplicateListener // Id=8015413 Size=568
{
public:
	ArkCystoidSignalReceiver m_signalReceiver;
	ArkEntityEffect m_stateVfx;
	ArkEntityEffect m_spawnedByWeaverVfx;
	Vec3 m_flockingStartPoint;
	EArkCystoidState m_state;
	unsigned m_targetEntityID;
	unsigned m_swarmLeader;
	bool m_bScripted;
	float m_updateRate;
	float m_movementPeriod;
	float m_movementPeriodPos;
	float m_nullWaveAccumulation;
	bool m_bIsInZeroG;
	bool m_bDamagedByPlayer;
	bool m_bPostSerializeExplicit;
	ArkCystoidProperties const *m_pProperties;
	ArkSimpleTimer m_invalidateTargetTimer;
	ArkSimpleTimer m_explodeTimer;
	ArkSimpleTimer m_energizeTimer;
	ArkAutoResetTimer m_lureTimer;
	ArkSimpleTimer m_targetResetTimer;
	ArkSimpleTimer m_stunnedTimer;
	ArkSimpleTimer m_timeOffGround;
	ArkTimeRemaining m_randomImpulseTimer;
	ArkGenericAttentionObject<ArkCystoid> m_attentionObject;
	int m_explodeInAnimId;
	int m_explodeLoopAnimId;
	std::vector<ArkCystoidPotentialTarget> m_potentialTargets;
	
	ArkCystoid();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject *_pGameObject);
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
	virtual void Update(SEntityUpdateContext &ctx, int updateSlot);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	void UpdateCystoid(const float _timeDelta, Vec3 const &_playerPos) { FUpdateCystoid(this,_timeDelta,_playerPos); }
	void PostSerializeCystoid() { FPostSerializeCystoid(this); }
	void ReceiveSignalPackage(ArkSignalSystem::Package const &_package) { FReceiveSignalPackage(this,_package); }
	void RegisterForSignals(bool _bRegister) { FRegisterForSignals(this,_bRegister); }
	void FollowTarget(const unsigned &_newTarget) { FFollowTarget(this,_newTarget); }
	float GetUpdateRate() const { return FGetUpdateRate(this); }
	bool TestTarget(unsigned _target) const { return FTestTarget(this,_target); }
	void TryToSetTarget(unsigned _target, unsigned _nestEntity, bool _bTestCurrentTarget) { FTryToSetTarget(this,_target,_nestEntity,_bTestCurrentTarget); }
	void SetTarget(unsigned _newTarget) { FSetTarget(this,_newTarget); }
	void SetActive(bool _bActive, bool _bForce) { FSetActive(this,_bActive,_bForce); }
	void SetSwarmLeader(const unsigned _swarmLeader, bool _bForce) { FSetSwarmLeader(this,_swarmLeader,_bForce); }
	void NotifyOfSwarmMemberAdded(ArkCystoid *_pCystoid) const { FNotifyOfSwarmMemberAdded(this,_pCystoid); }
	bool IsSwarmLeader() const { return FIsSwarmLeader(this); }
	bool HandleHypnotize(const unsigned _source) { return FHandleHypnotize(this,_source); }
	void OnSpawnedByWeaver() { FOnSpawnedByWeaver(this); }
	void Explode() { FExplode(this); }
	void SetState(EArkCystoidState _state, bool _bForce) { FSetState(this,_state,_bForce); }
	void OnReset(bool _bEnteringGameMode) { FOnReset(this,_bEnteringGameMode); }
	void UpdateTarget(float _frameTime) { FUpdateTarget(this,_frameTime); }
	virtual void OnStopCarry(IEntity *const _pEntity, bool _bThrown);
	virtual void OnGrenadeThrown(IEntity *const _pGrenade);
	virtual void OnEtherDuplicateCreated(const unsigned _etherDuplicate);
	void EnterState(bool _bForce) { FEnterState(this,_bForce); }
	void ExitState() { FExitState(this); }
	void SetUpdateRate(EArkCystoidState _state) { FSetUpdateRate(this,_state); }
	void MoveTowardsTarget(const float _frameTime, const bool _bUpdateMovement) { FMoveTowardsTarget(this,_frameTime,_bUpdateMovement); }
	float GetDistanceSqToTarget() const { return FGetDistanceSqToTarget(this); }
	void SpawnStateVFX(IParticleEffect *_pParticleEffect) { FSpawnStateVFX(this,_pParticleEffect); }
	void ProcessNearbyCystoids(float _nearbyRange, void (*_pFunc)(ArkCystoid const *const , ArkCystoid *const )) { FProcessNearbyCystoids(this,_nearbyRange,_pFunc); }
	static void LureCystoid(ArkCystoid const *const _pSourceCystoid, ArkCystoid *const _pNearbyCystoid) { FLureCystoid(_pSourceCystoid,_pNearbyCystoid); }
	
#if 0
	void Kill();
	unsigned GetTarget() const;
	bool IsEnergized() const;
	bool IsDead() const;
	unsigned GetSwarmLeader() const;
	void SetProperties(ArkCystoidProperties const *arg0);
	void SpawnParticle(IParticleEffect *arg0) const;
	void HandleScriptEvent(const char *arg0);
	void EnableAttentionObject();
	void DisableAttentionObject();
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkCystoid *const _this, IGameObject *_pGameObject)>(0x141AFF0);
	static inline auto FInitClient = PreyFunction<void(ArkCystoid *const _this, int channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkCystoid *const _this, IGameObject *_pGameObject)>(0x141C4D0);
	static inline auto FPostInitClient = PreyFunction<void(ArkCystoid *const _this, int channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkCystoid *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkCystoid *const _this, IGameObject *pGameObject, SEntitySpawnParams const &params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkCystoid *const _this, TSerialize signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(ArkCystoid *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(ArkCystoid *const _this, TSerialize _ser)>(0x141A600);
	static inline auto FNetSerialize = PreyFunction<bool(ArkCystoid *const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkCystoid *const _this)>(0x141C7B0);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkCystoid *const _this, TSerialize ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkCystoid *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkCystoid *const _this, SEntityUpdateContext &ctx, int updateSlot)>(0xA13080);
	static inline auto FPostUpdate = PreyFunction<void(ArkCystoid *const _this, float frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkCystoid *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkCystoid *const _this, SGameObjectEvent const &_event)>(0x141AC90);
	static inline auto FProcessEvent = PreyFunction<void(ArkCystoid *const _this, SEntityEvent &_event)>(0x141C820);
	static inline auto FSetChannelId = PreyFunction<void(ArkCystoid *const _this, uint16_t id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkCystoid *const _this, bool auth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkCystoid const *const _this, ICrySizer *s)>(0x141ABE0);
	static inline auto FUpdateCystoid = PreyFunction<void(ArkCystoid *const _this, const float _timeDelta, Vec3 const &_playerPos)>(0x141DFB0);
	static inline auto FPostSerializeCystoid = PreyFunction<void(ArkCystoid *const _this)>(0x141C7F0);
	static inline auto FReceiveSignalPackage = PreyFunction<void(ArkCystoid *const _this, ArkSignalSystem::Package const &_package)>(0x141CE20);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkCystoid *const _this, bool _bRegister)>(0x141D150);
	static inline auto FFollowTarget = PreyFunction<void(ArkCystoid *const _this, const unsigned &_newTarget)>(0x141A5E0);
	static inline auto FGetUpdateRate = PreyFunction<float(ArkCystoid const *const _this)>(0x141AC80);
	static inline auto FTestTarget = PreyFunction<bool(ArkCystoid const *const _this, unsigned _target)>(0x141DD00);
	static inline auto FTryToSetTarget = PreyFunction<void(ArkCystoid *const _this, unsigned _target, unsigned _nestEntity, bool _bTestCurrentTarget)>(0x141DD40);
	static inline auto FSetTarget = PreyFunction<void(ArkCystoid *const _this, unsigned _newTarget)>(0x141D640);
	static inline auto FSetActive = PreyFunction<void(ArkCystoid *const _this, bool _bActive, bool _bForce)>(0x141D2F0);
	static inline auto FSetSwarmLeader = PreyFunction<void(ArkCystoid *const _this, const unsigned _swarmLeader, bool _bForce)>(0x141D490);
	static inline auto FNotifyOfSwarmMemberAdded = PreyFunction<void(ArkCystoid const *const _this, ArkCystoid *_pCystoid)>(0x141BB50);
	static inline auto FIsSwarmLeader = PreyFunction<bool(ArkCystoid const *const _this)>(0x141B110);
	static inline auto FHandleHypnotize = PreyFunction<bool(ArkCystoid *const _this, const unsigned _source)>(0x141AF50);
	static inline auto FOnSpawnedByWeaver = PreyFunction<void(ArkCystoid *const _this)>(0x141BF70);
	static inline auto FExplode = PreyFunction<void(ArkCystoid *const _this)>(0x141A1E0);
	static inline auto FSetState = PreyFunction<void(ArkCystoid *const _this, EArkCystoidState _state, bool _bForce)>(0x141D330);
	static inline auto FOnReset = PreyFunction<void(ArkCystoid *const _this, bool _bEnteringGameMode)>(0x141BBC0);
	static inline auto FUpdateTarget = PreyFunction<void(ArkCystoid *const _this, float _frameTime)>(0x141E560);
	static inline auto FOnStopCarry = PreyFunction<void(ArkCystoid *const _this, IEntity *const _pEntity, bool _bThrown)>(0x141C480);
	static inline auto FOnGrenadeThrown = PreyFunction<void(ArkCystoid *const _this, IEntity *const _pGrenade)>(0x1267E30);
	static inline auto FOnEtherDuplicateCreated = PreyFunction<void(ArkCystoid *const _this, const unsigned _etherDuplicate)>(0x141BBB0);
	static inline auto FEnterState = PreyFunction<void(ArkCystoid *const _this, bool _bForce)>(0x1419CD0);
	static inline auto FExitState = PreyFunction<void(ArkCystoid *const _this)>(0x141A0B0);
	static inline auto FSetUpdateRate = PreyFunction<void(ArkCystoid *const _this, EArkCystoidState _state)>(0x141D770);
	static inline auto FMoveTowardsTarget = PreyFunction<void(ArkCystoid *const _this, const float _frameTime, const bool _bUpdateMovement)>(0x141B1A0);
	static inline auto FGetDistanceSqToTarget = PreyFunction<float(ArkCystoid const *const _this)>(0x141AB20);
	static inline auto FSpawnStateVFX = PreyFunction<void(ArkCystoid *const _this, IParticleEffect *_pParticleEffect)>(0x141D7E0);
	static inline auto FProcessNearbyCystoids = PreyFunction<void(ArkCystoid *const _this, float _nearbyRange, void (*_pFunc)(ArkCystoid const *const , ArkCystoid *const ))>(0x141CAD0);
	static inline auto FLureCystoid = PreyFunction<void(ArkCystoid const *const _pSourceCystoid, ArkCystoid *const _pNearbyCystoid)>(0x141B120);
};

