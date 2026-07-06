// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/turret/turretweapon/ArkTurretWeapon.h>

class ArkSafeScriptTable;
struct ArkTurretProperties;
class ICrySizer;
struct IEntityArchetype;
struct SEntityUpdateContext;

// ArkTurretWeaponMachineGun
// Header:  Prey/GameDll/ark/turret/turretweapon/ArkTurretWeaponMachineGun.h
class ArkTurretWeaponMachineGun : public ArkTurretWeapon
{ // Size=360 (0x168)
public:
	ArkSimpleTimer m_shootTimer;
	float m_currentHitChance;
	IEntityArchetype* m_pAmmoArchetype;
	ArkInterval<float> m_distForHitChanceRange;
	ArkInterval<float> m_bulletHitChanceRange;
	ArkInterval<float> m_missSpreadRange;
	ArkInterval<float> m_delayPerShotRange;
	float m_shootTimeUntilMaxFiringSpeed;
	float m_bulletSpeed;

	ArkTurretWeaponMachineGun();
	virtual ~ArkTurretWeaponMachineGun();
	virtual void DoPostInit();
	virtual void DoRelease();
	virtual void DoUpdate(SEntityUpdateContext& _ctx);
	virtual void DoFullSerialize(TSerialize _ser);
	virtual void DoPostSerialize();
	virtual void DoStartFire();
	virtual void DoStopFire();
	virtual void DoLoadProperties(const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties);
	virtual void DoOnTurretModelChanged();
	virtual void DoOnCreatedModel();
	virtual void DoOnDestroyedModel();
	virtual void GetMemoryUsage(ICrySizer* const _pSize) const;
	virtual Vec3 GetAttackTargetPositionToLeadTarget(unsigned _targetEntityId, float _hitPercentage) const;
	virtual void OnFiredBullet();

#if 0
	void FireBullet();
#endif

	static inline auto FArkTurretWeaponMachineGunOv1 = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x13D1020);
	static inline auto FBitNotArkTurretWeaponMachineGun = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x13D1080);
	static inline auto FDoPostInit = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FDoRelease = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FDoUpdate = PreyFunction<void(ArkTurretWeaponMachineGun* const _this, SEntityUpdateContext& _ctx)>(0x13D14E0);
	static inline auto FDoFullSerialize = PreyFunction<void(ArkTurretWeaponMachineGun* const _this, TSerialize _ser)>(0x13D10D0);
	static inline auto FDoPostSerialize = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FDoStartFire = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FDoStopFire = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FDoLoadProperties = PreyFunction<void(ArkTurretWeaponMachineGun* const _this, const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties)>(0x13D1160);
	static inline auto FDoOnTurretModelChanged = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FDoOnCreatedModel = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FDoOnDestroyedModel = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretWeaponMachineGun* const _this, ICrySizer* const _pSize)>(0x13D1930);
	static inline auto FGetAttackTargetPositionToLeadTarget = PreyFunction<Vec3*(const ArkTurretWeaponMachineGun* const _this, Vec3* _return_value_, unsigned _targetEntityId, float _hitPercentage)>(0x13D1730);
	static inline auto FOnFiredBullet = PreyFunction<void(ArkTurretWeaponMachineGun* const _this)>(0x13D1950);
};
#endif // MOONCRASH
