#include "EntitySelectionManager.h"

GameEditor::EntitySelectionManager::EntitySelectionManager(GameEditMode* pEditor)
{
    m_pEditor = pEditor;
}

GameEditor::EntitySelectionManager::~EntitySelectionManager()
{
}

bool GameEditor::EntitySelectionManager::ValidateObject(SceneObjectId id)
{
    if (id == INVALID_ENTITYID)
        return false;

    IEntity* pEnt = gEnv->pEntitySystem->GetEntity(id);
    return pEnt != nullptr;
}
