#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include <Preditor/SceneEditor/SelectionManager.h>
#include <Preditor/Input/IPreditorInput.h>
#include "SelectionWindow.h"

Main::SelectionWindow::SelectionWindow()
{
	SetTitle("Selection");
	SetPersistentID("Selection");
	SetCloseable(true);
	SetDestroyOnClose(false);
}

void Main::SelectionWindow::ShowContents()
{
	ISceneEditor* pEditor = gPreditor->pSceneEditorManager->GetEditor();

	if (!pEditor)
	{
		ImGui::TextDisabled("(No editor loaded)");
		return;
	}

	SelectionManager* pSel = pEditor->GetSelection();

	if (pSel->GetList().empty())
	{
		ImGui::TextDisabled("No objects selected.");
	}
	else
	{
		if (ImGui::Button("Clear Selection"))
			pSel->ClearSelection();

		SceneObjectId activeObjId = pSel->GetActiveObject();
		SceneObjectId deselObjId = INVALID_SCENE_OBJECT;

		for (SceneObjectId objId : pSel->GetList())
		{
			char buf[128];
			const char* objName = pEditor->GetObjectName(objId);

			if (!objName)
				objName = "< invalid obj >";

			snprintf(buf, sizeof(buf), "%s (%llu)", objName, objId);

			ImGui::Selectable(buf, activeObjId == objId);

			if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
			{
				// Switch active object
				pSel->AddToSelection(objId, true);
			}
			
			if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
			{
				// Deselect the object
				// Do not call RemoveFromSelection while iterating the list!
				deselObjId = objId;
			}
		}

		if (deselObjId != INVALID_SCENE_OBJECT)
		{
			pSel->RemoveFromSelection(deselObjId);
			deselObjId = INVALID_SCENE_OBJECT;
		}
	}
}
