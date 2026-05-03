#pragma once
#include <imgui.h>
#include "ICommand.h"

namespace FlowgraphEditor
{

//! Adjusts a commentbox node's Width / Height. Merges with prior resizes of
//! the same node so dragging the inspector's W/H fields collapses into one
//! undo entry instead of one-per-pixel.
class ResizeCommentBoxCmd : public ICommand
{
public:
    ResizeCommentBoxCmd(int64_t nodeId, ImVec2 oldSize, ImVec2 newSize);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    bool TryMerge(const ICommand& other) override;
    const char* Name() const override { return "Resize Commentbox"; }

private:
    int64_t m_NodeId;
    ImVec2 m_OldSize;
    ImVec2 m_NewSize;
};

} // namespace FlowgraphEditor
