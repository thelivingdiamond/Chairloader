#include <algorithm>
#include <imgui_stdlib.h>
#include "FlowgraphEditorWindow.h"
#include "GraphTab.h"
#include "IO/PathResolver.h"
#include "IO/XmlSerializer.h"
#include "Registry/NodeRegistry.h"

FlowgraphEditor::FlowgraphEditorWindow* FlowgraphEditor::FlowgraphEditorWindow::s_pInstance = nullptr;

FlowgraphEditor::FlowgraphEditorWindow::FlowgraphEditorWindow()
{
    SetTitle("Flowgraph Editor");
    SetPersistentID("FlowgraphEditor");
    SetDestroyOnClose(false);
    SetVisible(false);

    s_pInstance = this;
}

FlowgraphEditor::FlowgraphEditorWindow::~FlowgraphEditorWindow()
{
    if (s_pInstance == this)
        s_pInstance = nullptr;
}

void FlowgraphEditor::FlowgraphEditorWindow::Update(bool /*isVisible*/)
{
    // Hydrate the registry once the flow system comes online (idempotent).
    NodeRegistry::Get().EnsureLoaded();
}

void FlowgraphEditor::FlowgraphEditorWindow::ShowContents()
{
    DrawFileLoader();
    ImGui::Separator();

    m_pActiveTab = nullptr;

    if (m_Tabs.empty())
    {
        ImGui::TextDisabled("No graphs open. Paste a path above and click Load,");
        ImGui::TextDisabled("or open a file from the Flowgraph Browser.");
        return;
    }

    if (ImGui::BeginTabBar("##FlowgraphTabs",
            ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_AutoSelectNewTabs))
    {
        for (auto& pTab : m_Tabs)
        {
            // Insert a dirty marker before the ID separator: "title*###id".
            std::string label = pTab->GetImGuiId();
            if (Flowgraph* g = pTab->GetGraph(); g && g->IsDirty())
            {
                auto sep = label.find("###");
                if (sep != std::string::npos)
                    label.insert(sep, "*");
                else
                    label += "*";
            }

            bool open = true;
            if (ImGui::BeginTabItem(label.c_str(), &open))
            {
                m_pActiveTab = pTab.get();
                pTab->ShowContents();
                ImGui::EndTabItem();
            }
            if (!open)
                pTab->MarkForClose();
        }
        ImGui::EndTabBar();
    }

    m_Tabs.erase(
        std::remove_if(m_Tabs.begin(), m_Tabs.end(),
            [](const std::unique_ptr<GraphTab>& t) { return t->IsClosing(); }),
        m_Tabs.end());
}

void FlowgraphEditor::FlowgraphEditorWindow::DrawFileLoader()
{
    ImGui::SetNextItemWidth(-100.0f);
    ImGui::InputTextWithHint("##loadPath", "Path to a .xml file containing flowgraphs",
                             &m_LoadPath);
    ImGui::SameLine();

    bool canLoad = !m_LoadPath.empty() && NodeRegistry::Get().IsLoaded();
    ImGui::BeginDisabled(!canLoad);
    if (ImGui::Button("Load", ImVec2(-FLT_MIN, 0)))
        LoadGraphsFromFile(m_LoadPath);
    ImGui::EndDisabled();

    if (!m_LoadStatus.empty())
        ImGui::TextDisabled("%s", m_LoadStatus.c_str());
}

void FlowgraphEditor::FlowgraphEditorWindow::OpenFile(const std::string& path)
{
    LoadGraphsFromFile(path);
    SetVisible(true);
}

void FlowgraphEditor::FlowgraphEditorWindow::OpenGraphFromFile(const std::string& path,
                                                               const GraphSummary& target)
{
    auto& registry = NodeRegistry::Get();

    // Per-entity overlay redirect: a Chairmerger mod diff only contains the
    // entities the user has touched. Whole-file ResolvePreferredOpenPath would
    // lose visibility into untouched entities, so for entity-bound graphs we
    // redirect only when the overlay specifically contains THIS entity. For
    // non-entity-bound (rare; standalone single-graph files), a whole-file
    // overlay IS the user's mod, so the simpler redirect applies.
    std::filesystem::path requested(path);
    std::filesystem::path actual = requested;
    if (!target.entityGuid.empty())
    {
        std::filesystem::path overlay = PathResolver::GetSaveTarget(requested);
        if (overlay != requested &&
            XmlSerializer::ModFileContainsEntity(overlay, target.entityGuid))
        {
            actual = overlay;
        }
    }
    else
    {
        actual = PathResolver::ResolvePreferredOpenPath(requested);
    }
    const bool redirected = (actual != requested);

    auto graph = XmlSerializer::LoadGraphMatching(actual, target, registry);
    if (!graph)
    {
        m_LoadStatus = !target.entityGuid.empty()
            ? "Couldn't find that graph — the file may have changed. Click Rescan and try again."
            : "Failed to load that graph (index out of range or parse error). See log.";
        return;
    }

    std::string filename = actual.filename().u8string();
    std::string title = graph->title.empty() ? filename
                                             : (filename + ": " + graph->title);
    m_Tabs.emplace_back(std::make_unique<GraphTab>(std::move(graph), std::move(title)));

    // Status label: entity name if entity-bound, else group, else file index.
    std::string displayName;
    if (!target.entityName.empty())
        displayName = target.entityName;
    else if (!target.group.empty())
        displayName = target.group;
    else
        displayName = "graph #" + std::to_string(target.indexInFile);

    m_LoadStatus = redirected
        ? "Opened your existing mod of " + filename + " (" + displayName + ")."
        : "Loaded " + displayName + " from " + filename;

    SetVisible(true);
}

