// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/ArkGooSignalReceiver.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>

class ArkSafeScriptTable;
class ArkWeaponUtils;
struct EventPhysCollision;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct IMaterial;
struct IPhysicalEntity;
struct IStatObj;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectilegoo.h
class CArkProjectileGoo : public CArkProjectile // Id=801601F Size=1640
{
public:
	enum class EArkGooState
	{
		none = 0,
		adding = 1,
		locked = 2,
	};

	struct ArkGooSpawnParameters // Id=8016020 Size=80
	{
		unsigned m_projectileId;
		string m_weaponClassName;
		int m_hitPhysicsId;
		unsigned m_spawnerId;
		unsigned m_ownerId;
		Vec3 m_finalPoint;
		Vec3 m_spawnDirection;
		int m_partId;
		float m_spawnSize;
		float m_speedScale;
		int m_surfaceIndex;
		int m_attachedPhysicsId;
		bool m_bTerrain;
		
		void FullSerialize(TSerialize _ser) { FFullSerialize(this,_ser); }
		
		static inline auto FFullSerialize = PreyFunction<void(CArkProjectileGoo::ArkGooSpawnParameters *const _this, TSerialize _ser)>(0x164E670);
	};

	struct GooSpawningProperties // Id=8016021 Size=20
	{
		float m_gooImpulseApplied;
		float m_gooMovementSpeed;
		float m_offsetAttachOfInitialSpawn;
		ArkInterval<float> m_gooAttachOffsetAsPercentScaleRange;
	};

	CArkProjectileGoo::GooSpawningProperties m_spawnProperties;
	bool m_bAutomaticallyScaleInitial;
	bool m_bStopFiringOnBurst;
	int m_maxNumberGooBallsToSpawn;
	unsigned m_decalId;
	float m_offsetFromCenterBurstPercentScale;
	float m_gooSpawnScaleFactor;
	float m_gooSpawnConeAngleSpread;
	float m_gooSpawnRandomSpread;
	float m_timeCurrentScale;
	float m_timeBeforeEachChildBursts;
	float m_gooPercentOfOverlapBeforeCombine;
	float m_timeToMinDelayForGooSpawn;
	float m_gooMinSpawnDelay;
	float m_gooPenetrationAllowedBeforeDestroying;
	float m_maxCollisionDamage;
	float m_collisionDamageScale;
	float m_gooCollisionDamageSpeed;
	float m_gooMass;
	float m_gooAOEScaleFactor;
	string m_scaleUpMaterial;
	ArkInterval<float> m_timeToScaleChildrenRange;
	ArkInterval<float> m_timeToScaleAutomaticallyRange;
	ArkInterval<float> m_finalScaleStaticRange;
	ArkInterval<float> m_finalScaleDynamicRange;
	ArkInterval<float> m_initialScaleStaticRange;
	ArkInterval<float> m_initialScaleDynamicRange;
	uint64_t m_collisionSignalPackage;
	uint64_t m_hardenedGooSignalPackage;
	uint64_t m_maxedGooSignalPackage;
	static float k_playerMinDistanceToPush;
	static float k_playerPushSpeed;
	static float k_playerPushAngle;
	static float k_minGooBallSize;
	static float k_ratioOuterToInnerSpheres;
	CArkProjectileGoo::EArkGooState m_state;
	bool m_bAmmoIsPooled;
	float m_spawnSize;
	float m_initialScale;
	float m_currentScale;
	float m_finalScale;
	ArkSimpleTimer m_startScaleTimer;
	float m_timeToScaleChildren;
	float m_timeToAutoScale;
	ArkSimpleTimer m_lockingTimer;
	ArkSimpleTimer m_burstAndSpawnTimer;
	ArkSimpleTimer m_blendTimer;
	bool m_bConstrained;
	int m_constraintId;
	int m_gooNetworkId;
	int m_surfaceIndex;
	bool m_bNeedBursting;
	Vec3 m_initialNormalLocal;
	Vec3 m_initialPositionLocal;
	Vec3 m_finalPosition;
	bool m_bIsStatic;
	bool m_bAttachedToMovableStatic;
	int m_staticPhysicsId;
	int m_attachedPhysicsId;
	int m_attachedPartId;
	bool m_bAttachedTerrain;
	AABB m_regenNavMeshAABB;
	bool m_bHasRegeneratedNavMesh;
	IMaterial *m_pMaterial;
	IMaterial *m_pClonedScaleUpMaterial;
	unsigned m_spawnerId;
	ArkSimpleTimer m_spawnChildrenTimer;
	float m_offsetPercent;
	ArkEntityEffect m_burstAndSpawnEffect;
	ArkEntityEffect m_lockedEffect;
	std::vector<CArkProjectileGoo::ArkGooSpawnParameters> m_spawningGooList;
	ArkGooSignalReceiver m_signalReceiver;
	static IStatObj *m_pStaticGooMesh;
	static IStatObj *m_pDynamicGooMesh;
	CArkProjectile::ArkProjectileFFEffect m_collisionLockedEffect;
	CArkProjectile::ArkProjectileFFEffect m_collisionNotLockedEffect;
	
