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
    DrawTabActionsBar();
    ImGui::Separator();

    m_pActiveTab = nullptr;

    if (m_Tabs.empty())
    {
        ImGui::TextDisabled("No graphs open. Paste a path above and click Load,");
        ImGui::TextDisabled("or open a file from the Flowgraph Browser.");
        DrawCloseDirtyModal();
        DrawSaveAsModal();
        DrawResetModal();
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
            {
                // Intercept the X click for dirty tabs — confirm before
                // discarding work. Clean tabs close immediately.
                Flowgraph* g = pTab->GetGraph();
                if (g && g->IsDirty())
                    m_pPendingCloseTab = pTab.get();
                else
                    pTab->MarkForClose();
            }
        }
        ImGui::EndTabBar();
    }

    DrawCloseDirtyModal();
    DrawSaveAsModal();
    DrawResetModal();

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

void FlowgraphEditor::FlowgraphEditorWindow::DrawTabActionsBar()
{
    GraphTab* tab = m_pActiveTab; // last frame's; one-frame latency is fine
    const bool hasTab = (tab != nullptr);

    ImGui::BeginDisabled(!hasTab);
    if (ImGui::Button("Save As..."))
    {
        m_pPendingSaveAsTab = tab;
        if (Flowgraph* g = tab->GetGraph())
            m_SaveAsPath = g->sourcePath.u8string();
        else
            m_SaveAsPath.clear();
    }
    ImGui::SameLine();
    if (ImGui::Button("Reset to Vanilla"))
        m_pPendingResetTab = tab;
    ImGui::EndDisabled();

    if (!m_LoadStatus.empty())
    {
        ImGui::SameLine();
        ImGui::TextDisabled("|  %s", m_LoadStatus.c_str());
    }
}

