// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/cystoid/ArkCystoidManager.h>

class ArkCystoid;
namespace ArkSignalSystem
{
class Data;
} // namespace ArkSignalSystem
struct IEntity;
struct IEntityArchetype;
struct IParticleEffect;

// Header: FromCpp
// Prey/GameDll/ark/cystoid/ArkCystoidManager.h
class ArkCystoidManager // Id=8015411 Size=200
{
public:
	using ValidTargetCallback = Functor1wRet<unsigned int,bool>;
	
	class LOSSource // Id=801542A Size=24
	{
	public:
		IEntity const *m_pEntity;
		Vec3 m_pos;
		
#if 0
		bool operator==(IEntity const *const arg0) const;
		bool operator==(const unsigned arg0) const;
#endif
	};

	class CystoidInfo // Id=801542B Size=24
	{
	public:
		unsigned m_cystoidId;
		ArkCystoid *m_pCystoidExtension;
		float m_lastUpdateTime;
		
#if 0
		ArkCystoid *GetCystoidExtension() const;
		bool operator==(ArkCystoidManager::CystoidInfo const &arg0) const;
		float GetLastUpdateTime() const;
		void SetLastUpdateTime(float arg0);
		unsigned GetCystoidId() const;
		void Serialize(TSerialize arg0);
		void PostSerialize();
#endif
	};

	std::vector<std::pair<unsigned int,unsigned int>> m_cystoidsToUnregister;
	unsigned m_lastSwarmUpdated;
	bool m_bUpdating;
	bool m_bEnabled;
	ArkAutoResetTimer m_swarmBalanceTimer;
	int m_maxExpectedCystoidsInArea;
	int m_nestZeroGUpdateSlice;
	std::vector<unsigned int> m_pendingExplosions;
	std::unordered_map<unsigned __int64,ArkCystoidProperties> m_properties;
	std::unordered_map<unsigned int,std::vector<ArkCystoidManager::CystoidInfo>> m_swarms;
	
