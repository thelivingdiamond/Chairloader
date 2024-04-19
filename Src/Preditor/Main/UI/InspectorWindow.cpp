#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include "InspectorWindow.h"

Main::InspectorWindow::InspectorWindow()
{
	SetTitle("Inspector");
	SetPersistentID("Inspector");
	SetCloseable(true);
	SetDestroyOnClose(false);
}

void Main::InspectorWindow::ShowContents()
{
	ISceneEditor* pEditor = gPreditor->pSceneEditorManager->GetEditor();

	if (!pEditor)
	{
		ImGui::TextDisabled("(No editor loaded)");
		return;
	}

	pEditor->ShowInspector();
}
