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
			// TODO: get player position and save it to the position list
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
			std::pair <int, StorageCell> newItem = { cell.m_entityId, cell };
			inventoryItems.insert(newItem);
		}
	}
	if (ImGui::BeginTabItem("Inventories")) {
		if (ImGui::BeginChild("InventoryTable", ImVec2(0, 0), true)) {
			if (ImGui::BeginTable("InventoryTable", 5, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_BordersOuterH)) {
				ImGui::TableSetupColumn("Item");
				ImGui::TableSetupColumn("x", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupColumn("y", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupColumn("width", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupColumn("height", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableHeadersRow();
				for (auto& item : inventoryItems) {
					ImGui::TableNextRow();
					ImGui::TableSetColumnIndex(0);
					// ImGui::Text("%d", item.first);
					IEntity* itemEntity = gEnv->pEntitySystem->GetEntity(item.first);
					if (itemEntity != nullptr) {
						if(itemEntity->GetArchetype() != nullptr) {
							ImGui::Text("%s", itemEntity->GetArchetype()->GetName());
						}
						
					}
					ImGui::TableSetColumnIndex(1);
					ImGui::Text("%d", item.second.m_x);
					ImGui::TableSetColumnIndex(2);
					ImGui::Text("%d", item.second.m_y);
					ImGui::TableSetColumnIndex(3);
					ImGui::Text("%d", item.second.m_width);
					ImGui::TableSetColumnIndex(4);
					ImGui::Text("%d", item.second.m_height);
				}
				ImGui::EndTable();
			}
			ImGui::EndChild();
		}


		ImGui::EndTabItem();
	}
	if(ImGui::BeginTabItem("Inventory Test")) {
		float size = 100.0f;
		ImGui::Text("Inventory: "); 
		// ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPos().x + 20, ImGui::GetCursorPos().y + 20));
		ImVec2 windowPos = ImGui::GetCursorPos();
		for (auto& item : inventoryItems) {
			std::wstring name;
			wstring localizedName;
			std::string stringname = "";
			IEntity* itemEntity = gEnv->pEntitySystem->GetEntity(item.first);
			if (itemEntity != nullptr) {
				if (itemEntity->GetArchetype() != nullptr) {
					// auto proxy = (IGameObject*)itemEntity->GetProxy(EEntityProxy::ENTITY_PROXY_USER);
					// // printf("%p", proxy);
					// for (auto& extension : ((CGameObject*)proxy)->m_extensions) {
					// 	printf("%p\n", &extension);
					// }
					std::string tempstring = itemEntity->GetArchetype()->GetName();
					tempstring = tempstring.substr(tempstring.find_first_of(".") + 1, tempstring.size() - tempstring.find_first_of(".") - 1);
					stringname = stringname + tempstring;
					// boost::algorithm::to_lower(stringname);
					if (gEnv->pSystem->GetLocalizationManager()->LocalizeString(stringname.c_str(), localizedName)) {
						name = localizedName.c_str();
					}
					else {
						name = L"fuck";
					}
				}
				// name = itemEntity->GetDisplayName();
			}
			std::string name_string = std::string(name.begin(), name.end());
			ImGui::SetCursorPos(ImVec2(windowPos.x + item.second.m_x * size, windowPos.y + item.second.m_y * size));
			ImGuiUtils::selectableRectangle(name_string, item.second.m_width * size, item.second.m_height * size, ImColor(255, 180, 255, 255));
		}
		// ImGuiUtils::selectableRectangle("Fuck", 128, 128, ImColor(255, 180, 255, 255));


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