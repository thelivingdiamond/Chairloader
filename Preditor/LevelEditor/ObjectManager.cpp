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
}

LevelEditor::Object* LevelEditor::ObjectManager::CreateObject(XmlNodeRef objectNode)
{
    std::unique_ptr<Object> pTempObj;
    std::string_view objType = objectNode->getTag();
    
    if (objType == "Entity")
    {
        // TODO
        pTempObj = std::make_unique<Object>();
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
