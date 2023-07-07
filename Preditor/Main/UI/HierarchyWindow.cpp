#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include "UI/HierarchyWindow.h"

Main::HierarchyWindow::HierarchyWindow()
{
	SetTitle("Hierarchy");
	SetPersistentID("Hierarchy");
	SetCloseable(true);
	SetDestroyOnClose(false);
}

void Main::HierarchyWindow::ShowContents()
{
	ISceneEditor* pEditor = gPreditor->pSceneEditorManager->GetEditor();

	if (!pEditor)
	{
		ImGui::TextDisabled("(No editor loaded)");
		return;
	}

	pEditor->ShowHierarchy();
}
