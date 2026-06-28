// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/npc/ArkNpcConeDamageDealer.h>
#include <Prey/GameDll/ark/turret/turretweapon/ArkTurretWeapon.h>

class ArkSafeScriptTable;
struct ArkTurretProperties;
class ICrySizer;
struct SEntityUpdateContext;

// ArkTurretWeaponFlameThrower
// Header:  Prey/GameDll/ark/turret/turretweapon/ArkTurretWeaponFlameThrower.h
class ArkTurretWeaponFlameThrower : public ArkTurretWeapon
{ // Size=520 (0x208)
public:
	ArkNpcConeDamageDealer m_damageDealer;
	ArkLooseEffect m_flameEffect;

	ArkTurretWeaponFlameThrower();
	virtual ~ArkTurretWeaponFlameThrower();
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

	static inline auto FArkTurretWeaponFlameThrowerOv1 = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x13D0680);
	static inline auto FDoPostInit = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x1333E90);
	static inline auto FDoRelease = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x13D09B0);
	static inline auto FDoUpdate = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this, SEntityUpdateContext& _ctx)>(0x13D0A90);
	static inline auto FDoFullSerialize = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FDoPostSerialize = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x1333E90);
	static inline auto FDoStartFire = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x13D09C0);
	static inline auto FDoStopFire = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x13D0A80);
	static inline auto FDoLoadProperties = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this, const ArkSafeScriptTable& _weaponTable, ArkTurretProperties& _properties)>(0x13D0720);
	static inline auto FDoOnTurretModelChanged = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x1333E90);
	static inline auto FDoOnCreatedModel = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x1333E90);
	static inline auto FDoOnDestroyedModel = PreyFunction<void(ArkTurretWeaponFlameThrower* const _this)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretWeaponFlameThrower* const _this, ICrySizer* const _pSize)>(0x13D0B70);
};
#endif // MOONCRASH
