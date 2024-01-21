#include "Utils/AuxGeomComponent.h"
#include "AuxGeomManager.h"

LevelEditor::AuxGeomManager::AuxGeomManager()
{
    CRY_ASSERT(!gLevel->pAuxGeomManager);
    gLevel->pAuxGeomManager = this;
}

LevelEditor::AuxGeomManager::~AuxGeomManager()
{
    CRY_ASSERT_MESSAGE(m_List.empty(), "Aux geom component list still contains items");
    CRY_ASSERT(gLevel->pAuxGeomManager == this);
    gLevel->pAuxGeomManager = nullptr;
}

void LevelEditor::AuxGeomManager::RenderAuxGeom()
{
    for (AuxGeomComponent& i : m_List)
    {
        CRY_ASSERT_MESSAGE(i.IsAuxGeomEnabled(), "AuxGeomComponent not removed from list after disabling");
        i.RenderAuxGeom();
    }
}

void LevelEditor::AuxGeomManager::AddComponent(AuxGeomComponent& comp)
{
    m_List.add(comp.m_ListItem);
}

void LevelEditor::AuxGeomManager::RemoveComponent(AuxGeomComponent& comp)
{
    m_List.remove(comp.m_ListItem);
}
