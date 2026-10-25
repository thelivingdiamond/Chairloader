// Header test file for path Prey/GameDll/ark/npc/gameeffect/weavershield/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect_WeaverShield.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcGameEffect_WeaverShield) == 64);
#else
static_assert(sizeof(ArkNpcGameEffect_WeaverShield) == 72);
#endif
#endif
