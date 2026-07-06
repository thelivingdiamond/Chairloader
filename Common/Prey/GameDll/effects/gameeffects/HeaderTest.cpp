// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/effects/gameeffects/
#include "GameEffect.h"
static_assert(sizeof(CGameEffect) == 32);

#include "LightningGameEffect.h"
static_assert(sizeof(CLightningGameEffect) == 2216);
static_assert(sizeof(CLightningGameEffect::SLightningSpark) == 88);
static_assert(sizeof(CLightningGameEffect::STarget) == 36);
static_assert(sizeof(SLightningParams) == 68);

#include "ParameterGameEffect.h"
static_assert(sizeof(CParameterGameEffect) == 64);
static_assert(sizeof(CParameterGameEffect::SSaturationData) == 4);
#endif // MOONCRASH
