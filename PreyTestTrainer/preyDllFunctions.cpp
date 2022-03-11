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
	findEntityArchetype = getFunctionAddr<_FindEntityArchetype>(moduleBase, 0x0922910);//090fb70
	getArchetype = getFunctionAddr<_GetArchetype>(moduleBase, 0x0922de0);
	getArchetypeNames = getFunctionAddr<_GetArchetypeNames>(moduleBase, 0x0922d00);
	update = getFunctionAddr<_Update>(moduleBase, 0x0927920);
	createNpc = getFunctionAddr<_CreateNpc>(moduleBase, 0x151d6d0);
	getPlayerWorldEyePos = getFunctionAddr<_GetPlayerWorldEyePos>(moduleBase, 0x131f920);
	getViewRotation = getFunctionAddr<_GetViewRotation>(moduleBase, 0x154ff50);
	generateEntityId = getFunctionAddr<_GenerateEntityId>(moduleBase, 0x0922bb0);//0922bb0
	CryGretCurrentThreadId = getFunctionAddr<_CryGetCurrentThreadID>(moduleBase, 0x0099910);
}
