#include "Components/EntityArchetypeComponent.h"

LevelEditor::EntityArchetypeComponent::EntityArchetypeComponent()
{
}

LevelEditor::EntityArchetypeComponent::~EntityArchetypeComponent()
{
}

bool LevelEditor::EntityArchetypeComponent::SetArchetype(const char* name)
{
    m_ArchetypeName = name;
    m_pArchetype = gEnv->pEntitySystem->FindEntityArchetype(name);
    return m_pArchetype;
}

void LevelEditor::EntityArchetypeComponent::SetArchetype(IEntityArchetype* pArchetype)
{
    m_pArchetype = pArchetype;
    m_ArchetypeName = pArchetype->GetName();
}

void LevelEditor::EntityArchetypeComponent::ShowInspector()
{
    if (Inspector::Begin("Entity Archetype"))
    {
        ImGui::Text("Archetype: %s", m_ArchetypeName.c_str());
        ImGui::Text("Is found: %s", m_pArchetype ? "yes" : "no");
        Inspector::End();
    }
}
