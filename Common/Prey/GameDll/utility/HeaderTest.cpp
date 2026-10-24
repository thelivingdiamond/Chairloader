// Header test file for path Prey/GameDll/utility/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "SingleAllocTextBlock.h"
static_assert(sizeof(CSingleAllocTextBlock) == 48);
static_assert(sizeof(CSingleAllocTextBlock::SReuseDuplicatedStrings) == 8);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "MaskedVar.h"
#include <Prey/GameDll/CHealth.h>
static_assert(sizeof(CMaskedVarT<float, uint32, 0xffffffff>) == 8);
static_assert(sizeof(CMaskedVarT<int, uint32, 0xffffffff>) == 8);
static_assert(sizeof(CHealth) == 24);
#endif
