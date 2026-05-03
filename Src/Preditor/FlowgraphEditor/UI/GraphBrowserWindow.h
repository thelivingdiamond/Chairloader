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
        //! Vanilla file with a project-side overlay. Refreshed on a slow tick
        //! so post-save mods badge without an explicit Rescan click.
        bool hasOverlay = false;
        //! Mod-only file (no vanilla counterpart).
        bool isProjectOnly = false;
    };

    //! Public so the cpp-side section spec table can index it by value.
    enum class Section
    {
        Modules,
        GlobalActions,
        UIActions,
        Levels,
        Count,
    };

    GraphBrowserWindow();
    ~GraphBrowserWindow();

protected:
    virtual void ShowContents() override;
    virtual void Update(bool isVisible) override;

private:
    void RescanIfNeeded();
    void Rescan();
    void OpenCreateModal(Section section);
    void DrawCreateModal();
    //! Returns empty path if project paths aren't ready yet.
    std::filesystem::path ComposeCreateTarget(Section section, const std::string& name) const;
    //! Refreshes Entry::hasOverlay flags. Cheap (one fs::exists per file).
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

    // m_PendingCreateSection == Count when no modal is up.
    Section m_PendingCreateSection = Section::Count;
    std::string m_CreateNameBuffer;
    std::string m_CreateError;
};

} // namespace FlowgraphEditor
