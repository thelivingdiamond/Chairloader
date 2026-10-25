// Header test file for path Prey/GameDll/ark/npc/blackboard/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBlackboardManager.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBlackboardManager) == 576);
#else
static_assert(sizeof(ArkNpcBlackboardManager) == 648);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBlackboardEntryTemplates.h"
class ArkNpcBlackboardKey_EntityOccluded;
class ArkNpcBlackboardEntryKey_EntityOccluded;
class ArkNpcBlackboardEntry_EntityOccluded;
class ArkNpcBlackboardKey_VisibilityTime;
class ArkNpcBlackboardEntryKey_VisibilityTime;
class ArkNpcBlackboardEntry_VisibilityTime;
static_assert(sizeof(ArkNpcBlackboardEntryTemplate_LazyGet<ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardEntryKey_EntityOccluded,ArkNpcBlackboardEntry_EntityOccluded,bool,bool>) == 1);
static_assert(sizeof(ArkNpcBlackboardEntryTemplate_GetUpdate<ArkNpcBlackboardKey_VisibilityTime,ArkNpcBlackboardEntryKey_VisibilityTime,ArkNpcBlackboardEntry_VisibilityTime,float,float>) == 1);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBlackboardKeys.h"
#include "ArkBlackboard.h"
static_assert(sizeof(ArkNpcBlackboardKey_Emboldened) == 8);
static_assert(sizeof(ArkNpcBlackboardEntryKey_Emboldened) == 8);
static_assert(sizeof(ArkNpcBlackboardKey_EntityOccluded) == 16);
static_assert(sizeof(ArkNpcBlackboardEntryKey_EntityOccluded) == 16);
static_assert(sizeof(ArkNpcBlackboardKey_InCombat) == 8);
static_assert(sizeof(ArkNpcBlackboardKey_TargetEntity) == 16);
static_assert(sizeof(ArkNpcBlackboardEntryKey_TargetEntity) == 16);
static_assert(sizeof(ArkNpcBlackboardKey_VisibilityTime) == 16);
static_assert(sizeof(ArkNpcBlackboardEntry_InCombat) == 1);
static_assert(sizeof(ArkNpcBlackboardEntry_LockedInMimicry) == 1);
static_assert(sizeof(ArkNpcBlackboardEntry_TargetEntity) == 4);
static_assert(sizeof(decltype(ArkNpcBlackboardManager::m_blackboard)::RefCountedEntry<ArkNpcBlackboardEntry_Emboldened>) == 40);
static_assert(sizeof(decltype(ArkNpcBlackboardManager::m_blackboard)::RefCountedEntry<ArkNpcBlackboardEntry_EntityOccluded>) == 16);
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBlackboardManager::m_blackboard) == 576);
#else
static_assert(sizeof(ArkNpcBlackboardManager::m_blackboard) == 648);
#endif
#endif
