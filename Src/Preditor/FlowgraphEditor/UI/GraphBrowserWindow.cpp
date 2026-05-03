#include <algorithm>
#include <cctype>
#include <optional>
#include <unordered_set>
#include <imgui_stdlib.h>
#include "GraphBrowserWindow.h"
#include "../FlowgraphEditorWindow.h"
#include "../IO/PathResolver.h"
#include "../IO/XmlSerializer.h"

namespace fs = std::filesystem;

namespace
{

using Entry = FlowgraphEditor::GraphBrowserWindow::Entry;

//! Indexed by Section. nullopt zone = section is read-only (no "+ New" button).
struct SectionSpec
{
    const char* relPath;
    bool recursive;
    std::optional<FlowgraphEditor::GraphZone> zone;
};

constexpr SectionSpec kSectionSpecs[(size_t)FlowgraphEditor::GraphBrowserWindow::Section::Count] = {
    { "Libs/FlowgraphModules", false, FlowgraphEditor::GraphZone::FlowgraphModule },
    { "Libs/GlobalActions",    false, FlowgraphEditor::GraphZone::GlobalAction },
    { "Libs/UI/UIActions",     false, FlowgraphEditor::GraphZone::UIAction },
    { "Levels/Campaign",       true,  std::nullopt },
};

void CollectXmlFiles(const fs::path& dir, std::vector<Entry>& out,
                     const fs::path& root, bool recursive, bool isProjectOnly)
{
    std::error_code ec;
    if (!fs::exists(dir, ec))
        return;

    auto add = [&](const fs::path& p) {
        if (p.extension() != ".xml")
            return;
        Entry e;
        e.absolutePath = p;
        e.relativeDisplay = fs::relative(p, root, ec).u8string();
        std::replace(e.relativeDisplay.begin(), e.relativeDisplay.end(), '\\', '/');
        e.isProjectOnly = isProjectOnly;
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

//! Returns empty on valid input, else a user-facing error string.
std::string ValidateCreateName(const std::string& name)
{
    if (name.empty())
        return "Name is required.";

    auto isValidChar = [](char c) {
        return std::isalnum(static_cast<unsigned char>(c)) || c == '_' || c == '-';
    };
    if (!std::isalpha(static_cast<unsigned char>(name.front())) && name.front() != '_')
        return "Name must start with a letter or underscore.";
    for (char c : name)
        if (!isValidChar(c))
            return "Name may only contain letters, digits, underscore, or dash.";
    return {};
}

const char* SectionLabel(FlowgraphEditor::GraphBrowserWindow::Section s)
{
    using Section = FlowgraphEditor::GraphBrowserWindow::Section;
    switch (s)
    {
    case Section::Modules:       return "Flowgraph Module";
    case Section::GlobalActions: return "Global Action";
    case Section::UIActions:     return "UI Action";
    case Section::Levels:        return "Level Mission";
    case Section::Count:         break;
    }
    return "";
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

    DrawCreateModal();
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

    fs::path projectDataRoot;
    if (gPreditor->pPaths)
        projectDataRoot = gPreditor->pPaths->GetProjectDirPath() / "Data";

    for (size_t i = 0; i < (size_t)Section::Count; ++i)
    {
        const SectionSpec& spec = kSectionSpecs[i];
        auto& entries = m_Sections[i];

        CollectXmlFiles(m_RootPath / spec.relPath, entries, m_RootPath, spec.recursive, false);

        // Append mod-only files from the project overlay. Both walks key on
        // the same zone-relative display, so dedupe is straightforward and
        // vanilla wins on collision.
        if (!projectDataRoot.empty())
        {
            std::vector<Entry> overlayEntries;
            CollectXmlFiles(projectDataRoot / spec.relPath, overlayEntries, projectDataRoot, spec.recursive, true);

            std::unordered_set<std::string> existing;
            existing.reserve(entries.size());
            for (const Entry& e : entries)
                existing.insert(e.relativeDisplay);

            for (Entry& e : overlayEntries)
                if (existing.insert(e.relativeDisplay).second)
                    entries.push_back(std::move(e));
        }
    }

    // Levels: keep only mission_*.xml — other XMLs in Levels/ aren't graphs.
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

    // AllowItemOverlap lets the SameLine'd button win the hit test against
    // the header's full-row Selectable.
    const SectionSpec& spec = kSectionSpecs[(size_t)section];
    const ImGuiTreeNodeFlags headerFlags =
        spec.zone ? ImGuiTreeNodeFlags_AllowItemOverlap : 0;
    const bool open = ImGui::CollapsingHeader(header, headerFlags);

    if (spec.zone)
    {
        ImGui::SameLine();
        ImGui::PushID((int)section);
        if (ImGui::SmallButton("+ New"))
            OpenCreateModal(section);
        ImGui::PopID();
    }

    if (!open)
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
    // Picks vanilla-with-overlay AND mod-only files. Both flags are computed
    // at scan time, so this walk is cheap.
    std::vector<const Entry*> modded;
    for (const auto& section : m_Sections)
    {
        for (const Entry& e : section)
        {
            if (e.hasOverlay || e.isProjectOnly)
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
        if (e.isProjectOnly)
        {
            ImGui::SameLine();
            ImGui::TextColored(ImVec4(0.45f, 0.75f, 0.95f, 1.0f), "[new]");
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("Mod-only file — has no vanilla counterpart.\n"
                                  "Lives entirely in the project overlay.");
            return;
        }
        if (e.hasOverlay)
        {
            ImGui::SameLine();
            ImGui::TextColored(ImVec4(0.55f, 0.85f, 0.45f, 1.0f), "[modded]");
            if (ImGui::IsItemHovered())
                ImGui::SetTooltip("You've already saved a mod for this file.\n"
                                  "Opening it will load your mod, not vanilla.");
        }
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

void FlowgraphEditor::GraphBrowserWindow::OpenCreateModal(Section section)
{
    m_PendingCreateSection = section;
    m_CreateNameBuffer.clear();
    m_CreateError.clear();
}

fs::path FlowgraphEditor::GraphBrowserWindow::ComposeCreateTarget(Section section,
                                                                  const std::string& name) const
{
    if (!gPreditor || !gPreditor->pPaths)
        return {};

    const SectionSpec& spec = kSectionSpecs[(size_t)section];
    fs::path projectDataRoot = gPreditor->pPaths->GetProjectDirPath() / "Data";
    return projectDataRoot / spec.relPath / (name + ".xml");
}

void FlowgraphEditor::GraphBrowserWindow::DrawCreateModal()
{
    constexpr const char* kPopupId = "Create Flowgraph##fgCreate";
    if (m_PendingCreateSection != Section::Count)
        ImGui::OpenPopup(kPopupId);

    if (!ImGui::BeginPopupModal(kPopupId, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
        return;

    auto closeAndReset = [&]() {
        m_PendingCreateSection = Section::Count;
        m_CreateNameBuffer.clear();
        m_CreateError.clear();
        ImGui::CloseCurrentPopup();
    };

    if (m_PendingCreateSection == Section::Count)
    {
        ImGui::EndPopup();
        return;
    }

    const Section section = m_PendingCreateSection;
    const SectionSpec& spec = kSectionSpecs[(size_t)section];

    ImGui::Text("New %s", SectionLabel(section));
    ImGui::TextDisabled("Saved under: %s/%s/<name>.xml",
                        gPreditor && gPreditor->pPaths
                            ? gPreditor->pPaths->GetProjectDirPath().u8string().c_str()
                            : "<project>/Data",
                        spec.relPath);
    ImGui::Spacing();

    ImGui::SetNextItemWidth(360.0f);
    if (ImGui::IsWindowAppearing())
        ImGui::SetKeyboardFocusHere();
    const bool enterPressed = ImGui::InputTextWithHint(
        "##createName", "name (no extension)", &m_CreateNameBuffer,
        ImGuiInputTextFlags_EnterReturnsTrue);
    // Clear a stale create-failure message as soon as the user tweaks the name.
    if (ImGui::IsItemEdited())
        m_CreateError.clear();

    std::string err = ValidateCreateName(m_CreateNameBuffer);
    fs::path target;
    if (err.empty())
    {
        target = ComposeCreateTarget(section, m_CreateNameBuffer);
        if (target.empty())
            err = "Project paths aren't ready yet.";
        else
        {
            std::error_code ec;
            if (fs::exists(target, ec))
                err = "A file with that name already exists in the project overlay.";
            else if (fs::exists(m_RootPath / spec.relPath / (m_CreateNameBuffer + ".xml"), ec))
                err = "That name collides with a vanilla file. Open the vanilla file and edit it instead.";
        }
    }

    if (!m_CreateError.empty())
        ImGui::TextColored(ImVec4(0.95f, 0.45f, 0.45f, 1.0f), "%s", m_CreateError.c_str());
    else if (!err.empty() && !m_CreateNameBuffer.empty())
        ImGui::TextDisabled("%s", err.c_str());

    ImGui::Spacing();

    const bool canCreate = err.empty();
    ImGui::BeginDisabled(!canCreate);
    const bool clicked = ImGui::Button("Create");
    ImGui::EndDisabled();
    if (canCreate && (clicked || enterPressed))
    {
        if (!XmlSerializer::CreateEmpty(*spec.zone, target))
        {
            m_CreateError = "Failed to create file. See log for details.";
        }
        else
        {
            const std::string created = target.u8string();
            closeAndReset();
            Rescan();
            if (auto* editor = FlowgraphEditorWindow::Get())
                editor->OpenFile(created);
        }
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel"))
        closeAndReset();
    ImGui::EndPopup();
}