	ArkCystoidManager();
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void RegisterCystoid(const unsigned &_cystoidId, ArkCystoid *const _pCystoidExtension) { FRegisterCystoid(this,_cystoidId,_pCystoidExtension); }
	void UnRegisterCystoid(const unsigned &_cystoidId, const unsigned &_swarmLeader) { FUnRegisterCystoid(this,_cystoidId,_swarmLeader); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	bool IsEnergizedCystoid(const unsigned &_target) const { return FIsEnergizedCystoid(this,_target); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void BroadcastTargetChangeToSwarm(unsigned _swarmLeader, unsigned _newTarget) const { FBroadcastTargetChangeToSwarm(this,_swarmLeader,_newTarget); }
	void BroadcastActiveStateToSwarm(unsigned _swarmLeader, bool _bActive, bool _bForce) const { FBroadcastActiveStateToSwarm(this,_swarmLeader,_bActive,_bForce); }
	bool IsCystoidInSwarm(unsigned _cystoidId, unsigned _swarmLeader) const { return FIsCystoidInSwarm(this,_cystoidId,_swarmLeader); }
	void RequestSpaceForCystoids(int _numCystoidsRequested, bool _bImmediate) { FRequestSpaceForCystoids(this,_numCystoidsRequested,_bImmediate); }
	bool IsPotentialTarget(unsigned _targetId, bool _bFromCollision, bool _bInZeroG, std::vector<unsigned __int64> const &_tagsToIgnore) const { return FIsPotentialTarget(this,_targetId,_bFromCollision,_bInZeroG,_tagsToIgnore); }
	int GetMaxExpectedCystoidsInArea() const { return FGetMaxExpectedCystoidsInArea(this); }
	unsigned PickBestTarget(std::vector<ArkCystoidPotentialTarget> &_potentialTargets, IEntity const *_pSource, float _speedThresholdSq, float _playerSpeedThresholdSq, float _cystoidSpeedThresholdSq, Functor1wRet<unsigned int,bool> _targetTest, unsigned _nestEntity) const { return FPickBestTarget(this,_potentialTargets,_pSource,_speedThresholdSq,_playerSpeedThresholdSq,_cystoidSpeedThresholdSq,_targetTest,_nestEntity); }
	std::vector<unsigned int> GetCystoids() const { return FGetCystoids(this); }
	void RequestExplosion(const unsigned _cystoid) { FRequestExplosion(this,_cystoid); }
	void LoadProperties() { FLoadProperties(this); }
	void ClearReferences() { FClearReferences(this); }
	void UnRegisterCystoid_Internal(const unsigned _cystoidId, const unsigned _swarmLeader) { FUnRegisterCystoid_Internal(this,_cystoidId,_swarmLeader); }
	void AddToSwarm(ArkCystoidManager::CystoidInfo &_info) { FAddToSwarm(this,_info); }
	
#if 0
	bool IsCystoidRegistered(const unsigned &arg0) const;
	unsigned GetSwarmLeader(const unsigned &arg0) const;
	void PostSerialize(ArkGameSaveVersion arg0);
	void SetEnabled(bool arg0);
	bool IsEnabled() const;
	int GetIndexOfCystoidToUnregister(unsigned arg0) const;
	int GetNumCystoids() const;
	void RebalanceSwarms();
#endif
	
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkCystoidManager *const _this)>(0x14E4420);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkCystoidManager *const _this)>(0x14E4440);
	static inline auto FReset = PreyFunction<void(ArkCystoidManager *const _this, bool _bEnteringGameMode)>(0x14E5270);
	static inline auto FRegisterCystoid = PreyFunction<void(ArkCystoidManager *const _this, const unsigned &_cystoidId, ArkCystoid *const _pCystoidExtension)>(0x14E4B60);
	static inline auto FUnRegisterCystoid = PreyFunction<void(ArkCystoidManager *const _this, const unsigned &_cystoidId, const unsigned &_swarmLeader)>(0x14E54B0);
	static inline auto FUpdate = PreyFunction<void(ArkCystoidManager *const _this, const float _frameTime)>(0x14E56F0);
	static inline auto FIsEnergizedCystoid = PreyFunction<bool(ArkCystoidManager const *const _this, const unsigned &_target)>(0x14E2FC0);
	static inline auto FSerialize = PreyFunction<void(ArkCystoidManager *const _this, TSerialize _ser)>(0x14E52A0);
	static inline auto FBroadcastTargetChangeToSwarm = PreyFunction<void(ArkCystoidManager const *const _this, unsigned _swarmLeader, unsigned _newTarget)>(0x14E2B00);
	static inline auto FBroadcastActiveStateToSwarm = PreyFunction<void(ArkCystoidManager const *const _this, unsigned _swarmLeader, bool _bActive, bool _bForce)>(0x14E29E0);
	static inline auto FIsCystoidInSwarm = PreyFunction<bool(ArkCystoidManager const *const _this, unsigned _cystoidId, unsigned _swarmLeader)>(0x14E2E90);
	static inline auto FRequestSpaceForCystoids = PreyFunction<void(ArkCystoidManager *const _this, int _numCystoidsRequested, bool _bImmediate)>(0x14E4E90);
	static inline auto FIsPotentialTarget = PreyFunction<bool(ArkCystoidManager const *const _this, unsigned _targetId, bool _bFromCollision, bool _bInZeroG, std::vector<unsigned __int64> const &_tagsToIgnore)>(0x14E3000);
	static inline auto FGetMaxExpectedCystoidsInArea = PreyFunction<int(ArkCystoidManager const *const _this)>(0x158AF80);
	static inline auto FPickBestTarget = PreyFunction<unsigned(ArkCystoidManager const *const _this, std::vector<ArkCystoidPotentialTarget> &_potentialTargets, IEntity const *_pSource, float _speedThresholdSq, float _playerSpeedThresholdSq, float _cystoidSpeedThresholdSq, Functor1wRet<unsigned int,bool> _targetTest, unsigned _nestEntity)>(0x14E4450);
	static inline auto FGetCystoids = PreyFunction<std::vector<unsigned int>(ArkCystoidManager const *const _this)>(0x14E2DB0);
	static inline auto FRequestExplosion = PreyFunction<void(ArkCystoidManager *const _this, const unsigned _cystoid)>(0x14E4E70);
	static inline auto FLoadProperties = PreyFunction<void(ArkCystoidManager *const _this)>(0x14E30C0);
	static inline auto FClearReferences = PreyFunction<void(ArkCystoidManager *const _this)>(0x14E2C10);
	static inline auto FUnRegisterCystoid_Internal = PreyFunction<void(ArkCystoidManager *const _this, const unsigned _cystoidId, const unsigned _swarmLeader)>(0x14E54D0);
	static inline auto FAddToSwarm = PreyFunction<void(ArkCystoidManager *const _this, ArkCystoidManager::CystoidInfo &_info)>(0x14E2650);
};

