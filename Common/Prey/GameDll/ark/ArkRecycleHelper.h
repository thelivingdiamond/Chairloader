// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkFabricationPlanIngredients.h>

class ArkSafeScriptTable;
enum EEntityAspects;
class ICrySizer;
struct IEntity;
struct IEntityClass;
struct IGameObject;
struct IGameObjectExtension;
struct IParticleEffect;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// ArkRecycleHelper
// Header:  Prey/GameDll/ark/ArkRecycleHelper.h
class ArkRecycleHelper : public CGameObjectExtensionHelper<ArkRecycleHelper, IGameObjectExtension>
{ // Size=360 (0x168)
public:
	// ArkRecycleHelper::RecycleEntityInfo
	// Header:  Prey/GameDll/ark/ArkRecycleHelper.h
	struct RecycleEntityInfo
	{ // Size=3 (0x3)
		bool m_bInLOS;
		bool m_bCanRecycle;
		bool m_bRecycled;

	#if 0
		RecycleEntityInfo(const bool _arg0_, const bool _arg1_);
		~RecycleEntityInfo();
		void Serialize(TSerialize _arg0_);
	#endif
	};

	bool m_bHideCenterObjects;
	float m_recyclingRadius;
	float m_recyclingKillRadius;
	float m_sprayImpulseDegree;
	ArkInterval<float> m_sprayImpulseRange;
	ArkInterval<float> m_sprayImpulseZeroGRange;
	ArkInterval<float> m_percentRecycleRange;
	float m_maxTotalScraps;
	float m_maxTotalIngredients;
	float m_maxIngredientsPerType;
	float m_percentScrapPool;
	uint64_t m_recyclePackageId;
	uint64_t m_recycleKillPackageId;
	float m_recyclingImpulse;
	float m_coneRadius;
	float m_coneHeight;
	string m_sprayPointName;
	std::unordered_map<unsigned int, ArkRecycleHelper::RecycleEntityInfo> m_areaEntities;
	float m_recycleTimerAccumulation;
	float m_areaRadius;
	IParticleEffect* m_entityGravityEffect;
	std::unordered_set<unsigned int> m_entityIdsWithEffect;
	ArkFabricationPlanIngredients m_recycledIngredients;
	std::array<int, 4> m_numIngredientsToSpawnPerType;
	int m_totalIngredientsToSpawn;
	int m_currentIngredientTypeToSpawn;
	static inline auto m_overrideRecycleClasses = PreyGlobal<std::vector<const IEntityClass*>>(0x2D39D48);
	static inline auto m_bOverrideRecycleClassesLoaded = PreyGlobal<bool>(0x2D39D18);
	unsigned m_ownerEntityId;
	unsigned m_attachedToEntityId;
	unsigned m_instigatorId;

