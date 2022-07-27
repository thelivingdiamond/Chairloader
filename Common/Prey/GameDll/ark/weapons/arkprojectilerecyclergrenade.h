// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkFabricationPlanIngredients.h>
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>
#include <Prey/GameDll/ark/weapons/arkprojectilegrenade.h>

class ICrySizer;
struct IEntity;
struct IGameObject;
struct IParticleEffect;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectilerecyclergrenade.h
class CArkProjectileRecyclerGrenade : public CArkProjectileGrenade // Id=80194E2 Size=3064
{
public:
	enum class EArkRecyclerGrenadeState
	{
		none = 0,
		initialize = 1,
		launch = 2,
		detonate = 3,
		vibrateObjects = 4,
		gravityPull = 5,
		recycle = 6,
		destroyed = 7,
	};

	bool m_bHideCenterObjects;
	float m_vibrationRadius;
	float m_gravitationalPullRadius;
	float m_gravitationalPull;
	float m_gravitationalPullPlayer;
	float m_raiseGravityZ;
	float m_vibrationAmount;
	float m_recyclingRadius;
	float m_recyclingKillRadius;
	float m_recyclingImpulse;
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
	
	struct RecycleEntityInfo // Id=80194E3 Size=3
	{
		bool m_bInLOS;
		bool m_bCanRecycle;
		bool m_bRecycled;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	CArkProjectileRecyclerGrenade::EArkRecyclerGrenadeState m_state;
	std::unordered_map<unsigned int,CArkProjectileRecyclerGrenade::RecycleEntityInfo> m_areaEntities;
	ArkSimpleTimer m_pullTimer;
	ArkSimpleTimer m_vibrateTimer;
	ArkSimpleTimer m_recycleTimer;
	float m_recycleTimerAccumulation;
	float m_areaRadius;
	IParticleEffect *m_entityGravityEffect;
	CArkProjectile::ArkProjectileEntityEffect m_pullEffect;
	CArkProjectile::ArkProjectileEntityEffect m_popEffect;
	CArkProjectile::ArkProjectileEntityEffect m_flashEffect;
	std::unordered_set<unsigned int> m_entityIdsWithEffect;
	ArkFabricationPlanIngredients m_recycledIngredients;
	std::array<int,4> m_numIngredientsToSpawnPerType;
	int m_totalIngredientsToSpawn;
	int m_currentIngredientTypeToSpawn;
	static std::vector<IEntityClass const *> m_overrideRecycleClasses;
	static bool m_bOverrideRecycleClassesLoaded;
	
