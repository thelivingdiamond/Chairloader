#include <ImGuizmo/ImGuizmo.h>
#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/IObjectManipulator.h>
#include <Preditor/SceneEditor/SelectionManager.h>
#include "EditToolManager.h"
#include "MoveTool.h"

Matrix44 ToImGuizmo(const Matrix44& src)
{
    Matrix44 dest;

    for (auto row = 0; row < 4; row++)
    {
        for (auto col = 0; col < 4; col++)
            dest[row * 4 + col] = src[col * 4 + row];
    }

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

void Perspective(float fovyInDegrees, float aspectRatio, float znear, float zfar, float* m16)
{
    float ymax, xmax;
    ymax = znear * tanf(fovyInDegrees * 3.141592f / 180.0f);
    xmax = ymax * aspectRatio;
    Frustum(-xmax, xmax, -ymax, ymax, znear, zfar, m16);
}

EditTools::MoveTool::MoveTool(EditToolManager* pMgr)
    : EditTool(pMgr)
{
}

EditTools::MoveTool::~MoveTool()
{
}

void EditTools::MoveTool::DrawViewport(const Vec4& bounds, const Matrix44& projMat, const Matrix44& viewMat)
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
        Matrix44 projMat2 = projMat.GetTransposed();
        Matrix44 viewMat2 = viewMat.GetTransposed();
        Matrix44 objectTM = pManip->GetObjectWorldTM(activeObj).GetTransposed();

        // projMat2.m32 = -1 * projMat2.m32;
        Matrix44 projMat2_compare = projMat.GetTransposed();
        Perspective(90 / 2.0f, 1439.0f / 862.0f, 0.250f, 1024.0f, projMat2.GetData());

        ImGuizmo::Manipulate(
            viewMat2.GetData(),
            projMat2.GetData(),
            ImGuizmo::TRANSLATE,
            ImGuizmo::WORLD,
            objectTM.GetData());

        pManip->SetObjectWorldTM(activeObj, Matrix34(objectTM.GetTransposed()));
    }
}

EEditToolResult EditTools::MoveTool::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    if (ImGuizmo::IsOver())
        return EEditToolResult::Handled;
    else
        return EEditToolResult::Passthrough;
}
