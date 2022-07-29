// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkMaterialAnimationManager.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/arksimpletimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/player/IArkEtherDuplicateListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerCarryListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerCombatListener.h>
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerEntry.h>

namespace ArkSignalSystem
{
class Data;
class Package;
} // namespace ArkSignalSystem
class ICrySizer;
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkApexTentacle.h
class ArkApexTentacle : public ArkEnvironmentalObject, public IArkPlayerCarryListener, public IArkPlayerCombatListener, public IArkEtherDuplicateListener, public IEntityEventListener // Id=801608B Size=1264
{
public:
	class SegmentInfo // Id=8016091 Size=40
	{
	public:
		int m_jointId;
		int m_breadcrumbIndex;
		float m_breadcrumbDist;
		Vec3 m_position;
		Quat m_rotation;
		
		Vec3 GetWorldPos(IEntity *_pEntity) const { return FGetWorldPos(this,_pEntity); }
		Quat GetWorldRotation(IEntity *_pEntity) const { return FGetWorldRotation(this,_pEntity); }
		
#if 0
		void Serialize(TSerialize arg0);
		void Invalidate();
#endif
		
		static inline auto FGetWorldPos = PreyFunction<Vec3(ArkApexTentacle::SegmentInfo const *const _this, IEntity *_pEntity)>(0x1264130);
		static inline auto FGetWorldRotation = PreyFunction<Quat(ArkApexTentacle::SegmentInfo const *const _this, IEntity *_pEntity)>(0x12641F0);
	};

	struct HazardTarget // Id=8016092 Size=24
	{
		IEntity *m_pTarget;
		Vec3 m_pos;
		
#if 0
		bool operator==(ArkApexTentacle::HazardTarget const &arg0) const;
#endif
	};

	class Breadcrumb // Id=8016093 Size=24
	{
	public:
		Vec3 m_pos;
		float m_distToPrev;
		float m_roll;
		float m_frameTime;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	ArkMaterialAnimationManager m_materialAnimationManager;
	std::shared_ptr<IAnimationOperatorQueue> m_pJointLocationModifier;
	std::vector<ArkApexTentacle::Breadcrumb> m_breadcrumbs;
	std::vector<ArkApexTentacle::SegmentInfo> m_segments;
	std::vector<unsigned int> m_potentialTargets;
	std::vector<unsigned int> m_uniqueSignalPackages;
	ArkAutoResetTimer m_targetTimer;
	ArkAutoResetTimer m_pickClosestSegmentTimer;
	ArkAutoResetTimer m_movementNoiseXTimer;
	ArkAutoResetTimer m_movementNoiseZTimer;
	ArkAutoResetTimer m_movementRollTimer;
	ArkAutoResetTimer m_playerDamageTimer;
	ArkSimpleTimer m_revertToDefaultTimer;
	ArkSimpleTimer m_stunTimer;
	ArkSimpleTimer m_invalidTargetTimer;
	ArkSimpleTimer m_deathDelayForAudio;
	ArkRandomizedAutoResetTimer m_dissipationTimer;
	ArkFireAndForgetEffect m_dissipationVfx;
	Vec3 m_defaultTarget;
	Vec3 m_overrideDefaultTarget;
	unsigned m_target;
	unsigned m_spawner;
	unsigned m_headId;
	ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_ApexTentacle> m_spatialManagerEntry;
	float m_retractBreadcrumbDist;
	float m_retractRemainder;
	float m_currentRoll;
	float m_targetRoll;
	float m_overrideTargetRadius;
	float m_materialAnimTime;
	int m_retractBreadcrumb;
	int m_numUsedSegments;
	unsigned m_ticksUntilVisible;
	bool m_bStriking;
	bool m_bPlayerIsPotentialTarget;
	uint64_t m_hazardSignalPackage;
	uint64_t m_lureSignal;
	float m_perceptionRange;
	float m_tentacleRadius;
	float m_invalidTargetTimerDuration;
	float m_dissipationTimerDuration;
	float m_minSpeed;
	float m_speed;
	float m_retractSpeed;
	float m_maxTurnRadius;
	float m_headMaxTurnAngle;
	float m_damageCostPerSegment;
	float m_damageBleed;
	float m_targetSpeedThresholdSq;
	float m_segmentLength;
	float m_minMovementNoisePeriod;
	float m_maxMovementNoisePeriod;
	float m_movementNoiseMinTargetDist;
	float m_movementRoll;
	float m_minAdjustDistForRetract;
	float m_strikeRange;
	float m_strikeSpeed;
	float m_strikeRetractDist;
	int m_maxNumSegments;
	int m_defaultTargetNumSegments;
	int m_minSegmentsToRetract;
	int m_targetChangeRetractSegments;
	uint64_t m_dissipationMaterialAnim;
	string m_jointPrefix;
	string m_headAttachmentName;
	ArkSignalSystem::Data::SignalGroupData const *m_pDamagedSignalGroup;
	ArkSignalSystem::Data::SignalGroupData const *m_pStunnedSignalGroup;
	ArkAudioTrigger m_triggerExist;
	ArkAudioTrigger m_triggerDamage;
	ArkAudioTrigger m_triggerDissipation;
	ArkAudioTrigger m_triggerTargetChange;
	Vec3 m_defaultTargetOffset;
	
