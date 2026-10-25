
#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "TCurve.h"
static_assert(sizeof(TCurve<TRangedType<float, 0, 1, 0>>) == 8);
static_assert(sizeof(TCurve<TRangedType<float, 0, 2147483647, 0>>) == 8);
static_assert(sizeof(TCurve<TRangedType<float, 0, 360, 0>>::CCustomInfo) == 32);
#endif
