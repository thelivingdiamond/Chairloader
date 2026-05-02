#pragma once
#include "ICommand.h"

namespace FlowgraphEditor
{

class Flowgraph;

//! Per-Flowgraph undo/redo stack. Bounded; coalesces compatible commands.
//! Tracks a "saved anchor" so IsDirty() correctly returns false when the
//! user undoes back to the last-saved state.
class CommandHistory
{
public:
    static constexpr size_t kMaxSize = 1000;

    explicit CommandHistory(Flowgraph& graph);
    ~CommandHistory();

    CommandHistory(const CommandHistory&) = delete;
    CommandHistory& operator=(const CommandHistory&) = delete;

    //! Runs cmd's Redo, then pushes onto the undo stack. Tries to merge into
    //! the top entry first; if it merges, cmd is dropped instead. Clears redo.
    void Execute(std::unique_ptr<ICommand> cmd);

    bool CanUndo() const { return !m_Undo.empty(); }
    bool CanRedo() const { return !m_Redo.empty(); }

    void Undo();
    void Redo();

    bool IsDirty() const;
    void MarkClean();

    //! Empty string if there's nothing to undo/redo.
    const char* PeekUndoName() const;
    const char* PeekRedoName() const;

private:
    Flowgraph& m_Graph;
    std::vector<std::unique_ptr<ICommand>> m_Undo;
    std::vector<std::unique_ptr<ICommand>> m_Redo;

    // Position in the linear undo stream that matches the on-disk state.
    // IsDirty() == (m_SavedAnchor != m_Undo.size()). Set to SIZE_MAX once the
    // saved point becomes unreachable (e.g. evicted by the bounded size).
    size_t m_SavedAnchor = 0;
};

} // namespace FlowgraphEditor
