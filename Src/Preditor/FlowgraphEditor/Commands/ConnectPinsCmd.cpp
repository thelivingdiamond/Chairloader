#include <algorithm>
#include "ConnectPinsCmd.h"
#include "../Model/Flowgraph.h"

FlowgraphEditor::ConnectPinsCmd::ConnectPinsCmd(int64_t fromNodeId, std::string fromPort,
                                                 int64_t toNodeId,   std::string toPort)
    : m_FromNodeId(fromNodeId)
    , m_FromPort(std::move(fromPort))
    , m_ToNodeId(toNodeId)
    , m_ToPort(std::move(toPort))
{
}

void FlowgraphEditor::ConnectPinsCmd::Redo(Flowgraph& graph)
{
    if (m_EdgeId == 0)
        m_EdgeId = graph.AllocEdgeId();

    Edge edge;
    edge.id = m_EdgeId;
    edge.fromNodeId = m_FromNodeId;
    edge.fromPort = m_FromPort;
    edge.toNodeId = m_ToNodeId;
    edge.toPort = m_ToPort;
    edge.enabled = true;
    graph.edges.push_back(std::move(edge));
}

void FlowgraphEditor::ConnectPinsCmd::Undo(Flowgraph& graph)
{
    auto& edges = graph.edges;
    edges.erase(
        std::remove_if(edges.begin(), edges.end(),
            [this](const Edge& e) { return e.id == m_EdgeId; }),
        edges.end());
}
