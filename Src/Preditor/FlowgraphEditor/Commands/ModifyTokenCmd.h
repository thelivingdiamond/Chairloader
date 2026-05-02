#pragma once
#include "ICommand.h"
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Replaces the token at a given index with new data. Merges with prior
//! ModifyTokenCmds against the same index so rapid edits coalesce.
class ModifyTokenCmd : public ICommand
{
public:
    ModifyTokenCmd(size_t index, GraphToken oldData, GraphToken newData);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    bool TryMerge(const ICommand& other) override;
    const char* Name() const override { return "Modify Token"; }

private:
    size_t m_Index;
    GraphToken m_OldData;
    GraphToken m_NewData;
};

} // namespace FlowgraphEditor