// Header: Exact
// Prey/GameDll/ark/cystoid/arkcystoidmanager.h
class ArkCystoidProperties // Id=8015418 Size=440
{
public:
	class GravityDependentProperties // Id=8015419 Size=80
	{
	public:
		float m_explosionImpulse;
		float m_maxSpeed;
		float m_minSpeed;
		float m_deceleration;
		float m_homingRange;
		float m_deactivationRange;
		float m_enemyAttackRange;
		float m_damageRange;
		float m_damageRangeOuter;
		float m_innerImpulseRange;
		float m_outerImpulseRange;
		float m_flockingTetherRangeSq;
		float m_targetSpeedThresholdSq;
		float m_playerSpeedThresholdSq;
		float m_cystoidSpeedThresholdSq;
		float m_randomImpulseMinDelay;
		float m_randomImpulseMaxDelay;
		float m_randomImpulseMagnitude;
		uint64_t m_cameraShakeId;
	};

	float m_energizedAttackRange;
	float m_explodeDelay;
	float m_energizeDuration;
	float m_lureDelay;
	float m_targetRefreshDelay;
	float m_invalidTargetDelay;
	float m_stunDuration;
	float m_minMovementPeriod;
	float m_maxMovementPeriod;
	float m_nullWaveDeaccumulation;
	float m_maxTimeOffGround;
	uint64_t m_damageSignal;
	uint64_t m_energizedDamageSignal;
	uint64_t m_nullWaveSignal;
	uint64_t m_lureSignal;
	ArkSignalSystem::Data::SignalGroupData const *m_pDamageSignalGroup;
	ArkSignalSystem::Data::SignalGroupData const *m_pTriggerSignalGroup;
	uint64_t m_factionId;
	std::vector<unsigned __int64> m_tagsToIgnore;
	ArkCystoidProperties::GravityDependentProperties m_oneGProperties;
	ArkCystoidProperties::GravityDependentProperties m_zeroGProperties;
	string m_modelName;
	bool m_physicalize;
	bool m_rigidBody;
	float m_mass;
	float m_density;
	_smart_ptr<IParticleEffect> m_pActiveParticle;
	_smart_ptr<IParticleEffect> m_pDormantParticle;
	_smart_ptr<IParticleEffect> m_pProximityParticle;
	_smart_ptr<IParticleEffect> m_pExplodeParticle;
	_smart_ptr<IParticleEffect> m_pSpawnedByWeaverParticle;
	_smart_ptr<IParticleEffect> m_pEnergizedParticle;
	ArkAudioTrigger m_followStartAudio;
	ArkAudioTrigger m_followStopAudio;
	ArkAudioTrigger m_attackStartAudio;
	ArkAudioTrigger m_attackStopAudio;
	ArkAudioTrigger m_explodeAudio;
	ArkAudioTrigger m_damagePlayerAudio;
	ArkAudioTrigger m_existStartAudio;
	ArkAudioTrigger m_existStopAudio;
	std::vector<unsigned __int64> m_energizeSignals;
	std::vector<unsigned __int64> m_stunSignals;
	
