#include "AreaProxyComponent.h"

LevelEditor::AreaProxyComponent::AreaProxyComponent()
    : EntityProxyComponent(ENTITY_PROXY_AREA)
{
}

void LevelEditor::AreaProxyComponent::LoadFromXml(const XmlNodeRef& entityNode)
{
    EntityProxyComponent::LoadFromXml(entityNode);

    XmlNodeRef areaNode = entityNode->findChild("Area");
    CRY_ASSERT(areaNode);

    areaNode->getAttr("Id", m_nId);
    areaNode->getAttr("Group", m_nGroup);
    areaNode->getAttr("Proximity", m_flProximity);
    areaNode->getAttr("Priority", m_nPriority);

    if (XmlNodeRef pointsNode = areaNode->findChild("Points"))
    {
        m_nAreaType = ENTITY_AREA_TYPE_SHAPE;

        ShapeData& data = m_ShapeData;
        data.Reset();

        bool bObstructSound = false; // Located out of loop like in CryEngine
        data.numPoints = pointsNode->getChildCount();

        for (int i = 0; i < data.numPoints; i++)
        {
            XmlNodeRef pntNode = pointsNode->getChild(i);

            // Point
            Vec3 pos(ZERO);
            pntNode->getAttr("Pos", pos);
            data.localPoints.push_back(pos);

            // Sound obstruction
            pntNode->getAttr("ObstructSound", bObstructSound);
            data.obstructSound.push_back(bObstructSound);
        }

        // Get Roof
        if (XmlNodeRef const roofNode = areaNode->findChild("Roof"))
            roofNode->getAttr("ObstructSound", bObstructSound);
        else
            bObstructSound = false;

        data.obstructSound.push_back(bObstructSound);

        // Get Floor
        if (XmlNodeRef const floorNode = areaNode->findChild("Floor"))
            floorNode->getAttr("ObstructSound", bObstructSound);
        else
            bObstructSound = false;

        data.obstructSound.push_back(bObstructSound);

        // Get Height
        areaNode->getAttr("Height", data.flHeight);
    }
    else if (float flRadius = 0.0f; areaNode->getAttr("SphereRadius", flRadius))
    {
        m_nAreaType = ENTITY_AREA_TYPE_SPHERE;
        m_SphereData.flRadius = flRadius;
        areaNode->getAttr("SphereCenter", m_SphereData.vCenter);
    }
    else if (float flRadius = 0.0f; areaNode->getAttr("VolumeRadius", flRadius))
    {
        m_nAreaType = ENTITY_AREA_TYPE_GRAVITYVOLUME;

        GravityData& data = m_GravityData;
        data.Reset();

        areaNode->getAttr("Gravity", data.fGravity);
        areaNode->getAttr("DontDisableInvisible", data.bDontDisableInvisible);

        // BezierPoints
        if (pointsNode = areaNode->findChild("BezierPoints"))
        {
            for (int i = 0; i < pointsNode->getChildCount(); i++)
            {
                XmlNodeRef pntNode = pointsNode->getChild(i);
                Vec3 pt;
                if (pntNode->getAttr("Pos", pt))
                {
                    data.bezierPoints.push_back(pt);
                }
            }
        }
    }
    else if (const char* pszFileName; areaNode->getAttr("AreaSolidFileName", &pszFileName))
    {
        // TODO 2024-01-20: Implement solid area
        m_nAreaType = ENTITY_AREA_TYPE_SOLID;
    }
    else
    {
        m_nAreaType = ENTITY_AREA_TYPE_BOX;
        BoxData& data = m_BoxData;
        data.Reset();

        areaNode->getAttr("BoxMin", data.bmin);
        areaNode->getAttr("BoxMax", data.bmax);

        if (XmlNodeRef soundData = areaNode->findChild("SoundData"))
        {
            for (int i = 0; i < soundData->getChildCount(); ++i)
            {
                if (XmlNodeRef const pNodeSide = soundData->getChild(i))
                {
                    bool bObstructSound = false;
                    pNodeSide->getAttr("ObstructSound", bObstructSound);
                    data.obstructSound.push_back(bObstructSound);
                }
            }
        }
    }

    // Export Entities.
    m_NotifyEntities.clear();

    if (XmlNodeRef entitiesNode = areaNode->findChild("Entities"))
    {
        for (int i = 0; i < entitiesNode->getChildCount(); i++)
        {
            XmlNodeRef entNode = entitiesNode->getChild(i);
            EntityId entityId = INVALID_ENTITYID;
            if (entNode->getAttr("Id", entityId) && (entityId != INVALID_ENTITYID))
            {
                m_NotifyEntities.push_back(entityId);
            }
        }
    }
}