	ArkRecycleHelper();
	virtual ~ArkRecycleHelper();
	virtual bool Init(IGameObject* pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	void ReInitFromPool() { FReInitFromPool(this); }
	void LoadCachedProperties(const ArkSafeScriptTable& _ownerPropertyTable, const float _areaRadius, const float _effectLifetime) { FLoadCachedProperties(this, _ownerPropertyTable, _areaRadius, _effectLifetime); }
	void SetCachedProperties(const bool _bHideCenterObject, const float _recyclingRadius, const float _recyclingKillRadius, const float _sprayImpulseDegree, const ArkInterval<float>& _sprayImpulseRange, const ArkInterval<float>& _sprayImpulseZeroGRange, const ArkInterval<float>& _percentRecycleRange, const float _maxTotalScraps, const float _maxIngredientsPerType, const float _maxTotalIngredients, const float _percentScrapPool, const uint64_t& _recyclePackageId, const uint64_t& _recycleKillPackageId, const float _recyclingImpulse, const float _coneRadius, const float _coneHeight, const char* const _pSprayAttachmentName, const char* const _pEntityGravityEffectName, const char* const _pOverrideRecycleClasses, const float _areaRadius, const float _effectLifetime) { FSetCachedProperties(this, _bHideCenterObject, _recyclingRadius, _recyclingKillRadius, _sprayImpulseDegree, _sprayImpulseRange, _sprayImpulseZeroGRange, _percentRecycleRange, _maxTotalScraps, _maxIngredientsPerType, _maxTotalIngredients, _percentScrapPool, _recyclePackageId, _recycleKillPackageId, _recyclingImpulse, _coneRadius, _coneHeight, _pSprayAttachmentName, _pEntityGravityEffectName, _pOverrideRecycleClasses, _areaRadius, _effectLifetime); }
	bool IsIngredient(IEntity* const _pEntity) const { return FIsIngredient(this, _pEntity); }
	void AddIngredients(const IEntity& _recycledEntity, const ArkFabricationPlanIngredients& _ingredients) { FAddIngredients(this, _recycledEntity, _ingredients); }
	bool CanRecycleEntity(const IEntity& _rEntity) const { return FCanRecycleEntity(this, _rEntity); }
	static ArkRecycleHelper* GetExtension(unsigned _id) { return FGetExtensionOv2(_id); }
	static ArkRecycleHelper& GetExtension(const IGameObjectExtension& _extension) { return FGetExtensionOv1(_extension); }
	void VibrateEntities(const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _vibrationAmount) { FVibrateEntities(this, _position, _suctionPosition, _direction, _radius, _vibrationAmount); }
	void RaiseEntities(const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _raiseForce) { FRaiseEntities(this, _position, _suctionPosition, _direction, _radius, _raiseForce); }
	void PullEntities(const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _pullForce) { FPullEntities(this, _position, _suctionPosition, _direction, _radius, _pullForce); }
	void PullPlayer(const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _pullForce) { FPullPlayer(this, _position, _suctionPosition, _direction, _radius, _pullForce); }
	void PopulateEntities(const Vec3& _position, const bool _bRecycling) { FPopulateEntities(this, _position, _bRecycling); }
	void InitArea(const Vec3& _position, const bool _bRecycling) { FInitArea(this, _position, _bRecycling); }
	bool RecycleEntity(const Vec3& _position, const Vec3& _direction, unsigned _entityId, const bool _bInLOS, const std::vector<uint64_t>& _sneakAttackMetaTags) { return FRecycleEntity(this, _position, _direction, _entityId, _bInLOS, _sneakAttackMetaTags); }
	void HandleEntityInArea(const Vec3& _ownerPos, const unsigned _entityId, const bool _bRecycling) { FHandleEntityInArea(this, _ownerPos, _entityId, _bRecycling); }
	int RecycleEntitiesInArea(const Vec3& _position, const Vec3& _direction, const std::vector<uint64_t>& _sneakAttackMetaTags) { return FRecycleEntitiesInArea(this, _position, _direction, _sneakAttackMetaTags); }
	void ImpulseEntitiesInArea(const Vec3& _position) { FImpulseEntitiesInArea(this, _position); }
	void CalculateIngredientInfo() { FCalculateIngredientInfo(this); }
	void SpawnRecycledIngredientsInWorld(const Vec3& _position, const Vec3& _direction, const Quat& _rotation, const float _frametime, const int _numIngredientsToSpawn) { FSpawnRecycledIngredientsInWorld(this, _position, _direction, _rotation, _frametime, _numIngredientsToSpawn); }
	bool SpawnRecycledIngredientsInInventory(const float _yieldScale, const float _frametime, const int _numIngredientsToSpawn) { return FSpawnRecycledIngredientsInInventory(this, _yieldScale, _frametime, _numIngredientsToSpawn); }
	virtual void InitClient(int channelId);
	virtual void PostInit(IGameObject* pGameObject);
	virtual void PostInitClient(int channelId);
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params);
	virtual bool GetEntityPoolSignature(TSerialize signature);
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& ctx, int __unnamed1);
	virtual void PostUpdate(float frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& __unnamed1);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t id);
	virtual void SetAuthority(bool auth);
	virtual void GetMemoryUsage(ICrySizer* __unnamed1) const;
	bool IsEntityInArea(const Vec3& _ownerPos, const Vec3& _suctionPosition, const Vec3& _direction, const Vec3& _entityPos, const float _radius) { return FIsEntityInArea(this, _ownerPos, _suctionPosition, _direction, _entityPos, _radius); }

