#pragma once
#include <Preditor/SceneEditor/IObjectManipulator.h>

namespace GameEditor
{

class GameEditMode;

class EntityManipulator : public IObjectManipulator
{
public:
    EntityManipulator(GameEditMode* pEditor);
    ~EntityManipulator();

protected:
    // IObjectManipulator
    virtual Matrix34 GetObjectWorldTM(SceneObjectId id) override;
    virtual void SetObjectWorldTM(SceneObjectId id, const Matrix34& tm) override;

private:
    GameEditMode* m_pEditor = nullptr;
};

} // namespace GameEditor
