// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/ArkScriptTable.h>

class ArkSafeScriptTable;
class CArkWeapon;
enum EEntityAspects;
struct EventPhysCollision;
class ICrySizer;
struct IEntityArchetype;
struct IGameObject;
struct IGameObjectExtension;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkProjectile
// Header:  Prey/GameDll/ark/weapons/ArkProjectile.h
class CArkProjectile : public CGameObjectExtensionHelper<CArkProjectile, IGameObjectExtension>
{ // Size=664 (0x298)
public:
	enum class EArkProjectileTimer
	{
		lifetime = 272,
		hidetime = 273,
	};
	
	// CArkProjectile::ArkProjectileEntityEffect
	// Header:  Prey/GameDll/ark/weapons/ArkProjectile.h
	struct ArkProjectileEntityEffect
	{ // Size=280 (0x118)
		ArkEntityEffect m_expensiveEffect;
		ArkEntityEffect m_cheapEffect;
		bool m_bUseCheapEffect;
		
		void LoadEntityEffect(ArkSafeScriptTable _properties, const string _propertyName, const float _duration, const float _sizeScale) { FLoadEntityEffect(this, _properties, _propertyName, _duration, _sizeScale); }
		void Start(const bool _bUseCheap) { FStart(this, _bUseCheap); }
		void Kill() { FKill(this); }
		void SetLocalTM(const Matrix34& _localTM) { FSetLocalTM(this, _localTM); }
		
	#if 0
		ArkProjectileEntityEffect(IGameObjectExtension& _arg0_, int _arg1_, bool _arg2_);
		void Stop();
	#endif
		
