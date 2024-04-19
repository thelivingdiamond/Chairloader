#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include <WindowManager/WindowManager.h>
#include "ToolSelectionWindow.h"
#include "EditToolManager.h"

std::shared_ptr<ManagedWindow> IEditToolManager::CreateToolSelectionWindow()
{
    return WindowManager::Get().Create<EditTools::ToolSelectionWindow>();
}

EditTools::ToolSelectionWindow::ToolSelectionWindow()
{
    SetTitle("Tools");
    SetPersistentID("EditToolSel");
    SetDestroyOnClose(false);
}

EditTools::ToolSelectionWindow::~ToolSelectionWindow()
{
}

void EditTools::ToolSelectionWindow::ShowContents()
{
    ISceneEditor* pEditor = gPreditor->pSceneEditorManager->GetEditor();

    if (!pEditor)
    {
        ImGui::TextDisabled("(No editor loaded)");
        return;
    }

    auto pToolMgr = static_cast<EditToolManager*>(pEditor->GetToolManager());
    pToolMgr->ShowSelectionUI();
}
