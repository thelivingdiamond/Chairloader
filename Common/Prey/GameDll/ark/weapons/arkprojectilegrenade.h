// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/iface/IGameRulesKillListener.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>
#include <Prey/GameDll/ark/player/IArkPlayerCarryListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>
#include <Prey/GameDll/ark/weapons/ArkGrenadeSignalReceiver.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
struct HitInfo;
struct IAttachment;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectilegrenade.h
class CArkProjectileGrenade : public CArkProjectile, public IArkPlayerInteractionListener, public IArkPlayerCarryListener, public IGameRulesKillListener, public IArkDisruptableListener, public IEntityEventListener // Id=801601D Size=1896
{
public:
	bool m_bIsProximity;
	int m_proximityPhysicsEntityId;
	int m_proximityEntityId;
	int m_proximityPartId;
	bool m_bProximityTerrain;
	ArkSimpleTimer m_proximityTimer;
	bool m_bExploded;
	bool m_bTriggered;
	std::vector<int> m_ignoreEntities;
	float m_explosionRadius;
	float m_explosionImpulse;
	float m_proximityRadius;
	float m_proximitySpeed;
	bool m_bAutoDeploy;
	bool m_bImpendingDanger;
	string m_useMessage;
	string m_equipMessage;
	uint64_t m_cameraShakeId;
	float m_hitNPCTime;
	ArkSimpleTimer m_armingTimer;
	ArkSimpleTimer m_detonationTimer;
	ArkSimpleTimer m_pulseTimer;
	bool m_bShouldCheckLOS;
	bool m_bShouldBreakGlass;
	ArkDisruptable m_disruptable;
	bool m_bDisrupted;
	bool bArmFriendly;
	ArkEntityEffect m_armedFriendlyEffect;
	ArkEntityEffect m_armedEnemyEffect;
	ArkEntityEffect m_detonatedEffect;
	CArkProjectile::ArkProjectileEntityEffect m_AOEEffect;
	ArkGameNoise::Params m_explosionNoise;
	IAttachment *m_pAttachment;
	int m_constraintId;
	float m_originalMass;
	static int s_attachNameID;
	ArkSimpleTimer m_hitNPCTimer;
	ArkGrenadeSignalReceiver m_signalReceiver;
	CArkProjectile::ArkProjectileFFEffect m_destroyEffect;
	
	CArkProjectileGrenade();
	virtual ~CArkProjectileGrenade();
	virtual bool IsGrenade() const;
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual const void *GetRMIBase() const;
	virtual void OnEntityKilledEarly(HitInfo const &_hitInfo);
	virtual void OnEntityKilled(HitInfo const &_hitInfo);
	virtual void OnEntityBroken(const unsigned _brokenEntityId);
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	virtual void OnStartCarry(IEntity *const _pEntity);
	void TakeDamage(const float _damage, const unsigned _responsibleEntityId) { FTakeDamage(this,_damage,_responsibleEntityId); }
	virtual bool Detonate();
	virtual void DoDetonation();
	static CArkProjectileGrenade *GetProjectileGrenadeFromEntityId(const unsigned _entityId) { return FGetProjectileGrenadeFromEntityId(_entityId); }
	void AttachToPhysicsEntity(const int _physicsEntityId, Vec3 const &_attachPosition, const int _partId, const bool _bTerrain) { FAttachToPhysicsEntity(this,_physicsEntityId,_attachPosition,_partId,_bTerrain); }
	virtual void SetOwnerIdAndWeaponClassName(const unsigned _ownerId, string const &_weaponName);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	virtual bool HideDisplayName(IEntity const *const _pEntity) const;
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	static bool GivePlayerGrenadeAmmo(const char *_pArchetypeName, bool _bEquip) { return FGivePlayerGrenadeAmmo(_pArchetypeName,_bEquip); }
	virtual void ReInitFromPool();
	virtual bool IsUsingExpensiveParticles() const;
	void TriggerGrenade() { FTriggerGrenade(this); }
	virtual void Destroy(const bool _bDeleting, const bool _bDestroyImmediate);
	virtual void StartDestroy();
	void CleanupVisuals() { FCleanupVisuals(this); }
	static CArkProjectileGrenade *SpawnProjectile(IEntityArchetype *const _pArchetype, Vec3 const &_position, Vec3 const &_direction, const unsigned _weaponId, string _weaponClassName, const bool _bIsCritical, const bool _bIsPooled, const unsigned _extendedFlags, const unsigned _groupId, const bool _bSpawnFromCamera) { return FSpawnProjectile(_pArchetype,_position,_direction,_weaponId,_weaponClassName,_bIsCritical,_bIsPooled,_extendedFlags,_groupId,_bSpawnFromCamera); }
	virtual void Pulse();
	virtual void CheckProximity(const float _frametime);
	void ClearProximityAttachment() { FClearProximityAttachment(this); }
	virtual void LoadCachedProperties();
	virtual void CheckForCheapParticleUse();
	
#if 0
	ArkDisruptable &GetArkDisruptable();
	bool CanBeDisrupted() const;
	bool IsProximity() const;
	bool CanPickup() const;
#endif
	
