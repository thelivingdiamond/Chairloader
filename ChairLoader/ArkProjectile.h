#pragma once
#include "pch.h"

class CArkProjectile : CGameObjectExtensionHelper<CArkProjectile, IGameObjectExtension, 64>
{
public:
	virtual bool IsGrenade() = 0;
	virtual void ReInitFromPool() = 0;
	virtual void SetOwnerIdAndWeaponClassName(const unsigned int, const CryStringT<char>*) = 0;
	virtual void Destroy(const bool, const bool) = 0;
	virtual void StartDestroy() = 0;
	virtual bool IsUsingExpensiveParticles() = 0;
	virtual void LoadCachedProperties() = 0;
	virtual void Physicalize(const CryStringT<char>*) = 0;
	virtual void SetPhysicsParameters(const CryStringT<char>*, const bool) = 0;
	virtual void LoadModel() = 0;
	virtual void DoDamage(const EventPhysCollision*, const unsigned int*, const int) = 0;
	virtual CryStringT<char>* GetModelFilename(CryStringT<char>* result, const ArkSafeScriptTable*) = 0;
	virtual void StartParticleEffect(ArkFireAndForgetEffect*, const char*, const float, const Vec3_tpl<float>*) = 0;
	virtual void AttachParticleEffectsForLiveProjectiles() = 0;
	virtual void CheckForCheapParticleUse() = 0;

	class ArkProjectileFFEffect
	{
		ArkFireAndForgetEffect m_expensiveEffect;
		ArkFireAndForgetEffect m_cheapEffect;
		bool m_bUseCheapEffect;
		float m_scale;
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
	unsigned int m_ownerFaction;
	ArkFireAndForgetEffect m_collisionEffect;
	CArkProjectile::ArkProjectileFFEffect m_explosionEffect;
	ArkSimpleTimer m_gravityTimer;
	unsigned int m_ownerId;
	CryStringT<char> m_weaponClassName;
	ArkSimpleTimer m_ownerNotCollidingTimer;
	unsigned __int64 m_packageId;
	unsigned int m_groupId;
	Vec3_tpl<float> m_spawnPosition;
	ArkEntityEffect m_projectileEffect;
	ArkEntityEffect m_trailEffect;
};
class CArkProjectileGoo : CArkProjectile
{
public:
	class ArkGooSpawnParameters
	{
		unsigned int m_projectileId;
		CryStringT<char> m_weaponClassName;
		int m_hitPhysicsId;
		unsigned int m_spawnerId;
		unsigned int m_ownerId;
		Vec3_tpl<float> m_finalPoint;
		Vec3_tpl<float> m_spawnDirection;
		int m_partId;
		float m_spawnSize;
		float m_speedScale;
		int m_surfaceIndex;
		int m_attachedPhysicsId;
		bool m_bTerrain;
	};
	class GooSpawningProperties
	{
		float m_gooImpulseApplied;
		float m_gooMovementSpeed;
		float m_offsetAttachOfInitialSpawn;
		ArkInterval<float> m_gooAttachOffsetAsPercentScaleRange;
	};
	enum EArkGooState
	{
		none = 0,
		adding = 1,
		locked = 2
	};
	CArkProjectileGoo::GooSpawningProperties m_spawnProperties;
	bool m_bAutomaticallyScaleInitial;
	bool m_bStopFiringOnBurst;
	int m_maxNumberGooBallsToSpawn;
	unsigned int m_decalId;
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
	CryStringT<char> m_scaleUpMaterial;
	ArkInterval<float> m_timeToScaleChildrenRange;
	ArkInterval<float> m_timeToScaleAutomaticallyRange;
	ArkInterval<float> m_finalScaleStaticRange;
	ArkInterval<float> m_finalScaleDynamicRange;
	ArkInterval<float> m_initialScaleStaticRange;
	ArkInterval<float> m_initialScaleDynamicRange;
	unsigned __int64 m_collisionSignalPackage;
	unsigned __int64 m_hardenedGooSignalPackage;
	unsigned __int64 m_maxedGooSignalPackage;
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
	Vec3_tpl<float> m_initialNormalLocal;
	Vec3_tpl<float> m_initialPositionLocal;
	Vec3_tpl<float> m_finalPosition;
	bool m_bIsStatic;
	bool m_bAttachedToMovableStatic;
	int m_staticPhysicsId;
	int m_attachedPhysicsId;
	int m_attachedPartId;
	bool m_bAttachedTerrain;
	AABB m_regenNavMeshAABB;
	bool m_bHasRegeneratedNavMesh;
	IMaterial* m_pMaterial;
	IMaterial* m_pClonedScaleUpMaterial;
	unsigned int m_spawnerId;
	ArkSimpleTimer m_spawnChildrenTimer;
	float m_offsetPercent;
	ArkEntityEffect m_burstAndSpawnEffect;
	ArkEntityEffect m_lockedEffect;
	std::vector<CArkProjectileGoo::ArkGooSpawnParameters> m_spawningGooList;
	ArkGooSignalReceiver m_signalReceiver;
	CArkProjectile::ArkProjectileFFEffect m_collisionLockedEffect;
	CArkProjectile::ArkProjectileFFEffect m_collisionNotLockedEffect;
};