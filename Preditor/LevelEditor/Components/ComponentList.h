#pragma once
#include "Components/Component.h"

namespace LevelEditor
{

class Object;

//! A linked list of components.
class ComponentList : NoCopy
{
public:
    class Iterator
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = Component;
        using pointer = value_type*;
        using reference = value_type&;

        reference operator*() const { return *m_pComp; }
        pointer operator->() { return m_pComp; }

        // Increment
        Iterator& operator++()
        {
            m_pComp = m_pComp->m_pListNext;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }


        // Decrement
        Iterator& operator--()
        {
            m_pComp = m_pComp->m_pListPrev;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        // Comparison
        bool operator==(const Iterator& rhs) const { return m_pComp == rhs.m_pComp; }
        bool operator!=(const Iterator& rhs) const { return m_pComp != rhs.m_pComp; }

    private:
        Component* m_pComp = nullptr;

        explicit Iterator(Component* pComp)
        {
            m_pComp = pComp;
        }

        friend class ComponentList;
    };

    Iterator begin() const { return Iterator(m_pFirst); }
    Iterator end() const { return Iterator(nullptr); }

    //! Adds a component to the list.
    void Add(Component* pComp);

    //! Removes a component from the list.
    //! The component must be in the list.
    void Remove(Component* pComp);

    //! Invokes a method on all components.
    //! @param  pfnMethod   The method.
    //! @param  args        Method args.
    template <auto func, typename ...TArgs>
    void InvokeOnAll(TArgs&&... args)
    {
        for (Component& i : *this)
        {
            std::invoke(func, i, std::forward<TArgs>(args)...);
        }
    }

private:
    Component* m_pFirst = nullptr;
    Component* m_pLast = nullptr;
};

} // namespace LevelEditor
