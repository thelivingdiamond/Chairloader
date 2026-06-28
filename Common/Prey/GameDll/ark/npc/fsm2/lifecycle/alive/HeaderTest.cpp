// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/fsm2/lifecycle/alive/
#include "ArkNpcAliveFsm.h"
static_assert(sizeof(ArkNpcAliveFsm) == 704);

#include "ArkNpcAliveState_Broken.h"
static_assert(sizeof(ArkNpcAliveState_Broken) == 184);

#include "ArkNpcAliveState_Conscious.h"
static_assert(sizeof(ArkNpcAliveState_Conscious) == 496);

#include "ArkNpcAliveState_Unconscious.h"
static_assert(sizeof(ArkNpcAliveState_Unconscious) == 1);
#endif // MOONCRASH
