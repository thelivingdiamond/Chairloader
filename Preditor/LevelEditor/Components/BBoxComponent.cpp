#include "Components/BBoxComponent.h"
#include "Objects/Object.h"

LevelEditor::BBoxComponent::BBoxComponent()
{
    SetAuxGeomEnabled(true);
}

LevelEditor::BBoxComponent::~BBoxComponent()
{
}

void LevelEditor::BBoxComponent::SetLocalBounds(const AABB& localBounds)
{
    if (m_LocalBounds.min == localBounds.min &&
        m_LocalBounds.max == localBounds.max)
        return;

    m_LocalBounds = localBounds;
    UpdateWorldBounds();
}

bool LevelEditor::BBoxComponent::Intersect(const Ray& ray, Vec3& hitPoint)
{
    // Intersect with world AABB first (cheaper)
    Vec3 hitPointInThisFunc;
    if (!IntersectAABB(ray, hitPointInThisFunc))
        return false;

    // Intersect with more precise OBB
    if (!IntersectOBB(ray, hitPointInThisFunc))
        return false;

    hitPoint = hitPointInThisFunc;
    return true;
}

bool LevelEditor::BBoxComponent::IntersectAABB(const Ray& ray, Vec3& hitPoint)
{
    return Intersect::Ray_AABB(ray, m_WorldBounds, hitPoint) != 0x00;
}

bool LevelEditor::BBoxComponent::IntersectOBB(const Ray& ray, Vec3& hitPoint)
{
    Vec3 worldPos = GetObject()->GetTransform()->GetWorldTM().GetTranslation();
    return Intersect::Ray_OBB(ray, worldPos, m_WorldObb, hitPoint) == 0x01;
}

void LevelEditor::BBoxComponent::OnTransformChanged(unsigned nWhyFlags)
{
    UpdateWorldBounds();
}

void LevelEditor::BBoxComponent::RenderAuxGeom()
{
    gEnv->pAuxGeomRenderer->DrawAABB(m_LocalBounds, GetObject()->GetTransform()->GetWorldTM(), false, m_BoundsColor, eBBD_Faceted);
}

void LevelEditor::BBoxComponent::UpdateWorldBounds()
{
    const Matrix34& tm = GetObject()->GetTransform()->GetWorldTM();
    m_WorldBounds.SetTransformedAABB(tm, m_LocalBounds);
    m_WorldObb = OBB::CreateOBBfromAABB(Matrix33(tm), m_LocalBounds);
}
