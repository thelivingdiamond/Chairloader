// Header test file for path Prey/GameDll/ark/npc/fsm2/lifecycle/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcLifecycleFsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcLifecycleFsm) == 712);
#else
static_assert(sizeof(ArkNpcLifecycleFsm) == 720);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcLifecycleState_Alive.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcLifecycleState_Alive) == 696);
#else
static_assert(sizeof(ArkNpcLifecycleState_Alive) == 704);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcLifecycleState_Dead.h"
static_assert(sizeof(ArkNpcLifecycleState_Dead) == 1);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcLifecycleFsmBase.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcLifecycleFsmBase_template_<void>) == 712);
#else
static_assert(sizeof(ArkNpcLifecycleFsmBase_template_<void>) == 720);
#endif
#endif
