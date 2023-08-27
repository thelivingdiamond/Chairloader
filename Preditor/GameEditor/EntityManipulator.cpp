#include "EntityManipulator.h"

GameEditor::EntityManipulator::EntityManipulator(GameEditMode* pEditor)
{
    m_pEditor = pEditor;
}

GameEditor::EntityManipulator::~EntityManipulator()
{
}

Matrix34 GameEditor::EntityManipulator::GetObjectWorldTM(SceneObjectId id)
{
    IEntity* pEnt = gEnv->pEntitySystem->GetEntity((EntityId)id);

    if (!pEnt)
    {
        CryError("GetObjectWorldTM called with invalid entity id {}", id);
        return Matrix34(IDENTITY);
    }

    return pEnt->GetWorldTM();
}

void GameEditor::EntityManipulator::SetObjectWorldTM(SceneObjectId id, const Matrix34& tm)
{
    IEntity* pEnt = gEnv->pEntitySystem->GetEntity((EntityId)id);

    if (!pEnt)
    {
        CryError("SetObjectWorldTM called with invalid entity id {}", id);
        return;
    }

    pEnt->SetWorldTM(tm, ENTITY_XFORM_EDITOR);
}

void GameEditor::EntityManipulator::GetObjectLocalBounds(SceneObjectId id, AABB& aabb)
{
    IEntity* pEnt = gEnv->pEntitySystem->GetEntity((EntityId)id);

    if (!pEnt)
    {
        CryError("GetObjectLocalBounds called with invalid entity id {}", id);
        return;
    }

    pEnt->GetLocalBounds(aabb);
}
