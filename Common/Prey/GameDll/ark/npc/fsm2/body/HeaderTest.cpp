// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/fsm2/body/
#include "ArkNpcBodyFsm.h"
static_assert(sizeof(ArkNpcBodyFsm) == 6288);
static_assert(sizeof(ArkNpcBodyFsmBase_template_<void>) == 6288);
static_assert(sizeof(ArkNpcBodyFsmBase_template_<void>::StateSelector<1>) == 1);

#include "ArkNpcBodyState_Animated.h"
static_assert(sizeof(ArkNpcBodyState_Animated) == 64);

#include "ArkNpcBodyState_AnimatedBase.h"
static_assert(sizeof(ArkNpcBodyState_AnimatedBase) == 56);

#include "ArkNpcBodyState_AnimatedFall.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_AnimatedFall) == 40);
static_assert(sizeof(ArkNpcBodyState_AnimatedFall) == 336);

#include "ArkNpcBodyState_Burrowing.h"
static_assert(sizeof(ArkNpcBodyState_Burrowing) == 64);

#include "ArkNpcBodyState_Busy.h"
static_assert(sizeof(ArkNpcBodyState_Busy) == 8);

#include "ArkNpcBodyState_Dissipate.h"
static_assert(sizeof(ArkNpcBodyState_Dissipate) == 64);

#include "ArkNpcBodyState_Fatality.h"
static_assert(sizeof(ArkNpcBodyState_Fatality) == 304);

#include "ArkNpcBodyState_GravShaft.h"
static_assert(sizeof(ArkNpcBodyState_GravShaft) == 56);

#include "ArkNpcBodyState_HitReact.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_HitReact) == 32);
static_assert(sizeof(ArkNpcBodyState_HitReact) == 312);

#include "ArkNpcBodyState_Landing.h"
static_assert(sizeof(ArkNpcBodyState_Landing) == 56);

#include "ArkNpcBodyState_Lifted.h"
static_assert(sizeof(ArkNpcBodyState_Lifted) == 352);

#include "ArkNpcBodyState_Mimicking.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_Mimicking) == 32);
static_assert(sizeof(ArkNpcBodyState_Mimicking) == 296);

#include "ArkNpcBodyState_MultiStageAnimated.h"
static_assert(sizeof(ArkNpcBodyState_MultiStageAnimated) == 64);

#include "ArkNpcBodyState_Ragdoll.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_Ragdoll) == 40);
static_assert(sizeof(ArkNpcBodyStateSerializeParams_Ragdoll) == 48);
static_assert(sizeof(ArkNpcBodyState_Ragdoll) == 784);

#include "ArkNpcBodyState_Rebound.h"
static_assert(sizeof(ArkNpcBodyState_Rebound) == 344);

#include "ArkNpcBodyState_Resist.h"
static_assert(sizeof(ArkNpcBodyState_Resist) == 472);

#include "ArkNpcBodyState_ResistScrunch.h"
static_assert(sizeof(ArkNpcBodyState_ResistScrunch) == 472);

#include "ArkNpcBodyState_SearchExamine.h"
static_assert(sizeof(ArkNpcBodyState_SearchExamine) == 64);

#include "ArkNpcBodyState_Surprised.h"
static_assert(sizeof(ArkNpcBodyState_Surprised) == 696);

#include "ArkNpcBodyState_Trackview.h"
static_assert(sizeof(ArkNpcBodyStateEnterParams_Trackview) == 24);
static_assert(sizeof(ArkNpcBodyState_Trackview) == 656);
#endif // MOONCRASH
