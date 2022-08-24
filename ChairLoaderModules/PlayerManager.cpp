#include "PlayerManager.h"

#include "Logging.h"
#include "Prey/CrySystem/ILocalizationManager.h"
#include "boost/algorithm/string.hpp"
#include "Prey/CryAction/GameObject.h"
#include "Prey/CryGame/Game.h"
#include "Prey/CrySystem/Profiling.h"
#include "../ChairLoader/GUIUtils.h"
#include <Prey/CrySystem/IConsole.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Prey/GameDll/ark/player/ArkPlayerStatusComponent.h>
#include <Prey/GameDll/ark/player/arkpsicomponent.h>
#include <Prey/GameDll/ark/player/ArkPlayerFatigueComponent.h>
#include <Prey/GameDll/ark/player/psipower/IArkPsiPower.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ArkItemSystem.h>
#include <Prey/GameDll/arkitem.h>
#include <Prey/ArkAbilityLibrary.h>
#include "Prey/CryEntitySystem/EntitySystem.h"

// PUBLIC:
void PlayerManager::draw() {

    drawMenuBar();
    if(showPlayerManager) {
        if (!ImGui::Begin("Player Manager", &showPlayerManager, ImGuiWindowFlags_NoNavInputs)) {
            ImGui::End();
            return;
        }

        if (ImGui::BeginTabBar("Player Bar")) {
            if(ArkPlayer::GetInstancePtr() != nullptr) {
                drawPositionTab();
                drawHealthTab();
                drawAbilitiesTab();
                drawInventoryTab();
            }
//            ImGui::EndDisabled();
            ImGui::EndTabBar();
        }

        ImGui::End();
    }
}

void PlayerManager::drawPositionTab() {
	if (ImGui::BeginTabItem("Position")) {
		ImGui::Checkbox("Enable Position Hotkeys", &enablePosHotKeys);
		ImGui::Text("Load Positions:");
		for (int i = 0; i < 5; i++) {
			if (ImGui::Button(("Load Pos " + std::to_string(i+1)).c_str())) {
				// check if the saved position is null
				loadPosition(i);
			}
			ImGui::SameLine();
		}
		ImGui::SameLine();
		ImGuiUtils::HelpMarker("These buttons will set the player to a stored position");
		// add a dropdown list and button to save to each of the four positions
		ImGui::Separator();

		// static int index = 0;
		// create buttons to save each position
		ImGui::Text("Save Positions:");
		for (int i = 0; i < 5; i++) {
			if (ImGui::Button(("Save Pos " + std::to_string(i+1)).c_str())) {
				// index = i;
				savePosition(i, gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetPos());
			}
			ImGui::SameLine();
		}
        ImGui::Separator();
        static float position[3];
        auto player = gCLEnv->entUtils->ArkPlayerPtr();
        if(player != nullptr) {
            ImGui::Text("Player Position:");
            position[0] = player->GetEntity()->GetPos().x;
            position[1] = player->GetEntity()->GetPos().y;
            position[2] = player->GetEntity()->GetPos().z;
            if (ImGui::InputFloat3("Pos", position, "%.1f", ImGuiInputTextFlags_EnterReturnsTrue)) {
                Vec3 newPos = Vec3(position[0], position[1], position[2]);
                player->GetEntity()->SetPos(newPos, 0, true, true);
            }
        }
		ImGui::EndTabItem();
	}
}


