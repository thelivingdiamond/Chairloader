// Header test file for path Prey/GameDll/ark/npc/arkaliengiblet.h
#include "ArkNpcSpawnedState.h"
static_assert(sizeof(ArkNpcSpawnedState_Alive) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Alert) == 1);
static_assert(sizeof(ArkNpcSpawnedState_Broken) == 16);
static_assert(sizeof(ArkNpcSpawnedState_Dormant) == 32);
static_assert(sizeof(ArkNpcSpawnedState_Dead) == 1);

#include "ArkNpcSpawnManager.h"
static_assert(sizeof(ArkNpcSpawnManager) == 24);
static_assert(sizeof(ArkNpcSpawnManager::SpawnRequest) == 32);
