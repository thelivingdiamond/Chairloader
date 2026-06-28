// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/ability/prereqmodifier/
#include "ArkNpcAbilityPrereqModifier.h"
static_assert(sizeof(ArkNpcAbilityPrereqModifier) == 8);

#include "arknpcabilityprereqmodifiertemplate.h"
static_assert(sizeof(ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDifficultyEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>) == 16);
static_assert(sizeof(ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfDoomClockLevelEqual,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>) == 16);
static_assert(sizeof(ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentGreater,ArkNpcAbilityPrereqModifierCondition_Greater,ArkNpcAbilityPrereqModification_Add>) == 16);
static_assert(sizeof(ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfHealthPercentLess,ArkNpcAbilityPrereqModifierCondition_Less,ArkNpcAbilityPrereqModification_Add>) == 16);
static_assert(sizeof(ArkNpcAbilityPrereqModifierTemplate<ArkNpcAbilityPrereqModifier_AddIfLowG,ArkNpcAbilityPrereqModifierCondition_Equal,ArkNpcAbilityPrereqModification_Add>) == 16);
#endif // MOONCRASH