void PlayerManager::drawHealthTab() {
	if (ImGui::BeginTabItem("Health/Statuses")) {
		if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
			float currentHealth = gCLEnv->entUtils->ArkPlayerPtr()->GetHealth();
			float maxHealth = gCLEnv->entUtils->ArkPlayerPtr()->GetMaxHealth();
			float currentArmor = 100.0f - gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->GetTraumaForStatus( EArkPlayerStatus::SuitIntegrity)->m_currentAmount;
			float maxArmor = 100.0f;
			float currentRad = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->GetTraumaForStatus(EArkPlayerStatus::Radiation)->m_currentAmount;
			float maxRad = 100.0f;
			float currentPsi = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent->m_points;
			float maxPsi = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent->m_maxPoints;
			float currentFatigue = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pFatigueComponent->m_fatigue.m_amount;
			float maxFatigue = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pFatigueComponent->m_fatigue.m_maxAmount;
			static float setHealth = 0;
			static float setPsi = 0;
			static float setMaxPsi = 0;
			
			ImGui::Text("Player Entity Name: %s", gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetName());
			ImGui::Text("Player Entity ID: %u", gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetId());
			ImGui::Text("Health: %.2f / %.2f", currentHealth / 10, maxHealth / 10);
			ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(209, 37, 43, 255));
			ImGui::ProgressBar(currentHealth / maxHealth);
			ImGui::PopStyleColor();
			if (ImGui::InputFloat("Set Health", &setHealth, 0, 0, "%.2f")) {
				gCLEnv->entUtils->ArkPlayerPtr()->SetHealth(setHealth * 10);
				setHealth = gCLEnv->entUtils->ArkPlayerPtr()->GetHealth() / 10;
			}
			//TODO: update armor and radiation (apply statuses/
			//Armor
			ImGui::Checkbox("God Mode", &godMode);
			ImGui::Text("Armor: %.2f / %.2f", currentArmor, maxArmor);
			ImGui::ProgressBar(currentArmor / maxArmor);
			if (ImGui::InputFloat("Set Armor", &currentArmor)) {
				gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->GetTraumaForStatus(EArkPlayerStatus::SuitIntegrity)->m_currentAmount = 100.0f - currentArmor;
				// gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->GetTraumaForStatus(gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get(), EArkPlayerStatus::SuitIntegrity)->Update(0.1f);
			}
			//Psi
			ImGui::Text("Psi: %.2f / %.2f", currentPsi, maxPsi);
			ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(130, 8, 216, 255));
			ImGui::ProgressBar(currentPsi / maxPsi);
			ImGui::PopStyleColor();
			if (ImGui::InputFloat("Set Psi", &setPsi, 0, 0, "%.2f")) {
				gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_points = setPsi;
				setPsi = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_points;
				gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent->UpdateHUDMarkerElements();
			}
			//Set Max Psi
			if (ImGui::InputFloat("Set Max Psi", &setMaxPsi, 0, 0, "%.2f")) {
				gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_maxPoints = setMaxPsi;
				setMaxPsi = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_maxPoints;
			}
			//show fatigue
			ImGui::Text("Stamina: %.2f / %.2f", maxFatigue - currentFatigue, maxFatigue);
			ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(150, 150, 150, 255));
			ImGui::ProgressBar((maxFatigue - currentFatigue) / maxFatigue);
			ImGui::PopStyleColor();
			ImGui::Checkbox("Infinite Stamina", (bool*)&gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pFatigueComponent.get()->m_bInfiniteStamina);
			if (currentRad > 0.1f) {
				ImGui::Text("Radiation: %.2f / %.2f", currentRad, maxRad);
				ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(16, 147, 18, 255));
				ImGui::ProgressBar(currentRad / maxRad);
				ImGui::PopStyleColor();
			} else {
				ImGui::Text("Radiation: 0.00 / %.2f", maxRad);
				ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(16, 147, 18, 255));
				ImGui::ProgressBar(0 / maxRad);
				ImGui::PopStyleColor();
			}
			if (ImGui::InputFloat("Set Radiation", &currentRad)) {
				gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->GetTraumaForStatus(EArkPlayerStatus::Radiation)->m_currentAmount = currentRad;
				// gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->GetTraumaForStatus(gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get(), EArkPlayerStatus::Radiation)->Update(0.1f);
			}
			static bool showArmor = true;
			if(ImGui::Checkbox("Show Armor", &showArmor)) {
				gCLEnv->entUtils->ArkPlayerPtr()->SetShowArmor(showArmor, true);
			}
			ImGui::Separator();
			ImGui::Text("Statuses: ");
			ImGui::Columns(2);
			for (auto& status : gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get()->m_statuses) {
				if (ImGui::Selectable(status.get()->m_desc.m_Name.c_str())) {
					// status->m_desc.m_Duration = 1000.0f;
					if (status != nullptr) {
						// int level = status->m_currentLevel;
						status->Activate(0);
					}
					// gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->ForceStatus
					// status->UpdateHudIcon(status.get());
					// status->UpdateVisuals(true, true);
					// gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->SetStatus(gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get(), status.get()->m_status, true, false);
					// status.get()->UpdateVisuals(true, false);
				}
				ImGui::NextColumn();
				ImGui::Text("Level: %i", status->m_currentLevel);
				ImGui::Text("Current amount: %f", status->m_currentAmount);
				// printf("Offset: %llX", (uintptr_t)&status->m_desc.m_Phases - (uintptr_t)&status->m_desc); //Offset: 136
				// for(auto & phase : status->m_desc.m_Phases) {
				// 	ImGui::Text("%s", phase.m_HudIcon.c_str());
				// }
				ImGui::NextColumn();
			}
			ImGui::Columns(1);
			// if (ImGui::Button("Add Status")) {
			// 	gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get()->m_activeStatuses.emplace_back(
			// 		EArkPlayerStatus::Radiation);
			// }
			// TODO: figure out armor

		}
		ImGui::EndTabItem();
	}
}

