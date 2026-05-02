#include <algorithm>
#include <cstdio>
#include <imgui_stdlib.h>
#include "FlowgraphEditorWindow.h"
#include "GraphTab.h"
#include "IO/XmlSerializer.h"
#include "Registry/NodeRegistry.h"

FlowgraphEditor::FlowgraphEditorWindow::FlowgraphEditorWindow()
{
    SetTitle("Flowgraph Editor");
    SetPersistentID("FlowgraphEditor");
    SetDestroyOnClose(false);
    SetVisible(false);
}

FlowgraphEditor::FlowgraphEditorWindow::~FlowgraphEditorWindow()
{
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

    if (m_Tabs.empty())
    {
        ImGui::TextDisabled("No graphs open. Paste a path above and click Load.");
        ImGui::Separator();
        DrawPrototypeBrowser();
        return;
    }

    if (ImGui::BeginTabBar("##FlowgraphTabs",
            ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_AutoSelectNewTabs))
    {
        for (auto& pTab : m_Tabs)
        {
            bool open = true;
            if (ImGui::BeginTabItem(pTab->GetImGuiId().c_str(), &open))
            {
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

void FlowgraphEditor::FlowgraphEditorWindow::LoadGraphsFromFile(const std::string& path)
{
    auto& registry = NodeRegistry::Get();
    auto graphs = XmlSerializer::LoadFile(path, registry);

    if (graphs.empty())
    {
        m_LoadStatus = "No graphs found (or file failed to parse). See log for details.";
        return;
    }

    std::filesystem::path fsPath(path);
    std::string filename = fsPath.filename().u8string();

    for (auto& graph : graphs)
    {
        std::string title = graph->title.empty() ? filename
                                                 : (filename + ": " + graph->title);
        m_Tabs.emplace_back(std::make_unique<GraphTab>(std::move(graph), std::move(title)));
    }

    char buf[160];
    std::snprintf(buf, sizeof(buf), "Loaded %zu graph(s) from %s",
                  graphs.size(), filename.c_str());
    m_LoadStatus = buf;
}

void FlowgraphEditor::FlowgraphEditorWindow::DrawPrototypeBrowser()
{
    NodeRegistry& registry = NodeRegistry::Get();

    if (!registry.IsLoaded())
    {
        ImGui::TextDisabled("Prototypes: waiting for engine flow system...");
        return;
    }

    ImGui::Text("Prototypes: %zu loaded from engine", registry.Size());

    if (!ImGui::CollapsingHeader("Browse by category"))
        return;

    ImGui::InputTextWithHint("##protoFilter", "Filter (substring of class name)",
                             &m_PrototypeFilter);

    for (const auto& [key, protos] : registry.Categories())
    {
        char header[160];
        std::snprintf(header, sizeof(header), "%s (%zu)###cat-%s",
                      FormatCategoryDisplay(key).c_str(), protos.size(),
                      key.empty() ? "_misc" : key.c_str());

        if (!ImGui::TreeNode(header))
            continue;

        for (const PrototypeNode* proto : protos)
        {
            if (!m_PrototypeFilter.empty() &&
                proto->className.find(m_PrototypeFilter) == std::string::npos)
            {
                continue;
            }

            ImGui::BulletText("%s  (in %zu / out %zu)",
                              proto->className.c_str(),
                              proto->inputs.size(),
                              proto->outputs.size());
        }
        ImGui::TreePop();
    }
}
