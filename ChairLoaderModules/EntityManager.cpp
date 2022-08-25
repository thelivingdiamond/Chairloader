#include "ChairLoader/pch.h"
#include "EntityManager.h"

#include "Logging.h"
#include "Prey/Cry3DEngine/I3DEngine.h"
#include "Prey/CryEntitySystem/EntityArchetype.h"
#include "Prey/CryEntitySystem/EntitySystem.h"
#include "Prey/CryEntitySystem/Entity.h"
#include "Prey/GameDll/ark/player/ArkPlayer.h"
#include "Prey/CryEntitySystem/EntityClassRegistry.h"
#include "Prey/GameDll/ark/ArkGame.h"
#include "Prey/GameDll/ark/ArkLocationManager.h"
#include "Prey/GameDll/ark/npc/ArkNpc.h"
#include "Prey/GameDll/ark/ArkFactionManager.h"

static ClassLibrary gClassLibrary;

EntityManager::EntityManager(ChairloaderGlobalEnvironment* env) {
    gCLEnv = env;
    oldArchetypeFilterText = " ";
}

EntityManager::~EntityManager() {

}
static uint64_t selectedSpawnerFaction = 0;
static float offsetDistance[3] = {0,5,0};
void EntityManager::drawEntitySpawner(bool* bShow) {
    if(showEntitySpawner){
        if (ImGui::Begin("Entity Spawner", bShow, ImGuiWindowFlags_NoNavInputs)) {
            ImGui::TextColored(color, statusMessage.c_str());

            if (archetypeToSpawn == 0) {
                ImGui::Text("Entity Archetype Name: ");
                ImGui::Text("Archetype ID: ");
            } else {
                ImGui::Text("Entity Archetype Name: %s", gEnv->pEntitySystem->GetEntityArchetype(archetypeToSpawn)->GetName());
                ImGui::Text("Archetype ID: %llu", archetypeToSpawn);
            }
            ImGui::InputText("Entity Name", &inputName, ImGuiInputTextFlags_None);
            ImGui::InputInt("Spawn Count", &spawnCount);
            ImGui::Checkbox("Use Player Pos", &usePlayerPos);
            if (usePlayerPos) {
                ImGui::Checkbox("Offset In front of Player", &offsetFromPlayer);
                if(offsetFromPlayer) {
//                    ImGui::SliderFloat("Left/Right", &offsetDistance[0], -10.0f, 10.0f, "%.2f");
                    ImGui::SliderFloat2("Offset: In/Out, Up/Down", &offsetDistance[1], -10.0f, 10.0f, "%.2f");
//                    ImGui::SliderFloat("Forward/Backward", &offsetDistance[1], -10.0f, 10.0f, "%.2f");
//                    ImGui::SliderFloat("Up/Down", &offsetDistance[2], -10.0f, 10.0f, "%.2f");
                }
            } else {
                ImGui::InputFloat("X", &spawnX);
                ImGui::InputFloat("Y", &spawnY);
                ImGui::InputFloat("Z", &spawnZ);
            }
            auto IfactionManager = gEnv->pGame->GetIArkFactionManager();
            auto factionmanager = static_cast<ArkFactionManager*>(IfactionManager);
            ImGui::Separator();
            std::string previewText;
            if(selectedSpawnerFaction != 0){
                previewText = IfactionManager->GetFactionName(selectedSpawnerFaction);
            } else {
                previewText = "Default";
            }
            if(ImGui::BeginCombo("Faction", previewText.c_str())){
                if(ImGui::Selectable("Default")){
                    selectedSpawnerFaction = 0;
                }
                for(auto faction : factionmanager->m_idToIndexMap){
                    if(ImGui::Selectable(IfactionManager->GetFactionName(faction.first).c_str())){
                        selectedSpawnerFaction = faction.first;
                    }
                }
                ImGui::EndCombo();
            }
            if (ImGui::Button("Spawn Entity")) {
                spawnEntity();
            }
            ImGui::Text("Filter:");
            static bool initializedList = false;
            static std::string archetypeLoadString;
            ImGui::InputText("Archetype Library to Load", &archetypeLoadString, ImGuiInputTextFlags_None);
            if (ImGui::Button("Load Archetype Library")) {
                auto archetypeLibrary = string(archetypeLoadString.c_str());
                gEnv->pEntitySystem->LoadArchetypeLibrary(&archetypeLibrary);
    //            GetEntitySystem()->m_pEntityArchetypeManager->LoadLibrary(archetypeLoadString.c_str());
            }
            if (ImGui::InputText("##filter text", &archetypeFilterText) || !initializedList) {
                oldArchetypeFilterText = archetypeFilterText;
                initializedList = true;
                auto archetypeNameList = GetEntitySystem()->m_pEntityArchetypeManager->m_nameToArchetypeMap;
                auto itr = archetypeNameList.begin();
                archetypeFilteredList.clear();
                for (int i = 0; i < 500 && itr != archetypeNameList.end(); ++itr) {
                    std::string archetypeName = (*itr).second->GetName();
                    // size_t last_period = archetypeName.find_last_of('.');
                    // archetypeName = archetypeName.substr(last_period, archetypeName.size());
                    std::transform(archetypeName.begin(), archetypeName.end(), archetypeName.begin(), ::tolower);
                    std::transform(archetypeFilterText.begin(), archetypeFilterText.end(), archetypeFilterText.begin(),
                                   ::tolower);
                    if (archetypeName.find(archetypeFilterText) != std::string::npos || archetypeFilterText.empty()) {
                        archetypeFilteredList.emplace_back(itr->second->m_id);
                        i++;

                    }
                }
            }
//            ImGuiUtils::HelpMarker("Filter usage:\n"
//                                   "  \"\"         display all lines\n"
//                                   "  \"xxx\"      display lines containing \"xxx\"\n"
//                                   "  \"xxx,yyy\"  display lines containing \"xxx\" or \"yyy\"\n"
//                                   "  \"-xxx\"     hide lines containing \"xxx\"");

            static ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter |
                                           ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Hideable;
            ImVec2 outer_size = ImVec2(0.0f, 0.0f);

            if (ImGui::BeginTable("EntityArchetypeList", 2, flags, outer_size)) {
                ImGui::TableSetupScrollFreeze(0, 1);
                ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_None);
                ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_None);
                ImGui::TableHeadersRow();
                auto itr = archetypeFilteredList.begin();
                for (int clip = 0; clip < 500 && itr != archetypeFilteredList.end(); clip++, ++itr) {
                    IEntityArchetype *archetype = gEnv->pEntitySystem->GetEntityArchetype(*itr);
                    ImGui::TableNextRow();
                    //Yeah boi
                    ImGui::TableSetColumnIndex(0);
                    if(archetype != nullptr) {
                        if (ImGui::Selectable(archetype->GetName(), archetypeToSpawn == archetype->GetId(),
                                              ImGuiSelectableFlags_SpanAllColumns)) {
                            archetypeToSpawn = archetype->GetId();
                        }
                    }

                    // if (ImGui::BeginPopupContextItem(NULL, ImGuiPopupFlags_MouseButtonLeft)) // <-- use last item id as popup id
                    // {
                    //     ImGui::Text("Display information about the archetype here");
                    //     if (ImGui::Button("Choose"))
                    //         archetypeToSpawn = archetype;
                    //     if (ImGui::Button("Close"))
                    //         ImGui::CloseCurrentPopup();
                    //     ImGui::EndPopup();
                    // }

                    ImGui::TableSetColumnIndex(1);
                    ImGui::Text("%llu", archetype->GetId());
                }

                if (time(NULL) > statusTimer + 3)
                    statusMessage = "";
                ImGui::EndTable();
            }
            CRY_ASSERT(gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.ArkNightmare) != nullptr);
    //        ImGui::Text("%s", gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkGameplayObjects.GravShaft.GravShaft_Coil)->GetName());
        }
        ImGui::End();
    }
}

