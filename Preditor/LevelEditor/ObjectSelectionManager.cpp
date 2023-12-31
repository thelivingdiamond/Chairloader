#include "ObjectSelectionManager.h"
#include "ObjectManager.h"
#include "LevelEditMode.h"

LevelEditor::ObjectSelectionManager::ObjectSelectionManager(LevelEditMode* pEditor)
{
    m_pEditor = pEditor;
}

LevelEditor::ObjectSelectionManager::~ObjectSelectionManager()
{
}

bool LevelEditor::ObjectSelectionManager::ValidateObject(SceneObjectId id)
{
    Object* pObject = m_pEditor->GetObjectManager()->GetObject(id);
    return pObject != nullptr;
}
