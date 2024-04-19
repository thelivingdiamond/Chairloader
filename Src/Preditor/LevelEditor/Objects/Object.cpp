#include <Prey/CryMath/Cry_GeoIntersect.h>
#include <Preditor/SceneEditor/IViewportHandler.h>
#include "Objects/Object.h"
#include "RayIntersectInfo.h"

LevelEditor::Object::Object()
{
    static ObjectTypeInfo sTypeInfo
    {
        EObjectType::Object,
        "Object",
        "Object",
    };

    SetType(sTypeInfo);
}

LevelEditor::Object::~Object()
{
    // Destroy components while the object is still alive
    m_pTransform.reset();
}

void LevelEditor::Object::SetName(const std::string& name)
{
    m_ObjectName = name;
}

void LevelEditor::Object::SetSelfVisible(bool state)
{
    m_IsSelfVisible = state;
}

void LevelEditor::Object::Init(XmlNodeRef objectNode)
{
    SetName(objectNode->getAttr("Name"));

    m_pTransform = AddComponent<Transform>();
    m_pTransform->Init(objectNode);
}

void LevelEditor::Object::ShowInspector()
{
    ImGui::PushTextWrapPos(0.0f);

    if (Inspector::Begin(GetTypeInfo().displayName))
    {
        ShowInspectorSelf();
        Inspector::End();
    }

    ShowInspectorComponents();
    ImGui::PopTextWrapPos();
}

void LevelEditor::Object::ShowInspectorSelf()
{
    ImGui::Text("Name: %s", GetName().c_str());
    ImGui::Text("ID: %llu", GetObjectId());
}

void LevelEditor::Object::ShowInspectorComponents()
{
    m_Components.InvokeOnAll<&Component::ShowInspector>();
}

void LevelEditor::Object::OnTransformChanged(unsigned nWhyFlags)
{
    m_Components.InvokeOnAll<&Component::OnTransformChanged>(nWhyFlags);
}

void LevelEditor::Object::OnEnterPlayMode()
{
    m_Components.InvokeOnAll<&Component::OnEnterPlayMode>();
}

void LevelEditor::Object::OnExitPlayMode()
{
    m_Components.InvokeOnAll<&Component::OnExitPlayMode>();
}

bool LevelEditor::Object::IntersectRay(const ViewportRaycastInfo& ray, RayIntersectInfo& intersect)
{
    // Intersect with a small OBB
    const Matrix34& worldTM = GetTransform()->GetWorldTM();
    OBB obb = OBB::CreateOBB(Matrix33(worldTM), Vec3(0.25f), Vec3(ZERO));

    Vec3 hitPos;
    if (Intersect::Ray_OBB(ray.ray, worldTM.GetTranslation(), obb, hitPos) == 0x01)
    {
        intersect.hitPosition = hitPos;
        return true;
    }

    return false;
}

void LevelEditor::Object::DrawSelection(bool isActive)
{
    // Not implemented
}

void LevelEditor::Object::SetType(const ObjectTypeInfo& typeInfo)
{
    typeInfo.Validate();
    m_pTypeInfo = &typeInfo;
}

void LevelEditor::Object::InternalInit(SceneObjectId id)
{
    m_ObjectId = id;
}
