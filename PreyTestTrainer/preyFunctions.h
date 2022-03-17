#pragma once
#include "preyDllObjects.h"
class preyFunctionBase {
public:
	template<typename t> t getFunctionAddr(uintptr_t moduleBase, uint64_t offset);
};
class preyFunctions : preyFunctionBase{
public:
	preyFunctions(uintptr_t moduleBase);

	class ArkPlayerPrivate : preyFunctionBase {
	public:
		ArkPlayerPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _ShowThirdPerson)(ArkPlayer*, bool); _ShowThirdPerson showThirdPerson; //1557e20
		typedef Vec3_tpl<float>* (__thiscall* _GetPlayerWorldEyePos)(ArkPlayer*, Vec3_tpl<float>*); _GetPlayerWorldEyePos getPlayerWorldEyePos;
		typedef void(__thiscall* _Ragdollize)(ArkPlayer*, float); _Ragdollize ragdollize;//
		typedef void(__thiscall* _onFlyModePressed)(ArkPlayer*); _onFlyModePressed onFlyModePressed;//15710e0
		typedef ArkPlayer* (_fastcall* _GetPlayerInstance)(); _GetPlayerInstance getInstance;
		typedef CGodMode* (_fastcall* _GetGodModeInstance)(); _GetGodModeInstance getGodModeInstance;

	};

	class CArkWeaponPrivate :preyFunctionBase {
	public:
		CArkWeaponPrivate(uintptr_t moduleBase);
		typedef CArkWeapon* (__thiscall* _GetEquippedWeapon)(ArkPlayerWeaponComponent*); _GetEquippedWeapon getEquippedWeapon;
		typedef void(__thiscall* _FireWeapon)(CArkWeapon*); _FireWeapon fireWeapon;
		typedef void(__thiscall* _SetWeaponAmmoCount)(CArkWeapon*, uint32_t count); _SetWeaponAmmoCount setWeaponAmmoCount;
		typedef uint32_t(__thiscall* _GetClipSize)(CArkWeapon*); _GetClipSize getClipSize;
	};

	class CEntitySystemPrivate :preyFunctionBase {
	public:
		CEntitySystemPrivate(uintptr_t moduleBase);
		typedef std::vector<CryStringT<char>>(__thiscall* _GetArchetypeNames)(CEntitySystem*, CryStringT<char>); _GetArchetypeNames getArchetypeNames;
		typedef CEntityArchetype* (__thiscall* _FindEntityArchetype)(CEntitySystem*, char*); _FindEntityArchetype findEntityArchetype;
		typedef CEntity* (__cdecl* _CreateNpc)(CEntityArchetype*, Vec3_tpl<float>, Quat_tpl<float>, uint32_t, boost::variant<ArkNpc::ArkNpcSpawnedState_Alert, ArkNpc::ArkNpcSpawnedState_Broken, ArkNpc::ArkNpcSpawnedState_Dead, ArkNpc::ArkNpcSpawnedState_Dormant>*); _CreateNpc createNpc;
		//typedef CEntity* (__fastcall *_CreateNpc)(CEntityArchetype*, Vec3_tpl<float>, Quat_tpl<float>, uint64_t, uint32_t*); _CreateNpc createNpc;
		typedef CEntityArchetype* (__thiscall* _GetArchetype)(CEntitySystem*, uint64_t); _GetArchetype getArchetype;// 0922de0
		typedef void(__thiscall* _Update)(CEntitySystem*); _Update update;//0927920
		typedef uint32_t(__thiscall* _GenerateEntityId)(CEntitySystem*, bool); _GenerateEntityId generateEntityId;
	};

	class ArkNpcSpawnManagerPrivate : preyFunctionBase {
	public:
		ArkNpcSpawnManagerPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _ArkNpcSpawnManagerUpdate)(ArkNpcSpawnManager*, float); _ArkNpcSpawnManagerUpdate ArkNpcSpawnManagerUpdate;//151db30
		typedef uint64_t(__thiscall* _RequestNpcSpawn)(ArkNpcSpawnManager*, ArkNpcSpawnRequester*, CArkNpcSpawner*); _RequestNpcSpawn requestNpcSpawn; //151dac0
	};
	
	class CEntityPrivate : preyFunctionBase {
	public:
		CEntityPrivate(uintptr_t moduleBase);
		typedef bool(__thiscall* _InitCEntity)(CEntity*, SEntitySpawnParams*);//0905cb0
		typedef bool(__thiscall* _HasAi)(CEntity*); _HasAi hasAi;
		typedef CArkNpcSpawner* (__fastcall* _GetArkNpcSpawner)(CEntity*); _GetArkNpcSpawner getArkNpcSpawner;//151c740

	};

	class ArkNightmareSpawnManagerPrivate : preyFunctionBase {
	public:
		ArkNightmareSpawnManagerPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _SpawnNewNightmare)(ArkNightmareSpawnManager*); _SpawnNewNightmare spawnNewNightmare;//11f58d0
		typedef void(__thiscall* _enableNightmareSpawner)(ArkNightmareSpawnManager*); _enableNightmareSpawner enableNightmareSpawner;
	};

	class CArkNpcSpawnerPrivate : preyFunctionBase{
	public:
		CArkNpcSpawnerPrivate(uintptr_t moduleBase);
		typedef void* (__fastcall* _CreateNpcSpawner)(uint64_t, void*); _CreateNpcSpawner createNpcSpawner;//1703f00
		typedef void* (__thiscall* _CArkNpcSpawner)(CArkNpcSpawner*); _CArkNpcSpawner cArkNpcSpawnerConstructor; //151bed0
		typedef void(__thiscall* _RequestSpawn)(CArkNpcSpawner*); _RequestSpawn requestSpawn;//151cd80
	};
	// typedef CryStringT<char>(__thiscall* _GetEntityClassName)(ArkPlayer*);  _GetEntityClassName getEntityClassName;//1557e20
	// typedef Quat_tpl<float>* (__thiscall* _GetViewRotation)(ArkPlayer*, Quat_tpl<float>*); _GetViewRotation getViewRotation;

	class CXConsolePrivate : preyFunctionBase {
	public:
		CXConsolePrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _ShowConsole)(CXConsole*, bool, int32_t); _ShowConsole showConsole;
		typedef void(__thiscall* _DisplayHelp)(CXConsole*, char*, char*); _DisplayHelp displayHelp;//0df0fa0
		typedef void(__thiscall* _EnableActivationKey)(CXConsole*, bool); _EnableActivationKey enableActivationKey;//0df23b0
		typedef void(__thiscall* _Init)(CXConsole*, CSystem*); _Init initCXConsole;//0df5270
		typedef void(__thiscall* _ExecuteString)(CXConsole*, char* command, bool silentMode, bool bDeferExecution); _ExecuteString executeString; //0df3640
		typedef CVar* (__thiscall* _GetCvar)(CXConsole*, char*); _GetCvar getCvar;
		typedef void(__thiscall* _AddLine)(CXConsole*, char*); _AddLine addLine;//0defa00
	};

	class CSystemPrivate : preyFunctionBase {
	public:
		CSystemPrivate(uintptr_t moduleBase);
		typedef void(__thiscall* _SetDevMode)(CSystem*, bool); _SetDevMode setDevMode;//0dc7720
		typedef CWindowsConsole* (__thiscall* _GetTextModeConsole)(CSystem*); _GetTextModeConsole GetTextModeConsole;//0dc4cb0
	};

	typedef unsigned long(__cdecl *_CryGetCurrentThreadID)(); _CryGetCurrentThreadID CryGretCurrentThreadId;//0099910
	typedef Vec2_tpl<float>(__thiscall* _BeginDraw)(CWindowsConsole*); _BeginDraw beginDraw;//0de9710

	ArkPlayerPrivate *ArkPlayerF;
	CArkWeaponPrivate *CArkWeaponF;
	CEntitySystemPrivate* CEntitySystemF;
	ArkNpcSpawnManagerPrivate* ArkNpcSpawnManagerF;
	CEntityPrivate *CEntity;
	ArkNightmareSpawnManagerPrivate *ArkNightmareSpawnManagerF;
	CArkNpcSpawnerPrivate *CArkNpcSpawnerF;
	CXConsolePrivate *CXConsoleF;
	CSystemPrivate *CSystemF;
};


// class ArkPlayer {
// 	
// };