	ArkCystoidProperties();
	~ArkCystoidProperties();
	void LoadProperties(IEntityArchetype *_pArchetype) { FLoadProperties(this,_pArchetype); }
	float GetAttackRange(const unsigned &_target, const bool _bZeroG) const { return FGetAttackRange(this,_target,_bZeroG); }
	float GetRandomImpulseDelay(const bool _bZeroG) const { return FGetRandomImpulseDelay(this,_bZeroG); }
	bool IsEnergizeSignal(const uint64_t &_signal) const { return FIsEnergizeSignal(this,_signal); }
	bool IsStunSignal(const uint64_t &_signal) const { return FIsStunSignal(this,_signal); }
	
#if 0
	void ClearReferences();
	float GetExplodeDelay() const;
	float GetEnergizeDuration() const;
	float GetLureDelay() const;
	float GetTargetRefreshDelay() const;
	float GetInvalidTargetDelay() const;
	float GetStunDuration() const;
	float GetMovementPeriod() const;
	float GetMaxTimeOffGround() const;
	float GetMaxSpeed(const bool arg0) const;
	float GetMinSpeed(const bool arg0) const;
	float GetDeceleration(const bool arg0) const;
	float GetExplosionImpulse(const bool arg0) const;
	float GetHomingRange(const bool arg0) const;
	float GetDeactivationRange(const bool arg0) const;
	float GetDamageRange(const bool arg0) const;
	float GetOuterDamageRange(const bool arg0) const;
	float GetInnerImpulseRange(const bool arg0) const;
	float GetOuterImpulseRange(const bool arg0) const;
	uint64_t GetCameraShakeId(const bool arg0) const;
	float GetFlockingTetherRangeSq(const bool arg0) const;
	float GetTargetSpeedThresholdSq(const bool arg0) const;
	float GetPlayerSpeedThresholdSq(const bool arg0) const;
	float GetCystoidSpeedThresholdSq(const bool arg0) const;
	float GetRandomImpulseMagnitude(const bool arg0) const;
	std::vector<unsigned __int64> const &GetEnergizeSignals() const;
	std::vector<unsigned __int64> const &GetStunSignals() const;
	bool ShouldPhysicalize() const;
	bool IsRigidBody() const;
	float GetMass() const;
	float GetDensity() const;
	const char *GetModelName() const;
	uint64_t GetDamageSignal() const;
	uint64_t GetEnergizedDamageSignal() const;
	uint64_t GetNullWaveSignal() const;
	uint64_t GetLureSignal() const;
	float GetNullWaveDeaccumulation() const;
	ArkSignalSystem::Data::SignalGroupData const *GetDamageSignalGroup() const;
	ArkSignalSystem::Data::SignalGroupData const *GetTriggerSignalGroup() const;
	uint64_t GetFactionId() const;
	std::vector<unsigned __int64> const &GetTagsToIgnore() const;
	IParticleEffect *GetActiveParticle() const;
	IParticleEffect *GetDormantParticle() const;
	IParticleEffect *GetProxmityParticle() const;
	IParticleEffect *GetExplodeParticle() const;
	IParticleEffect *GetSpawnedByWeaverParticle() const;
	IParticleEffect *GetEnergizedParticle() const;
	ArkAudioTrigger const &GetFollowStartAudio() const;
	ArkAudioTrigger const &GetFollowStopAudio() const;
	ArkAudioTrigger const &GetAttackStartAudio() const;
	ArkAudioTrigger const &GetAttackStopAudio() const;
	ArkAudioTrigger const &GetExplodeAudio() const;
	ArkAudioTrigger const &GetDamagePlayerAudio() const;
	ArkAudioTrigger const &GetExistStartAudio() const;
	ArkAudioTrigger const &GetExistStopAudio() const;
#endif
	
	static inline auto FBitNotArkCystoidProperties = PreyFunction<void(ArkCystoidProperties *const _this)>(0x14E1EE0);
	static inline auto FLoadProperties = PreyFunction<void(ArkCystoidProperties *const _this, IEntityArchetype *_pArchetype)>(0x14E3230);
	static inline auto FGetAttackRange = PreyFunction<float(ArkCystoidProperties const *const _this, const unsigned &_target, const bool _bZeroG)>(0x14E2CF0);
	static inline auto FGetRandomImpulseDelay = PreyFunction<float(ArkCystoidProperties const *const _this, const bool _bZeroG)>(0x141AC10);
	static inline auto FIsEnergizeSignal = PreyFunction<bool(ArkCystoidProperties const *const _this, const uint64_t &_signal)>(0x14E2F90);
	static inline auto FIsStunSignal = PreyFunction<bool(ArkCystoidProperties const *const _this, const uint64_t &_signal)>(0x14E3090);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/cystoid/ArkCystoidPotentialTarget.h>
#include <_unknown/Functor1wRet.h>

class ArkCystoid;
enum class ArkGameSaveVersion;
struct IEntity;
struct IEntityArchetype;
struct IParticleEffect;

// ArkCystoidProperties
// Header:  Prey/GameDll/ark/cystoid/ArkCystoidManager.h
class ArkCystoidProperties
{ // Size=440 (0x1B8)
public:
	// ArkCystoidProperties::GravityDependentProperties
	// Header:  Prey/GameDll/ark/cystoid/ArkCystoidManager.h
	class GravityDependentProperties
	{ // Size=80 (0x50)
	public:
		float m_explosionImpulse;
		float m_maxSpeed;
		float m_minSpeed;
		float m_deceleration;
		float m_homingRange;
		float m_deactivationRange;
		float m_enemyAttackRange;
		float m_damageRange;
		float m_damageRangeOuter;
		float m_innerImpulseRange;
		float m_outerImpulseRange;
		float m_flockingTetherRangeSq;
		float m_targetSpeedThresholdSq;
		float m_playerSpeedThresholdSq;
		float m_cystoidSpeedThresholdSq;
		float m_randomImpulseMinDelay;
		float m_randomImpulseMaxDelay;
		float m_randomImpulseMagnitude;
		uint64_t m_cameraShakeId;

