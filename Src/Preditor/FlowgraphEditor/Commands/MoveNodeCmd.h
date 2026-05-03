#pragma once
#include "ICommand.h"

namespace FlowgraphEditor
{

//! Reference command: moves a node from oldPos to newPos.
//! Successive moves of the same node are coalesced via TryMerge so a drag
//! produces one undo entry rather than one per frame.
class MoveNodeCmd : public ICommand
{
public:
    MoveNodeCmd(int64_t nodeId, ImVec2 oldPos, ImVec2 newPos);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    bool TryMerge(const ICommand& other) override;
    const char* Name() const override { return "Move Node"; }

private:
    int64_t m_NodeId;
    ImVec2 m_OldPos;
    ImVec2 m_NewPos;
};

} // namespace FlowgraphEditor
