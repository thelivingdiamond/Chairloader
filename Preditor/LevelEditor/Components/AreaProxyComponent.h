#pragma once
#include "Components/EntityProxyComponent.h"

namespace LevelEditor
{

class AreaProxyComponent : public EntityProxyComponent
{
public:
    AreaProxyComponent();

    // EntityProxyComponent
    IEntityAreaProxy* GetProxy() const { return static_cast<IEntityAreaProxy*>(EntityProxyComponent::GetProxy()); }
    virtual void LoadFromXml(const XmlNodeRef& entityNode) override;

protected:
    // Component
    virtual void ShowInspector() override;
    virtual void OnProxyCreated() override;

private:
    struct ShapeData
    {
        //! The number of points.
        int numPoints = 0;

        //! The points in local space.
        std::vector<Vec3> localPoints;

        //! Point sound obstruction (?)
        //! This should be bool but vector of bool is not a real vector
        std::vector<char> obstructSound;

        float flHeight = 0.0f;

        void Reset()
        {
            numPoints = 0;
            localPoints.clear();
            obstructSound.clear();
            flHeight = 0.0f;
        }
    };

    struct SphereData
    {
        Vec3 vCenter = ZERO;
        float flRadius = 0.0f;
    };

    struct GravityData
    {
        std::vector<Vec3> bezierPoints;
        float fRadius = 0.0f;
        float fGravity = 0.0f;
        bool bDontDisableInvisible = false;
        float fFalloff = 0.0f;
        float fDamping = 0.0f;

        void Reset()
        {
            bezierPoints.clear();
            fRadius = 0.0f;
            fGravity = 0.0f;
            bDontDisableInvisible = false;
            fFalloff = 0.0f;
            fDamping = 0.0f;
        }
    };

    struct BoxData
    {
        Vec3 bmin = ZERO;
        Vec3 bmax = ZERO;

        //! This should be bool but vector of bool is not a real vector
        std::vector<char> obstructSound;

        void Reset()
        {
            bmin = ZERO;
            bmax = ZERO;
            obstructSound.clear();
        }
    };

    int m_nId = 0;
    int m_nGroup = 0;
    float m_flProximity = 0;
    int m_nPriority = 0;

    //! Entities to be notified.
    //! TODO 2024-01-20: This should use an object list with GUIDs
    std::vector<EntityId> m_NotifyEntities;

    EEntityAreaType m_nAreaType = (EEntityAreaType)0;
    ShapeData m_ShapeData;
    SphereData m_SphereData;
    GravityData m_GravityData;
    BoxData m_BoxData;

    //! Applies area properties to the area instance.
    void ApplyArea();
};

} // namespace LevelEditor
