// Header test file for path Prey/GameDll/ark/npc/gameeffect/stun/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect_Stun.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcGameEffectInstance_Stun) == 656);
#else
static_assert(sizeof(ArkNpcGameEffectInstance_Stun) == 664);
#endif
static_assert(sizeof(ArkNpcGameEffect_Stun) == 24);
#endif
