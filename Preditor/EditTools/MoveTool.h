#include "EditTool.h"

struct IKeyAction;

namespace EditTools
{

class MoveTool : public EditTool
{
public:
    MoveTool(EditToolManager* pMgr);
    ~MoveTool();

    // EditTool
    virtual void DrawViewport(const Vec4& bounds, const CCamera& camera) override;
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize);

private:
    IKeyAction* m_pAppendKey = nullptr;
};

} // namespace EditTools