void FlowgraphEditor::FlowgraphEditorWindow::LoadGraphsFromFile(const std::string& path)
{
    auto& registry = NodeRegistry::Get();

    // Redirect vanilla→overlay so opening Ark_HUD.xml after modding it picks
    // up your work-in-progress instead of the pristine vanilla source.
    std::filesystem::path requested(path);
    std::filesystem::path actual = PathResolver::ResolvePreferredOpenPath(requested);
    const bool redirected = (actual != requested);

    auto graphs = XmlSerializer::LoadFile(actual, registry);

    if (graphs.empty())
    {
        m_LoadStatus = "No graphs found (or file failed to parse). See log for details.";
        return;
    }

    std::string filename = actual.filename().u8string();
    const size_t loaded = graphs.size();

    for (auto& graph : graphs)
    {
        std::string title = graph->title.empty() ? filename
                                                 : (filename + ": " + graph->title);
        m_Tabs.emplace_back(std::make_unique<GraphTab>(std::move(graph), std::move(title)));
    }

    const std::string countStr = std::to_string(loaded) + " graph(s)";
    m_LoadStatus = redirected
        ? "Opened your existing mod of " + filename + " (" + countStr + ")."
        : "Loaded " + countStr + " from " + filename;
}

void FlowgraphEditor::FlowgraphEditorWindow::SaveActiveTab()
{
    if (m_pActiveTab)
        SaveTab(*m_pActiveTab);
}

void FlowgraphEditor::FlowgraphEditorWindow::SaveAll()
{
    size_t saved = 0;
    size_t skipped = 0;
    for (auto& tab : m_Tabs)
    {
        Flowgraph* g = tab->GetGraph();
        if (!g || !g->IsDirty())
            continue;
        if (SaveTab(*tab)) ++saved; else ++skipped;
    }

    m_LoadStatus = "Save All: " + std::to_string(saved) + " saved, "
                 + std::to_string(skipped) + " skipped";
}

bool FlowgraphEditor::FlowgraphEditorWindow::SaveTab(GraphTab& tab)
{
    Flowgraph* graph = tab.GetGraph();
    if (!graph)
        return false;

    if (graph->sourcePath.empty())
    {
        m_LoadStatus = "Tab has no source path; Save As is not yet supported.";
        return false;
    }

    std::filesystem::path target = PathResolver::GetSaveTarget(graph->sourcePath);

    // Entity-bound graphs (mission embeds) ship as Chairmerger diff files
    // keyed by EntityGuid — NOT full-file copies. SaveIntoExistingFile
    // builds/merges a minimal <Mission><Objects><Entity><FlowGraph
    // ch:action="replace">…</FlowGraph></Entity></Objects></Mission> diff,
    // adding our entity to any existing mod file in place.
    if (!graph->parentEntityGuid.empty())
    {
        if (!XmlSerializer::SaveIntoExistingFile(*graph, target))
        {
            m_LoadStatus = "Failed to save mod diff into " + target.u8string()
                + " (see log).";
            return false;
        }

        graph->MarkClean();
        // After a successful save, the source IS now the overlay — future
        // edits load from the overlay and surgically replace within it.
        graph->sourcePath = target;
        m_LoadStatus = "Saved entity '" + graph->parentEntityName + "' diff into "
                     + target.u8string();
        return true;
    }

    // Non-entity-bound multi-graph files (rare; not missions) have no stable
    // identifier, so we still refuse them.
    if (graph->sourceTotalGraphs > 1)
    {
        m_LoadStatus = "Non-entity-bound multi-graph files aren't yet saveable.";
        return false;
    }

    if (!XmlSerializer::Save(*graph, target))
    {
        m_LoadStatus = "Failed to save " + target.u8string();
        return false;
    }

    graph->MarkClean();
    m_LoadStatus = "Saved " + target.u8string();
    return true;
}