void LevelEditor::AreaProxyComponent::ShowInspector()
{
    if (Inspector::Begin("Area"))
    {
        ImGui::Text("m_nId = %d", m_nId);
        ImGui::Text("m_nGroup = %d", m_nGroup);
        ImGui::Text("m_flProximity = %f", m_flProximity);
        ImGui::Text("m_nPriority = %d", m_nPriority);
        ImGui::Text("m_nAreaType = %d", m_nAreaType);

        switch (m_nAreaType)
        {
        case ENTITY_AREA_TYPE_SHAPE:
        {
            const ShapeData& data = m_ShapeData;
            ImGui::Text("ENTITY_AREA_TYPE_SHAPE");
            ImGui::Text("numPoints = %d", data.numPoints);
            ImGui::Text("flHeight = %f", data.flHeight);
            break;
        }
        case ENTITY_AREA_TYPE_BOX:
        {
            const BoxData& data = m_BoxData;
            ImGui::Text("ENTITY_AREA_TYPE_BOX");
            ImGui::Text("Min = %.1f, %.1f, %.1f", data.bmin.x, data.bmin.y, data.bmin.z);
            ImGui::Text("Max = %.1f, %.1f, %.1f", data.bmax.x, data.bmax.y, data.bmax.z);
            ImGui::Text("obstructSound = %lld", data.obstructSound.size());
            break;
        }
        case ENTITY_AREA_TYPE_SPHERE:
        {
            const SphereData& data = m_SphereData;
            ImGui::Text("ENTITY_AREA_TYPE_SPHERE");
            ImGui::Text("vCenter = %.1f, %.1f, %.1f", data.vCenter.x, data.vCenter.y, data.vCenter.z);
            ImGui::Text("flRadius = %f", data.flRadius);
            break;
        }
        case ENTITY_AREA_TYPE_GRAVITYVOLUME:
        {
            const GravityData& data = m_GravityData;
            ImGui::Text("ENTITY_AREA_TYPE_GRAVITYVOLUME");
            break;
        }
        case ENTITY_AREA_TYPE_SOLID:
        {
            ImGui::Text("ENTITY_AREA_TYPE_SOLID");
            ImGui::Text("TODO Not Implemented");
            break;
        }
        }

        Inspector::End();
    }
}

void LevelEditor::AreaProxyComponent::OnProxyCreated()
{
    ApplyArea();
}

void LevelEditor::AreaProxyComponent::ApplyArea()
{
    IEntityAreaProxy* pArea = GetProxy();
    pArea->SetID(m_nId);
    pArea->SetGroup(m_nGroup);
    pArea->SetProximity(m_flProximity);
    pArea->SetPriority(m_nPriority);

    switch (m_nAreaType)
    {
    case ENTITY_AREA_TYPE_SHAPE:
    {
        const ShapeData& data = m_ShapeData;
        pArea->SetPoints(
            data.localPoints.data(),
            reinterpret_cast<const bool*>(data.obstructSound.data()),
            data.numPoints,
            data.flHeight);
        break;
    }
    case ENTITY_AREA_TYPE_SPHERE:
    {
        const SphereData& data = m_SphereData;
        pArea->SetSphere(data.vCenter, data.flRadius);
        break;
    }
    case ENTITY_AREA_TYPE_GRAVITYVOLUME:
    {
        const GravityData& data = m_GravityData;
        pArea->SetGravityVolume(
            data.bezierPoints.data(),
            data.bezierPoints.size(),
            data.fRadius,
            data.fGravity,
            data.bDontDisableInvisible,
            data.fFalloff,
            data.fDamping);
        break;
    }
    case ENTITY_AREA_TYPE_BOX:
    {
        const BoxData& data = m_BoxData;
        pArea->SetBox(
            data.bmin,
            data.bmax,
            reinterpret_cast<const bool*>(data.obstructSound.data()),
            data.obstructSound.size());
        break;
    }
    }

    pArea->ClearEntities();

    for (EntityId id : m_NotifyEntities)
    {
        pArea->AddEntity(id);
    }
}
