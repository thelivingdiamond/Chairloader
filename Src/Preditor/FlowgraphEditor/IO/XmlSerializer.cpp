#include <charconv>
#include <pugixml.hpp>
#include "XmlSerializer.h"
#include "../Registry/NodeRegistry.h"

namespace FlowgraphEditor::XmlSerializer
{

namespace
{

ImVec2 ParsePos(std::string_view text)
{
    float x = 0.0f, y = 0.0f;
    auto firstComma = text.find(',');
    if (firstComma == std::string_view::npos)
        return { 0.0f, 0.0f };

    auto xs = text.substr(0, firstComma);
    auto rest = text.substr(firstComma + 1);
    auto secondComma = rest.find(',');
    auto ys = secondComma == std::string_view::npos ? rest : rest.substr(0, secondComma);

    std::from_chars(xs.data(), xs.data() + xs.size(), x);
    std::from_chars(ys.data(), ys.data() + ys.size(), y);
    return { x, y };
}

void BuildPinsFromPrototype(Node& node, Flowgraph& graph)
{
    for (const auto& portProto : node.prototype->inputs)
    {
        Pin pin;
        pin.id = graph.AllocPinId();
        pin.name = portProto.name;
        pin.isInput = true;
        pin.prototype = &portProto;
        node.inputs.push_back(std::move(pin));
    }
    for (const auto& portProto : node.prototype->outputs)
    {
        Pin pin;
        pin.id = graph.AllocPinId();
        pin.name = portProto.name;
        pin.isInput = false;
        pin.prototype = &portProto;
        node.outputs.push_back(std::move(pin));
    }
}

void EnsurePinExists(Node& node, Flowgraph& graph,
                     std::string_view portName, bool isInput)
{
    auto& vec = isInput ? node.inputs : node.outputs;
    for (auto& p : vec)
        if (p.name == portName)
            return;

    Pin pin;
    pin.id = graph.AllocPinId();
    pin.name = std::string(portName);
    pin.isInput = isInput;
    vec.push_back(std::move(pin));
}

void ParseInputDefaultsAndEnsurePins(Node& node, Flowgraph& graph,
                                     const pugi::xml_node& nodeEl)
{
    auto inputsEl = nodeEl.child("Inputs");
    for (auto attr : inputsEl.attributes())
    {
        std::string portName = attr.name();
        node.inputDefaults[portName] = attr.value();
        // For unknown-class nodes (no prototype), this synthesizes input pins
        // from the XML attribute set so they show up on the canvas.
        EnsurePinExists(node, graph, portName, true);
    }
}

std::unique_ptr<Flowgraph> ParseFlowGraphElement(
    const pugi::xml_node& fg, const NodeRegistry& registry)
{
    auto graph = std::make_unique<Flowgraph>();
    graph->description = fg.attribute("Description").as_string();
    graph->group = fg.attribute("Group").as_string();
    graph->enabled = fg.attribute("enabled").as_bool(true);
    graph->multiplayer = fg.attribute("MultiPlayer").as_string();
    graph->title = !graph->group.empty() ? graph->group : fg.name();

    // Nodes
    for (auto nodeEl : fg.child("Nodes").children("Node"))
    {
        Node node;
        node.id = nodeEl.attribute("Id").as_llong();
        node.className = nodeEl.attribute("Class").as_string();
        node.pos = ParsePos(nodeEl.attribute("pos").as_string());
        node.entityGuid = nodeEl.attribute("EntityGUID").as_string();
        node.entityGuid64 = nodeEl.attribute("EntityGUID_64").as_string();
        node.targetsGraphEntity = nodeEl.attribute("GraphEntity").as_int(-1) > 0;

        node.prototype = registry.Find(node.className);
        if (node.prototype)
            BuildPinsFromPrototype(node, *graph);

        ParseInputDefaultsAndEnsurePins(node, *graph, nodeEl);

        graph->nodes.push_back(std::move(node));
    }

    // Edges
    for (auto edgeEl : fg.child("Edges").children("Edge"))
    {
        Edge edge;
        edge.id = graph->AllocEdgeId();
        edge.fromNodeId = edgeEl.attribute("nodeOut").as_llong();
        edge.fromPort = edgeEl.attribute("portOut").as_string();
        edge.toNodeId = edgeEl.attribute("nodeIn").as_llong();
        edge.toPort = edgeEl.attribute("portIn").as_string();
        edge.enabled = edgeEl.attribute("enabled").as_bool(true);
        graph->edges.push_back(std::move(edge));
    }

    // Finalization: synthesize any pins that edges reference but the prototype
    // / <Inputs> didn't already create. This matters mostly for output pins on
    // unknown-class nodes (no prototype + Outputs aren't in <Inputs> defaults).
    for (auto& edge : graph->edges)
    {
        if (Node* fromNode = graph->FindNode(edge.fromNodeId))
            EnsurePinExists(*fromNode, *graph, edge.fromPort, false);
        if (Node* toNode = graph->FindNode(edge.toNodeId))
            EnsurePinExists(*toNode, *graph, edge.toPort, true);
    }

    // Graph tokens
    for (auto tokenEl : fg.child("GraphTokens").children("Token"))
    {
        GraphToken token;
        token.name = tokenEl.attribute("Name").as_string();
        token.type = tokenEl.attribute("Type").as_int();
        graph->tokens.push_back(std::move(token));
    }

    return graph;
}

void CollectFlowgraphs(const pugi::xml_node& node,
                       const NodeRegistry& registry,
                       std::vector<std::unique_ptr<Flowgraph>>& out)
{
    std::string_view tag = node.name();
    if (tag == "FlowGraph" || tag == "Graph")
    {
        if (auto graph = ParseFlowGraphElement(node, registry))
            out.push_back(std::move(graph));
        return; // don't descend into a graph's body
    }
    for (auto child : node.children())
        CollectFlowgraphs(child, registry, out);
}

} // anonymous namespace

std::vector<std::unique_ptr<Flowgraph>> LoadFile(
    const std::filesystem::path& path, const NodeRegistry& registry)
{
    std::vector<std::unique_ptr<Flowgraph>> result;

    pugi::xml_document doc;
    auto parseResult = doc.load_file(path.wstring().c_str());
    if (!parseResult)
    {
        CryLog("FlowgraphEditor: failed to load '{}': {}",
               path.u8string(), parseResult.description());
        return result;
    }

    CollectFlowgraphs(doc.root(), registry, result);

    CryLog("FlowgraphEditor: loaded {} graph(s) from '{}'",
           result.size(), path.u8string());
    return result;
}

} // namespace FlowgraphEditor::XmlSerializer
