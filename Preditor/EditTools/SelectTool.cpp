#include "SelectTool.h"

EditTools::SelectTool::SelectTool(EditToolManager* pMgr)
    : EditTool(pMgr)
{
}

EditTools::SelectTool::~SelectTool()
{
}

EEditToolResult EditTools::SelectTool::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    CryLog("SelectTool::OnLeftMouseClick {} {}", clickPos.x, clickPos.y);
    return EEditToolResult::Passthrough;
}
