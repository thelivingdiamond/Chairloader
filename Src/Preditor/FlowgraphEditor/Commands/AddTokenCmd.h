#pragma once
#include "ICommand.h"
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! Appends a token to the active graph.
class AddTokenCmd : public ICommand
{
public:
    AddTokenCmd(std::string name, int type);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return "Add Token"; }

private:
    GraphToken m_Token;
};

} // namespace FlowgraphEditor
