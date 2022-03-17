#include "pch.h"
#include "preyFunctions.h"

template <typename t>
t preyFunctionBase::getFunctionAddr(uintptr_t moduleBaseIn, uintptr_t offset) {
	return (t)(moduleBaseIn + offset);
}
preyFunctions::ArkPlayerPrivate::ArkPlayerPrivate(uintptr_t moduleBase) {
	// getEntityClassName = getFunctionAddr<_GetEntityClassName>(moduleBase, 0x154f9b0);//154f9b0
	// getViewRotation = getFunctionAddr<_GetViewRotation>(moduleBase, 0x154ff50);

	showThirdPerson = getFunctionAddr<_ShowThirdPerson>(moduleBase, 0x1557e20);
	getPlayerWorldEyePos = getFunctionAddr<_GetPlayerWorldEyePos>(moduleBase, 0x131f920);
	onFlyModePressed = getFunctionAddr<_onFlyModePressed>(moduleBase, 0x15710e0);
	ragdollize = getFunctionAddr<_Ragdollize>(moduleBase, 0x1555000);
	getInstance = getFunctionAddr<_GetPlayerInstance>(moduleBase, 0x154fa60);
	getGodModeInstance = getFunctionAddr<_GetGodModeInstance>(moduleBase, 0x173c050);
}

preyFunctions::CArkWeaponPrivate::CArkWeaponPrivate(uintptr_t moduleBase) {
	getEquippedWeapon = getFunctionAddr<_GetEquippedWeapon>(moduleBase, 0x1248500);
	fireWeapon = getFunctionAddr<_FireWeapon>(moduleBase, 0x16659b0);
	setWeaponAmmoCount = getFunctionAddr<_SetWeaponAmmoCount>(moduleBase, 0x166d840);
	getClipSize = getFunctionAddr<_GetClipSize>(moduleBase, 0x161665f50);
}
preyFunctions::CEntitySystemPrivate::CEntitySystemPrivate(uintptr_t moduleBase) {
	findEntityArchetype = getFunctionAddr<_FindEntityArchetype>(moduleBase, 0x0922910);//090fb70
	getArchetype = getFunctionAddr<_GetArchetype>(moduleBase, 0x0922de0);
	getArchetypeNames = getFunctionAddr<_GetArchetypeNames>(moduleBase, 0x0922d00);
	update = getFunctionAddr<_Update>(moduleBase, 0x0927920);
	createNpc = getFunctionAddr<_CreateNpc>(moduleBase, 0x151d6d0);

	generateEntityId = getFunctionAddr<_GenerateEntityId>(moduleBase, 0x0922bb0);//0922bb0
	
}

preyFunctions::ArkNpcSpawnManagerPrivate::ArkNpcSpawnManagerPrivate(uintptr_t moduleBase) {
	ArkNpcSpawnManagerUpdate = getFunctionAddr<_ArkNpcSpawnManagerUpdate>(moduleBase, 0x151db30);
	requestNpcSpawn = getFunctionAddr<_RequestNpcSpawn>(moduleBase, 0x151dac0);
	
}
preyFunctions::CEntityPrivate::CEntityPrivate(uintptr_t moduleBase) {
	hasAi = getFunctionAddr<_HasAi>(moduleBase, 0x0905b70);//0905b70
	getArkNpcSpawner = getFunctionAddr<_GetArkNpcSpawner>(moduleBase, 0x151c740);
}
preyFunctions::ArkNightmareSpawnManagerPrivate::ArkNightmareSpawnManagerPrivate(uintptr_t moduleBase) {
	spawnNewNightmare = getFunctionAddr<_SpawnNewNightmare>(moduleBase, 0x11f58d0);
	enableNightmareSpawner = getFunctionAddr <_enableNightmareSpawner >(moduleBase, 0x11f47a0);
}

preyFunctions::CArkNpcSpawnerPrivate::CArkNpcSpawnerPrivate(uintptr_t moduleBase) {
	cArkNpcSpawnerConstructor = getFunctionAddr<_CArkNpcSpawner>(moduleBase, 0x151bed0);
	createNpcSpawner = getFunctionAddr<_CreateNpcSpawner>(moduleBase, 0x1703f00);//1703f00
	requestSpawn = getFunctionAddr<_RequestSpawn>(moduleBase, 0x151cd80);
}

preyFunctions::CXConsolePrivate::CXConsolePrivate(uintptr_t moduleBase) {
	showConsole = getFunctionAddr<_ShowConsole>(moduleBase, 0x0df85f0);
	displayHelp = getFunctionAddr<_DisplayHelp>(moduleBase, 0x0df0fa0);
	enableActivationKey = getFunctionAddr<_EnableActivationKey>(moduleBase, 0x0df23b0);
	initCXConsole = getFunctionAddr<_Init>(moduleBase, 0x0df5270);
	executeString = getFunctionAddr<_ExecuteString>(moduleBase, 0x0df3640);
	getCvar = getFunctionAddr<_GetCvar>(moduleBase, 0x0df48e0);
	addLine = getFunctionAddr<_AddLine>(moduleBase, 0x0defa00);
}

preyFunctions::CSystemPrivate::CSystemPrivate(uintptr_t moduleBase) {
	setDevMode = getFunctionAddr<_SetDevMode>(moduleBase, 0x0dc7720);
	GetTextModeConsole = getFunctionAddr<_GetTextModeConsole>(moduleBase, 0x0dc4cb0);
}

preyFunctions::preyFunctions(uintptr_t moduleBase) {
	ArkPlayerF = new  ArkPlayerPrivate(moduleBase);
	CArkWeaponF = new CArkWeaponPrivate(moduleBase);
	CEntitySystemF = new CEntitySystemPrivate(moduleBase);
	ArkNpcSpawnManagerF = new ArkNpcSpawnManagerPrivate(moduleBase);
	CEntity = new CEntityPrivate(moduleBase);
	ArkNightmareSpawnManagerF = new ArkNightmareSpawnManagerPrivate(moduleBase);
	CArkNpcSpawnerF = new CArkNpcSpawnerPrivate(moduleBase);
	CXConsoleF = new CXConsolePrivate(moduleBase);
	CSystemF = new CSystemPrivate(moduleBase);

	CryGretCurrentThreadId = getFunctionAddr<_CryGetCurrentThreadID>(moduleBase, 0x0099910);


	

	beginDraw = getFunctionAddr<_BeginDraw>(moduleBase, 0x0de9710);
	

	
}