void PlayerManager::drawAbilitiesTab() {
	if (ImGui::BeginTabItem("Abilities")) {
		refreshAbilityList = ImGui::Button("Refresh");
		if (ImGui::BeginChild("AbilityList", ImGui::GetContentRegionAvail(), false, ImGuiWindowFlags_HorizontalScrollbar)) {
			for (auto &ability : gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent->m_abilities) {
                std::string name;
                if(arkAbilityMap.find(ability.m_id) != arkAbilityMap.end()) {
                    name = arkAbilityMap.find(ability.m_id)->second.c_str();
                } else {
                    name = ToString(ability.m_id);
                }
				if (!ability.m_bAcquired) {

					if (ImGui::Selectable(name.c_str())) {
						if(!gCLEnv->entUtils->ArkPlayerPtr()->HasAbility(ability.m_id)){
                            gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent->GrantAbility(ability.m_id);
                        }
					}
				}
				else {
					ImGui::TextColored(ImVec4{1.0f, 1.0f, 1.0f, 0.7f}, "%s - acquired", name.c_str());
				}
			}
			ImGui::EndChild();
		}
		//TODO: figure out how to remove abilities too
		// std::vector<ArkAbilityData>* abilities = &gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get()->m_abilities;
		// if (!abilities->empty()) {
		//     ImGui::Text("Size: %d\n", abilities->size());
		//     int clip = 0;
		//     for (auto itr = abilities->begin(); itr != abilities->end() && clip <= 1000; ++itr, clip++) {
		//         if (itr->m_id != 0) {
		//             static ArkAbilityLibrary library;
		//             auto entry = library.arkAbilityMap.find(itr->m_id);
		//             if(entry != library.arkAbilityMap.end()) {
		//                 ImGui::Text(entry->second.c_str());
		//             } else {
		//                 ImGui::Text(std::to_string(itr->m_id).c_str());
		//             }
		//         }
		//     }
		// }
		ImGui::EndTabItem();
	}
    //TODO: clean me up
	if (ImGui::BeginTabItem("Random fun shit")) {
		auto abilityComponent = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get();
		// static auto acquiredAbilities = abilityComponent->GetAcquiredAbilities(abilityComponent);
		for (auto& power : gCLEnv->entUtils->ArkPlayerPtr()->GetPsiPowerComponent().m_powers) {
			wstring localizedName;
			gEnv->pSystem->GetLocalizationManager()->LocalizeString(power->GetDescription(), localizedName);
			ImGui::Text("%ls", localizedName.c_str());
		}
		auto &PsiPowerComponent = gCLEnv->entUtils->ArkPlayerPtr()->GetPsiPowerComponent();
		ArkPlayerMovementFSM* fsm = &gCLEnv->entUtils->ArkPlayerPtr()->m_movementFSM;
		if (ImGui::Button("Smoke Form"))
			PsiPowerComponent.UnlockPower(EArkPsiPowers::smokeForm, 1);
		if (ImGui::Button("Fly Mode Test"))
			fsm->m_flyMode = ArkPlayerMovementFSM::EArkFlyMode::on;
		ImGui::Text("Fly Mode: %u", fsm->m_flyMode);
		ImGui::Text("Current State: %u", fsm->m_currentStateId);
		ImGui::Text("Stance: %u", gCLEnv->entUtils->ArkPlayerPtr()->GetStance());
        static Vec3 ptc = {0, 0, 0};
        static Vec3 gravity = {0, 0, 0};
        ptc = gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetWorldPos();
        pe_params_buoyancy buoyancy;
//        pe_action action;
        auto impulse = new pe_action_impulse();
        auto randDir = cry_random_unit_vector<Vec3>();
        impulse->impulse = randDir *= 10000;
        ImGui::Text("Player Physics Type %u", gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetPhysics()->GetType());
        if(ImGui::Button("Force Player")) {
            gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetPhysics()->Action(impulse);

        }
        if(ImGui::Button("Check Areas")){
//            gCLEnv->entUtils->ArkPlayerPtr()->SetStance(EStance::STANCE_ZEROG);

            auto result = ArkPlayer::GetInstancePtr()->GetEntity()->GetPhysics()->GetWorld()->CheckAreas(ptc, gravity, &buoyancy);
//            gCLEnv->entUtils->ArkPlayerPtr()->m_movementFSM.m_currentStateId = ArkPlayerMovementFSM::EStateId::fly;
            CryLog("Result: %d", result);
        }
        static bool katamari;
        ImGui::Checkbox("Katamari", &katamari);
        if(katamari){
            for(auto centity :((CEntitySystem*)gEnv->pEntitySystem)->m_EntityArray){
                IEntity* entity = (IEntity*)centity;
                if(entity!= nullptr) {
                    auto physics = entity->GetPhysics();
                    if (physics != nullptr) {
                        if (physics->GetType() == pe_type::PE_RIGID) {
                            auto distance = (ArkPlayer::GetInstancePtr()->GetEntity()->GetWorldPos() - entity->GetWorldPos()).GetLength();
                            auto forceDir = ArkPlayer::GetInstancePtr()->GetEntity()->GetWorldPos() - entity->GetWorldPos();
                            forceDir.Normalize();
                            auto force = new pe_action_impulse();
//                            pe_params_collision_class
                            force->impulse = forceDir *= 1.0f * distance;
                            physics->Action(force);
                        }
                    }
                }
            }
        }
        ImGui::Text("ptc: %f %f %f", ptc.x, ptc.y, ptc.z);
        ImGui::Text("gravity: %f %f %f", gravity.x, gravity.y, gravity.z);
		ImGui::Text("Spectator Mode: %u", gCLEnv->entUtils->ArkPlayerPtr()->GetSpectatorMode());
		ImGui::Text("Input Disabled Mode: %u", gCLEnv->entUtils->ArkPlayerPtr()->m_input.m_disabledMode);
		ArkPlayerCamera* camera = &gCLEnv->entUtils->ArkPlayerPtr()->m_camera;
		ImGui::Text("Camera Mode: %llu", (uintptr_t)camera->m_customViewFunction.target<void __cdecl(SViewParams&)>());
		ImGui::Separator();
#if 0
		auto filter = (CActionFilter*)(((CGame*)gEnv->pGame)->m_pGameActions->m_pFilterPsiPowerSmokeForm);
		auto pAction = reinterpret_cast<CCryAction*>(gCL->GetFramework());
		ImGui::Text("%u", filter->m_enabled);
		if (ImGui::Button("Text")) {
			auto brrr = filter->m_name.c_str();
			printf("%s", brrr);
			ImGui::Text("%s", brrr);
		}
		if (ImGui::Button("Action Filter true")) {

			filter->m_enabled = true;
			//fix something later I guess
		}
		if (ImGui::Button("Action Filter false")) {
			filter->m_enabled = false;
			//fix something later I guess
		}
		if (ImGui::Button("Exit Smoke Movement State")) {
			gCLEnv->entUtils->ArkPlayerPtr()->m_movementFSM.m_smokeState.Exit();
			//fix something later I guess
		}
		ImGui::Separator();
		ImGui::Text("Maps:");
		ImGui::BeginTable("Maps", 2);
		for (auto& map : pAction->m_pActionMapManager->m_actionMaps) {
			ImGui::TableNextColumn();
			ImGui::Text("%s", map.first.c_str());
			ImGui::TableNextColumn();
			ImGui::Text("%u", map.second->m_enabled);
			ImGui::TableNextRow();
		}
		ImGui::EndTable();
		ImGui::Separator();
		ImGui::Text("Filters:");
		ImGui::BeginTable("Filters", 2);
		for (auto& map : pAction->m_pActionMapManager->m_actionFilters) {
			ImGui::TableNextColumn();
			ImGui::Text("%s", map.first.c_str());
			ImGui::TableNextColumn();
			ImGui::Text("%u", map.second->m_enabled);
			ImGui::TableNextRow();
		}
		ImGui::EndTable();
		ImGui::Separator();
		ImGui::Text("Ark Filters: %u", pAction->m_pActionMapManager->m_actionFilterStack.m_FilterStack.size());
		ImGui::BeginTable("Ark Filters:", 2);
		for (auto& map : pAction->m_pActionMapManager->m_actionFilterStack.m_FilterStack) {
			ImGui::TableNextColumn();
			ImGui::Text("Size");
			ImGui::TableNextColumn();
			ImGui::Text("%u", map.size());
			ImGui::TableNextRow();
			for (auto& entry : map) {
				ImGui::TableNextColumn();
				ImGui::Text("%s", ((CActionFilter*)entry)->m_name.c_str());
				ImGui::TableNextColumn();
				ImGui::Text("%u", ((CActionFilter*)entry)->m_enabled);
				ImGui::TableNextRow();
			}
			ImGui::TableNextRow();
		}
		ImGui::EndTable();
#endif
		// for (auto &ability : acquiredAbilities) {
		// 	ImGui::Text("1");
		// 	// std::string acquired = std::to_string(ability->m_id);
		// 	// if(ImGui::Selectable(acquired.c_str())) {
		// 	// 	// ability->m_bAcquired = !ability->m_bAcquired;
		// 	// }
		// 	// ImGui::SameLine();
		// 	// ImGui::Text("  %u", ability->m_bAcquired);
		// }
		ImGui::EndTabItem();
	}
}

