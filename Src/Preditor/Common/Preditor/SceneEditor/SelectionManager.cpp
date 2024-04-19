#include <Preditor/SceneEditor/SelectionManager.h>

SelectionManager::SelectionManager()
{
}

SelectionManager::~SelectionManager()
{
}

bool SelectionManager::IsSelected(SceneObjectId id)
{
    return m_ObjectSet.find(id) != m_ObjectSet.end();
}

void SelectionManager::AddToSelection(SceneObjectId id, bool isActive)
{
    if (id != INVALID_SCENE_OBJECT && !IsSelected(id))
    {
        m_Objects.push_back(id);
        m_ObjectSet.insert(id);
        OnSelected(id);
    }

    if (isActive && m_ActiveObject != id)
    {
        m_ActiveObject = id;
        OnMadeActive(id);
    }
}

void SelectionManager::RemoveFromSelection(SceneObjectId id)
{
    if (id == INVALID_SCENE_OBJECT)
    {
        CryError("[SelectionManager] RemoveFromSelection: invalid id");
        return;
    }

    auto setIt = m_ObjectSet.find(id);

    if (setIt == m_ObjectSet.end())
    {
        // Not selected
        CRY_ASSERT(m_ActiveObject != id);
        return;
    }

    if (m_ActiveObject == id)
        ClearActiveObject();

    m_ObjectSet.erase(setIt);
    auto vecIt = std::find(m_Objects.begin(), m_Objects.end(), id);
    CRY_ASSERT(vecIt != m_Objects.end());
    m_Objects.erase(vecIt);
    OnDeselected(id);
}

void SelectionManager::ClearSelection()
{
    ClearActiveObject();

    for (SceneObjectId id : m_Objects)
        OnDeselected(id);

    m_Objects.clear();
    m_ObjectSet.clear();
}

void SelectionManager::ClearActiveObject()
{
    if (m_ActiveObject != INVALID_SCENE_OBJECT)
    {
        m_ActiveObject = INVALID_SCENE_OBJECT;
        OnMadeActive(m_ActiveObject);
    }
}

void SelectionManager::ValidateSelection()
{
    // Reverse iteration since objects are removed
    for (int i = m_Objects.size() - 1; i >= 0; i--)
    {
        SceneObjectId id = m_Objects[i];

        if (!ValidateObject(id))
        {
            // No longer valid
            if (m_ActiveObject == id)
                ClearActiveObject();

            OnDeselected(id);
            m_Objects.erase(m_Objects.begin() + i);
            m_ObjectSet.erase(id);
        }
    }
}

bool SelectionManager::ValidateObject(SceneObjectId id)
{
    // Default implementation
    return true;
}
