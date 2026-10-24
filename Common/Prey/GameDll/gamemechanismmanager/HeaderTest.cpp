// Header test file for path Prey/GameDll/gamemechanismmanager/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameMechanismBase.h"
static_assert(sizeof(CGameMechanismBase) == 24);
static_assert(sizeof(CGameMechanismBase::SLinkedListPointers) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "GameMechanismManager.h"
static_assert(sizeof(CGameMechanismManager) == 8);
#endif
