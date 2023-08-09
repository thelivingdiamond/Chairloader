#include <Preditor/Viewport/IViewportWindow.h>
#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/IViewportHandler.h>
#include <Preditor/SceneEditor/SelectionManager.h>
#include <Preditor/Input/IPreditorInput.h>
#include "EditToolManager.h"
#include "SelectTool.h"

EditTools::SelectTool::SelectTool(EditToolManager* pMgr)
    : EditTool(pMgr)
{
    m_pAppendKey = gPreditor->pInput->FindAction("select_tool.append");
}

EditTools::SelectTool::~SelectTool()
{
}

EEditToolResult EditTools::SelectTool::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    ISceneEditor* pEditor = GetManager()->GetEditor();
    SelectionManager* pSel = pEditor->GetSelection();
    bool append = m_pAppendKey->IsHeldDown();

    if (!append)
    {
        // Clear existing selection
        pSel->ClearSelection();
    }
    else
    {
        // Validate before continuing
        pSel->ValidateSelection();
    }

    ViewportRaycastInfo rc = gPreditor->pViewportWindow->GetRayForMouse(clickPos, vpSize);
    SceneObjectId activeObjId = pSel->GetActiveObject();
    SceneObjectId objId = pEditor->GetViewport()->Raycast(rc);

    if (objId != INVALID_SCENE_OBJECT)
    {
        if (append)
        {
            // Toggle selection
            if (pSel->IsSelected(objId))
            {
                // Make active if inactive, deselect if active
                if (activeObjId == objId)
                    pSel->RemoveFromSelection(objId);
                else
                    pSel->AddToSelection(objId, true);
            }
            else
            {
                pSel->AddToSelection(objId, true);
            }
        }
        else
        {
            // Select the object
            pSel->AddToSelection(objId);
        }

        return EEditToolResult::Handled;
    }

    return EEditToolResult::Passthrough;
}
