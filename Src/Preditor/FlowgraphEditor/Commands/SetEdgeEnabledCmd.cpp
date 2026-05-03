#include "SetEdgeEnabledCmd.h"
#include "../Model/Flowgraph.h"

FlowgraphEditor::SetEdgeEnabledCmd::SetEdgeEnabledCmd(int64_t edgeId,
                                                       bool oldEnabled,
                                                       bool newEnabled)
    : m_EdgeId(edgeId)
    , m_OldEnabled(oldEnabled)
    , m_NewEnabled(newEnabled)
{
}

void FlowgraphEditor::SetEdgeEnabledCmd::Redo(Flowgraph& graph)
{
    if (Edge* e = graph.FindEdge(m_EdgeId))
        e->enabled = m_NewEnabled;
}

void FlowgraphEditor::SetEdgeEnabledCmd::Undo(Flowgraph& graph)
{
    if (Edge* e = graph.FindEdge(m_EdgeId))
        e->enabled = m_OldEnabled;
}