void PlayerManager::drawInventoryTab() {
	if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
		inventoryItems.clear();
		for (auto& cell : gCLEnv->entUtils->ArkPlayerPtr()->m_pInventory->m_storedItems) {
			std::pair<int, ArkInventory::StorageCell> newItem = {cell.m_entityId, cell};
			inventoryItems.insert(newItem);
		}
	}
	if (ImGui::BeginTabItem("Inventory")) {
		float size = 75.0f;
		int inventoryWidth = 0, inventoryHeight = 0;
		if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
			inventoryHeight = gCLEnv->entUtils->ArkPlayerPtr()->m_pInventory->GetHeight();
			inventoryWidth = gCLEnv->entUtils->ArkPlayerPtr()->m_pInventory->GetWidth();
		}
		else {
			inventoryWidth = 12;
			inventoryHeight = 8;
		}
		if (!ImGui::IsWindowDocked())
			ImGui::SetWindowSize(ImVec2(inventoryWidth * size + 40, inventoryHeight * size + 30 + 300));
		static unsigned int selected = 0;
		ArkGame* game = ArkGame::GetArkGame();
		ArkItemSystem* itemSystem = game->m_pArkItemSystem.get();
		if (ImGui::BeginChild("Inventory Grid", ImVec2(inventoryWidth * size + 20, inventoryHeight * size + 30),
		                      false)) {
			ImGui::Text("Inventory: ");
			// ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 20, ImGui::GetCursorPos().y + 20));
			ImVec2 windowPos = ImGui::GetCursorPos();
			ImVec2 screenCursorPos = ImGui::GetCursorScreenPos();

			// loop 12 times
			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			for (int i = 0; i <= inventoryWidth; i++) {
				draw_list->AddLine(ImVec2(screenCursorPos.x + i * size, screenCursorPos.y),
				                   ImVec2(screenCursorPos.x + i * size, screenCursorPos.y + inventoryHeight * size),
				                   ImColor(255, 255, 255, 80));
			}
			// draw the horizontal lines
			for (int i = 0; i <= inventoryHeight; i++) {
				draw_list->AddLine(ImVec2(screenCursorPos.x, screenCursorPos.y + i * size),
				                   ImVec2(screenCursorPos.x + inventoryWidth * size, screenCursorPos.y + i * size),
				                   ImColor(255, 255, 255, 80));
			}
			for (auto& item : inventoryItems) {
				std::wstring name;
				wstring localizedName;
				std::string stringname = "";
				IArkItem* itemObj = itemSystem->GetItem(item.first);
				if (itemObj != nullptr) {
					gEnv->pSystem->GetLocalizationManager()->LocalizeString(itemObj->GetName(), localizedName);
				}
				name = localizedName.c_str();
				std::string name_string = std::string(name.begin(), name.end());
				ImGui::SetCursorPos(ImVec2(windowPos.x + (item.second.m_x - 1) * size,
				                           windowPos.y + (item.second.m_y - 1) * size));
				ImGuiUtils::textRectangle(name_string, item.second.m_width * size, item.second.m_height * size,
				                          ImColor(255, 255, 255, 255), ImColor(20, 20, 20, 255));

				ImGui::SetCursorPos(ImVec2(windowPos.x + (item.second.m_x - 1) * size,
				                           windowPos.y + (item.second.m_y - 1) * size));
				ImGui::PushID(std::to_string(item.first).c_str());
				ImGui::PushStyleColor(ImGuiCol_Button, ImColor(255, 255, 255, 0).Value);
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor(255, 255, 255, 60).Value);
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor(255, 255, 255, 120).Value);
				if (ImGui::Button("", ImVec2(item.second.m_width * size, item.second.m_height * size))) {
					// gCLEnv->gui->logItem(name_string + " Pressed!", modName);
					selected = item.first;
				}
				ImGui::PopID();
				ImGui::PopStyleColor(3);

			}
			// ImGuiUtils::textRectangle("Fuck", 128, 128, ImColor(255, 180, 255, 255));
		}
		ImGui::EndChild();
		// ImGui::SameLine();
		if (ImGui::BeginChild("Item Editor", ImVec2(0, 300))) {
			if (selected != 0) {
				IArkItem* selectedItem = itemSystem->GetItem(selected);
				CArkItem* selectedItemObj = (CArkItem*)selectedItem;
				if (selectedItem != nullptr) {
					ImGui::Separator();
					std::wstring name;
					wstring localizedName;
					gEnv->pSystem->GetLocalizationManager()->LocalizeString(selectedItem->GetName(), localizedName);
					name = localizedName.c_str();

					ImGui::Text("%ls", name.c_str());
					ImGui::Text("ID:%u", selected);
					ImGui::Columns(2);
					ImGui::Text("Archetype: %s", gEnv->pEntitySystem->GetEntity(selected)->GetArchetype()->GetName());
					ImGui::NextColumn();
					ImGui::Text("Count: %i", selectedItem->GetCount());
					ImGui::NextColumn();
					ImGui::Text("Unlocalized: %s", selectedItem->GetName());
					ImGui::NextColumn();
					ImGui::Text("Equippable: %i", selectedItem->IsEquippable());
					ImGui::NextColumn();
					ImGui::Text("Icon: %s", selectedItem->GetIcon());
					ImGui::NextColumn();
					ImGui::Text("Is Grenade: %u", selectedItem->IsGrenade());
					ImGui::NextColumn();
					ImGui::Text("Is Trash: %u", selectedItem->IsTrash());
					ImGui::NextColumn();
					ImGui::Text("Is Weapon: %u", selectedItem->IsWeapon());
					ImGui::Columns(1);
					ImGui::Separator();
					if (selectedItem->CanUse()) {
						if (ImGui::Button("Use"))
							selectedItem->Use();
						ImGui::SameLine();
					}
					if (ImGui::Button("Use From Inventory"))
						selectedItem->UseFromInventory();
					ImGui::SameLine();
					if (ImGui::Button("Use From World"))
						selectedItem->UseFromWorld();
					Vec3 playerpos = ArkPlayer::GetInstance().GetPlayerWorldEyePos();
					if (ImGui::Button("Drop"))
						selectedItem->Drop(1, &playerpos);
					if (selectedItem->CanConsume()) {
						ImGui::SameLine();
						if (ImGui::Button("Consume"))
							selectedItem->Consume(1);
					}
					ImGui::InputInt("Item Count", &selectedItemObj->m_count);
					ImGui::Checkbox("Stackable", &selectedItemObj->m_bStackable);
					ImGui::SameLine();
					ImGui::BeginDisabled();
					ImGui::Checkbox("Favorite", &selectedItemObj->m_bFavorite);
					ImGui::EndDisabled();
					ImGui::SameLine();
					ImGui::Checkbox("Junk", &selectedItemObj->m_bJunk);
					ImGui::SameLine();
					ImGui::Checkbox("Important", &selectedItemObj->m_bIsImportant);
				}
			}
		}
		if (ImGui::Button("Make the game unplayable")) {
			gCLEnv->entUtils->ArkPlayerPtr()->m_pInventory->m_size = ArkInventory::EArkGridSizes::smallExternal;
		}
		ImGui::EndChild();
		//TODO: add items
		ImGui::EndTabItem();
	}
}

