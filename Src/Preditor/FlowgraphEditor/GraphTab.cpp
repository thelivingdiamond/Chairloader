#include <algorithm>
#include <cctype>
#include <cstdio>
#include <map>
#include <set>
#include <imgui_stdlib.h>
#include "GraphTab.h"
#include "Clipboard.h"
#include "Commands/AddNodeCmd.h"
#include "Commands/CompositeCommand.h"
#include "Commands/ConnectPinsCmd.h"
#include "Commands/MoveNodeCmd.h"
#include "Commands/PasteNodesCmd.h"
#include "Commands/RemoveEdgeCmd.h"
#include "Commands/RemoveNodeCmd.h"
#include "FlowgraphEditorWindow.h"
#include "Registry/NodeRegistry.h"

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

// Parses "r,g,b" (each in 0..1) out of a commentbox's <Inputs Color="..."/>
// default. Returns ImColor(160,160,160) when missing or malformed.
ImColor ParseCommentColor(const Node& node)
{
    auto it = node.inputDefaults.find("Color");
    if (it == node.inputDefaults.end())
        return ImColor(160, 160, 160);

    float r = 0.0f, g = 0.0f, b = 0.0f;
    if (std::sscanf(it->second.c_str(), "%f,%f,%f", &r, &g, &b) != 3)
        return ImColor(160, 160, 160);

    return ImColor(r, g, b, 1.0f);
}

// Commentboxes are decoration, not flow nodes — render as a colored group
// rectangle with a header label, no pins. Z-pushed behind regular nodes so
// they don't intercept clicks.
void DrawCommentBox(const Node& node)
{
    std::string label;
    if      (!node.name.empty())      label = node.name;
    else if (!node.className.empty()) label = node.className;
    else                              label = "comment";

    const ImColor color = ParseCommentColor(node);
    const ImColor bg(color.Value.x, color.Value.y, color.Value.z, 0.20f);
    const ImColor border(color.Value.x, color.Value.y, color.Value.z, 0.85f);

    ed::PushStyleColor(ed::StyleColor_NodeBg,     bg);
    ed::PushStyleColor(ed::StyleColor_NodeBorder, border);
    ed::PushStyleColor(ed::StyleColor_GroupBg,    bg);
    ed::PushStyleColor(ed::StyleColor_GroupBorder, border);

    ed::BeginNode(node.id);
    ImGui::TextUnformatted(label.c_str());
    ed::Group(ImVec2(node.commentWidth, node.commentHeight));
    ed::EndNode();

    ed::PopStyleColor(4);

    // Sit behind regular nodes so they receive input first.
    ed::SetNodeZPosition(node.id, -1.0f);
}

// Builds a PasteNodesCmd from a snapshot of source nodes/edges. Allocates
// fresh ids in `dst`, applies a uniform position offset, and drops edges with
// at least one endpoint outside the snapshot. Used by both paste and duplicate.
std::unique_ptr<FlowgraphEditor::PasteNodesCmd> BuildCloneCommand(
    FlowgraphEditor::Flowgraph& dst,
    const std::vector<FlowgraphEditor::Node>& srcNodes,
    const std::vector<FlowgraphEditor::Edge>& srcEdges,
    ImVec2 offset,
    const char* commandName)
{
    using namespace FlowgraphEditor;

    std::map<int64_t, int64_t> nodeIdRemap;
    std::vector<Node> newNodes;
    newNodes.reserve(srcNodes.size());
    for (const Node& src : srcNodes)
    {
        Node n = src;
        const int64_t newId = dst.AllocNodeId();
        nodeIdRemap[src.id] = newId;
        n.id = newId;
        n.pos.x += offset.x;
        n.pos.y += offset.y;
        for (Pin& p : n.inputs)  p.id = dst.AllocPinId();
        for (Pin& p : n.outputs) p.id = dst.AllocPinId();
        newNodes.push_back(std::move(n));
    }

    std::vector<Edge> newEdges;
    newEdges.reserve(srcEdges.size());
    for (const Edge& src : srcEdges)
    {
        auto fromIt = nodeIdRemap.find(src.fromNodeId);
        auto toIt   = nodeIdRemap.find(src.toNodeId);
        if (fromIt == nodeIdRemap.end() || toIt == nodeIdRemap.end())
            continue;
        Edge e = src;
        e.id = dst.AllocEdgeId();
        e.fromNodeId = fromIt->second;
        e.toNodeId   = toIt->second;
        newEdges.push_back(std::move(e));
    }

    return std::make_unique<PasteNodesCmd>(
        std::move(newNodes), std::move(newEdges), commandName);
}

