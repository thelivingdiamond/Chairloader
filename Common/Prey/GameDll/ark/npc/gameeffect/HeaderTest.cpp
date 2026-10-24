// Header test file for path Prey/GameDll/ark/npc/gameeffect/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffect.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcGameEffect) == 8);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcGameEffectManager.h"
static_assert(sizeof(ArkNpcGameEffectManager) == 136);
static_assert(sizeof(ArkNpcGameEffectManager::AttachedGameEffect) == 40);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcgameeffectreflections.h"
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcgameeffecttemplate.h"
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcNullGameEffect.h"
static_assert(sizeof(ArkNpcNullGameEffect) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcNullGameEffect, ArkNpcGameEffectInstance>) == 8);
#endif
