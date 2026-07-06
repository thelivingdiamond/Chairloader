// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/utility/
#include "SingleAllocTextBlock.h"
static_assert(sizeof(CSingleAllocTextBlock) == 48);
static_assert(sizeof(CSingleAllocTextBlock::SReuseDuplicatedStrings) == 8);
#endif // MOONCRASH
