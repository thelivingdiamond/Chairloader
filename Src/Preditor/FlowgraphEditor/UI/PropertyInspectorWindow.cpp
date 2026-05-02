#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ImGuiNodeEditor/imgui_node_editor.h>
#include <imgui_stdlib.h>
#include "PropertyInspectorWindow.h"
#include "../Commands/RenameNodeCmd.h"
#include "../Commands/SetPortDefaultCmd.h"
#include "../FlowgraphEditorWindow.h"
#include "../GraphTab.h"
#include "../Model/Flowgraph.h"

namespace ed = ax::NodeEditor;

namespace
{

// True for port names that look color-ish (substring match, case insensitive).
// Used to swap the Vec3 editor for a ColorEdit3 swatch + picker.
bool LooksLikeColor(std::string_view name)
{
    std::string lower(name);
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c) { return (char)std::tolower(c); });
    return lower.find("color") != std::string::npos;
}

// Returns a typed editor for an input port; on commit emits SetPortDefaultCmd.
// Each frame: read current from model, run a typed widget, compare to before,
// emit if changed. Coalescing in SetPortDefaultCmd keeps history clean.
void DrawPortValueEditor(FlowgraphEditor::Flowgraph& graph,
                         FlowgraphEditor::Node& node,
                         const FlowgraphEditor::Pin& pin)
{
    using namespace FlowgraphEditor;

    auto it = node.inputDefaults.find(pin.name);
    const std::string current = it != node.inputDefaults.end() ? it->second : "";
    const FlowDataType type = pin.prototype ? pin.prototype->type : FlowDataType::Void;

    ImGui::PushID(pin.name.c_str());
    ImGui::SetNextItemWidth(-FLT_MIN);

    bool changed = false;
    std::string newValue = current;

    switch (type)
    {
    case FlowDataType::Bool:
    {
        bool v = (current == "1" || current == "true");
        if (ImGui::Checkbox("##val", &v))
        {
            newValue = v ? "1" : "0";
            changed = true;
        }
        break;
    }
    case FlowDataType::Int:
    {
        int v = std::atoi(current.c_str());
        if (ImGui::InputInt("##val", &v))
        {
            newValue = std::to_string(v);
            changed = true;
        }
        break;
    }
    case FlowDataType::Float:
    {
        float v = static_cast<float>(std::atof(current.c_str()));
        if (ImGui::InputFloat("##val", &v))
        {
            char buf[32];
            std::snprintf(buf, sizeof(buf), "%g", v);
            newValue = buf;
            changed = true;
        }
        break;
    }
    case FlowDataType::Vec3:
    {
        float v[3] = { 0.0f, 0.0f, 0.0f };
        std::sscanf(current.c_str(), "%f,%f,%f", &v[0], &v[1], &v[2]);

        const bool committed = LooksLikeColor(pin.name)
            ? ImGui::ColorEdit3("##val", v, ImGuiColorEditFlags_Float)
            : ImGui::InputFloat3("##val", v);

        if (committed)
        {
            char buf[96];
            std::snprintf(buf, sizeof(buf), "%g,%g,%g", v[0], v[1], v[2]);
            newValue = buf;
            changed = true;
        }
        break;
    }
    case FlowDataType::String:
    case FlowDataType::EntityId:
    default:
    {
        std::string buf = current;
        if (ImGui::InputText("##val", &buf))
        {
            newValue = buf;
            changed = true;
        }
        break;
    }
    }

    ImGui::PopID();

    if (changed && newValue != current)
    {
        graph.Execute(std::make_unique<SetPortDefaultCmd>(
            node.id, pin.name, current, newValue));
    }
}

} // anonymous namespace

FlowgraphEditor::PropertyInspectorWindow::PropertyInspectorWindow()
{
    SetTitle("Flowgraph Inspector");
    SetPersistentID("FlowgraphInspector");
    SetDestroyOnClose(false);
    SetVisible(false);
}

FlowgraphEditor::PropertyInspectorWindow::~PropertyInspectorWindow()
{
}

