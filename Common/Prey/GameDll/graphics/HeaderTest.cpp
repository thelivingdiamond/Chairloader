// Header test file for path Prey/GameDll/graphics/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ColorGradientManager.h"
static_assert(sizeof(Graphics::CColorGradientManager) == 48);
static_assert(sizeof(Graphics::CColorGradientManager::LoadedColorGradient) == 32);
static_assert(sizeof(Graphics::CColorGradientManager::LoadingColorGradient) == 16);
#endif
