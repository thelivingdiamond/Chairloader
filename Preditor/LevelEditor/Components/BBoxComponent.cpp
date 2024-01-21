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
    m_WorldBounds.SetTransformedAABB(GetObject()->GetTransform()->GetWorldTM(), m_LocalBounds);
}
