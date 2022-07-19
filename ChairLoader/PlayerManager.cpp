#include "pch.h"
#include "PlayerManager.h"

#include "Logging.h"
#include "Prey/CrySystem/ILocalizationManager.h"
#include "boost/algorithm/string.hpp"
#include "Prey/CryAction/GameObject.h"
#include "Prey/CryGame/Game.h"
#include "Chairloader.h"

// PUBLIC:
void ChairloaderGUIPlayerManager::draw(bool* bShow) {
	if (!ImGui::Begin("Player Manager", bShow, ImGuiWindowFlags_NoNavInputs)) {
		ImGui::End();
		return;
	}

	if (ImGui::BeginTabBar("Player Bar")) {
		ImGui::BeginDisabled(gEntUtils->ArkPlayerPtr() == nullptr);
		drawPositionTab();
		drawHealthTab();
		drawAbilitiesTab();
		drawInventoryTab();
		ImGui::EndDisabled();
		ImGui::EndTabBar();
	}

	ImGui::End();
}

void ChairloaderGUIPlayerManager::drawPositionTab() {
	if (ImGui::BeginTabItem("Position")) {
		// static std::vector<std::string> positionStrings = {"Pos 1", "Pos 2", "Pos 3", "Pos 4", "pos 5"};
		// static std::vector<Vec3_tpl<float>> savedPositions = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
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
				savePosition(i, gEntUtils->ArkPlayerPtr()->GetEntity()->GetPos());
			}
			ImGui::SameLine();
		}


		// if (ImGui::BeginCombo("Position Combo", comboPreviewValue.c_str())) {
		// 	for (int i = 0; i < positionStrings.size(); i++) {
		// 		bool isSelected = (i == index);
		// 		if (ImGui::Selectable(positionStrings[i].c_str(), isSelected)) {
		// 			index = i;
		// 		}
		// 		// if(isSelected){
		// 		// 	ImGui::SetItemDefaultFocus();
		// 		//}
		// 	}
		// 	ImGui::EndCombo();
		// }
		// if (ImGui::Button("Save Position")) {
		// 	if (gEntUtils->ArkPlayerPtr() != nullptr) {
		// 		savedPositions[index] = gEntUtils->ArkPlayerPtr()->GetEntity()->GetPos();
		// 		GUILog->logItem(
		// 			positionStrings[index] + " set to " + std::to_string(savedPositions[index].x) + "," +
		// 			std::to_string(savedPositions[index].y) + "," + std::to_string(savedPositions[index].z), modName);
		// 	}
		// }
		ImGui::EndTabItem();
	}
}