	ArkApexTentacle();
	virtual ~ArkApexTentacle();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void GetMemoryUsage(ICrySizer *_pSizer) const;
	void SetOverrideDefaultTarget(Vec3 const &_target, float _radius) { FSetOverrideDefaultTarget(this,_target,_radius); }
	void SetSpawner(unsigned _spawner) { FSetSpawner(this,_spawner); }
	unsigned GetCurrentTarget() const { return FGetCurrentTarget(this); }
	void SetTarget(unsigned _newTarget, bool _bInvalidateImmediately) { FSetTarget(this,_newTarget,_bInvalidateImmediately); }
	void PickBestTarget() { FPickBestTarget(this); }
	Vec3 GetHeadPosition() const { return FGetHeadPosition(this); }
	void OnCollisionEvent(IEntity *const _pCollidingEntity, Vec3 _collisionPos) { FOnCollisionEvent(this,_pCollidingEntity,_collisionPos); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void OnReceiveSignal(ArkSignalSystem::Package const &_package);
	virtual void RegisterForSignals(bool _bRegister);
	virtual void OnStopCarry(IEntity *const _pEntity, bool _bThrown);
	virtual void OnGrenadeThrown(IEntity *const _pGrenade);
	virtual void OnEtherDuplicateCreated(const unsigned _etherDuplicate);
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	void InitArea() const { FInitArea(this); }
	void HitTargetWithHazard(IEntity *_pTarget, Vec3 const &_pos, uint64_t _packageId, float _scale) const { FHitTargetWithHazard(this,_pTarget,_pos,_packageId,_scale); }
	Vec3 GetTargetPos() const { return FGetTargetPos(this); }
	void MoveToTarget(float _frameTime) { FMoveToTarget(this,_frameTime); }
	void RetractImmediate(unsigned _breadcrumbIndex) { FRetractImmediate(this,_breadcrumbIndex); }
	void RetractToSegmentClosestToTarget() { FRetractToSegmentClosestToTarget(this); }
	void UpdateJointLocations() { FUpdateJointLocations(this); }
	bool IsOverlappingPlayer() { return FIsOverlappingPlayer(this); }
	void UpdateSegmentLocation(ArkApexTentacle::SegmentInfo &_segment, bool _bIsHead, Matrix34 const &_invertedWorldTM) const { FUpdateSegmentLocation(this,_segment,_bIsHead,_invertedWorldTM); }
	void MoveSegments() { FMoveSegments(this); }
	void AddSegments() { FAddSegments(this); }
	void Dissipate() { FDissipate(this); }
	void DissipateSegment(ArkApexTentacle::SegmentInfo const &_segment) const { FDissipateSegment(this,_segment); }
	Vec3 GetAverageForwardVector(int _breadcrumbIndex) const { return FGetAverageForwardVector(this,_breadcrumbIndex); }
	void SetupHeadEntity() { FSetupHeadEntity(this); }
	
#if 0
	Vec3 const &GetOverrideDefaultTarget() const;
	bool HasPlayerAsPotentialTarget() const;
	bool HandleHypnotize(const unsigned arg0);
	void RetractOnTargetChange();
	void SpawnSegmentEntity();
	void MoveSegment(ArkApexTentacle::SegmentInfo &arg0, unsigned arg1, float arg2) const;
	float GetSpeedInLastSecond() const;
#endif
	
	static inline auto FBitNotArkApexTentacle = PreyFunction<void(ArkApexTentacle *const _this)>(0x1262810);
	static inline auto FInit = PreyFunction<bool(ArkApexTentacle *const _this, IGameObject *_pGameObject)>(0x1264950);
	static inline auto FPostInit = PreyFunction<void(ArkApexTentacle *const _this, IGameObject *_pGameObject)>(0x12688F0);
	static inline auto FFullSerialize = PreyFunction<void(ArkApexTentacle *const _this, TSerialize _ser)>(0x12635A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkApexTentacle *const _this)>(0x1268E80);
	static inline auto FUpdate = PreyFunction<void(ArkApexTentacle *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x1269CC0);
	static inline auto FProcessEvent = PreyFunction<void(ArkApexTentacle *const _this, SEntityEvent &_event)>(0x1268EC0);
	static inline auto FHandleEvent = PreyFunction<void(ArkApexTentacle *const _this, SGameObjectEvent const &_event)>(0x12646B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkApexTentacle const *const _this, ICrySizer *_pSizer)>(0x1263F00);
	static inline auto FSetOverrideDefaultTarget = PreyFunction<void(ArkApexTentacle *const _this, Vec3 const &_target, float _radius)>(0x1269880);
	static inline auto FSetSpawner = PreyFunction<void(ArkApexTentacle *const _this, unsigned _spawner)>(0x12698A0);
	static inline auto FGetCurrentTarget = PreyFunction<unsigned(ArkApexTentacle const *const _this)>(0x1263EA0);
	static inline auto FSetTarget = PreyFunction<void(ArkApexTentacle *const _this, unsigned _newTarget, bool _bInvalidateImmediately)>(0x12698B0);
	static inline auto FPickBestTarget = PreyFunction<void(ArkApexTentacle *const _this)>(0x1268440);
	static inline auto FGetHeadPosition = PreyFunction<Vec3(ArkApexTentacle const *const _this)>(0x1263EB0);
	static inline auto FOnCollisionEvent = PreyFunction<void(ArkApexTentacle *const _this, IEntity *const _pCollidingEntity, Vec3 _collisionPos)>(0x1267D60);
	static inline auto FOnReset = PreyFunction<void(ArkApexTentacle *const _this, bool _bEnteringGameMode)>(0x1268220);
	static inline auto FLoadProperties = PreyFunction<void(ArkApexTentacle *const _this)>(0x1264DE0);
	static inline auto FOnReceiveSignal = PreyFunction<void(ArkApexTentacle *const _this, ArkSignalSystem::Package const &_package)>(0x1267E40);
	static inline auto FRegisterForSignals = PreyFunction<void(ArkApexTentacle *const _this, bool _bRegister)>(0x1269160);
	static inline auto FOnStopCarry = PreyFunction<void(ArkApexTentacle *const _this, IEntity *const _pEntity, bool _bThrown)>(0x12683F0);
	static inline auto FOnGrenadeThrown = PreyFunction<void(ArkApexTentacle *const _this, IEntity *const _pGrenade)>(0x1267E30);
	static inline auto FOnEtherDuplicateCreated = PreyFunction<void(ArkApexTentacle *const _this, const unsigned _etherDuplicate)>(0x1267E10);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkApexTentacle *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x1267D90);
	static inline auto FInitArea = PreyFunction<void(ArkApexTentacle const *const _this)>(0x1264A40);
	static inline auto FHitTargetWithHazard = PreyFunction<void(ArkApexTentacle const *const _this, IEntity *_pTarget, Vec3 const &_pos, uint64_t _packageId, float _scale)>(0x1264750);
	static inline auto FGetTargetPos = PreyFunction<Vec3(ArkApexTentacle const *const _this)>(0x1264000);
	static inline auto FMoveToTarget = PreyFunction<void(ArkApexTentacle *const _this, float _frameTime)>(0x12662A0);
	static inline auto FRetractImmediate = PreyFunction<void(ArkApexTentacle *const _this, unsigned _breadcrumbIndex)>(0x1269290);
	static inline auto FRetractToSegmentClosestToTarget = PreyFunction<void(ArkApexTentacle *const _this)>(0x1269460);
	static inline auto FUpdateJointLocations = PreyFunction<void(ArkApexTentacle *const _this)>(0x126A540);
	static inline auto FIsOverlappingPlayer = PreyFunction<bool(ArkApexTentacle *const _this)>(0x1264AC0);
	static inline auto FUpdateSegmentLocation = PreyFunction<void(ArkApexTentacle const *const _this, ArkApexTentacle::SegmentInfo &_segment, bool _bIsHead, Matrix34 const &_invertedWorldTM)>(0x126A750);
	static inline auto FMoveSegments = PreyFunction<void(ArkApexTentacle *const _this)>(0x1266080);
	static inline auto FAddSegments = PreyFunction<void(ArkApexTentacle *const _this)>(0x1263080);
	static inline auto FDissipate = PreyFunction<void(ArkApexTentacle *const _this)>(0x12633D0);
	static inline auto FDissipateSegment = PreyFunction<void(ArkApexTentacle const *const _this, ArkApexTentacle::SegmentInfo const &_segment)>(0x12634E0);
	static inline auto FGetAverageForwardVector = PreyFunction<Vec3(ArkApexTentacle const *const _this, int _breadcrumbIndex)>(0x1263B20);
	static inline auto FSetupHeadEntity = PreyFunction<void(ArkApexTentacle *const _this)>(0x1269A00);
};

