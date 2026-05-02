#pragma once
#include <filesystem>
#include "../Model/Flowgraph.h"

namespace FlowgraphEditor
{

class NodeRegistry;

namespace XmlSerializer
{

//! Loads every <FlowGraph> / <Graph> element from an XML file (recurses into
//! containing elements like <Entity>). Resolves Class strings against the
//! registry; nodes whose class isn't registered keep their data and synthesize
//! pins from their <Inputs> defaults and edges that reference them.
//!
//! Returns an empty vector on parse failure (failure is logged via CryLog).
std::vector<std::unique_ptr<Flowgraph>> LoadFile(
    const std::filesystem::path& path,
    const NodeRegistry& registry);

} // namespace XmlSerializer
} // namespace FlowgraphEditor