void DrawNode(const Node& node)
{
    if (node.IsCommentBox())
    {
        DrawCommentBox(node);
        return;
    }

    const std::string title = node.className.empty() ? "<unnamed>" : node.className;
    const float titleW     = ImGui::CalcTextSize(title.c_str()).x;
    const float maxInputW  = MaxPinLabelWidth(node.inputs);
    const float maxOutputW = MaxPinLabelWidth(node.outputs);
    const float bodyW      = std::max(titleW, maxInputW + kColumnGap + maxOutputW);

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

    if (m_bNeedsSync)
    {
        SyncAllNodePositions();
        m_bNeedsSync = false;
    }

    for (const Node& node : m_Graph->nodes)
        DrawNode(node);

    DetectAndEmitMoves();

    for (const Edge& edge : m_Graph->edges)
    {
        int64_t fromId = m_Graph->ResolvePinId(edge.fromNodeId, edge.fromPort, false);
        int64_t toId   = m_Graph->ResolvePinId(edge.toNodeId,   edge.toPort,   true);
        if (fromId && toId)
            ed::Link(edge.id, fromId, toId);
    }

    HandleNewLinks();
    HandleDelete();

    ed::End();

    // Drop target for prototypes dragged in from the palette. ed::End leaves
    // an item that BeginDragDropTarget latches onto.
    if (ImGui::BeginDragDropTarget())
    {
        if (const auto* payload = ImGui::AcceptDragDropPayload("FLOWGRAPH_PROTOTYPE"))
        {
            std::string className(static_cast<const char*>(payload->Data));
            ImVec2 canvasPos = ed::ScreenToCanvas(ImGui::GetMousePos());
            m_Graph->Execute(std::make_unique<AddNodeCmd>(std::move(className), canvasPos));
            m_bNeedsSync = true;
        }
        ImGui::EndDragDropTarget();
    }

    HandleKeyboard();
    DrawAddPopup();

    ed::SetCurrentEditor(nullptr);
}

void FlowgraphEditor::GraphTab::SyncAllNodePositions()
{
    for (const Node& node : m_Graph->nodes)
        ed::SetNodePosition(node.id, node.pos);
}

void FlowgraphEditor::GraphTab::DetectAndEmitMoves()
{
    for (Node& node : m_Graph->nodes)
    {
        ImVec2 canvasPos = ed::GetNodePosition(node.id);
        if (canvasPos.x != node.pos.x || canvasPos.y != node.pos.y)
        {
            // First time we see this node move in the current session, snapshot start.
            // Direct mutation during drag — the composite command emitted on drag-end
            // is what makes it undoable.
            if (m_DragStartPositions.find(node.id) == m_DragStartPositions.end())
                m_DragStartPositions[node.id] = node.pos;
            node.pos = canvasPos;
            m_bDragInProgress = true;
        }
    }

    // Finalize on mouse release rather than "no motion this frame" — a paused
    // mid-drag would otherwise prematurely close the session and the next bit
    // of motion would start a fresh one, producing many tiny undo entries.
    if (m_bDragInProgress && ImGui::IsMouseReleased(ImGuiMouseButton_Left))
        FinalizeDragSession();
}

void FlowgraphEditor::GraphTab::FinalizeDragSession()
{
    auto composite = std::make_unique<CompositeCommand>("Move Nodes");

    for (auto& [nodeId, startPos] : m_DragStartPositions)
    {
        const Node* n = m_Graph->FindNode(nodeId);
        if (!n)
            continue;
        if (n->pos.x == startPos.x && n->pos.y == startPos.y)
            continue;
        composite->Add(std::make_unique<MoveNodeCmd>(nodeId, startPos, n->pos));
    }

    if (!composite->IsEmpty())
    {
        // Composite::Redo re-applies positions — idempotent here since the
        // direct-mutation in DetectAndEmitMoves already moved them.
        m_Graph->Execute(std::move(composite));
    }

    m_DragStartPositions.clear();
    m_bDragInProgress = false;
}

