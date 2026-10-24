// Header test file for path Prey/GameDll/ark/npc/gameeffect/pet/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect_Pet.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcGameEffectInstance_Pet) == 40);
static_assert(sizeof(ArkNpcGameEffect_Pet) == 16);
#endif
#endif
