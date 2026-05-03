#include <imgui.h>
#include <Preditor/ReferenceCatalog/Catalog.h>
#include "CatalogBrowserWindow.h"

namespace ReferenceCatalog
{

CatalogBrowserWindow::CatalogBrowserWindow()
{
    SetTitle("Reference Catalog");
    SetPersistentID("ReferenceCatalogBrowser");
    SetDestroyOnClose(false);
    SetVisible(false);
    RebuildKindList();
}

CatalogBrowserWindow::~CatalogBrowserWindow() = default;

void CatalogBrowserWindow::RebuildKindList()
{
    m_Kinds.clear();
    m_Kinds.push_back(""); // 0 = All
    for (const auto& k : Catalog::Get().Kinds())
        m_Kinds.push_back(k);
    if (m_KindIndex >= (int)m_Kinds.size())
        m_KindIndex = 0;
}

void CatalogBrowserWindow::ShowContents()
{
    // Kind selector — refreshes list each frame so newly registered kinds appear.
    RebuildKindList();
    {
        const char* preview = m_KindIndex == 0 ? "All" : m_Kinds[m_KindIndex].c_str();
        ImGui::SetNextItemWidth(220);
        if (ImGui::BeginCombo("Kind", preview))
        {
            for (int i = 0; i < (int)m_Kinds.size(); ++i)
            {
                const bool selected = (i == m_KindIndex);
                const char* label = i == 0 ? "All" : m_Kinds[i].c_str();
                if (ImGui::Selectable(label, selected))
                    m_KindIndex = i;
                if (selected)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndCombo();
        }
    }

    ImGui::SameLine();
    if (m_KindIndex != 0 && ImGui::Button("Refresh"))
        Catalog::Get().Refresh(m_Kinds[m_KindIndex]);

    ImGui::SameLine();
    m_Filter.Draw("##filter", 220);

    if (m_KindIndex != 0)
    {
        const std::string& kind = m_Kinds[m_KindIndex];
        std::string desc = Catalog::Get().DescriptionOf(kind);
        if (!desc.empty())
            ImGui::TextDisabled("%s", desc.c_str());
    }

    ImGui::Separator();
    DrawResults();
}

void CatalogBrowserWindow::DrawResults()
{
    if (!ImGui::BeginTable("##results", 4,
            ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_RowBg |
            ImGuiTableFlags_ScrollY | ImGuiTableFlags_SizingStretchProp))
        return;

    ImGui::TableSetupColumn("Name",   ImGuiTableColumnFlags_WidthStretch);
    ImGui::TableSetupColumn("Id",     ImGuiTableColumnFlags_WidthFixed, 180);
    ImGui::TableSetupColumn("Kind",   ImGuiTableColumnFlags_WidthFixed, 120);
    ImGui::TableSetupColumn("Source", ImGuiTableColumnFlags_WidthFixed, 200);
    ImGui::TableSetupScrollFreeze(0, 1);
    ImGui::TableHeadersRow();

    auto drawRow = [&](const Entry& e, const std::string& kind) {
        if (!m_Filter.PassFilter(e.name.c_str()) && !m_Filter.PassFilter(e.id.c_str()))
            return;
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TextUnformatted(e.name.c_str());
        ImGui::TableNextColumn();
        ImGui::TextUnformatted(e.id.c_str());
        if (ImGui::IsItemClicked())
            ImGui::SetClipboardText(e.id.c_str());
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Click to copy id");
        ImGui::TableNextColumn();
        ImGui::TextDisabled("%s", kind.c_str());
        ImGui::TableNextColumn();
        ImGui::TextDisabled("%s", e.sourceLabel.c_str());
    };

    if (m_KindIndex == 0)
    {
        for (const auto& kind : Catalog::Get().Kinds())
        {
            auto table = Catalog::Get().TryGet(kind);
            if (!table)
                continue;
            for (const Entry& e : table->All())
                drawRow(e, kind);
        }
    }
    else
    {
        const std::string& kind = m_Kinds[m_KindIndex];
        auto table = Catalog::Get().TryGet(kind);
        if (table)
        {
            for (const Entry& e : table->All())
                drawRow(e, kind);
        }
        else
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::TextDisabled("(no provider for this kind)");
        }
    }

    ImGui::EndTable();
}

} // namespace ReferenceCatalog
