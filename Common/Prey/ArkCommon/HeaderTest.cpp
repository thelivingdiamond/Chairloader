// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/ArkCommon/ArkContiguousMemory.h
#include "ArkContiguousMemory.h"
static_assert(sizeof(ArkContiguousMemory) == 24);

#include "ArkContiguousMemorySizer.h"
static_assert(sizeof(ArkContiguousMemorySizer) == 8);

#include "ArkDelegate.h"
//static_assert(sizeof(ArkFlowNodeObjectiveState) == 64);
//static_assert(sizeof(ArkFlowNodeTaskState) == 64);
//static_assert(sizeof(CArkFlowNodeWorkstationResult) == 64);
//static_assert(sizeof(CArkFlowNodeConfirmDialog) == 64);

#include "ArkRegularOutcome.h"
static_assert(sizeof(ArkRegularOutcome) == 4);

//#include "arkunanimous.h"
//static_assert(sizeof(ArkNpcBodyStateEnterParams_Busy) == 16);
#else // MOONCRASH
// Header test file for path Prey/ArkCommon/
#include "ArkContiguousMemory.h"
static_assert(sizeof(ArkContiguousMemory) == 24);

#include "ArkContiguousMemorySizer.h"
static_assert(sizeof(ArkContiguousMemorySizer) == 8);

#include "ArkInterval.h"
static_assert(sizeof(ArkInterval<float>) == 8);

#include "ArkRegularOutcome.h"
static_assert(sizeof(ArkRegularOutcome) == 4);

#include "ArkUnanimous.h"
static_assert(sizeof(ArkUnanimous) == 16);

#include "arkblackboardautoentry.h"
static_assert(sizeof(ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_Emboldened>) == 24);
static_assert(sizeof(ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_LockedInMimicry>) == 24);
static_assert(sizeof(ArkBlackboardAutoEntry<ArkBlackboard<boost::mpl::vector<ArkNpcBlackboardKey_Emboldened,ArkNpcBlackboardKey_EntityOccluded,ArkNpcBlackboardKey_EntityReachable,ArkNpcBlackboardKey_InCombat,ArkNpcBlackboardKey_LockedInMimicry,ArkNpcBlackboardKey_LostVisibilityTime,ArkNpcBlackboardKey_TargetArmedTime,ArkNpcBlackboardKey_TargetEntity,ArkNpcBlackboardKey_VisibilityTime,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na,boost::mpl::na>,ArkNpcBlackboardEntryKeyHash,ArkNpcBlackboardEntryKeyEqualTo>,ArkNpcBlackboardKey_TargetEntity>) == 32);

#include "arklibrary.h"
static_assert(sizeof(ArkLibrary<unsigned __int64,ArkNpcAbilityContext>) == 64);
static_assert(sizeof(ArkLibrary<unsigned __int64,ArkNpcAbilityContextProfile>) == 64);
static_assert(sizeof(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >) == 64);
static_assert(sizeof(ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >) == 64);

#include "arktimesample.h"
static_assert(sizeof(ArkTimeSample<float,10>) == 48);
static_assert(sizeof(ArkTimeSample<int,10>) == 48);
#endif // !MOONCRASH