		static inline auto FLoadEntityEffect = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect* const _this, ArkSafeScriptTable _properties, const string _propertyName, const float _duration, const float _sizeScale)>(0x1647500);
		static inline auto FStart = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect* const _this, const bool _bUseCheap)>(0x164A500);
		static inline auto FKill = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect* const _this)>(0x16468C0);
		static inline auto FSetLocalTM = PreyFunction<void(CArkProjectile::ArkProjectileEntityEffect* const _this, const Matrix34& _localTM)>(0x1648E30);
	};
	
	// CArkProjectile::ArkProjectileFFEffect
	// Header:  Prey/GameDll/ark/weapons/ArkProjectile.h
	struct ArkProjectileFFEffect
	{ // Size=136 (0x88)
		ArkFireAndForgetEffect m_expensiveEffect;
		ArkFireAndForgetEffect m_cheapEffect;
		bool m_bUseCheapEffect = false;
		float m_scale = 1.0f;
		
		void LoadFFEffect(ArkSafeScriptTable _properties, const string _propertyName) { FLoadFFEffect(this, _properties, _propertyName); }
		void Start(const bool _bUseCheap, const Vec3& _position, const Vec3& _worldDirection, const float _scale) { FStart(this, _bUseCheap, _position, _worldDirection, _scale); }
		
	#if 0
		ArkProjectileFFEffect();
	#endif
		
		static inline auto FLoadFFEffect = PreyFunction<void(CArkProjectile::ArkProjectileFFEffect* const _this, ArkSafeScriptTable _properties, const string _propertyName)>(0x1647670);
		static inline auto FStart = PreyFunction<void(CArkProjectile::ArkProjectileFFEffect* const _this, const bool _bUseCheap, const Vec3& _position, const Vec3& _worldDirection, const float _scale)>(0x164A550);
	};
	
	ArkSimpleTimer m_lifeTimer;
	bool m_isDestroying = false;
	bool m_bUseCheapEffects = false;
	ArkSimpleTimer m_destroyTimer;
	bool m_bIsPooled = false;
	bool m_bTracerIsPooled = false;
	bool m_bCollidesWithProjectile = false;
	bool m_bOverrideGravity = false;
	bool m_bAlignWithVelocity = false;
	bool m_bDestroyOnCollision = false;
	float m_speed = 0.0f;
	float m_speedFromCamera = 0.0f;
	std::vector<uint64_t> m_sneakAttackMetaTags;
	unsigned m_ownerFaction = -1;
	ArkFireAndForgetEffect m_collisionEffect;
	ArkProjectileFFEffect m_explosionEffect;
	ArkSimpleTimer m_gravityTimer;
	unsigned m_ownerId = 0;
	string m_weaponClassName;
	ArkSimpleTimer m_ownerNotCollidingTimer;
	uint64_t m_packageId = -1;
	unsigned m_groupId = 0;
	Vec3 m_spawnPosition = Vec3(ZERO);
	ArkEntityEffect m_projectileEffect;
	ArkEntityEffect m_trailEffect;
	static inline auto m_pTracerArchetype = PreyGlobal<IEntityArchetype*>(0x2C071C8);
	static inline auto s_groupIdGen = PreyGlobal<unsigned>(0x2C071D0);
	
	CArkProjectile()
		: m_projectileEffect(*this, -1, 0)
		, m_trailEffect(*this, -1, 0) {}

	virtual ~CArkProjectile() = default;
	virtual bool IsGrenade() const { return FIsGrenade(this); }
	virtual void GetMemoryUsage(ICrySizer* _s) const { FGetMemoryUsage(this, _s); }
	virtual bool Init(IGameObject* _pGameObject) { return FInit(this, _pGameObject); }
	virtual void PostInit(IGameObject* _pGameObject) { FPostInit(this, _pGameObject); }
	virtual void InitClient(int _channelId) { FInitClient(this, _channelId); }
	virtual void PostInitClient(int _channelId) { FPostInitClient(this, _channelId); }
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params) { return FReloadExtension(this, _pGameObject, _params); }
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params) { FPostReloadExtension(this, _pGameObject, _params); }
	virtual bool GetEntityPoolSignature(TSerialize _signature) { return FGetEntityPoolSignature(this, _signature); }
	virtual void Release() { FRelease(this); }
	virtual void FullSerialize(TSerialize _ser) { FFullSerialize(this, _ser); }
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags) { return FNetSerialize(this, _ser, _aspect, _profile, _pflags); }
	virtual void PostSerialize() { FPostSerialize(this); }
	virtual void SerializeSpawnInfo(TSerialize _ser) { FSerializeSpawnInfo(this, _ser); }
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo() { alignas(_smart_ptr<ISerializableInfo>) std::byte _return_buf_[sizeof(_smart_ptr<ISerializableInfo>)]; return *FGetSpawnInfo(this, reinterpret_cast<_smart_ptr<ISerializableInfo>*>(_return_buf_)); }
	virtual void Update(SEntityUpdateContext& _ctx, int _slot) { FUpdate(this, _ctx, _slot); }
	virtual void HandleEvent(const SGameObjectEvent& _event) { FHandleEvent(this, _event); }
	virtual void ProcessEvent(SEntityEvent& _event) { FProcessEvent(this, _event); }
	virtual void SetChannelId(uint16_t _id) { FSetChannelId(this, _id); }
	virtual void SetAuthority(bool _auth) { FSetAuthority(this, _auth); }
	virtual const void* GetRMIBase() const { return FGetRMIBase(this); }
	virtual void PostUpdate(float _frameTime) { FPostUpdate(this, _frameTime); }
	virtual void PostRemoteSpawn() { FPostRemoteSpawn(this); }
	virtual void ReInitFromPool() { FReInitFromPool(this); }
	virtual void SetOwnerIdAndWeaponClassName(const unsigned _ownerId, const string& _weaponName) { FSetOwnerIdAndWeaponClassName(this, _ownerId, _weaponName); }
	static CArkProjectile* SpawnProjectile(IEntityArchetype* const _pArchetype, const Vec3& _position, const Vec3& _direction, const unsigned _ownerId, const string _weaponClassName, const bool _bIsCritical, const bool _bIsPooled, const unsigned _extendedFlags, const unsigned _groupId, const bool _bSpawnFromCamera) { return FSpawnProjectile(_pArchetype, _position, _direction, _ownerId, _weaponClassName, _bIsCritical, _bIsPooled, _extendedFlags, _groupId, _bSpawnFromCamera); }
	virtual void Destroy(const bool _bDeleting, const bool _bDestroyImmediate) { FDestroy(this, _bDeleting, _bDestroyImmediate); }
	virtual void StartDestroy() { FStartDestroy(this); }
	void StartHiddenIfNecessary(const float _hideTime) { FStartHiddenIfNecessary(this, _hideTime); }
	uint64_t GetPackageId() const { return FGetPackageId(this); }
	static CArkProjectile* GetProjectileFromEntityId(const unsigned _entityId) { return FGetProjectileFromEntityId(_entityId); }
	void SetGravityTimer(const float _gravityTime) { FSetGravityTimer(this, _gravityTime); }
	IEntityArchetype* GetAmmoPickupArchetype() const { return FGetAmmoPickupArchetype(this); }
	virtual bool IsUsingExpensiveParticles() const { return FIsUsingExpensiveParticles(this); }
	ArkSafeScriptTable GetPropertiesTable() const { alignas(ArkSafeScriptTable) std::byte _return_buf_[sizeof(ArkSafeScriptTable)]; return *FGetPropertiesTable(this, reinterpret_cast<ArkSafeScriptTable*>(_return_buf_)); }
	virtual void LoadCachedProperties() { FLoadCachedProperties(this); }
	virtual void Physicalize(const string& _physicsType) { FPhysicalize(this, _physicsType); }
	virtual void SetPhysicsParameters(const string& _physicsType, const bool _bImpulseOnCollision) { FSetPhysicsParameters(this, _physicsType, _bImpulseOnCollision); }
	virtual void LoadModel() { FLoadModel(this); }
	virtual void DoDamage(const EventPhysCollision& _collision, const unsigned& _targetId, const int _targetIndex) { FDoDamage(this, _collision, _targetId, _targetIndex); }
	unsigned GetWeaponOwnerId() const { return FGetWeaponOwnerId(this); }
	CArkWeapon* GetWeapon() const { return FGetWeapon(this); }
	void SetCriticalHit() { FSetCriticalHit(this); }
	bool IsCriticalHit() const { return FIsCriticalHit(this); }
	virtual string GetModelFilename(const ArkSafeScriptTable& _propertiesTable) { alignas(string) std::byte _return_buf_[sizeof(string)]; return *FGetModelFilename(this, reinterpret_cast<string*>(_return_buf_), _propertiesTable); }
	static void SpawnTracer(CArkProjectile* const _pProjectile, const Vec3& _position, const Vec3& _direction, const unsigned _ownerId, const string _weaponClassName, const bool _bTracerIsPooled, const bool _bSpawnFromCamera) { FSpawnTracer(_pProjectile, _position, _direction, _ownerId, _weaponClassName, _bTracerIsPooled, _bSpawnFromCamera); }
	virtual void StartParticleEffect(ArkFireAndForgetEffect& _effect, const char* _propTableName, const float _scale, const Vec3& _worldDirection) { FStartParticleEffect(this, _effect, _propTableName, _scale, _worldDirection); }
	void InitializeLiveProjectile() { FInitializeLiveProjectile(this); }
	float GetLifetime() const { return FGetLifetime(this); }
	virtual void AttachParticleEffectsForLiveProjectiles() { FAttachParticleEffectsForLiveProjectiles(this); }
	virtual void CheckForCheapParticleUse() { FCheckForCheapParticleUse(this); }
	
