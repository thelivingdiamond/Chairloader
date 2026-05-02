#include <algorithm>
#include <imgui_stdlib.h>
#include "GraphBrowserWindow.h"
#include "../FlowgraphEditorWindow.h"
#include "../IO/PathResolver.h"

namespace fs = std::filesystem;

namespace
{

void CollectXmlFiles(const fs::path& dir, std::vector<FlowgraphEditor::GraphBrowserWindow::Entry>& out,
                     const fs::path& root, bool recursive)
{
    std::error_code ec;
    if (!fs::exists(dir, ec))
        return;

    auto add = [&](const fs::path& p) {
        if (p.extension() != ".xml")
            return;
        FlowgraphEditor::GraphBrowserWindow::Entry e;
        e.absolutePath = p;
        e.relativeDisplay = fs::relative(p, root, ec).u8string();
        std::replace(e.relativeDisplay.begin(), e.relativeDisplay.end(), '\\', '/');
        out.push_back(std::move(e));
    };

    if (recursive)
    {
        for (auto& it : fs::recursive_directory_iterator(dir, fs::directory_options::skip_permission_denied, ec))
            if (!ec && it.is_regular_file(ec))
                add(it.path());
    }
    else
    {
        for (auto& it : fs::directory_iterator(dir, ec))
            if (!ec && it.is_regular_file(ec))
                add(it.path());
    }
}

} // anonymous namespace

FlowgraphEditor::GraphBrowserWindow::GraphBrowserWindow()
{
    SetTitle("Flowgraph Browser");
    SetPersistentID("FlowgraphBrowser");
    SetDestroyOnClose(false);
    SetVisible(false);
}

FlowgraphEditor::GraphBrowserWindow::~GraphBrowserWindow()
{
}

void FlowgraphEditor::GraphBrowserWindow::ShowContents()
{
    RescanIfNeeded();

    if (m_RootPath.empty())
    {
        ImGui::TextDisabled("No PreyFiles path configured.");
        return;
    }

    ImGui::TextDisabled("Vanilla: %s", m_RootPath.u8string().c_str());
    if (ImGui::SmallButton("Rescan"))
        Rescan();
    ImGui::SameLine();
    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::InputTextWithHint("##browserFilter", "Filter (substring)", &m_Filter);

    ImGui::Separator();

    // The user's mods, surfaced at the top — easiest path back to anything
    // already touched.
    DrawModdedSection();

    DrawSection(Section::Modules,       "Flowgraph Modules", /*expandableLeaves*/ false);
    DrawSection(Section::GlobalActions, "Global Actions",    /*expandableLeaves*/ false);
    DrawSection(Section::UIActions,     "UI Actions",        /*expandableLeaves*/ false);
    DrawSection(Section::Levels,        "Level Missions",    /*expandableLeaves*/ true);
}

void FlowgraphEditor::GraphBrowserWindow::RescanIfNeeded()
{
    if (m_bScanned)
        return;
    if (!gPreditor || !gPreditor->pConfig)
        return;

    Rescan();
}

void FlowgraphEditor::GraphBrowserWindow::Rescan()
{
    if (!gPreditor || !gPreditor->pConfig)
        return;

    m_RootPath = gPreditor->pConfig->GetPreyFiles();
    for (auto& v : m_Sections)
        v.clear();
    m_SummaryCache.clear();

    if (m_RootPath.empty())
    {
        m_bScanned = true;
        return;
    }

    CollectXmlFiles(m_RootPath / "Libs/FlowgraphModules", m_Sections[(size_t)Section::Modules],       m_RootPath, false);
    CollectXmlFiles(m_RootPath / "Libs/GlobalActions",    m_Sections[(size_t)Section::GlobalActions], m_RootPath, false);
    CollectXmlFiles(m_RootPath / "Libs/UI/UIActions",     m_Sections[(size_t)Section::UIActions],     m_RootPath, false);
    CollectXmlFiles(m_RootPath / "Levels/Campaign",       m_Sections[(size_t)Section::Levels],        m_RootPath, true);

    // Levels: filter to mission_*.xml files only.
    auto& levels = m_Sections[(size_t)Section::Levels];
    levels.erase(
        std::remove_if(levels.begin(), levels.end(),
            [](const Entry& e) {
                auto name = e.absolutePath.filename().u8string();
                return name.find("mission_") != 0;
            }),
        levels.end());

    for (auto& v : m_Sections)
    {
        std::sort(v.begin(), v.end(),
            [](const Entry& a, const Entry& b) { return a.relativeDisplay < b.relativeDisplay; });
    }

    RefreshOverlayFlags();
    m_bScanned = true;
}

void FlowgraphEditor::GraphBrowserWindow::RefreshOverlayFlags()
{
    for (auto& section : m_Sections)
    {
        for (Entry& e : section)
            e.hasOverlay = PathResolver::HasProjectOverlay(e.absolutePath);
    }
    m_LastOverlayRefreshTime = ImGui::GetTime();
}

void FlowgraphEditor::GraphBrowserWindow::Update(bool isVisible)
{
    // Background refresh while the browser is visible — keeps modded badges
    // in sync after the user saves a mod from the editor without making them
    // click Rescan. Cheap: fs::exists per file at low frequency.
    constexpr double kRefreshIntervalSec = 2.0;
    if (isVisible && m_bScanned &&
        ImGui::GetTime() - m_LastOverlayRefreshTime > kRefreshIntervalSec)
    {
        RefreshOverlayFlags();
    }
}

