#include "EditTool.h"

namespace EditTools
{

class SelectTool : public EditTool
{
public:
    SelectTool(EditToolManager* pMgr);
    ~SelectTool();

    // EditTool
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize);
};

} // namespace EditTools
