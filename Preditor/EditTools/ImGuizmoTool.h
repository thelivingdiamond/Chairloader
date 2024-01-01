#include <ImGuizmo/ImGuizmo.h>
#include "EditTool.h"

struct IKeyAction;

namespace EditTools
{

class ImGuizmoTool : public EditTool
{
public:
    ImGuizmoTool(EditToolManager* pMgr, ImGuizmo::OPERATION operation, const Vec3& snap);
    ~ImGuizmoTool();

    // EditTool
    virtual void DrawViewport(const Vec4& bounds, const CCamera& camera) override;
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize);

private:
    ImGuizmo::OPERATION m_Op = (ImGuizmo::OPERATION)0;
    Vec3 m_Snap = Vec3(ZERO);
    IKeyAction* m_pSnapKey = nullptr;
};

} // namespace EditTools
