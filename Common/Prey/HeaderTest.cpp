// Header test file for path Prey/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "Arkbreakableglassutil.h"
static_assert(sizeof(ArkGlassFrag) == 36);
static_assert(sizeof(ArkGlassGeo) == 112);
#endif
