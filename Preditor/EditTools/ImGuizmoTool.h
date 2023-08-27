#include <ImGuizmo/ImGuizmo.h>
#include "EditTool.h"

struct IKeyAction;

namespace EditTools
{

class ImGuizmoTool : public EditTool
{
public:
    ImGuizmoTool(EditToolManager* pMgr, ImGuizmo::OPERATION operation);
    ~ImGuizmoTool();

    // EditTool
    virtual void DrawViewport(const Vec4& bounds, const CCamera& camera) override;
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize);

private:
    ImGuizmo::OPERATION m_Op = (ImGuizmo::OPERATION)0;
    IKeyAction* m_pAppendKey = nullptr;
};

} // namespace EditTools
