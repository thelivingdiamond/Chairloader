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

int64_t Flowgraph::ResolvePinId(int64_t nodeId, std::string_view portName, bool isInput) const
{
    const Node* n = FindNode(nodeId);
    if (!n)
        return 0;
    const Pin* p = isInput ? n->FindInput(portName) : n->FindOutput(portName);
    return p ? p->id : 0;
}

} // namespace FlowgraphEditor
