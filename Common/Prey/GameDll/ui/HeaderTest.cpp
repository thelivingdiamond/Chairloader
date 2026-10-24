// Header test file for path Prey/GameDll/ui/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "UIGameEvents.h"
static_assert(sizeof(CUIGameEvents) == 72);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "UIInput.h"
static_assert(sizeof(CUIInput) == 152);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "UIMenuEvents.h"
static_assert(sizeof(CUIMenuEvents) == 104);
#endif