void PlayerManager::loadPosition(int saveSlot) {
	if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
		if (positions[saveSlot] != Vec3_tpl{ 0, 0, 0 }) {
			gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->SetPos(positions[saveSlot]);
			std::string playerMessage = "Player position set to ";
			gCLEnv->gui->logItem(
				playerMessage + "Pos "+ std::to_string(saveSlot + 1) + " at " + std::to_string(positions[saveSlot].x) + "," +
				std::to_string(positions[saveSlot].y) + "," + std::to_string(positions[saveSlot].z), modName);
		}
		else {
			gCLEnv->gui->logItem(
				std::string("Invalid Saved Position: ") + std::to_string(positions[saveSlot].x) + "," +
				std::to_string(positions[saveSlot].y) + "," + std::to_string(positions[saveSlot].z), modName);
		}
	}
}
void PlayerManager::savePosition(int saveSlot, Vec3_tpl<float> pos) {
	positions[saveSlot] = gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetPos();
	gCLEnv->gui->logItem("Pos " + std::to_string(saveSlot + 1) + " set to " + std::to_string(positions[saveSlot].x) + "," + std::to_string(positions[saveSlot].y) + "," + std::to_string(positions[saveSlot].z), modName);
}


void PlayerManager::drawMenuBar() {
    if(ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Player")) {
            ImGui::MenuItem("Refresh Abilities");
            if (ImGui::MenuItem("Full Heal")) {
                if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
                    gCLEnv->entUtils->ArkPlayerPtr()->SetHealth(gCLEnv->entUtils->ArkPlayerPtr()->GetMaxHealth());
                }
            }
            ImGui::MenuItem("God Mode", NULL, &godMode);
            ImGui::MenuItem("Show Player Manager", NULL, &showPlayerManager);
            ImGui::EndMenu();
            // }
        }
        ImGui::EndMainMenuBar();
    }
}

