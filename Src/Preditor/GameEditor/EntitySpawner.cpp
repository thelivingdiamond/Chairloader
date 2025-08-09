#include <boost/algorithm/string.hpp>
#include <Prey/CryEntitySystem/EntityArchetype.h>
#include <Prey/CryEntitySystem/EntitySystem.h>
#include <Prey/CryString/StringUtils.h>
#include <Prey/GameDll/ark/npc/ArkNpcSpawnedState.h>
#include <Prey/GameDll/ark/npc/ArkNpcSpawnManager.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include <Preditor/SceneEditor/I3DCursor.h>
#include "EntitySpawner.h"

GameEditor::EntitySpawner::EntitySpawner()
{
    SetTitle("Entity Spawner");
    SetPersistentID("GameEditorEntitySpawner");
    SetVisible(false);
    SetDestroyOnClose(false);
    RefreshList();
}

void GameEditor::EntitySpawner::ShowContents()
{
    if (ImGui::InputText("Filter", &m_FilterText))
    {
        RefreshList();
    }

    ImGuiListClipper clipper;
    clipper.Begin((int)m_Achetypes.size());

    while (clipper.Step())
    {
        for (int idx = clipper.DisplayStart; idx < clipper.DisplayEnd; idx++)
        {
            if (ImGui::Selectable(m_Achetypes[idx].c_str()))
            {
                SpawnArchetype(m_Achetypes[idx]);
            }
        }
    }
}

void GameEditor::EntitySpawner::RefreshList()
{
    auto* pEntSys = static_cast<CEntitySystem*>(gEnv->pEntitySystem);
    m_Achetypes.clear();

    if (m_FilterText.empty())
    {
        // List all archetypes
        for (const auto& [key, value] : pEntSys->m_pEntityArchetypeManager->m_nameToArchetypeMap)
        {
            m_Achetypes.emplace_back(key);
        }
    }
    else
    {
        // Only list archetypes that contain the filter
        for (const auto& [key, value] : pEntSys->m_pEntityArchetypeManager->m_nameToArchetypeMap)
        {
            if (CryStringUtils::stristr(key, m_FilterText.c_str()))
            {
                m_Achetypes.emplace_back(key);
            }
        }
    }
}
void GameEditor::EntitySpawner::SpawnArchetype(const std::string& archetypeName)
{
    // Get the archetype
    IEntityArchetype* pArchetype = gEnv->pEntitySystem->FindEntityArchetype(archetypeName.c_str());

    if (!pArchetype)
    {
        CryError("Archetype {} not found", archetypeName);
        return;
    }

    Quat rot = Quat::CreateIdentity();
    Vec3 pos = gPreditor->pSceneEditorManager->Get3DCursor()->GetPos();
    IEntity* pSpawnedEntity = nullptr;

    if (boost::istarts_with(archetypeName, "ArkNpcs"))
    {
        pSpawnedEntity = ArkNpcSpawnManager::CreateNpc(*pArchetype, pos, rot, 0, ArkNpcSpawnedState_Alert(true));
    }
    else
    {
        SEntitySpawnParams params;
        params.sName = archetypeName.c_str();
        params.vPosition = pos;
        params.qRotation = rot;
        pSpawnedEntity = gEnv->pEntitySystem->SpawnEntityFromArchetype(pArchetype, params);
    }

    if (pSpawnedEntity)
    {
        CryLog("Spawned entity [{}] {}", pSpawnedEntity->GetId(), pSpawnedEntity->GetName());
    }
    else
    {
        CryError("Failed to spawn entity {}", archetypeName);
    }
}
