#include <Preditor/Viewport/IViewportWindow.h>
#include <Preditor/SceneEditor/I3DCursor.h>
#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/IViewportHandler.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include "CursorTool.h"
#include "EditToolManager.h"

EditTools::CursorTool::CursorTool(EditToolManager* pMgr)
    : EditTool(pMgr)
{
}

EditTools::CursorTool::~CursorTool()
{
}

EEditToolResult EditTools::CursorTool::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    ISceneEditor* pEditor = GetManager()->GetEditor();
    ViewportRaycastInfo rc = gPreditor->pViewportWindow->GetRayForMouse(clickPos, vpSize);
    ViewportRaycastHit hit = pEditor->GetViewport()->Raycast(rc);

    if (hit.isHit)
    {
        gPreditor->pSceneEditorManager->Get3DCursor()->SetPos(hit.hitPos);
    }

    // Always handled so Select Tool doesn't change selection.
    return EEditToolResult::Handled;
}