void FlowgraphEditor::PropertyInspectorWindow::ShowContents()
{
    auto* editor = FlowgraphEditorWindow::Get();
    GraphTab* tab = editor ? editor->GetActiveTab() : nullptr;
    Flowgraph* graph = tab ? tab->GetGraph() : nullptr;
    ed::EditorContext* ctx = tab ? tab->GetEditorContext() : nullptr;

    if (!graph || !ctx)
    {
        ImGui::TextDisabled("No active graph.");
        return;
    }

    ed::SetCurrentEditor(ctx);
    const int count = ed::GetSelectedObjectCount();
    std::vector<ed::NodeId> selected(count);
    const int written = ed::GetSelectedNodes(selected.data(), count);
    ed::SetCurrentEditor(nullptr);

    if (written <= 0)
    {
        ImGui::TextDisabled("Select a node on the canvas to inspect it.");
        return;
    }

    for (int i = 0; i < written; ++i)
    {
        int64_t nodeId = (int64_t)(uintptr_t)selected[i].AsPointer();
        Node* node = graph->FindNode(nodeId);
        if (!node)
            continue;

        ImGui::PushID((int)nodeId);
        DrawNodeProperties(*node);
        ImGui::PopID();

        if (i + 1 < written)
            ImGui::Separator();
    }
}

void FlowgraphEditor::PropertyInspectorWindow::DrawNodeProperties(Node& node)
{
    auto* editor = FlowgraphEditorWindow::Get();
    GraphTab* tab = editor ? editor->GetActiveTab() : nullptr;
    Flowgraph* graph = tab ? tab->GetGraph() : nullptr;
    if (!graph)
        return;

    ImGui::TextUnformatted(node.className.empty() ? "<unnamed>" : node.className.c_str());
    ImGui::TextDisabled("id %lld", (long long)node.id);

    // Editable Name attribute. Mandatory for commentboxes (it's their label);
    // optional for regular nodes (some flowgraphs use it as a comment).
    {
        ImGui::Spacing();
        ImGui::AlignTextToFramePadding();
        ImGui::TextUnformatted("Name");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(-FLT_MIN);
        std::string buf = node.name;
        const char* hint = node.IsCommentBox() ? "Commentbox label" : "(optional)";
        if (ImGui::InputTextWithHint("##nodeName", hint, &buf) && buf != node.name)
        {
            graph->Execute(std::make_unique<RenameNodeCmd>(node.id, node.name, buf));
        }
    }

    if (node.prototype && !node.prototype->description.empty())
    {
        ImGui::Spacing();
        ImGui::TextWrapped("%s", node.prototype->description.c_str());
    }

    if (!node.entityGuid.empty() || !node.entityGuid64.empty())
    {
        ImGui::Spacing();
        if (!node.entityGuid64.empty())
            ImGui::Text("EntityGUID_64: %s", node.entityGuid64.c_str());
        else
            ImGui::Text("EntityGUID: %s", node.entityGuid.c_str());
    }

    ImGui::Spacing();
    ImGui::TextDisabled("Inputs");

    if (node.inputs.empty())
    {
        ImGui::BulletText("(none)");
    }
    else if (ImGui::BeginTable("##inputs", 3,
        ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingStretchProp))
    {
        ImGui::TableSetupColumn("Name",  ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Type",  ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);

        for (Pin& pin : node.inputs)
        {
            ImGui::TableNextRow();

            ImGui::TableNextColumn();
            ImGui::TextUnformatted(pin.name.c_str());
            if (pin.prototype && !pin.prototype->description.empty() && ImGui::IsItemHovered())
                ImGui::SetTooltip("%s", pin.prototype->description.c_str());

            ImGui::TableNextColumn();
            const char* typeStr = pin.prototype ? ToString(pin.prototype->type) : "?";
            ImGui::TextDisabled("%s", typeStr);

            ImGui::TableNextColumn();
            DrawPortValueEditor(*graph, node, pin);
        }
        ImGui::EndTable();
    }

    ImGui::Spacing();
    ImGui::TextDisabled("Outputs");

    if (node.outputs.empty())
    {
        ImGui::BulletText("(none)");
    }
    else
    {
        for (const Pin& pin : node.outputs)
        {
            const char* typeStr = pin.prototype ? ToString(pin.prototype->type) : "?";
            ImGui::BulletText("%s : %s", pin.name.c_str(), typeStr);
            if (pin.prototype && !pin.prototype->description.empty() && ImGui::IsItemHovered())
                ImGui::SetTooltip("%s", pin.prototype->description.c_str());
        }
    }
}
