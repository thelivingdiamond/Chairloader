#pragma once
#include "EditTool.h"

namespace EditTools
{

class CursorTool : public EditTool
{
public:
    CursorTool(EditToolManager* pMgr);
    ~CursorTool();

    // EditTool
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize);
};

} // namespace EditTools
