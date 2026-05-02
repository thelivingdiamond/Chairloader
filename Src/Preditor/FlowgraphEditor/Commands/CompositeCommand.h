#pragma once
#include "ICommand.h"

namespace FlowgraphEditor
{

//! A command that runs a list of children in order on Redo, in reverse on Undo.
//! Used to make multi-step user actions (delete-selection, drag-multiple-nodes)
//! appear as a single undo entry.
class CompositeCommand : public ICommand
{
public:
    explicit CompositeCommand(std::string name);

    void Add(std::unique_ptr<ICommand> cmd);
    bool IsEmpty() const { return m_Children.empty(); }
    size_t Size() const { return m_Children.size(); }

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return m_Name.c_str(); }

private:
    std::string m_Name;
    std::vector<std::unique_ptr<ICommand>> m_Children;
};

} // namespace FlowgraphEditor