void FlowgraphEditor::GraphTab::HandleNewLinks()
{
    if (!ed::BeginCreate(ImColor(255, 255, 255), 2.0f))
    {
        ed::EndCreate();
        return;
    }

    ed::PinId fromPinId, toPinId;
    if (ed::QueryNewLink(&fromPinId, &toPinId) && fromPinId && toPinId)
    {
        const int64_t fromId = (int64_t)(uintptr_t)fromPinId.AsPointer();
        const int64_t toId   = (int64_t)(uintptr_t)toPinId.AsPointer();

        PinLocation from = m_Graph->FindPinLocation(fromId);
        PinLocation to   = m_Graph->FindPinLocation(toId);

        const bool valid = from.IsValid() && to.IsValid()
                        && from.nodeId != to.nodeId
                        && from.isInput != to.isInput;

        if (!valid)
        {
            ed::RejectNewItem(ImColor(255, 64, 64), 2.0f);
        }
        else
        {
            // Ensure `from` is the output side, `to` is the input side.
            if (from.isInput)
                std::swap(from, to);

            if (ed::AcceptNewItem(ImColor(64, 255, 64), 2.0f))
            {
                m_Graph->Execute(std::make_unique<ConnectPinsCmd>(
                    from.nodeId, std::move(from.portName),
                    to.nodeId,   std::move(to.portName)));
            }
        }
    }

    ed::EndCreate();
}

void FlowgraphEditor::GraphTab::HandleDelete()
{
    std::vector<int64_t> nodeIds;
    std::vector<int64_t> edgeIds;

    if (ed::BeginDelete())
    {
        ed::NodeId nodeId;
        while (ed::QueryDeletedNode(&nodeId))
        {
            if (ed::AcceptDeletedItem())
                nodeIds.push_back((int64_t)(uintptr_t)nodeId.AsPointer());
        }
        ed::LinkId linkId;
        while (ed::QueryDeletedLink(&linkId))
        {
            if (ed::AcceptDeletedItem())
                edgeIds.push_back((int64_t)(uintptr_t)linkId.AsPointer());
        }
    }
    ed::EndDelete();

    if (nodeIds.empty() && edgeIds.empty())
        return;

    // Cascade: incident edges of deleted nodes get implicitly removed too.
    std::set<int64_t> edgeSet(edgeIds.begin(), edgeIds.end());
    for (int64_t nodeId : nodeIds)
    {
        for (const Edge& edge : m_Graph->edges)
            if (edge.fromNodeId == nodeId || edge.toNodeId == nodeId)
                edgeSet.insert(edge.id);
    }

    const char* name = "Delete Selection";
    if (nodeIds.size() == 1 && edgeSet.empty())       name = "Remove Node";
    else if (nodeIds.empty() && edgeSet.size() == 1)  name = "Remove Edge";

    auto composite = std::make_unique<CompositeCommand>(name);

    // Edges first so that on Undo the nodes restore first and edges find their endpoints.
    for (int64_t id : edgeSet)
        composite->Add(std::make_unique<RemoveEdgeCmd>(*m_Graph, id));
    for (int64_t id : nodeIds)
        composite->Add(std::make_unique<RemoveNodeCmd>(*m_Graph, id));

    if (!composite->IsEmpty())
    {
        m_Graph->Execute(std::move(composite));
        // Restored nodes (from a future Undo) will need positions pushed back to canvas.
        m_bNeedsSync = true;
    }
}

void FlowgraphEditor::GraphTab::HandleKeyboard()
{
    if (!ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows))
        return;
    // Don't steal Ctrl+C/X/V from focused InputTexts (e.g. the load-path field
    // at the top of the editor, or the inspector's Name field).
    if (ImGui::GetIO().WantTextInput)
        return;

    const bool ctrl  = ImGui::GetIO().KeyCtrl;
    const bool shift = ImGui::GetIO().KeyShift;

    if (ctrl && ImGui::IsKeyPressed(ImGuiKey_Z))
    {
        if (shift) m_Graph->Redo();
        else       m_Graph->Undo();
        m_bNeedsSync = true;
    }
    else if (ctrl && ImGui::IsKeyPressed(ImGuiKey_Y))
    {
        m_Graph->Redo();
        m_bNeedsSync = true;
    }
    else if (ctrl && ImGui::IsKeyPressed(ImGuiKey_S))
    {
        if (auto* w = FlowgraphEditorWindow::Get())
        {
            if (shift) w->SaveAll();
            else       w->SaveActiveTab();
        }
    }
    else if (ctrl && ImGui::IsKeyPressed(ImGuiKey_C))   CopySelection();
    else if (ctrl && ImGui::IsKeyPressed(ImGuiKey_X))   CutSelection();
    else if (ctrl && ImGui::IsKeyPressed(ImGuiKey_V))   PasteFromClipboard();
    else if (ctrl && ImGui::IsKeyPressed(ImGuiKey_D))   DuplicateSelection();
    // Blender-style: X to delete, Shift+A to open the add-node search popup.
    else if (!ctrl && !shift && ImGui::IsKeyPressed(ImGuiKey_X)) DeleteSelection();
    else if (!ctrl && shift  && ImGui::IsKeyPressed(ImGuiKey_A)) OpenAddPopup();
}

