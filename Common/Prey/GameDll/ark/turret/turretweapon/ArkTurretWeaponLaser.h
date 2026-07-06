// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ability/arkoperatorlaserhelper.h>
#include <Prey/GameDll/ark/turret/turretweapon/ArkTurretWeapon.h>

class ArkSafeScriptTable;
struct ArkTurretProperties;
class ICrySizer;
struct SEntityUpdateContext;

// ArkTurretWeaponLaser
// Header:  Prey/GameDll/ark/turret/turretweapon/ArkTurretWeaponLaser.h
class ArkTurretWeaponLaser : public ArkTurretWeapon
{ // Size=920 (0x398)
public:
	ArkLaserHelper m_laserHelper;

	ArkTurretWeaponLaser();
	virtual ~ArkTurretWeaponLaser();
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
	void ActivateLaser() { FActivateLaser(this); }

#if 0
	void DeactivateLaser();
#endif

	static inline auto FArkTurretWeaponLaserOv1 = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x13D0C30);
	static inline auto FDoPostInit = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x13D0D80);
	static inline auto FDoRelease = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x13D0E20);
	static inline auto FDoUpdate = PreyFunction<void(ArkTurretWeaponLaser* const _this, SEntityUpdateContext& _ctx)>(0x13D0F00);
	static inline auto FDoFullSerialize = PreyFunction<void(ArkTurretWeaponLaser* const _this, TSerialize _ser)>(0x13D0CB0);
	static inline auto FDoPostSerialize = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x13D0D90);
	static inline auto FDoStartFire = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x13D0E30);
	static inline auto FDoStopFire = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x13D0E90);
	static inline auto FDoLoadProperties = PreyFunction<void(ArkTurretWeaponLaser* const _this, const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties)>(0x13D0D40);
	static inline auto FDoOnTurretModelChanged = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x1333E90);
	static inline auto FDoOnCreatedModel = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x1333E90);
	static inline auto FDoOnDestroyedModel = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretWeaponLaser* const _this, ICrySizer* const _pSize)>(0x13D1000);
	static inline auto FActivateLaser = PreyFunction<void(ArkTurretWeaponLaser* const _this)>(0x13D0E30);
};
#endif // MOONCRASH
