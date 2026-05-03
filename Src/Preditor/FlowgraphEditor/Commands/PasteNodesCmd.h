#pragma once
#include "ICommand.h"
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Inserts a batch of pre-built nodes and edges into the graph as one
//! undoable operation. The caller is responsible for allocating fresh
//! node/pin/edge ids before constructing the command — this lets paste,
//! duplicate, and any future bulk-add path share the same insertion logic
//! while staying independent of the source of truth (clipboard vs. selection).
class PasteNodesCmd : public ICommand
{
public:
    PasteNodesCmd(std::vector<Node> nodes, std::vector<Edge> edges, const char* name);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return m_Name; }

private:
    std::vector<Node> m_Nodes;
    std::vector<Edge> m_Edges;
    const char* m_Name;
};

} // namespace FlowgraphEditor
