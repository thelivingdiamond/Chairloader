#pragma once
#include "ICommand.h"
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Removes a node by id. Does NOT cascade to incident edges — the caller is
//! responsible for adding RemoveEdgeCmds for those *before* the RemoveNodeCmd
//! in a CompositeCommand. Snapshots the node data so Undo restores it.
class RemoveNodeCmd : public ICommand
{
public:
    RemoveNodeCmd(const Flowgraph& graph, int64_t nodeId);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return "Remove Node"; }

private:
    Node m_Node;
    bool m_bSnapshotValid = false;
};

} // namespace FlowgraphEditor
