// Header test file for path Prey/GameDll/ark/npc/fsm2/body/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyFsm.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyFsmBase_template_<void>) == 6072);
static_assert(sizeof(ArkNpcBodyFsm) == 6072);
#else
static_assert(sizeof(ArkNpcBodyFsmBase_template_<void>) == 6288);
static_assert(sizeof(ArkNpcBodyFsm) == 6288);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Animated.h"
static_assert(sizeof(ArkNpcBodyState_Animated) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_AnimatedBase.h"
static_assert(sizeof(ArkNpcBodyState_AnimatedBase) == 56);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_AnimatedFall.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_AnimatedFall) == 40);
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_AnimatedFall) == 328);
#else
static_assert(sizeof(ArkNpcBodyState_AnimatedFall) == 336);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Burrowing.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Burrowing) == 64);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Busy.h"
static_assert(sizeof(ArkNpcBodyState_Busy) == 8);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Dissipate.h"
static_assert(sizeof(ArkNpcBodyState_Dissipate) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Fatality.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Fatality) == 296);
#else
static_assert(sizeof(ArkNpcBodyState_Fatality) == 304);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_GravShaft.h"
static_assert(sizeof(ArkNpcBodyState_GravShaft) == 56);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_HitReact.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_HitReact) == 32);
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_HitReact) == 304);
#else
static_assert(sizeof(ArkNpcBodyState_HitReact) == 312);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Landing.h"
static_assert(sizeof(ArkNpcBodyState_Landing) == 56);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Lifted.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Lifted) == 344);
#else
static_assert(sizeof(ArkNpcBodyState_Lifted) == 352);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Mimicking.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_Mimicking) == 32);
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Mimicking) == 288);
#else
static_assert(sizeof(ArkNpcBodyState_Mimicking) == 296);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_MultiStageAnimated.h"
static_assert(sizeof(ArkNpcBodyState_MultiStageAnimated) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Ragdoll.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_Ragdoll) == 40);
static_assert(sizeof(ArkNpcBodyStateSerializeParams_Ragdoll) == 48);
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Ragdoll) == 776);
#else
static_assert(sizeof(ArkNpcBodyState_Ragdoll) == 784);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Rebound.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Rebound) == 336);
#else
static_assert(sizeof(ArkNpcBodyState_Rebound) == 344);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Resist.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Resist) == 464);
#else
static_assert(sizeof(ArkNpcBodyState_Resist) == 472);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_ResistScrunch.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_ResistScrunch) == 464);
#else
static_assert(sizeof(ArkNpcBodyState_ResistScrunch) == 472);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_SearchExamine.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_SearchExamine) == 64);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Surprised.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Surprised) == 688);
#else
static_assert(sizeof(ArkNpcBodyState_Surprised) == 696);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcBodyState_Trackview.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_Trackview) == 24);
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcBodyState_Trackview) == 648);
#else
static_assert(sizeof(ArkNpcBodyState_Trackview) == 656);
#endif
#endif
