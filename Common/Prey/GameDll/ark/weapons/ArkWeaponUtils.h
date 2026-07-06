// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryPhysics/physinterface.h>

class CArkProjectileGoo;
class CArkWeapon;
struct EventPhysCollision;
struct HitInfo;
struct IEntity;
struct IEntityClass;
struct IMaterial;
struct IPhysicalEntity;
struct ISurfaceType;
namespace primitives
{
struct primitive;
} // namespace primitives
struct ray_hit;

// Header: Exact
// Prey/GameDll/ark/weapons/ArkWeaponUtils.h
class ArkWeaponUtils // Id=8017530 Size=1
{
public:
	struct PhysicsMaterialInfo // Id=8017531 Size=64
	{
		IMaterial *m_pMaterial;
		int m_hitIndex;
		IPhysicalEntity *m_pCollider;
		Vec3 m_hitPosition;
		Vec3 m_hitDirection;
		int m_partId;
		int m_surfaceIndex;
		int m_iPrim;
	};

	struct ArkExplosionInfo // Id=8017532 Size=168
	{
		pe_explosion m_physicsData;
		uint64_t m_packageId;
		uint64_t m_cameraShakeId;
		float m_impulseFromCenter;
		float m_packageMinRadius;
		float m_packageMaxRadius;
		float m_impulseMinRadius;
		float m_impulseMaxRadius;
		bool m_bCheckLOS;
		bool m_bBreaksGlass;
		std::vector<IPhysicalEntity *> explodedPhysicsEntities;
		
		ArkExplosionInfo(Vec3 const &_center, const float _minRadius, const float _maxRadius, const uint64_t _packageId, const float _impulseFromCenter, const bool _bCheckLOS, const bool _bBreaksGlass, const uint64_t _cameraShakeId);
	};

	static IEntityClass *k_pGeomEntityClass;
	
