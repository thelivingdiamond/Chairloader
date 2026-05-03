#include "ResizeCommentBoxCmd.h"
#include "../Model/Flowgraph.h"

FlowgraphEditor::ResizeCommentBoxCmd::ResizeCommentBoxCmd(int64_t nodeId,
                                                          ImVec2 oldSize,
                                                          ImVec2 newSize)
    : m_NodeId(nodeId)
    , m_OldSize(oldSize)
    , m_NewSize(newSize)
{
}

void FlowgraphEditor::ResizeCommentBoxCmd::Redo(Flowgraph& graph)
{
    if (Node* n = graph.FindNode(m_NodeId))
    {
        n->commentWidth  = m_NewSize.x;
        n->commentHeight = m_NewSize.y;
    }
}

void FlowgraphEditor::ResizeCommentBoxCmd::Undo(Flowgraph& graph)
{
    if (Node* n = graph.FindNode(m_NodeId))
    {
        n->commentWidth  = m_OldSize.x;
        n->commentHeight = m_OldSize.y;
    }
}

bool FlowgraphEditor::ResizeCommentBoxCmd::TryMerge(const ICommand& other)
{
    auto* o = dynamic_cast<const ResizeCommentBoxCmd*>(&other);
    if (!o || o->m_NodeId != m_NodeId)
        return false;
    m_NewSize = o->m_NewSize;
    return true;
}
