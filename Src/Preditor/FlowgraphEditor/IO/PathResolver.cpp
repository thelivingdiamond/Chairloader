#include "PathResolver.h"

namespace fs = std::filesystem;

namespace
{

// Pure lexical compare — no filesystem touches. Both inputs come from
// directory iteration or engine APIs and are already absolute and symlink-free
// in this codebase, so weakly_canonical would just be a perf cost.
bool IsSubpath(const fs::path& path, const fs::path& base)
{
    if (base.empty())
        return false;

    fs::path rel = path.lexically_normal().lexically_relative(base.lexically_normal());
    if (rel.empty())
        return false;

    // If `path` is outside `base`, lexically_relative starts the result with "..".
    auto first = rel.begin();
    return first != rel.end() && first->u8string() != "..";
}

} // anonymous namespace

FlowgraphEditor::PathResolver::Source FlowgraphEditor::PathResolver::Classify(const fs::path& absolute)
{
    if (!gPreditor)
        return Source::Unknown;

    fs::path projectDir = gPreditor->pPaths ? gPreditor->pPaths->GetProjectDirPath() : fs::path();
    fs::path preyFiles  = gPreditor->pConfig ? gPreditor->pConfig->GetPreyFiles()    : fs::path();

    if (IsSubpath(absolute, projectDir))
        return Source::Project;
    if (IsSubpath(absolute, preyFiles))
        return Source::Vanilla;
    return Source::Unknown;
}

fs::path FlowgraphEditor::PathResolver::GetSaveTarget(const fs::path& source)
{
    Source kind = Classify(source);

    if (kind == Source::Vanilla && gPreditor && gPreditor->pConfig && gPreditor->pPaths)
    {
        std::error_code ec;
        fs::path rel = fs::relative(source, gPreditor->pConfig->GetPreyFiles(), ec);
        if (!ec && !rel.empty())
            return gPreditor->pPaths->GetProjectDirPath() / "Data" / rel;
    }

    return source;
}

fs::path FlowgraphEditor::PathResolver::ResolvePreferredOpenPath(const fs::path& source)
{
    if (Classify(source) != Source::Vanilla)
        return source;

    fs::path overlay = GetSaveTarget(source);
    std::error_code ec;
    if (overlay != source && fs::exists(overlay, ec))
        return overlay;
    return source;
}

bool FlowgraphEditor::PathResolver::HasProjectOverlay(const fs::path& source)
{
    if (Classify(source) != Source::Vanilla)
        return false;
    fs::path overlay = GetSaveTarget(source);
    std::error_code ec;
    return overlay != source && fs::exists(overlay, ec);
}
