// Header test file for path Prey/ArkCommon/

#include "ArkContiguousMemory.h"
static_assert(sizeof(ArkContiguousMemory) == 24);

#include "ArkContiguousMemorySizer.h"
static_assert(sizeof(ArkContiguousMemorySizer) == 8);

#include "ArkDelegate.h"

#include "ArkRegularOutcome.h"
static_assert(sizeof(ArkRegularOutcome) == 4);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arkblackboardautoentry.h"
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkSafeIterator.h"
#include "arkintrusivelist.h"
class ArkNpcAnimActionObserver;
static_assert(sizeof(ArkIntrusiveListImpl::ArkIntrusiveListIterator<ArkNpcAnimActionObserver>) == 8);
static_assert(sizeof(ArkIntrusiveListImpl::ArkIntrusiveListConstIterator<ArkNpcAnimActionObserver>) == 8);
static_assert(sizeof(ArkSafeIterator<ArkIntrusiveListImpl::ArkIntrusiveListIterator<ArkNpcAnimActionObserver>>) == 16);
#endif
