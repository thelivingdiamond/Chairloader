// Header test file for path Prey/GameDll/gamerulesmodules/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameRulesCommonDamageHandling.h"
static_assert(sizeof(CGameRulesCommonDamageHandling) == 32);
static_assert(sizeof(CGameRulesCommonDamageHandling::SCollisionEntityInfo) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameRulesModulesManager.h"
static_assert(sizeof(CGameRulesModulesManager) == 72);
static_assert(sizeof(CGameRulesModulesManager::SGameRulesData) == 184);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameRulesSpawningBase.h"
static_assert(sizeof(CGameRulesSpawningBase) == 120);
static_assert(sizeof(CGameRulesSpawningBase::SSpawnGroup) == 32);
static_assert(sizeof(compare_spawns_name_only) == 1);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameRulesSPDamageHandling.h"
static_assert(sizeof(CMercyTimeFilter) == 64);
static_assert(sizeof(CMercyTimeFilter::ClassFilter) == 4);
static_assert(sizeof(CMercyTimeFilter::CompareClassFilter) == 1);
static_assert(sizeof(CGameRulesSPDamageHandling) == 200);
static_assert(sizeof(CGameRulesSPDamageHandling::SReactionInfoOnHit) == 16);
static_assert(sizeof(CGameRulesSPDamageHandling::EntityCollisionRecord) == 8);
#endif