	CArkProjectileRecyclerGrenade();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void ReInitFromPool();
	virtual bool Detonate();
	static CArkProjectileRecyclerGrenade *GetProjectileGrenadeFromEntityId(const unsigned _entityId) { return FGetProjectileGrenadeFromEntityId(_entityId); }
	bool IsIngredient(IEntity *const _pEntity) const { return FIsIngredient(this,_pEntity); }
	void AddIngredients(IEntity const &_recycledEntity, ArkFabricationPlanIngredients const &_ingredients) { FAddIngredients(this,_recycledEntity,_ingredients); }
	bool CanRecycleEntity(IEntity const &_rEntity) const { return FCanRecycleEntity(this,_rEntity); }
	virtual void Pulse();
	virtual void Destroy(const bool _bDeleting, const bool _bDestroyImmediate);
	void HandleEntityInArea(const unsigned _entityId, const bool _bRecycling) { FHandleEntityInArea(this,_entityId,_bRecycling); }
	virtual void LoadCachedProperties();
	void StateUpdate(SEntityUpdateContext const &_ctx) { FStateUpdate(this,_ctx); }
	void StateEnter(CArkProjectileRecyclerGrenade::EArkRecyclerGrenadeState _state) { FStateEnter(this,_state); }
	void StateExit(CArkProjectileRecyclerGrenade::EArkRecyclerGrenadeState _state) { FStateExit(this,_state); }
	void InitArea(Vec3 const &_position, const bool _bRecycling) { FInitArea(this,_position,_bRecycling); }
	bool RecycleEntity(unsigned _entityId, const bool _bInLOS) { return FRecycleEntity(this,_entityId,_bInLOS); }
	void VibrateEntities(const float _radius, const float _vibrationAmount) { FVibrateEntities(this,_radius,_vibrationAmount); }
	void RaiseEntities(const float _radius, const float _raiseForce) { FRaiseEntities(this,_radius,_raiseForce); }
	void PullEntities(const float _radius, const float _pullForce) { FPullEntities(this,_radius,_pullForce); }
	void PullPlayer(const float _radius, const float _pullForce) { FPullPlayer(this,_radius,_pullForce); }
	void CalculateIngredientInfo() { FCalculateIngredientInfo(this); }
	
#if 0
	ArkInterval<float> GetPercentRecycleRange() const;
	int CalculateTotalScraps();
	bool IsAttachedToEntity(IEntity const &arg0);
	void ChangeState(CArkProjectileRecyclerGrenade::EArkRecyclerGrenadeState arg0);
	bool IsEntityInArea(Vec3 const &arg0, Vec3 const &arg1, const float arg2);
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectileRecyclerGrenade const *const _this, ICrySizer *_s)>(0x1657B60);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, IGameObject *_pGameObject)>(0x1659730);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, TSerialize _ser)>(0x16577D0);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this)>(0x16597A0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x165B720);
	static inline auto FProcessEvent = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, SEntityEvent &_event)>(0x16597D0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this)>(0x165A7C0);
	static inline auto FDetonate = PreyFunction<bool(CArkProjectileRecyclerGrenade *const _this)>(0x16576F0);
	static inline auto FGetProjectileGrenadeFromEntityId = PreyFunction<CArkProjectileRecyclerGrenade *(const unsigned _entityId)>(0x1657B80);
	static inline auto FIsIngredient = PreyFunction<bool(CArkProjectileRecyclerGrenade const *const _this, IEntity *const _pEntity)>(0x16583F0);
	static inline auto FAddIngredients = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, IEntity const &_recycledEntity, ArkFabricationPlanIngredients const &_ingredients)>(0x1657200);
	static inline auto FCanRecycleEntity = PreyFunction<bool(CArkProjectileRecyclerGrenade const *const _this, IEntity const &_rEntity)>(0x16575C0);
	static inline auto FPulse = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this)>(0x165A2D0);
	static inline auto FDestroy = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, const bool _bDeleting, const bool _bDestroyImmediate)>(0x1657680);
	static inline auto FHandleEntityInArea = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, const unsigned _entityId, const bool _bRecycling)>(0x1657C30);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this)>(0x1658420);
	static inline auto FStateUpdate = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, SEntityUpdateContext const &_ctx)>(0x165B3B0);
	static inline auto FStateEnter = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, CArkProjectileRecyclerGrenade::EArkRecyclerGrenadeState _state)>(0x165AD50);
	static inline auto FStateExit = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, CArkProjectileRecyclerGrenade::EArkRecyclerGrenadeState _state)>(0x165B070);
	static inline auto FInitArea = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, Vec3 const &_position, const bool _bRecycling)>(0x1658180);
	static inline auto FRecycleEntity = PreyFunction<bool(CArkProjectileRecyclerGrenade *const _this, unsigned _entityId, const bool _bInLOS)>(0x165A910);
	static inline auto FVibrateEntities = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, const float _radius, const float _vibrationAmount)>(0x165B810);
	static inline auto FRaiseEntities = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, const float _radius, const float _raiseForce)>(0x165A4C0);
	static inline auto FPullEntities = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, const float _radius, const float _pullForce)>(0x1659910);
	static inline auto FPullPlayer = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this, const float _radius, const float _pullForce)>(0x1659F80);
	static inline auto FCalculateIngredientInfo = PreyFunction<void(CArkProjectileRecyclerGrenade *const _this)>(0x16573C0);
};