void PlayerManager::update() {
//	if (!gEnv->pSystem->IsPaused()) {
//		abilityRequestHandler(log);
//	}
//	checkAbilities(log);
	static ICVar* g_godMode = gEnv->pConsole->GetCVar("g_godMode");
	g_godMode->Set(godMode);

//	if (enablePosHotKeys) {
//		for (int i = 1; i <= 5; i++) {
//			if (GetAsyncKeyState(0x30 + i) & 1) {
//				if (GetAsyncKeyState(VK_SHIFT)) {
//					loadPosition(i - 1);
//				} else if(GetAsyncKeyState(VK_CONTROL)) {
//					savePosition(i - 1, gCLEnv->entUtils->ArkPlayerPtr()->GetEntity()->GetPos());
//				}
//			}
//		}
//	}
}


//PRIVATE:
#if 0
void ChairloaderGUIPlayerManager::checkAbilities(ChairloaderGUILog* log) {
	if (refreshAbilityList) {
		if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
			for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
				if (gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
					itr->acquired = gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent->HasAbility(itr->id);
				}
				//abilityDisplayList.emplace_back(entry);
			}
			std::sort(abilityDisplayList.begin(), abilityDisplayList.end(), AbilityEntrySortByName);
			refreshAbilityList = false;
			log->logItem("Ability list refreshed", modName);
			// return logMessage{"Ability list refreshed", time(nullptr), logLevel::normal};
		}
		else {
			log->logItem("Player pointer null", modName);
		}
	}
}

