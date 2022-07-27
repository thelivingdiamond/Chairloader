// Header test file for path Prey/ArkCommon/ArkContiguousMemory.h
#include "ArkContiguousMemory.h"
static_assert(sizeof(ArkContiguousMemory) == 24);

#include "ArkContiguousMemorySizer.h"
static_assert(sizeof(ArkContiguousMemorySizer) == 8);

#include "arkdelegate.h"
//static_assert(sizeof(ArkFlowNodeObjectiveState) == 64);
//static_assert(sizeof(ArkFlowNodeTaskState) == 64);
//static_assert(sizeof(CArkFlowNodeWorkstationResult) == 64);
//static_assert(sizeof(CArkFlowNodeConfirmDialog) == 64);

#include "ArkRegularOutcome.h"
static_assert(sizeof(ArkRegularOutcome) == 4);

//#include "arkunanimous.h"
//static_assert(sizeof(ArkNpcBodyStateEnterParams_Busy) == 16);
