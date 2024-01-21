#include "Utils/AuxGeomComponent.h"
#include "AuxGeomManager.h"

LevelEditor::AuxGeomComponent::AuxGeomComponent()
    : m_ListItem(this)
{
}

LevelEditor::AuxGeomComponent::~AuxGeomComponent()
{
    SetAuxGeomEnabled(false);
}

void LevelEditor::AuxGeomComponent::SetAuxGeomEnabled(bool state)
{
    if (m_bEnabled == state)
        return;

    m_bEnabled = state;

    if (state)
        gLevel->pAuxGeomManager->AddComponent(*this);
    else
        gLevel->pAuxGeomManager->RemoveComponent(*this);
}
