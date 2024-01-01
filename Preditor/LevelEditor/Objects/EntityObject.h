#pragma once
#include "Objects/Object.h"

namespace LevelEditor
{

class EntityArchetypeComponent;

//! Object type for entities.
class EntityObject : public Object
{
public:
    EntityObject();
    ~EntityObject();

    //! @returns the entity ID.
    EntityId GetEntityId() const { return m_EntityId; }

    //! @returns the entity if it is spawned.
    IEntity* GetEntity() const { return m_pEntity; }

    //! Respawns the entity.
    void RespawnEntity();

    //! Applies the object tranform to the entity.
    void ApplyTranformToEntity(unsigned nWhyFlags = 0);

    // Object
    virtual void Init(XmlNodeRef objectNode) override;
    virtual void ShowInspectorSelf() override;
    virtual void OnTransformChanged(unsigned nWhyFlags) override;
    virtual void OnEnterPlayMode() override;
    virtual void OnExitPlayMode() override;
    virtual bool IntersectRay(const ViewportRaycastInfo& ray, RayIntersectInfo& intersect) override;
    virtual void DrawSelection(bool isActive) override;

private:
    XmlString m_EntityClassName;
    IEntityClass* m_pEntityClass = nullptr;
    EntityId m_EntityId = INVALID_ENTITYID;
    EntityGUID m_EntityGuid = 0;
    XmlNodeRef m_XmlData;

    std::unique_ptr<EntityArchetypeComponent> m_pArchetype;
    IEntity* m_pEntity = nullptr;

    //! Finds the entity spawned by hte engine during loading.
    //! @returns whether it was found.
    bool FindExistingEntity();

    //! Sets up the entity.
    //! @param  isExisting  Whether this is th entity found by FindExistingEntity.
    void SetUpEntity(bool isExisting);

    //! Intersects a ray with the entity's OBB.
    bool IntersectOBB(const ViewportRaycastInfo& ray, RayIntersectInfo& intersect);
};

} // namespace LevelEditor