	static ArkWeaponUtils::PhysicsMaterialInfo FindMaterialAndUpdateValidHit(ray_hit const *const _pRayHits, const int _numHits, Vec3 const &_originalDirection) { return FFindMaterialAndUpdateValidHit(_pRayHits,_numHits,_originalDirection); }
	static Vec3 CalculateOffsetPointInSquare(IEntity const *const _pEntity, Quat const &_rotation, const float _stepColumn, const float _stepRow, const int _numColumn, const int _numRow) { return FCalculateOffsetPointInSquare(_pEntity,_rotation,_stepColumn,_stepRow,_numColumn,_numRow); }
	static Vec3 CalculatePointInCircle(IEntity const *const _pEntity, Vec3 const &_centerPoint, Quat const &_rotation, const float _minAngleRadians, const float _maxAngleRadians, const float _minDistance, const float _maxDistance) { return FCalculatePointInCircle(_pEntity,_centerPoint,_rotation,_minAngleRadians,_maxAngleRadians,_minDistance,_maxDistance); }
	static CArkProjectileGoo *GetProjectileGooBall(IPhysicalEntity *const _pHitPhysics) { return FGetProjectileGooBall(_pHitPhysics); }
	static void GenerateFakeCollision(EventPhysCollision &_collisionEventInfo, ArkWeaponUtils::PhysicsMaterialInfo const &_materialInfo, Vec3 _hitDir, IEntity *const _pWeaponEntity, IPhysicalEntity *const _pOwnerPhysics, const float _damage, const float _radius, const bool _bSendEvent, const int16_t _matId) { FGenerateFakeCollision(_collisionEventInfo,_materialInfo,_hitDir,_pWeaponEntity,_pOwnerPhysics,_damage,_radius,_bSendEvent,_matId); }
	static float CollideBeam(EventPhysCollision &_collisionEventInfo, Vec3 const &_raycastStart, Vec3 const &_raycastDir, const float _beamLength, const bool _bSkipOwner, unsigned _ownerId, IEntity *_pEntity, const bool _bSendEvent, const bool _bProjectile, const int _customSurfaceId) { return FCollideBeam(_collisionEventInfo,_raycastStart,_raycastDir,_beamLength,_bSkipOwner,_ownerId,_pEntity,_bSendEvent,_bProjectile,_customSurfaceId); }
	static bool CannotAttachGooInGravity(IPhysicalEntity *const _pPhysics) { return FCannotAttachGooInGravity(_pPhysics); }
	static bool CanGooAttachToSurface(IMaterial *const _pMaterial) { return FCanGooAttachToSurfaceOv1(_pMaterial); }
	static bool CanGooAttachToSurface(const int _surfaceIndex) { return FCanGooAttachToSurfaceOv0(_surfaceIndex); }
	static bool IsAttachingToStatic(IPhysicalEntity *_pCurrentHitPhysics) { return FIsAttachingToStatic(_pCurrentHitPhysics); }
	static bool IsStaticPhysics(IPhysicalEntity *_pPhysics) { return FIsStaticPhysics(_pPhysics); }
	static std::pair<float,bool> GetDamageScaleAgainstTarget(unsigned _target, std::vector<unsigned __int64> *_pSneakAttackMetaTags) { return FGetDamageScaleAgainstTarget(_target,_pSneakAttackMetaTags); }
	static void OnHit(bool _bIsCritical, unsigned _target) { FOnHit(_bIsCritical,_target); }
	static void SendExplosion(const unsigned _senderId, const unsigned _instigatorId, const float _signalScale, std::vector<unsigned __int64> *_pSneakAttackMetaTags, const float _mininumSignalScale, ArkWeaponUtils::ArkExplosionInfo &_arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity *> &)) { FSendExplosionOv1(_senderId,_instigatorId,_signalScale,_pSneakAttackMetaTags,_mininumSignalScale,_arkExplosionInfo,_leverageFlags,_entTypes,_UpdateEntitiesFunction); }
	static void SendExplosion(const unsigned _senderId, const unsigned _instigatorId, const float _signalScale, std::vector<unsigned __int64> *_pSneakAttackMetaTags, const float _mininumSignalScale, ArkWeaponUtils::ArkExplosionInfo const &_arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity *> &)) { FSendExplosionOv0(_senderId,_instigatorId,_signalScale,_pSneakAttackMetaTags,_mininumSignalScale,_arkExplosionInfo,_leverageFlags,_entTypes,_UpdateEntitiesFunction); }
	static void RemoveGooAttachedToEntity(IEntity const &_rEntity) { FRemoveGooAttachedToEntity(_rEntity); }
	static bool HandleGooOverlappingEntity(IEntity const &_rEntity, const bool _bDestroy) { return FHandleGooOverlappingEntity(_rEntity,_bDestroy); }
	static bool IsGlass(const int _surface_idx) { return FIsGlass(_surface_idx); }
	static std::vector<ray_hit> FindEntitiesInShape(Vec3 const &_position, Vec3 const &_direction, const float _range, const float _size, const int _flags, const int _primitiveType, primitives::primitive *_pShape, IEntity const *const _pIgnoreEntity) { return FFindEntitiesInShape(_position,_direction,_range,_size,_flags,_primitiveType,_pShape,_pIgnoreEntity); }
	static float GetRadiusOfCone(const float _coneAngle, const float _coneLength) { return FGetRadiusOfCone(_coneAngle,_coneLength); }
	static bool FindMaterialFromPhysicsPart(IPhysicalEntity *const _pPhysicsEntity, const int _ipart, Vec3 const &_worldPosition, Vec3 const &_worldDirection, ArkWeaponUtils::PhysicsMaterialInfo &_materialInfo, const int _defaultSurfaceIndex) { return FFindMaterialFromPhysicsPart(_pPhysicsEntity,_ipart,_worldPosition,_worldDirection,_materialInfo,_defaultSurfaceIndex); }
	static IPhysicalEntity *GetPhysicsEntityFromEntityId(const unsigned _entityId) { return FGetPhysicsEntityFromEntityId(_entityId); }
	static IEntity *GetEntityFromPhysicsId(const int _physicsId) { return FGetEntityFromPhysicsId(_physicsId); }
	static void DoHitImpulse(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitPosition, Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale) { FDoHitImpulseOv1(_pHitEntity,_pHitPhysics,_hitPosition,_hitDirection,_partid,_impulseScale,_minMassScale,_maxMassScale); }
	static void DoHitImpulse(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale) { FDoHitImpulseOv0(_pHitEntity,_pHitPhysics,_hitDirection,_partid,_impulseScale,_minMassScale,_maxMassScale); }
	static void DoWeaponImpulse(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitPosition, Vec3 _hitDirection, const int _partid, CArkWeapon const *const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale) { FDoWeaponImpulseOv1(_pHitEntity,_pHitPhysics,_hitPosition,_hitDirection,_partid,_pWeapon,_impulseScale,_minMassScale,_maxMassScale); }
	static void DoWeaponImpulse(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitDirection, const int _partid, CArkWeapon const *const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale) { FDoWeaponImpulseOv0(_pHitEntity,_pHitPhysics,_hitDirection,_partid,_pWeapon,_impulseScale,_minMassScale,_maxMassScale); }
	
