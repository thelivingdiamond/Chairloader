#include <charconv>
#include <iterator>
#include <optional>
#include <set>
#include <sstream>
#include <pugixml.hpp>
#include "XmlSerializer.h"
#include "../Registry/NodeRegistry.h"

namespace FlowgraphEditor::XmlSerializer
{

namespace
{

//! Names of <Node> attributes that map onto typed Node fields. Anything not in
//! this set is treated as a passthrough extra during load and save.
const std::set<std::string_view, std::less<>> kKnownNodeAttrs = {
    "Id", "Class", "Name", "pos", "EntityGUID", "EntityGUID_64", "GraphEntity"
};

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

//! Parent <Entity ...> context tracked while walking, so mission-embedded
//! graphs carry their binding identity. Shared between enumeration and load.
struct EntityContext
{
    std::string name;
    std::string entityClass;
    std::string entityGuid;
};

std::unique_ptr<Flowgraph> ParseFlowGraphElement(
    const pugi::xml_node& fg,
    const EntityContext* parent,
    const NodeRegistry& registry)
{
    auto graph = std::make_unique<Flowgraph>();
    graph->rootTag = fg.name();
    if (parent)
    {
        graph->parentEntityName  = parent->name;
        graph->parentEntityClass = parent->entityClass;
        graph->parentEntityGuid  = parent->entityGuid;
    }

    // Capture every root attribute in source order, parsing typed fields as we go.
    for (auto attr : fg.attributes())
    {
        std::string name = attr.name();
        std::string value = attr.value();

        if      (name == "Description") graph->description = value;
        else if (name == "Group")       graph->group = value;
        else if (name == "enabled")     graph->enabled = attr.as_bool(true);
        else if (name == "MultiPlayer") graph->multiplayer = value;

        graph->rootAttributes.emplace_back(std::move(name), std::move(value));
    }

    // Tab title preference: explicit Group > parent entity name > root tag.
    if (!graph->group.empty())
        graph->title = graph->group;
    else if (!graph->parentEntityName.empty())
        graph->title = graph->parentEntityName;
    else
        graph->title = fg.name();

    // Nodes
    for (auto nodeEl : fg.child("Nodes").children("Node"))
    {
        Node node;
        node.id = nodeEl.attribute("Id").as_llong();
        node.className = nodeEl.attribute("Class").as_string();
        node.name = nodeEl.attribute("Name").as_string();
        node.pos = ParsePos(nodeEl.attribute("pos").as_string());
        node.entityGuid = nodeEl.attribute("EntityGUID").as_string();
        node.entityGuid64 = nodeEl.attribute("EntityGUID_64").as_string();
        node.targetsGraphEntity = nodeEl.attribute("GraphEntity").as_int(-1) > 0;

        // Anything else on <Node> rides through as a passthrough attribute.
        for (auto attr : nodeEl.attributes())
        {
            std::string_view n = attr.name();
            if (kKnownNodeAttrs.count(n) == 0)
                node.extraAttributes.emplace_back(std::string(n), attr.value());
        }

        // <Inputs> is parsed below; <CommentBox> is parsed into typed fields
        // when the node is a commentbox; every other child rides through verbatim.
        const bool isCommentBox = node.IsCommentBox();
        for (auto child : nodeEl.children())
        {
            std::string_view tag = child.name();
            if (tag == "Inputs")
                continue;
            if (tag == "CommentBox" && isCommentBox)
            {
                node.commentWidth  = child.attribute("Width").as_float();
                node.commentHeight = child.attribute("Height").as_float();
                continue;
            }
            std::ostringstream oss;
            child.print(oss, "", pugi::format_raw);
            node.rawExtraChildren.push_back(oss.str());
        }

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

    graph->RebuildIdCounters();
    return graph;
}

//! Reads the parent-entity attributes off an <Entity ...> XML element. Same
//! attribute set used by both the loader and the lightweight enumerator.
EntityContext ReadEntityContext(const pugi::xml_node& entityEl)
{
    EntityContext ctx;
    ctx.name        = entityEl.attribute("Name").as_string();
    ctx.entityClass = entityEl.attribute("EntityClass").as_string();
    ctx.entityGuid  = entityEl.attribute("EntityGuid").as_string();
    return ctx;
}

void CollectFlowgraphs(const pugi::xml_node& node,
                       const EntityContext* parent,
                       const NodeRegistry& registry,
                       std::vector<std::unique_ptr<Flowgraph>>& out)
{
    std::string_view tag = node.name();
    if (tag == "FlowGraph" || tag == "Graph")
    {
        if (auto graph = ParseFlowGraphElement(node, parent, registry))
            out.push_back(std::move(graph));
        return; // don't descend into a graph's body
    }

    EntityContext ctx;
    const EntityContext* childParent = parent;
    if (tag == "Entity")
    {
        ctx = ReadEntityContext(node);
        childParent = &ctx;
    }

    for (auto child : node.children())
        CollectFlowgraphs(child, childParent, registry, out);
}

void EnumerateRecursive(const pugi::xml_node& node,
                        const EntityContext* parent,
                        std::vector<GraphSummary>& out)
{
    std::string_view tag = node.name();

    if (tag == "FlowGraph" || tag == "Graph")
    {
        GraphSummary s;
        s.indexInFile = out.size();
        s.group = node.attribute("Group").as_string();
        if (parent)
        {
            s.entityName  = parent->name;
            s.entityClass = parent->entityClass;
            s.entityGuid  = parent->entityGuid;
        }

        const auto nodes = node.child("Nodes").children("Node");
        const auto edges = node.child("Edges").children("Edge");
        s.nodeCount = (size_t)std::distance(nodes.begin(), nodes.end());
        s.edgeCount = (size_t)std::distance(edges.begin(), edges.end());

        out.push_back(std::move(s));
        return; // don't descend into a graph's body
    }

    EntityContext ctx;
    const EntityContext* childParent = parent;
    if (tag == "Entity")
    {
        ctx = ReadEntityContext(node);
        childParent = &ctx;
    }

    for (auto child : node.children())
        EnumerateRecursive(child, childParent, out);
}

} // anonymous namespace

std::vector<GraphSummary> EnumerateGraphs(const std::filesystem::path& path)
{
    std::vector<GraphSummary> result;

    pugi::xml_document doc;
    auto parseResult = doc.load_file(path.wstring().c_str());
    if (!parseResult)
    {
        CryLog("FlowgraphEditor: failed to enumerate '{}': {}",
               path.u8string(), parseResult.description());
        return result;
    }

    EnumerateRecursive(doc.root(), nullptr, result);
    return result;
}

std::unique_ptr<Flowgraph> LoadGraphMatching(
    const std::filesystem::path& path, const GraphSummary& target,
    const NodeRegistry& registry)
{
    auto graphs = LoadFile(path, registry);
    if (graphs.empty())
        return nullptr;

    // Prefer matching by parent entity GUID — stable across reorders and
    // external edits, unlike file-relative position.
    if (!target.entityGuid.empty())
    {
        for (auto& g : graphs)
        {
            if (g->parentEntityGuid == target.entityGuid)
                return std::move(g);
        }
        // Guid was supplied but no graph matched — file changed under us. Don't
        // silently pick a different graph; leave the caller to report it.
        CryLog("FlowgraphEditor: graph with entity guid '{}' not found in '{}' "
               "(file may have changed since enumeration)",
               target.entityGuid, path.u8string());
        return nullptr;
    }

    // Fallback for non-entity-bound graphs: positional index.
    if (target.indexInFile < graphs.size())
        return std::move(graphs[target.indexInFile]);
    return nullptr;
}

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

