#include "Components/Component.h"

LevelEditor::Component::Component()
{
}

LevelEditor::Component::~Component()
{
}

void LevelEditor::Component::AttachToObject(Object* pObj)
{
    CRY_ASSERT_MESSAGE(!m_pObject, "Component already attached to an object");
    m_pObject = pObj;
    OnAttached();
}
