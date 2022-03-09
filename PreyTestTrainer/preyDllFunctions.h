#pragma once
#include "preyDllObjects.h"
#include <functional>
class preyDllFunctions {
private:
public:
	preyDllFunctions(uintptr_t moduleBase);
	template<typename t> t getFunctionAddr(uintptr_t moduleBase, uintptr_t offset);
	template<typename t> t getFunctionAddr(uintptr_t offset);
	typedef ArkPlayer*(_fastcall* _GetPlayerInstance)();
	_GetPlayerInstance getPlayerInstance;
	typedef float(__thiscall* _GetPlayerHealth)(ArkPlayer*);
	_GetPlayerHealth getPlayerHealth;
	typedef void(__thiscall* _SetPlayerHealth)(ArkPlayer*, float);
	_SetPlayerHealth setPlayerHealth;
	typedef CArkWeapon* (__thiscall* _GetEquippedWeapon)(ArkPlayerWeaponComponent*);
	_GetEquippedWeapon getEquippedWeapon;
	typedef void(__thiscall* _FireWeapon)(CArkWeapon*);
	_FireWeapon fireWeapon;
	typedef void(__thiscall* _SetWeaponAmmoCount)(CArkWeapon*,uint32_t count);
	_SetWeaponAmmoCount setWeaponAmmoCount;
	typedef uint32_t(__thiscall* _GetClipSize)(CArkWeapon*);
	_GetClipSize getClipSize;
	typedef void(__thiscall* _ShowThirdPerson)(ArkPlayer*, bool); //1557e20
	_ShowThirdPerson showThirdPerson;
	typedef CryStringT<char>(__thiscall* _GetEntityClassName)(ArkPlayer*); //1557e20
	_GetEntityClassName getEntityClassName;
};

template <typename t>
t preyDllFunctions::getFunctionAddr(uintptr_t moduleBaseIn, uintptr_t offset) {
	return (t)(moduleBaseIn + offset);
}

