// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/turret/turretweapon/ArkTurretWeaponBurstGun.h>

class ICrySizer;

// ArkTurretWeaponGlooGun
// Header:  Prey/GameDll/ark/turret/turretweapon/ArkTurretWeaponGlooGun.h
class ArkTurretWeaponGlooGun : public ArkTurretWeaponBurstGun
{ // Size=376 (0x178)
public:
	ArkTurretWeaponGlooGun();
	virtual ~ArkTurretWeaponGlooGun();
	virtual void GetMemoryUsage(ICrySizer* const _pSize) const;
	virtual void DoPostInit();

	static inline auto FArkTurretWeaponGlooGunOv1 = PreyFunction<void(ArkTurretWeaponGlooGun* const _this)>(0x13D0B90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretWeaponGlooGun* const _this, ICrySizer* const _pSize)>(0x182A3F0);
	static inline auto FDoPostInit = PreyFunction<void(ArkTurretWeaponGlooGun* const _this)>(0x13D0C00);
};
#endif // MOONCRASH