std::vector<int64_t> FlowgraphEditor::GraphTab::GetSelectedNodeIds()
{
    if (!m_pContext)
        return {};

    ed::SetCurrentEditor(m_pContext);
    const int count = ed::GetSelectedObjectCount();
    std::vector<ed::NodeId> selected(count);
    const int written = ed::GetSelectedNodes(selected.data(), count);
    ed::SetCurrentEditor(nullptr);

    std::vector<int64_t> ids;
    ids.reserve((size_t)std::max(0, written));
    for (int i = 0; i < written; ++i)
        ids.push_back((int64_t)(uintptr_t)selected[i].AsPointer());
    return ids;
}

void FlowgraphEditor::GraphTab::CopySelection()
{
    auto ids = GetSelectedNodeIds();
    if (ids.empty())
        return;

    std::set<int64_t> idSet(ids.begin(), ids.end());

    Clipboard& clip = Clipboard::Get();
    clip.Clear();

    for (const Node& n : m_Graph->nodes)
    {
        if (idSet.count(n.id))
            clip.nodes.push_back(n);
    }
    // Keep only edges fully internal to the selection — partial edges would
    // dangle on paste with no matching endpoint.
    for (const Edge& e : m_Graph->edges)
    {
        if (idSet.count(e.fromNodeId) && idSet.count(e.toNodeId))
            clip.edges.push_back(e);
    }
}

void FlowgraphEditor::GraphTab::CutSelection()
{
    auto ids = GetSelectedNodeIds();
    if (ids.empty())
        return;
    CopySelection();
    DeleteNodes(ids, "Cut");
}

void FlowgraphEditor::GraphTab::DeleteSelection()
{
    DeleteNodes(GetSelectedNodeIds(), "Delete");
}

void FlowgraphEditor::GraphTab::DeleteNodes(const std::vector<int64_t>& nodeIds,
                                            const char* commandName)
{
    if (nodeIds.empty())
        return;

    // Cascade: incident edges first so undo restores nodes before edges look
    // up their endpoints.
    std::set<int64_t> idSet(nodeIds.begin(), nodeIds.end());
    std::set<int64_t> edgeIds;
    for (const Edge& e : m_Graph->edges)
    {
        if (idSet.count(e.fromNodeId) || idSet.count(e.toNodeId))
            edgeIds.insert(e.id);
    }

    auto composite = std::make_unique<CompositeCommand>(commandName);
    for (int64_t id : edgeIds)
        composite->Add(std::make_unique<RemoveEdgeCmd>(*m_Graph, id));
    for (int64_t id : nodeIds)
        composite->Add(std::make_unique<RemoveNodeCmd>(*m_Graph, id));

    if (!composite->IsEmpty())
    {
        m_Graph->Execute(std::move(composite));
        m_bNeedsSync = true;
    }
}

void FlowgraphEditor::GraphTab::PasteFromClipboard()
{
    const Clipboard& clip = Clipboard::Get();
    if (clip.Empty())
        return;

    constexpr ImVec2 kPasteOffset(20.0f, 20.0f);
    auto cmd = BuildCloneCommand(*m_Graph, clip.nodes, clip.edges, kPasteOffset, "Paste");
    m_Graph->Execute(std::move(cmd));
    m_bNeedsSync = true;
}

void FlowgraphEditor::GraphTab::DuplicateSelection()
{
    auto ids = GetSelectedNodeIds();
    if (ids.empty())
        return;

    std::set<int64_t> idSet(ids.begin(), ids.end());

    std::vector<Node> srcNodes;
    for (const Node& n : m_Graph->nodes)
        if (idSet.count(n.id))
            srcNodes.push_back(n);

    std::vector<Edge> srcEdges;
    for (const Edge& e : m_Graph->edges)
        if (idSet.count(e.fromNodeId) && idSet.count(e.toNodeId))
            srcEdges.push_back(e);

    constexpr ImVec2 kDuplicateOffset(20.0f, 20.0f);
    auto cmd = BuildCloneCommand(*m_Graph, srcNodes, srcEdges, kDuplicateOffset, "Duplicate");
    m_Graph->Execute(std::move(cmd));
    m_bNeedsSync = true;
}

void FlowgraphEditor::GraphTab::OpenAddPopup()
{
    // Capture canvas pos at press time so the new node lands here even if
    // the user mouses around in the popup before clicking a result.
    m_AddPopupCanvasPos = ed::ScreenToCanvas(ImGui::GetMousePos());
    m_bWantOpenAddPopup = true;
}

