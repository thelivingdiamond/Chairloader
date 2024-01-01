#include <Preditor/Input/IPreditorInput.h>
#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/IObjectManipulator.h>
#include <Preditor/SceneEditor/SelectionManager.h>
#include "EditToolManager.h"
#include "ImGuizmoTool.h"

namespace
{

/**
 * Right +X
 * Up +Y
 * Forward -Z
 */
const Matrix44 g_ImGuizmoBasis = Matrix44(
     1.0f,  0.0f,  0.0f,  0.0f,
     0.0f,  0.0f,  1.0f,  0.0f,
     0.0f, -1.0f,  0.0f,  0.0f,
     0.0f,  0.0f,  0.0f,  1.0f
);

const Matrix44 g_ImGuizmoBasisInv = g_ImGuizmoBasis.GetInverted();

Matrix44 CryToImGuizmo(const Matrix44& src)
{
    Matrix44 dest = g_ImGuizmoBasis * src * g_ImGuizmoBasisInv;
    dest.Transpose();
    return dest;
}

Matrix44 ImGuizmoToCry(const Matrix44& src)
{
    Matrix44 dest = src;
    dest.Transpose();
    dest = g_ImGuizmoBasisInv * dest * g_ImGuizmoBasis;
    return dest;
}

void Frustum(float left, float right, float bottom, float top, float znear, float zfar, float* m16)
{
    float temp, temp2, temp3, temp4;
    temp = 2.0f * znear;
    temp2 = right - left;
    temp3 = top - bottom;
    temp4 = zfar - znear;
    m16[0] = temp / temp2;
    m16[1] = 0.0;
    m16[2] = 0.0;
    m16[3] = 0.0;
    m16[4] = 0.0;
    m16[5] = temp / temp3;
    m16[6] = 0.0;
    m16[7] = 0.0;
    m16[8] = (right + left) / temp2;
    m16[9] = (top + bottom) / temp3;
    m16[10] = (-zfar - znear) / temp4;
    m16[11] = -1.0f;
    m16[12] = 0.0;
    m16[13] = 0.0;
    m16[14] = (-temp * zfar) / temp4;
    m16[15] = 0.0;
}

void Perspective(float fovy, float aspectRatio, float znear, float zfar, float* m16)
{
    float ymax, xmax;
    ymax = znear * tanf(fovy);
    xmax = ymax * aspectRatio;
    Frustum(-xmax, xmax, -ymax, ymax, znear, zfar, m16);
}

void FrustumFromCamera(const CCamera& cam, float width, float height, float* m16)
{
    Perspective(0.5f * cam.GetFov(), width / height, cam.GetNearPlane(), cam.GetFarPlane(), m16);
}

} // namespace

EditTools::ImGuizmoTool::ImGuizmoTool(EditToolManager* pMgr, ImGuizmo::OPERATION operation, const Vec3& snap)
    : EditTool(pMgr)
{
    m_Op = operation;
    m_Snap = snap;
    m_pSnapKey = gPreditor->pInput->FindAction("transform_tools.snap");
}

EditTools::ImGuizmoTool::~ImGuizmoTool()
{
}

void EditTools::ImGuizmoTool::DrawViewport(const Vec4& bounds, const CCamera& camera)
{
    ImVec2 windowPos = ImGui::GetWindowPos();
    ImGuizmo::SetDrawlist();
    ImGuizmo::SetRect(
        windowPos.x + bounds.x,
        windowPos.y + bounds.y,
        bounds.z - bounds.x,
        bounds.w - bounds.y);

    ISceneEditor* pEditor = GetManager()->GetEditor();
    SelectionManager* pSel = pEditor->GetSelection();
    SceneObjectId activeObj = pSel->GetActiveObject();
    
    if (activeObj != INVALID_SCENE_OBJECT)
    {
        IObjectManipulator* pManip = pEditor->GetManipulator();
        Matrix44 pivotTransform(IDENTITY);

        if (GetManager()->IsPivotCenter())
        {
            // Get AABB center
            AABB aabb;
            pManip->GetObjectLocalBounds(activeObj, aabb);
            pivotTransform.SetTranslation(aabb.GetCenter());
        }

        Matrix44 viewMat = CryToImGuizmo(camera.GetViewMatrix());
        Matrix44 objectTM = CryToImGuizmo(pManip->GetObjectWorldTM(activeObj) * pivotTransform);

        Matrix44 projMat;
        FrustumFromCamera(camera, bounds.z - bounds.x, bounds.w - bounds.y, projMat.GetData());

        bool manipulated = ImGuizmo::Manipulate(
            viewMat.GetData(),
            projMat.GetData(),
            m_Op,
            GetManager()->IsWorldTransform() ? ImGuizmo::WORLD : ImGuizmo::LOCAL,
            objectTM.GetData(),
            nullptr, // deltaMatrix
            m_pSnapKey->IsHeldDown() ? &m_Snap.x : nullptr);

        if (manipulated)
            pManip->SetObjectWorldTM(activeObj, Matrix34(ImGuizmoToCry(objectTM) * pivotTransform.GetInverted()));
    }
}

EEditToolResult EditTools::ImGuizmoTool::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    if (ImGuizmo::IsOver())
        return EEditToolResult::Handled;
    else
        return EEditToolResult::Passthrough;
}
