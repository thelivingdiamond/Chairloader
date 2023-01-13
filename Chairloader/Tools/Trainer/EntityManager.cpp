#include "ChairLoader/pch.h"
#include "EntityManager.h"

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

EntityManager::EntityManager() {
    oldArchetypeFilterText = " ";
    InitGame();
}

EntityManager::~EntityManager() {

}
static uint64_t selectedSpawnerFaction = 0;
static float offsetDistance[3] = {0,5,0};
void EntityManager::drawEntitySpawner(bool* bShow) {
    if(showEntitySpawner){
        if (ImGui::Begin("Entity Spawner", bShow, ImGuiWindowFlags_NoNavInputs)) {
            ImGui::TextColored(color, statusMessage.c_str());

            if (archetypeToSpawn == 0 || gEnv->pEntitySystem->GetEntityArchetype(archetypeToSpawn) == nullptr) {
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
//            static std::string archetypeLoadString;
//            ImGui::InputText("Archetype Library to Load", &archetypeLoadString, ImGuiInputTextFlags_None);
//            if (ImGui::Button("Load Archetype Library")) {
//                auto archetypeLibrary = string(archetypeLoadString.c_str());
//                gEnv->pEntitySystem->LoadArchetypeLibrary(&archetypeLibrary);
//    //            GetEntitySystem()->m_pEntityArchetypeManager->LoadLibrary(archetypeLoadString.c_str());
//            }
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
                    if(archetype) {
                        ImGui::TableNextRow();
                        //Yeah boi
                        ImGui::TableSetColumnIndex(0);
                        if (archetype != nullptr) {
                            if (ImGui::Selectable(archetype->GetName(), archetypeToSpawn == archetype->GetId(),
                                                  ImGuiSelectableFlags_SpanAllColumns)) {
                                archetypeToSpawn = archetype->GetId();
                            }
                        }
                        ImGui::TableSetColumnIndex(1);
                        ImGui::Text("%llu", archetype->GetId());
                    }
                }

                if (time(nullptr) > statusTimer + 3)
                    statusMessage = "";
                ImGui::EndTable();
            }
//            CRY_ASSERT(gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.ArkNightmare) != nullptr);
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
                hierarchy.ShowContents();
                ImGui::EndChild();
            }
            ImGui::SameLine();
            // Right
            {
                EntityId selectedEntity = hierarchy.GetSelectedEntity();
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
                        auto npc = EntityUtils::GetArkNpc(entity);
                        if (ImGui::BeginTabItem("Entity Details")) {
                            inspector.ShowContents(selectedEntity);
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
                                static float force[3] = {0, 0, 0};
                                ImGui::SliderFloat3("Force", force, -100, 100);
                                static bool useRandomDir;
                                ImGui::Checkbox("Random Direction", &useRandomDir);
                                if(ImGui::Button("Random Direction")){
                                }
                                if(ImGui::Button("Apply Force")){
                                    if(useRandomDir){
                                        auto randomDir = cry_random_unit_vector<Vec3>();
                                        auto action = new pe_action_impulse;
                                        action->impulse = randomDir *= cry_random(0.0f, 100000.0f);
                                        physics->Action(action);
                                        delete action;
                                    } else {
                                        auto action = new pe_action_impulse;
                                        action->impulse = Vec3(force[0] * 100.0f, force[1] * 100.0f, force[2] * 100.0f);
                                        physics->Action(action);
                                        delete action;
                                    }

                                }
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
                                OverlayLog("Set Entity {} to Selected Faction {}", entity->GetName(), IfactionManager->GetFactionName(selectedFaction).c_str());
//                                gCL->gui->logItem(std::string("Set Entity ") + entity->GetName() + " to Faction " + IfactionManager->GetFactionName(selectedFaction).c_str(), GetModuleName());
                            }
                            ImGui::EndTabItem();
                        }
                        if (ImGui::BeginTabItem("Actions:")) {
                            // Entity Actions here
                            ImGui::Text("Hidden: {}", entity->IsHidden() ? "true" : "false");
                            if(ImGui::Button("Toggle Hidden")){
                                entity->Hide(!entity->IsHidden());
                            }
                            static std::string nameSet;
                            nameSet = entity->GetName();
                            if(ImGui::InputText("Name", &nameSet))
                                entity->SetName(nameSet.c_str());
                            ImGui::Text("Invisible: {}", entity->IsInvisible() ? "true" : "false");
                            if(ImGui::Button("Toggle Invisible")){
                                entity->Invisible(!entity->IsInvisible());
                            }
                            if(npc != nullptr){
                                static float timeUntilDeath = 0.0f;
                                ImGui::InputFloat("Time Until Death", &timeUntilDeath);
                                if(ImGui::Button("Set Time Until death"))
                                    npc->SetTimeUntilDeath(timeUntilDeath);
                                static bool pistolHidden;
                                if(ImGui::Checkbox("Pistol Hidden", &pistolHidden)){
                                    npc->SetPistolHidden(pistolHidden);
                                }
                                if(ImGui::Button("Set Played Controlled (IDK WHAT THIS DOES)"))
                                    npc->SetIsPlayerControlled();
                            }
                            ImGui::EndTabItem();
                        }
                        if(npc!= nullptr) {
                            if (ImGui::BeginTabItem("Npc Info")) {
                                if(ImGui::BeginTable("Npc Infos", 2)){
                                    ImGui::TableSetupColumn("Category");
                                    ImGui::TableSetupColumn("Value");
                                    //"IsAlert", "IsAsleep", "IsAttentionProxyFollowing", "IsBreakable", "IsBroken", "IsCharacterEffectEnabled", "IsCorrupted", "IsCowering", "IsDead", "IsDestroyed", "IsDissipating", "IsDormant", "IsEntityMimicable", "IsEthericDoppelganger", "IsFalling", "IsFeared", "IsFollowingPlayer",
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Alert");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsAlert() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Asleep");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsAsleep() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Attention Proxy Following Player");
                                    ImGui::TableNextColumn();
                                    if(ArkPlayer::GetInstancePtr() != nullptr){
                                        ImGui::Text("%s", npc->IsAttentionProxyFollowing(ArkPlayer::GetInstancePtr()->GetEntityId()) ? "true" : "false");
                                    } else {
                                        ImGui::Text("%s", "unknown");
                                    }
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Breakable");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsBreakable() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Broken");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsBroken() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Is Character Effect Enabled");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->IsCharacterEffectEnabled() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Corrupted");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsCorrupted() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Cowering");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsCowering() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Dead");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsDead() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Destroyed");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsDestroyed() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Dissipating");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsDissipating() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Dormant");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsDormant() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Is Entity Mimicable");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->IsEntityMimicable() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Etheric Doppelganger");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsEthericDoppelganger() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Falling");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsFalling() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Feared");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsFeared() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Following Player");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsFollowingPlayer() ? "true" : "false");
                                    //"IsGlooSlow", "IsGoingToFreezeInGloo", "IsHacked", "IsIgnoringRangedAbilities", "IsInRaiseFromCorpseAnim", "IsJumping", "IsLureFlareValid", "IsLurking", "IsMimic", "IsMimicking", "IsMindControlled", "IsMovementAnimated", "IsMovementDesireExecuting", "IsMovementInterruptible", "IsNpcHealthUIDisabled", "IsPerformingAbility", "IsPlayerControlled"
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Gloo Slow");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsGlooSlow() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Going To Freeze In Gloo");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsGoingToFreezeInGloo() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Hacked");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsHacked() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Ignoring Ranged Abilities");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsIgnoringRangedAbilities() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is In Raise From Corpse Anim");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsInRaiseFromCorpseAnim() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Jumping");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsJumping() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Is Lure Flare Valid");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->IsLureFlareValid() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Lurking");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsLurking() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Mimic");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsMimic() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Mimicking");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsMimicking() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Mind Controlled");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsMindControlled() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Movement Animated");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsMovementAnimated() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Is Movement Desire Executing");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->IsMovementDesireExecuting() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Movement Interruptible");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsMovementInterruptible() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Npc Health UI Disabled");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsNpcHealthUIDisabled() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Performing Ability");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsPerformingAbility() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Player Controlled");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsPlayerControlled() ? "true" : "false");
                                    // "IsPsiLifted", "IsPsiSuppressed", "IsRagdolled", "IsResisting", "IsScrunched", "IsShifting", "IsStandingUp", "IsStunned", "IsVisible", "IsVulnerable", "IsWithinCameraViewCone", "IsXRayTrackingTarget", "CanAttachGloo", "CanBeDistracted", "CanBeHypnotized", "CanDeathReact", "CanHitReact", "CanInstigate", "CanJump", "CanMimicSideStepLeft", "CanMimicSideStepRight", "CanPerformAbilityContext", "CanPerformAnimatedAbility", "CanPerformFatality", "CanPerformHitReactShift"
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Psi Lifted");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsPsiLifted() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Psi Suppressed");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsPsiSuppressed() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Ragdolled");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsRagdolled() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Resisting");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsResisting() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Scrunched");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsScrunched() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Standing Up");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsStandingUp() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Stunned");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsStunned() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is Vulnerable");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->IsVulnerable() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Is Player Within Camera View Cone");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->IsWithinCameraViewCone() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Is XRay Tracking Player");
                                    ImGui::TableNextColumn();
                                    if(ArkPlayer::GetInstancePtr() != nullptr) {
                                        ImGui::Text("%s", npc->IsXRayTrackingTarget(ArkPlayer::GetInstancePtr()->GetEntityId()) ? "true" : "false");
                                    } else {
                                        ImGui::Text("%s", "unknown");
                                    }
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Attach Gloo");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanAttachGloo() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Be Distracted");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanBeDistracted() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Be Hypnotized");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanBeHypnotized() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Death React");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanDeathReact() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Can Hit React");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->CanHitReact() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Instigate");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanInstigate() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Jump");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanJump() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Mimic Side Step Left");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanMimicSideStepLeft() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Mimic Side Step Right");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanMimicSideStepRight() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Can Perform Ability Context");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->CanPerformAbilityContext() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Perform Animated Ability");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanPerformAnimatedAbility() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Perform Fatality");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanPerformFatality() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Perform Hit React Shift");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanPerformHitReactShift() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    //"CanPerformUnanimatedAbility", "CanRaiseAnotherPhantom", "CanSee", "CanSpeak"
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Perform Unanimated Ability");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanPerformUnanimatedAbility() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Raise Another Phantom");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanRaiseAnotherPhantom() ? "true" : "false");
//                                    ImGui::TableNextRow();
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("Can See");
//                                    ImGui::TableNextColumn();
//                                    ImGui::Text("%s", npc->CanSee() ? "true" : "false");
                                    ImGui::TableNextRow();
                                    ImGui::TableNextColumn();
                                    ImGui::Text("Can Speak");
                                    ImGui::TableNextColumn();
                                    ImGui::Text("%s", npc->CanSpeak() ? "true" : "false");
                                    ImGui::EndTable();
                                }
                                ImGui::EndTabItem();
                            }
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
                                auto & properties = npc->m_properties;
                                if(ImGui::TreeNode("Ability")){
                                    ImGui::Text("Ability Context Profile ID: %llu", properties.m_ability.m_abilityContextProfileId);
                                    ImGui::TreePop();
                                }
                                if(ImGui::TreeNode("Attention Facing")){
                                    ImGui::Text("Uses Attention Facing: %u", properties.m_attentionFacing.m_bUsesAttentionFacing);
                                    ImGui::Text("Uses Attention Look: %u", properties.m_attentionFacing.m_bUsesAttentionLook);
                                    ImGui::TreePop();
                                }
                                if(ImGui::TreeNode("Audio")){
                                    ImGui::Text("Distance to player param: %s", properties.m_audio.m_pDistanceToPlayerParam);
                                    ImGui::TreePop();
                                }
                                if(ImGui::TreeNode("Call For Help")){
                                    //uint64_t m_onAttackNoiseLoudness; uint64_t m_onAttackNoiseType; uint64_t m_onNewCombatAttentionNoiseLoudness; uint64_t m_onNewCombatAttentionNoiseType;
                                    ImGui::Text("On Attack Noise Loudness: %llu", properties.m_callForHelp.m_onAttackNoiseLoudness);
                                    ImGui::Text("On Attack Noise Type: %llu", properties.m_callForHelp.m_onAttackNoiseType);
                                    ImGui::Text("On New Combat Attention Noise Loudness: %llu", properties.m_callForHelp.m_onNewCombatAttentionNoiseLoudness);
                                    ImGui::Text("On New Combat Attention Noise Type: %llu", properties.m_callForHelp.m_onNewCombatAttentionNoiseType);
                                    ImGui::TreePop();
                                }
                                //Character
                                if(ImGui::TreeNode("Character")){
                                    ImGui::Text("Character: %llu", properties.m_character.m_characterId);
                                    ImGui::TreePop();
                                }
                                // combat role info
                                if(ImGui::TreeNode("Combat Role Info")){
//                                    bool m_bCanGetStaleInMeleeRole; bool m_bUsesCombatRoles; float m_meleeRoleCost; float m_meleeRolePreference; float m_meleeRoleScoreBias; float m_minDistanceToAllowRangeRoleSwitchSq;
                                    ImGui::Text("Can Get Stale In Melee Role: %u", properties.m_combatRoleInfo.m_bCanGetStaleInMeleeRole);
                                    ImGui::Text("Uses Combat Roles: %u", properties.m_combatRoleInfo.m_bUsesCombatRoles);
                                    ImGui::Text("Melee Role Cost: %f", properties.m_combatRoleInfo.m_meleeRoleCost);
                                    ImGui::Text("Melee Role Preference: %f", properties.m_combatRoleInfo.m_meleeRolePreference);
                                    ImGui::Text("Melee Role Score Bias: %f", properties.m_combatRoleInfo.m_meleeRoleScoreBias);
                                    ImGui::Text("Min Distance To Allow Range Role Switch Sq: %f", properties.m_combatRoleInfo.m_minDistanceToAllowRangeRoleSwitchSq);
                                    ImGui::TreePop();
                                }
                                //Control Turrets
                                if(ImGui::TreeNode("Control Turrets")){
                                    //uint64_t m_controlTurretsGameEffectId;
                                    ImGui::Text("Control Turrets Game Effect Id: %llu", properties.m_controlTurrets.m_controlTurretsGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Corrupt NPC
                                if(ImGui::TreeNode("Corrupt NPC")){
                                    //bool m_bReleaseCorruptionOnDeath;
                                    ImGui::Text("Release Corruption On Death: %u", properties.m_corruptNpc.m_bReleaseCorruptionOnDeath);
                                    ImGui::TreePop();
                                }
                                //Corruption
                                if(ImGui::TreeNode("Corruption")){
                                    //	bool m_bDeletedOnLevelLoadAndUncorrupted; bool m_bShouldGoUnconsciousOnUncorruption; bool m_bStartCorrupted; const char *m_pMovementGlitchAttachmentName1; const char *m_pMovementGlitchAttachmentName2; ArkAudioTrigger m_becomeCorruptedAudioTrigger; uint64_t m_corruptedGameEffectId; uint64_t m_uncorruptedMetaTagId; _smart_ptr<IParticleEffect> m_pCorruptedMovementGlitchParticleEffect;
                                    ImGui::Text("Deleted On Level Load And Uncorrupted: %u", properties.m_corruption.m_bDeletedOnLevelLoadAndUncorrupted);
                                    ImGui::Text("Should Go Unconscious On Uncorruption: %u", properties.m_corruption.m_bShouldGoUnconsciousOnUncorruption);
                                    ImGui::Text("Start Corrupted: %u", properties.m_corruption.m_bStartCorrupted);
                                    ImGui::Text("Movement Glitch Attachment Name 1: %s", properties.m_corruption.m_pMovementGlitchAttachmentName1);
                                    ImGui::Text("Movement Glitch Attachment Name 2: %s", properties.m_corruption.m_pMovementGlitchAttachmentName2);
//                                    ImGui::Text("Become Corrupted Audio Trigger: %u", properties.m_corruption.m_becomeCorruptedAudioTrigger.m_controlId);
                                    ImGui::Text("Corrupted Game Effect Id: %llu", properties.m_corruption.m_corruptedGameEffectId);
                                    ImGui::Text("Uncorrupted Meta Tag Id: %llu", properties.m_corruption.m_uncorruptedMetaTagId);
                                    ImGui::Text("Corrupted Movement Glitch Particle Effect: %p", properties.m_corruption.m_pCorruptedMovementGlitchParticleEffect.get());
                                    ImGui::TreePop();
                                    //Damage States
                                }
                                if(ImGui::TreeNode("Damage States")){
                                    // bool m_bHasDamageStates;float m_healthThresholdDamage;float m_healthThresholdDisabled;float m_destroyedExplosionRadius;float m_destroyedExplosionImpulse;float m_destroyedExplosionDelay;float m_destroyedHeightOffset;float m_disabledRepeatDialogCD;float m_disabledFlickerDuration;const char *m_pUndamagedAttachmentName;const char *m_pDamagedAttachmentName;const char *m_pDisabledAttachmentName;const char *m_pChassisModelName;const char *m_pChassisUndamagedAttachmentName;const char *m_pChassisDestroyedAttachmentName;ArkAudioTrigger m_becomeUndamagedAudioTrigger;ArkAudioTrigger m_becomeDamagedAudioTrigger;ArkAudioTrigger m_becomeDisabledAudioTrigger;uint64_t m_destroyedExplosionPackageId;uint64_t m_destroyedExplosionCameraShakeId;
                                    ImGui::Text("Has Damage States: %u", properties.m_damageStates.m_bHasDamageStates);
                                    ImGui::Text("Health Threshold Damage: %f", properties.m_damageStates.m_healthThresholdDamage);
                                    ImGui::Text("Health Threshold Disabled: %f", properties.m_damageStates.m_healthThresholdDisabled);
                                    ImGui::Text("Destroyed Explosion Radius: %f", properties.m_damageStates.m_destroyedExplosionRadius);
                                    ImGui::Text("Destroyed Explosion Impulse: %f", properties.m_damageStates.m_destroyedExplosionImpulse);
                                    ImGui::Text("Destroyed Explosion Delay: %f", properties.m_damageStates.m_destroyedExplosionDelay);
                                    ImGui::Text("Destroyed Height Offset: %f", properties.m_damageStates.m_destroyedHeightOffset);
                                    ImGui::Text("Disabled Repeat Dialog CD: %f", properties.m_damageStates.m_disabledRepeatDialogCD);
                                    ImGui::Text("Disabled Flicker Duration: %f", properties.m_damageStates.m_disabledFlickerDuration);
                                    ImGui::Text("Undamaged Attachment Name: %s", properties.m_damageStates.m_pUndamagedAttachmentName);
                                    ImGui::Text("Damaged Attachment Name: %s", properties.m_damageStates.m_pDamagedAttachmentName);
                                    ImGui::Text("Disabled Attachment Name: %s", properties.m_damageStates.m_pDisabledAttachmentName);
                                    ImGui::Text("Chassis Model Name: %s", properties.m_damageStates.m_pChassisModelName);
                                    ImGui::Text("Chassis Undamaged Attachment Name: %s", properties.m_damageStates.m_pChassisUndamagedAttachmentName);
                                    ImGui::Text("Chassis Destroyed Attachment Name: %s", properties.m_damageStates.m_pChassisDestroyedAttachmentName);
                                    ImGui::Text("destroyedExplosionPackageId: %llu", properties.m_damageStates.m_destroyedExplosionPackageId);
                                    ImGui::Text("destroyedExplosionCameraShakeId: %llu", properties.m_damageStates.m_destroyedExplosionCameraShakeId);
                                    ImGui::TreePop();
                                }
                                // Dodge
                                if(ImGui::TreeNode("Dodge")){
                                    //bool m_bEnabled; float m_chance; float m_cooldown; uint64_t m_damagePackageId;
                                    ImGui::Text("Enabled: %u", properties.m_dodge.m_bEnabled);
                                    ImGui::Text("Chance: %f", properties.m_dodge.m_chance);
                                    ImGui::Text("Cooldown: %f", properties.m_dodge.m_cooldown);
                                    ImGui::Text("Damage Package Id: %llu", properties.m_dodge.m_damagePackageId);
                                    ImGui::TreePop();
                                }
                                // Dormant
                                if(ImGui::TreeNode("Dormant")){
                                    //float m_hearingGainModifier; uint64_t m_signalModifierId;
                                    ImGui::Text("Hearing Gain Modifier: %f", properties.m_dormant.m_hearingGainModifier);
                                    ImGui::Text("Signal Modifier Id: %llu", properties.m_dormant.m_signalModifierId);
                                    ImGui::TreePop();
                                }
                                // Energized
                                if(ImGui::TreeNode("Energized")){
                                    //uint64_t m_energizedGameEffectId;
                                    ImGui::Text("Energized Game Effect Id: %llu", properties.m_energized.m_energizedGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Entity Faction Modifier
                                if(ImGui::TreeNode("Entity Faction Modifier")){
                                    //uint64_t m_hositleToFactionId;
                                    ImGui::Text("Hositle To Faction Id: %llu", properties.m_entityFactionModifier.m_hositleToFactionId);
                                    ImGui::TreePop();
                                }
                                // Fatality
                                if(ImGui::TreeNode("Fatality")){
                                    //float m_vulnerabilityHealthThreshold;
                                    ImGui::Text("Vulnerability Health Threshold: %f", properties.m_fatality.m_vulnerabilityHealthThreshold);
                                    ImGui::TreePop();
                                }
                                // Fear
                                if(ImGui::TreeNode("Fear")){
                                    //uint64_t m_fearedGameEffectId; uint64_t m_fearedSignalModifierId;
                                    ImGui::Text("Feared Game Effect Id: %llu", properties.m_fear.m_fearedGameEffectId);
                                    ImGui::Text("Feared Signal Modifier Id: %llu", properties.m_fear.m_fearedSignalModifierId);
                                    ImGui::TreePop();
                                }
                                // Glooed
                                if(ImGui::TreeNode("Glooed")){
                                    //uint64_t m_glooGameEffectId; uint64_t m_onGlooedAbilityContextId;
                                    ImGui::Text("Gloo Game Effect Id: %llu", properties.m_glooed.m_glooGameEffectId);
                                    ImGui::Text("On Glooed Ability Context Id: %llu", properties.m_glooed.m_onGlooedAbilityContextId);
                                    ImGui::TreePop();
                                }
                                // Hack
                                if(ImGui::TreeNode("Hack")){
                                    //bool m_bStartHacked; uint64_t m_hackedGameEffectId;
                                    ImGui::Text("Start Hacked: %u", properties.m_hack.m_bStartHacked);
                                    ImGui::Text("Hacked Game Effect Id: %llu", properties.m_hack.m_hackedGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Hit Reaction
                                if(ImGui::TreeNode("Hit Reaction")){
                                    //uint64_t m_hitReactionMaterialAnimationGameEffectId;
                                    ImGui::Text("Hit Reaction Material Animation Game Effect Id: %llu", properties.m_hitReaction.m_hitReactionMaterialAnimationGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Human Armed
                                if(ImGui::TreeNode("Human Armed")){
                                    //bool m_bIsArmed; int m_magSize; const char *m_pGunAttachmentName; IEntityArchetype *m_pLootWeaponEntityArchetype;
                                    ImGui::Text("Is Armed: %u", properties.m_humanArmed.m_bIsArmed);
                                    if(ImGui::IsItemClicked()){
                                        properties.m_humanArmed.m_bIsArmed = !properties.m_humanArmed.m_bIsArmed;
                                    }
                                    ImGui::Text("Mag Size: %d", properties.m_humanArmed.m_magSize);
                                    ImGui::Text("Gun Attachment Name: %s", properties.m_humanArmed.m_pGunAttachmentName);
                                    if(properties.m_humanArmed.m_pLootWeaponEntityArchetype){
                                        ImGui::Text("Loot Weapon Entity Archetype: %s", properties.m_humanArmed.m_pLootWeaponEntityArchetype->GetName());
                                    } else {
                                        ImGui::Text("Loot Weapon Entity Archetype: %p", properties.m_humanArmed.m_pLootWeaponEntityArchetype);
                                    }
                                    ImGui::TreePop();
                                }
                                // Hypnotize
                                if(ImGui::TreeNode("Hypnotize")){
                                    //float m_timeBetweenHypnotize;
                                    ImGui::Text("Time Between Hypnotize: %f", properties.m_hypnotize.m_timeBetweenHypnotize);
                                    ImGui::TreePop();
                                }
                                // Laser
                                if(ImGui::TreeNode("Laser")){
                                    //int m_laserHitTypeId; float m_beamEndJumpDistanceSq; float m_materialEffectCooldown; float m_maxLaserLength; float m_maxThickness; float m_minThickness; uint64_t m_laserPackageId; int m_customSurfaceTypeId; const char *m_pBeamEndEffectName; const char *m_pLaserGeometryName; const char *m_pLaserMaterialEffectName; const char *m_pReflectionGeometryName; IEntityArchetype *m_pLootAmmoLaserArchetype; IEntityArchetype *m_pLootAmmoStunArchetype;
                                    ImGui::Text("Laser Hit Type Id: %d", properties.m_laser.m_laserHitTypeId);
                                    ImGui::Text("Beam End Jump Distance Sq: %f", properties.m_laser.m_beamEndJumpDistanceSq);
                                    ImGui::Text("Material Effect Cooldown: %f", properties.m_laser.m_materialEffectCooldown);
                                    ImGui::Text("Max Laser Length: %f", properties.m_laser.m_maxLaserLength);
                                    ImGui::Text("Max Thickness: %f", properties.m_laser.m_maxThickness);
                                    ImGui::Text("Min Thickness: %f", properties.m_laser.m_minThickness);
                                    ImGui::Text("Laser Package Id: %llu", properties.m_laser.m_laserPackageId);
                                    ImGui::Text("Custom Surface Type Id: %d", properties.m_laser.m_customSurfaceTypeId);
                                    ImGui::Text("Beam End Effect Name: %s", properties.m_laser.m_pBeamEndEffectName);
                                    ImGui::Text("Laser Geometry Name: %s", properties.m_laser.m_pLaserGeometryName);
                                    ImGui::Text("Laser Material Effect Name: %s", properties.m_laser.m_pLaserMaterialEffectName);
                                    ImGui::Text("Reflection Geometry Name: %s", properties.m_laser.m_pReflectionGeometryName);
                                    if(properties.m_laser.m_pLootAmmoLaserArchetype){
                                        ImGui::Text("Loot Ammo Laser Archetype: %s", properties.m_laser.m_pLootAmmoLaserArchetype->GetName());
                                    } else {
                                        ImGui::Text("Loot Ammo Laser Archetype: NULL");
                                    }
                                    if(properties.m_laser.m_pLootAmmoStunArchetype){
                                        ImGui::Text("Loot Ammo Stun Archetype: %s", properties.m_laser.m_pLootAmmoStunArchetype->GetName());
                                    } else {
                                        ImGui::Text("Loot Ammo Stun Archetype: NULL");
                                    }
                                    ImGui::TreePop();
                                }
                                // Mannequin
                                if(ImGui::TreeNode("Mannequin")){
                                    //const char *m_pLifetimeTag;
                                    ImGui::Text("Lifetime Tag: %s", properties.m_mannequin.m_pLifetimeTag);
                                    ImGui::TreePop();
                                }
                                // Mimic Jump attack
                                if(ImGui::TreeNode("Mimic Jump attack")){
                                    //uint64_t m_mimicJumpAttackPackageId; _smart_ptr<IParticleEffect> m_pMimicAttackEffect;
                                    ImGui::Text("Mimic Jump Attack Package Id: %llu", properties.m_mimicJumpAttack.m_mimicJumpAttackPackageId);
                                    ImGui::Text("Mimic Attack Effect: %p", properties.m_mimicJumpAttack.m_pMimicAttackEffect.get());
                                    ImGui::TreePop();
                                }
                                // Mimic Reorient
                                if(ImGui::TreeNode("Mimic Reorient")){
                                    //bool m_bSupportsReorientation; float m_mimicGlitchRandTimeMax; float m_mimicGlitchRandTimeMin;
                                    ImGui::Text("Supports Reorientation: %u", properties.m_mimicReorient.m_bSupportsReorientation);
                                    ImGui::Text("Mimic Glitch Rand Time Max: %f", properties.m_mimicReorient.m_mimicGlitchRandTimeMax);
                                    ImGui::Text("Mimic Glitch Rand Time Min: %f", properties.m_mimicReorient.m_mimicGlitchRandTimeMin);
                                    ImGui::TreePop();
                                }
                                // Mimicry
                                if(ImGui::TreeNode("Mimicry")){
                                    //int m_morphInSlot; int m_morphOutSlot; float m_defaultMass; float m_impulseMultiplier; float m_impulsePointHorizontalRatio; float m_impulsePointVerticalRatio; float m_startCharacterMorphOutTime; float m_startGeometryMorphInTime; float m_stopCharacterMorphInTime; float m_stopGeometryMorphOutTime; string m_MorphOutBamfBoneName; uint64_t m_signalModifierId; _smart_ptr<IParticleEffect> m_pMorphInParticlefEffect; _smart_ptr<IParticleEffect> m_pMorphOutBamParticlefEffect; _smart_ptr<IParticleEffect> m_pMorphOutParticlefEffect; ArkAudioTrigger m_startTickingAudioTrigger; ArkAudioTrigger m_stopTickingAudioTrigger; ArkAudioTrigger m_unmorphAudioTrigger;
                                    ImGui::Text("Morph In Slot: %d", properties.m_mimicry.m_morphInSlot);
                                    ImGui::Text("Morph Out Slot: %d", properties.m_mimicry.m_morphOutSlot);
                                    ImGui::Text("Default Mass: %f", properties.m_mimicry.m_defaultMass);
                                    ImGui::Text("Impulse Multiplier: %f", properties.m_mimicry.m_impulseMultiplier);
                                    ImGui::Text("Impulse Point Horizontal Ratio: %f", properties.m_mimicry.m_impulsePointHorizontalRatio);
                                    ImGui::Text("Impulse Point Vertical Ratio: %f", properties.m_mimicry.m_impulsePointVerticalRatio);
                                    ImGui::Text("Start Character Morph Out Time: %f", properties.m_mimicry.m_startCharacterMorphOutTime);
                                    ImGui::Text("Start Geometry Morph In Time: %f", properties.m_mimicry.m_startGeometryMorphInTime);
                                    ImGui::Text("Stop Character Morph In Time: %f", properties.m_mimicry.m_stopCharacterMorphInTime);
                                    ImGui::Text("Stop Geometry Morph Out Time: %f", properties.m_mimicry.m_stopGeometryMorphOutTime);
                                    ImGui::Text("Morph Out Bamf Bone Name: %s", properties.m_mimicry.m_MorphOutBamfBoneName.c_str());
                                    ImGui::Text("Signal Modifier Id: %llu", properties.m_mimicry.m_signalModifierId);
                                    ImGui::Text("Morph In Particlef Effect: %p", properties.m_mimicry.m_pMorphInParticlefEffect.get());
                                    ImGui::Text("Morph Out Bam Particlef Effect: %p", properties.m_mimicry.m_pMorphOutBamParticlefEffect.get());
                                    ImGui::Text("Morph Out Particlef Effect: %p", properties.m_mimicry.m_pMorphOutParticlefEffect.get());
                                    ImGui::TreePop();
                                }
                                // Mind Control
                                if(ImGui::TreeNode("Mind Control")){
                                    //uint64_t m_mindControlGameEffectId;
                                    ImGui::Text("Mind Control Game Effect Id: %llu", properties.m_mindControl.m_mindControlGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Nullwave
                                if(ImGui::TreeNode("Nullwave")){
                                    //uint64_t m_nullwavedSignalModifierId;
                                    ImGui::Text("Nullwaved Signal Modifier Id: %llu", properties.m_nullwave.m_nullwavedSignalModifierId);
                                    ImGui::TreePop();
                                }
                                //OnDeath
                                if(ImGui::TreeNode("OnDeath")){
                                    //float m_aoeDeathRadius; float m_aoeDeathSignalScale; uint64_t m_aoeDeathSignal; _smart_ptr<IParticleEffect> m_pFearAoeParticleEffect;
                                    ImGui::Text("Aoe Death Radius: %f", properties.m_onDeath.m_aoeDeathRadius);
                                    ImGui::Text("Aoe Death Signal Scale: %f", properties.m_onDeath.m_aoeDeathSignalScale);
                                    ImGui::Text("Aoe Death Signal: %llu", properties.m_onDeath.m_aoeDeathSignal);
                                    ImGui::Text("Fear Aoe Particle Effect: %p", properties.m_onDeath.m_pFearAoeParticleEffect.get());
                                    ImGui::TreePop();
                                }
                                //On Fire
                                if(ImGui::TreeNode("On Fire")){
                                    //uint64_t m_onFireGameEffectId;
                                    ImGui::Text("On Fire Game Effect Id: %llu", properties.m_onFire.m_onFireGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Operator effects
                                if(ImGui::TreeNode("Operator Effects")){
                                    //float m_airJetToggleOffTime; float m_maxAirJetToggleOnTime; float m_minAirJetToggleOnTime; uint64_t m_operatorArmRetractedGameEffectId; _smart_ptr<IParticleEffect> m_pAirJetParticleEffect;
                                    ImGui::Text("Air Jet Toggle Off Time: %f", properties.m_operatorEffects.m_airJetToggleOffTime);
                                    ImGui::Text("Max Air Jet Toggle On Time: %f", properties.m_operatorEffects.m_maxAirJetToggleOnTime);
                                    ImGui::Text("Min Air Jet Toggle On Time: %f", properties.m_operatorEffects.m_minAirJetToggleOnTime);
                                    ImGui::Text("Operator Arm Retracted Game Effect Id: %llu", properties.m_operatorEffects.m_operatorArmRetractedGameEffectId);
                                    ImGui::Text("Air Jet Particle Effect: %p", properties.m_operatorEffects.m_pAirJetParticleEffect.get());
                                    ImGui::TreePop();
                                }
                                // Player Controlled
                                if(ImGui::TreeNode("Player Controlled")){
                                    //uint64_t m_playerControlledGameEffectId;
                                    ImGui::Text("Player Controlled Game Effect Id: %llu", properties.m_playerControlled.m_playerControlledGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Poltergeist Effects
                                if(ImGui::TreeNode("Poltergeist Effects")){
                                    //uint64_t m_invisibilityGameEffectId;
                                    ImGui::Text("Invisibility Game Effect Id: %llu", properties.m_poltergeistEffects.m_invisibilityGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Raise From Corpse
                                if(ImGui::TreeNode("Raise From Corpse")){
                                    //uint64_t m_raiseFromCorpseGameEffectId;
                                    ImGui::Text("Raise From Corpse Game Effect Id: %llu", properties.m_raiseFromCorpse.m_raiseFromCorpseGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Raise Phantom
                                if(ImGui::TreeNode("Raise Phantom")){
                                    //bool m_bCanBeRaisedPhantom; int m_maxAllowedRaisedPhantoms;
                                    ImGui::Text("Can Be Raised Phantom: %s", properties.m_raisePhantom.m_bCanBeRaisedPhantom ? "true" : "false");
                                    ImGui::Text("Max Allowed Raised Phantoms: %d", properties.m_raisePhantom.m_maxAllowedRaisedPhantoms);
                                    ImGui::TreePop();
                                }
                                // Shift
                                if(ImGui::TreeNode("Shift")){
                                    //uint64_t m_shiftingSignalModifierId;
                                    ImGui::Text("Shifting Signal Modifier Id: %llu", properties.m_shift.m_shiftingSignalModifierId);
                                    ImGui::TreePop();
                                }
                                // Sound
                                if(ImGui::TreeNode("Sound")){
                                    ImGui::Text("A bunch of audio triggers here, nothing exciting");
                                    ImGui::TreePop();
                                }
                                // Stunned
                                if(ImGui::TreeNode("Stunned")){
                                    //uint64_t m_stunnedGameEffectId;
                                    ImGui::Text("Stunned Game Effect Id: %llu", properties.m_stunned.m_stunnedGameEffectId);
                                    ImGui::TreePop();
                                }
                                // Surprise
                                if(ImGui::TreeNode("Surprise")){
                                    //uint64_t m_noiseLoudnessId; uint64_t m_noiseTypeId;
                                    ImGui::Text("Noise Loudness Id: %llu", properties.m_surprise.m_noiseLoudnessId);
                                    ImGui::Text("Noise Type Id: %llu", properties.m_surprise.m_noiseTypeId);
                                    ImGui::TreePop();
                                }
                                // Turret Weapon
                                if(ImGui::TreeNode("Turret Weapon")){
                                    //IEntityArchetype *m_pLootAmmoLaserArchetype; IEntityArchetype *m_pLootAmmoStunArchetype;
                                    if(properties.m_turretWeapon.m_pLootAmmoLaserArchetype != nullptr){
                                        ImGui::Text("Loot Ammo Laser Archetype: %s", properties.m_turretWeapon.m_pLootAmmoLaserArchetype->GetName());
                                    }
                                    else{
                                        ImGui::Text("Loot Ammo Laser Archetype: NULL");
                                    }
                                    if(properties.m_turretWeapon.m_pLootAmmoStunArchetype != nullptr){
                                        ImGui::Text("Loot Ammo Stun Archetype: %s", properties.m_turretWeapon.m_pLootAmmoStunArchetype->GetName());
                                    }
                                    else{
                                        ImGui::Text("Loot Ammo Stun Archetype: NULL");
                                    }
                                    ImGui::TreePop();
                                }
                                // Unreachable Targeting
                                if(ImGui::TreeNode("Unreachable Targeting")){
                                    //float m_defaultCombatReachabilityCheckUp; float m_defaultCombatReachabilityCheckDown; float m_defaultCombatReachabilityCheckHorizontal; float m_startingTraceRadius; float m_startingMinSearchRadius; float m_chanceToSearchInReverseOrder; float m_horizontalOffsetStanding; float m_standardCombatHeight;
                                    ImGui::Text("Default Combat Reachability Check Up: %f", properties.m_unreachableTargeting.m_defaultCombatReachabilityCheckUp);
                                    ImGui::Text("Default Combat Reachability Check Down: %f", properties.m_unreachableTargeting.m_defaultCombatReachabilityCheckDown);
                                    ImGui::Text("Default Combat Reachability Check Horizontal: %f", properties.m_unreachableTargeting.m_defaultCombatReachabilityCheckHorizontal);
                                    ImGui::Text("Starting Trace Radius: %f", properties.m_unreachableTargeting.m_startingTraceRadius);
                                    ImGui::Text("Starting Min Search Radius: %f", properties.m_unreachableTargeting.m_startingMinSearchRadius);
                                    ImGui::Text("Chance To Search In Reverse Order: %f", properties.m_unreachableTargeting.m_chanceToSearchInReverseOrder);
                                    ImGui::Text("Horizontal Offset Standing: %f", properties.m_unreachableTargeting.m_horizontalOffsetStanding);
                                    ImGui::Text("Standard Combat Height: %f", properties.m_unreachableTargeting.m_standardCombatHeight);
                                    ImGui::TreePop();
                                }
                                //bool m_bCanFall; bool m_bCanRagdoll; bool m_bSupportsLookAt; int m_playerPowerTierTriggerThreshold; int m_npcManagerCombatPoints; float m_combatIntensityContribution; float m_combatIntensityRange; float m_fallDamagePerMeter; float m_fallDistanceForDamage; float m_fallDistanceForDialog; float m_fallDistanceForFallAnim; float m_fallDistanceForGlooBreak; float m_fallDistanceForLandAnim; float m_forceResistScrunchDistance; const char *m_pAiTreeFilePath; const char *m_pFaction; uint64_t m_fallDamagePackage; uint64_t m_ragdollSignalModifierId;
                                std::string label = std::string("Can Fall: ") + (properties.m_bCanFall ? "true" : "false");
//                                ImGui::Text("Can Fall: %s", properties.m_bCanFall ? "true" : "false");
                                if(ImGui::Selectable(label.c_str())){
                                    properties.m_bCanFall = !properties.m_bCanFall;
                                }
                                label = std::string("Can Ragdoll: ") + (properties.m_bCanRagdoll ? "true" : "false");
                                if(ImGui::Selectable(label.c_str())){
                                    properties.m_bCanRagdoll = !properties.m_bCanRagdoll;
                                }
                                label = std::string("Supports Look At: ") + (properties.m_bSupportsLookAt ? "true" : "false");
                                if(ImGui::Selectable(label.c_str())){
                                    properties.m_bSupportsLookAt = !properties.m_bSupportsLookAt;
                                }
                                ImGui::Text("Player Power Tier Trigger Threshold: %d", properties.m_playerPowerTierTriggerThreshold);
                                ImGui::Text("Npc Manager Combat Points: %d", properties.m_npcManagerCombatPoints);
                                ImGui::Text("Combat Intensity Contribution: %f", properties.m_combatIntensityContribution);
                                ImGui::Text("Combat Intensity Range: %f", properties.m_combatIntensityRange);
                                ImGui::Text("Fall Damage Per Meter: %f", properties.m_fallDamagePerMeter);
                                ImGui::Text("Fall Distance For Damage: %f", properties.m_fallDistanceForDamage);
                                ImGui::Text("Fall Distance For Dialog: %f", properties.m_fallDistanceForDialog);
                                ImGui::Text("Fall Distance For Fall Anim: %f", properties.m_fallDistanceForFallAnim);
                                ImGui::Text("Fall Distance For Gloo Break: %f", properties.m_fallDistanceForGlooBreak);
                                ImGui::Text("Fall Distance For Land Anim: %f", properties.m_fallDistanceForLandAnim);
                                ImGui::Text("Force Resist Scrunch Distance: %f", properties.m_forceResistScrunchDistance);
                                ImGui::Text("Ai Tree File Path: %s", properties.m_pAiTreeFilePath);
                                ImGui::Text("Faction: %s", properties.m_pFaction);
                                ImGui::Text("Fall Damage Package: %llu", properties.m_fallDamagePackage);
                                ImGui::Text("Ragdoll Signal Modifier Id: %llu", properties.m_ragdollSignalModifierId);
                                ImGui::EndTabItem();
                            }


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
        if (ImGui::BeginMenu("Trainer")) {
            if (ImGui::BeginMenu("Entity")) {
                if (ImGui::BeginMenu("Spawn Entity")) {
                    std::string lastSpawnedText;
//                    lastSpawnedText = (lastSpawnedEntity != 0)? std::string("Spawn Last Spawned: (") + gEnv->pEntitySystem->GetEntityArchetype(lastSpawnedEntity)->GetName() + ")" : " Spawn Last Spawned: None";

                    if(ImGui::MenuItem("Spawn Last Quick-Spawned", nullptr, false, lastSpawnedEntity != 0)){
                        quickSpawnEntity(lastSpawnedEntity);
                    }
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
                if (ImGui::MenuItem("List Classes")) {
                    CEntityClassRegistry* registry = ((CEntityClassRegistry*)gEnv->pEntitySystem->GetClassRegistry());
                    for (auto& entityClass : registry->m_mapClassName) {
                        CryLog("{}", entityClass.second->GetName());

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
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}


void EntityManager::spawnEntity() {
    try {
        if (archetypeToSpawn != 0) {
            static Vec3 pos;
            static Quat rot = Quat{0, 0, 0, 1};
            archetypeToSpawn;
            usePlayerPos;
            offsetFromPlayer;
            if (usePlayerPos) {
                if (ArkPlayer::GetInstancePtr() != nullptr) {
                    pos = ArkPlayer::GetInstancePtr()->GetEntity()->GetPos();
                    if (offsetFromPlayer) {
                        pos.x += ArkPlayer::GetInstancePtr()->m_cachedReticleDir.x * offsetDistance[1];
                        pos.y += ArkPlayer::GetInstancePtr()->m_cachedReticleDir.y * offsetDistance[1];
                        pos.z += offsetDistance[2];

                    } else {
                        throw ("Ark Player not found");
                    }
                } else {
                    pos = Vec3{spawnX, spawnY, spawnZ};
                }
                auto archetype = gEnv->pEntitySystem->GetEntityArchetype(archetypeToSpawn);
                std::string archetypeName = archetype->GetName();
                // if an npc use npc spawning
                auto entityClass = archetype->GetClass();
                if (entityClass != nullptr) {

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
                        auto entity = EntityUtils::SpawnNpc(inputName.c_str(), pos, rot, archetype->GetId(),
                                                                 spawnCount, selectedSpawnerFaction);
                        if (entity != nullptr) {
                            if (selectedSpawnerFaction != 0) {
                                OverlayLog("Spawned {} {} in faction {}", spawnCount, archetype->GetName(), gEnv->pGame->GetIArkFactionManager()->GetFactionName(selectedSpawnerFaction).c_str());
                            } else {
                                OverlayLog("Spawned {} {}", spawnCount, archetype->GetName());
                            }
                        }
                    } else {
                        EntityUtils::SpawnEntity(inputName.c_str(), pos, rot, archetype->GetId(), spawnCount);
                        OverlayLog("Spawned {} {}", spawnCount, archetype->GetName());
                    }
                }
                // done
                color = {1, 1, 1, 1};
                statusMessage = "spawned an entity: " + inputName;
                time(&statusTimer);
            } else {
                throw ("Error, no archetype selected");
            }
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
            lastSpawnedEntity = archetypeId;
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
                    EntityUtils::SpawnNpc("", pos, rot, archetypeId, spawnCount);
                } else {
                    EntityUtils::SpawnEntity("", pos, rot, archetypeId, spawnCount);
                }
            } else {
                throw("Error, no class found");
            }
            OverlayLog("spawned an entity: {}", inputName);
        }
        else {
            throw("Error, no archetype found");
        }
    }
    catch (std::string& c) {
        OverlayLog("{}", c.c_str());
    }
}



void EntityManager::Draw() {
    drawMenuBar();
    drawEntityList(&showEntityList);
    drawEntitySpawner(&showEntitySpawner);
}

void EntityManager::InitGame() {

}
