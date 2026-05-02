#pragma once
#include "../Registry/PrototypeNode.h"

namespace FlowgraphEditor
{

//! Runtime pin (instance). References its prototype port; carries an editor ID
//! used by imgui-node-editor.
struct Pin
{
    int64_t id = 0;
    std::string name;
    bool isInput = true;
    const PrototypePort* prototype = nullptr; //!< null if class isn't in the registry
};

//! Runtime node (instance) inside a Flowgraph. The XML <Node> element becomes one of these.
struct Node
{
    int64_t id = 0;                       //!< from XML "Id" attribute, unique within graph
    std::string className;                //!< from "Class", e.g. "entity:SpawnPoint"
    ImVec2 pos{};                         //!< from "pos" (x,y; z dropped)
    const PrototypeNode* prototype = nullptr; //!< null if the class isn't in the registry

    std::vector<Pin> inputs;
    std::vector<Pin> outputs;

    //! Serialized port defaults from <Inputs port="value" .../>; preserved for round-trip.
    std::map<std::string, std::string> inputDefaults;

    //! Optional entity binding (entity:* nodes).
    std::string entityGuid;       //!< from "EntityGUID"
    std::string entityGuid64;     //!< from "EntityGUID_64"
    bool targetsGraphEntity = false; //!< from "GraphEntity" attribute > 0

    Pin* FindInput(std::string_view name);
    Pin* FindOutput(std::string_view name);
    const Pin* FindInput(std::string_view name) const;
    const Pin* FindOutput(std::string_view name) const;
};

//! One link. Stored as (nodeId, portName) so it round-trips XML stably.
struct Edge
{
    int64_t id = 0;
    int64_t fromNodeId = 0;
    std::string fromPort;
    int64_t toNodeId = 0;
    std::string toPort;
    bool enabled = true;
};

//! Graph-scoped variable.
struct GraphToken
{
    std::string name;
    int type = 0;
};

//! One <FlowGraph> (or <Graph>) element loaded from disk.
class Flowgraph
{
public:
    std::string title;          //!< human-readable; derived from group if set, else element tag
    std::string description;    //!< from "Description" attribute
    std::string group;          //!< from "Group" attribute
    bool enabled = true;        //!< from "enabled" attribute
    std::string multiplayer;    //!< raw "MultiPlayer" value (e.g. "ClientServer")

    std::vector<Node> nodes;
    std::vector<Edge> edges;
    std::vector<GraphToken> tokens;

    Node* FindNode(int64_t id);
    const Node* FindNode(int64_t id) const;

    int64_t AllocPinId() { return m_NextPinId++; }
    int64_t AllocEdgeId() { return m_NextEdgeId++; }

    //! Resolve (nodeId, portName) -> editor pin id. Returns 0 if not found.
    int64_t ResolvePinId(int64_t nodeId, std::string_view portName, bool isInput) const;

private:
    // Disjoint from typical XML node IDs so any future "single-ID-space" assumptions
    // in the editor lib don't collide.
    int64_t m_NextPinId  = 1'000'000'000;
    int64_t m_NextEdgeId = 2'000'000'000;
};

} // namespace FlowgraphEditor
