
#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include <Prey/CryAISystem/navigation/mnm/DynamicSpanGrid.h>
static_assert(sizeof(MNM::DynamicSpanGrid) == 88);
static_assert(sizeof(MNM::DynamicSpanGrid::Element) == 16);
static_assert(sizeof(MNM::DynamicSpanGrid::Allocator) == 40);
#endif
