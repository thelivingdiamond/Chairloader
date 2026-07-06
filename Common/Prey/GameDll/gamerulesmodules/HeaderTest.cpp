// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/gamerulesmodules/
#include "GameRulesCommonDamageHandling.h"
static_assert(sizeof(CGameRulesCommonDamageHandling) == 32);
static_assert(sizeof(CGameRulesCommonDamageHandling::SCollisionEntityInfo) == 24);

#include "GameRulesModulesManager.h"
static_assert(sizeof(CGameRulesModulesManager) == 72);
static_assert(sizeof(CGameRulesModulesManager::SGameRulesData) == 184);

#include "GameRulesSPDamageHandling.h"
static_assert(sizeof(CGameRulesSPDamageHandling) == 200);
static_assert(sizeof(CGameRulesSPDamageHandling::EntityCollisionRecord) == 8);
static_assert(sizeof(CGameRulesSPDamageHandling::SReactionInfoOnHit) == 16);
static_assert(sizeof(CMercyTimeFilter) == 64);
static_assert(sizeof(CMercyTimeFilter::ClassFilter) == 4);
static_assert(sizeof(CMercyTimeFilter::CompareClassFilter) == 1);

#include "GameRulesSpawningBase.h"
static_assert(sizeof(CGameRulesSpawningBase) == 120);
static_assert(sizeof(CGameRulesSpawningBase::SSpawnGroup) == 32);
static_assert(sizeof(compare_spawns_name_only) == 1);
#endif // MOONCRASH
