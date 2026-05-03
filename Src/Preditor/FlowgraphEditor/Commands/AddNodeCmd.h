#pragma once
#include "ICommand.h"
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Adds a new node of the given class at the given canvas position.
//! On first Redo, allocates the node id and pin ids and resolves the prototype.
//! Subsequent Redo/Undo cycles reuse the snapshot so ids stay stable across undo.
class AddNodeCmd : public ICommand
{
public:
    AddNodeCmd(std::string className, ImVec2 pos);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return "Add Node"; }

private:
    std::string m_ClassName;
    ImVec2 m_Pos;
    Node m_Node;
    bool m_bAllocated = false;
};

} // namespace FlowgraphEditor
