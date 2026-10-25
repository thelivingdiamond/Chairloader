// Header test file for path Prey/GameDll/ark/npc/gameeffect/underground/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect_Underground.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcUndergroundReceiver) == 32);
static_assert(sizeof(ArkNpcGameEffectInstance_Underground) == 304);
static_assert(sizeof(ArkNpcGameEffect_Underground) == 72);
#endif
#endif
