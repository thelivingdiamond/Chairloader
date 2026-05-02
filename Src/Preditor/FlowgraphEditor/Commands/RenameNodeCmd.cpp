#include "RenameNodeCmd.h"
#include "../Model/Flowgraph.h"

FlowgraphEditor::RenameNodeCmd::RenameNodeCmd(int64_t nodeId,
                                              std::string oldName,
                                              std::string newName)
    : m_NodeId(nodeId)
    , m_OldName(std::move(oldName))
    , m_NewName(std::move(newName))
{
}

void FlowgraphEditor::RenameNodeCmd::Redo(Flowgraph& graph)
{
    if (Node* n = graph.FindNode(m_NodeId))
        n->name = m_NewName;
}

void FlowgraphEditor::RenameNodeCmd::Undo(Flowgraph& graph)
{
    if (Node* n = graph.FindNode(m_NodeId))
        n->name = m_OldName;
}

bool FlowgraphEditor::RenameNodeCmd::TryMerge(const ICommand& other)
{
    auto* o = dynamic_cast<const RenameNodeCmd*>(&other);
    if (!o || o->m_NodeId != m_NodeId)
        return false;
    m_NewName = o->m_NewName;
    return true;
}