void ChairloaderGUIPlayerManager::drawHealthTab() {
	if (ImGui::BeginTabItem("Health/Statuses")) {
		if (gEntUtils->ArkPlayerPtr() != nullptr) {
			float currentHealth = gEntUtils->ArkPlayerPtr()->GetHealth();
			float maxHealth = gEntUtils->ArkPlayerPtr()->GetMaxHealth();
			ArkPlayer* player = player->GetInstancePtr();
			float currentArmor = gEntUtils->ArkPlayerPtr()->GetArmor();
			float maxArmor = gEntUtils->ArkPlayerPtr()->GetMaxArmor();
			float currentPsi = gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_points;
			float maxPsi = gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_maxPoints;
			float currentFatigue = gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pFatigueComponent.get()->m_fatigue.
			                                  m_amount;
			float maxFatigue = gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pFatigueComponent.get()->m_fatigue.
			                              m_maxAmount;
			static float setHealth = 0;
			static float setPsi = 0;
			static float setMaxPsi = 0;
			ImGui::Text("Player Entity Name: %s", gEntUtils->ArkPlayerPtr()->GetEntity()->GetName());
			ImGui::Text("Player Entity ID: %u", gEntUtils->ArkPlayerPtr()->GetEntity()->GetId());
			ImGui::Text("Health: %.2f / %.2f", currentHealth / 10, maxHealth / 10);
			ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(209, 37, 43, 255));
			ImGui::ProgressBar(currentHealth / maxHealth);
			ImGui::PopStyleColor();
			if (ImGui::InputFloat("Set Health", &setHealth, 0, 0, "%.2f")) {
				gEntUtils->ArkPlayerPtr()->SetHealth(setHealth * 10);
				setHealth = gEntUtils->ArkPlayerPtr()->GetHealth() / 10;
			}
			ImGui::Checkbox("God Mode", &godMode);
			ImGui::Text("Armor: %.2f / %.2f", currentArmor / 10, maxArmor / 10);
			ImGui::ProgressBar(maxArmor / currentArmor);
			//Psi
			ImGui::Text("Psi: %.2f / %.2f", currentPsi, maxPsi);
			ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(130, 8, 216, 255));
			ImGui::ProgressBar(currentPsi / maxPsi);
			ImGui::PopStyleColor();
			if (ImGui::InputFloat("Set Psi", &setPsi, 0, 0, "%.2f")) {
				gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_points = setPsi;
				setPsi = gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_points;
				CArkPsiComponent::UpdateHUDMarkerElements(
					gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get());
			}
			//Set Max Psi
			if (ImGui::InputFloat("Set Max Psi", &setMaxPsi, 0, 0, "%.2f")) {
				gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_maxPoints = setMaxPsi;
				setMaxPsi = gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pPsiComponent.get()->m_maxPoints;
			}
			//show fatigue
			ImGui::Text("Stamina: %.2f / %.2f", maxFatigue - currentFatigue, maxFatigue);
			ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(150, 150, 150, 255));
			ImGui::ProgressBar((maxFatigue - currentFatigue) / maxFatigue);
			ImGui::PopStyleColor();
			ImGui::Checkbox("Infinite Stamina", (bool*)&gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pFatigueComponent.get()->m_bInfiniteStamina);

			
			ImGui::Separator();
			ImGui::Text("Statuses: ");
			ImGui::Columns(2);
			for (auto& status : gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get()->m_statuses) {
				if (ImGui::Selectable(status.get()->m_desc.m_Name.m_str)) {
					status->m_desc.m_Duration = 1000.0f;
					status->Activate(0);
					// gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->ForceStatus
					// status->UpdateHudIcon(status.get());
					// status->UpdateVisuals(true, true);
					// gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent->SetStatus(gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get(), status.get()->m_status, true, false);
					// status.get()->UpdateVisuals(true, false);
				}
				ImGui::NextColumn();
				ImGui::Text("%u", status.get()->IsEnabled());
				ImGui::Text("%f", status.get()->m_desc.m_Duration);
				// printf("Offset: %llX", (uintptr_t)&status->m_desc.m_Phases - (uintptr_t)&status->m_desc); //Offset: 136
				// for(auto & phase : status->m_desc.m_Phases) {
				// 	ImGui::Text("%s", phase.m_HudIcon.c_str());
				// }
				ImGui::NextColumn();
			}
			ImGui::Columns(1);
			if (ImGui::Button("Add Status")) {
				gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pStatusComponent.get()->m_activeStatuses.emplace_back(
					EArkPlayerStatus::Radiation);
			}
			// TODO: figure out armor and psi

		}
		ImGui::EndTabItem();
	}
}

