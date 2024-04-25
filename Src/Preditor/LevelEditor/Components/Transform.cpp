#include <EditorControls.h>
#include "Components/Transform.h"
#include "Objects/Object.h"
#include "Utils/AffineParts.h"

LevelEditor::Transform::Transform()
    : m_ThisItemInParent(this)
{
    CalcLocalTM();
    CalcWorldTM();
}

LevelEditor::Transform::~Transform()
{
    if (m_pParent)
    {
        m_pParent->m_Children.remove(m_ThisItemInParent);
        m_pParent = nullptr;
    }

    for (Transform& child : m_Children)
    {
        CRY_ASSERT(child.GetParent() == this);
        child.SetParent(nullptr);
    }
}

void LevelEditor::Transform::SetPos(const Vec3& pos)
{
    m_Pos = pos;
    InvalidateTM(ENTITY_XFORM_POS);
}

void LevelEditor::Transform::SetRot(const Quat& rot)
{
    m_Rot = rot;
    InvalidateTM(ENTITY_XFORM_ROT);
}

void LevelEditor::Transform::SetScale(const Vec3& scale)
{
    m_Scale = scale;
    InvalidateTM(ENTITY_XFORM_SCL);
}

void LevelEditor::Transform::SetPosRotScale(const Vec3& pos, const Quat& rot, const Vec3& scale)
{
    m_Pos = pos;
    m_Rot = rot;
    m_Scale = scale;
    InvalidateTM(ENTITY_XFORM_POS | ENTITY_XFORM_ROT | ENTITY_XFORM_SCL);
}

void LevelEditor::Transform::SetLocalTM(const Matrix34& tm)
{
    if (tm.IsOrthonormal())
    {
        SetPosRotScale(tm.GetTranslation(), Quat(tm), Vec3(1.0f));
    }
    else
    {
        AffineParts affineParts;
        affineParts.SpectralDecompose(tm);

        SetPosRotScale(affineParts.pos, affineParts.rot, affineParts.scale);
    }
}

void LevelEditor::Transform::SetWorldTM(const Matrix34& tm)
{
    Transform* pParent = GetParent();

    if (pParent)
    {
        Matrix34 localTM = pParent->GetWorldTM().GetInverted() * tm;
        SetLocalTM(localTM);
    }
    else
    {
        SetLocalTM(tm);
    }
}

void LevelEditor::Transform::SetParent(Transform* pNewParent, bool suppressTransform)
{  
    if (pNewParent == this)
    {
        CryError("Object {}: Attempted to set self as parent", GetObject()->GetName());
        return;
    }

    if (m_pParent == pNewParent)
        return;

    if (m_pParent)
    {
        // Remove from the current parent
        m_pParent->m_Children.remove(m_ThisItemInParent);
        m_pParent = nullptr;
    }

    if (pNewParent)
    {
        // Add to the foster parent
        pNewParent->m_Children.add(m_ThisItemInParent);
        m_pParent = pNewParent;

#ifdef DEBUG_BUILD
        // Alabama check
        for (Transform& child : pNewParent->m_Children)
        {
            CRY_ASSERT(child.GetParent() == pNewParent);
        }
#endif
    }

#ifdef DEBUG_BUILD
    // Alabama check
    for (Transform& child : m_Children)
    {
        CRY_ASSERT(child.GetParent() == this);
    }
#endif

    if (!suppressTransform)
        InvalidateTM(ENTITY_XFORM_FROM_PARENT);
}


void LevelEditor::Transform::InvalidateTM(unsigned nWhyFlags)
{
    if (nWhyFlags & ENTITY_XFORM_FROM_PARENT)
        nWhyFlags |= ENTITY_XFORM_POS | ENTITY_XFORM_ROT | ENTITY_XFORM_SCL;

    CalcLocalTM();
    CalcWorldTM();
    GetObject()->OnTransformChanged(nWhyFlags);

    for (Transform& child : m_Children)
    {
        CRY_ASSERT(child.GetParent() == this);
        child.InvalidateTM(ENTITY_XFORM_FROM_PARENT);
    }
}

void LevelEditor::Transform::Init(XmlNodeRef objectNode)
{
    Vec3 pos(ZERO);
    Quat rot(IDENTITY);
    Vec3 scale(1, 1, 1);

    XmlString szPos, szRotate, szScale;

    if (objectNode->getAttr("Pos", szPos))
    {
        if (sscanf(szPos, "%f,%f,%f", &pos.x, &pos.y, &pos.z) != 3)
            CryError("[{}] Invalid Pos: {}", GetObject()->GetName(), szPos);
    }

    if (objectNode->getAttr("Rotate", szRotate))
    {
        if (sscanf(szRotate, "%f,%f,%f,%f", &rot.w, &rot.v.x, &rot.v.y, &rot.v.z) != 4)
            CryError("[{}] Invalid Rotate: {}", GetObject()->GetName(), szRotate);
    }

    if (objectNode->getAttr("Scale", szScale))
    {
        if (sscanf(szScale, "%f,%f,%f", &scale.x, &scale.y, &scale.z) != 3)
            CryError("[{}] Invalid Scale: {}", GetObject()->GetName(), szScale);
    }

    SetPosRotScale(pos, rot, scale);
}

void LevelEditor::Transform::ShowInspector()
{
    if (Inspector::Begin("Transform"))
    {
        Vec3 pos = GetPos();
        Quat rot = GetRot();
        Vec3 scale = GetScale();

        ImGui::Text("Tip: Right-Click to copy");

        if (EditorControls::DragVec3("Position", &pos))
            SetPos(pos);

        if (EditorControls::DragQuat("Rotation (PRY)", &rot))
            SetRot(rot);

        if (EditorControls::DragVec3("Scale", &scale))
            SetScale(scale);

        Inspector::End();
    }
}

void LevelEditor::Transform::CalcLocalTM()
{
    m_Mat =
        Matrix34::CreateScale(m_Scale, m_Pos) *
        Matrix34(m_Rot);
}

void LevelEditor::Transform::CalcWorldTM()
{
    if (m_pParent)
        m_WMat = m_pParent->m_WMat * m_Mat;
    else
        m_WMat = m_Mat;
}
