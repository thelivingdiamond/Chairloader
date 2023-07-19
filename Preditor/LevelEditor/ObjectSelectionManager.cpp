#include "ObjectSelectionManager.h"

LevelEditor::ObjectSelectionManager::ObjectSelectionManager(LevelEditMode* pEditor)
{
    m_pEditor = pEditor;
}

LevelEditor::ObjectSelectionManager::~ObjectSelectionManager()
{
}

bool LevelEditor::ObjectSelectionManager::ValidateObject(SceneObjectId id)
{
    // TODO 2023-07-15
    return false;
}
