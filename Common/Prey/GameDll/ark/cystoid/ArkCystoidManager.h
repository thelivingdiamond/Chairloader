// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/Ark/arksignalsystemdata.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arksimpletimer.h>
#include <Prey/GameDll/ark/cystoid/arkcystoidmanager.h>

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
	~ArkCystoidProperties() { FBitNotArkCystoidProperties(this); }
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

