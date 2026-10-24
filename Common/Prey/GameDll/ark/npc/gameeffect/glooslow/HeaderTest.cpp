// Header test file for path Prey/GameDll/ark/npc/gameeffect/glooslow/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect_Gloo.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcGameEffectInstance_Gloo) == 536);
static_assert(sizeof(ArkNpcGameEffect_Gloo) == 40);
#else
static_assert(sizeof(ArkNpcGameEffectInstance_Gloo) == 552);
static_assert(sizeof(ArkNpcGameEffect_Gloo) == 48);
#endif
#endif
