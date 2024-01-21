#include "Objects/Object.h"
#include "LevelEditMode.h"
#include "ObjectManager.h"
#include "ObjectManipulator.h"

LevelEditor::ObjectManipulator::ObjectManipulator(LevelEditMode* pEditor)
{
    m_pEditor = pEditor;
}

LevelEditor::ObjectManipulator::~ObjectManipulator()
{
}

Matrix34 LevelEditor::ObjectManipulator::GetObjectWorldTM(SceneObjectId id)
{
    Object* pObject = m_pEditor->GetObjectManager()->GetObject(id);

    if (!pObject)
    {
        CryError("GetObjectWorldTM called with invalid object id {}", id);
        return Matrix34(IDENTITY);
    }

    return pObject->GetTransform()->GetWorldTM();
}

void LevelEditor::ObjectManipulator::SetObjectWorldTM(SceneObjectId id, const Matrix34& tm)
{
    Object* pObject = m_pEditor->GetObjectManager()->GetObject(id);

    if (!pObject)
    {
        CryError("SetObjectWorldTM called with invalid object id {}", id);
        return;
    }

    pObject->GetTransform()->SetWorldTM(tm);
}

void LevelEditor::ObjectManipulator::GetObjectLocalBounds(SceneObjectId id, AABB& aabb)
{
    Object* pObject = m_pEditor->GetObjectManager()->GetObject(id);

    if (!pObject)
    {
        CryError("GetObjectLocalBounds called with invalid object id {}", id);
        aabb = AABB::RESET;
        return;
    }
    
    aabb = pObject->GetBBox()->GetLocalBounds();
}
