#include <WindowManager/WindowManager.h>
#include <Preditor/FlowgraphEditor/IFlowgraphEditor.h>
#include "FlowgraphEditorWindow.h"
#include "UI/GraphBrowserWindow.h"
#include "UI/GraphTokensWindow.h"
#include "UI/NodePaletteWindow.h"
#include "UI/PropertyInspectorWindow.h"

std::shared_ptr<ManagedWindow> IFlowgraphEditor::CreateMainWindow()
{
    return WindowManager::Get().Create<FlowgraphEditor::FlowgraphEditorWindow>();
}

std::shared_ptr<ManagedWindow> IFlowgraphEditor::CreateBrowserWindow()
{
    return WindowManager::Get().Create<FlowgraphEditor::GraphBrowserWindow>();
}

std::shared_ptr<ManagedWindow> IFlowgraphEditor::CreatePaletteWindow()
{
    return WindowManager::Get().Create<FlowgraphEditor::NodePaletteWindow>();
}

std::shared_ptr<ManagedWindow> IFlowgraphEditor::CreateInspectorWindow()
{
    return WindowManager::Get().Create<FlowgraphEditor::PropertyInspectorWindow>();
}

std::shared_ptr<ManagedWindow> IFlowgraphEditor::CreateTokensWindow()
{
    return WindowManager::Get().Create<FlowgraphEditor::GraphTokensWindow>();
}