void ChairloaderGUIPlayerManager::drawAbilitiesTab() {
	if (ImGui::BeginTabItem("Abilities")) {
		refreshAbilityList = ImGui::Button("Refresh");
		if (ImGui::BeginChild("AbilityList", ImGui::GetContentRegionAvail(), false,
		                      ImGuiWindowFlags_HorizontalScrollbar)) {
			for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
				if (!itr->acquired) {
					if (ImGui::Selectable(itr->name.c_str())) {
						abilityRequestQueue.push(itr->id);
					}
				}
				else {
					ImGui::TextColored(ImVec4{1.0f, 1.0f, 1.0f, 0.7f}, "%s - acquired", itr->name.c_str());
				}
			}
			ImGui::EndChild();
		}
		//TODO: figure out how to remove abilities too
		// std::vector<ArkAbilityData>* abilities = &gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get()->m_abilities;
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
		//             
		//         }
		//     }
		// }
		ImGui::EndTabItem();
	}
	if (ImGui::BeginTabItem("Smoke Form Test")) {
		auto abilityComponent = gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get();
		// static auto acquiredAbilities = abilityComponent->GetAcquiredAbilities(abilityComponent);
		for (auto& power : gEntUtils->ArkPlayerPtr()->GetPsiPowerComponent(gEntUtils->ArkPlayerPtr())->m_powers) {
			wstring localizedName;
			gEnv->pSystem->GetLocalizationManager()->LocalizeString(power->GetDescription(), localizedName);
			ImGui::Text("%ls", localizedName.c_str());
		}
		auto PsiPowerComponent = gEntUtils->ArkPlayerPtr()->GetPsiPowerComponent(gEntUtils->ArkPlayerPtr());
		ArkPlayerMovementFSM* fsm = &gEntUtils->ArkPlayerPtr()->m_movementFSM;
		if (ImGui::Button("Smoke Form"))
			PsiPowerComponent->UnlockPower(PsiPowerComponent, EArkPsiPowers::smokeForm, 1);
		if (ImGui::Button("Fly Mode Test"))
			fsm->m_flyMode = ArkPlayerMovementFSM::EArkFlyMode::on;
		ImGui::Text("Fly Mode: %u", fsm->m_flyMode);
		ImGui::Text("Current State: %u", fsm->m_currentStateId);
		ImGui::Text("Stance: %u", gEntUtils->ArkPlayerPtr()->GetStance());
		ImGui::Text("Spectator Mode: %u", gEntUtils->ArkPlayerPtr()->GetSpectatorMode());
		ImGui::Text("Input Disabled Mode: %u", gEntUtils->ArkPlayerPtr()->m_input.m_disabledMode);
		ArkPlayerCamera* camera = &gEntUtils->ArkPlayerPtr()->m_camera;
		ImGui::Text("Camera Mode: %llu", (uintptr_t)camera->m_customViewFunction.target<void __cdecl(SViewParams&)>());
		ImGui::Separator();
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
			gEntUtils->ArkPlayerPtr()->m_movementFSM.m_smokeState.Exit();
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

void ChairloaderGUIPlayerManager::drawInventoryTab() {
	if (gEntUtils->ArkPlayerPtr() != nullptr) {
		inventoryItems.clear();
		for (auto& cell : gEntUtils->ArkPlayerPtr()->m_pInventory->m_storedItems) {
			std::pair<int, ArkInventory::StorageCell> newItem = {cell.m_entityId, cell};
			inventoryItems.insert(newItem);
		}
	}
	if (ImGui::BeginTabItem("Inventory")) {
		float size = 75.0f;
		int inventoryWidth = 0, inventoryHeight = 0;
		if (gEntUtils->ArkPlayerPtr() != nullptr) {
			inventoryHeight = gEntUtils->ArkPlayerPtr()->m_pInventory->GetHeight();
			inventoryWidth = gEntUtils->ArkPlayerPtr()->m_pInventory->GetWidth();
		}
		else {
			inventoryWidth = 12;
			inventoryHeight = 8;
		}
		if (!ImGui::IsWindowDocked())
			ImGui::SetWindowSize(ImVec2(inventoryWidth * size + 40, inventoryHeight * size + 30 + 300));
		static unsigned int selected = 0;
		ArkGame* game = game->GetArkGame();
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
				IArkItem* itemObj = itemSystem->getItem(itemSystem, item.first);
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
					// GUILog->logItem(name_string + " Pressed!", modName);
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
				IArkItem* selectedItem = itemSystem->getItem(itemSystem, selected);
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
					Vec3_tpl<float> playerpos;
					gPreyFuncs->ArkPlayerF->getPlayerWorldEyePos(gEntUtils->ArkPlayerPtr(), &playerpos);
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
		ImGui::EndChild();
		//TODO: add items
		ImGui::EndTabItem();
	}
}

void ChairloaderGUIPlayerManager::loadPosition(int saveSlot) {
	if (gEntUtils->ArkPlayerPtr() != nullptr) {
		if (positions[saveSlot] != Vec3_tpl{ 0, 0, 0 }) {
			gEntUtils->ArkPlayerPtr()->GetEntity()->SetPos(positions[saveSlot]);
			std::string playerMessage = "Player position set to ";
			GUILog->logItem(
				playerMessage + "Pos "+ std::to_string(saveSlot + 1) + " at " + std::to_string(positions[saveSlot].x) + "," +
				std::to_string(positions[saveSlot].y) + "," + std::to_string(positions[saveSlot].z), modName);
		}
		else {
			GUILog->logItem(
				std::string("Invalid Saved Position: ") + std::to_string(positions[saveSlot].x) + "," +
				std::to_string(positions[saveSlot].y) + "," + std::to_string(positions[saveSlot].z), modName);
		}
	}
}
void ChairloaderGUIPlayerManager::savePosition(int saveSlot, Vec3_tpl<float> pos) {
	positions[saveSlot] = gEntUtils->ArkPlayerPtr()->GetEntity()->GetPos();
	GUILog->logItem("Pos " + std::to_string(saveSlot + 1) + " set to " + std::to_string(positions[saveSlot].x) + "," + std::to_string(positions[saveSlot].y) + "," + std::to_string(positions[saveSlot].z), modName);
}


void ChairloaderGUIPlayerManager::drawMenuBar(bool* control) {
	if (ImGui::BeginMenu("Player")) {
		ImGui::MenuItem("Refresh Abilities");
		if (ImGui::MenuItem("Full Heal")) {
			if (gEntUtils->ArkPlayerPtr() != nullptr) {
				gEntUtils->ArkPlayerPtr()->SetHealth(gEntUtils->ArkPlayerPtr()->GetMaxHealth());
			}
		}
		ImGui::MenuItem("God Mode", NULL, &godMode);
		ImGui::MenuItem("Show Player Manager", NULL, control);
		ImGui::EndMenu();
		// }
	}
}

void ChairloaderGUIPlayerManager::update(ChairloaderGUILog* log) {
	if (!gEnv->pSystem->IsPaused()) {
		abilityRequestHandler(log);
	}
	checkAbilities(log);
	if (godMode) {
		CGodMode* godMode = gPreyFuncs->ArkPlayerF->getGodModeInstance();
		godMode->m_godMode = 1;
	}
	else {
		CGodMode* godMode = gPreyFuncs->ArkPlayerF->getGodModeInstance();
		godMode->m_godMode = 0;
	}
	if (enablePosHotKeys) {
		for (int i = 1; i <= 5; i++) {
			if (GetAsyncKeyState(0x30 + i) & 1) {
				if (GetAsyncKeyState(VK_SHIFT)) {
					loadPosition(i - 1);
				} else if(GetAsyncKeyState(VK_CONTROL)) {
					savePosition(i - 1, gEntUtils->ArkPlayerPtr()->GetEntity()->GetPos());
				}
			}
		}
	}
}


//PRIVATE:
void ChairloaderGUIPlayerManager::checkAbilities(ChairloaderGUILog* log) {
	if (refreshAbilityList) {
		if (gEntUtils->ArkPlayerPtr() != nullptr) {
			for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
				if (gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
					itr->acquired = gPreyFuncs->ArkAbilityComponentF->HasAbility(
						gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), itr->id);
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
			if (gEntUtils->ArkPlayerPtr() != nullptr) {
				for (auto itr = gEntUtils->abilityLibrary.arkAbilityMap.begin(); itr != gEntUtils->abilityLibrary.
				     arkAbilityMap.end(); ++itr) {
					abilityEntry entry = {itr->first, itr->second, false};
					if (gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
						if (gPreyFuncs->ArkAbilityComponentF->HasAbility(
							gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), itr->first)) {
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
						if (gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr && !
							gPreyFuncs->ArkAbilityComponentF->HasAbility(
								gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), entry->id)) {
							gPreyFuncs->ArkAbilityComponentF->GrantAbility(
								gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), entry->id);
							
							// CryLog("Granted Ability: %s\n", gEntUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second.c_str());
							entry->acquired = true;
							// std::string msg = "Granted Ability: " + gEntUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second + "\n";
							log->logItem(
								("Granted Ability: " + gEntUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second +
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
		log->logItem(c, modName, ChairloaderGUILog::logLevel::error);
	}
}
