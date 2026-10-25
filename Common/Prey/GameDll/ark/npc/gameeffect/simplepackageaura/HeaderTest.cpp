// Header test file for path Prey/GameDll/ark/npc/gameeffect/simplepackageaura/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect_SimplePackageAura.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcGameEffect_SimplePackageAura) == 48);
#else
static_assert(sizeof(ArkNpcGameEffect_SimplePackageAura) == 56);
#endif
#endif
