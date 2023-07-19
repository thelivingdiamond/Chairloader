#pragma once
#include <Preditor/SceneEditor/SelectionManager.h>

namespace LevelEditor
{

class LevelEditMode;

class ObjectSelectionManager : public SelectionManager
{
public:
    ObjectSelectionManager(LevelEditMode* pEditor);
    ~ObjectSelectionManager();

protected:
    // SelectionManager
    virtual bool ValidateObject(SceneObjectId id) override;

private:
    LevelEditMode* m_pEditor = nullptr;
};

} // namespace LevelEditor
