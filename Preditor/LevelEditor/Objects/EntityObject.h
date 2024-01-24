#pragma once
#include "Objects/Object.h"

namespace LevelEditor
{

class EntityArchetypeComponent;
class EntityScriptComponent;

class AreaProxyComponent;

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

    //! Applies the object transform to the entity.
    void ApplyTransformToEntity(unsigned nWhyFlags = 0);

    // Object
    virtual void Init(XmlNodeRef objectNode) override;
    virtual void ShowInspectorSelf() override;
    virtual void OnTransformChanged(unsigned nWhyFlags) override;
    virtual void OnEnterPlayMode() override;
    virtual void OnExitPlayMode() override;
    virtual bool IntersectRay(const ViewportRaycastInfo& ray, RayIntersectInfo& intersect) override;
    virtual void DrawSelection(bool isActive) override;

private:
    struct EntitySpawnInfo
    {
        bool bGoodOccluder = false;
        bool bOutdoorOnly = false;
        bool bNoDecals = false;
        bool bDynamicDistanceShadows = false;
        int castShadowMinSpec = CONFIG_LOW_SPEC;

        void LoadFromXml(const XmlNodeRef& entityNode)
        {
            entityNode->getAttr("CastShadowMinSpec", castShadowMinSpec);
            entityNode->getAttr("DynamicDistanceShadows", bDynamicDistanceShadows);
            entityNode->getAttr("GoodOccluder", bGoodOccluder);
            entityNode->getAttr("OutdoorOnly", bOutdoorOnly);
            entityNode->getAttr("NoDecals", bNoDecals);
        }

        uint32 GetFlags()
        {
            uint32 f = 0;

            static const ICVar* const pObjShadowCastSpec = gEnv->pConsole->GetCVar("e_ObjShadowCastSpec");
            if (castShadowMinSpec <= pObjShadowCastSpec->GetIVal())
                f |= ENTITY_FLAG_CASTSHADOW;

            if (bGoodOccluder)
                f |= ENTITY_FLAG_GOOD_OCCLUDER;

            if (bOutdoorOnly)
                f |= ENTITY_FLAG_OUTDOORONLY;

            if (bNoDecals)
                f |= ENTITY_FLAG_NO_DECALNODE_DECALS;

            return f;
        }

        uint32 GetFlagsExtended()
        {
            uint32 f = 0;

            if (bDynamicDistanceShadows)
                f |= ENTITY_FLAG_EXTENDED_DYNAMIC_DISTANCE_SHADOWS;

            return f;
        }
    };

    XmlString m_EntityClassName;
    IEntityClass* m_pEntityClass = nullptr;
    EntityId m_EntityId = INVALID_ENTITYID;
    EntityGUID m_EntityGuid = 0;
    XmlNodeRef m_XmlData;
    EntitySpawnInfo m_SpawnInfo;

    // Proxies
    std::unique_ptr<AreaProxyComponent> m_pAreaProxy;

    std::unique_ptr<EntityArchetypeComponent> m_pArchetype;
    std::unique_ptr<EntityScriptComponent> m_pScript;
    IEntity* m_pEntity = nullptr;
};

} // namespace LevelEditor
