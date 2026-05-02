#include <imgui_stdlib.h>
#include "GraphTokensWindow.h"
#include "../Commands/AddTokenCmd.h"
#include "../Commands/ModifyTokenCmd.h"
#include "../Commands/RemoveTokenCmd.h"
#include "../FlowgraphEditorWindow.h"
#include "../GraphTab.h"
#include "../Model/Flowgraph.h"
#include "../Registry/PrototypeNode.h"

namespace
{
const char* const kTypeNames[] = { "Void", "Int", "Float", "EntityId", "Vec3", "String", "Bool" };
constexpr int kTypeCount = (int)(sizeof(kTypeNames) / sizeof(kTypeNames[0]));
} // anonymous namespace

FlowgraphEditor::GraphTokensWindow::GraphTokensWindow()
{
    SetTitle("Flowgraph Tokens");
    SetPersistentID("FlowgraphTokens");
    SetDestroyOnClose(false);
    SetVisible(false);
}

FlowgraphEditor::GraphTokensWindow::~GraphTokensWindow()
{
}

void FlowgraphEditor::GraphTokensWindow::ShowContents()
{
    auto* editor = FlowgraphEditorWindow::Get();
    GraphTab* tab = editor ? editor->GetActiveTab() : nullptr;
    Flowgraph* graph = tab ? tab->GetGraph() : nullptr;

    if (!graph)
    {
        ImGui::TextDisabled("No active graph.");
        return;
    }

    ImGui::TextDisabled("Graph");
    ImGui::BulletText("Title: %s", graph->title.empty() ? "(none)" : graph->title.c_str());
    if (!graph->description.empty())
        ImGui::BulletText("Description: %s", graph->description.c_str());
    if (!graph->group.empty())
        ImGui::BulletText("Group: %s", graph->group.c_str());
    ImGui::BulletText("Enabled: %s", graph->enabled ? "yes" : "no");
    if (!graph->multiplayer.empty())
        ImGui::BulletText("MultiPlayer: %s", graph->multiplayer.c_str());

    ImGui::Spacing();
    ImGui::TextDisabled("Tokens (%zu)", graph->tokens.size());
    ImGui::SameLine();
    if (ImGui::SmallButton("+ Add"))
        graph->Execute(std::make_unique<AddTokenCmd>("newToken", 0));

    if (graph->tokens.empty())
    {
        ImGui::BulletText("(none)");
        return;
    }

    if (!ImGui::BeginTable("##tokens", 3,
            ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp))
    {
        return;
    }

    ImGui::TableSetupColumn("Name",   ImGuiTableColumnFlags_WidthStretch);
    ImGui::TableSetupColumn("Type",   ImGuiTableColumnFlags_WidthFixed);
    ImGui::TableSetupColumn("##del",  ImGuiTableColumnFlags_WidthFixed);
    ImGui::TableHeadersRow();

    int removeIndex = -1;

    for (size_t i = 0; i < graph->tokens.size(); ++i)
    {
        const GraphToken& token = graph->tokens[i];
        ImGui::PushID((int)i);
        ImGui::TableNextRow();

        // Name
        ImGui::TableNextColumn();
        ImGui::SetNextItemWidth(-FLT_MIN);
        std::string name = token.name;
        if (ImGui::InputText("##name", &name) && name != token.name)
        {
            GraphToken updated = token;
            updated.name = name;
            graph->Execute(std::make_unique<ModifyTokenCmd>(i, token, updated));
        }

        // Type
        ImGui::TableNextColumn();
        ImGui::SetNextItemWidth(-FLT_MIN);
        int typeIdx = (token.type >= 0 && token.type < kTypeCount) ? token.type : 0;
        if (ImGui::Combo("##type", &typeIdx, kTypeNames, kTypeCount) && typeIdx != token.type)
        {
            GraphToken updated = token;
            updated.type = typeIdx;
            graph->Execute(std::make_unique<ModifyTokenCmd>(i, token, updated));
        }

        // Delete
        ImGui::TableNextColumn();
        if (ImGui::SmallButton("X"))
            removeIndex = (int)i;

        ImGui::PopID();
    }

    ImGui::EndTable();

    if (removeIndex >= 0)
        graph->Execute(std::make_unique<RemoveTokenCmd>(*graph, (size_t)removeIndex));
}
