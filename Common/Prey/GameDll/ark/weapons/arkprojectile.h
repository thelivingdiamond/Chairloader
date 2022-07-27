// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/arkscripttable.h>

class CArkWeapon;
struct EventPhysCollision;
class ICrySizer;
struct IEntityArchetype;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectile.h
class CArkProjectile : public CGameObjectExtensionHelper<CArkProjectile,IGameObjectExtension> // Id=8015F0A Size=664
{
public:
	enum class EArkProjectileTimer
	{
		lifetime = 272,
		hidetime = 273,
	};

	struct ArkProjectileEntityEffect // Id=8015F0D Size=280
	{
		ArkEntityEffect m_expensiveEffect;
		ArkEntityEffect m_cheapEffect;
		bool m_bUseCheapEffect;
		
		void LoadEntityEffect(ArkSafeScriptTable _properties, string _propertyName, const float _duration, const float _sizeScale) { FLoadEntityEffect(this,_properties,_propertyName,_duration,_sizeScale); }
		void Start(const bool _bUseCheap) { FStart(this,_bUseCheap); }
		void Kill() { FKill(this); }
		void SetLocalTM(Matrix34 const &_localTM) { FSetLocalTM(this,_localTM); }
		
#if 0
		void Stop();
#endif
		
		static inline auto FLoadEntityEffect = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect *const _this, ArkSafeScriptTable _properties, string _propertyName, const float _duration, const float _sizeScale)>(0x1647500);
		static inline auto FStart = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect *const _this, const bool _bUseCheap)>(0x164A500);
		static inline auto FKill = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect *const _this)>(0x16468C0);
		static inline auto FSetLocalTM = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect *const _this, Matrix34 const &_localTM)>(0x1648E30);
	};

	struct ArkProjectileFFEffect // Id=8015F0E Size=136
	{
		ArkFireAndForgetEffect m_expensiveEffect;
		ArkFireAndForgetEffect m_cheapEffect;
		bool m_bUseCheapEffect;
		float m_scale;
		
		void LoadFFEffect(ArkSafeScriptTable _properties, string _propertyName) { FLoadFFEffect(this,_properties,_propertyName); }
		void Start(const bool _bUseCheap, Vec3 const &_position, Vec3 const &_worldDirection, const float _scale) { FStart(this,_bUseCheap,_position,_worldDirection,_scale); }
		
		static inline auto FLoadFFEffect = PreyFunction<void(CArkProjectile::ArkProjectileFFEffect *const _this, ArkSafeScriptTable _properties, string _propertyName)>(0x1647670);
		static inline auto FStart = PreyFunction<void(CArkProjectile::ArkProjectileFFEffect *const _this, const bool _bUseCheap, Vec3 const &_position, Vec3 const &_worldDirection, const float _scale)>(0x164A550);
	};

	ArkSimpleTimer m_lifeTimer;
	bool m_isDestroying;
	bool m_bUseCheapEffects;
	ArkSimpleTimer m_destroyTimer;
	bool m_bIsPooled;
	bool m_bTracerIsPooled;
	bool m_bCollidesWithProjectile;
	bool m_bOverrideGravity;
	bool m_bAlignWithVelocity;
	bool m_bDestroyOnCollision;
	float m_speed;
	float m_speedFromCamera;
	std::vector<unsigned __int64> m_sneakAttackMetaTags;
	unsigned m_ownerFaction;
	ArkFireAndForgetEffect m_collisionEffect;
	CArkProjectile::ArkProjectileFFEffect m_explosionEffect;
	ArkSimpleTimer m_gravityTimer;
	unsigned m_ownerId;
	string m_weaponClassName;
	ArkSimpleTimer m_ownerNotCollidingTimer;
	uint64_t m_packageId;
	unsigned m_groupId;
	Vec3 m_spawnPosition;
	ArkEntityEffect m_projectileEffect;
	ArkEntityEffect m_trailEffect;
	static IEntityArchetype *m_pTracerArchetype;
	static unsigned s_groupIdGen;
	
	CArkProjectile();
	virtual ~CArkProjectile();
	virtual bool IsGrenade() const;
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
	virtual void SetOwnerIdAndWeaponClassName(const unsigned _ownerId, string const &_weaponName);
	static CArkProjectile *SpawnProjectile(IEntityArchetype *const _pArchetype, Vec3 const &_position, Vec3 const &_direction, const unsigned _ownerId, string _weaponClassName, const bool _bIsCritical, const bool _bIsPooled, const unsigned _extendedFlags, const unsigned _groupId, const bool _bSpawnFromCamera) { return FSpawnProjectile(_pArchetype,_position,_direction,_ownerId,_weaponClassName,_bIsCritical,_bIsPooled,_extendedFlags,_groupId,_bSpawnFromCamera); }
	virtual void Destroy(const bool _bDeleting, const bool _bDestroyImmediate);
	virtual void StartDestroy();
	void StartHiddenIfNecessary(const float _hideTime) { FStartHiddenIfNecessary(this,_hideTime); }
	uint64_t GetPackageId() const { return FGetPackageId(this); }
	static CArkProjectile *GetProjectileFromEntityId(const unsigned _entityId) { return FGetProjectileFromEntityId(_entityId); }
	void SetGravityTimer(const float _gravityTime) { FSetGravityTimer(this,_gravityTime); }
	IEntityArchetype *GetAmmoPickupArchetype() const { return FGetAmmoPickupArchetype(this); }
	virtual bool IsUsingExpensiveParticles() const;
	ArkSafeScriptTable GetPropertiesTable() const { return FGetPropertiesTable(this); }
	virtual void LoadCachedProperties();
	virtual void Physicalize(string const &_physicsType);
	virtual void SetPhysicsParameters(string const &_physicsType, const bool _bImpulseOnCollision);
	virtual void LoadModel();
	virtual void DoDamage(EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex);
	unsigned GetWeaponOwnerId() const { return FGetWeaponOwnerId(this); }
	CArkWeapon *GetWeapon() const { return FGetWeapon(this); }
	void SetCriticalHit() { FSetCriticalHit(this); }
	bool IsCriticalHit() const { return FIsCriticalHit(this); }
	virtual string GetModelFilename(ArkSafeScriptTable const &_propertiesTable);
	static void SpawnTracer(CArkProjectile *const _pProjectile, Vec3 const &_position, Vec3 const &_direction, const unsigned _ownerId, string _weaponClassName, const bool _bTracerIsPooled, const bool _bSpawnFromCamera) { FSpawnTracer(_pProjectile,_position,_direction,_ownerId,_weaponClassName,_bTracerIsPooled,_bSpawnFromCamera); }
	virtual void StartParticleEffect(ArkFireAndForgetEffect &_effect, const char *_propTableName, const float _scale, Vec3 const &_worldDirection);
	void InitializeLiveProjectile() { FInitializeLiveProjectile(this); }
	float GetLifetime() const { return FGetLifetime(this); }
	virtual void AttachParticleEffectsForLiveProjectiles();
	virtual void CheckForCheapParticleUse();
	
