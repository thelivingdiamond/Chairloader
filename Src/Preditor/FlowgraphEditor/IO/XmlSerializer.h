#pragma once
#include <filesystem>
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

class NodeRegistry;

//! Lightweight metadata about a single graph inside an XML file. Used by the
//! browser to enumerate and pick individual graphs without parsing them into
//! the full editor model — mission files routinely hold dozens.
struct GraphSummary
{
    //! 0-based position in the file. Position-based, so it shifts if anyone
    //! reorders the underlying XML — only used as a fallback identifier.
    size_t indexInFile = 0;

    std::string group;            //!< from the graph's "Group" attribute (often empty)
    std::string entityName;       //!< when entity-bound, the parent <Entity Name="..."> value
    std::string entityClass;      //!< when entity-bound, the parent <Entity EntityClass="...">

    //! When entity-bound, the parent <Entity EntityGuid="..."> hex string. This
    //! is the stable identifier — it survives reorders, additions, and external
    //! edits. Empty for graphs that aren't entity-embedded.
    std::string entityGuid;

    size_t nodeCount = 0;
    size_t edgeCount = 0;
};

//! Identifies which family of standalone flowgraph file CreateEmpty produces.
//! Mission/entity-bound graphs aren't a zone — they're authored against
//! existing vanilla entities, not created from scratch.
enum class GraphZone
{
    FlowgraphModule,
    GlobalAction,
    UIAction,
};

namespace XmlSerializer
{

//! Enumerates every <FlowGraph>/<Graph> in `path` without building the full
//! model. Returns an empty vector if the file fails to parse.
std::vector<GraphSummary> EnumerateGraphs(const std::filesystem::path& path);

//! Loads every <FlowGraph> / <Graph> element from an XML file (recurses into
//! containing elements like <Entity>). Resolves Class strings against the
//! registry; nodes whose class isn't registered keep their data and synthesize
//! pins from their <Inputs> defaults and edges that reference them.
//!
//! Returns an empty vector on parse failure (failure is logged via CryLog).
std::vector<std::unique_ptr<Flowgraph>> LoadFile(
    const std::filesystem::path& path,
    const NodeRegistry& registry);

//! Loads exactly one graph from a file, identified by `target`. Prefers
//! matching `target.entityGuid` (stable identifier for mission-bound graphs);
//! falls back to `target.indexInFile` if no entity guid is set or no match is
//! found. Used by the browser to open one graph from a multi-graph file.
//!
//! Returns nullptr if no graph matches or the parse fails.
std::unique_ptr<Flowgraph> LoadGraphMatching(
    const std::filesystem::path& path,
    const GraphSummary& target,
    const NodeRegistry& registry);

//! Writes one Flowgraph as a standalone XML document at `target`. Uses the
//! root element name captured at load time (<FlowGraph> or <Graph>); fresh
//! in-memory graphs default to <FlowGraph>. Root attributes that aren't typed
//! (xmlns declarations, schemaLocation, isModule, moduleName, isObjectList,
//! objectListClass, ...) and per-node attrs/child elements that aren't typed
//! (CommentBox, etc) ride through verbatim from load.
//!
//! Output is deterministic (nodes sorted by id, edges by tuple,
//! input-defaults alphabetical). Creates parent directories as needed.
//!
//! Returns true on success; logs failure via CryLog.
bool Save(const Flowgraph& graph, const std::filesystem::path& target);

//! Writes an empty `<Graph>` skeleton at `target` matching the vanilla format
//! for the given zone. For modules, `moduleName` is the target filename stem.
//! Refuses to overwrite an existing file. Returns true on success.
bool CreateEmpty(GraphZone zone, const std::filesystem::path& target);

//! Surgical save for entity-bound graphs (mission files). Produces a Chairmerger
//! diff XML, NOT a full-file copy:
//!
//!   <Mission xmlns="..." xmlns:ch="...">
//!     <Objects>
//!       <Entity EntityGuid="...">
//!         <FlowGraph ch:action="replace">...</FlowGraph>
//!       </Entity>
//!     </Objects>
//!   </Mission>
//!
//! Chairmerger's MergingPolicy for missions matches Entities by EntityGuid and
//! merges only the elements present in the mod file with vanilla. The
//! `ch:action="replace"` attribute tells it to swap the FlowGraph block
//! wholesale rather than recursively merging child <Node>/<Edge> elements.
//!
//! If `targetPath` already exists (user has modded other entities in the same
//! mission), the existing mod file is loaded and our entity is added or its
//! FlowGraph replaced — preserving every other entity already in the overlay.
//!
//! Fails (returns false) if the file can't be written or `graph.parentEntityGuid`
//! is empty. Logs failures via CryLog.
bool SaveIntoExistingFile(const Flowgraph& graph,
                          const std::filesystem::path& targetPath);

//! True if `modFilePath` exists and contains an <Entity EntityGuid="..."> that
//! matches. Used by the editor on open to decide whether to load the user's
//! mod version of a specific mission entity or fall back to vanilla.
bool ModFileContainsEntity(const std::filesystem::path& modFilePath,
                           const std::string& entityGuid);

//! Surgical removal: finds the <Entity EntityGuid="..."> block in the mod
//! diff and removes it. If the mod file has no remaining <Entity> children
//! afterward, the file itself is deleted (no point keeping an empty diff).
//!
//! Used by "Reset to Vanilla" on entity-bound mission graphs so other modded
//! entities in the same mission survive. Returns true if anything was removed.
bool RemoveEntityFromMissionMod(const std::filesystem::path& modFilePath,
                                const std::string& entityGuid);

} // namespace XmlSerializer
} // namespace FlowgraphEditor
