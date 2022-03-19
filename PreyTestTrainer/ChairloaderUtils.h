#pragma once
#include "pch.h"

#include "preyDllObjects.h"
#include "preyFunctions.h"
namespace ChairloaderUtils {
	CEntity* CreateEntity(CEntitySystem* system, char* name, Vec3_tpl<float>* pos, Quat_tpl<float>* rot, uint64_t archetypeId, preyFunctions* functions);
	SEntitySpawnParams* CreateEntitySpawnParameters(char* name, Vec3_tpl<float>* pos, Quat_tpl<float>* rot, SEntitySpawnParams* params);
}
