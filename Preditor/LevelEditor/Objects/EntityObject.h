#pragma once
#include "Objects/Object.h"

namespace LevelEditor
{

class EntityArchetypeComponent;

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

    // Object
    virtual void Init(XmlNodeRef objectNode) override;
    virtual void ShowInspectorSelf() override;

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
};

} // namespace LevelEditor
