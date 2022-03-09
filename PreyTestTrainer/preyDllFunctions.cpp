#include "pch.h"
#include "preyDllFunctions.h"
preyDllFunctions::preyDllFunctions(uintptr_t moduleBase) {
	getPlayerInstance = getFunctionAddr<_GetPlayerInstance>(moduleBase, 0x154fa60);
	getPlayerHealth = getFunctionAddr<_GetPlayerHealth>(moduleBase, 0x154fa40);
	setPlayerHealth = getFunctionAddr<_SetPlayerHealth>(moduleBase, 0x15575c0);
	getEquippedWeapon = getFunctionAddr<_GetEquippedWeapon>(moduleBase, 0x1248500);
	fireWeapon = getFunctionAddr<_FireWeapon>(moduleBase, 0x16659b0);
	setWeaponAmmoCount = getFunctionAddr<_SetWeaponAmmoCount>(moduleBase, 0x166d840);
	getClipSize = getFunctionAddr<_GetClipSize>(moduleBase, 0x161665f50);
	showThirdPerson = getFunctionAddr<_ShowThirdPerson>(moduleBase, 0x1557e20);
	getEntityClassName = getFunctionAddr<_GetEntityClassName>(moduleBase, 0x154f9b0);//154f9b0
}
