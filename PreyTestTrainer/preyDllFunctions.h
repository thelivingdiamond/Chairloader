#pragma once
#include "preyDllObjects.h"
class preyDllFunctions {
private:
public:
	preyDllFunctions(uintptr_t moduleBase);
	template<typename t> t getFunctionAddr(uintptr_t moduleBase, uintptr_t offset);
	template<typename t> t getFunctionAddr(uintptr_t offset);
	typedef ArkPlayer* (_fastcall* _GetPlayerInstance)(); _GetPlayerInstance getPlayerInstance;
	typedef float(__thiscall* _GetPlayerHealth)(ArkPlayer*); _GetPlayerHealth getPlayerHealth;
	typedef void(__thiscall* _SetPlayerHealth)(ArkPlayer*, float); _SetPlayerHealth setPlayerHealth;
	typedef CArkWeapon* (__thiscall* _GetEquippedWeapon)(ArkPlayerWeaponComponent*); _GetEquippedWeapon getEquippedWeapon;
	typedef void(__thiscall* _FireWeapon)(CArkWeapon*); _FireWeapon fireWeapon;
	typedef void(__thiscall* _SetWeaponAmmoCount)(CArkWeapon*, uint32_t count); _SetWeaponAmmoCount setWeaponAmmoCount;
	typedef uint32_t(__thiscall* _GetClipSize)(CArkWeapon*); _GetClipSize getClipSize;
	typedef void(__thiscall* _ShowThirdPerson)(ArkPlayer*, bool); _ShowThirdPerson showThirdPerson; //1557e20
	typedef CryStringT<char>(__thiscall* _GetEntityClassName)(ArkPlayer*);  _GetEntityClassName getEntityClassName;//1557e20
	typedef std::vector<CryStringT<char>>(__thiscall* _GetArchetypeNames)(CEntitySystem*, CryStringT<char>); _GetArchetypeNames getArchetypeNames;
	typedef CEntityArchetype* (__thiscall* _FindEntityArchetype)(CEntitySystem*, char*); _FindEntityArchetype findEntityArchetype;
	//typedef IEntity* (_cdecl* CreateNpc)(IEntityArchetype*, Vec3_tpl<float>, Quat_tpl<float>, uint32_t,ArkNpc::variant<ArkNpc::ArkNpcSpawnedState_Alert, ArkNpc::ArkNpcSpawnedState_Broken, ArkNpc::ArkNpcSpawnedState_Dead, ArkNpc::ArkNpcSpawnedState_Dormant>);
	typedef IEntity* (__fastcall *_CreateNpc)(CEntityArchetype*, Vec3_tpl<float>, Quat_tpl<float>, uint64_t, uint32_t*); _CreateNpc createNpc;
	typedef CEntityArchetype* (__thiscall* _GetArchetype)(CEntitySystem*, uint64_t); _GetArchetype getArchetype;// 0922de0
	typedef Vec3_tpl<float>* (__thiscall* _GetPlayerWorldEyePos)(ArkPlayer*, Vec3_tpl<float>*); _GetPlayerWorldEyePos getPlayerWorldEyePos;
	typedef Quat_tpl<float>* (__thiscall* _GetViewRotation)(ArkPlayer*, Quat_tpl<float>*); _GetViewRotation getViewRotation;
	typedef void(__thiscall* _Update)(CEntitySystem*); _Update update;//0927920
	typedef uint32_t (__thiscall * _GenerateEntityId)(CEntitySystem*, bool); _GenerateEntityId generateEntityId;
	typedef unsigned long(__cdecl *_CryGetCurrentThreadID)(); _CryGetCurrentThreadID CryGretCurrentThreadId;//0099910
};


template <typename t>
t preyDllFunctions::getFunctionAddr(uintptr_t moduleBaseIn, uintptr_t offset) {
	return (t)(moduleBaseIn + offset);
}

