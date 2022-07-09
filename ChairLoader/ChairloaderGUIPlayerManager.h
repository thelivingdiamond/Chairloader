#pragma once
#include "pch.h"

#include <Prey/ArkBasicTypes.h>
#include "EntityUtils.h"
#include "preyDllObjects.h"
#include <Prey/ArkEntityArchetypeLibrary.h>
#include "GUIUtils.h"
class ChairloaderGUIPlayerManager
{
public:
	struct abilityEntry {
	public:
		uint64_t id;
		std::string name;
		bool acquired{ false };
	};
	static bool AbilityEntrySortByName(const abilityEntry& lhs, const abilityEntry& rhs) {
		return lhs.name < rhs.name;
	}
private:
	bool godMode;
	const std::string modName = "ChairloaderGUI.PlayerManager";
	bool AbilityListInitialized, refreshAbilityList;
	std::vector<abilityEntry> abilityDisplayList;
	std::queue<uint64_t> abilityRequestQueue;
	std::queue<Vec3_tpl<float>> positionRequestQueue;
	// TODO: inventory items
	std::map<uint32_t, StorageCell> inventoryItems;
public:
	ChairloaderGUIPlayerManager() = default;

	/**
	 * \brief 
	 * \param bShow 
	 */
	void draw(bool* bShow) {
		if (!ImGui::Begin("Player Manager", bShow, ImGuiWindowFlags_NoNavInputs)) {
			ImGui::End();
			return;
		}
		if (ImGui::BeginTabBar("Player Bar")) {
			if (ImGui::BeginTabItem("Position")) {
				static std::vector<std::string> positionStrings = { "Pos 1", "Pos 2", "Pos 3", "Pos 4", "pos 5" };
				static std::vector<Vec3_tpl<float>> savedPositions = { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0} };
				for (int i = 0; i < 5; i++) {
					if(ImGui::Button(positionStrings[i].c_str())) {
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
				if(ImGui::BeginCombo("Position Combo", comboPreviewValue.c_str())){
					for(int i = 0; i < positionStrings.size(); i++){
						bool isSelected = (i == index);
						if(ImGui::Selectable(positionStrings[i].c_str(), isSelected)){
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
			if (ImGui::BeginTabItem("Health/Armor")) {
				if (gEntUtils->ArkPlayerPtr() != nullptr) {
					float currentHealth = gEntUtils->ArkPlayerPtr()->GetHealth();
					float maxHealth = gEntUtils->ArkPlayerPtr()->GetMaxHealth();
					float currentArmor = gEntUtils->ArkPlayerPtr()->GetArmor();
					float maxArmor = gEntUtils->ArkPlayerPtr()->GetMaxArmor();
					static float setHealth = 0;
					ImGui::Text("Health: %.2f / %.2f", currentHealth/10, maxHealth/10);
					ImGui::PushStyleColor(ImGuiCol_PlotHistogram, IM_COL32(209, 37, 43, 255));
					ImGui::ProgressBar(currentHealth / maxHealth);
					ImGui::PopStyleColor();
					ImGui::InputFloat("Set Health", &setHealth, 0, 0, "%.2f");
					if(ImGui::Button("Set")) {
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
			if (ImGui::BeginTabItem("Inventories")) {
				if (ImGui::BeginChild("InventoryTable", ImVec2(0, 0), true)) {
					if (ImGui::BeginTable("InventoryTable", 3, ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_BordersOuterH)) {
						ImGui::TableSetupColumn("Item", ImGuiTableColumnFlags_WidthFixed);
						ImGui::TableSetupColumn("x", ImGuiTableColumnFlags_WidthFixed);
						ImGui::TableSetupColumn("y", ImGuiTableColumnFlags_WidthFixed);
						ImGui::TableHeadersRow();
						for (auto& item : inventoryItems) {
							ImGui::TableNextRow();
							ImGui::TableSetColumnIndex(0);
							ImGui::Text("%d", item.first);
							ImGui::TableSetColumnIndex(1);
							ImGui::Text("%d", item.second.m_x);
							ImGui::TableSetColumnIndex(2);
							ImGui::Text("%d", item.second.m_y);
						}
						ImGui::EndTable();
					}
					ImGui::EndChild();
				}


				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	}
	void drawMenuBar(bool* control) {
		if (ImGui::BeginMenu("Player")) {
			ImGui::MenuItem("Refresh Abilities");
			if(ImGui::MenuItem("Full Heal")) {
				if(gEntUtils->ArkPlayerPtr() != nullptr) {
					gEntUtils->ArkPlayerPtr()->SetHealth(gEntUtils->ArkPlayerPtr()->GetMaxHealth());
				}
			}
			ImGui::MenuItem("God Mode", NULL, &godMode);
			ImGui::MenuItem("Show Player Manager", NULL, control);
			ImGui::EndMenu();
			// }
		}
	}

	void update(ChairloaderGUILog* log) {
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
private:
	// Handlers
	void checkAbilities(ChairloaderGUILog* log) {
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
	void abilityRequestHandler(ChairloaderGUILog* log) {
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
};

