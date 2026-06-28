// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/effects/rendernodes/
#include "lightningnode.h"
static_assert(sizeof(CLightningRenderNode) == 304);
static_assert(sizeof(CLightningRenderNode::CSegment) == 60);
static_assert(sizeof(CLightningRenderNode::CTriStrip) == 56);
static_assert(sizeof(CLightningRenderNode::SPointData) == 72);
#endif // MOONCRASH
