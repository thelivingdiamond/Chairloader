#include <algorithm>
#include "Flowgraph.h"

namespace FlowgraphEditor
{

Pin* Node::FindInput(std::string_view name)
{
    for (auto& p : inputs)
        if (p.name == name)
            return &p;
    return nullptr;
}

Pin* Node::FindOutput(std::string_view name)
{
    for (auto& p : outputs)
        if (p.name == name)
            return &p;
    return nullptr;
}

const Pin* Node::FindInput(std::string_view name) const
{
    for (const auto& p : inputs)
        if (p.name == name)
            return &p;
    return nullptr;
}

const Pin* Node::FindOutput(std::string_view name) const
{
    for (const auto& p : outputs)
        if (p.name == name)
            return &p;
    return nullptr;
}

Node* Flowgraph::FindNode(int64_t id)
{
    for (auto& n : nodes)
        if (n.id == id)
            return &n;
    return nullptr;
}

const Node* Flowgraph::FindNode(int64_t id) const
{
    for (const auto& n : nodes)
        if (n.id == id)
            return &n;
    return nullptr;
}

Edge* Flowgraph::FindEdge(int64_t id)
{
    for (auto& e : edges)
        if (e.id == id)
            return &e;
    return nullptr;
}

const Edge* Flowgraph::FindEdge(int64_t id) const
{
    for (const auto& e : edges)
        if (e.id == id)
            return &e;
    return nullptr;
}

int64_t Flowgraph::ResolvePinId(int64_t nodeId, std::string_view portName, bool isInput) const
{
    const Node* n = FindNode(nodeId);
    if (!n)
        return 0;
    const Pin* p = isInput ? n->FindInput(portName) : n->FindOutput(portName);
    return p ? p->id : 0;
}

PinLocation Flowgraph::FindPinLocation(int64_t pinId) const
{
    for (const Node& n : nodes)
    {
        for (const Pin& p : n.inputs)
            if (p.id == pinId)
                return { n.id, p.name, true };
        for (const Pin& p : n.outputs)
            if (p.id == pinId)
                return { n.id, p.name, false };
    }
    return {};
}

void Flowgraph::RebuildIdCounters()
{
    int64_t maxNode = 0;
    int64_t maxPin = m_NextPinId - 1;
    int64_t maxEdge = m_NextEdgeId - 1;

    for (const Node& n : nodes)
    {
        maxNode = std::max(maxNode, n.id);
        for (const Pin& p : n.inputs)  maxPin = std::max(maxPin, p.id);
        for (const Pin& p : n.outputs) maxPin = std::max(maxPin, p.id);
    }
    for (const Edge& e : edges)
        maxEdge = std::max(maxEdge, e.id);

    m_NextNodeId = maxNode + 1;
    m_NextPinId  = maxPin  + 1;
    m_NextEdgeId = maxEdge + 1;
}

} // namespace FlowgraphEditor
