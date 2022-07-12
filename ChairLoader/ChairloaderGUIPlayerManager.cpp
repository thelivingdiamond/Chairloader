#include "pch.h"
#include "ChairloaderGUIPlayerManager.h"

#include "Prey/CrySystem/ILocalizationManager.h"
#include "boost/algorithm/string.hpp"
#include "Prey/CryAction/GameObject.h"
#include "Prey/CryGame/Game.h"

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
		static std::vector<std::string> positionStrings = { "Pos 1", "Pos 2", "Pos 3", "Pos 4", "pos 5" };
		static std::vector<Vec3_tpl<float>> savedPositions = { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0} };
		for (int i = 0; i < 5; i++) {
			if (ImGui::Button(positionStrings[i].c_str())) {
				// check if the saved position is null
				if (gEntUtils->ArkPlayerPtr() != nullptr) {
					if (savedPositions[i] != Vec3_tpl{ 0,0,0 }) {
						gEntUtils->ArkPlayerPtr()->GetEntity()->SetPos(savedPositions[i]);
						std::string playerMessage = "Player position set to ";
						GUILog->logItem(playerMessage + positionStrings[i] + " at " + std::to_string(savedPositions[i].x) + "," + std::to_string(savedPositions[i].y) + "," + std::to_string(savedPositions[i].z), modName);
					}
					else {
						GUILog->logItem(std::string("Invalid Saved Position: ") + std::to_string(savedPositions[i].x) + "," + std::to_string(savedPositions[i].y) + "," + std::to_string(savedPositions[i].z), modName);
					}
				}
			}
			ImGui::SameLine();
		}
		ImGui::SameLine();
		ImGuiUtils::HelpMarker("These buttons will set the player to a stored position");
		// add a dropdown list and button to save to each of the four positions
		ImGui::Separator();

		static int index = 0;
		std::string comboPreviewValue = positionStrings[index];
		if (ImGui::BeginCombo("Position Combo", comboPreviewValue.c_str())) {
			for (int i = 0; i < positionStrings.size(); i++) {
				bool isSelected = (i == index);
				if (ImGui::Selectable(positionStrings[i].c_str(), isSelected)) {
					index = i;
				}
				// if(isSelected){
				// 	ImGui::SetItemDefaultFocus();
				 //}
			}
			ImGui::EndCombo();
		}
		if (ImGui::Button("Save Position")) {
			if (gEntUtils->ArkPlayerPtr() != nullptr) {
				savedPositions[index] = gEntUtils->ArkPlayerPtr()->GetEntity()->GetPos();
				GUILog->logItem(positionStrings[index] + " set to " + std::to_string(savedPositions[index].x) + "," + std::to_string(savedPositions[index].y) + "," + std::to_string(savedPositions[index].z), modName);
			}
		}
		ImGui::EndTabItem();
	}
}
void ChairloaderGUIPlayerManager::drawHealthTab() {
	if (ImGui::BeginTabItem("Health/Armor")) {
		if (gEntUtils->ArkPlayerPtr() != nullptr) {
			float currentHealth = gEntUtils->ArkPlayerPtr()->GetHealth();
			float maxHealth = gEntUtils->ArkPlayerPtr()->GetMaxHealth();
			float currentArmor = gEntUtils->ArkPlayerPtr()->GetArmor();
			float maxArmor = gEntUtils->ArkPlayerPtr()->GetMaxArmor();
			static float setHealth = 0;
			ImGui::Text("Player Entity Name: %s", gEntUtils->ArkPlayerPtr()->GetEntity()->GetName());
			ImGui::Text("Player Entity ID: %u", gEntUtils->ArkPlayerPtr()->GetEntity()->GetId());
			ImGui::Text("Health: %.2f / %.2f", currentHealth / 10, maxHealth / 10);
			ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(209, 37, 43, 255));
			ImGui::ProgressBar(currentHealth / maxHealth);
			ImGui::PopStyleColor();
			ImGui::InputFloat("Set Health", &setHealth, 0, 0, "%.2f");
			if (ImGui::Button("Set")) {
				gEntUtils->ArkPlayerPtr()->SetHealth(setHealth * 10);
			}
			ImGui::SameLine();

			ImGui::Checkbox("God Mode", &godMode);
			ImGui::Text("Armor: %.2f / %.2f", currentArmor / 10, maxArmor / 10);
			ImGui::ProgressBar(maxArmor / currentArmor);
			// TODO: figure out armor and psi

		}
		ImGui::EndTabItem();
	}
}
void ChairloaderGUIPlayerManager::drawAbilitiesTab() {
	if (ImGui::BeginTabItem("Abilities")) {
		refreshAbilityList = ImGui::Button("Refresh");
		if (ImGui::BeginChild("AbilityList", ImGui::GetContentRegionAvail(), false, ImGuiWindowFlags_HorizontalScrollbar)) {
			for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
				if (!itr->acquired) {
					if (ImGui::Selectable(itr->name.c_str())) {
						abilityRequestQueue.push(itr->id);
					}
				}
				else {
					ImGui::TextColored(ImVec4{ 1.0f,1.0f,1.0f,0.7f }, "%s - acquired", itr->name.c_str());
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
}
void ChairloaderGUIPlayerManager::drawInventoryTab() {
	if (gEntUtils->ArkPlayerPtr() != nullptr) {
		inventoryItems.clear();
		for (auto& cell : gEntUtils->ArkPlayerPtr()->m_pInventory->m_storedItems) {
			std::pair <int, ArkInventory::StorageCell> newItem = { cell.m_entityId, cell };
			inventoryItems.insert(newItem);
		}
	}
	if(ImGui::BeginTabItem("Inventory Test")) {
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
		ImGui::SetWindowSize(ImVec2(inventoryWidth * size + 40, inventoryHeight * size + 30 + 300));
		static unsigned int selected = 0;
		ArkGame* game = game->GetArkGame();
		ArkItemSystem* itemSystem = game->m_pArkItemSystem.get();
		if (ImGui::BeginChild("Inventory Grid", ImVec2(inventoryWidth * size + 20, inventoryHeight * size + 30), false)) {
			ImGui::Text("Inventory: ");
				// ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 20, ImGui::GetCursorPos().y + 20));
				ImVec2 windowPos = ImGui::GetCursorPos();
				ImVec2 screenCursorPos = ImGui::GetCursorScreenPos();
				
				// loop 12 times
				ImDrawList* draw_list = ImGui::GetWindowDrawList();
				for (int i = 0; i <= inventoryWidth; i++) {
					draw_list->AddLine(ImVec2(screenCursorPos.x + i * size, screenCursorPos.y), ImVec2(screenCursorPos.x + i * size, screenCursorPos.y + inventoryHeight * size), ImColor(255, 255, 255, 80));
				}
			// draw the horizontal lines
			for (int i = 0; i <= inventoryHeight; i++) {
				draw_list->AddLine(ImVec2(screenCursorPos.x, screenCursorPos.y + i * size), ImVec2(screenCursorPos.x + inventoryWidth * size, screenCursorPos.y + i * size), ImColor(255, 255, 255, 80));
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
				ImGui::SetCursorPos(ImVec2(windowPos.x + (item.second.m_x - 1) * size, windowPos.y + (item.second.m_y - 1) * size));
				ImGuiUtils::textRectangle(name_string, item.second.m_width * size, item.second.m_height * size, ImColor(255, 255, 255, 255), ImColor(20, 20, 20, 255));

				ImGui::SetCursorPos(ImVec2(windowPos.x + (item.second.m_x - 1) * size, windowPos.y + (item.second.m_y - 1) * size));
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
			ImGui::EndChild();
			
		}
		// ImGui::SameLine();
		if(ImGui::BeginChild("Item Editor", ImVec2(0, 300))) {
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
			ImGui::EndChild();
		}
		//TODO: add items
		ImGui::EndTabItem();
	}
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
}


//PRIVATE:
void ChairloaderGUIPlayerManager::checkAbilities(ChairloaderGUILog* log) {
	if (refreshAbilityList) {
		if (gEntUtils->ArkPlayerPtr() != nullptr) {
			for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
				if (gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
					itr->acquired = gPreyFuncs->ArkAbilityComponentF->HasAbility(gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), itr->id);
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
				for (auto itr = gEntUtils->abilityLibrary.arkAbilityMap.begin(); itr != gEntUtils->abilityLibrary.arkAbilityMap.end(); ++itr) {
					abilityEntry entry = { itr->first, itr->second, false };
					if (gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
						if (gPreyFuncs->ArkAbilityComponentF->HasAbility(gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), itr->first)) {
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
						if (gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get() != nullptr && !gPreyFuncs->ArkAbilityComponentF->HasAbility(gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), entry->id)) {
							gPreyFuncs->ArkAbilityComponentF->GrantAbility(gEntUtils->ArkPlayerPtr()->m_playerComponent.m_pAbilityComponent.get(), entry->id);

							// CryLog("Granted Ability: %s\n", gEntUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second.c_str());
							entry->acquired = true;
							// std::string msg = "Granted Ability: " + gEntUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second + "\n";
							log->logItem(("Granted Ability: " + gEntUtils->abilityLibrary.arkAbilityMap.find(entry->id)->second + "\n"), modName);
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