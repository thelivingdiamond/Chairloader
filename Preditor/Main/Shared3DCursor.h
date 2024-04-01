#pragma once
#include <Preditor/SceneEditor/I3DCursor.h>

namespace Main
{
class Shared3DCursor final : public I3DCursor
{
public:
    Shared3DCursor();
    ~Shared3DCursor();

    void MoveToOrigin();
    void MoveToPlayer();
    void MoveToCamera();

    // I3DCursor
    virtual const Vec3& GetPos() const override { return m_Pos; }
    virtual void SetPos(const Vec3& newPos) override { m_Pos = newPos; }
    virtual void ShowMenu() override;
    virtual void DrawAuxGeom() override;

private:
    std::vector<Vec3> m_UnitCircle;
    std::vector<Vec3> m_TempCircle;
    Vec3 m_Pos = ZERO;
};

} // namespace Main