void ChairloaderGUIPlayerManager::abilityRequestHandler(ChairloaderGUILog* log) {
	try {
		if (!AbilityListInitialized) {
			if (gCLEnv->entUtils->ArkPlayerPtr() != nullptr) {
				for (auto itr = gCLEnv->entUtils->abilityLibrary.arkAbilityMap.begin(); itr != gCLEnv->entUtils->abilityLibrary.
				     arkAbilityMap.end(); ++itr) {
					abilityEntry entry = {itr->first, itr->second, false};
					if (gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
						if (gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent->HasAbility(itr->first)) {
							entry.acquired = true;
						}
					}
					abilityDisplayList.emplace_back(entry);

				}
				std::sort(abilityDisplayList.begin(), abilityDisplayList.end(), AbilityEntrySortByName);
				AbilityListInitialized = true;
				log->logItem("Ability List Initialized", modName);
				// return logMessage{"Ability List Initialized", time(nullptr), logLevel::normal};
			}
		}
		else {
			if (!abilityRequestQueue.empty()) {
				uint64_t id = abilityRequestQueue.front();
				abilityRequestQueue.pop();
				abilityEntry* entry = nullptr;
				for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
					if (itr->id == id) {
						entry = itr._Ptr;
					}
				}
				if (entry != nullptr) {
					if (!entry->acquired) {
						if (gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr && !
							gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent->HasAbility(entry->id)) {
							gCLEnv->entUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent->GrantAbility(entry->id);

							// CryLog("Granted Ability: %s\n", gCLEnv->entUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second.c_str());
							entry->acquired = true;
							// std::string msg = "Granted Ability: " + gCLEnv->entUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second + "\n";
							log->logItem(
								("Granted Ability: " + gCLEnv->entUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second +
									"\n"), modName);
						}
						else {
							throw("Error, Ability Component Not Found");
						}
					}
				}
				else {
					throw("Error, invalid ability id");
				}
			}
		}
	}
	catch (std::string c) {
		log->logItem(c, modName, logLevel::error);
	}
}
#endif