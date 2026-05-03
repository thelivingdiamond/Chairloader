#pragma once
#include "Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Process-lifetime clipboard for cut/copy/paste between tabs (and within one).
//! Holds full Node/Edge snapshots with their original ids — paste remaps to
//! fresh ids in the target graph. Edges with one endpoint outside the copied
//! selection are dropped at copy time.
struct Clipboard
{
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    bool Empty() const { return nodes.empty(); }
    void Clear() { nodes.clear(); edges.clear(); }

    static Clipboard& Get();
};

} // namespace FlowgraphEditor
