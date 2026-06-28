// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/ArkProjectile.h>

struct IEntity;
struct IEntityArchetype;
struct IParticleEffect;
struct SEntityUpdateContext;

// CArkProjectileMatter
// Header:  Prey/GameDll/ark/weapons/ArkProjectileMatter.h
class CArkProjectileMatter : public CArkProjectile
{ // Size=952 (0x3B8)
public:
	Vec3 m_spawnPosition;
	Vec3 m_targetPosition;
	ArkLooseEffect m_fireEffect;
	ArkLooseEffect m_telegraphEffect;
	_smart_ptr<IParticleEffect> m_pImpactEffect;
	unsigned m_targetEntityId;
	uint64_t m_impactCameraShakeId;
	float m_maxSpeed;
	float m_trackingStrength;

	CArkProjectileMatter();
	virtual ~CArkProjectileMatter();
	virtual void StartDestroy();
	virtual void LoadCachedProperties();
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void Destroy(const bool _bDeleting, const bool _bDestroyImmediate);
	static CArkProjectileMatter* SpawnProjectile(IEntityArchetype& _archetype, const Vec3& _spawnPosition, const Vec3& _targetPosition) { return FSpawnProjectileOv1(_archetype, _spawnPosition, _targetPosition); }
	static CArkProjectileMatter* SpawnProjectile(IEntityArchetype& _archetype, const Vec3& _spawnPosition, const IEntity& _targetEntity) { return FSpawnProjectileOv0(_archetype, _spawnPosition, _targetEntity); }
	void Fire(const Vec3& _targetPosition) { FFire(this, _targetPosition); }
	virtual unsigned GetWeaponOwnerId() const;

	static inline auto FCArkProjectileMatterOv1 = PreyFunction<void(CArkProjectileMatter* const _this)>(0x14885B0);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectileMatter* const _this)>(0x14894D0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileMatter* const _this)>(0x1488B20);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileMatter* const _this, TSerialize _ser)>(0x1488A90);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileMatter* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x14899D0);
	static inline auto FDestroy = PreyFunction<void(CArkProjectileMatter* const _this, const bool _bDeleting, const bool _bDestroyImmediate)>(0x14886A0);
	static inline auto FSpawnProjectileOv1 = PreyFunction<CArkProjectileMatter* (IEntityArchetype& _archetype, const Vec3& _spawnPosition, const Vec3& _targetPosition)>(0x1489070);
	static inline auto FSpawnProjectileOv0 = PreyFunction<CArkProjectileMatter* (IEntityArchetype& _archetype, const Vec3& _spawnPosition, const IEntity& _targetEntity)>(0x1489470);
	static inline auto FFire = PreyFunction<void(CArkProjectileMatter* const _this, const Vec3& _targetPosition)>(0x14887B0);
	static inline auto FGetWeaponOwnerId = PreyFunction<unsigned(const CArkProjectileMatter* const _this)>(0x1508070);
};
#endif // MOONCRASH
