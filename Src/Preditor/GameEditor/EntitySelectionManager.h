#pragma once
#include <Preditor/SceneEditor/SelectionManager.h>

namespace GameEditor
{

class GameEditMode;

class EntitySelectionManager : public SelectionManager
{
public:
    EntitySelectionManager(GameEditMode* pEditor);
    ~EntitySelectionManager();

protected:
    // SelectionManager
    virtual bool ValidateObject(SceneObjectId id) override;

private:
    GameEditMode* m_pEditor = nullptr;
};

} // namespace GameEditor
