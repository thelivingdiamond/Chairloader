// Header test file for path Prey/GameDll/effects/rendernodes/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "lightningnode.h"
static_assert(sizeof(CLightningRenderNode) == 304);
static_assert(sizeof(CLightningRenderNode::CTriStrip) == 56);
static_assert(sizeof(CLightningRenderNode::SPointData) == 72);
static_assert(sizeof(CLightningRenderNode::CSegment) == 60);
#endif
