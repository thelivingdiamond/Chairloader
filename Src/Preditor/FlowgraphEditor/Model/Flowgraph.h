#pragma once
#include <filesystem>
#include "../Commands/CommandHistory.h"
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
    std::string name;                     //!< from "Name" attribute (used by _commentbox etc.)
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

    //! Any <Node> attributes we don't have typed fields for, in source order.
    //! Round-tripped verbatim so format-specific quirks survive an edit cycle.
    std::vector<std::pair<std::string, std::string>> extraAttributes;

    //! Any <Node> child elements other than <Inputs> and (for commentboxes)
    //! <CommentBox>, serialized as XML.
    std::vector<std::string> rawExtraChildren;

    //! Commentbox typed fields. Populated only when IsCommentBox() — parsed
    //! from the <CommentBox Width="..." Height="..."/> child element.
    float commentWidth  = 0.0f;
    float commentHeight = 0.0f;

    //! True for the editor-only "_commentbox" / "_comment" classes — these are
    //! decorative groupings, not real flow nodes, and render as ed::Group rects.
    bool IsCommentBox() const { return className == "_commentbox" || className == "_comment"; }

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

//! Reverse lookup: which (node, port, kind) corresponds to an editor pin id.
struct PinLocation
{
    int64_t nodeId = 0;
    std::string portName;
    bool isInput = false;

    bool IsValid() const { return nodeId != 0; }
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
    Flowgraph() = default;

    Flowgraph(const Flowgraph&) = delete;
    Flowgraph& operator=(const Flowgraph&) = delete;
    Flowgraph(Flowgraph&&) = delete;
    Flowgraph& operator=(Flowgraph&&) = delete;

    std::string title;          //!< human-readable; group > parent entity name > root tag
    std::string description;    //!< from "Description" attribute
    std::string group;          //!< from "Group" attribute
    bool enabled = true;        //!< from "enabled" attribute
    std::string multiplayer;    //!< raw "MultiPlayer" value (e.g. "ClientServer")

    //! Source XML root element name. UIActions and FlowGraphObjectLists use
    //! <Graph>; entity-bound and most standalone files use <FlowGraph>.
    //! Captured at load time so save reproduces the same root tag.
    std::string rootTag = "FlowGraph";

    //! Every attribute that was on the root element at load time, in source
    //! order. On save we walk this list and emit each attribute, substituting
    //! the current typed value (description/group/enabled/multiplayer) where
    //! applicable; everything else (xmlns:*, schemaLocation, isModule,
    //! moduleName, isObjectList, objectListClass, ...) round-trips verbatim.
    //! Empty for fresh in-memory graphs — those use canonical attribute order.
    std::vector<std::pair<std::string, std::string>> rootAttributes;

    //! Where this graph was loaded from. Empty for fresh in-memory graphs.
    std::filesystem::path sourcePath;
    //! How many <FlowGraph> elements were in the source file at load time.
    size_t sourceTotalGraphs = 1;

    //! When this graph is embedded inside an <Entity> (mission files), the
    //! parent's metadata. EntityGuid is the stable identifier — it survives
    //! reorders and external edits, unlike file-relative position.
    std::string parentEntityName;
    std::string parentEntityClass;
    std::string parentEntityGuid;

    std::vector<Node> nodes;
    std::vector<Edge> edges;
    std::vector<GraphToken> tokens;

    Node* FindNode(int64_t id);
    const Node* FindNode(int64_t id) const;

    Edge* FindEdge(int64_t id);
    const Edge* FindEdge(int64_t id) const;

    int64_t AllocNodeId() { return m_NextNodeId++; }
    int64_t AllocPinId()  { return m_NextPinId++; }
    int64_t AllocEdgeId() { return m_NextEdgeId++; }

    //! Resets the id counters from the current contents — used after XML load
    //! to make sure newly-allocated ids never collide with parsed ones.
    void RebuildIdCounters();

    //! Resolve (nodeId, portName) -> editor pin id. Returns 0 if not found.
    int64_t ResolvePinId(int64_t nodeId, std::string_view portName, bool isInput) const;

    //! Reverse of the above: editor pin id -> (nodeId, portName, isInput).
    PinLocation FindPinLocation(int64_t pinId) const;

    // -- Mutation API. Every mutation MUST go through Execute so it's reversible.

    void Execute(std::unique_ptr<ICommand> cmd) { m_History.Execute(std::move(cmd)); }
    void Undo() { m_History.Undo(); }
    void Redo() { m_History.Redo(); }

    bool CanUndo() const { return m_History.CanUndo(); }
    bool CanRedo() const { return m_History.CanRedo(); }
    bool IsDirty() const { return m_History.IsDirty(); }
    void MarkClean() { m_History.MarkClean(); }

    const CommandHistory& GetHistory() const { return m_History; }

private:
    // Disjoint ranges so allocated ids don't collide across categories or with
    // typical XML node ids (which are small ints).
    int64_t m_NextNodeId =             1;
    int64_t m_NextPinId  = 1'000'000'000;
    int64_t m_NextEdgeId = 2'000'000'000;

    CommandHistory m_History{*this};
};

} // namespace FlowgraphEditor
