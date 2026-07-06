// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/graphics/
#include "ColorGradientManager.h"
static_assert(sizeof(Graphics::CColorGradientManager) == 48);
static_assert(sizeof(Graphics::CColorGradientManager::LoadedColorGradient) == 32);
static_assert(sizeof(Graphics::CColorGradientManager::LoadingColorGradient) == 16);
#endif // MOONCRASH
