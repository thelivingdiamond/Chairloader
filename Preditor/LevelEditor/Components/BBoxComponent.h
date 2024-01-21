#pragma once
#include "Components/Component.h"
#include "Utils/AuxGeomComponent.h"

namespace LevelEditor
{

//! Stores the object's bounding box (in local and world space).
class BBoxComponent : public Component, protected AuxGeomComponent
{
public:
    BBoxComponent();
    ~BBoxComponent();

    //! @returns The bbox in object local space.
    const AABB& GetLocalBounds() const { return m_LocalBounds; }

    //! @returns The bbox in world space.
    const AABB& GetWorldBounds() const { return m_WorldBounds; }

    //! Sets new local-space bounding box.
    void SetLocalBounds(const AABB& localBounds);

    //! @returns The bounding box color.
    ColorB GetBoundsColor() const { return m_BoundsColor; }

    //! Sets the bounding box color.
    void SetBoundsColor(const ColorB& c) { m_BoundsColor = c; }

protected:
    // Component
    virtual void OnTransformChanged(unsigned nWhyFlags) override;

    // AuxGeomComponent
    virtual void RenderAuxGeom() override;

private:
    //! BBox in object local space.
    AABB m_LocalBounds = AABB(Vec3(ZERO));

    //! BBox on world space.
    AABB m_WorldBounds = AABB(Vec3(ZERO));

    //! Bounding box color when rendering.
    ColorB m_BoundsColor = ColorB(0, 255, 0);

    //! Updates m_WorldBounds using m_LocalBounds and the object's transform.
    void UpdateWorldBounds();
};

} // namespace LevelEditor
