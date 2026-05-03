#pragma once
#include "ICommand.h"

namespace FlowgraphEditor
{

//! Updates a node's "Name" attribute (used by commentboxes as their label).
//! Merges with prior renames of the same node so per-keystroke edits collapse
//! into one undo entry.
class RenameNodeCmd : public ICommand
{
public:
    RenameNodeCmd(int64_t nodeId, std::string oldName, std::string newName);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    bool TryMerge(const ICommand& other) override;
    const char* Name() const override { return "Rename Node"; }

private:
    int64_t m_NodeId;
    std::string m_OldName;
    std::string m_NewName;
};

} // namespace FlowgraphEditor