#if 0
	int GetTotalIngredientsToSpawn() const;
	float GetTimerAccumulation() const;
	void SetAttachedEntityId(const unsigned _arg0_);
	void SetOwnerAndInstigatorEntityIds(const unsigned _arg0_, const unsigned _arg1_);
	float GetRecyclingRadius() const;
	ArkInterval<float> GetPercentRecycleRange() const;
	int CalculateTotalScraps();
	bool CanRecyclePlayerEntity(unsigned _arg0_) const;
	static const ArkRecycleHelper* GetExtension(const IEntity& _arg0_);
	std::unordered_map<unsigned int, ArkRecycleHelper::RecycleEntityInfo> GetAreaEntities() const;
	bool IsAttachedToEntity(const IEntity& _arg0_);
	bool IsInRecyclingRange(const Vec3& _arg0_, const Vec3& _arg1_);
#endif

	static inline auto FArkRecycleHelperOv1 = PreyFunction<void(ArkRecycleHelper* const _this)>(0x11BE8E0);
	static inline auto FInit = PreyFunction<bool(ArkRecycleHelper* const _this, IGameObject* pGameObject)>(0x1A302A0);
	static inline auto FRelease = PreyFunction<void(ArkRecycleHelper* const _this)>(0x3E3960);
	static inline auto FFullSerialize = PreyFunction<void(ArkRecycleHelper* const _this, TSerialize _ser)>(0x11BF2E0);
	static inline auto FReInitFromPool = PreyFunction<void(ArkRecycleHelper* const _this)>(0x11C1EC0);
	static inline auto FLoadCachedProperties = PreyFunction<void(ArkRecycleHelper* const _this, const ArkSafeScriptTable& _ownerPropertyTable, const float _areaRadius, const float _effectLifetime)>(0x11C0340);
	static inline auto FSetCachedProperties = PreyFunction<void(ArkRecycleHelper* const _this, const bool _bHideCenterObject, const float _recyclingRadius, const float _recyclingKillRadius, const float _sprayImpulseDegree, const ArkInterval<float>& _sprayImpulseRange, const ArkInterval<float>& _sprayImpulseZeroGRange, const ArkInterval<float>& _percentRecycleRange, const float _maxTotalScraps, const float _maxIngredientsPerType, const float _maxTotalIngredients, const float _percentScrapPool, const uint64_t& _recyclePackageId, const uint64_t& _recycleKillPackageId, const float _recyclingImpulse, const float _coneRadius, const float _coneHeight, const char* const _pSprayAttachmentName, const char* const _pEntityGravityEffectName, const char* const _pOverrideRecycleClasses, const float _areaRadius, const float _effectLifetime)>(0x11C2490);
	static inline auto FIsIngredient = PreyFunction<bool(const ArkRecycleHelper* const _this, IEntity* const _pEntity)>(0x11C0310);
	static inline auto FAddIngredients = PreyFunction<void(ArkRecycleHelper* const _this, const IEntity& _recycledEntity, const ArkFabricationPlanIngredients& _ingredients)>(0x11BEED0);
	static inline auto FCanRecycleEntity = PreyFunction<bool(const ArkRecycleHelper* const _this, const IEntity& _rEntity)>(0x11BF200);
	static inline auto FGetExtensionOv2 = PreyFunction<ArkRecycleHelper* (unsigned _id)>(0x11BF5B0);
	static inline auto FGetExtensionOv1 = PreyFunction<ArkRecycleHelper& (const IGameObjectExtension& _extension)>(0x11BF5A0);
	static inline auto FVibrateEntities = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _vibrationAmount)>(0x11C2D70);
	static inline auto FRaiseEntities = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _raiseForce)>(0x11C1B80);
	static inline auto FPullEntities = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _pullForce)>(0x11C11E0);
	static inline auto FPullPlayer = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position, const Vec3& _suctionPosition, const Vec3& _direction, const float _radius, const float _pullForce)>(0x11C1850);
	static inline auto FPopulateEntities = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position, const bool _bRecycling)>(0x11C1050);
	static inline auto FInitArea = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position, const bool _bRecycling)>(0x11BFE80);
	static inline auto FRecycleEntity = PreyFunction<bool(ArkRecycleHelper* const _this, const Vec3& _position, const Vec3& _direction, unsigned _entityId, const bool _bInLOS, const std::vector<uint64_t>& _sneakAttackMetaTags)>(0x11C2060);
	static inline auto FHandleEntityInArea = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _ownerPos, const unsigned _entityId, const bool _bRecycling)>(0x11BF670);
	static inline auto FRecycleEntitiesInArea = PreyFunction<int(ArkRecycleHelper* const _this, const Vec3& _position, const Vec3& _direction, const std::vector<uint64_t>& _sneakAttackMetaTags)>(0x11C1FB0);
	static inline auto FImpulseEntitiesInArea = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position)>(0x11BFC00);
	static inline auto FCalculateIngredientInfo = PreyFunction<void(ArkRecycleHelper* const _this)>(0x11BF020);
	static inline auto FSpawnRecycledIngredientsInWorld = PreyFunction<void(ArkRecycleHelper* const _this, const Vec3& _position, const Vec3& _direction, const Quat& _rotation, const float _frametime, const int _numIngredientsToSpawn)>(0x11C2B20);
	static inline auto FSpawnRecycledIngredientsInInventory = PreyFunction<bool(ArkRecycleHelper* const _this, const float _yieldScale, const float _frametime, const int _numIngredientsToSpawn)>(0x11C2930);
	static inline auto FInitClient = PreyFunction<void(ArkRecycleHelper* const _this, int channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(ArkRecycleHelper* const _this, IGameObject* pGameObject)>(0x1333E90);
	static inline auto FPostInitClient = PreyFunction<void(ArkRecycleHelper* const _this, int channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkRecycleHelper* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkRecycleHelper* const _this, IGameObject* pGameObject, const SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkRecycleHelper* const _this, TSerialize signature)>(0x1A302A0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkRecycleHelper* const _this, TSerialize ser, EEntityAspects aspect, uint8_t profile, int flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkRecycleHelper* const _this)>(0x1333E90);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkRecycleHelper* const _this, TSerialize ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkRecycleHelper* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkRecycleHelper* const _this, SEntityUpdateContext& ctx, int __unnamed1)>(0x1333E90);
	static inline auto FPostUpdate = PreyFunction<void(ArkRecycleHelper* const _this, float frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkRecycleHelper* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkRecycleHelper* const _this, const SGameObjectEvent& __unnamed1)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(ArkRecycleHelper* const _this, SEntityEvent& _event)>(0x1333E90);
	static inline auto FSetChannelId = PreyFunction<void(ArkRecycleHelper* const _this, uint16_t id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkRecycleHelper* const _this, bool auth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkRecycleHelper* const _this, ICrySizer* __unnamed1)>(0x1333E90);
	static inline auto FIsEntityInArea = PreyFunction<bool(ArkRecycleHelper* const _this, const Vec3& _ownerPos, const Vec3& _suctionPosition, const Vec3& _direction, const Vec3& _entityPos, const float _radius)>(0x11C0100);
};
#endif // MOONCRASH