#if 0
	static IEntityClass *GetGeomEntityClass();
	static bool CanGooAttachToEntity(IPhysicalEntity *arg0);
	static bool CanGooAttachToSurface(ISurfaceType const *const arg0);
	static void SendSignalToEntity(IPhysicalEntity *arg0, unsigned arg1, uint64_t arg2, HitInfo *arg3);
	static bool IsAmmo(IEntity const &arg0);
#endif
	
	static inline auto FFindMaterialAndUpdateValidHit = PreyFunction<ArkWeaponUtils::PhysicsMaterialInfo(ray_hit const *const _pRayHits, const int _numHits, Vec3 const &_originalDirection)>(0x1680F20);
	static inline auto FCalculateOffsetPointInSquare = PreyFunction<Vec3(IEntity const *const _pEntity, Quat const &_rotation, const float _stepColumn, const float _stepRow, const int _numColumn, const int _numRow)>(0x167F790);
	static inline auto FCalculatePointInCircle = PreyFunction<Vec3(IEntity const *const _pEntity, Vec3 const &_centerPoint, Quat const &_rotation, const float _minAngleRadians, const float _maxAngleRadians, const float _minDistance, const float _maxDistance)>(0x167F990);
	static inline auto FGetProjectileGooBall = PreyFunction<CArkProjectileGoo *(IPhysicalEntity *const _pHitPhysics)>(0x1681900);
	static inline auto FGenerateFakeCollision = PreyFunction<void(EventPhysCollision &_collisionEventInfo, ArkWeaponUtils::PhysicsMaterialInfo const &_materialInfo, Vec3 _hitDir, IEntity *const _pWeaponEntity, IPhysicalEntity *const _pOwnerPhysics, const float _damage, const float _radius, const bool _bSendEvent, const int16_t _matId)>(0x1681520);
	static inline auto FCollideBeam = PreyFunction<float(EventPhysCollision &_collisionEventInfo, Vec3 const &_raycastStart, Vec3 const &_raycastDir, const float _beamLength, const bool _bSkipOwner, unsigned _ownerId, IEntity *_pEntity, const bool _bSendEvent, const bool _bProjectile, const int _customSurfaceId)>(0x167FD90);
	static inline auto FCannotAttachGooInGravity = PreyFunction<bool(IPhysicalEntity *const _pPhysics)>(0x167FC90);
	static inline auto FCanGooAttachToSurfaceOv1 = PreyFunction<bool(IMaterial *const _pMaterial)>(0x167FC30);
	static inline auto FCanGooAttachToSurfaceOv0 = PreyFunction<bool(const int _surfaceIndex)>(0x167FBB0);
	static inline auto FIsAttachingToStatic = PreyFunction<bool(IPhysicalEntity *_pCurrentHitPhysics)>(0x1681DB0);
	static inline auto FIsStaticPhysics = PreyFunction<bool(IPhysicalEntity *_pPhysics)>(0x1681EF0);
	static inline auto FGetDamageScaleAgainstTarget = PreyFunction<std::pair<float,bool>(unsigned _target, std::vector<unsigned __int64> *_pSneakAttackMetaTags)>(0x16816C0);
	static inline auto FOnHit = PreyFunction<void(bool _bIsCritical, unsigned _target)>(0x1681F80);
	static inline auto FSendExplosionOv1 = PreyFunction<void(const unsigned _senderId, const unsigned _instigatorId, const float _signalScale, std::vector<unsigned __int64> *_pSneakAttackMetaTags, const float _mininumSignalScale, ArkWeaponUtils::ArkExplosionInfo &_arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity *> &))>(0x16820B0);
	static inline auto FSendExplosionOv0 = PreyFunction<void(const unsigned _senderId, const unsigned _instigatorId, const float _signalScale, std::vector<unsigned __int64> *_pSneakAttackMetaTags, const float _mininumSignalScale, ArkWeaponUtils::ArkExplosionInfo const &_arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity *> &))>(0x1682540);
	static inline auto FRemoveGooAttachedToEntity = PreyFunction<void(IEntity const &_rEntity)>(0x1682080);
	static inline auto FHandleGooOverlappingEntity = PreyFunction<bool(IEntity const &_rEntity, const bool _bDestroy)>(0x1681A10);
	static inline auto FIsGlass = PreyFunction<bool(const int _surface_idx)>(0x1681E90);
	static inline auto FFindEntitiesInShape = PreyFunction<std::vector<ray_hit>(Vec3 const &_position, Vec3 const &_direction, const float _range, const float _size, const int _flags, const int _primitiveType, primitives::primitive *_pShape, IEntity const *const _pIgnoreEntity)>(0x1680AF0);
	static inline auto FGetRadiusOfCone = PreyFunction<float(const float _coneAngle, const float _coneLength)>(0x16819F0);
	static inline auto FFindMaterialFromPhysicsPart = PreyFunction<bool(IPhysicalEntity *const _pPhysicsEntity, const int _ipart, Vec3 const &_worldPosition, Vec3 const &_worldDirection, ArkWeaponUtils::PhysicsMaterialInfo &_materialInfo, const int _defaultSurfaceIndex)>(0x16810F0);
	static inline auto FGetPhysicsEntityFromEntityId = PreyFunction<IPhysicalEntity *(const unsigned _entityId)>(0x16818D0);
	static inline auto FGetEntityFromPhysicsId = PreyFunction<IEntity *(const int _physicsId)>(0x1681890);
	static inline auto FDoHitImpulseOv1 = PreyFunction<void(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitPosition, Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale)>(0x16803D0);
	static inline auto FDoHitImpulseOv0 = PreyFunction<void(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale)>(0x16805F0);
	static inline auto FDoWeaponImpulseOv1 = PreyFunction<void(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitPosition, Vec3 _hitDirection, const int _partid, CArkWeapon const *const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale)>(0x16807C0);
	static inline auto FDoWeaponImpulseOv0 = PreyFunction<void(IEntity *const _pHitEntity, IPhysicalEntity *const _pHitPhysics, Vec3 _hitDirection, const int _partid, CArkWeapon const *const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale)>(0x1680A10);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryPhysics/physinterface.h>

