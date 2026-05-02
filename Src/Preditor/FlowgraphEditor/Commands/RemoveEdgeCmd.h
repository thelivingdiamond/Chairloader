#pragma once
#include "ICommand.h"
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Removes an edge by id. Snapshots the edge data on construction so Undo
//! can restore it verbatim (including the original edge id, which the editor
//! lib uses as a link id).
class RemoveEdgeCmd : public ICommand
{
public:
    RemoveEdgeCmd(const Flowgraph& graph, int64_t edgeId);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return "Remove Edge"; }

private:
    Edge m_Edge;
    bool m_bSnapshotValid = false;
};

} // namespace FlowgraphEditor
