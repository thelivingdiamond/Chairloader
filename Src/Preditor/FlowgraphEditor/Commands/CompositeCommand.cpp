#include "CompositeCommand.h"

FlowgraphEditor::CompositeCommand::CompositeCommand(std::string name)
    : m_Name(std::move(name))
{
}

void FlowgraphEditor::CompositeCommand::Add(std::unique_ptr<ICommand> cmd)
{
    if (cmd)
        m_Children.push_back(std::move(cmd));
}

void FlowgraphEditor::CompositeCommand::Redo(Flowgraph& graph)
{
    for (auto& child : m_Children)
        child->Redo(graph);
}

void FlowgraphEditor::CompositeCommand::Undo(Flowgraph& graph)
{
    for (auto it = m_Children.rbegin(); it != m_Children.rend(); ++it)
        (*it)->Undo(graph);
}
