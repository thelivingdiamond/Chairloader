#pragma once
#include "ICommand.h"

namespace FlowgraphEditor
{

//! Toggles the `enabled` flag on an edge. Stored as before/after so undo
//! restores the prior state independently of the current value.
class SetEdgeEnabledCmd : public ICommand
{
public:
    SetEdgeEnabledCmd(int64_t edgeId, bool oldEnabled, bool newEnabled);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return "Toggle Edge"; }

private:
    int64_t m_EdgeId;
    bool m_OldEnabled;
    bool m_NewEnabled;
};

} // namespace FlowgraphEditor