class CArkProjectileGoo;
class CArkWeapon;
struct EventPhysCollision;
struct HitInfo;
struct IEntity;
struct IEntityClass;
struct IMaterial;
struct IPhysicalEntity;
struct ISurfaceType;
namespace primitives
{
struct primitive;
} // namespace primitives

// ArkWeaponUtils
// Header:  Prey/GameDll/ark/weapons/ArkWeaponUtils.h
class ArkWeaponUtils
{ // Size=1 (0x1)
public:
	// ArkWeaponUtils::PhysicsMaterialInfo
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponUtils.h
	struct PhysicsMaterialInfo
	{ // Size=64 (0x40)
		IMaterial* m_pMaterial;
		int m_hitIndex;
		IPhysicalEntity* m_pCollider;
		Vec3 m_hitPosition;
		Vec3 m_hitDirection;
		int m_partId;
		int m_surfaceIndex;
		int m_iPrim;

	#if 0
		PhysicsMaterialInfo();
	#endif
	};

	// ArkWeaponUtils::ArkExplosionInfo
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponUtils.h
	struct ArkExplosionInfo
	{ // Size=168 (0xA8)
		pe_explosion m_physicsData;
		uint64_t m_packageId;
		uint64_t m_cameraShakeId;
		float m_impulseFromCenter;
		float m_packageMinRadius;
		float m_packageMaxRadius;
		float m_impulseMinRadius;
		float m_impulseMaxRadius;
		bool m_bCheckLOS;
		bool m_bBreaksGlass;
		bool m_bShowOnHit;
		std::vector<IPhysicalEntity*> explodedPhysicsEntities;

		ArkExplosionInfo(const Vec3& _center, const float _minRadius, const float _maxRadius, const uint64_t _packageId, const float _impulseFromCenter, const bool _bCheckLOS, const bool _bBreaksGlass, const uint64_t _cameraShakeId);

