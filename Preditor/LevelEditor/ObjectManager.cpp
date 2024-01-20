#include "Objects/EntityObject.h"
#include "Objects/Object.h"
#include "ObjectManager.h"

LevelEditor::ObjectManager::ObjectManager()
{
    gLevel->pObjectManager = this;
}

LevelEditor::ObjectManager::~ObjectManager()
{
}

LevelEditor::Object* LevelEditor::ObjectManager::GetObject(SceneObjectId id)
{
    if (id >= m_Objects.size())
        return nullptr;

    return m_Objects[id].get();
}

void LevelEditor::ObjectManager::CreateLevelObjects(XmlNodeRef objectsNode)
{
    CRY_ASSERT_MESSAGE(m_Objects.empty(), "Objects already loaded");

    int childCount = objectsNode->getChildCount();
    m_Objects.reserve(childCount);

    for (int i = 0; i < childCount; i++)
    {
        XmlNodeRef objectNode = objectsNode->getChild(i);
        CreateObject(objectNode);
    }

    // Set up parents
    for (int i = 0; i < childCount; i++)
    {
        Object* pObj = m_Objects[i].get();
        XmlNodeRef objectNode = objectsNode->getChild(i);

        if (objectNode->isTag("Entity"))
        {
            EntityId parentEntId = INVALID_ENTITYID;

            if (objectNode->getAttr("ParentId", parentEntId))
            {
                if (parentEntId != INVALID_ENTITYID)
                {
                    auto parentObjIt = std::find_if(m_Objects.begin(), m_Objects.end(),
                        [parentEntId](std::unique_ptr<Object>& pObj) {
                            return pObj->GetTypeInfo().type == EObjectType::Entity &&
                                static_cast<EntityObject*>(pObj.get())->GetEntityId() == parentEntId;
                        });

                    if (parentObjIt != m_Objects.end())
                    {
                        Object* pParent = parentObjIt->get();
                        pObj->GetTransform()->SetParent(pParent->GetTransform(), true);
                    }
                    else
                    {
                        CryError("Object {}: parent entity id {} not found", pObj->GetName(), parentEntId);
                    }
                }
                else
                {
                    CryError("Object {}: parent entity id is invalid");
                }
            }
        }
    }

    // Invalidate transform after all parents are set
    for (int i = 0; i < childCount; i++)
    {
        m_Objects[i]->GetTransform()->InvalidateTM(ENTITY_XFORM_FROM_PARENT);
    }

    // Spawn entities
    for (int i = 0; i < childCount; i++)
    {
        // Only check root entities
        if (m_Objects[i]->GetTransform()->GetParent())
            continue;

        SpawnEntityRecursive(*m_Objects[i]->GetTransform());
    }
}

LevelEditor::Object* LevelEditor::ObjectManager::CreateObject(XmlNodeRef objectNode)
{
    std::unique_ptr<Object> pTempObj;
    std::string_view objType = objectNode->getTag();
    
    if (objType == "Entity")
    {
        pTempObj = std::make_unique<EntityObject>();
    }
    else if (objType == "Object")
    {
        pTempObj = std::make_unique<Object>();
    }
    else
    {
        CryError("[ObjectManager] Unknown object type: {}", objType);
        pTempObj = std::make_unique<Object>();
    }

    assert(pTempObj);

    size_t idx = m_Objects.size();
    std::unique_ptr<Object>& pObj = m_Objects.emplace_back(std::move(pTempObj));
    InitObject(idx, objectNode);
    return pObj.get();
}

void LevelEditor::ObjectManager::InitObject(size_t idx, XmlNodeRef objectNode)
{
    Object* pObj = m_Objects[idx].get();
    pObj->InternalInit((SceneObjectId)idx);
    pObj->Init(objectNode);
}

void LevelEditor::ObjectManager::SpawnEntityRecursive(Transform& tr)
{
    Object* pObj = tr.GetObject();

    if (pObj->IsEntity())
    {
        static_cast<EntityObject*>(pObj)->RespawnEntity();
    }

    // Recurse into children
    for (Transform& childTr : tr.GetChildren())
    {
        SpawnEntityRecursive(childTr);
    }
}
