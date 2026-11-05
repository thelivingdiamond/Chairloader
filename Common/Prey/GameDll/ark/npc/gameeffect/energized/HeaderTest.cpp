// Header test file for path Prey/GameDll/ark/npc/gameeffect/energized/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect_Energized.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcGameEffect_Energized) == 48);
#else
static_assert(sizeof(ArkNpcGameEffect_Energized) == 56);
#endif
#endif
