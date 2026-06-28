// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/turret/turretweapon/ArkTurretWeaponMachineGun.h>

class ArkSafeScriptTable;
struct ArkTurretProperties;
class ICrySizer;
struct SEntityUpdateContext;

// ArkTurretWeaponBurstGun
// Header:  Prey/GameDll/ark/turret/turretweapon/ArkTurretWeaponBurstGun.h
class ArkTurretWeaponBurstGun : public ArkTurretWeaponMachineGun
{ // Size=376 (0x178)
public:
	float m_burstCooldownTimer;
	int m_bulletsFired;
	float m_burstCooldown;
	int m_numBulletsPerBurst;

	ArkTurretWeaponBurstGun();
	virtual ~ArkTurretWeaponBurstGun();
	virtual void DoUpdate(SEntityUpdateContext& _ctx);
	virtual void DoFullSerialize(TSerialize _ser);
	virtual void DoLoadProperties(const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties);
	virtual void DoStartFire();
	virtual void DoStopFire();
	virtual void GetMemoryUsage(ICrySizer* const _pSize) const;
	virtual void OnFiredBullet();

	static inline auto FArkTurretWeaponBurstGunOv1 = PreyFunction<void(ArkTurretWeaponBurstGun* const _this)>(0x13D0370);
	static inline auto FBitNotArkTurretWeaponBurstGun = PreyFunction<void(ArkTurretWeaponBurstGun* const _this)>(0x13D03A0);
	static inline auto FDoUpdate = PreyFunction<void(ArkTurretWeaponBurstGun* const _this, SEntityUpdateContext& _ctx)>(0x13D0600);
	static inline auto FDoFullSerialize = PreyFunction<void(ArkTurretWeaponBurstGun* const _this, TSerialize _ser)>(0x13D03F0);
	static inline auto FDoLoadProperties = PreyFunction<void(ArkTurretWeaponBurstGun* const _this, const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties)>(0x13D0480);
	static inline auto FDoStartFire = PreyFunction<void(ArkTurretWeaponBurstGun* const _this)>(0x13D05D0);
	static inline auto FDoStopFire = PreyFunction<void(ArkTurretWeaponBurstGun* const _this)>(0x18C9930);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretWeaponBurstGun* const _this, ICrySizer* const _pSize)>(0x182A3F0);
	static inline auto FOnFiredBullet = PreyFunction<void(ArkTurretWeaponBurstGun* const _this)>(0x13D0640);
};
#endif // MOONCRASH
