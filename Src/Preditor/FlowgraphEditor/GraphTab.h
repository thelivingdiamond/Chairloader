#pragma once
#include <ImGuiNodeEditor/imgui_node_editor.h>
#include "Model/Flowgraph.h"

namespace FlowgraphEditor
{

//! One open graph viewport: owns an imgui-node-editor context and one Flowgraph.
class GraphTab
{
public:
    explicit GraphTab(std::unique_ptr<Flowgraph> graph, std::string title);
    ~GraphTab();

    GraphTab(const GraphTab&) = delete;
    GraphTab& operator=(const GraphTab&) = delete;

    const std::string& GetTitle() const { return m_Title; }
    const std::string& GetImGuiId() const { return m_ImGuiId; }

    Flowgraph* GetGraph() const { return m_Graph.get(); }
    ax::NodeEditor::EditorContext* GetEditorContext() const { return m_pContext; }

    bool IsClosing() const { return m_bClosing; }
    void MarkForClose() { m_bClosing = true; }

    void ShowContents();

private:
    void SyncAllNodePositions();
    void DetectAndEmitMoves();
    void FinalizeDragSession();
    void HandleNewLinks();
    void HandleDelete();
    void HandleKeyboard();

    //! Returns the editor-selected node ids in this tab. Empty if nothing
    //! selected or the editor context isn't ready.
    std::vector<int64_t> GetSelectedNodeIds();

    void CopySelection();
    void CutSelection();
    void PasteFromClipboard();
    void DuplicateSelection();

    std::string m_Title;
    std::string m_ImGuiId;
    std::unique_ptr<Flowgraph> m_Graph;
    ax::NodeEditor::EditorContext* m_pContext = nullptr;

    // Push model positions into the canvas next time we draw. Set on first frame
    // and after Undo/Redo so the visuals catch up with model mutations.
    bool m_bNeedsSync = true;

    // Drag-session bookkeeping. Records each moving node's start-of-drag position
    // so a multi-frame drag becomes a single composite undo entry on release.
    bool m_bDragInProgress = false;
    std::map<int64_t, ImVec2> m_DragStartPositions;

    bool m_bClosing = false;
};

} // namespace FlowgraphEditor