	#if 0
		ArkExplosionInfo(const Vec3& _arg0_, const float _arg1_, const float _arg2_, const float _arg3_, const float _arg4_, const uint64_t _arg5_, const float _arg6_, const bool _arg7_, const bool _arg8_, const uint64_t _arg9_);
	#endif

		static inline auto FArkExplosionInfoOv3 = PreyFunction<void(ArkWeaponUtils::ArkExplosionInfo* const _this, const Vec3& _center, const float _minRadius, const float _maxRadius, const uint64_t _packageId, const float _impulseFromCenter, const bool _bCheckLOS, const bool _bBreaksGlass, const uint64_t _cameraShakeId)>(0x16AE290);
	};

	static inline auto k_pGeomEntityClass = PreyGlobal<IEntityClass*>(0x2D82130);

	static ArkWeaponUtils::PhysicsMaterialInfo FindMaterialAndUpdateValidHit(const ray_hit* const _pRayHits, const int _numHits, const Vec3& _originalDirection) { return FFindMaterialAndUpdateValidHit(_pRayHits, _numHits, _originalDirection); }
	static Vec3 CalculateOffsetPointInSquare(const IEntity* const _pEntity, const Quat& _rotation, const float _stepColumn, const float _stepRow, const int _numColumn, const int _numRow) { return FCalculateOffsetPointInSquare(_pEntity, _rotation, _stepColumn, _stepRow, _numColumn, _numRow); }
	static Vec3 CalculatePointInCircle(const IEntity* const _pEntity, const Vec3& _centerPoint, const Quat& _rotation, const float _minAngleRadians, const float _maxAngleRadians, const float _minDistance, const float _maxDistance) { return FCalculatePointInCircle(_pEntity, _centerPoint, _rotation, _minAngleRadians, _maxAngleRadians, _minDistance, _maxDistance); }
	static CArkProjectileGoo* GetProjectileGooBall(IPhysicalEntity* const _pHitPhysics) { return FGetProjectileGooBall(_pHitPhysics); }
	static void GenerateFakeCollision(EventPhysCollision& _collisionEventInfo, const ArkWeaponUtils::PhysicsMaterialInfo& _materialInfo, const Vec3 _hitDir, IEntity* const _pWeaponEntity, IPhysicalEntity* const _pOwnerPhysics, const float _damage, const float _radius, const bool _bSendEvent, const int16_t _matId) { FGenerateFakeCollision(_collisionEventInfo, _materialInfo, _hitDir, _pWeaponEntity, _pOwnerPhysics, _damage, _radius, _bSendEvent, _matId); }
	static float CollideBeam(EventPhysCollision& _collisionEventInfo, const Vec3& _raycastStart, const Vec3& _raycastDir, const float _beamLength, const bool _bSkipOwner, unsigned _ownerId, IEntity* _pEntity, const bool _bSendEvent, const bool _bProjectile, const int _customSurfaceId) { return FCollideBeam(_collisionEventInfo, _raycastStart, _raycastDir, _beamLength, _bSkipOwner, _ownerId, _pEntity, _bSendEvent, _bProjectile, _customSurfaceId); }
	static bool CannotAttachGooInGravity(IPhysicalEntity* const _pPhysics) { return FCannotAttachGooInGravity(_pPhysics); }
	static void HandleGooCollison(IPhysicalEntity* _gooPhysics, IPhysicalEntity* _pPhysicalEntity, IEntity* _pEntity, Vec3& _spawnPosition, Vec3& _spawnDirection) { FHandleGooCollison(_gooPhysics, _pPhysicalEntity, _pEntity, _spawnPosition, _spawnDirection); }
	static bool CanGooAttachToSurface(IMaterial* const _pMaterial) { return FCanGooAttachToSurfaceOv1(_pMaterial); }
	static bool CanGooAttachToSurface(const int _surfaceIndex) { return FCanGooAttachToSurfaceOv0(_surfaceIndex); }
	static void SendWeaponEnchantmentSignalsToEntity(CArkWeapon* _pWeapon, unsigned _targetId, unsigned _senderId, HitInfo* hitInfo) { FSendWeaponEnchantmentSignalsToEntity(_pWeapon, _targetId, _senderId, hitInfo); }
	static void SendWeaponEnchantmentAOESignalToEntity(const CArkWeapon* const _pWeapon, const Vec3& _targetPos, const unsigned _senderId) { FSendWeaponEnchantmentAOESignalToEntity(_pWeapon, _targetPos, _senderId); }
	static void PlayWeaponEnchantmentEffect(const CArkWeapon* const _pWeapon, const Vec3& _position, const Vec3& _normal) { FPlayWeaponEnchantmentEffect(_pWeapon, _position, _normal); }
	static bool IsAttachingToStatic(IPhysicalEntity* _pCurrentHitPhysics) { return FIsAttachingToStatic(_pCurrentHitPhysics); }
	static bool IsStaticPhysics(IPhysicalEntity* _pPhysics) { return FIsStaticPhysics(_pPhysics); }
	static std::pair<float, bool> GetDamageScaleAgainstTarget(unsigned _target, const std::vector<uint64_t>* const _pSneakAttackMetaTags) { return FGetDamageScaleAgainstTarget(_target, _pSneakAttackMetaTags); }
	static void OnHit(bool _bIsCritical, bool _bResistant, unsigned _target) { FOnHit(_bIsCritical, _bResistant, _target); }
	static void SendExplosion(const unsigned _senderId, const unsigned _instigatorId, const unsigned _weaponId, const float _signalScale, std::vector<uint64_t>* _pSneakAttackMetaTags, const float _mininumSignalScale, ArkWeaponUtils::ArkExplosionInfo& _arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity*>&)) { FSendExplosionOv1(_senderId, _instigatorId, _weaponId, _signalScale, _pSneakAttackMetaTags, _mininumSignalScale, _arkExplosionInfo, _leverageFlags, _entTypes, _UpdateEntitiesFunction); }
	static void SendExplosion(const unsigned _senderId, const unsigned _instigatorId, const unsigned _weaponId, const float _signalScale, std::vector<uint64_t>* _pSneakAttackMetaTags, const float _mininumSignalScale, const ArkWeaponUtils::ArkExplosionInfo& _arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity*>&)) { FSendExplosionOv0(_senderId, _instigatorId, _weaponId, _signalScale, _pSneakAttackMetaTags, _mininumSignalScale, _arkExplosionInfo, _leverageFlags, _entTypes, _UpdateEntitiesFunction); }
	static void RemoveGooAttachedToEntity(const IEntity& _rEntity, const float _radiusAOE) { FRemoveGooAttachedToEntity(_rEntity, _radiusAOE); }
	static bool HandleGooOverlappingEntity(const IEntity& _rEntity, const bool _bDestroy) { return FHandleGooOverlappingEntity(_rEntity, _bDestroy); }
	static bool IsGlass(const int _surface_idx) { return FIsGlass(_surface_idx); }
	static std::vector<ray_hit> FindEntitiesInShape(const Vec3& _position, const Vec3& _direction, const float _range, const float _size, const int _flags, const int _primitiveType, primitives::primitive* _pShape, const IEntity* const _pIgnoreEntity) { return FFindEntitiesInShape(_position, _direction, _range, _size, _flags, _primitiveType, _pShape, _pIgnoreEntity); }
	static float GetRadiusOfCone(const float _coneAngle, const float _coneLength) { return FGetRadiusOfCone(_coneAngle, _coneLength); }
	static bool FindMaterialFromPhysicsPart(IPhysicalEntity* const _pPhysicsEntity, const int _ipart, const Vec3& _worldPosition, const Vec3& _worldDirection, ArkWeaponUtils::PhysicsMaterialInfo& _materialInfo, const int _defaultSurfaceIndex) { return FFindMaterialFromPhysicsPart(_pPhysicsEntity, _ipart, _worldPosition, _worldDirection, _materialInfo, _defaultSurfaceIndex); }
	static IPhysicalEntity* GetPhysicsEntityFromEntityId(const unsigned _entityId) { return FGetPhysicsEntityFromEntityId(_entityId); }
	static IEntity* GetEntityFromPhysicsId(const int _physicsId) { return FGetEntityFromPhysicsId(_physicsId); }
	static void DoHitImpulse(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitPosition, const Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale) { FDoHitImpulseOv1(_pHitEntity, _pHitPhysics, _hitPosition, _hitDirection, _partid, _impulseScale, _minMassScale, _maxMassScale); }
	static void DoHitImpulse(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale) { FDoHitImpulseOv0(_pHitEntity, _pHitPhysics, _hitDirection, _partid, _impulseScale, _minMassScale, _maxMassScale); }
	static void DoWeaponImpulse(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitPosition, const Vec3 _hitDirection, const int _partid, const CArkWeapon* const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale) { FDoWeaponImpulseOv1(_pHitEntity, _pHitPhysics, _hitPosition, _hitDirection, _partid, _pWeapon, _impulseScale, _minMassScale, _maxMassScale); }
	static void DoWeaponImpulse(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitDirection, const int _partid, const CArkWeapon* const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale) { FDoWeaponImpulseOv0(_pHitEntity, _pHitPhysics, _hitDirection, _partid, _pWeapon, _impulseScale, _minMassScale, _maxMassScale); }

