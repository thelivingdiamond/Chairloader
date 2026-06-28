// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/flowgraph/arkfaction/
#include "ArkFlowNodeDispositionSwitch.h"
static_assert(sizeof(ArkFlowNodeDispositionSwitch) == 16);

#include "ArkFlowNodeEffectiveDisposition_EntityToEntity.h"
static_assert(sizeof(ArkFlowNodeEffectiveDisposition_EntityToEntity) == 16);

#include "ArkFlowNodeEffectiveDisposition_EntityToFaction.h"
static_assert(sizeof(ArkFlowNodeEffectiveDisposition_EntityToFaction) == 16);

#include "ArkFlowNodeEffectiveDisposition_FactionToEntity.h"
static_assert(sizeof(ArkFlowNodeEffectiveDisposition_FactionToEntity) == 16);

#include "arkfactionflowgraphcommon.h"
static_assert(sizeof(ArkFactionFlow::ArkFlowNodeFactionBase) == 16);

#include "arkflownodedispositionbase.h"
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityEntity>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityFaction>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityToFactionEntities>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionFaction>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionToFactionEntities>) == 16);
static_assert(sizeof(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearRelationshipFactionEntity>) == 16);
static_assert(sizeof(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityEntity>) == 16);
static_assert(sizeof(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityFaction>) == 16);
static_assert(sizeof(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionEntity>) == 16);
static_assert(sizeof(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionFaction>) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_FactionToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityEntity>) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityFaction>) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionEntity>) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionFaction>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityEntity>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityFaction>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityToFactionEntities>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToEntity>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFaction>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntity>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionFaction>) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionToFactionEntities>) == 16);

#include "arkflownodedispositionentityentity.h"
static_assert(sizeof(ArkFlowNodeClearDispositionEntityEntity) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionEntityEntity) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionEntityEntity) == 16);

#include "arkflownodedispositionentityfaction.h"
static_assert(sizeof(ArkFlowNodeClearDispositionEntityFaction) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionEntityFaction) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionEntityFaction) == 16);

#include "arkflownodedispositionfactionentity.h"
static_assert(sizeof(ArkFlowNodeClearRelationshipFactionEntity) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionFactionEntity) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionFactionEntity) == 16);

#include "arkflownodedispositionfactionfaction.h"
static_assert(sizeof(ArkFlowNodeClearDispositionFactionFaction) == 16);
static_assert(sizeof(ArkFlowNodeGetDispositionFactionFaction) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionFactionFaction) == 16);

#include "arkflownodeendhostility.h"
static_assert(sizeof(ArkFlowNodeEndHostilityEntityEntity) == 16);
static_assert(sizeof(ArkFlowNodeEndHostilityEntityFaction) == 16);
static_assert(sizeof(ArkFlowNodeEndHostilityFactionEntity) == 16);
static_assert(sizeof(ArkFlowNodeEndHostilityFactionFaction) == 16);

#include "arkflownodeentitytofactionentities.h"
static_assert(sizeof(ArkFlowNodeClearDispositionEntityToFactionEntities) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionEntityToFactionEntities) == 16);

#include "arkflownodefaction.h"
static_assert(sizeof(ArkFlowNodeGetFaction) == 16);
static_assert(sizeof(ArkFlowNodeSetFaction) == 16);

#include "arkflownodefactionentitiestoentity.h"
static_assert(sizeof(ArkFlowNodeClearDispositionFactionEntitiesToEntity) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionFactionEntitiesToEntity) == 16);

#include "arkflownodefactionentitiestofaction.h"
static_assert(sizeof(ArkFlowNodeClearDispositionFactionEntitiesToFaction) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionFactionEntitiesToFaction) == 16);

#include "arkflownodefactionentitiestofactionentities.h"
static_assert(sizeof(ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities) == 16);

#include "arkflownodefactiontofactionentities.h"
static_assert(sizeof(ArkFlowNodeClearDispositionFactionToFactionEntities) == 16);
static_assert(sizeof(ArkFlowNodeSetDispositionFactionToFactionEntities) == 16);

#include "arkflownodeisdisposition.h"
static_assert(sizeof(ArkFlowNodeIsEntityFriendlyToEntity) == 16);
static_assert(sizeof(ArkFlowNodeIsEntityFriendlyToFaction) == 16);
static_assert(sizeof(ArkFlowNodeIsEntityHostileToEntity) == 16);
static_assert(sizeof(ArkFlowNodeIsEntityHostileToFaction) == 16);
static_assert(sizeof(ArkFlowNodeIsEntityNeutralToEntity) == 16);
static_assert(sizeof(ArkFlowNodeIsEntityNeutralToFaction) == 16);
static_assert(sizeof(ArkFlowNodeIsFactionFriendlyToEntity) == 16);
static_assert(sizeof(ArkFlowNodeIsFactionFriendlyToFaction) == 16);
static_assert(sizeof(ArkFlowNodeIsFactionHostileToEntity) == 16);
static_assert(sizeof(ArkFlowNodeIsFactionHostileToFaction) == 16);
static_assert(sizeof(ArkFlowNodeIsFactionNeutralToEntity) == 16);
static_assert(sizeof(ArkFlowNodeIsFactionNeutralToFaction) == 16);
#endif // MOONCRASH
