#include "FlowgraphEditorWindow.h"

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

void FlowgraphEditor::FlowgraphEditorWindow::ShowContents()
{
    ImGui::TextUnformatted("Flowgraph Editor");
    ImGui::Separator();
}