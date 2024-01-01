#pragma once
#include <Preditor/SceneEditor/IObjectManipulator.h>

namespace LevelEditor
{

class LevelEditMode;

class ObjectManipulator : public IObjectManipulator
{
public:
    ObjectManipulator(LevelEditMode* pEditor);
    ~ObjectManipulator();

protected:
    // IObjectManipulator
    virtual Matrix34 GetObjectWorldTM(SceneObjectId id) override;
    virtual void SetObjectWorldTM(SceneObjectId id, const Matrix34& tm) override;
    virtual void GetObjectLocalBounds(SceneObjectId id, AABB& aabb) override;

private:
    LevelEditMode* m_pEditor = nullptr;
};

} // namespace GameEditor
