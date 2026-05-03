#include "SetPortDefaultCmd.h"
#include "../Model/Flowgraph.h"

FlowgraphEditor::SetPortDefaultCmd::SetPortDefaultCmd(int64_t nodeId, std::string portName,
                                                       std::string oldValue, std::string newValue)
    : m_NodeId(nodeId)
    , m_PortName(std::move(portName))
    , m_OldValue(std::move(oldValue))
    , m_NewValue(std::move(newValue))
{
}

void FlowgraphEditor::SetPortDefaultCmd::Redo(Flowgraph& graph)
{
    if (Node* n = graph.FindNode(m_NodeId))
        n->inputDefaults[m_PortName] = m_NewValue;
}

void FlowgraphEditor::SetPortDefaultCmd::Undo(Flowgraph& graph)
{
    if (Node* n = graph.FindNode(m_NodeId))
        n->inputDefaults[m_PortName] = m_OldValue;
}

bool FlowgraphEditor::SetPortDefaultCmd::TryMerge(const ICommand& other)
{
    auto* o = dynamic_cast<const SetPortDefaultCmd*>(&other);
    if (!o || o->m_NodeId != m_NodeId || o->m_PortName != m_PortName)
        return false;
    m_NewValue = o->m_NewValue;
    return true;
}
