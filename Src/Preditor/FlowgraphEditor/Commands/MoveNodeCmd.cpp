#include "MoveNodeCmd.h"
#include "../Model/Flowgraph.h"

FlowgraphEditor::MoveNodeCmd::MoveNodeCmd(int64_t nodeId, ImVec2 oldPos, ImVec2 newPos)
    : m_NodeId(nodeId)
    , m_OldPos(oldPos)
    , m_NewPos(newPos)
{
}

void FlowgraphEditor::MoveNodeCmd::Redo(Flowgraph& graph)
{
    if (Node* node = graph.FindNode(m_NodeId))
        node->pos = m_NewPos;
}

void FlowgraphEditor::MoveNodeCmd::Undo(Flowgraph& graph)
{
    if (Node* node = graph.FindNode(m_NodeId))
        node->pos = m_OldPos;
}

bool FlowgraphEditor::MoveNodeCmd::TryMerge(const ICommand& other)
{
    auto* o = dynamic_cast<const MoveNodeCmd*>(&other);
    if (!o || o->m_NodeId != m_NodeId)
        return false;
    m_NewPos = o->m_NewPos;
    return true;
}
