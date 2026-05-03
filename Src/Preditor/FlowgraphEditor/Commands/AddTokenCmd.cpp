#include "AddTokenCmd.h"

FlowgraphEditor::AddTokenCmd::AddTokenCmd(std::string name, int type)
{
    m_Token.name = std::move(name);
    m_Token.type = type;
}

void FlowgraphEditor::AddTokenCmd::Redo(Flowgraph& graph)
{
    graph.tokens.push_back(m_Token);
}

void FlowgraphEditor::AddTokenCmd::Undo(Flowgraph& graph)
{
    if (!graph.tokens.empty())
        graph.tokens.pop_back();
}
