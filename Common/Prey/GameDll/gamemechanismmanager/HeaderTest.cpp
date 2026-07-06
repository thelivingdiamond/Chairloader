// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/gamemechanismmanager/
#include "GameMechanismBase.h"
static_assert(sizeof(CGameMechanismBase) == 24);
static_assert(sizeof(CGameMechanismBase::SLinkedListPointers) == 16);

#include "GameMechanismManager.h"
static_assert(sizeof(CGameMechanismManager) == 8);
#endif // MOONCRASH