#if 0
	static IEntityClass* GetGeomEntityClass();
	static bool CanGooAttachToEntity(IPhysicalEntity* _arg0_);
	static bool CanGooAttachToSurface(const ISurfaceType* const _arg0_);
	static void SendSignalToEntity(IPhysicalEntity* _arg0_, unsigned _arg1_, uint64_t _arg2_, HitInfo* _arg3_);
	static bool IsAmmo(const IEntity& _arg0_);
#endif

	static inline auto FFindMaterialAndUpdateValidHit = PreyFunction<ArkWeaponUtils::PhysicsMaterialInfo(const ray_hit* const _pRayHits, const int _numHits, const Vec3& _originalDirection)>(0x17A47E0);
	static inline auto FCalculateOffsetPointInSquare = PreyFunction<Vec3(const IEntity* const _pEntity, const Quat& _rotation, const float _stepColumn, const float _stepRow, const int _numColumn, const int _numRow)>(0x17A3260);
	static inline auto FCalculatePointInCircle = PreyFunction<Vec3(const IEntity* const _pEntity, const Vec3& _centerPoint, const Quat& _rotation, const float _minAngleRadians, const float _maxAngleRadians, const float _minDistance, const float _maxDistance)>(0x17A3460);
	static inline auto FGetProjectileGooBall = PreyFunction<CArkProjectileGoo* (IPhysicalEntity* const _pHitPhysics)>(0x17A51C0);
	static inline auto FGenerateFakeCollision = PreyFunction<void(EventPhysCollision& _collisionEventInfo, const ArkWeaponUtils::PhysicsMaterialInfo& _materialInfo, const Vec3 _hitDir, IEntity* const _pWeaponEntity, IPhysicalEntity* const _pOwnerPhysics, const float _damage, const float _radius, const bool _bSendEvent, const int16_t _matId)>(0x17A4DE0);
	static inline auto FCollideBeam = PreyFunction<float(EventPhysCollision& _collisionEventInfo, const Vec3& _raycastStart, const Vec3& _raycastDir, const float _beamLength, const bool _bSkipOwner, unsigned _ownerId, IEntity* _pEntity, const bool _bSendEvent, const bool _bProjectile, const int _customSurfaceId)>(0x17A3860);
	static inline auto FCannotAttachGooInGravity = PreyFunction<bool(IPhysicalEntity* const _pPhysics)>(0x17A3760);
	static inline auto FHandleGooCollison = PreyFunction<void(IPhysicalEntity* _gooPhysics, IPhysicalEntity* _pPhysicalEntity, IEntity* _pEntity, Vec3& _spawnPosition, Vec3& _spawnDirection)>(0x17A52D0);
	static inline auto FCanGooAttachToSurfaceOv1 = PreyFunction<bool(IMaterial* const _pMaterial)>(0x17A3700);
	static inline auto FCanGooAttachToSurfaceOv0 = PreyFunction<bool(const int _surfaceIndex)>(0x17A3680);
	static inline auto FSendWeaponEnchantmentSignalsToEntity = PreyFunction<void(CArkWeapon* _pWeapon, unsigned _targetId, unsigned _senderId, HitInfo* hitInfo)>(0x17A6800);
	static inline auto FSendWeaponEnchantmentAOESignalToEntity = PreyFunction<void(const CArkWeapon* const _pWeapon, const Vec3& _targetPos, const unsigned _senderId)>(0x17A66B0);
	static inline auto FPlayWeaponEnchantmentEffect = PreyFunction<void(const CArkWeapon* const _pWeapon, const Vec3& _position, const Vec3& _normal)>(0x17A5B70);
	static inline auto FIsAttachingToStatic = PreyFunction<bool(IPhysicalEntity* _pCurrentHitPhysics)>(0x17A5890);
	static inline auto FIsStaticPhysics = PreyFunction<bool(IPhysicalEntity* _pPhysics)>(0x17A59D0);
	static inline auto FGetDamageScaleAgainstTarget = PreyFunction<std::pair<float, bool>(unsigned _target, const std::vector<uint64_t>* const _pSneakAttackMetaTags)>(0x17A4F80);
	static inline auto FOnHit = PreyFunction<void(bool _bIsCritical, bool _bResistant, unsigned _target)>(0x17A5A60);
	static inline auto FSendExplosionOv1 = PreyFunction<void(const unsigned _senderId, const unsigned _instigatorId, const unsigned _weaponId, const float _signalScale, std::vector<uint64_t>* _pSneakAttackMetaTags, const float _mininumSignalScale, ArkWeaponUtils::ArkExplosionInfo& _arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity*>&))>(0x17A6030);
	static inline auto FSendExplosionOv0 = PreyFunction<void(const unsigned _senderId, const unsigned _instigatorId, const unsigned _weaponId, const float _signalScale, std::vector<uint64_t>* _pSneakAttackMetaTags, const float _mininumSignalScale, const ArkWeaponUtils::ArkExplosionInfo& _arkExplosionInfo, const unsigned _leverageFlags, const int _entTypes, void (*_UpdateEntitiesFunction)(std::vector<IPhysicalEntity*>&))>(0x17A6550);
	static inline auto FRemoveGooAttachedToEntity = PreyFunction<void(const IEntity& _rEntity, const float _radiusAOE)>(0x17A5DD0);
	static inline auto FHandleGooOverlappingEntity = PreyFunction<bool(const IEntity& _rEntity, const bool _bDestroy)>(0x17A5430);
	static inline auto FIsGlass = PreyFunction<bool(const int _surface_idx)>(0x17A5970);
	static inline auto FFindEntitiesInShape = PreyFunction<std::vector<ray_hit>(const Vec3& _position, const Vec3& _direction, const float _range, const float _size, const int _flags, const int _primitiveType, primitives::primitive* _pShape, const IEntity* const _pIgnoreEntity)>(0x17A45C0);
	static inline auto FGetRadiusOfCone = PreyFunction<float(const float _coneAngle, const float _coneLength)>(0x17A52B0);
	static inline auto FFindMaterialFromPhysicsPart = PreyFunction<bool(IPhysicalEntity* const _pPhysicsEntity, const int _ipart, const Vec3& _worldPosition, const Vec3& _worldDirection, ArkWeaponUtils::PhysicsMaterialInfo& _materialInfo, const int _defaultSurfaceIndex)>(0x17A49B0);
	static inline auto FGetPhysicsEntityFromEntityId = PreyFunction<IPhysicalEntity* (const unsigned _entityId)>(0x17A5190);
	static inline auto FGetEntityFromPhysicsId = PreyFunction<IEntity* (const int _physicsId)>(0x17A5150);
	static inline auto FDoHitImpulseOv1 = PreyFunction<void(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitPosition, const Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale)>(0x17A3EA0);
	static inline auto FDoHitImpulseOv0 = PreyFunction<void(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitDirection, const int _partid, float _impulseScale, float _minMassScale, float _maxMassScale)>(0x17A40C0);
	static inline auto FDoWeaponImpulseOv1 = PreyFunction<void(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitPosition, const Vec3 _hitDirection, const int _partid, const CArkWeapon* const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale)>(0x17A4290);
	static inline auto FDoWeaponImpulseOv0 = PreyFunction<void(IEntity* const _pHitEntity, IPhysicalEntity* const _pHitPhysics, const Vec3 _hitDirection, const int _partid, const CArkWeapon* const _pWeapon, const float _impulseScale, const float _minMassScale, const float _maxMassScale)>(0x17A44E0);
};
#endif // !MOONCRASH
