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

    //! ImGui ID for use with BeginTabItem — title with a unique-per-instance suffix
    //! so multiple tabs of the same file don't collide.
    const std::string& GetImGuiId() const { return m_ImGuiId; }

    bool IsClosing() const { return m_bClosing; }
    void MarkForClose() { m_bClosing = true; }

    void ShowContents();

private:
    std::string m_Title;
    std::string m_ImGuiId;
    std::unique_ptr<Flowgraph> m_Graph;
    ax::NodeEditor::EditorContext* m_pContext = nullptr;
    bool m_bFirstFrame = true;
    bool m_bClosing = false;
};

} // namespace FlowgraphEditor