	#if 0
		GravityDependentProperties();
	#endif
	};

	float m_energizedAttackRange;
	float m_explodeDelay;
	float m_energizeDuration;
	float m_lureDelay;
	float m_targetRefreshDelay;
	float m_invalidTargetDelay;
	float m_stunDuration;
	float m_minMovementPeriod;
	float m_maxMovementPeriod;
	float m_nullWaveDeaccumulation;
	float m_maxTimeOffGround;
	uint64_t m_damageSignal;
	uint64_t m_energizedDamageSignal;
	uint64_t m_nullWaveSignal;
	uint64_t m_lureSignal;
	const ArkSignalSystem::Data::SignalGroupData* m_pDamageSignalGroup;
	const ArkSignalSystem::Data::SignalGroupData* m_pTriggerSignalGroup;
	uint64_t m_factionId;
	std::vector<uint64_t> m_tagsToIgnore;
	ArkCystoidProperties::GravityDependentProperties m_oneGProperties;
	ArkCystoidProperties::GravityDependentProperties m_zeroGProperties;
	string m_modelName;
	bool m_physicalize;
	bool m_rigidBody;
	float m_mass;
	float m_density;
	_smart_ptr<IParticleEffect> m_pActiveParticle;
	_smart_ptr<IParticleEffect> m_pDormantParticle;
	_smart_ptr<IParticleEffect> m_pProximityParticle;
	_smart_ptr<IParticleEffect> m_pExplodeParticle;
	_smart_ptr<IParticleEffect> m_pSpawnedByWeaverParticle;
	_smart_ptr<IParticleEffect> m_pEnergizedParticle;
	ArkAudioTrigger m_followStartAudio;
	ArkAudioTrigger m_followStopAudio;
	ArkAudioTrigger m_attackStartAudio;
	ArkAudioTrigger m_attackStopAudio;
	ArkAudioTrigger m_explodeAudio;
	ArkAudioTrigger m_damagePlayerAudio;
	ArkAudioTrigger m_existStartAudio;
	ArkAudioTrigger m_existStopAudio;
	std::vector<uint64_t> m_energizeSignals;
	std::vector<uint64_t> m_stunSignals;

