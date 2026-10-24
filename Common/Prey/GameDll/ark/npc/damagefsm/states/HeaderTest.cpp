// Header test file for path Prey/GameDll/ark/npc/damagefsm/states/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDamageState.h"
static_assert(sizeof(ArkNpcDamageState) == 1);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDamageState_Damaged.h"
static_assert(sizeof(ArkNpcDamageState_Damaged) == 1);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDamageState_Destroyed.h"
static_assert(sizeof(ArkNpcDamageState_Destroyed) == 32);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDamageState_Disabled.h"
static_assert(sizeof(ArkNpcDamageState_Disabled) == 12);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDamageState_Undamaged.h"
static_assert(sizeof(ArkNpcDamageState_Undamaged) == 1);
#endif
