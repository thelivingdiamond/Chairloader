#include <Prey/CryMath/Cry_GeoIntersect.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Preditor/SceneEditor/IViewportHandler.h>
#include "Components/EntityArchetypeComponent.h"
#include "Objects/EntityObject.h"
#include "RayIntersectInfo.h"

LevelEditor::EntityObject::EntityObject()
{
    static ObjectTypeInfo sTypeInfo
    {
        EObjectType::Entity,
        "EntityObject",
        "Entity Object",
    };

    SetType(sTypeInfo);
}

LevelEditor::EntityObject::~EntityObject()
{
}

void LevelEditor::EntityObject::RespawnEntity()
{
    IEntitySystem* pEntSystem = gEnv->pEntitySystem;

    if (m_pEntity)
    {
        // Destroy existing entity
        m_pEntity->ClearFlags(ENTITY_FLAG_UNREMOVABLE);
        pEntSystem->RemoveEntity(m_pEntity->GetId(), true);
        m_pEntity = nullptr;
    }

    // Make sure ID is not used
    if (m_EntityId != INVALID_ENTITYID && pEntSystem->IsIDUsed(m_EntityId))
    {
        CryWarning("[{}] Entity ID {} is in use by some other entity. A different one will be generated.", GetName(), m_EntityId);
        m_EntityId = INVALID_ENTITYID;
    }

    // Set up spawn params
    SEntitySpawnParams params;
    params.id = m_EntityId;
    params.guid = m_EntityGuid;
    params.pClass = m_pEntityClass;

    if (m_pArchetype)
        params.pArchetype = m_pArchetype->GetArchetype();

    // params.sLayerName
    params.entityNode = m_XmlData;

    params.sName = GetName().c_str();
    params.nFlags = 0;
    params.vPosition = GetTransform()->GetPos();
    params.qRotation = GetTransform()->GetRot();

    // Spawn the entity
    CRY_ASSERT(!m_pEntity);
    m_pEntity = pEntSystem->SpawnEntity(params);

    if (m_pEntity)
    {
        SetUpEntity(false);
    }
    else
    {
        CryError("[{}] Failed to spawn the entity", GetName());
    }
}

void LevelEditor::EntityObject::ApplyTransformToEntity(unsigned nWhyFlags)
{
    if (m_pEntity)
    {
        Transform* t = GetTransform();
        m_pEntity->SetPosRotScale(t->GetPos(), t->GetRot(), t->GetScale(), nWhyFlags | ENTITY_XFORM_EDITOR);
    }
}

void LevelEditor::EntityObject::DetachFromGame()
{
    Object::DetachFromGame();
    m_pEntity = nullptr;
}

void LevelEditor::EntityObject::Init(XmlNodeRef objectNode)
{
    Object::Init(objectNode);
    m_XmlData = objectNode->clone();

    XmlString archetypeName;
    objectNode->getAttr("Archetype", archetypeName);
    objectNode->getAttr("EntityClass", m_EntityClassName);
    objectNode->getAttr("EntityId", m_EntityId);
    objectNode->getAttrHex("EntityGuid", m_EntityGuid);

    m_pEntityClass = gEnv->pEntitySystem->GetClassRegistry()->FindClass(m_EntityClassName);
    if (!m_pEntityClass)
    {
        CryError("[{}] Class not found: {}", GetName(), m_EntityClassName);
    }

    if (!archetypeName.empty())
    {
        m_pArchetype = AddComponent<EntityArchetypeComponent>();

        if (!m_pArchetype->SetArchetype(archetypeName))
        {
            CryError("[{}] Archetype not found: {}", GetName(), archetypeName);
        }
    }

    if (!FindExistingEntity())
    {
        CryWarning("[{}] Respawning missing entity", GetName());
        RespawnEntity();
    }
}

void LevelEditor::EntityObject::ShowInspectorSelf()
{
    Object::ShowInspectorSelf();
    ImGui::Text("EntityID: %u", m_EntityId);
    ImGui::Text("Entity: %s", m_pEntity ? "spawned" : "not spawned");

    if (ImGui::Button("Respawn"))
        RespawnEntity();
}

void LevelEditor::EntityObject::OnTransformChanged(unsigned nWhyFlags)
{
    ApplyTransformToEntity();
    Object::OnTransformChanged(nWhyFlags);
}

void LevelEditor::EntityObject::OnEnterPlayMode()
{
    Object::OnEnterPlayMode();
    ApplyTransformToEntity();
}

void LevelEditor::EntityObject::OnExitPlayMode()
{
    Object::OnExitPlayMode();
    ApplyTransformToEntity();
}

bool LevelEditor::EntityObject::IntersectRay(const ViewportRaycastInfo& ray, RayIntersectInfo& intersect)
{
    if (!m_pEntity)
        return false;

    return IntersectOBB(ray, intersect);
}

void LevelEditor::EntityObject::DrawSelection(bool isActive)
{
    if (!m_pEntity)
        return;

    ColorB color = isActive ? SELECTION_ACTIVE_COLOR : SELECTION_COLOR;

    AABB aabb;
    m_pEntity->GetLocalBounds(aabb);
    gEnv->pAuxGeomRenderer->DrawAABB(aabb, GetTransform()->GetWorldTM(), false, color, eBBD_Faceted);
}

bool LevelEditor::EntityObject::FindExistingEntity()
{
    CRY_ASSERT_MESSAGE(!m_pEntity, "Entity already found");
    m_pEntity = gEnv->pEntitySystem->GetEntity(m_EntityId);

    if (m_pEntity)
    {
        // Found it
        SetUpEntity(true);
        return true;
    }
    else
    {
        CryError("[{}] Failed to find entity {}", GetName(), GetEntityId());
        return false;
    }
}

void LevelEditor::EntityObject::SetUpEntity(bool isExisting)
{
    // Mark this entity non destroyable.
    m_pEntity->AddFlags(ENTITY_FLAG_UNREMOVABLE);
}

bool LevelEditor::EntityObject::IntersectOBB(const ViewportRaycastInfo& ray, RayIntersectInfo& intersect)
{
    if (!m_pEntity)
        return false;

    const Matrix34& worldTM = GetTransform()->GetWorldTM();
    AABB aabb;
    m_pEntity->GetLocalBounds(aabb);

    OBB obb = OBB::CreateOBBfromAABB(Matrix33(worldTM), aabb);
    Vec3 hitPos;

    if (Intersect::Ray_OBB(ray.ray, worldTM.GetTranslation(), obb, hitPos) == 0x01)
    {
        intersect.hitPosition = hitPos;
        return true;
    }

    return false;
}