	ArkCystoidProperties();
	~ArkCystoidProperties();
	void LoadProperties(IEntityArchetype* _pArchetype) { FLoadProperties(this, _pArchetype); }
	float GetAttackRange(const unsigned& _target, const bool _bZeroG) const { return FGetAttackRange(this, _target, _bZeroG); }
	float GetRandomImpulseDelay(const bool _bZeroG) const { return FGetRandomImpulseDelay(this, _bZeroG); }
	bool IsEnergizeSignal(const uint64_t& _signal) const { return FIsEnergizeSignal(this, _signal); }
	bool IsStunSignal(const uint64_t& _signal) const { return FIsStunSignal(this, _signal); }

#if 0
	void ClearReferences();
	float GetExplodeDelay() const;
	float GetEnergizeDuration() const;
	float GetLureDelay() const;
	float GetTargetRefreshDelay() const;
	float GetInvalidTargetDelay() const;
	float GetStunDuration() const;
	float GetMovementPeriod() const;
	float GetMaxTimeOffGround() const;
	float GetMaxSpeed(const bool _arg0_) const;
	float GetMinSpeed(const bool _arg0_) const;
	float GetDeceleration(const bool _arg0_) const;
	float GetExplosionImpulse(const bool _arg0_) const;
	float GetHomingRange(const bool _arg0_) const;
	float GetDeactivationRange(const bool _arg0_) const;
	float GetDamageRange(const bool _arg0_) const;
	float GetOuterDamageRange(const bool _arg0_) const;
	float GetInnerImpulseRange(const bool _arg0_) const;
	float GetOuterImpulseRange(const bool _arg0_) const;
	uint64_t GetCameraShakeId(const bool _arg0_) const;
	float GetFlockingTetherRangeSq(const bool _arg0_) const;
	float GetTargetSpeedThresholdSq(const bool _arg0_) const;
	float GetPlayerSpeedThresholdSq(const bool _arg0_) const;
	float GetCystoidSpeedThresholdSq(const bool _arg0_) const;
	float GetRandomImpulseMagnitude(const bool _arg0_) const;
	const std::vector<uint64_t>& GetEnergizeSignals() const;
	const std::vector<uint64_t>& GetStunSignals() const;
	bool ShouldPhysicalize() const;
	bool IsRigidBody() const;
	float GetMass() const;
	float GetDensity() const;
	const char* GetModelName() const;
	uint64_t GetDamageSignal() const;
	uint64_t GetEnergizedDamageSignal() const;
	uint64_t GetNullWaveSignal() const;
	uint64_t GetLureSignal() const;
	float GetNullWaveDeaccumulation() const;
	const ArkSignalSystem::Data::SignalGroupData* GetDamageSignalGroup() const;
	const ArkSignalSystem::Data::SignalGroupData* GetTriggerSignalGroup() const;
	uint64_t GetFactionId() const;
	const std::vector<uint64_t>& GetTagsToIgnore() const;
	IParticleEffect* GetActiveParticle() const;
	IParticleEffect* GetDormantParticle() const;
	IParticleEffect* GetProxmityParticle() const;
	IParticleEffect* GetExplodeParticle() const;
	IParticleEffect* GetSpawnedByWeaverParticle() const;
	IParticleEffect* GetEnergizedParticle() const;
	const ArkAudioTrigger& GetFollowStartAudio() const;
	const ArkAudioTrigger& GetFollowStopAudio() const;
	const ArkAudioTrigger& GetAttackStartAudio() const;
	const ArkAudioTrigger& GetAttackStopAudio() const;
	const ArkAudioTrigger& GetExplodeAudio() const;
	const ArkAudioTrigger& GetDamagePlayerAudio() const;
	const ArkAudioTrigger& GetExistStartAudio() const;
	const ArkAudioTrigger& GetExistStopAudio() const;
#endif

	static inline auto FArkCystoidPropertiesOv1 = PreyFunction<void(ArkCystoidProperties* const _this)>(0x15FD5E0);
	static inline auto FBitNotArkCystoidProperties = PreyFunction<void(ArkCystoidProperties* const _this)>(0x15FD740);
	static inline auto FLoadProperties = PreyFunction<void(ArkCystoidProperties* const _this, IEntityArchetype* _pArchetype)>(0x15FEAB0);
	static inline auto FGetAttackRange = PreyFunction<float(const ArkCystoidProperties* const _this, const unsigned& _target, const bool _bZeroG)>(0x15FE560);
	static inline auto FGetRandomImpulseDelay = PreyFunction<float(const ArkCystoidProperties* const _this, const bool _bZeroG)>(0x1530AA0);
	static inline auto FIsEnergizeSignal = PreyFunction<bool(const ArkCystoidProperties* const _this, const uint64_t& _signal)>(0x15FE800);
	static inline auto FIsStunSignal = PreyFunction<bool(const ArkCystoidProperties* const _this, const uint64_t& _signal)>(0x15FE900);
};

// ArkCystoidManager
// Header:  Prey/GameDll/ark/cystoid/ArkCystoidManager.h
class ArkCystoidManager
{ // Size=200 (0xC8)
public:
	// ArkCystoidManager::LOSSource
	// Header:  Prey/GameDll/ark/cystoid/ArkCystoidManager.h
	class LOSSource
	{ // Size=24 (0x18)
	public:
		const IEntity* m_pEntity;
		Vec3 m_pos;

	#if 0
		LOSSource(const IEntity* _arg0_);
		bool operator==(const IEntity* const _arg0_) const;
		bool operator==(const unsigned _arg0_) const;
	#endif
	};

	// ArkCystoidManager::CystoidInfo
	// Header:  Prey/GameDll/ark/cystoid/ArkCystoidManager.h
	class CystoidInfo
	{ // Size=24 (0x18)
	public:
		unsigned m_cystoidId;
		ArkCystoid* m_pCystoidExtension;
		float m_lastUpdateTime;