void FlowgraphEditor::FlowgraphEditorWindow::DrawCloseDirtyModal()
{
    constexpr const char* kPopupId = "Unsaved changes##closeDirty";
    if (m_pPendingCloseTab)
        ImGui::OpenPopup(kPopupId);

    if (ImGui::BeginPopupModal(kPopupId, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        if (m_pPendingCloseTab)
        {
            ImGui::Text("'%s' has unsaved changes.", m_pPendingCloseTab->GetTitle().c_str());
            ImGui::Spacing();

            if (ImGui::Button("Save"))
            {
                if (SaveTab(*m_pPendingCloseTab))
                    m_pPendingCloseTab->MarkForClose();
                m_pPendingCloseTab = nullptr;
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine();
            if (ImGui::Button("Don't Save"))
            {
                m_pPendingCloseTab->MarkForClose();
                m_pPendingCloseTab = nullptr;
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel"))
            {
                m_pPendingCloseTab = nullptr;
                ImGui::CloseCurrentPopup();
            }
        }
        ImGui::EndPopup();
    }
}

void FlowgraphEditor::FlowgraphEditorWindow::DrawSaveAsModal()
{
    constexpr const char* kPopupId = "Save As##saveAs";
    if (m_pPendingSaveAsTab)
        ImGui::OpenPopup(kPopupId);

    if (ImGui::BeginPopupModal(kPopupId, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        if (m_pPendingSaveAsTab)
        {
            Flowgraph* g = m_pPendingSaveAsTab->GetGraph();
            const bool isMissionDiff = g && !g->parentEntityGuid.empty();

            if (isMissionDiff)
            {
                ImGui::TextWrapped("Mission entity graphs are written as merge-XML diffs into the project Data overlay. Save As doesn't apply — use the regular Save.");
                ImGui::Spacing();
                if (ImGui::Button("OK"))
                {
                    m_pPendingSaveAsTab = nullptr;
                    ImGui::CloseCurrentPopup();
                }
            }
            else
            {
                ImGui::Text("Write a copy of '%s' to:",
                            m_pPendingSaveAsTab->GetTitle().c_str());
                ImGui::SetNextItemWidth(560.0f);
                ImGui::InputText("##saveAsPath", &m_SaveAsPath);
                ImGui::Spacing();

                ImGui::BeginDisabled(m_SaveAsPath.empty());
                if (ImGui::Button("Save"))
                {
                    if (SaveTabAs(*m_pPendingSaveAsTab, std::filesystem::path(m_SaveAsPath)))
                    {
                        m_pPendingSaveAsTab = nullptr;
                        ImGui::CloseCurrentPopup();
                    }
                    // On failure, stay open so user sees the status message.
                }
                ImGui::EndDisabled();
                ImGui::SameLine();
                if (ImGui::Button("Cancel"))
                {
                    m_pPendingSaveAsTab = nullptr;
                    ImGui::CloseCurrentPopup();
                }
            }
        }
        ImGui::EndPopup();
    }
}

void FlowgraphEditor::FlowgraphEditorWindow::DrawResetModal()
{
    constexpr const char* kPopupId = "Reset to Vanilla?##reset";
    if (m_pPendingResetTab)
        ImGui::OpenPopup(kPopupId);

    if (ImGui::BeginPopupModal(kPopupId, nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        if (m_pPendingResetTab)
        {
            Flowgraph* g = m_pPendingResetTab->GetGraph();
            ImGui::Text("Discard your mod of '%s' and revert to vanilla?",
                        m_pPendingResetTab->GetTitle().c_str());
            if (g && !g->parentEntityGuid.empty())
                ImGui::TextDisabled("(Only this entity is affected; other modded entities in the same mission stay.)");
            else
                ImGui::TextDisabled("(The whole project overlay file will be deleted.)");

            ImGui::Spacing();
            if (ImGui::Button("Reset"))
            {
                if (ResetTabToVanilla(*m_pPendingResetTab))
                    m_pPendingResetTab->MarkForClose();
                m_pPendingResetTab = nullptr;
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel"))
            {
                m_pPendingResetTab = nullptr;
                ImGui::CloseCurrentPopup();
            }
        }
        ImGui::EndPopup();
    }
}

bool FlowgraphEditor::FlowgraphEditorWindow::SaveTabAs(GraphTab& tab,
                                                       const std::filesystem::path& target)
{
    Flowgraph* graph = tab.GetGraph();
    if (!graph)
        return false;

    if (!XmlSerializer::Save(*graph, target))
    {
        m_LoadStatus = "Save As failed for " + target.u8string();
        return false;
    }

    // Repoint the tab at the new file so subsequent Saves target it.
    graph->sourcePath = target;
    graph->MarkClean();
    m_LoadStatus = "Saved a copy to " + target.u8string();
    return true;
}

bool FlowgraphEditor::FlowgraphEditorWindow::ResetTabToVanilla(GraphTab& tab)
{
    Flowgraph* graph = tab.GetGraph();
    if (!graph || graph->sourcePath.empty())
    {
        m_LoadStatus = "Tab has no source path; nothing to reset.";
        return false;
    }

    // Mission entity diff: surgically remove just our entity (the helper
    // deletes the overlay file if we were the last entry).
    if (!graph->parentEntityGuid.empty())
    {
        std::filesystem::path target = PathResolver::GetSaveTarget(graph->sourcePath);
        if (!XmlSerializer::RemoveEntityFromMissionMod(target, graph->parentEntityGuid))
        {
            m_LoadStatus = "Nothing to reset — no mod for entity '"
                + graph->parentEntityName + "'.";
            return false;
        }
        m_LoadStatus = "Reset entity '" + graph->parentEntityName + "' to vanilla.";
        return true;
    }

    // Standalone overlay (UIAction etc.): delete the project file outright.
    // Refuse for Unknown sources — those aren't in the project tree, so
    // "Reset to Vanilla" has no defined meaning.
    if (PathResolver::Classify(graph->sourcePath) == PathResolver::Source::Unknown)
    {
        m_LoadStatus = "Source isn't in the vanilla or project tree — Reset doesn't apply.";
        return false;
    }

    std::filesystem::path target = PathResolver::GetSaveTarget(graph->sourcePath);
    std::error_code ec;
    if (!std::filesystem::exists(target, ec))
    {
        m_LoadStatus = "Nothing to reset — no mod overlay for this file.";
        return false;
    }
    if (!std::filesystem::remove(target, ec))
    {
        m_LoadStatus = "Failed to delete overlay " + target.u8string();
        return false;
    }
    m_LoadStatus = "Deleted overlay " + target.u8string();
    return true;
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
