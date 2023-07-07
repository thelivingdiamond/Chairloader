#include "EditTool.h"

EditTools::EditTool::EditTool(EditToolManager* pMgr)
{
}

EditTools::EditTool::~EditTool()
{
}

void EditTools::EditTool::OnEnabled()
{
}

void EditTools::EditTool::OnDisabled()
{
}

EEditToolResult EditTools::EditTool::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    return EEditToolResult::Passthrough;
}

void EditTools::EditTool::SetActive(bool state)
{
    if (m_bIsActive == state)
        return;

    m_bIsActive = state;

    if (state)
        OnEnabled();
    else
        OnDisabled();
}