	CArkProjectileGoo();
	virtual ~CArkProjectileGoo();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _auth);
	virtual const void *GetRMIBase() const;
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void ReInitFromPool();
	static CArkProjectileGoo *SpawnProjectileGoo(CArkProjectileGoo::ArkGooSpawnParameters const &_gooSpawnParams, const bool _bAmmoIsPooled) { return FSpawnProjectileGoo(_gooSpawnParams,_bAmmoIsPooled); }
	static CArkProjectileGoo *GetProjectileGooFromEntityId(const unsigned _entityId) { return FGetProjectileGooFromEntityId(_entityId); }
	static CArkProjectileGoo *GetProjectileGooFromEntity(IEntity const *const _pEntity) { return FGetProjectileGooFromEntity(_pEntity); }
	void IncreaseGoo() { FIncreaseGoo(this); }
	void SetCurrentScale(const float _newScale, const bool _bCanBurst) { FSetCurrentScale(this,_newScale,_bCanBurst); }
	int AddToNetwork(const int _networkId) { return FAddToNetwork(this,_networkId); }
	void ChangeState(CArkProjectileGoo::EArkGooState _state) { FChangeState(this,_state); }
	bool BurstAndSpawnGoo() { return FBurstAndSpawnGoo(this); }
	void UpdateFinalPosition(Vec3 const &_finalPosition) { FUpdateFinalPosition(this,_finalPosition); }
	Vec3 GetWorldInitialNormal() const { return FGetWorldInitialNormal(this); }
	bool OnCollision(IPhysicalEntity *const _pTargetPhysics, Vec3 const &_position, Vec3 const &_normal, const float _impulseAmount, const int _partId, const int _surfaceIdx) { return FOnCollision(this,_pTargetPhysics,_position,_normal,_impulseAmount,_partId,_surfaceIdx); }
	void DoCollisionDamage(EventPhysCollision const *const pCollision, IEntity *pInstigator, const int targetIndex) { FDoCollisionDamage(this,pCollision,pInstigator,targetIndex); }
	void TakeDamage(const float _damage, const unsigned _instigatorId, const bool _bExplosion) { FTakeDamage(this,_damage,_instigatorId,_bExplosion); }
	virtual void Destroy(const bool _bDeleting, const bool _bDestroyImmediate);
	virtual void StartDestroy();
	void SwitchToStaticPhysics() { FSwitchToStaticPhysics(this); }
	virtual void LoadCachedProperties();
	void SetupScaleValues(const int _physicsId) { FSetupScaleValues(this,_physicsId); }
	void StopScalingAndMoving() { FStopScalingAndMoving(this); }
	void SendOutMaxGooPackage(const float _scale) { FSendOutMaxGooPackage(this,_scale); }
	virtual void Physicalize(string const &_physicsType);
	virtual string GetModelFilename(ArkSafeScriptTable const &_propertiesTable);
	virtual void LoadModel();
	virtual void CheckForCheapParticleUse();
	bool IsOverlapping(Vec3 const &_position, const float _scale) { return FIsOverlapping(this,_position,_scale); }
	void UpdateBlendTimer() { FUpdateBlendTimer(this); }
	void StateUpdate(SEntityUpdateContext const &_ctx) { FStateUpdate(this,_ctx); }
	void StateEnter(CArkProjectileGoo::EArkGooState _state) { FStateEnter(this,_state); }
	bool TryToSpawnGoo(CArkProjectileGoo::ArkGooSpawnParameters const &_gooSpawnParams) { return FTryToSpawnGoo(this,_gooSpawnParams); }
	bool UpdateMovement(const float _frameTime) { return FUpdateMovement(this,_frameTime); }
	void SetupConstraint(IPhysicalEntity *_pOwnerPhysics, IPhysicalEntity *_pConstrainedEntityPhysics, Vec3 const &_position, const int _partId) { FSetupConstraint(this,_pOwnerPhysics,_pConstrainedEntityPhysics,_position,_partId); }
	boost::optional<float> CheckGooForCollisions(Vec3 const &_position, const float _scale, const int _entTypes) { return FCheckGooForCollisions(this,_position,_scale,_entTypes); }
	void AddGooToDynamicEntity(IPhysicalEntity *const _pEntityPhysics, const bool _bIsEntityStatic, IPhysicalEntity *const _pAttachedPhysics) { FAddGooToDynamicEntity(this,_pEntityPhysics,_bIsEntityStatic,_pAttachedPhysics); }
	static IPhysicalEntity *CheckCollisionForAttachEntity(Vec3 const &_position, const float _scale, const int _attachedPhysicsId, ArkWeaponUtils::PhysicsMaterialInfo &_materialInfo) { return FCheckCollisionForAttachEntity(_position,_scale,_attachedPhysicsId,_materialInfo); }
	
