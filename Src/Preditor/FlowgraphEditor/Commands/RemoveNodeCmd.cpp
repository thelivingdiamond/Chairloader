#include <algorithm>
#include "RemoveNodeCmd.h"

FlowgraphEditor::RemoveNodeCmd::RemoveNodeCmd(const Flowgraph& graph, int64_t nodeId)
{
    if (const Node* n = graph.FindNode(nodeId))
    {
        m_Node = *n;
        m_bSnapshotValid = true;
    }
}

void FlowgraphEditor::RemoveNodeCmd::Redo(Flowgraph& graph)
{
    if (!m_bSnapshotValid)
        return;
    auto& nodes = graph.nodes;
    nodes.erase(
        std::remove_if(nodes.begin(), nodes.end(),
            [this](const Node& n) { return n.id == m_Node.id; }),
        nodes.end());
}

void FlowgraphEditor::RemoveNodeCmd::Undo(Flowgraph& graph)
{
    if (!m_bSnapshotValid)
        return;
    graph.nodes.push_back(m_Node);
}
