// Header test file for path Prey/GameDll/ark/npc/damagefsm/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDamageFsm.h"
static_assert(sizeof(ArkNpcDamageFsm) == 60);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcDamageFsmBase.h"
static_assert(sizeof(ArkNpcDamageFsmBase_template_<void>) == 56);
#endif
