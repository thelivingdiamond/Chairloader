// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header test file for path Prey/GameDll/EntityUtility/EntityEffects.h
#include "EntityEffects.h"
static_assert(sizeof(EntityEffects::SLightAttachParams) == 104);
static_assert(sizeof(EntityEffects::CEffectsController) == 40);
static_assert(sizeof(EntityEffects::SEffectInfo) == 24);
static_assert(sizeof(EntityEffects::SEffectAttachParams) == 36);
static_assert(sizeof(EntityEffects::SEffectSpawnParams) == 36);
#else // MOONCRASH
// Header test file for path Prey/GameDll/EntityUtility/
#include "EntityEffects.h"
static_assert(sizeof(EntityEffects::CEffectsController) == 40);
static_assert(sizeof(EntityEffects::SEffectAttachParams) == 36);
static_assert(sizeof(EntityEffects::SEffectInfo) == 24);
static_assert(sizeof(EntityEffects::SEffectSpawnParams) == 36);
static_assert(sizeof(EntityEffects::SLightAttachParams) == 104);
#endif // !MOONCRASH
