// Header test file for path Prey/GameDll/ark/npc/fsm2/lifecycle/alive/conscious/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcConsciousFsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcConsciousFsm) == 488);
#else
static_assert(sizeof(ArkNpcConsciousFsm) == 496);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcConsciousState_Alert.h"
static_assert(sizeof(ArkNpcConsciousState_Alert) == 1);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcConsciousState_Dormant.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcConsciousState_Dormant) == 480);
#else
static_assert(sizeof(ArkNpcConsciousState_Dormant) == 488);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcConsciousFsmBase.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcConsciousFsmBase_template_<void>) == 488);
#else
static_assert(sizeof(ArkNpcConsciousFsmBase_template_<void>) == 496);
#endif
#endif
