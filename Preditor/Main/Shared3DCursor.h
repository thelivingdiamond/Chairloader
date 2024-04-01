#pragma once
#include <Preditor/SceneEditor/I3DCursor.h>

namespace Main
{
class Shared3DCursor final : public I3DCursor
{
public:
    void MoveToZero();
    void MoveToPlayer();

    // I3DCursor
    virtual const Vec3& GetPos() const override { return m_Pos; }
    virtual void SetPos(const Vec3& newPos) override { m_Pos = newPos; }
    virtual void DrawAuxGeom() override;

private:
    Vec3 m_Pos = ZERO;
};

} // namespace Main
