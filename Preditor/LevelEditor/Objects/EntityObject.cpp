#include <Prey/CryMath/Cry_GeoIntersect.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Preditor/SceneEditor/IViewportHandler.h>
#include "Components/EntityArchetypeComponent.h"
#include "Components/EntityScriptComponent.h"
#include "Components/AreaProxyComponent.h"
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

    if (!m_pEntityClass)
    {
        CryError("[{}] Can't respawn entity: class is null", GetName());
        return;
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

    // TODO 2024-01-20: params.sLayerName
    params.entityNode = m_XmlData;

    params.sName = GetName().c_str();

    params.nFlags = 0;
    params.nFlags |= ENTITY_FLAG_UNREMOVABLE; // Level entities can't be removed
    params.nFlags |= m_SpawnInfo.GetFlags();

    params.nFlagsExtended = 0;
    params.nFlagsExtended |= m_SpawnInfo.GetFlagsExtended();

    params.vPosition = GetTransform()->GetPos();
    params.qRotation = GetTransform()->GetRot();

    // TODO 2024-01-20: Set legacy entity flags

    // Spawn the entity
    CRY_ASSERT(!m_pEntity);
    m_pEntity = pEntSystem->SpawnEntity(params);

    if (!m_pEntity)
    {
        CryError("[{}] Failed to spawn the entity", GetName());
        return;
    }

    // Save new EntityId
    m_EntityId = m_pEntity->GetId();

    // TODO 2024-01-20: Copy properties
    // TODO 2024-01-20: Init light
    // TODO 2024-01-20: Set parent
    // TODO 2024-01-20: Update attachments

    // Now initialize entity
    if (!gEnv->pEntitySystem->InitEntity(m_pEntity, params))
    {
        CryError("[{}] Failed to initialize the entity", GetName());
        m_pEntity = nullptr;
        return;
    }

    // Set parent
    if (Transform* pParentTr = GetTransform()->GetParent())
    {
        if (pParentTr->GetObject()->IsEntity())
        {
            IEntity* pParentEnt = static_cast<EntityObject*>(pParentTr->GetObject())->GetEntity();
            CRY_ASSERT_MESSAGE(pParentEnt, "Parent entity must be initialized");
            pParentEnt->AttachChild(m_pEntity);
        }
        else
        {
            CryError("[{}] Object parent {} is not an entity", GetName(), pParentTr->GetObject()->GetName());
        }
    }

    // TODO 2024-01-20: Update entity links
    ApplyTransformToEntity();
    // TODO 2024-01-20: Update visibility
    // TODO 2024-01-20: Apply material
    // TODO 2024-01-20: Update render flags

    AABB entityLocalBounds;
    m_pEntity->GetLocalBounds(entityLocalBounds);
    GetBBox()->SetLocalBounds(entityLocalBounds);

    // TODO 2024-01-20: Init flow graph
    // TODO 2024-01-20: Set physics state
}

void LevelEditor::EntityObject::ApplyTransformToEntity(unsigned nWhyFlags)
{
    if (m_pEntity)
    {
        Transform* t = GetTransform();
        m_pEntity->SetPosRotScale(t->GetPos(), t->GetRot(), t->GetScale(), nWhyFlags | ENTITY_XFORM_EDITOR);
    }
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

    m_pScript = AddComponent<EntityScriptComponent>();
    m_pScript->SetEntityClass(m_pEntityClass);

    m_SpawnInfo.LoadFromXml(objectNode);

    if (objectNode->findChild("Area"))
    {
        m_pAreaProxy = AddComponent<AreaProxyComponent>();
        m_pAreaProxy->LoadFromXml(objectNode);
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
