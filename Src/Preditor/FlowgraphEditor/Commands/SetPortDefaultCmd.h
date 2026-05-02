#pragma once
#include "ICommand.h"

namespace FlowgraphEditor
{

//! Updates an input port's default value on a node. Merges with prior commands
//! for the same (node, port) so rapid edits coalesce into one undo entry.
class SetPortDefaultCmd : public ICommand
{
public:
    SetPortDefaultCmd(int64_t nodeId, std::string portName,
                      std::string oldValue, std::string newValue);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    bool TryMerge(const ICommand& other) override;
    const char* Name() const override { return "Edit Port Default"; }

private:
    int64_t m_NodeId;
    std::string m_PortName;
    std::string m_OldValue;
    std::string m_NewValue;
};

} // namespace FlowgraphEditor
