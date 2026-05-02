#include "CommandHistory.h"

namespace FlowgraphEditor
{

namespace
{
constexpr size_t kUnreachable = static_cast<size_t>(-1);
}

CommandHistory::CommandHistory(Flowgraph& graph)
    : m_Graph(graph)
{
}

CommandHistory::~CommandHistory() = default;

void CommandHistory::Execute(std::unique_ptr<ICommand> cmd)
{
    cmd->Redo(m_Graph);

    const bool merged = !m_Undo.empty() && m_Undo.back()->TryMerge(*cmd);
    if (!merged)
    {
        m_Undo.push_back(std::move(cmd));
        if (m_Undo.size() > kMaxSize)
        {
            m_Undo.erase(m_Undo.begin());
            if (m_SavedAnchor != kUnreachable)
                m_SavedAnchor = (m_SavedAnchor > 0) ? m_SavedAnchor - 1 : kUnreachable;
        }
    }

    // If a saved anchor lived in the about-to-be-discarded redo stack, we
    // can never reach the saved state again from this branch.
    if (!m_Redo.empty() && m_SavedAnchor > m_Undo.size())
        m_SavedAnchor = kUnreachable;
    m_Redo.clear();
}

void CommandHistory::Undo()
{
    if (m_Undo.empty())
        return;
    auto cmd = std::move(m_Undo.back());
    m_Undo.pop_back();
    cmd->Undo(m_Graph);
    m_Redo.push_back(std::move(cmd));
}

void CommandHistory::Redo()
{
    if (m_Redo.empty())
        return;
    auto cmd = std::move(m_Redo.back());
    m_Redo.pop_back();
    cmd->Redo(m_Graph);
    m_Undo.push_back(std::move(cmd));
}

bool CommandHistory::IsDirty() const
{
    return m_SavedAnchor != m_Undo.size();
}

void CommandHistory::MarkClean()
{
    m_SavedAnchor = m_Undo.size();
}

const char* CommandHistory::PeekUndoName() const
{
    return m_Undo.empty() ? "" : m_Undo.back()->Name();
}

const char* CommandHistory::PeekRedoName() const
{
    return m_Redo.empty() ? "" : m_Redo.back()->Name();
}

} // namespace FlowgraphEditor