	static inline auto FBitNotCArkProjectileGrenade = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x165C530);
	static inline auto FIsGrenade = PreyFunction<bool(CArkProjectileGrenade const *const _this)>(0x1B933B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectileGrenade const *const _this, ICrySizer *_s)>(0x165F220);
	static inline auto FInit = PreyFunction<bool(CArkProjectileGrenade *const _this, IGameObject *_pGameObject)>(0x165FDC0);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileGrenade *const _this, IGameObject *_pGameObject)>(0x16611A0);
	static inline auto FRelease = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x1661730);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileGrenade *const _this, TSerialize _ser)>(0x165EC10);
	static inline auto FPostSerialize = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x1661250);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileGrenade *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x1661BC0);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileGrenade *const _this, SGameObjectEvent const &_event)>(0x165F900);
	static inline auto FProcessEvent = PreyFunction<void(CArkProjectileGrenade *const _this, SEntityEvent &_event)>(0x16612D0);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkProjectileGrenade const *const _this)>(0x158AEF0);
	static inline auto FOnEntityKilledEarly = PreyFunction<void(CArkProjectileGrenade *const _this, HitInfo const &_hitInfo)>(0xA13080);
	static inline auto FOnEntityKilled = PreyFunction<void(CArkProjectileGrenade *const _this, HitInfo const &_hitInfo)>(0x1660DD0);
	static inline auto FOnEntityBroken = PreyFunction<void(CArkProjectileGrenade *const _this, const unsigned _brokenEntityId)>(0x1660CA0);
	static inline auto FOnDisruptedChanged = PreyFunction<void(CArkProjectileGrenade *const _this, bool _bDisrupted, bool _bWasForced)>(0x1660C40);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(CArkProjectileGrenade const *const _this)>(0x165F570);
	static inline auto FOnStartCarry = PreyFunction<void(CArkProjectileGrenade *const _this, IEntity *const _pEntity)>(0x1660EC0);
	static inline auto FTakeDamage = PreyFunction<void(CArkProjectileGrenade *const _this, const float _damage, const unsigned _responsibleEntityId)>(0x16619A0);
	static inline auto FDetonate = PreyFunction<bool(CArkProjectileGrenade *const _this)>(0x165E5E0);
	static inline auto FDoDetonation = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x165E6D0);
	static inline auto FGetProjectileGrenadeFromEntityId = PreyFunction<CArkProjectileGrenade *(const unsigned _entityId)>(0x165F240);
	static inline auto FAttachToPhysicsEntity = PreyFunction<void(CArkProjectileGrenade *const _this, const int _physicsEntityId, Vec3 const &_attachPosition, const int _partId, const bool _bTerrain)>(0x165C8B0);
	static inline auto FSetOwnerIdAndWeaponClassName = PreyFunction<void(CArkProjectileGrenade *const _this, const unsigned _ownerId, string const &_weaponName)>(0x16617E0);
	static inline auto FOnInteraction = PreyFunction<bool(CArkProjectileGrenade *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x1660DE0);
	static inline auto FTestInteraction = PreyFunction<bool(CArkProjectileGrenade const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1661AF0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(CArkProjectileGrenade const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1660F30);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(CArkProjectileGrenade const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0x1660FB0);
	static inline auto FHideDisplayName = PreyFunction<bool(CArkProjectileGrenade const *const _this, IEntity const *const _pEntity)>(0x165FDA0);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkProjectileGrenade *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x1660DB0);
	static inline auto FGivePlayerGrenadeAmmo = PreyFunction<bool(const char *_pArchetypeName, bool _bEquip)>(0x165F5F0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x1661650);
	static inline auto FIsUsingExpensiveParticles = PreyFunction<bool(CArkProjectileGrenade const *const _this)>(0x165FE10);
	static inline auto FTriggerGrenade = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x1661B30);
	static inline auto FDestroy = PreyFunction<void(CArkProjectileGrenade *const _this, const bool _bDeleting, const bool _bDestroyImmediate)>(0x165E500);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x1661980);
	static inline auto FCleanupVisuals = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x165E370);
	static inline auto FSpawnProjectile = PreyFunction<CArkProjectileGrenade *(IEntityArchetype *const _pArchetype, Vec3 const &_position, Vec3 const &_direction, const unsigned _weaponId, string _weaponClassName, const bool _bIsCritical, const bool _bIsPooled, const unsigned _extendedFlags, const unsigned _groupId, const bool _bSpawnFromCamera)>(0x1661800);
	static inline auto FPulse = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x1661480);
	static inline auto FCheckProximity = PreyFunction<void(CArkProjectileGrenade *const _this, const float _frametime)>(0x165DB40);
	static inline auto FClearProximityAttachment = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x165E3E0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x165FE40);
	static inline auto FCheckForCheapParticleUse = PreyFunction<void(CArkProjectileGrenade *const _this)>(0x165DB00);
};

