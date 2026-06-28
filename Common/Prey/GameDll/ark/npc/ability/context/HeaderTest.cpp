// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/ability/context/
#include "ArkNpcAbilityContext.h"
static_assert(sizeof(ArkNpcAbilityContext) == 48);

#include "ArkNpcAbilityContextInstance.h"
static_assert(sizeof(ArkNpcAbilityContextInstance) == 32);

#include "ArkNpcAbilityContextInstanceStorage.h"
static_assert(sizeof(ArkNpcAbilityContextInstanceStorage) == 24);

#include "ArkNpcAbilityContextProfile.h"
static_assert(sizeof(ArkNpcAbilityContextProfile) == 40);
static_assert(sizeof(ArkNpcAbilityContextProfile::ContextIndexPair) == 16);

#include "ArkNpcAbilityContextProfileInstance.h"
static_assert(sizeof(ArkNpcAbilityContextProfileInstance) == 80);
#endif // MOONCRASH
