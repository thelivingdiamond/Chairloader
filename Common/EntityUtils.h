#pragma once
#include <Prey/ArkEntityArchetypeLibrary.h>
#include <Prey/ArkEntityClassLibrary.h>
#include <Prey/ArkAbilityLibrary.h>

class ArkPlayer;
class CGameObject;
class ArkNpc;

// spawn non-npc entities through IEntitySystem.spawnNpcfromArchetype()
   //- create spawn parameters from Vec3 pos, Rot, name, archetype ID or class ID
// spawn npc entities
   //- create/manage a chairloader ArkNpcSpawner 
   //- set the archetype of the spawner
   //- spawn the npcs by requesting a spawn
   //- 

class EntityUtils {
public:
	EntityUtils() = delete;

	static void DumpEntity(IEntity* entity, bool dumpProxies);
	static void DumpGameObject(CGameObject* obj);

	static IEntity* SpawnNpc(const char* name, Vec3& pos, Quat& rot, uint64 archetypeId, unsigned int spawnCount = 1, uint64_t faction = 0);
	static IEntity* SpawnEntity(const char* name, Vec3 pos, Quat rot, uint64 archetypeId, unsigned int spawnCount = 1);

	static ArkNpc* GetArkNpc(IEntity* entity);
};
