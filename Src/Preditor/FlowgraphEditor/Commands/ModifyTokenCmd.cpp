#include "ModifyTokenCmd.h"

FlowgraphEditor::ModifyTokenCmd::ModifyTokenCmd(size_t index, GraphToken oldData, GraphToken newData)
    : m_Index(index)
    , m_OldData(std::move(oldData))
    , m_NewData(std::move(newData))
{
}

void FlowgraphEditor::ModifyTokenCmd::Redo(Flowgraph& graph)
{
    if (m_Index < graph.tokens.size())
        graph.tokens[m_Index] = m_NewData;
}

void FlowgraphEditor::ModifyTokenCmd::Undo(Flowgraph& graph)
{
    if (m_Index < graph.tokens.size())
        graph.tokens[m_Index] = m_OldData;
}

bool FlowgraphEditor::ModifyTokenCmd::TryMerge(const ICommand& other)
{
    auto* o = dynamic_cast<const ModifyTokenCmd*>(&other);
    if (!o || o->m_Index != m_Index)
        return false;
    m_NewData = o->m_NewData;
    return true;
}
