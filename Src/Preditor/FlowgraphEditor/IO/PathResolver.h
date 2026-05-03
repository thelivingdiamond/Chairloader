#pragma once
#include <filesystem>

namespace FlowgraphEditor::PathResolver
{

enum class Source
{
    Vanilla,    //!< under gPreditor->pConfig->GetPreyFiles()
    Project,    //!< under gPreditor->pPaths->GetProjectDirPath()
    Unknown,    //!< anywhere else (other mod, absolute path, etc.)
};

//! Determines whether `absolute` lives inside the vanilla files dir or the
//! current project dir.
Source Classify(const std::filesystem::path& absolute);

//! Returns the path that a save should target for a graph loaded from `source`.
//! - Vanilla source → projectDir/<relative-to-PreyFiles>
//! - Project source → source itself
//! - Unknown source → source itself (caller beware)
std::filesystem::path GetSaveTarget(const std::filesystem::path& source);

//! When the user asks to open a vanilla file that they've already modded,
//! we should open their mod instead — otherwise the next save silently
//! clobbers their previous edits with the freshly-loaded vanilla state.
//!
//! Returns the existing project overlay if `source` is vanilla AND its
//! project-side counterpart exists on disk; otherwise returns `source`
//! unchanged.
std::filesystem::path ResolvePreferredOpenPath(const std::filesystem::path& source);

//! Quick "has the user already modded this vanilla file?" check.
//! False for non-vanilla sources.
bool HasProjectOverlay(const std::filesystem::path& source);

} // namespace FlowgraphEditor::PathResolver
