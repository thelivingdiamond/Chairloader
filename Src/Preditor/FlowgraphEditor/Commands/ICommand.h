#pragma once

namespace FlowgraphEditor
{

class Flowgraph;

//! A reversible mutation of a Flowgraph. Concrete commands store the
//! before/after data they need to apply Redo and Undo idempotently.
class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void Redo(Flowgraph& graph) = 0;
    virtual void Undo(Flowgraph& graph) = 0;

    //! Optional coalescing hook. If this returns true, `other` is absorbed
    //! into `this` (caller must drop `other`). Used for things like drag-move
    //! where one logical action emits N per-frame commands.
    virtual bool TryMerge(const ICommand& /*other*/) { return false; }

    //! Short label for UI ("Move Node", "Connect Pins"). Must outlive the call.
    virtual const char* Name() const = 0;
};

} // namespace FlowgraphEditor