#if 0
	float GetMaxScale() const;
	bool IsMaxScale() const;
	bool IsLocked() const;
	void GrowGooToMaxSize();
	float GetCurrentScale() const;
	float GetFinalScale() const;
	void SetGooNetworkId(const int arg0);
	int GetGooNetworkId() const;
	IPhysicalEntity *GetConstrainedPhysicalEntity() const;
	Vec3 GetFinalPosition() const;
	void SetFinalPosition(Vec3 const &arg0);
	void CalculateFinalPosition(const float arg0, Vec3 const &arg1);
	void SetSpawnerId(unsigned arg0);
	float GetOffsetPercent() const;
	void SetOffsetPercent(const float arg0);
	Vec3 GetWorldInitialPosition() const;
	static float GetPlayerPushMinDistance();
	static float GetPlayerPushSpeed();
	static float GetPlayerPushAngle();
	Vec3 GetPositionOfTop() const;
	void EnableConstraint(const bool arg0);
	CArkProjectileGoo::GooSpawningProperties const &GetSpawnProperties() const;
	void CheckMaxScale();
	void SetIsStatic(const bool arg0);
	void UpdateBurstAndSpawnTimer(const float arg0);
	void AddToSpawnQueue(CArkProjectileGoo::ArkGooSpawnParameters const &arg0);
	void ResetNavMesh();
	boost::optional<float> CheckGooForCollisionsWithPlayers(Vec3 const &arg0, const float arg1, const int arg2);
	std::vector<CArkProjectileGoo const *> GetGooProjectilesInBox(Vec3 const &arg0, const float arg1) const;
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectileGoo const *const _this, ICrySizer *_s)>(0x164EED0);
	static inline auto FInit = PreyFunction<bool(CArkProjectileGoo *const _this, IGameObject *_pGameObject)>(0x165FDC0);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileGoo *const _this, IGameObject *_pGameObject)>(0x16515D0);
	static inline auto FInitClient = PreyFunction<void(CArkProjectileGoo *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkProjectileGoo *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkProjectileGoo *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkProjectileGoo *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkProjectileGoo *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1651E30);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileGoo *const _this, TSerialize _ser)>(0x164E7C0);
	static inline auto FNetSerialize = PreyFunction<bool(CArkProjectileGoo *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1651910);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkProjectileGoo *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkProjectileGoo *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGoo *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x1654470);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileGoo *const _this, SGameObjectEvent const &_event)>(0x164F230);
	static inline auto FProcessEvent = PreyFunction<void(CArkProjectileGoo *const _this, SEntityEvent &_event)>(0x1651B40);
	static inline auto FSetChannelId = PreyFunction<void(CArkProjectileGoo *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkProjectileGoo *const _this, bool _auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkProjectileGoo const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkProjectileGoo *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkProjectileGoo *const _this)>(0xA13080);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1651B80);
	static inline auto FSpawnProjectileGoo = PreyFunction<CArkProjectileGoo *(CArkProjectileGoo::ArkGooSpawnParameters const &_gooSpawnParams, const bool _bAmmoIsPooled)>(0x1652DB0);
	static inline auto FGetProjectileGooFromEntityId = PreyFunction<CArkProjectileGoo *(const unsigned _entityId)>(0x164F040);
	static inline auto FGetProjectileGooFromEntity = PreyFunction<CArkProjectileGoo *(IEntity const *const _pEntity)>(0x164F010);
	static inline auto FIncreaseGoo = PreyFunction<void(CArkProjectileGoo *const _this)>(0x164F4E0);
	static inline auto FSetCurrentScale = PreyFunction<void(CArkProjectileGoo *const _this, const float _newScale, const bool _bCanBurst)>(0x16525A0);
	static inline auto FAddToNetwork = PreyFunction<int(CArkProjectileGoo *const _this, const int _networkId)>(0x164C960);
	static inline auto FChangeState = PreyFunction<void(CArkProjectileGoo *const _this, CArkProjectileGoo::EArkGooState _state)>(0x164D240);
	static inline auto FBurstAndSpawnGoo = PreyFunction<bool(CArkProjectileGoo *const _this)>(0x164CA00);
	static inline auto FUpdateFinalPosition = PreyFunction<void(CArkProjectileGoo *const _this, Vec3 const &_finalPosition)>(0x1654610);
	static inline auto FGetWorldInitialNormal = PreyFunction<Vec3(CArkProjectileGoo const *const _this)>(0x164F0F0);
	static inline auto FOnCollision = PreyFunction<bool(CArkProjectileGoo *const _this, IPhysicalEntity *const _pTargetPhysics, Vec3 const &_position, Vec3 const &_normal, const float _impulseAmount, const int _partId, const int _surfaceIdx)>(0x1650C80);
	static inline auto FDoCollisionDamage = PreyFunction<void(CArkProjectileGoo *const _this, EventPhysCollision const *const pCollision, IEntity *pInstigator, const int targetIndex)>(0x164E300);
	static inline auto FTakeDamage = PreyFunction<void(CArkProjectileGoo *const _this, const float _damage, const unsigned _instigatorId, const bool _bExplosion)>(0x1654090);
	static inline auto FDestroy = PreyFunction<void(CArkProjectileGoo *const _this, const bool _bDeleting, const bool _bDestroyImmediate)>(0x164E140);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1653500);
	static inline auto FSwitchToStaticPhysics = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1653E80);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileGoo *const _this)>(0x164F850);
	static inline auto FSetupScaleValues = PreyFunction<void(CArkProjectileGoo *const _this, const int _physicsId)>(0x1652BC0);
	static inline auto FStopScalingAndMoving = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1653E20);
	static inline auto FSendOutMaxGooPackage = PreyFunction<void(CArkProjectileGoo *const _this, const float _scale)>(0x1651FB0);
	static inline auto FPhysicalize = PreyFunction<void(CArkProjectileGoo *const _this, string const &_physicsType)>(0x16513D0);
	static inline auto FGetModelFilename = PreyFunction<string(CArkProjectileGoo *const _this, ArkSafeScriptTable const &_propertiesTable)>(0x164EF50);
	static inline auto FLoadModel = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1650BE0);
	static inline auto FCheckForCheapParticleUse = PreyFunction<void(CArkProjectileGoo *const _this)>(0x164D830);
	static inline auto FIsOverlapping = PreyFunction<bool(CArkProjectileGoo *const _this, Vec3 const &_position, const float _scale)>(0x164F5C0);
	static inline auto FUpdateBlendTimer = PreyFunction<void(CArkProjectileGoo *const _this)>(0x1654500);
	static inline auto FStateUpdate = PreyFunction<void(CArkProjectileGoo *const _this, SEntityUpdateContext const &_ctx)>(0x16538C0);
	static inline auto FStateEnter = PreyFunction<void(CArkProjectileGoo *const _this, CArkProjectileGoo::EArkGooState _state)>(0x16535B0);
	static inline auto FTryToSpawnGoo = PreyFunction<bool(CArkProjectileGoo *const _this, CArkProjectileGoo::ArkGooSpawnParameters const &_gooSpawnParams)>(0x1654200);
	static inline auto FUpdateMovement = PreyFunction<bool(CArkProjectileGoo *const _this, const float _frameTime)>(0x1654860);
	static inline auto FSetupConstraint = PreyFunction<void(CArkProjectileGoo *const _this, IPhysicalEntity *_pOwnerPhysics, IPhysicalEntity *_pConstrainedEntityPhysics, Vec3 const &_position, const int _partId)>(0x16528B0);
	static inline auto FCheckGooForCollisions = PreyFunction<boost::optional<float>(CArkProjectileGoo *const _this, Vec3 const &_position, const float _scale, const int _entTypes)>(0x164D870);
	static inline auto FAddGooToDynamicEntity = PreyFunction<void(CArkProjectileGoo *const _this, IPhysicalEntity *const _pEntityPhysics, const bool _bIsEntityStatic, IPhysicalEntity *const _pAttachedPhysics)>(0x164C6A0);
	static inline auto FCheckCollisionForAttachEntity = PreyFunction<IPhysicalEntity *(Vec3 const &_position, const float _scale, const int _attachedPhysicsId, ArkWeaponUtils::PhysicsMaterialInfo &_materialInfo)>(0x164D250);
};

