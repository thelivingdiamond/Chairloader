#pragma once
#include "Utils/InspectorHelpers.h"

namespace LevelEditor
{

class ComponentList;
class Object;

//! A single unit of logic for level objects.
//! 
//! Internally implements an intrusive linked list for iteration.
class Component : NoCopy
{
public:
    Component();
    virtual ~Component();

    //! @returns the object to which the component is attached to.
    Object* GetObject() const { return m_pObject; }

protected:
    //! Called when the component is attached to an object.
    virtual void OnAttached() {}

    //! Called when object transform is changed.
    //! @param  nWhyFlags   Mask of EEntityXFormFlags. Informs what has changed.
    virtual void OnTransformChanged(unsigned nWhyFlags) {}

    //! Shows the component's inspector nodes.
    virtual void ShowInspector() {}

private:
    Object* m_pObject = nullptr;

    // Intrusive component list
    Component* m_pListPrev = nullptr;
    Component* m_pListNext = nullptr;

    //! Internal: Attaches the component to an object.
    void AttachToObject(Object* pObj);

    friend class ComponentList;
    friend class Object;
};

} // namespace LevelEditor
