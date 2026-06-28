// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/ability/operatorstrafe/
#include "ArkNpcAbility_OperatorStrafeAttack.h"
static_assert(sizeof(ArkNpcAbilityInstance_OperatorStrafeAttack) == 2088);
static_assert(sizeof(ArkNpcAbility_OperatorStrafeAttack) == 24);

#include "ArkOperatorStrafeAttackFsm.h"
static_assert(sizeof(ArkOperatorStrafeAttackFsm) == 2048);
static_assert(sizeof(ArkOperatorStrafeFsmBase_template_<void>) == 1360);
static_assert(sizeof(ArkOperatorStrafeFsmBase_template_<void>::StateSelector<1>) == 1);
static_assert(sizeof(ArkOperatorStrafeState_Strafe) == 504);
#endif // MOONCRASH
