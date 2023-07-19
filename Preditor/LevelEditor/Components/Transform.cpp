#include "Components/Transform.h"
#include "Objects/Object.h"

LevelEditor::Transform::Transform()
{
    CalcLocalTM();
    CalcWorldTM();
}

LevelEditor::Transform::~Transform()
{
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

void LevelEditor::Transform::InvalidateTM(unsigned nWhyFlags)
{
    if (nWhyFlags & ENTITY_XFORM_FROM_PARENT)
        nWhyFlags |= ENTITY_XFORM_POS | ENTITY_XFORM_ROT | ENTITY_XFORM_SCL;

    CalcLocalTM();
    CalcWorldTM();
    GetObject()->OnTransformChanged(nWhyFlags);
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
        if (sscanf(szRotate, "%f,%f,%f,%f", &rot.v.x, &rot.v.y, &rot.v.z, &rot.w) != 4)
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
        Ang3 angles = RAD2DEG(Ang3(GetRot()));
        Vec3 scale = GetScale();

        static bool highPrecision = false;
        ImGui::Checkbox("High precision", &highPrecision);
        const char* format = highPrecision ? "%.8f" : "%.2f";

        ImGui::InputFloat3("Position", &pos.x, format);
        if (ImGui::IsItemDeactivatedAfterEdit()) {
            SetPos(pos);
        }
        if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
            ImGui::SetClipboardText(fmt::format("{:.8f},{:.8f},{:.8f}", pos.x, pos.y, pos.z).c_str());
        }

        ImGui::InputFloat3("Rotation (PRY)", &angles.x, format);
        if (ImGui::IsItemDeactivatedAfterEdit()) {
            SetRot(Quat(DEG2RAD(angles)));
        }
        if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
            ImGui::SetClipboardText(fmt::format("{:.8f},{:.8f},{:.8f}", angles.x, angles.y, angles.z).c_str());
        }

        if (ImGui::BeginPopup("Copy Rotation")) {
            Quat rot = GetRot();

            if (ImGui::MenuItem("Copy as Quat (XYZW)"))
                ImGui::SetClipboardText(fmt::format("{:.8f},{:.8f},{:.8f},{:.8f}", rot.w, rot.v.x, rot.v.y, rot.v.z).c_str());

            if (ImGui::MenuItem("Copy as Quat (WXYZ)"))
                ImGui::SetClipboardText(fmt::format("{:.8f},{:.8f},{:.8f},{:.8f}", rot.v.x, rot.v.y, rot.v.z, rot.w).c_str());

            if (ImGui::MenuItem("Copy as P,R,Y"))
                ImGui::SetClipboardText(fmt::format("{:.8f},{:.8f},{:.8f}", angles.x, angles.y, angles.z).c_str());

            ImGui::EndPopup();
        }
        ImGui::InputFloat3("Scale", &scale.x, format);
        if (ImGui::IsItemDeactivatedAfterEdit()) {
            SetScale(scale);
        }
        if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
            ImGui::SetClipboardText(fmt::format("{:.8f},{:.8f},{:.8f}", scale.x, scale.y, scale.z).c_str());
        }

        if (scale.x != scale.y || scale.x != scale.z) {
            ImGui::TextWrapped("Note: non-uniform scaling is not supported well");
        }

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
    // TODO 2023-07-16: Transform hierarchy
    m_WMat = m_Mat;
}
