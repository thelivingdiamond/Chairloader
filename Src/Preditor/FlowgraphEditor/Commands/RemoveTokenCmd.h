#pragma once
#include "ICommand.h"
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Removes a token at a given index. Snapshots the token so Undo can restore it.
class RemoveTokenCmd : public ICommand
{
public:
    RemoveTokenCmd(const Flowgraph& graph, size_t index);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return "Remove Token"; }

private:
    GraphToken m_Token;
    size_t m_Index = 0;
    bool m_bSnapshotValid = false;
};

} // namespace FlowgraphEditor
