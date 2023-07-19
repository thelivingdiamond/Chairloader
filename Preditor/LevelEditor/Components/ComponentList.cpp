#include "Components/Component.h"
#include "Components/ComponentList.h"

void LevelEditor::ComponentList::Add(Component* pComp)
{
    pComp->m_pListPrev = m_pLast;

    if (m_pLast)
    {
        assert(!m_pLast->m_pListNext);
        m_pLast->m_pListNext = pComp;
    }

    m_pLast = pComp;

    if (!m_pFirst)
        m_pFirst = pComp;
}

void LevelEditor::ComponentList::Remove(Component* pComp)
{
    Component* pPrev = pComp->m_pListPrev;
    Component* pNext = pComp->m_pListNext;

    if (pPrev)
        pPrev->m_pListNext = pNext;

    if (pNext)
        pNext->m_pListPrev = pPrev;

    if (m_pFirst == pComp)
        m_pFirst = pNext;

    if (m_pLast == pComp)
        m_pLast = pPrev;
}