	#if 0
		CystoidInfo();
		CystoidInfo(const unsigned& _arg0_);
		CystoidInfo(const unsigned& _arg0_, ArkCystoid* _arg1_, float _arg2_);
		ArkCystoid* GetCystoidExtension() const;
		bool operator==(const ArkCystoidManager::CystoidInfo& _arg0_) const;
		float GetLastUpdateTime() const;
		void SetLastUpdateTime(float _arg0_);
		unsigned GetCystoidId() const;
		void Serialize(TSerialize _arg0_);
		void PostSerialize();
	#endif
	};

	using ValidTargetCallback = Functor1wRet<unsigned int,bool>;

	std::vector<std::pair<unsigned int, unsigned int>> m_cystoidsToUnregister;
	unsigned m_lastSwarmUpdated;
	bool m_bUpdating;
	bool m_bEnabled;
	ArkAutoResetTimer m_swarmBalanceTimer;
	int m_maxExpectedCystoidsInArea;
	int m_nestZeroGUpdateSlice;
	std::vector<unsigned int> m_pendingExplosions;
	std::unordered_map<uint64_t, ArkCystoidProperties> m_properties;
	std::unordered_map<unsigned int, std::vector<ArkCystoidManager::CystoidInfo>> m_swarms;

	ArkCystoidManager();
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void RegisterCystoid(const unsigned& _cystoidId, ArkCystoid* const _pCystoidExtension) { FRegisterCystoid(this, _cystoidId, _pCystoidExtension); }
	void UnRegisterCystoid(const unsigned& _cystoidId, const unsigned& _swarmLeader) { FUnRegisterCystoid(this, _cystoidId, _swarmLeader); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	bool IsEnergizedCystoid(const unsigned& _target) const { return FIsEnergizedCystoid(this, _target); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void BroadcastTargetChangeToSwarm(unsigned _swarmLeader, unsigned _newTarget) const { FBroadcastTargetChangeToSwarm(this, _swarmLeader, _newTarget); }
	void BroadcastActiveStateToSwarm(unsigned _swarmLeader, bool _bActive, bool _bForce) const { FBroadcastActiveStateToSwarm(this, _swarmLeader, _bActive, _bForce); }
	bool IsCystoidInSwarm(unsigned _cystoidId, unsigned _swarmLeader) const { return FIsCystoidInSwarm(this, _cystoidId, _swarmLeader); }
	void RequestSpaceForCystoids(int _numCystoidsRequested, bool _bImmediate) { FRequestSpaceForCystoids(this, _numCystoidsRequested, _bImmediate); }
	bool IsPotentialTarget(unsigned _targetId, bool _bFromCollision, bool _bInZeroG, const std::vector<uint64_t>& _tagsToIgnore) const { return FIsPotentialTarget(this, _targetId, _bFromCollision, _bInZeroG, _tagsToIgnore); }
	int GetMaxExpectedCystoidsInArea() const { return FGetMaxExpectedCystoidsInArea(this); }
	unsigned PickBestTarget(std::vector<ArkCystoidPotentialTarget>& _potentialTargets, const IEntity* _pSource, float _speedThresholdSq, float _playerSpeedThresholdSq, float _cystoidSpeedThresholdSq, Functor1wRet<unsigned int,bool> _targetTest, unsigned _nestEntity) const { return FPickBestTarget(this, _potentialTargets, _pSource, _speedThresholdSq, _playerSpeedThresholdSq, _cystoidSpeedThresholdSq, _targetTest, _nestEntity); }
	std::vector<unsigned int> GetCystoids() const { alignas(std::vector<unsigned int>) std::byte _return_buf_[sizeof(std::vector<unsigned int>)]; return *FGetCystoids(this, reinterpret_cast<std::vector<unsigned int>*>(_return_buf_)); }
	void RequestExplosion(const unsigned _cystoid) { FRequestExplosion(this, _cystoid); }
	void LoadProperties() { FLoadProperties(this); }
	void ClearReferences() { FClearReferences(this); }
	void UnRegisterCystoid_Internal(const unsigned _cystoidId, const unsigned _swarmLeader) { FUnRegisterCystoid_Internal(this, _cystoidId, _swarmLeader); }
	void AddToSwarm(ArkCystoidManager::CystoidInfo& _info) { FAddToSwarm(this, _info); }

#if 0
	bool IsCystoidRegistered(const unsigned& _arg0_) const;
	unsigned GetSwarmLeader(const unsigned& _arg0_) const;
	void PostSerialize(ArkGameSaveVersion _arg0_);
	void SetEnabled(bool _arg0_);
	bool IsEnabled() const;
	int GetIndexOfCystoidToUnregister(unsigned _arg0_) const;
	int GetNumCystoids() const;
	void RebalanceSwarms();
#endif

	static inline auto FArkCystoidManagerOv2 = PreyFunction<void(ArkCystoidManager* const _this)>(0x15FD4F0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkCystoidManager* const _this)>(0x15FFCA0);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkCystoidManager* const _this)>(0x15FFCC0);
	static inline auto FReset = PreyFunction<void(ArkCystoidManager* const _this, bool _bEnteringGameMode)>(0x1600AF0);
	static inline auto FRegisterCystoid = PreyFunction<void(ArkCystoidManager* const _this, const unsigned& _cystoidId, ArkCystoid* const _pCystoidExtension)>(0x16003E0);
	static inline auto FUnRegisterCystoid = PreyFunction<void(ArkCystoidManager* const _this, const unsigned& _cystoidId, const unsigned& _swarmLeader)>(0x1600D30);
	static inline auto FUpdate = PreyFunction<void(ArkCystoidManager* const _this, const float _frameTime)>(0x1600F70);
	static inline auto FIsEnergizedCystoid = PreyFunction<bool(const ArkCystoidManager* const _this, const unsigned& _target)>(0x15FE830);
	static inline auto FSerialize = PreyFunction<void(ArkCystoidManager* const _this, TSerialize _ser)>(0x1600B20);
	static inline auto FBroadcastTargetChangeToSwarm = PreyFunction<void(const ArkCystoidManager* const _this, unsigned _swarmLeader, unsigned _newTarget)>(0x15FE370);
	static inline auto FBroadcastActiveStateToSwarm = PreyFunction<void(const ArkCystoidManager* const _this, unsigned _swarmLeader, bool _bActive, bool _bForce)>(0x15FE250);
	static inline auto FIsCystoidInSwarm = PreyFunction<bool(const ArkCystoidManager* const _this, unsigned _cystoidId, unsigned _swarmLeader)>(0x15FE700);
	static inline auto FRequestSpaceForCystoids = PreyFunction<void(ArkCystoidManager* const _this, int _numCystoidsRequested, bool _bImmediate)>(0x1600710);
	static inline auto FIsPotentialTarget = PreyFunction<bool(const ArkCystoidManager* const _this, unsigned _targetId, bool _bFromCollision, bool _bInZeroG, const std::vector<uint64_t>& _tagsToIgnore)>(0x15FE870);
	static inline auto FGetMaxExpectedCystoidsInArea = PreyFunction<int(const ArkCystoidManager* const _this)>(0x13BEF60);
	static inline auto FPickBestTarget = PreyFunction<unsigned(const ArkCystoidManager* const _this, std::vector<ArkCystoidPotentialTarget>& _potentialTargets, const IEntity* _pSource, float _speedThresholdSq, float _playerSpeedThresholdSq, float _cystoidSpeedThresholdSq, Functor1wRet<unsigned int,bool> _targetTest, unsigned _nestEntity)>(0x15FFCD0);
	static inline auto FGetCystoids = PreyFunction<std::vector<unsigned int>*(const ArkCystoidManager* const _this, std::vector<unsigned int>* _return_value_)>(0x15FE620);
	static inline auto FRequestExplosion = PreyFunction<void(ArkCystoidManager* const _this, const unsigned _cystoid)>(0x16006F0);
	static inline auto FLoadProperties = PreyFunction<void(ArkCystoidManager* const _this)>(0x15FE930);
	static inline auto FClearReferences = PreyFunction<void(ArkCystoidManager* const _this)>(0x15FE480);
	static inline auto FUnRegisterCystoid_Internal = PreyFunction<void(ArkCystoidManager* const _this, const unsigned _cystoidId, const unsigned _swarmLeader)>(0x1600D50);
	static inline auto FAddToSwarm = PreyFunction<void(ArkCystoidManager* const _this, ArkCystoidManager::CystoidInfo& _info)>(0x15FDEC0);
};
#endif // !MOONCRASH
