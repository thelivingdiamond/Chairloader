// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleCharge.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/attention/arkgenericattentionobject.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry_cystoidnest.h>

namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IGameObject;
struct IMaterial;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/cystoid/ArkCystoidNest.h
class ArkCystoidNest : public ArkEnvironmentalObject // Id=80160C0 Size=536
{
public:
	EArkCystoidNestState m_state;
	std::vector<ArkCystoidPotentialTarget> m_potentialTargets;
	unsigned m_chosenTarget;
	ArkSimpleTimer m_timer;
	ArkSimpleTimer m_delayedActivation;
	ArkAutoResetTimer m_hazardTimer;
	ArkSimpleCharge m_nullWaveAccumulation;
	std::vector<QuatT> m_spawnLocs;
	QuatT m_vfxLoc;
	ArkFireAndForgetEffect m_spawnVfx;
	ArkFireAndForgetEffect m_destroyedVfx;
	int m_cystoidsRemainingToSpawn;
	bool m_bDamagedByPlayer;
	bool m_bInZeroG;
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_CystoidNest> m_spatialManagerEntry;
	float m_monitorRadius;
	float m_spawnImpulse;
	float m_targetSpeedThresholdSq;
	float m_playerSpeedThresholdSq;
	float m_hazardRadius;
	int m_cystoidsToSpawn;
	int m_lastZeroGUpdateSlice;
	string m_cystoidArchetype;
	string m_primedMaterial;
	string m_idleAnim;
	ArkSignalSystem::Data::SignalGroupData const *m_pDamagingSignalGroup;
	ArkSignalSystem::Data::SignalGroupData const *m_pTriggerSignalGroup;
	uint64_t m_nullWaveSignal;
	uint64_t m_hazardPackage;
	std::vector<unsigned __int64> m_tagsToIgnore;
	ArkAudioTrigger m_triggerExistStart;
	ArkAudioTrigger m_triggerTriggered;
	ArkAudioTrigger m_triggerExplode;
	ArkGenericAttentionObject<ArkCystoidNest> m_attentionObject;
	
	ArkCystoidNest();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	void ForceTrigger(unsigned _forcedTarget) { FForceTrigger(this,_forcedTarget); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	void LoadGravityProperties() { FLoadGravityProperties(this); }
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void RegisterForSignals(bool _bRegister);
	void InitCachedPositionData() { FInitCachedPositionData(this); }
	void SetState(EArkCystoidNestState _state, bool _bForce) { FSetState(this,_state,_bForce); }
	bool SpawnCystoid() { return FSpawnCystoid(this); }
	void SetMaterial(IMaterial *const _material) const { FSetMaterial(this,_material); }
	void UpdateFromCystoidManager(const float _frameTime, const int _zeroGUpdateSlice, bool &_bDidZeroGTest) { FUpdateFromCystoidManager(this,_frameTime,_zeroGUpdateSlice,_bDidZeroGTest); }
	void EnableAttentionObject() { FEnableAttentionObject(this); }
	void DisableAttentionObject() { FDisableAttentionObject(this); }
	
#if 0
	bool IsDepleted() const;
	void InitArea();
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkCystoidNest *const _this, IGameObject *_pGameObject)>(0x125E760);
	static inline auto FPostInit = PreyFunction<void(ArkCystoidNest *const _this, IGameObject *_pGameObject)>(0x12602E0);
	static inline auto FRelease = PreyFunction<void(ArkCystoidNest *const _this)>(0x1260860);
	static inline auto FFullSerialize = PreyFunction<void(ArkCystoidNest *const _this, TSerialize _ser)>(0x125E440);
	static inline auto FPostSerialize = PreyFunction<void(ArkCystoidNest *const _this)>(0x1260450);
	static inline auto FHandleEvent = PreyFunction<void(ArkCystoidNest *const _this, SGameObjectEvent const &_event)>(0x125E6D0);
	static inline auto FUpdate = PreyFunction<void(ArkCystoidNest *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkCystoidNest *const _this, SEntityEvent &_event)>(0x1260460);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkCystoidNest const *const _this, ICrySizer *_s)>(0x125E670);
	static inline auto FForceTrigger = PreyFunction<void(ArkCystoidNest *const _this, unsigned _forcedTarget)>(0x125E420);
	static inline auto FOnReset = PreyFunction<void(ArkCystoidNest *const _this, bool _bEnteringGameMode)>(0x12601B0);
	static inline auto FLoadProperties = PreyFunction<void(ArkCystoidNest *const _this)>(0x125F0D0);
	static inline auto FLoadGravityProperties = PreyFunction<void(ArkCystoidNest *const _this)>(0x125EB50);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkCystoidNest *const _this, ArkSignalSystem::Package const &_package)>(0x125FEF0);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkCystoidNest *const _this, bool _bRegister)>(0x1260730);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkCystoidNest *const _this)>(0x125E860);
	static inline auto FSetState = PreyFunction<void(ArkCystoidNest *const _this, EArkCystoidNestState _state, bool _bForce)>(0x12609A0);
	static inline auto FSpawnCystoid = PreyFunction<bool(ArkCystoidNest *const _this)>(0x1260E60);
	static inline auto FSetMaterial = PreyFunction<void(ArkCystoidNest const *const _this, IMaterial *const _material)>(0x1260930);
	static inline auto FUpdateFromCystoidManager = PreyFunction<void(ArkCystoidNest *const _this, const float _frameTime, const int _zeroGUpdateSlice, bool &_bDidZeroGTest)>(0x1261210);
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkCystoidNest *const _this)>(0x125E3F0);
	static inline auto FDisableAttentionObject = PreyFunction<void(ArkCystoidNest *const _this)>(0x125E3C0);
};