void FlowgraphEditor::GraphTab::DrawAddPopup()
{
    constexpr const char* kPopupId = "##addNodePopup";

    if (m_bWantOpenAddPopup)
    {
        ImGui::OpenPopup(kPopupId);
        m_AddFilter.clear();
        m_AddHighlightedIndex = 0;
        m_bWantOpenAddPopup = false;
    }

    if (!ImGui::BeginPopup(kPopupId))
        return;

    if (ImGui::IsWindowAppearing())
        ImGui::SetKeyboardFocusHere();

    // Up/Down inside the InputText route through CallbackHistory — that's
    // ImGui's built-in hook for console-style history nav, repurposed here for
    // result-list nav. The lambda has no captures so it converts to a function
    // pointer; we pass &navDelta as user_data.
    int navDelta = 0;
    auto navCallback = [](ImGuiInputTextCallbackData* data) -> int {
        if (data->EventFlag == ImGuiInputTextFlags_CallbackHistory)
        {
            int* d = static_cast<int*>(data->UserData);
            if      (data->EventKey == ImGuiKey_UpArrow)   --(*d);
            else if (data->EventKey == ImGuiKey_DownArrow) ++(*d);
        }
        return 0;
    };

    constexpr float kPopupWidth = 320.0f;
    ImGui::SetNextItemWidth(kPopupWidth);
    const bool enterPressed = ImGui::InputTextWithHint(
        "##filter", "Search prototypes...", &m_AddFilter,
        ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackHistory,
        navCallback, &navDelta);

    // Reset selection when the filter changes — old index would point at a
    // stale row in the new (potentially shorter) match list.
    if (ImGui::IsItemEdited())
        m_AddHighlightedIndex = 0;

    if (m_AddFilter.empty())
    {
        ImGui::TextDisabled("Type to search across all categories.");
        ImGui::EndPopup();
        return;
    }

    // Lowercase the filter once for the case-insensitive substring match.
    std::string needle;
    needle.reserve(m_AddFilter.size());
    for (char c : m_AddFilter)
        needle += (char)std::tolower((unsigned char)c);

    // Two-pass: collect matches first, then render. Lets us clamp the
    // highlight index against the actual count before drawing the highlighted
    // row, and lets Enter pick the right entry without tracking during draw.
    constexpr size_t kMaxResults = 50;
    std::vector<const std::string*> matches;
    matches.reserve(kMaxResults);
    size_t totalMatches = 0;
    std::string lowerName;

    for (const auto& proto : NodeRegistry::Get().All())
    {
        lowerName.assign(proto->className);
        for (char& c : lowerName)
            c = (char)std::tolower((unsigned char)c);
        if (lowerName.find(needle) == std::string::npos)
            continue;

        ++totalMatches;
        if (matches.size() < kMaxResults)
            matches.push_back(&proto->className);
    }

    // Apply nav and clamp.
    m_AddHighlightedIndex += navDelta;
    if (matches.empty())
        m_AddHighlightedIndex = 0;
    else
        m_AddHighlightedIndex = std::clamp(m_AddHighlightedIndex, 0, (int)matches.size() - 1);

    for (size_t i = 0; i < matches.size(); ++i)
    {
        const bool highlighted = ((int)i == m_AddHighlightedIndex);
        if (ImGui::Selectable(matches[i]->c_str(), highlighted))
        {
            m_Graph->Execute(std::make_unique<AddNodeCmd>(*matches[i], m_AddPopupCanvasPos));
            m_bNeedsSync = true;
            ImGui::CloseCurrentPopup();
        }
        // Keep the highlighted row visible while the user nav-arrows up/down.
        if (highlighted && navDelta != 0)
            ImGui::SetScrollHereY(0.5f);
        // Tooltip for hover (mouse only — won't fire from nav).
        if (ImGui::IsItemHovered())
        {
            const PrototypeNode* p = NodeRegistry::Get().Find(*matches[i]);
            if (p && !p->description.empty())
                ImGui::SetTooltip("%s", p->description.c_str());
        }
    }

    if (matches.empty())
    {
        ImGui::TextDisabled("No matches.");
    }
    else if (totalMatches > kMaxResults)
    {
        ImGui::Separator();
        ImGui::TextDisabled("%zu more — refine search",
                            totalMatches - kMaxResults);
    }

    if (enterPressed && !matches.empty())
    {
        m_Graph->Execute(std::make_unique<AddNodeCmd>(
            *matches[m_AddHighlightedIndex], m_AddPopupCanvasPos));
        m_bNeedsSync = true;
        ImGui::CloseCurrentPopup();
    }

    ImGui::EndPopup();
}
