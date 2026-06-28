// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/weapons/arklaser.h>

class ArkSafeScriptTable;
struct EventPhysCollision;
struct IEntity;

// ArkLaserHelper
// Header:  Prey/GameDll/ark/npc/ability/arkoperatorlaserhelper.h
class ArkLaserHelper
{ // Size=624 (0x270)
public:
	using BeamEndVfxs = std::array<ArkLooseEffect, 4>;

	unsigned m_instigatorEntityId;
	CArkLaserBeam m_laserBeam;
	CArkLaserBeam::ArkLaserParams m_params;
	ArkSimpleTimer m_materialEffectCooldown;
	string m_laserMatEffectName;
	Vec3 m_position;
	Vec3 m_target;
	Vec3 m_beamCollisionPoint;
	uint64_t m_laserAttackPackageId;
	float m_laserDamagePerSecond;
	float m_laserLength;
	int m_laserHitTypeId;
	int m_laserSurfaceTypeId;
	std::array<ArkLooseEffect, 4> m_beamEndVfx;
	int m_currentBeamEndEffectIndex;
	float m_beamEndJumpDistSq;

	ArkLaserHelper();
	~ArkLaserHelper();
	void Initialize(IEntity& _entity) { FInitialize(this, _entity); }
	void LoadScriptVariables(IEntity& _entity, ArkSafeScriptTable _laserTable) { FLoadScriptVariables(this, _entity, _laserTable); }
	void Activate() { FActivate(this); }
	void Deactivate() { FDeactivate(this); }
	bool IsActive() const { return FIsActive(this); }
	void Update(IEntity& _entity, float _elapsedTime) { FUpdate(this, _entity, _elapsedTime); }
	void SetTargetDirection(const Vec3& _direction) { FSetTargetDirection(this, _direction); }
	const Vec3& GetBeamCollisionPoint() const { return FGetBeamCollisionPoint(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void DoDamage(const IEntity& _owner, unsigned _instigatorId, float _frameTime, const EventPhysCollision& _collision) { FDoDamage(this, _owner, _instigatorId, _frameTime, _collision); }

#if 0
	void SetTarget(const Vec3& _arg0_);
	Vec3 GetPosition() const;
	void SetPosition(Vec3 _arg0_);
	void UpdateBeamEndParticleEffect(bool _arg0_, const Vec3& _arg1_, const Vec3& _arg2_);
	void UpdateBeamEndMaterialEffect(const EventPhysCollision& _arg0_);
#endif

	static inline auto FArkLaserHelperOv1 = PreyFunction<void(ArkLaserHelper* const _this)>(0x1323490);
	static inline auto FBitNotArkLaserHelper = PreyFunction<void(ArkLaserHelper* const _this)>(0x1323700);
	static inline auto FInitialize = PreyFunction<void(ArkLaserHelper* const _this, IEntity& _entity)>(0x1323E90);
	static inline auto FLoadScriptVariables = PreyFunction<void(ArkLaserHelper* const _this, IEntity& _entity, ArkSafeScriptTable _laserTable)>(0x1324010);
	static inline auto FActivate = PreyFunction<void(ArkLaserHelper* const _this)>(0x13238A0);
	static inline auto FDeactivate = PreyFunction<void(ArkLaserHelper* const _this)>(0x13238B0);
	static inline auto FIsActive = PreyFunction<bool(const ArkLaserHelper* const _this)>(0x36F4C0);
	static inline auto FUpdate = PreyFunction<void(ArkLaserHelper* const _this, IEntity& _entity, float _elapsedTime)>(0x13247F0);
	static inline auto FSetTargetDirection = PreyFunction<void(ArkLaserHelper* const _this, const Vec3& _direction)>(0x13246E0);
	static inline auto FGetBeamCollisionPoint = PreyFunction<const Vec3& (const ArkLaserHelper* const _this)>(0x13691E0);
	static inline auto FSerialize = PreyFunction<void(ArkLaserHelper* const _this, TSerialize _ser)>(0x1324580);
	static inline auto FDoDamage = PreyFunction<void(ArkLaserHelper* const _this, const IEntity& _owner, unsigned _instigatorId, float _frameTime, const EventPhysCollision& _collision)>(0x1323900);
};
#endif // MOONCRASH
