// Header test file for path Prey/GameDll/effects/gameeffects/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameEffect.h"
static_assert(sizeof(CGameEffect) == 32);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "LightningGameEffect.h"
static_assert(sizeof(SLightningParams) == 68);
static_assert(sizeof(CLightningGameEffect) == 2216);
static_assert(sizeof(CLightningGameEffect::STarget) == 36);
static_assert(sizeof(CLightningGameEffect::SLightningSpark) == 88);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ParameterGameEffect.h"
static_assert(sizeof(CParameterGameEffect) == 64);
static_assert(sizeof(CParameterGameEffect::SSaturationData) == 4);
#endif
