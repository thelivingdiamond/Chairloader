// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/damagefsm/states/
#include "ArkNpcDamageState.h"
static_assert(sizeof(ArkNpcDamageState) == 1);

#include "ArkNpcDamageState_Damaged.h"
static_assert(sizeof(ArkNpcDamageState_Damaged) == 1);

#include "ArkNpcDamageState_Destroyed.h"
static_assert(sizeof(ArkNpcDamageState_Destroyed) == 32);

#include "ArkNpcDamageState_Disabled.h"
static_assert(sizeof(ArkNpcDamageState_Disabled) == 12);

#include "ArkNpcDamageState_Undamaged.h"
static_assert(sizeof(ArkNpcDamageState_Undamaged) == 1);
#endif // MOONCRASH
