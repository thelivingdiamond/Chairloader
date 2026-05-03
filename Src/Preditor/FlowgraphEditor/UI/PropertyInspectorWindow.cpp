#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ImGuiNodeEditor/imgui_node_editor.h>
#include <imgui_stdlib.h>
#include <Preditor/ReferenceCatalog/Catalog.h>
#include <Preditor/ReferenceCatalog/KindRegistry.h>
#include <Preditor/ReferenceCatalog/Table.h>
#include "PropertyInspectorWindow.h"
#include "../Commands/RenameNodeCmd.h"
#include "../Commands/ResizeCommentBoxCmd.h"
#include "../Commands/SetEdgeEnabledCmd.h"
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

// Renders a name-picker for ports whose value is an id into a catalog kind.
// Returns true on success; false (rare — empty/unloaded table) falls through
// to the typed editor.
bool DrawReferencePicker(FlowgraphEditor::Flowgraph& graph,
                         FlowgraphEditor::Node& node,
                         const FlowgraphEditor::Pin& pin,
                         const std::string& kind,
                         const std::string& current)
{
    auto table = ReferenceCatalog::Catalog::Get().TryGet(kind);
    if (!table || table->Empty())
        return false;

    const ReferenceCatalog::Entry* entry = table->ById(current);

    // Display the user's raw value alongside the resolved name — preserves
    // signed-int64 forms ("-4589…") that the model stores even though the
    // Table resolves via the canonical unsigned form.
    std::string buttonLabel;
    ImVec4 col;
    if (entry)
    {
        buttonLabel = entry->name + "  [" + current + "]";
        col = ImVec4(0.45f, 0.95f, 0.45f, 1.0f);
    }
    else if (current.empty())
    {
        buttonLabel = "(none)";
        col = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
    }
    else
    {
        buttonLabel = "(unknown) " + current;
        col = ImVec4(1.0f, 0.78f, 0.2f, 1.0f);
    }

    ImGui::PushStyleColor(ImGuiCol_Text, col);
    const bool open = ImGui::Button(buttonLabel.c_str(), ImVec2(-FLT_MIN, 0));
    ImGui::PopStyleColor();
    if (open)
        ImGui::OpenPopup("##refPicker");

    if (ImGui::BeginPopup("##refPicker"))
    {
        static ImGuiTextFilter filter;
        if (ImGui::IsWindowAppearing())
        {
            filter.Clear();
            ImGui::SetKeyboardFocusHere();
        }
        filter.Draw("##filter", 280.0f);

        const std::string canonCurrent = ReferenceCatalog::CanonicalizeId(current);

        ImGui::BeginChild("##list", ImVec2(380, 300), true);
        for (const auto& e : table->All())
        {
            if (!filter.PassFilter(e.name.c_str()) && !filter.PassFilter(e.id.c_str()))
                continue;
            ImGui::PushID(&e);
            const bool selected = (ReferenceCatalog::CanonicalizeId(e.id) == canonCurrent);
            if (ImGui::Selectable(e.name.c_str(), selected))
            {
                if (!selected)
                {
                    graph.Execute(std::make_unique<FlowgraphEditor::SetPortDefaultCmd>(
                        node.id, pin.name, current, e.id));
                }
                ImGui::CloseCurrentPopup();
            }
            ImGui::SameLine();
            ImGui::TextDisabled("[%s]", e.id.c_str());
            ImGui::PopID();
        }
        ImGui::EndChild();

        ImGui::TextDisabled("%zu entries · %s", table->Size(), kind.c_str());
        ImGui::EndPopup();
    }
    return true;
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

    // Reference picker takes precedence over the typed editor when this port
    // is mapped to a catalog kind (e.g. GameToken). Falls through if the
    // catalog is empty or unloaded — typed editor remains as escape hatch.
    {
        const std::string& uiCfg = pin.prototype ? pin.prototype->uiConfig : std::string{};
        auto kindOpt = ReferenceCatalog::KindRegistry::Get().Resolve({
            node.className, pin.name, uiCfg
        });
        if (kindOpt && DrawReferencePicker(graph, node, pin, *kindOpt, current))
        {
            ImGui::PopID();
            return;
        }
    }

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
    const int objectCount = ed::GetSelectedObjectCount();
    std::vector<ed::NodeId> selectedNodes(objectCount);
    std::vector<ed::LinkId> selectedLinks(objectCount);
    const int writtenNodes = ed::GetSelectedNodes(selectedNodes.data(), objectCount);
    const int writtenLinks = ed::GetSelectedLinks(selectedLinks.data(), objectCount);
    ed::SetCurrentEditor(nullptr);

    if (writtenNodes <= 0 && writtenLinks <= 0)
    {
        ImGui::TextDisabled("Select a node or edge on the canvas to inspect it.");
        return;
    }

    bool anyDrawn = false;
    for (int i = 0; i < writtenNodes; ++i)
    {
        int64_t nodeId = (int64_t)(uintptr_t)selectedNodes[i].AsPointer();
        Node* node = graph->FindNode(nodeId);
        if (!node)
            continue;

        if (anyDrawn)
            ImGui::Separator();
        ImGui::PushID((int)nodeId);
        DrawNodeProperties(*node);
        ImGui::PopID();
        anyDrawn = true;
    }

    for (int i = 0; i < writtenLinks; ++i)
    {
        int64_t edgeId = (int64_t)(uintptr_t)selectedLinks[i].AsPointer();
        Edge* edge = graph->FindEdge(edgeId);
        if (!edge)
            continue;

        if (anyDrawn)
            ImGui::Separator();
        ImGui::PushID((int)edgeId);
        DrawEdgeProperties(*edge);
        ImGui::PopID();
        anyDrawn = true;
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

    // Commentbox-specific controls — typed Width/Height live on the Node, not
    // in inputDefaults, so they don't get a row in the generic Inputs table.
    if (node.IsCommentBox())
    {
        ImGui::Spacing();
        ImGui::AlignTextToFramePadding();
        ImGui::TextUnformatted("Size");
        ImGui::SameLine();
        float w = node.commentWidth;
        float h = node.commentHeight;
        constexpr float kItemW = 80.0f;
        ImGui::SetNextItemWidth(kItemW);
        const bool wChanged = ImGui::DragFloat("##cw", &w, 1.0f, 30.0f, 8192.0f, "W: %.0f");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(kItemW);
        const bool hChanged = ImGui::DragFloat("##ch", &h, 1.0f, 30.0f, 8192.0f, "H: %.0f");
        if ((wChanged || hChanged) &&
            (w != node.commentWidth || h != node.commentHeight))
        {
            graph->Execute(std::make_unique<ResizeCommentBoxCmd>(
                node.id,
                ImVec2(node.commentWidth, node.commentHeight),
                ImVec2(w, h)));
        }
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

void FlowgraphEditor::PropertyInspectorWindow::DrawEdgeProperties(Edge& edge)
{
    auto* editor = FlowgraphEditorWindow::Get();
    GraphTab* tab = editor ? editor->GetActiveTab() : nullptr;
    Flowgraph* graph = tab ? tab->GetGraph() : nullptr;
    if (!graph)
        return;

    auto nodeLabel = [&](int64_t nodeId) -> std::string {
        const Node* n = graph->FindNode(nodeId);
        if (!n) return "<missing>";
        if (!n->name.empty()) return n->name;
        return n->className.empty() ? "<unnamed>" : n->className;
    };

    ImGui::TextUnformatted("Edge");
    ImGui::TextDisabled("id %lld", (long long)edge.id);

    ImGui::Spacing();
    ImGui::Text("From: %s.%s", nodeLabel(edge.fromNodeId).c_str(), edge.fromPort.c_str());
    ImGui::Text("To:   %s.%s", nodeLabel(edge.toNodeId).c_str(),   edge.toPort.c_str());

    ImGui::Spacing();
    bool enabled = edge.enabled;
    if (ImGui::Checkbox("Enabled", &enabled) && enabled != edge.enabled)
    {
        graph->Execute(std::make_unique<SetEdgeEnabledCmd>(
            edge.id, edge.enabled, enabled));
    }
}
