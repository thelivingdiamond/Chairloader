#include <WindowManager/WindowManager.h>
#include <Preditor/FlowgraphEditor/IFlowgraphEditor.h>
#include "FlowgraphEditorWindow.h"

std::shared_ptr<ManagedWindow> IFlowgraphEditor::CreateMainWindow()
{
    return WindowManager::Get().Create<FlowgraphEditor::FlowgraphEditorWindow>();
}