#include <algorithm>
#include "RemoveEdgeCmd.h"

FlowgraphEditor::RemoveEdgeCmd::RemoveEdgeCmd(const Flowgraph& graph, int64_t edgeId)
{
    if (const Edge* e = graph.FindEdge(edgeId))
    {
        m_Edge = *e;
        m_bSnapshotValid = true;
    }
}

void FlowgraphEditor::RemoveEdgeCmd::Redo(Flowgraph& graph)
{
    if (!m_bSnapshotValid)
        return;
    auto& edges = graph.edges;
    edges.erase(
        std::remove_if(edges.begin(), edges.end(),
            [this](const Edge& e) { return e.id == m_Edge.id; }),
        edges.end());
}

void FlowgraphEditor::RemoveEdgeCmd::Undo(Flowgraph& graph)
{
    if (!m_bSnapshotValid)
        return;
    graph.edges.push_back(m_Edge);
}
