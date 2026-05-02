#pragma once
#include <filesystem>
#include <map>
#include <WindowManager/ManagedWindow.h>
#include "../IO/XmlSerializer.h" // GraphSummary

namespace FlowgraphEditor
{

//! File tree for the project's known flowgraph-bearing XML locations.
//! Click-to-open routes through FlowgraphEditorWindow::OpenFile.
class GraphBrowserWindow : public ManagedWindow
{
public:
    struct Entry
    {
        std::filesystem::path absolutePath;
        std::string relativeDisplay;
        //! Cached "is there a project-side overlay for this file?" flag.
        //! Refreshed on Rescan and at a slow tick so post-save mods show up
        //! without paying for fs::exists per row per frame.
        bool hasOverlay = false;
    };

    GraphBrowserWindow();
    ~GraphBrowserWindow();

protected:
    virtual void ShowContents() override;
    virtual void Update(bool isVisible) override;

private:
    enum class Section
    {
        Modules,
        GlobalActions,
        UIActions,
        Levels,
        Count,
    };

    void RescanIfNeeded();
    void Rescan();
    //! Recomputes Entry::hasOverlay across every cached entry. Cheap (one
    //! fs::exists per file); called from Rescan and on a low-frequency tick.
    void RefreshOverlayFlags();
    void DrawModdedSection();
    void DrawSection(Section section, const char* label, bool expandableLeaves);
    //! Renders a file as either a click-to-open-all leaf, or a tree node
    //! whose children are individual graphs (lazily enumerated).
    void DrawFileEntry(const Entry& e, bool expandable);
    //! Renders the per-graph leaves under an expanded file entry.
    void DrawGraphLeaves(const Entry& e, const std::vector<GraphSummary>& summaries);
    //! Returns cached summaries for `path`, populating the cache on first call.
    const std::vector<GraphSummary>& GetSummaries(const std::filesystem::path& path);

    std::filesystem::path m_RootPath;
    std::array<std::vector<Entry>, (size_t)Section::Count> m_Sections;
    std::string m_Filter;
    bool m_bScanned = false;

    //! Per-file graph metadata cache. Filled lazily when a file's tree node is
    //! expanded; cleared on Rescan. Keyed by absolute path.
    std::map<std::filesystem::path, std::vector<GraphSummary>> m_SummaryCache;

    //! ImGui::GetTime() value of the last RefreshOverlayFlags pass. Used to
    //! throttle the background refresh.
    double m_LastOverlayRefreshTime = 0.0;
};

} // namespace FlowgraphEditor
