#include <algorithm>
#include "GraphTab.h"

namespace ed = ax::NodeEditor;

namespace
{

using FlowgraphEditor::Pin;
using FlowgraphEditor::Node;

// Minimum gap between input and output columns; title width may push wider.
constexpr float kColumnGap = 30.0f;

uint64_t NextTabId()
{
    static uint64_t s_id = 0;
    return ++s_id;
}

float MaxPinLabelWidth(const std::vector<Pin>& pins)
{
    float maxW = 0.0f;
    for (const Pin& pin : pins)
        maxW = std::max(maxW, ImGui::CalcTextSize(pin.name.c_str()).x);
    return maxW;
}

void DrawPin(const Pin& pin, ed::PinKind kind)
{
    ed::BeginPin(pin.id, kind);
    ImGui::TextUnformatted(pin.name.c_str());
    ed::EndPin();
}

// Stacks input pins downwards from (x, y); connectors anchor at the left text edge.
void DrawInputColumn(const std::vector<Pin>& pins, float x, float y, float lineH)
{
    if (pins.empty())
        return;

    ed::PushStyleVar(ed::StyleVar_PivotAlignment, ImVec2(0.0f, 0.5f));
    ed::PushStyleVar(ed::StyleVar_PivotSize,      ImVec2(0.0f, 0.0f));
    for (size_t i = 0; i < pins.size(); ++i)
    {
        ImGui::SetCursorPos(ImVec2(x, y + (float)i * lineH));
        DrawPin(pins[i], ed::PinKind::Input);
    }
    ed::PopStyleVar(2);
}

// Stacks output pins downwards, right-justified to rightX; connectors at the right text edge.
void DrawOutputColumn(const std::vector<Pin>& pins, float rightX, float y, float lineH)
{
    if (pins.empty())
        return;

    ed::PushStyleVar(ed::StyleVar_PivotAlignment, ImVec2(1.0f, 0.5f));
    ed::PushStyleVar(ed::StyleVar_PivotSize,      ImVec2(0.0f, 0.0f));
    for (size_t i = 0; i < pins.size(); ++i)
    {
        const float w = ImGui::CalcTextSize(pins[i].name.c_str()).x;
        ImGui::SetCursorPos(ImVec2(rightX - w, y + (float)i * lineH));
        DrawPin(pins[i], ed::PinKind::Output);
    }
    ed::PopStyleVar(2);
}

void DrawNode(const Node& node)
{
    const std::string& title = node.className.empty() ? std::string("<unnamed>")
                                                       : node.className;
    const float titleW     = ImGui::CalcTextSize(title.c_str()).x;
    const float inputColW  = MaxPinLabelWidth(node.inputs);
    const float outputColW = MaxPinLabelWidth(node.outputs);
    const float bodyW      = std::max(titleW, inputColW + kColumnGap + outputColW);

    ed::BeginNode(node.id);

    ImGui::TextUnformatted(title.c_str());
    if (!node.prototype)
        ImGui::TextDisabled("(class not in registry)");

    // Pins placed at explicit (x, y) — bypasses ImGui auto-layout inside BeginNode.
    const float originX = ImGui::GetCursorPosX();
    const float originY = ImGui::GetCursorPosY();
    const float lineH   = ImGui::GetTextLineHeightWithSpacing();

    DrawInputColumn (node.inputs,  originX,          originY, lineH);
    DrawOutputColumn(node.outputs, originX + bodyW,  originY, lineH);

    // Sentinel: extends the node's content rect so the output column hugs the right edge.
    const int rowCount = std::max((int)node.inputs.size(), (int)node.outputs.size());
    if (rowCount > 0)
    {
        ImGui::SetCursorPos(ImVec2(originX, originY + (float)rowCount * lineH));
        ImGui::Dummy(ImVec2(bodyW, 0.0f));
    }

    ed::EndNode();
}

} // anonymous namespace

FlowgraphEditor::GraphTab::GraphTab(std::unique_ptr<Flowgraph> graph, std::string title)
    : m_Title(std::move(title))
    , m_Graph(std::move(graph))
{
    m_ImGuiId = m_Title + "###flowgraph-tab-" + std::to_string(NextTabId());

    ed::Config config;
    config.SettingsFile = nullptr;
    m_pContext = ed::CreateEditor(&config);
}

FlowgraphEditor::GraphTab::~GraphTab()
{
    if (m_pContext)
    {
        ed::DestroyEditor(m_pContext);
        m_pContext = nullptr;
    }
}

void FlowgraphEditor::GraphTab::ShowContents()
{
    if (!m_Graph)
        return;

    ed::SetCurrentEditor(m_pContext);
    ed::Begin("##GraphCanvas", ImVec2(0, 0));

    if (m_bFirstFrame)
    {
        for (const Node& node : m_Graph->nodes)
            ed::SetNodePosition(node.id, node.pos);
        m_bFirstFrame = false;
    }

    for (const Node& node : m_Graph->nodes)
        DrawNode(node);

    for (const Edge& edge : m_Graph->edges)
    {
        int64_t fromId = m_Graph->ResolvePinId(edge.fromNodeId, edge.fromPort, false);
        int64_t toId   = m_Graph->ResolvePinId(edge.toNodeId,   edge.toPort,   true);
        if (fromId && toId)
            ed::Link(edge.id, fromId, toId);
    }

    ed::End();
    ed::SetCurrentEditor(nullptr);
}