#if 0
	void SetOwnerId(const unsigned arg0);
	string const &GetWeaponClassName() const;
	bool IsTracerPooled();
	void SetGroupId(unsigned arg0);
	static unsigned GenerateGroupId();
	unsigned GetShooterId() const;
	unsigned GetOwnerId() const;
	void SetPackageId(uint64_t arg0);
	bool IsDestroying() const;
	void SetSpawnPosition(Vec3 const &arg0);
#endif
	
	static inline auto FBitNotCArkProjectile = PreyFunction<void(CArkProjectile *const _this)>(0x1644ED0);
	static inline auto FIsGrenade = PreyFunction<bool(CArkProjectile const *const _this)>(0xDD23F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectile const *const _this, ICrySizer *_s)>(0x1645BA0);
	static inline auto FInit = PreyFunction<bool(CArkProjectile *const _this, IGameObject *_pGameObject)>(0x1646490);
	static inline auto FPostInit = PreyFunction<void(CArkProjectile *const _this, IGameObject *_pGameObject)>(0x1648290);
	static inline auto FInitClient = PreyFunction<void(CArkProjectile *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkProjectile *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkProjectile *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkProjectile *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkProjectile *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkProjectile *const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectile *const _this, TSerialize _ser)>(0x16457E0);
	static inline auto FNetSerialize = PreyFunction<bool(CArkProjectile *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectile *const _this)>(0x1648680);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkProjectile *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(CArkProjectile *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectile *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x164ACB0);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectile *const _this, SGameObjectEvent const &_event)>(0x16462E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkProjectile *const _this, SEntityEvent &_event)>(0x1648840);
	static inline auto FSetChannelId = PreyFunction<void(CArkProjectile *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkProjectile *const _this, bool _auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkProjectile const *const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkProjectile *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkProjectile *const _this)>(0xA13080);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectile *const _this)>(0x16488C0);
	static inline auto FSetOwnerIdAndWeaponClassName = PreyFunction<void(CArkProjectile *const _this, const unsigned _ownerId, string const &_weaponName)>(0x1648E50);
	static inline auto FSpawnProjectile = PreyFunction<CArkProjectile *(IEntityArchetype *const _pArchetype, Vec3 const &_position, Vec3 const &_direction, const unsigned _ownerId, string _weaponClassName, const bool _bIsCritical, const bool _bIsPooled, const unsigned _extendedFlags, const unsigned _groupId, const bool _bSpawnFromCamera)>(0x16495C0);
	static inline auto FDestroy = PreyFunction<void(CArkProjectile *const _this, const bool _bDeleting, const bool _bDestroyImmediate)>(0x16453D0);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectile *const _this)>(0x164A760);
	static inline auto FStartHiddenIfNecessary = PreyFunction<void(CArkProjectile *const _this, const float _hideTime)>(0x164A830);
	static inline auto FGetPackageId = PreyFunction<uint64_t(CArkProjectile const *const _this)>(0x1645C70);
	static inline auto FGetProjectileFromEntityId = PreyFunction<CArkProjectile *(const unsigned _entityId)>(0x1645C80);
	static inline auto FSetGravityTimer = PreyFunction<void(CArkProjectile *const _this, const float _gravityTime)>(0x1648E20);
	static inline auto FGetAmmoPickupArchetype = PreyFunction<IEntityArchetype *(CArkProjectile const *const _this)>(0x16459F0);
	static inline auto FIsUsingExpensiveParticles = PreyFunction<bool(CArkProjectile const *const _this)>(0x16468A0);
	static inline auto FGetPropertiesTable = PreyFunction<ArkSafeScriptTable(CArkProjectile const *const _this)>(0x1646210);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectile *const _this)>(0x16468E0);
	static inline auto FPhysicalize = PreyFunction<void(CArkProjectile *const _this, string const &_physicsType)>(0x1647B00);
	static inline auto FSetPhysicsParameters = PreyFunction<void(CArkProjectile *const _this, string const &_physicsType, const bool _bImpulseOnCollision)>(0x1648FF0);
	static inline auto FLoadModel = PreyFunction<void(CArkProjectile *const _this)>(0x16478D0);
	static inline auto FDoDamage = PreyFunction<void(CArkProjectile *const _this, EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex)>(0x16454A0);
	static inline auto FGetWeaponOwnerId = PreyFunction<unsigned(CArkProjectile const *const _this)>(0x16462B0);
	static inline auto FGetWeapon = PreyFunction<CArkWeapon *(CArkProjectile const *const _this)>(0x1646230);
	static inline auto FSetCriticalHit = PreyFunction<void(CArkProjectile *const _this)>(0x1648C70);
	static inline auto FIsCriticalHit = PreyFunction<bool(CArkProjectile const *const _this)>(0x16466F0);
	static inline auto FGetModelFilename = PreyFunction<string(CArkProjectile *const _this, ArkSafeScriptTable const &_propertiesTable)>(0x1645BC0);
	static inline auto FSpawnTracer = PreyFunction<void(CArkProjectile *const _pProjectile, Vec3 const &_position, Vec3 const &_direction, const unsigned _ownerId, string _weaponClassName, const bool _bTracerIsPooled, const bool _bSpawnFromCamera)>(0x1649BC0);
	static inline auto FStartParticleEffect = PreyFunction<void(CArkProjectile *const _this, ArkFireAndForgetEffect &_effect, const char *_propTableName, const float _scale, Vec3 const &_worldDirection)>(0x164A8D0);
	static inline auto FInitializeLiveProjectile = PreyFunction<void(CArkProjectile *const _this)>(0x16464C0);
	static inline auto FGetLifetime = PreyFunction<float(CArkProjectile const *const _this)>(0x1645A10);
	static inline auto FAttachParticleEffectsForLiveProjectiles = PreyFunction<void(CArkProjectile *const _this)>(0x16453A0);
	static inline auto FCheckForCheapParticleUse = PreyFunction<void(CArkProjectile *const _this)>(0xA13080);
};

