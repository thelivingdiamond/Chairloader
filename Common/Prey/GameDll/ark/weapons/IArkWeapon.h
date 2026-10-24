// Header file automatically created from a PDB.

#pragma once

class CCryName;
struct IArkWeaponEventListener;

// Header: Override
// Prey/GameDll/ark/weapons/IArkWeapon.h
struct IArkWeapon // Id=8015F10 Size=8
{
#ifndef MOONCRASH
	virtual ~IArkWeapon() {}
#else
	virtual ~IArkWeapon();
#endif
	virtual void OnEquip() = 0;
#ifndef MOONCRASH
	virtual void OnUnequip(const bool arg0) = 0;
#else
	virtual void OnUnequip(const bool _bUnselect, const bool _bImmediate) = 0;
#endif
	virtual void SetWeaponAmmoCount(const int arg0) = 0;
	virtual int GetWeaponAmmoCount() const = 0;
	virtual int GetInventoryAmmoCount() const = 0;
	virtual int GetClipSize() const = 0;
#ifndef MOONCRASH
	virtual void OnJump() {}
#else
	virtual void OnJump();
#endif
#ifndef MOONCRASH
	virtual void OnSlide() {}
#else
	virtual void OnSlide();
#endif
	virtual bool OnActionAttackUse(unsigned arg0, CCryName const &arg1, int arg2, float arg3) = 0;
	virtual bool OnActionAttackPrimary(unsigned arg0, CCryName const &arg1, int arg2, float arg3) = 0;
	virtual bool OnActionReload(unsigned arg0, CCryName const &arg1, int arg2, float arg3) = 0;
	virtual void RegisterListener(IArkWeaponEventListener *arg0) = 0;
	virtual void UnregisterListener(IArkWeaponEventListener *arg0) = 0;
	virtual string const &GetAmmoArchetypeName() const = 0;
	
#ifndef MOONCRASH
	static inline auto FOnJump = PreyFunction<void(IArkWeapon *const _this)>(0xA13080);
	static inline auto FOnSlide = PreyFunction<void(IArkWeapon *const _this)>(0xA13080);
#else
	static inline auto FOnJump = PreyFunction<void(IArkWeapon* const _this)>(0x1333E90);
	static inline auto FOnSlide = PreyFunction<void(IArkWeapon* const _this)>(0x1333E90);
#endif
};