void FlowgraphEditor::GraphBrowserWindow::DrawSection(Section section, const char* label,
                                                       bool expandableLeaves)
{
    const auto& entries = m_Sections[(size_t)section];
    char header[64];
    std::snprintf(header, sizeof(header), "%s (%zu)###section-%s", label, entries.size(), label);

    if (!ImGui::CollapsingHeader(header))
        return;

    for (const Entry& e : entries)
    {
        if (!m_Filter.empty() &&
            e.relativeDisplay.find(m_Filter) == std::string::npos)
        {
            continue;
        }
        DrawFileEntry(e, expandableLeaves);
    }
}

void FlowgraphEditor::GraphBrowserWindow::DrawModdedSection()
{
    // Walk every cached file entry and pick those flagged as having an
    // overlay. The flag is recomputed in Rescan + on a slow timer in Update,
    // so we don't pay fs::exists per row per frame.
    std::vector<const Entry*> modded;
    for (const auto& section : m_Sections)
    {
        for (const Entry& e : section)
        {
            if (e.hasOverlay)
                modded.push_back(&e);
        }
    }

    char header[96];
    std::snprintf(header, sizeof(header),
                  "Modded (%zu)###section-modded", modded.size());

    // Open by default so the user lands on their own work.
    ImGui::SetNextItemOpen(true, ImGuiCond_Once);
    if (!ImGui::CollapsingHeader(header))
        return;

    if (modded.empty())
    {
        ImGui::Indent();
        ImGui::TextDisabled("Nothing modded yet.");
        ImGui::Unindent();
        return;
    }

    for (const Entry* pe : modded)
    {
        if (!m_Filter.empty() &&
            pe->relativeDisplay.find(m_Filter) == std::string::npos)
        {
            continue;
        }
        // Mission files have many graphs; even in the Modded section, give
        // the user a way to drill in instead of dumping all 30+ tabs.
        const bool isLevel = pe->relativeDisplay.find("Levels/") == 0;
        DrawFileEntry(*pe, isLevel);
    }
}

void FlowgraphEditor::GraphBrowserWindow::DrawFileEntry(const Entry& e, bool expandable)
{
    ImGui::PushID(e.absolutePath.u8string().c_str());

    auto drawBadge = [&]() {
        if (!e.hasOverlay)
            return;
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.55f, 0.85f, 0.45f, 1.0f), "[modded]");
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("You've already saved a mod for this file.\n"
                              "Opening it will load your mod, not vanilla.");
    };

    if (!expandable)
    {
        if (ImGui::Selectable(e.relativeDisplay.c_str()))
        {
            if (auto* editor = FlowgraphEditorWindow::Get())
                editor->OpenFile(e.absolutePath.u8string());
        }
        drawBadge();
        ImGui::PopID();
        return;
    }

    const bool open = ImGui::TreeNodeEx(e.relativeDisplay.c_str(),
                                        ImGuiTreeNodeFlags_SpanAvailWidth);
    drawBadge();

    if (open)
    {
        const auto& summaries = GetSummaries(e.absolutePath);
        DrawGraphLeaves(e, summaries);
        ImGui::TreePop();
    }

    ImGui::PopID();
}

void FlowgraphEditor::GraphBrowserWindow::DrawGraphLeaves(
    const Entry& e, const std::vector<GraphSummary>& summaries)
{
    if (summaries.empty())
    {
        ImGui::TextDisabled("(no graphs found)");
        return;
    }

    for (const GraphSummary& s : summaries)
    {
        // Build a one-line descriptor. Entity-bound graphs (mission embeds)
        // show by their parent entity; otherwise fall back to Group, then to
        // a numeric label. The node count helps the user spot the big ones.
        char label[256];
        if (!s.entityName.empty())
            std::snprintf(label, sizeof(label),
                          "%s  [%s]  (%zu nodes)###g%zu",
                          s.entityName.c_str(),
                          s.entityClass.empty() ? "?" : s.entityClass.c_str(),
                          s.nodeCount, s.indexInFile);
        else if (!s.group.empty())
            std::snprintf(label, sizeof(label),
                          "%s  (%zu nodes)###g%zu",
                          s.group.c_str(), s.nodeCount, s.indexInFile);
        else
            std::snprintf(label, sizeof(label),
                          "Graph #%zu  (%zu nodes)###g%zu",
                          s.indexInFile, s.nodeCount, s.indexInFile);

        if (ImGui::Selectable(label))
        {
            if (auto* editor = FlowgraphEditorWindow::Get())
                editor->OpenGraphFromFile(e.absolutePath.u8string(), s);
        }
    }
}

const std::vector<FlowgraphEditor::GraphSummary>&
FlowgraphEditor::GraphBrowserWindow::GetSummaries(const std::filesystem::path& path)
{
    auto it = m_SummaryCache.find(path);
    if (it != m_SummaryCache.end())
        return it->second;

    auto summaries = XmlSerializer::EnumerateGraphs(path);
    auto [ins, _] = m_SummaryCache.emplace(path, std::move(summaries));
    return ins->second;
}