std::string getDispositionStr(EArkDisposition disposition) {
    switch (disposition) {
        case EArkDisposition::friendly:
            return "Friendly";
        case EArkDisposition::neutral:
            return "Neutral";
        case EArkDisposition::hostile:
            return "Hostile";
        case EArkDisposition::none:
            return "None";
        default:
            return "Unknown";
    }
}


void EntityManager::drawEntityList(bool* bShow) {
    if(showEntityList) {
        if (ImGui::Begin("Entity List", bShow, ImGuiWindowFlags_NoNavInputs)) {
            {
                static bool filterByNpcs = false;
                ImGui::BeginChild("left pane", ImVec2(250, 0), true, ImGuiWindowFlags_HorizontalScrollbar);
                ImGui::InputText("##input", &filterText);
                if (oldFilterText != filterText) {
                    oldFilterText = filterText;
                    refreshDisplayList = true;
                }
                ImGui::SameLine();
                if (ImGui::Button("Refresh")) {
                    refreshDisplayList = true;
                }
                if(ImGui::Checkbox("Filter By NPCs", &filterByNpcs))
                    refreshDisplayList = true;
                if (refreshDisplayList) {
                    refreshDisplayList = false;
                    entityDisplayList.clear();
                    selectedEntity = 0;
                    for (auto itr = GetEntitySystem()->m_EntityArray.begin();
                         itr != GetEntitySystem()->m_EntityArray.end(); ++itr) {
                        if (*itr != nullptr) {
                            if (!(*itr)->m_szName.empty()) {
                                std::string name = (*itr)->m_szName.c_str();
                                std::string newFilterText = filterText;
                                std::transform(newFilterText.begin(), newFilterText.end(), newFilterText.begin(), ::tolower);
                                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                                if (name.find(newFilterText) != name.npos || filterText.empty()) {
                                    if(filterByNpcs) {
                                        if(gCLEnv->entUtils->GetArkNpc(*itr) != nullptr) {
                                            entityDisplayList.emplace_back((*itr)->GetId());
                                        }
                                    } else {
                                        entityDisplayList.emplace_back((*itr)->GetId());
                                    }
                                }
                            }
                        }
                    }
                }
                auto itr = entityDisplayList.begin();
                for (int i = 0; itr != entityDisplayList.end() && i < 500; i++, ++itr) {
                    std::string label;
                    if(gEnv->pEntitySystem->GetEntity(*itr) != nullptr) {
                        if (!string(gEnv->pEntitySystem->GetEntity(*itr)->GetName()).empty()) {
                            label = gEnv->pEntitySystem->GetEntity(*itr)->GetName();
                        } else {
                            label = "invalid name";
                        }
                        // sprintf_s(label, "Entity: %d", i);
                        if (ImGui::Selectable(label.c_str(), selectedEntity == *itr))
                            selectedEntity = *itr;
                    }
                }
                ImGui::EndChild();
            }
            ImGui::SameLine();
            // Right
            {
                ImGui::BeginGroup();
                ImGui::BeginChild("entity view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
                if (selectedEntity != 0 && gEnv->pEntitySystem->GetEntity(selectedEntity) != nullptr) {
                    ImGui::Text("Entity: %llu", gEnv->pEntitySystem->GetEntity(selectedEntity)->GetId());
                } else {
                    ImGui::Text("Entity: %s", "Null");
                }
                ImGui::Separator();
                if (ImGui::BeginTabBar("##Tabs",
                                       ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_TabListPopupButton)) {
                    if (selectedEntity != 0 && gEnv->pEntitySystem->GetEntity(selectedEntity) != nullptr) {
                        auto entity = gEnv->pEntitySystem->GetEntity(selectedEntity);
                        auto npc = gCLEnv->entUtils->GetArkNpc(entity);
                        if (ImGui::BeginTabItem("Entity Details")) {
                            // CryLog("at the entity check\n");
                            if (ImGui::BeginTable("Details", 2, ImGuiTableFlags_NoClip | ImGuiTableFlags_BordersH)) {
                                // Setup Columns
                                ImGui::TableSetupColumn(" Item:", ImGuiTableColumnFlags_WidthFixed, 75.0f);
                                ImGui::TableSetupColumn(" Value:");
                                // Name
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                ImGuiUtils::RightAlignText("Name:");
                                ImGui::Text("Name:");
                                ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                                ImGui::TableNextColumn();
                                if (!string(entity->GetName()).empty())
                                    ImGui::Text("%s", entity->GetName());
                                else
                                    ImGui::Text("%s", "--Null Name--");
                                // ID
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                ImGuiUtils::RightAlignText("ID:");
                                ImGui::Text("ID:");
                                ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                                ImGui::TableNextColumn();
                                // CryLog("at id\n");
                                ImGui::Text("%u", entity->GetId());
                                // GUID
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                // CryLog("at guid\n");
                                ImGuiUtils::RightAlignText("GUID:");
                                ImGui::Text("GUID:");
                                ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                                ImGui::TableNextColumn();
                                ImGui::Text("%llu", entity->GetGuid());
                                // Class
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                // CryLog("at class\n");
                                ImGuiUtils::RightAlignText("Class:");
                                ImGui::Text("Class:");
                                ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                                ImGui::TableNextColumn();
                                if (entity->GetClass() != nullptr) {
                                    if (!string(entity->GetClass()->GetName()).empty())
                                        ImGui::Text("%s", entity->GetName());
                                    else
                                        ImGui::Text("%s", "--Unknown Class--");
                                } else {
                                    ImGui::Text("%s", "--Null Class--");
                                }
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                ImGuiUtils::RightAlignText("Archetype:");
                                ImGui::Text("Archetype:");
                                ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                                ImGui::TableNextColumn();
                                if (entity->GetArchetype() != nullptr) {
                                    if (!string(entity->GetArchetype()->GetName()).empty())
                                        ImGui::Text("%s", entity->GetName());
                                    else
                                        ImGui::Text("%s", "--Unknown Archetype--");
                                } else {
                                    ImGui::Text("%s", "--Null Archetype--");
                                }

                                ImGui::EndTable();
                            }
                            ImGui::Text("Position: ");
                            static float position[3];
                            position[0] = entity->GetPos().x;
                            position[1] = entity->GetPos().y;
                            position[2] = entity->GetPos().z;
                            if (ImGui::InputFloat3("Pos", position, "%.1f", ImGuiInputTextFlags_EnterReturnsTrue)) {
                                Vec3 newPos = Vec3(position[0], position[1], position[2]);
                                entity->SetPos(newPos, 0, true, true);
                            }
                            if (ImGui::Button("Set to player pos")) {
                                entity->SetPos(gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetPos());
                            }

                            ImGui::Text("Rotation: ");
                            static float rotation[4];
                            rotation[0] = entity->GetRotation().v.x;
                            rotation[1] = entity->GetRotation().v.y;
                            rotation[2] = entity->GetRotation().v.z;
                            rotation[3] = entity->GetRotation().w;
                            if (ImGui::InputFloat4("Rot", rotation, "%.3f", ImGuiInputTextFlags_EnterReturnsTrue)) {
                                Quat newRot = Quat(rotation[0], rotation[1], rotation[2], rotation[3]);
                                entity->SetRotation(newRot, 0);
                            }

                            static float scale;
                            scale = entity->GetScale().x;
                            ImGui::Text("Scale: ");
                            if (ImGui::InputFloat("scale", &scale, 0, 0, "% .1f",
                                                  ImGuiInputTextFlags_EnterReturnsTrue)) {
                                Vec3 newScale{scale, scale, scale};
                                entity->SetScale(newScale, 0);
                            }
                            auto npc = gCLEnv->entUtils->GetArkNpc(entity);
                            if(npc != nullptr){
                                ImGui::Text("NPC: %p", npc);
                                if(ImGui::Button("Kill NPC")){

                                }
                            } else {
                                ImGui::Text("NPC: null");
                            }
                            ImGui::EndTabItem();
                        }
                        if(ImGui::BeginTabItem("Physics")){
                            if(entity->GetPhysics() != nullptr){
                                auto physics = entity->GetPhysics();
                                std::string type;
                                switch(physics->GetType()){
                                    case pe_type::PE_NONE:
                                        type = "None";
                                        break;
                                    case pe_type::PE_STATIC:
                                        type = "Static";
                                        break;
                                    case pe_type::PE_RIGID:
                                        type = "Rigid";
                                        break;
                                    case pe_type::PE_WHEELEDVEHICLE:
                                        type = "Wheeled Vehicle";
                                        break;
                                    case pe_type::PE_LIVING:
                                        type = "Living";
                                        break;
                                    case pe_type::PE_PARTICLE:
                                        type = "Particles";
                                        break;
                                    case pe_type::PE_ARTICULATED:
                                        type = "Articulated";
                                        break;
                                    case pe_type::PE_ROPE:
                                        type = "Rope";
                                        break;
                                    case pe_type::PE_SOFT:
                                        type = "Soft";
                                        break;
                                    case pe_type::PE_AREA:
                                        type = "Area";
                                        break;
                                }
                                ImGui::Text("Type: %s", type.c_str());
//                                auto params = new pe_params_flags();
//                                physics->GetParams(params);
//                                ImGui::Text("Params:");
//                                ImGui::Text("  Flags: %u", params->flags);
//                                ImGui::Text("  Ignore Areas: %u", params->flags & pef_ignore_areas);
//                                if(ImGui::Button("Set Ignore Gravity Flag")){
//                                    params->flags = params->flags & pef_ignore_areas;
//                                    physics->SetParams(params);
//                                }
                            }
                            ImGui::EndTabItem();
                        }
                        // Push Pop Effects
                        // TODO: ALL OF THIS
                        if(ImGui::BeginTabItem("Factions")){
                            auto IfactionManager = gEnv->pGame->GetIArkFactionManager();
                            auto factionmanager = static_cast<ArkFactionManager*>(IfactionManager);
                            ImGui::Text("Current Faction: %s", IfactionManager->GetFactionName(IfactionManager->GetEntityFaction(entity->GetId())).c_str());
                            ImGui::Separator();
                            static auto selectedFaction = (++factionmanager->m_idToIndexMap.begin())->first;
                            if(ImGui::BeginCombo("Faction", IfactionManager->GetFactionName(selectedFaction).c_str())){
                                for(auto faction : factionmanager->m_idToIndexMap){
                                    if(ImGui::Selectable(IfactionManager->GetFactionName(faction.first).c_str())){
                                        selectedFaction = faction.first;
                                    }
                                }
                                ImGui::EndCombo();
                            }
                            ImGui::Text("Relation to selected entity: %s", getDispositionStr(IfactionManager->GetEffectiveFactionDispositionToEntity(entity->GetId(), IfactionManager->GetFactionIndex(selectedFaction))).c_str());
                            if(ImGui::Button("Set Entity to Selected Faction")){
                                factionmanager->SetEntityFaction(entity->GetId(), IfactionManager->GetFactionIndex(selectedFaction));
                                gCLEnv->gui->logItem(std::string("Set Entity ") + entity->GetName() + " to Faction " + IfactionManager->GetFactionName(selectedFaction).c_str(), GetModuleName());
                            }
                            ImGui::EndTabItem();
                        }
                        if(npc!= nullptr) {
                            if (ImGui::BeginTabItem("Status Effects")) {
                                //"AIAlwaysUpdate",AIAlwaysUpdateForPatrol",AttentionDrainLockOnTarget",DisableAiTree",DisableAllAmbientSounds",DisableAttentionAndSenses",DisableAttentionObjectAndPerceivable "DisableAudible",DisableBreakable",DisableDeathReactions",DisableHearing",DisableHitReactions",DisableLifetimeEffect",DisableNpcHealthUI",DisableOperatorLevitatorsEffect",DisableSenses",DisableVisible",DisableVision",Dumbed",EnableAbilities",EnableAiTree",EnableAttentionObject",
                                if (ImGui::Button("Push AI Always Update")) {
                                    npc->PushAIAlwaysUpdate();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop AI Always Update")) {
                                    npc->PopAIAlwaysUpdate();
                                }
                                if (ImGui::Button("Push AI Always Update For Patrol")) {
                                    npc->PushAIAlwaysUpdateForPatrol();
                                }
//                            ImGui::SameLine();
//                            if(ImGui::Button("Pop AI Always Update For Patrol")){
//                                npc->PopAIAlwaysUpdateForPatrol();
//                            }
                                // NEEDS TARGET
//                            if(ImGui::Button("Push Attention Drain Lock On Target")){
//                                npc->PushAttentionDrainLockOnTarget();
//                            }
//                            ImGui::SameLine();
//                            if(ImGui::Button("Pop Attention Drain Lock On Target")){
//                                npc->PopAttentionDrainLockOnTarget();
//                            }
                                if (ImGui::Button("Push Disable AI Tree")) {
                                    npc->PushDisableAiTree();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable AI Tree")) {
                                    npc->PopDisableAiTree();
                                }
                                if (ImGui::Button("Push Disable All Ambient Sounds")) {
                                    npc->PushDisableAllAmbientSounds();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable All Ambient Sounds")) {
                                    npc->PopDisableAllAmbientSounds();
                                }
                                if (ImGui::Button("Push Disable Attention And Senses")) {
                                    npc->PushDisableAttentionAndSenses();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Attention And Senses")) {
                                    npc->PopDisableAttentionAndSenses();
                                }
                                if (ImGui::Button("Push Disable Attention Object And Perceivable")) {
                                    npc->PushDisableAttentionObjectAndPerceivables();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Attention Object And Perceivable")) {
                                    npc->PopDisableAttentionObjectAndPerceivables();
                                }
                                if (ImGui::Button("Push Disable Audible")) {
                                    npc->PushDisableAudible();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Audible")) {
                                    npc->PopDisableAudible();
                                }
                                if (ImGui::Button("Push Disable Breakable")) {
                                    npc->PushDisableBreakable();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Breakable")) {
                                    npc->PopDisableBreakable();
                                }
                                if (ImGui::Button("Push Disable Death Reactions")) {
                                    npc->PushDisableDeathReactions();
                                }
//                            ImGui::SameLine();
//                            if(ImGui::Button("Pop Disable Death Reactions")){
//                                npc;
//                            }
                                if (ImGui::Button("Push Disable Hearing")) {
                                    npc->PushDisableHearing();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Hearing")) {
                                    npc->PopDisableHearing();
                                }
                                if (ImGui::Button("Push Disable Hit Reactions")) {
                                    npc->PushDisableHitReactions();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Hit Reactions")) {
                                    npc->PopDisableHitReactions();
                                }
                                if (ImGui::Button("Push Disable Lifetime Effect")) {
                                    npc->PushDisableLifetimeEffect();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Lifetime Effect")) {
                                    npc->PopDisableLifetimeEffect();
                                }
                                if (ImGui::Button("Push Disable Npc Health UI")) {
                                    npc->PushDisableNpcHealthUI();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Npc Health UI")) {
                                    npc->PopDisableNpcHealthUI();
                                }
                                if (ImGui::Button("Push Disable Operator Levitators Effect")) {
                                    npc->PushDisableOperatorLevitatorsEffect();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Operator Levitators Effect")) {
                                    npc->PopDisableOperatorLevitatorsEffect();
                                }
                                if (ImGui::Button("Push Disable Senses")) {
                                    npc->PushDisableSenses();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Senses")) {
                                    npc->PopDisableSenses();
                                }
                                if (ImGui::Button("Push Disable Visible")) {
                                    npc->PushDisableVisible();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Disable Visible")) {
                                    npc->PopDisableVisible();
                                }
                                if (ImGui::Button("Push Enable Abilities")) {
                                    npc->PushEnableAbilities();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Abilities")) {
                                    npc->PopEnableAbilities();
                                }
                                //EnableAttentiveSubject",EnableAudible",EnableGlassBreaking",EnableHearing",EnableLifetimeEffect",EnableOperatorLevitatorsEffect",EnableRoomPerceiver",EnableVisible",EnableVision",EnabledAmbientSound",Fear",ForceRigidOnGloo",IndefiniteRagdoll"
                                if (ImGui::Button("Push Enable Attentive Subject")) {
                                    npc->PushEnableAttentiveSubject();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Attentive Subject")) {
                                    npc->PopEnableAttentiveSubject();
                                }
                                if (ImGui::Button("Push Enable Audible")) {
                                    npc->PushEnableAudible();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Audible")) {
                                    npc->PopEnableAudible();
                                }
                                if (ImGui::Button("Push Enable Glass Breaking")) {
                                    npc->PushEnableGlassBreaking();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Glass Breaking")) {
                                    npc->PopEnableGlassBreaking();
                                }
                                if (ImGui::Button("Push Enable Hearing")) {
                                    npc->PushEnableHearing();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Hearing")) {
                                    npc->PopEnableHearing();
                                }
                                if (ImGui::Button("Push Enable Lifetime Effect")) {
                                    npc->PushEnableLifetimeEffect();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Lifetime Effect")) {
                                    npc->PopEnableLifetimeEffect();
                                }
                                if (ImGui::Button("Push Enable Operator Levitators Effect")) {
                                    npc->PushEnableOperatorLevitatorsEffect();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Operator Levitators Effect")) {
                                    npc->PopEnableOperatorLevitatorsEffect();
                                }
                                if (ImGui::Button("Push Enable Room Perceiver")) {
                                    npc->PushEnableRoomPerceiver();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Room Perceiver")) {
                                    npc->PopEnableRoomPerceiver();
                                }
                                if (ImGui::Button("Push Enable Vision")) {
                                    npc->PushEnableVision();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Vision")) {
                                    npc->PopEnableVision();
                                }
                                if (ImGui::Button("Push Enable Visible")) {
                                    npc->PushEnableVisible();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Enable Visible")) {
                                    npc->PopEnableVisible();
                                }
                                // needs sound id
//                            if(ImGui::Button("Push Enabled Ambient Sound")){
//                                npc->PushEnabledAmbientSound();
//                            }
//                            ImGui::SameLine();
//                            if(ImGui::Button("Pop Enabled Ambient Sound")){
//                                npc->PopEnabledAmbientSound();
//                            }
//                            needs parameter setup
//                            if(ImGui::Button("Push Fear")){
//                                npc->PushFear();
//                            }
//                            ImGui::SameLine();
//                            if(ImGui::Button("Pop Fear")){
//                                npc->PopFear();
//                            }
                                if (ImGui::Button("Push Force Rigid On Gloo")) {
                                    npc->PushForceRigidOnGloo();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Force Rigid On Gloo")) {
                                    npc->PopForceRigidOnGloo();
                                }
                                if (ImGui::Button("Push Indefinite Ragdoll")) {
                                    npc->PushIndefiniteRagdoll();
                                }
                                ImGui::SameLine();
                                if (ImGui::Button("Pop Indefinite Ragdoll")) {
                                    npc->PopIndefiniteRagdoll();
                                }


//                            static std::string selectedStatus;
//                            // if(ImGui::BeginChild("status list", ImVec2(0, ImGui::GetContentRegionAvail().y * 0.6f))){
//                            if (ImGui::BeginTable("statusList", 1, ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersOuter,
//                                                  ImVec2(0, ImGui::GetContentRegionAvail().y * 0.8f))) {
//                                ImGui::TableSetupColumn("Status");
//                                ImGui::TableHeadersRow();
//                                for (auto itr = statusPush.begin(); itr != statusPush.end(); ++itr) {
//                                    ImGui::TableNextRow();
//                                    // if(ImGui::TreeNode((itr)->c_str())) {
//                                    // ImGui::Text("%s", itr->c_str());
//                                    ImGui::TableSetColumnIndex(0);
//                                    if (ImGui::Selectable(itr->c_str(), *itr == selectedStatus)) {
//                                        selectedStatus = *itr;
//                                    }
//                                }
//                                ImGui::EndTable();
//                            }
//                            ImGui::Text("%s", selectedStatus.c_str());
//                            if (std::find(statusPush.begin(), statusPush.end(), selectedStatus) != statusPush.end()) {
//                                ImGui::Button("Push");
//                            }
//                            if (std::find(statusPop.begin(), statusPop.end(), selectedStatus) != statusPop.end()) {
//                                ImGui::SameLine();
//                                ImGui::Button("Pop");
//                            }
                                ImGui::EndTabItem();
                            }
#if 0
                            if (ImGui::BeginTabItem("Npc Details")) {
//                                ActiveEthericDoppelgangerId,AmmoCount,AttachedPistolId,Attachment,AttentionOnPlayer,CachedThrowAtLocation,CachedThrowAtType,CharacterEffectsManager,ComplexHearingGain,ComplexVisionGain,CurrentAbilityContextId,CurrentCombatRole,DefaultFaction,DesiredSpeed,DodgeTimeStamp,EnergizedAmount,EntityPoolSignature,EthericDoppelgangerOwnerId,GlooEffect,HeadDirection,HeadPosition,HitReactKnockDownTimeStamp,HitReactStaggerTimeStamp,IsHitReactingPrereqFlag,IsRegainingLosPrereqFlag,IsShuttingDownHack,IsTakingDamagePrereqFlag,LastPerformedContextId,LeaderId,MaterialAnimationDuration,MaterialAnimationManager,MimicingEntityId,MimicryReason,MovementRequestId,NpcManagerCombatPoints,NumControlledTurrets,NumCorruptedNpcs,PhysicalEntitiesInBox,Properties,RMIBase,SearchReasonFromChangeReason,TopAttentionTargetEntityId"
                                ImGui::Text("ActiveEthericDoppelgangerId: %d", npc->GetActiveEthericDoppelgangerId());
                                ImGui::Text("AmmoCount: %d", npc->GetAmmoCount());
                                ImGui::Text("AttachedPistolId: %d", npc->GetAttachedPistolId());
                                ImGui::Text("CachedThrowAtLocation: %f %f %f", npc->GetCachedThrowAtLocation().x, npc->GetCachedThrowAtLocation().y, npc->GetCachedThrowAtLocation().z);
                                ImGui::Text("CachedThrowAtType: %d", npc->GetCachedThrowAtType());
                                ImGui::Text("CharacterEffectsManager: %p", &npc->GetCharacterEffectsManager());
                                ImGui::Text("ComplexHearingGain: %f", npc->GetComplexHearingGain());
                                ImGui::Text("ComplexVisionGain: %f", npc->GetComplexVisionGain());
                                ImGui::Text("CurrentAbilityContextId: %llu", npc->GetCurrentAbilityContextId());
                                ImGui::Text("CurrentCombatRole: %d", npc->GetCurrentCombatRole());
                                ImGui::Text("DefaultFaction: %d", npc->GetDefaultFaction());
                                ImGui::Text("DesiredSpeed: %d", npc->GetDesiredSpeed());
//                                ImGui::Text("DodgeTimeStamp: %d", npc->GetDodgeTimeStamp().);
                                ImGui::Text("EnergizedAmount: %f", npc->GetEnergizedAmount());
//                                ImGui::Text("EntityPoolSignature: %d", npc->GetEntityPoolSignature());
                                ImGui::Text("EthericDoppelgangerOwnerId: %d", npc->GetEthericDoppelgangerOwnerId());
                                ImGui::Text("GlooEffect: %p", npc->GetGlooEffect());
                                ImGui::Text("HeadDirection: %f %f %f", npc->GetHeadDirection().x, npc->GetHeadDirection().y, npc->GetHeadDirection().z);
                                ImGui::Text("HeadPosition: %f %f %f", npc->GetHeadPosition().x, npc->GetHeadPosition().y, npc->GetHeadPosition().z);
//                                ImGui::Text("HitReactKnockDownTimeStamp: %d", npc->GetHitReactKnockDownTimeStamp());
//                                ImGui::Text("HitReactStaggerTimeStamp: %d", npc->GetHitReactStaggerTimeStamp());
                                ImGui::Text("IsHitReactingPrereqFlag: %d", npc->GetIsHitReactingPrereqFlag());
                                ImGui::Text("IsRegainingLosPrereqFlag: %d", npc->GetIsRegainingLosPrereqFlag());
                                ImGui::Text("IsShuttingDownHack: %d", npc->GetIsShuttingDown_Hack());
                                ImGui::Text("IsTakingDamagePrereqFlag: %d", npc->GetIsTakingDamagePrereqFlag());
                                ImGui::Text("LastPerformedContextId: %llu", npc->GetLastPerformedContextId());
                                ImGui::Text("LeaderId: %d", npc->GetLeaderId());
//                                ImGui::Text("MaterialAnimationDuration: %f", npc->GetMaterialAnimationDuration());
                                ImGui::Text("MaterialAnimationManager: %p", &npc->GetMaterialAnimationManager());
                                ImGui::Text("MimicingEntityId: %d", npc->GetMimicingEntityId());
                                ImGui::Text("MimicryReason: %d", npc->GetMimicryReason());
//                                ImGui::Text("MovementRequestId: %d", npc->GetMovementRequestId().id);
                                ImGui::Text("NpcManagerCombatPoints: %d", npc->GetNpcManagerCombatPoints());
                                ImGui::Text("NumControlledTurrets: %d", npc->GetNumControlledTurrets());
                                ImGui::Text("NumCorruptedNpcs: %d", npc->GetNumCorruptedNpcs());
//                                ImGui::Text("PhysicalEntitiesInBox: %d", npc.);
//                                ImGui::Text("Properties: %d", npc->GetProperties().);
//                                ImGui::Text("RMIBase: %p", npc->GetRMIBase());
//                                ImGui::Text("SearchReasonFromChangeReason: %d", npc.getse;
//                                ImGui::Text("TopAttentionTargetEntityId: %d", npc->GetTopAttentionTargetEntityId());


//                                if (ImGui::BeginTable("SettableGettables", 2,
//                                                      ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersH |
//                                                      ImGuiTableFlags_BordersInnerV)) {
//                                    ImGui::TableSetupColumn("Readable", ImGuiTableColumnFlags_WidthFixed,
//                                                            ImGui::GetContentRegionAvail().x * 0.5f);
//                                    ImGui::TableSetupColumn("Writable", ImGuiTableColumnFlags_WidthFixed,
//                                                            ImGui::GetContentRegionAvail().x * 0.5f);
//                                    ImGui::TableSetupScrollFreeze(0, 1);
//                                    ImGui::TableHeadersRow();
//                                    auto itrget = get.begin();
//                                    auto itrset = set.begin();
//                                    bool setend = false, getend = false;
//                                    while (itrset != set.end() || itrget != get.end()) {
//                                        ImGui::TableNextRow();
//                                        if (!getend) {
//                                            ++itrget;
//                                            if (itrget == get.end()) {
//                                                getend = true;
//                                            }
//                                        }
//                                        if (!getend) {
//                                            ImGui::TableSetColumnIndex(0);
//                                            ImGui::Text("%s", itrget->c_str());
//                                            ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - 10.0f);
//                                            std::string text = "0";
//                                            ImGui::InputText("##NPC", &text, ImGuiInputTextFlags_ReadOnly);
//                                            ImGui::PopItemWidth();
//                                        } else {
//
//                                        }
//                                        if (!setend) {
//                                            ++itrset;
//                                            if (itrset == set.end()) {
//                                                setend = true;
//                                            }
//                                        }
//                                        if (!setend) {
//                                            ImGui::TableSetColumnIndex(1);
//                                            ImGui::Text("%s", itrset->c_str());
//                                            ImGui::PushItemWidth(
//                                                    ImGui::GetContentRegionAvail().x -
//                                                    ImGui::CalcTextSize(" Set   ").x);
//                                            std::string text = "0";
//                                            ImGui::InputText("", &text, ImGuiInputTextFlags_ReadOnly);
//                                            ImGui::SameLine();
//                                            ImGui::Button("Set");
//                                            ImGui::PopItemWidth();
//                                        } else {
//
//                                        }
//                                    }
//                                    ImGui::EndTable();
//                                }
                                ImGui::EndTabItem();
                            }
#endif
                            if(ImGui::BeginTabItem("Npc Properties")){
                                auto properties = npc->GetProperties();
                                ImGui::EndTabItem();
                            }
                            if (ImGui::BeginTabItem("Npc Info")) {
                                if (ImGui::BeginTable("IsTable", 2,
                                                      ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_BordersH |
                                                      ImGuiTableFlags_ScrollY, ImGui::GetContentRegionAvail())) {
                                    ImGui::TableSetupColumn("Param");
                                    ImGui::TableSetupColumn("Value");
                                    for (auto itr = is.begin(); itr != is.end(); ++itr) {
                                        ImGui::TableNextRow();
                                        ImGui::TableSetColumnIndex(0);
                                        // RightAlignText(itr->c_str());
                                        ImGui::Text("%s", itr->c_str());
                                        // ImGui::SetCursorPosX(ImGui::GetColumnWidth(1));
                                        ImGui::TableSetColumnIndex(1);
                                        ImGui::Text("True");
                                    }
                                    ImGui::EndTable();
                                }
                                // ImGui::ListBox("")
                                ImGui::EndTabItem();
                            }

                        }
                        if (ImGui::BeginTabItem("Actions:")) {

                            ImGui::EndTabItem();
                        }
                    }
                    else {
                        ImGui::Text("No Entity Selected");
                    }
                    // ENDTODO
                    ImGui::EndTabBar();
                }
                ImGui::EndChild();
                // if (ImGui::Button("Revert")) {}
                // ImGui::SameLine();
                // if (ImGui::Button("Save")) {}
                ImGui::EndGroup();
            }
        }
        ImGui::End();
    }
}

void EntityManager::drawMenuBar() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Entity")) {
            if (ImGui::BeginMenu("Spawn Entity")) {
                ImGui::MenuItem("Spawn Last Spawned", nullptr, false, archetypeToSpawn != 0);
                ImGui::Separator();
                ImGui::TextDisabled("Quick Spawns");
                if (ImGui::BeginMenu("Spawn Typhon")) {
                    if (ImGui::BeginMenu("Mimics")) {
                        if (ImGui::MenuItem("Mimic"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Mimics.Mimic);
                        if (ImGui::MenuItem("Greater Mimic"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Mimics.EliteMimic);
                        ImGui::EndMenu();
                    }
                    if (ImGui::BeginMenu("Phantoms")) {
                        if (ImGui::MenuItem("Normal"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Phantoms.BasePhantom);
                        if (ImGui::MenuItem("Thermal"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Phantoms.ThermalPhantom);
                        if (ImGui::MenuItem("Etheric"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Phantoms.EthericPhantom);
                        if (ImGui::MenuItem("Voltaic"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Phantoms.VoltaicPhantom);
                        ImGui::EndMenu();
                    }
                    if (ImGui::MenuItem("Nightmare"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.ArkNightmare);
                    if (ImGui::MenuItem("Poltergeist"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.ArkPoltergeist);
                    if (ImGui::MenuItem("Telepath"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Overseers.Telepath);
                    if (ImGui::MenuItem("Technopath"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkNpcs.Overseers.Technopath);
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Spawn Operator")) {
                    if (ImGui::MenuItem("Medical"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkRobots.Operators.Generic.MedicalOperator);
                    if (ImGui::MenuItem("Engineering"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkRobots.Operators.Generic.EngineeringOperator);
                    if (ImGui::MenuItem("Science"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkRobots.Operators.Generic.ScienceOperator);
                    if (ImGui::MenuItem("Military"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkRobots.Operators.Generic.MilitaryOperator);
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Spawn Turrets")) {
                    if (ImGui::MenuItem("Turret"))
                        quickSpawnEntity(entityArchetypeLibrary.ArkRobots.Turrets.Turret_Default);
                    ImGui::EndMenu();
                }
                ImGui::Separator();
                if (ImGui::BeginMenu("Spawn Items")) {
                    if (ImGui::BeginMenu("Weapons")) {
                        if (ImGui::MenuItem("Wrench"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Weapons.Wrench);
                        if (ImGui::MenuItem("Shotgun"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Weapons.Shotgun);
                        if (ImGui::MenuItem("Shotgun Ammo"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Ammo.ShotgunShells);
                        if (ImGui::MenuItem("Pistol"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Weapons.Pistol);
                        if (ImGui::MenuItem("Pistol Ammo"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Ammo.PistolBullets);
                        if (ImGui::MenuItem("Gloo Gun"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Weapons.GooGun);
                        if (ImGui::MenuItem("Gloo Gun Ammo"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Ammo.GooGun);
                        if (ImGui::MenuItem("Q Beam"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Weapons.Instalaser);
                        if (ImGui::MenuItem("Q Beam Ammo"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Ammo.InstaLaser);
                        if (ImGui::MenuItem("Stun Gun"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Weapons.StunGun);
                        if (ImGui::MenuItem("Stun Gun Ammo"))
                            quickSpawnEntity(entityArchetypeLibrary.ArkPickups.Ammo.StunGunAmmo);
                        ImGui::EndMenu();
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
            if(ImGui::MenuItem("List Classes")){
               CEntityClassRegistry* registry = ((CEntityClassRegistry*)gEnv->pEntitySystem->GetClassRegistry());
               for(auto &entityClass : registry->m_mapClassName){
                    CryLog("%s", entityClass.second->GetName());

               }
//                for(auto &class = gEnv.pEntitySystem.)
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Toggle All")) {
                if (showEntityList && showEntitySpawner) {
                    showEntityList = false;
                    showEntitySpawner = false;
                }
                else {
                    showEntityList = true;
                    showEntitySpawner = true;
                }
            }
            ImGui::MenuItem("Show Entity List", nullptr, &showEntityList);
            ImGui::MenuItem("Show Entity Spawner", nullptr, &showEntitySpawner);
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}


void EntityManager::spawnEntity() {
    try {
        if (archetypeToSpawn != 0) {
            static Vec3 pos;
            static Quat rot = Quat{ 0,0,0,1 };
            archetypeToSpawn;
            usePlayerPos;
            offsetFromPlayer;
            if (usePlayerPos) {
                pos = gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetPos();
                if (offsetFromPlayer) {
                    pos.x += gCLEnv->entUtils->ArkPlayerPtr()->m_cachedReticleDir.x * offsetDistance[1];
                    pos.y += gCLEnv->entUtils->ArkPlayerPtr()->m_cachedReticleDir.y * offsetDistance[1];
                    pos.z += offsetDistance[2];
                }
            }
            else {
                pos = Vec3{ spawnX, spawnY, spawnZ };
            }
            auto archetype = gEnv->pEntitySystem->GetEntityArchetype(archetypeToSpawn);
            std::string archetypeName = archetype->GetName();
            // if an npc use npc spawning
            auto entityClass = archetype->GetClass();
            if(entityClass != nullptr) {

                if (entityClass->GetName() == std::string(gClassLibrary.ArkNightmare) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkHuman) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkHumanTest) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkApexTentacle) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkApexTentacleHead) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkBeta) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkEtherDuplicate) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkEtherForm) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkEthericDoppelganger) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkMimic) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkMimicElite) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkNpcPlayer) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperator) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorEngineer) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorMedic) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorScience) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorMilitary) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkPlayer) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkPoltergeist) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkPhantomVoltaic) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkTelepath) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkTentacle) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkWeaver) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkTechnopath) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkCystoidNest))
                // TODO: ADD ability for mods to define what their archetypes are
                // TODO: add cystoid support
                {
                    auto entity = gCLEnv->entUtils->spawnNpc(inputName.c_str(), pos, rot, archetype->GetId(), spawnCount);
                    if(entity != nullptr){
                        if(selectedSpawnerFaction != 0){
                            static_cast<ArkFactionManager*>(gEnv->pGame->GetIArkFactionManager())->SetEntityFaction(entity->GetId(), gEnv->pGame->GetIArkFactionManager()->GetFactionIndex(selectedSpawnerFaction));
                        }
                    }
                } else {
                    gCLEnv->entUtils->spawnEntity(inputName.c_str(), pos, rot, archetype->GetId(), spawnCount);
                }
            }
            // done
            color = { 1,1,1,1 };
            statusMessage = "spawned an entity: " + inputName;
            time(&statusTimer);
        }
        else {
            throw("Error, no archetype selected");
        }
    }
    catch (const char* c) {
        color = { 1,0,0,1 };
        statusMessage = c;
        time(&statusTimer);
    }
}

void EntityManager::quickSpawnEntity(uint64_t archetypeId) {
    try {
        if (gEnv->pEntitySystem->GetEntityArchetype(archetypeId) != nullptr) {
            static Vec3 pos;
            static Quat rot = Quat{ 0,0,0,1 };
            pos = ArkPlayer::GetInstancePtr()->GetEntity()->GetPos();
            pos.x += ArkPlayer::GetInstancePtr()->m_cachedReticleDir.x * 5;
            pos.y += ArkPlayer::GetInstancePtr()->m_cachedReticleDir.y * 5;
            std::string archetypeName = gEnv->pEntitySystem->GetEntityArchetype(archetypeId)->GetName();

            auto archetype = gEnv->pEntitySystem->GetEntityArchetype(archetypeId);
            auto entityClass = archetype->GetClass();
            if(entityClass != nullptr) {
                if (entityClass->GetName() == std::string(gClassLibrary.ArkNightmare) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkHuman) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkHumanTest) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkApexTentacle) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkApexTentacleHead) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkBeta) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkEtherDuplicate) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkEtherForm) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkEthericDoppelganger) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkMimic) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkMimicElite) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkNpcPlayer) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperator) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorEngineer) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorMedic) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorScience) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkOperatorMilitary) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkPlayer) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkPoltergeist) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkPhantomVoltaic) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkTelepath) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkTentacle) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkWeaver) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkTechnopath) ||
                    entityClass->GetName() == std::string(gClassLibrary.ArkCystoidNest))
                    // TODO: ADD ability for mods to define what their archetypes are
                    // TODO: add cystoid support
                {
                    gCLEnv->entUtils->spawnNpc("", pos, rot, archetypeId, spawnCount);
                } else {
                    gCLEnv->entUtils->spawnEntity("", pos, rot, archetypeId, spawnCount);
                }
            } else {
                throw("Error, no class found");
            }
            gCLEnv->gui->logItem("spawned an entity: " + inputName, moduleName);
        }
        else {
            throw("Error, no archetype found");
        }
    }
    catch (std::string& c) {
        gCLEnv->gui->logItem(c, moduleName, logLevel::error);
    }
}



void EntityManager::Draw() {
    drawMenuBar();
    drawEntityList(&showEntityList);
    drawEntitySpawner(&showEntitySpawner);
}

void EntityManager::Update() {

}