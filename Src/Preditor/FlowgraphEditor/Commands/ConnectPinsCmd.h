#pragma once
#include "ICommand.h"

namespace FlowgraphEditor
{

//! Adds a new edge between an output port and an input port. The edge id is
//! allocated on first Redo and reused on subsequent Redo/Undo cycles so the
//! editor's link id stays stable across undo.
class ConnectPinsCmd : public ICommand
{
public:
    ConnectPinsCmd(int64_t fromNodeId, std::string fromPort,
                   int64_t toNodeId,   std::string toPort);

    void Redo(Flowgraph& graph) override;
    void Undo(Flowgraph& graph) override;
    const char* Name() const override { return "Connect Pins"; }

private:
    int64_t m_FromNodeId;
    std::string m_FromPort;
    int64_t m_ToNodeId;
    std::string m_ToPort;
    int64_t m_EdgeId = 0;
};

} // namespace FlowgraphEditor
