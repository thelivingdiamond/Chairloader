// Header test file for path Prey/GameDll/effects/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameEffectsSystem.h"
static_assert(sizeof(CGameEffectsSystem) == 48);
static_assert(sizeof(CGameEffectsSystem::SRegisterDataCallbacks) == 1);
static_assert(sizeof(CGameEffectsSystem::SRegisterGameCallbacks) == 1);
static_assert(sizeof(SGameEffectSystemStaticData) == 1);
#endif