#if 0
	void SetOwnerId(const unsigned _arg0_);
	const string& GetWeaponClassName() const;
	bool IsTracerPooled();
	void SetGroupId(unsigned _arg0_);
	static unsigned GenerateGroupId();
	unsigned GetShooterId() const;
	unsigned GetOwnerId() const;
	void SetPackageId(uint64_t _arg0_);
	bool IsDestroying() const;
	void SetSpawnPosition(const Vec3& _arg0_);
#endif
	
	static inline auto FCArkProjectileOv1 = PreyFunction<void(CArkProjectile* const _this)>(0x1644DB0);
	static inline auto FBitNotCArkProjectile = PreyFunction<void(CArkProjectile* const _this)>(0x1644ED0);
	static inline auto FIsGrenade = PreyFunction<bool(const CArkProjectile* const _this)>(0xDD23F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkProjectile* const _this, ICrySizer* _s)>(0x1645BA0);
	static inline auto FInit = PreyFunction<bool(CArkProjectile* const _this, IGameObject* _pGameObject)>(0x1646490);
	static inline auto FPostInit = PreyFunction<void(CArkProjectile* const _this, IGameObject* _pGameObject)>(0x1648290);
	static inline auto FInitClient = PreyFunction<void(CArkProjectile* const _this, int _channelId)>(0xA13080);
	static inline auto FPostInitClient = PreyFunction<void(CArkProjectile* const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(CArkProjectile* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(CArkProjectile* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(CArkProjectile* const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(CArkProjectile* const _this)>(0xA97D40);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectile* const _this, TSerialize _ser)>(0x16457E0);
	static inline auto FNetSerialize = PreyFunction<bool(CArkProjectile* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _pflags)>(0xDD23F0);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectile* const _this)>(0x1648680);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(CArkProjectile* const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(CArkProjectile* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectile* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x164ACB0);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectile* const _this, const SGameObjectEvent& _event)>(0x16462E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkProjectile* const _this, SEntityEvent& _event)>(0x1648840);
	static inline auto FSetChannelId = PreyFunction<void(CArkProjectile* const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(CArkProjectile* const _this, bool _auth)>(0xA13080);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkProjectile* const _this)>(0x158AEF0);
	static inline auto FPostUpdate = PreyFunction<void(CArkProjectile* const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(CArkProjectile* const _this)>(0xA13080);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectile* const _this)>(0x16488C0);
	static inline auto FSetOwnerIdAndWeaponClassName = PreyFunction<void(CArkProjectile* const _this, const unsigned _ownerId, const string& _weaponName)>(0x1648E50);
	static inline auto FSpawnProjectile = PreyFunction<CArkProjectile* (IEntityArchetype* const _pArchetype, const Vec3& _position, const Vec3& _direction, const unsigned _ownerId, const string _weaponClassName, const bool _bIsCritical, const bool _bIsPooled, const unsigned _extendedFlags, const unsigned _groupId, const bool _bSpawnFromCamera)>(0x16495C0);
	static inline auto FDestroy = PreyFunction<void(CArkProjectile* const _this, const bool _bDeleting, const bool _bDestroyImmediate)>(0x16453D0);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectile* const _this)>(0x164A760);
	static inline auto FStartHiddenIfNecessary = PreyFunction<void(CArkProjectile* const _this, const float _hideTime)>(0x164A830);
	static inline auto FGetPackageId = PreyFunction<uint64_t(const CArkProjectile* const _this)>(0x1645C70);
	static inline auto FGetProjectileFromEntityId = PreyFunction<CArkProjectile* (const unsigned _entityId)>(0x1645C80);
	static inline auto FSetGravityTimer = PreyFunction<void(CArkProjectile* const _this, const float _gravityTime)>(0x1648E20);
	static inline auto FGetAmmoPickupArchetype = PreyFunction<IEntityArchetype* (const CArkProjectile* const _this)>(0x16459F0);
	static inline auto FIsUsingExpensiveParticles = PreyFunction<bool(const CArkProjectile* const _this)>(0x16468A0);
	static inline auto FGetPropertiesTable = PreyFunction<ArkSafeScriptTable*(const CArkProjectile* const _this, ArkSafeScriptTable* _return_value_)>(0x1646210);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectile* const _this)>(0x16468E0);
	static inline auto FPhysicalize = PreyFunction<void(CArkProjectile* const _this, const string& _physicsType)>(0x1647B00);
	static inline auto FSetPhysicsParameters = PreyFunction<void(CArkProjectile* const _this, const string& _physicsType, const bool _bImpulseOnCollision)>(0x1648FF0);
	static inline auto FLoadModel = PreyFunction<void(CArkProjectile* const _this)>(0x16478D0);
	static inline auto FDoDamage = PreyFunction<void(CArkProjectile* const _this, const EventPhysCollision& _collision, const unsigned& _targetId, const int _targetIndex)>(0x16454A0);
	static inline auto FGetWeaponOwnerId = PreyFunction<unsigned(const CArkProjectile* const _this)>(0x16462B0);
	static inline auto FGetWeapon = PreyFunction<CArkWeapon* (const CArkProjectile* const _this)>(0x1646230);
	static inline auto FSetCriticalHit = PreyFunction<void(CArkProjectile* const _this)>(0x1648C70);
	static inline auto FIsCriticalHit = PreyFunction<bool(const CArkProjectile* const _this)>(0x16466F0);
	static inline auto FGetModelFilename = PreyFunction<string*(CArkProjectile* const _this, string* _return_value_, const ArkSafeScriptTable& _propertiesTable)>(0x1645BC0);
	static inline auto FSpawnTracer = PreyFunction<void(CArkProjectile* const _pProjectile, const Vec3& _position, const Vec3& _direction, const unsigned _ownerId, const string _weaponClassName, const bool _bTracerIsPooled, const bool _bSpawnFromCamera)>(0x1649BC0);
	static inline auto FStartParticleEffect = PreyFunction<void(CArkProjectile* const _this, ArkFireAndForgetEffect& _effect, const char* _propTableName, const float _scale, const Vec3& _worldDirection)>(0x164A8D0);
	static inline auto FInitializeLiveProjectile = PreyFunction<void(CArkProjectile* const _this)>(0x16464C0);
	static inline auto FGetLifetime = PreyFunction<float(const CArkProjectile* const _this)>(0x1645A10);
	static inline auto FAttachParticleEffectsForLiveProjectiles = PreyFunction<void(CArkProjectile* const _this)>(0x16453A0);
	static inline auto FCheckForCheapParticleUse = PreyFunction<void(CArkProjectile* const _this)>(0xA13080);
};


