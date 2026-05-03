#include "RemoveTokenCmd.h"

FlowgraphEditor::RemoveTokenCmd::RemoveTokenCmd(const Flowgraph& graph, size_t index)
    : m_Index(index)
{
    if (index < graph.tokens.size())
    {
        m_Token = graph.tokens[index];
        m_bSnapshotValid = true;
    }
}

void FlowgraphEditor::RemoveTokenCmd::Redo(Flowgraph& graph)
{
    if (m_bSnapshotValid && m_Index < graph.tokens.size())
        graph.tokens.erase(graph.tokens.begin() + m_Index);
}

void FlowgraphEditor::RemoveTokenCmd::Undo(Flowgraph& graph)
{
    if (m_bSnapshotValid && m_Index <= graph.tokens.size())
        graph.tokens.insert(graph.tokens.begin() + m_Index, m_Token);
}