    CollectFlowgraphs(doc.root(), nullptr, registry, result);

    for (auto& graph : result)
    {
        graph->sourcePath = path;
        graph->sourceTotalGraphs = result.size();
    }

    CryLog("FlowgraphEditor: loaded {} graph(s) from '{}'",
           result.size(), path.u8string());
    return result;
}

namespace
{

// Save formatting — 4-space indentation with each attribute on its own line.
// Matches the convention used by the game's mission/UIAction XMLs, so saved
// files diff cleanly against vanilla.
constexpr const char* kSaveIndent = "    ";
constexpr unsigned kSaveFormatFlags =
    pugi::format_indent | pugi::format_indent_attributes;

//! Builds a <FlowGraph>/<Graph> element from `graph` and appends it under
//! `parent`. Returns the new node. Used by both the standalone-file save
//! (parent = document) and the surgical mission save (parent = <Entity>).
pugi::xml_node WriteFlowgraphElement(const Flowgraph& graph, pugi::xml_node parent)
{
    const std::string rootTag = graph.rootTag.empty() ? "FlowGraph" : graph.rootTag;
    auto fg = parent.append_child(rootTag.c_str());

    // Returns the current typed value for a root attribute as a string, or
    // nullopt if the attribute isn't one of our typed fields.
    auto currentTypedRootValue = [&](std::string_view name) -> std::optional<std::string> {
        if (name == "Description") return graph.description;
        if (name == "Group")       return graph.group;
        if (name == "enabled")     return std::string(graph.enabled ? "1" : "0");
        if (name == "MultiPlayer") return graph.multiplayer;
        return std::nullopt;
    };

    // Walk the load-time attribute list in order, substituting current typed
    // values for the well-known names. Anything we don't type (xmlns:*,
    // schemaLocation, isModule, ...) round-trips verbatim.
    std::set<std::string_view, std::less<>> emittedRootAttrs;
    for (const auto& [name, originalValue] : graph.rootAttributes)
    {
        auto typed = currentTypedRootValue(name);
        const std::string& value = typed ? *typed : originalValue;
        fg.append_attribute(name.c_str()) = value.c_str();
        emittedRootAttrs.insert(name);
    }

    // Append typed attrs that weren't in the original — handles fresh
    // in-memory graphs, and typed fields the user added to a loaded graph.
    auto appendTypedRootAttr = [&](const char* name, const std::string& value, bool emitEvenIfEmpty) {
        if (emittedRootAttrs.count(name))
            return;
        if (!emitEvenIfEmpty && value.empty())
            return;
        fg.append_attribute(name) = value.c_str();
    };
    appendTypedRootAttr("Description", graph.description,                    false);
    appendTypedRootAttr("Group",       graph.group,                          false);
    appendTypedRootAttr("enabled",     graph.enabled ? "1" : "0",            true);
    appendTypedRootAttr("MultiPlayer", graph.multiplayer,                    false);

    // Nodes — sorted by id for stable output.
    std::vector<const Node*> nodesSorted;
    nodesSorted.reserve(graph.nodes.size());
    for (const Node& n : graph.nodes)
        nodesSorted.push_back(&n);
    std::sort(nodesSorted.begin(), nodesSorted.end(),
        [](const Node* a, const Node* b) { return a->id < b->id; });

    auto nodesEl = fg.append_child("Nodes");
    for (const Node* node : nodesSorted)
    {
        auto nEl = nodesEl.append_child("Node");
        nEl.append_attribute("Id") = (long long)node->id;
        if (!node->name.empty())
            nEl.append_attribute("Name") = node->name.c_str();
        nEl.append_attribute("Class") = node->className.c_str();

        char posBuf[64];
        std::snprintf(posBuf, sizeof(posBuf), "%g,%g,0", node->pos.x, node->pos.y);
        nEl.append_attribute("pos") = posBuf;

        if (!node->entityGuid.empty())
            nEl.append_attribute("EntityGUID") = node->entityGuid.c_str();
        if (!node->entityGuid64.empty())
            nEl.append_attribute("EntityGUID_64") = node->entityGuid64.c_str();
        if (node->targetsGraphEntity)
            nEl.append_attribute("GraphEntity") = "1";

        // Passthrough — attrs we don't type (commentbox styling, etc).
        for (const auto& [name, value] : node->extraAttributes)
            nEl.append_attribute(name.c_str()) = value.c_str();

        if (!node->inputDefaults.empty())
        {
            auto inputsEl = nEl.append_child("Inputs");
            // std::map iteration is alphabetical — already deterministic.
            for (const auto& [portName, value] : node->inputDefaults)
                inputsEl.append_attribute(portName.c_str()) = value.c_str();
        }

        // Typed commentbox child — emit between <Inputs> and other passthrough
        // children to match the source-file ordering.
        if (node->IsCommentBox())
        {
            auto cbEl = nEl.append_child("CommentBox");
            cbEl.append_attribute("Width")  = node->commentWidth;
            cbEl.append_attribute("Height") = node->commentHeight;
        }

        // Passthrough — child elements we don't type.
        for (const std::string& raw : node->rawExtraChildren)
        {
            pugi::xml_document tmp;
            if (tmp.load_string(raw.c_str()) && tmp.first_child())
                nEl.append_copy(tmp.first_child());
        }
    }

    // Edges — sorted lexicographically for stable output.
    std::vector<const Edge*> edgesSorted;
    edgesSorted.reserve(graph.edges.size());
    for (const Edge& e : graph.edges)
        edgesSorted.push_back(&e);
    std::sort(edgesSorted.begin(), edgesSorted.end(),
        [](const Edge* a, const Edge* b) {
            if (a->fromNodeId != b->fromNodeId) return a->fromNodeId < b->fromNodeId;
            if (a->toNodeId   != b->toNodeId)   return a->toNodeId   < b->toNodeId;
            if (a->fromPort   != b->fromPort)   return a->fromPort   < b->fromPort;
            return a->toPort < b->toPort;
        });

    auto edgesEl = fg.append_child("Edges");
    for (const Edge* edge : edgesSorted)
    {
        auto eEl = edgesEl.append_child("Edge");
        eEl.append_attribute("nodeIn")  = (long long)edge->toNodeId;
        eEl.append_attribute("nodeOut") = (long long)edge->fromNodeId;
        eEl.append_attribute("portIn")  = edge->toPort.c_str();
        eEl.append_attribute("portOut") = edge->fromPort.c_str();
        eEl.append_attribute("enabled") = edge->enabled ? "1" : "0";
    }

    auto tokensEl = fg.append_child("GraphTokens");
    for (const GraphToken& token : graph.tokens)
    {
        auto tEl = tokensEl.append_child("Token");
        tEl.append_attribute("Name") = token.name.c_str();
        tEl.append_attribute("Type") = token.type;
    }

    return fg;
}

//! Recursively searches `from` for an <Entity EntityGuid="..."> element with
//! the given guid. Returns null if not found. Stops at the first match.
pugi::xml_node FindEntityByGuid(pugi::xml_node from, const std::string& guid)
{
    if (std::string_view(from.name()) == "Entity")
    {
        if (from.attribute("EntityGuid").as_string() == guid)
            return from;
    }
    for (auto child : from.children())
    {
        if (auto match = FindEntityByGuid(child, guid))
            return match;
    }
    return {};
}

} // anonymous namespace

bool Save(const Flowgraph& graph, const std::filesystem::path& target)
{
    pugi::xml_document doc;
    WriteFlowgraphElement(graph, doc);

    std::error_code ec;
    if (!target.parent_path().empty())
        std::filesystem::create_directories(target.parent_path(), ec);

    if (!doc.save_file(target.wstring().c_str(), kSaveIndent, kSaveFormatFlags))
    {
        CryLog("FlowgraphEditor: failed to save '{}'", target.u8string());
        return false;
    }

    CryLog("FlowgraphEditor: saved '{}'", target.u8string());
    return true;
}

bool SaveIntoExistingFile(const Flowgraph& graph,
                          const std::filesystem::path& targetPath)
{
    if (graph.parentEntityGuid.empty())
    {
        CryLog("FlowgraphEditor: SaveIntoExistingFile called for non-entity-bound graph");
        return false;
    }

    constexpr const char* kPreyNs = "https://thelivingdiamond.github.io/Chairloader/Xsd/Prey";
    constexpr const char* kChairNs = "https://thelivingdiamond.github.io/Chairloader/Xsd/Chairloader";

    // If the user has already saved mods for OTHER entities in this mission,
    // load that existing diff so we merge into it. Otherwise build a fresh
    // skeleton — we want to ship a Chairmerger diff, not a full-file copy.
    pugi::xml_document doc;
    std::error_code ec;
    const bool overlayExists = std::filesystem::exists(targetPath, ec);

    if (overlayExists)
    {
        if (!doc.load_file(targetPath.wstring().c_str()))
        {
            CryLog("FlowgraphEditor: existing mod file at '{}' could not be parsed; aborting save",
                   targetPath.u8string());
            return false;
        }
    }

    auto mission = doc.child("Mission");
    if (!mission)
    {
        mission = doc.append_child("Mission");
        mission.append_attribute("xmlns")    = kPreyNs;
        mission.append_attribute("xmlns:ch") = kChairNs;
    }

    auto objects = mission.child("Objects");
    if (!objects)
        objects = mission.append_child("Objects");

    // Find an existing <Entity EntityGuid=...> in the overlay (user previously
    // modded this entity), or append a fresh stub.
    pugi::xml_node entity;
    for (auto e : objects.children("Entity"))
    {
        if (e.attribute("EntityGuid").as_string() == graph.parentEntityGuid)
        {
            entity = e;
            break;
        }
    }
    if (!entity)
    {
        entity = objects.append_child("Entity");
        entity.append_attribute("EntityGuid") = graph.parentEntityGuid.c_str();
    }

    // Replace the entity's <FlowGraph> child wholesale. Try both possible
    // names defensively in case of a previous save that chose differently.
    const std::string rootTag = graph.rootTag.empty() ? "FlowGraph" : graph.rootTag;
    if (auto existing = entity.child(rootTag.c_str()))
        entity.remove_child(existing);
    const char* altTag = (rootTag == "Graph") ? "FlowGraph" : "Graph";
    if (auto alt = entity.child(altTag))
        entity.remove_child(alt);

    auto fg = WriteFlowgraphElement(graph, entity);
    // Tell Chairmerger to swap this FlowGraph wholesale rather than try to
    // merge child Nodes/Edges (which it would otherwise attempt under the
    // mission policy's nodeDict rules).
    if (!fg.attribute("ch:action"))
        fg.prepend_attribute("ch:action") = "replace";

    if (!targetPath.parent_path().empty())
        std::filesystem::create_directories(targetPath.parent_path(), ec);

    if (!doc.save_file(targetPath.wstring().c_str(), kSaveIndent, kSaveFormatFlags))
    {
        CryLog("FlowgraphEditor: failed to save mod file '{}'", targetPath.u8string());
        return false;
    }

    CryLog("FlowgraphEditor: saved entity '{}' FlowGraph diff into '{}'",
           graph.parentEntityGuid, targetPath.u8string());
    return true;
}

bool ModFileContainsEntity(const std::filesystem::path& modFilePath,
                           const std::string& entityGuid)
{
    if (entityGuid.empty())
        return false;

    std::error_code ec;
    if (!std::filesystem::exists(modFilePath, ec))
        return false;

    pugi::xml_document doc;
    if (!doc.load_file(modFilePath.wstring().c_str()))
        return false;

    return (bool)FindEntityByGuid(doc.root(), entityGuid);
}

bool RemoveEntityFromMissionMod(const std::filesystem::path& modFilePath,
                                const std::string& entityGuid)
{
    if (entityGuid.empty())
        return false;

    std::error_code ec;
    if (!std::filesystem::exists(modFilePath, ec))
        return false;

    pugi::xml_document doc;
    if (!doc.load_file(modFilePath.wstring().c_str()))
    {
        CryLog("FlowgraphEditor: RemoveEntityFromMissionMod failed to parse '{}'",
               modFilePath.u8string());
        return false;
    }

    pugi::xml_node entity = FindEntityByGuid(doc.root(), entityGuid);
    if (!entity)
        return false;

    pugi::xml_node parent = entity.parent();
    parent.remove_child(entity);

    // If the diff is now empty (no more <Entity> children under <Objects>),
    // there's no point keeping it on disk — delete the file entirely so the
    // browser stops badging it as modded.
    auto objects = doc.child("Mission").child("Objects");
    if (!objects || !objects.first_child())
    {
        std::filesystem::remove(modFilePath, ec);
        CryLog("FlowgraphEditor: removed entity '{}' (last entry; deleted '{}')",
               entityGuid, modFilePath.u8string());
        return true;
    }

    if (!doc.save_file(modFilePath.wstring().c_str(), kSaveIndent, kSaveFormatFlags))
    {
        CryLog("FlowgraphEditor: failed to save mod file after entity removal '{}'",
               modFilePath.u8string());
        return false;
    }

    CryLog("FlowgraphEditor: removed entity '{}' from '{}'",
           entityGuid, modFilePath.u8string());
    return true;
}

} // namespace FlowgraphEditor::XmlSerializer
