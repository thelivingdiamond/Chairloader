// Header test file for path Prey/GameDll/ark/npc/fsm2/lifecycle/alive/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcAliveFsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcAliveFsm) == 696);
#else
static_assert(sizeof(ArkNpcAliveFsm) == 704);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcAliveState_Broken.h"
static_assert(sizeof(ArkNpcAliveState_Broken) == 184);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcAliveState_Conscious.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcAliveState_Conscious) == 488);
#else
static_assert(sizeof(ArkNpcAliveState_Conscious) == 496);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcAliveState_Unconscious.h"
static_assert(sizeof(ArkNpcAliveState_Unconscious) == 1);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcAliveFsmBase.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcAliveFsmBase_template_<void>) == 688);
#else
static_assert(sizeof(ArkNpcAliveFsmBase_template_<void>) == 696);
#endif
#endif
