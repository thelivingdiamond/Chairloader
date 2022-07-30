#include "EntityManager.h"
#include <Prey/GameDll/ark/player/ArkPlayer.h>

#include "Prey/Cry3DEngine/I3DEngine.h"
ChairloaderGUIEntityManager::ChairloaderGUIEntityManager() {
    archetypeToSpawn = nullptr;
    // chairloaderGlobal = chairloaderIn;
    archetypeFilterRequestQueue.push(archetypeFilterRequest{ "" });
}
ChairloaderGUIEntityManager::~ChairloaderGUIEntityManager() {

}

// void ChairloaderGUIEntityManager::draw(bool* bShow) {
//     // if (!ImGui::Begin("Entity System", bShow, ImGuiWindowFlags_NoNavInputs)) {
//     //     ImGui::End();
//     //     return;
//     // }
//     // ImGui::End();
//     drawEntitySpawner(bShow);
//     drawEntityList(bShow);
// }
void ChairloaderGUIEntityManager::drawEntitySpawner(bool* bShow) {
    if (ImGui::Begin("Entity Spawner", bShow)) {
        static bool usePlayerPos = true, offsetFromPlayer = true;
        static std::string inputId, inputName;
        static std::string statusMessage;
        static float spawnX, spawnY, spawnZ;
        static ImVec4 color{ 1,1,1,1 };
        static time_t statusTimer;
        static int spawnCount{ 1 };
        ImGui::TextColored(color, statusMessage.c_str());

        if (archetypeToSpawn == nullptr) {
            ImGui::Text("Entity Archetype Name: ");
            ImGui::Text("Entity ID: ");
        }
        else {
            ImGui::Text("Entity Archetype Name: %s", archetypeToSpawn->GetName());
            ImGui::Text("Entity ID: %d", archetypeToSpawn->GetId());
        }
        ImGui::InputText("Entity Name", &inputName, ImGuiInputTextFlags_None);
        ImGui::InputInt("Spawn Count", &spawnCount);
        ImGui::Checkbox("Use Player Pos", &usePlayerPos);
        if (usePlayerPos) {
            ImGui::Checkbox("Offset In front of Player", &offsetFromPlayer);
        }
        else {
            ImGui::InputFloat("X", &spawnX);
            ImGui::InputFloat("Y", &spawnY);
            ImGui::InputFloat("Z", &spawnZ);
        }
        if (ImGui::Button("Spawn Entity")) {
            try {
                if (archetypeToSpawn != nullptr) {
                    static Vec3 pos;
                    static Quat rot = Quat{ 0,0,0,1 };
                	archetypeToSpawn;
                    usePlayerPos;
                    offsetFromPlayer;
                    if(usePlayerPos) {
                        pos = gEntUtils->ArkPlayerPtr()->GetEntity()->GetPos();
                        if(offsetFromPlayer) {
	                        pos.x += gEntUtils->ArkPlayerPtr()->m_cachedReticleDir.x * 5;
                            pos.y += gEntUtils->ArkPlayerPtr()->m_cachedReticleDir.y * 5;
                        } 
                    } else {
                        pos = Vec3{ spawnX, spawnY, spawnZ };
                    }
                    std::string archetypeName = archetypeToSpawn->GetName();
                    // if an npc use npc spawning
                    if ((archetypeName.find("ArkRobots") != std::string::npos || archetypeName.find("ArkHumans") != std::string::npos || archetypeName.find("ArkNpcs") != std::string::npos) && archetypeName != "Turrets.Turret_Default") {
                        gEntUtils->spawnNpcFromArchetype(inputName.c_str(), pos, rot, archetypeToSpawn->GetId(), spawnCount);
                    } else {
                        pos.z += 0.2f;
                        gEntUtils->spawnEntityFromArchetype(inputName.c_str(), pos, rot, archetypeToSpawn->GetId(), spawnCount);
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
            catch (std::string& c) {
                color = { 1,0,0,1 };
                statusMessage = c;
                time(&statusTimer);
            }
        }
        ImGui::Text("Filter:");
        ImGui::InputText("##filter text", &archetypeFilterText);
        if (archetypeFilterText != oldArchetypeFilterText) {
            oldArchetypeFilterText = archetypeFilterText;
            archetypeFilterRequestQueue.push(archetypeFilterRequest{ archetypeFilterText });
        }
        ImGuiUtils::HelpMarker("Filter usage:\n"
            "  \"\"         display all lines\n"
            "  \"xxx\"      display lines containing \"xxx\"\n"
            "  \"xxx,yyy\"  display lines containing \"xxx\" or \"yyy\"\n"
            "  \"-xxx\"     hide lines containing \"xxx\"");

        static ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Hideable;
        ImVec2 outer_size = ImVec2(0.0f, 0.0f);

        if (ImGui::BeginTable("EntityArchetypeList", 2, flags, outer_size)) {
            ImGui::TableSetupScrollFreeze(0, 1);
            ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_None);
            ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_None);
            ImGui::TableHeadersRow();

            auto itr = archetypeFilteredList.begin();
            for (int clip = 0; clip < 200 && itr != archetypeFilteredList.end(); clip++, ++itr) {
                static bool nameClicked, idClicked;
                IEntityArchetype* archetype = *itr;
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);

                nameClicked = ImGui::Selectable(archetype->GetName());
                if (ImGui::BeginPopupContextItem(NULL, ImGuiPopupFlags_MouseButtonLeft)) // <-- use last item id as popup id
                {
                    ImGui::Text("Display information about the archetype here");
                    if (ImGui::Button("Choose"))
                        archetypeToSpawn = archetype;
                    if (ImGui::Button("Close"))
                        ImGui::CloseCurrentPopup();
                    ImGui::EndPopup();
                }

                ImGui::TableSetColumnIndex(1);
                if (ImGui::Selectable(std::to_string(archetype->GetId()).c_str())) {
                    archetypeToSpawn = archetype;
                }
            }

            if (time(NULL) > statusTimer + 3)
                statusMessage = "";
            ImGui::EndTable();
        }
    }
    ImGui::End();
}

void ChairloaderGUIEntityManager::drawEntityList(bool* bShow) {
    if (ImGui::Begin("Entity List", bShow)) {
        {
            ImGui::BeginChild("left pane", ImVec2(250, 0), true, ImGuiWindowFlags_HorizontalScrollbar);
            ImGui::InputText("##input", &filterText);
            if (oldFilterText != filterText) {
                oldFilterText = filterText;
                refreshDisplayList = true;
            }
            ImGui::SameLine();
            if(ImGui::Button("Refresh")) {
                refreshDisplayList = true;
            }
            auto itr = entityDisplayList.begin();
            for (int i = 0; itr != entityDisplayList.end() && i < 500; i++, ++itr) {
                // FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
                std::string label;
                if ((*itr)->GetName() != nullptr) {
                    label = (*itr)->GetName();
                }
                else {
                    label = "invalid name";
                }
                // sprintf_s(label, "Entity: %d", i);
                if (ImGui::Selectable(label.c_str(), selected == (*itr)))
                    selected = (*itr);
            }
            ImGui::EndChild();
        }
        ImGui::SameLine();

        // Right
        {
            ImGui::BeginGroup();
            ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
            if (selected != nullptr) {
                ImGui::Text("Entity: %llu", selected->GetId());
            }
            else {
                ImGui::Text("Entity: %s", "Null");
            }
            ImGui::Separator();
            if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_FittingPolicyScroll | ImGuiTabBarFlags_TabListPopupButton))
            {
                if (ImGui::BeginTabItem("Entity Details"))
                {
                    // CryLog("at the entity check\n");

                    if (selected != nullptr) {
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
                            if (selected->GetName() != nullptr)
                                ImGui::Text("%s", selected->GetName());
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
                            ImGui::Text("%llu", selected->GetId());
                            // GUID
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            // CryLog("at guid\n");
                            ImGuiUtils::RightAlignText("GUID:");
                            ImGui::Text("GUID:");
                            ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                            ImGui::TableNextColumn();
                            ImGui::Text("%llu", selected->GetGuid());
                            // Class
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            // CryLog("at class\n");
                            ImGuiUtils::RightAlignText("Class:");
                            ImGui::Text("Class:");
                            ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                            ImGui::TableNextColumn();
                            if (selected->GetClass() != nullptr) {
                                if (selected->GetClass()->GetName() != nullptr)
                                    ImGui::Text("%s", selected->GetClass()->GetName());
                                else
                                    ImGui::Text("%s", "--Null Class--");
                            }
                            else {
                                ImGui::Text("%s", "--Null Class--");
                            }
                            ImGui::TableNextRow();
                            ImGui::TableNextColumn();
                            ImGuiUtils::RightAlignText("Archetype:");
                            ImGui::Text("Archetype:");
                            ImGui::SetCursorPosX(ImGui::GetColumnWidth());
                            ImGui::TableNextColumn();
                            if (selected->GetArchetype() != nullptr) {
                                if (selected->GetArchetype()->GetName() != nullptr)
                                    ImGui::Text("%s", selected->GetArchetype()->GetName());
                                else
                                    ImGui::Text("%s", "--Null Archetype--");
                            }
                            else {
                                ImGui::Text("%s", "--Null Archetype--");
                            }

                            ImGui::EndTable();
                        }
                        static float pos[3];
                        pos[0] = selected->GetPos().x;
                        pos[1] = selected->GetPos().y;
                        pos[2] = selected->GetPos().z;
                        static float newPos[3];
                        static float rot[4];
                        rot[0] = selected->GetRotation().v.x;
                        rot[1] = selected->GetRotation().v.y;
                        rot[2] = selected->GetRotation().v.z;
                        rot[2] = selected->GetRotation().w;
                        static float newRot[3];
                        static float scale[3]{ 1,1,1 };
                        scale[0] = selected->GetScale().x;
                        scale[1] = selected->GetScale().y;
                        scale[2] = selected->GetScale().z;
                        static float newScale[3];
                        // static float x, y, z, rx, rz, ry, rw = 1;
                        ImGui::Text("Position: ");
                        ImGui::InputFloat3("pos", pos, "%.1f", ImGuiInputTextFlags_ReadOnly);

                        ImGui::Text("Rotation: ");
                        ImGui::InputFloat4("rot", rot, "%.1f", ImGuiInputTextFlags_ReadOnly);

                        ImGui::Text("Scale: ");
                        ImGui::InputFloat3("scale", scale, "%.1f", ImGuiInputTextFlags_ReadOnly);
                        ImGui::NewLine();
                        ImGui::Button("Set Pos");
                        if (ImGui::BeginPopupContextItem(NULL, ImGuiPopupFlags_MouseButtonLeft)) {
                            static bool playerPos = false;
                            if (!playerPos)
                                ImGui::InputFloat3("pos", newPos, "%.2f");
                            ImGui::Checkbox("Set To Player Pos", &playerPos);
                            if (ImGui::Button("Set")) {
                                if (playerPos)
                                    modifyQueue.push(entityModifyRequest{ selected, entityModifyType::playerPos });

                                else
                                    modifyQueue.push(entityModifyRequest{ selected, entityModifyType::pos, Vec3_tpl<float>{newPos[0], newPos[1], newPos[2]} });
                            }
                            ImGui::EndPopup();
                        }

                        ImGui::SameLine();
                        ImGui::Button("Set Rot");
                        if (ImGui::BeginPopupContextItem(NULL, ImGuiPopupFlags_MouseButtonLeft)) {
                            ImGui::InputFloat4("rot", newRot, "%.2f");
                            ImGui::Button("Set");
                            ImGui::EndPopup();
                        }

                        ImGui::SameLine();
                        ImGui::Button("Set Scale");
                        if (ImGui::BeginPopupContextItem(NULL, ImGuiPopupFlags_MouseButtonLeft)) {
                            newScale[1] = newScale[0];
                            newScale[2] = newScale[0];
                            ImGui::InputFloat3("scale", newScale, "%.2f");
                            if (ImGui::Button("Set")) {
                                CryLog("%f", newScale[0]);
                                Vec3_tpl<float> scalar;
                                scalar.x = newScale[0];
                                scalar.y = newScale[0];
                                scalar.z = newScale[0];
                                modifyQueue.push(entityModifyRequest{ selected, entityModifyType::scale, {},{}, scalar });
                            }
                            ImGui::EndPopup();
                        }
                        // ImGui::Text("Rotation");

                        // ImGui::TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ");
                        // ImGui::Text("Pos:\nx:%f\ny:%f\nz:%f", 1.0f, 2.0f, 420.0f);
                    }
                    else {
                        ImGui::Text("No Entity Selected");
                    }
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("Status Effects"))
                {
                    static std::string selectedStatus;
                    // if(ImGui::BeginChild("status list", ImVec2(0, ImGui::GetContentRegionAvail().y * 0.6f))){
                    if (ImGui::BeginTable("statusList", 1, ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersOuter, ImVec2(0, ImGui::GetContentRegionAvail().y * 0.8f))) {
                        ImGui::TableSetupColumn("Status");
                        ImGui::TableHeadersRow();
                        for (auto itr = statusPush.begin(); itr != statusPush.end(); ++itr) {
                            ImGui::TableNextRow();
                            // if(ImGui::TreeNode((itr)->c_str())) {
                            // ImGui::Text("%s", itr->c_str());
                            ImGui::TableSetColumnIndex(0);
                            if (ImGui::Selectable(itr->c_str(), *itr == selectedStatus)) {
                                selectedStatus = *itr;
                            }
                        }
                        ImGui::EndTable();
                    }
                    ImGui::Text("%s", selectedStatus.c_str());
                    if (std::find(statusPush.begin(), statusPush.end(), selectedStatus) != statusPush.end()) {
                        ImGui::Button("Push");
                    }
                    if (std::find(statusPop.begin(), statusPop.end(), selectedStatus) != statusPop.end()) {
                        ImGui::SameLine();
                        ImGui::Button("Pop");
                    }
                    ImGui::EndTabItem();
                }
                // TODO: ALL OF THIS
                if (ImGui::BeginTabItem("Npc Details")) {
                    if (ImGui::BeginTable("SettableGettables", 2, ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersH | ImGuiTableFlags_BordersInnerV)) {
                        ImGui::TableSetupColumn("Readable", ImGuiTableColumnFlags_WidthFixed, ImGui::GetContentRegionAvail().x * 0.5f);
                        ImGui::TableSetupColumn("Writable", ImGuiTableColumnFlags_WidthFixed,
                            ImGui::GetContentRegionAvail().x * 0.5f);
                        ImGui::TableSetupScrollFreeze(0, 1);
                        ImGui::TableHeadersRow();
                        auto itrget = get.begin();
                        auto itrset = set.begin();
                        bool setend = false, getend = false;
                        while (itrset != set.end() || itrget != get.end()) {
                            ImGui::TableNextRow();
                            if (!getend) {
                                ++itrget;
                                if (itrget == get.end()) {
                                    getend = true;
                                }
                            }
                            if (!getend) {
                                ImGui::TableSetColumnIndex(0);
                                ImGui::Text("%s", itrget->c_str());
                                ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - 10.0f);
                                std::string text = "0";
                                ImGui::InputText("##NPC", &text, ImGuiInputTextFlags_ReadOnly);
                                ImGui::PopItemWidth();
                            }
                            else {

                            }
                            if (!setend) {
                                ++itrset;
                                if (itrset == set.end()) {
                                    setend = true;
                                }
                            }
                            if (!setend) {
                                ImGui::TableSetColumnIndex(1);
                                ImGui::Text("%s", itrset->c_str());
                                ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - ImGui::CalcTextSize(" Set   ").x);
                                std::string text = "0";
                                ImGui::InputText("", &text, ImGuiInputTextFlags_ReadOnly);
                                ImGui::SameLine();
                                ImGui::Button("Set");
                                ImGui::PopItemWidth();
                            }
                            else {

                            }
                        }
                        ImGui::EndTable();
                    }
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Npc Info")) {
                    if (ImGui::BeginTable("IsTable", 2, ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_BordersH | ImGuiTableFlags_ScrollY, ImGui::GetContentRegionAvail())) {
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
                if (ImGui::BeginTabItem("Actions:")) {

                    ImGui::EndTabItem();
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

void ChairloaderGUIEntityManager::drawMenuBar(bool* entityListShow, bool* entitySpawnerShow) {
    if (ImGui::BeginMenu("Entity")) {
        if (ImGui::BeginMenu("Spawn Entity")) {
            ImGui::MenuItem("Spawn Last Spawned", nullptr, false, archetypeToSpawn != nullptr);
            ImGui::Separator();
            ImGui::TextDisabled("Quick Spawns");
            if (ImGui::BeginMenu("Spawn Typhon")) {
                if (ImGui::BeginMenu("Mimics")) {
                    if (ImGui::MenuItem("Mimic"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Mimics.Mimic) });
                    if (ImGui::MenuItem("Greater Mimic"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Mimics.EliteMimic) });
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Phantoms")) {
                    if (ImGui::MenuItem("Normal"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Phantoms.BasePhantom) });
                    if (ImGui::MenuItem("Thermal"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Phantoms.ThermalPhantom) });
                    if (ImGui::MenuItem("Etheric"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Phantoms.EthericPhantom) });
                    if (ImGui::MenuItem("Voltaic"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Phantoms.VoltaicPhantom) });
                    ImGui::EndMenu();
                }
                if (ImGui::MenuItem("Nightmare"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.ArkNightmare) });
                if (ImGui::MenuItem("Poltergeist"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.ArkPoltergeist) });
                if (ImGui::MenuItem("Telepath"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Overseers.Telepath) });
                if (ImGui::MenuItem("Technopath"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkNpcs.Overseers.Technopath) });
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Spawn Operator")) {
                if (ImGui::MenuItem("Medical"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkRobots.Operators.Generic.MedicalOperator) });
                if (ImGui::MenuItem("Engineering"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkRobots.Operators.Generic.EngineeringOperator) });
                if (ImGui::MenuItem("Science"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkRobots.Operators.Generic.ScienceOperator) });
                if (ImGui::MenuItem("Military"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkRobots.Operators.Generic.MilitaryOperator) });
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Spawn Turrets")) {
                if (ImGui::MenuItem("Turret"))
                    archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkRobots.Turrets.Turret_Default) });
                ImGui::EndMenu();
            }
            ImGui::Separator();
            // ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 1,1,1,0.5f });
            // ImGui::TextWrapped("Item Spawning Not Stable, use at own risk");
            // ImGui::PopStyleColor();
            if (ImGui::BeginMenu("Spawn Items")) {
                if (ImGui::BeginMenu("Weapons")) {
                    if (ImGui::MenuItem("Wrench"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Weapons.Wrench) });
                    if (ImGui::MenuItem("Shotgun"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Weapons.Shotgun) });
                    if (ImGui::MenuItem("Shotgun Ammo"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Ammo.ShotgunShells) });
                    if (ImGui::MenuItem("Pistol"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Weapons.Pistol) });
                    if (ImGui::MenuItem("Pistol Ammo"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Ammo.PistolBullets) });
                    if (ImGui::MenuItem("Gloo Gun"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Weapons.GooGun) });
                    if (ImGui::MenuItem("Gloo Gun Ammo"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Ammo.GooGun) });
                    if (ImGui::MenuItem("Q Beam"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Weapons.Instalaser) });
                    if (ImGui::MenuItem("Q Beam Ammo"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Ammo.InstaLaser) });
                    if (ImGui::MenuItem("Stun Gun"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Weapons.StunGun) });
                    if (ImGui::MenuItem("Stun Gun Ammo"))
                        archetypeSpawnRequestQueue.push(spawnRequest{ gEnv->pEntitySystem->GetEntityArchetype(entityArchetypeLibrary.ArkPickups.Ammo.StunGunAmmo) });
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
            // if(ImGui::BeginMenu("Spawn Human")) {
            //     ImGui::MenuItem("Marco Simmons");
            //     ImGui::MenuItem("Igwe");
            //     ImGui::MenuItem("Mikhaila");
            //     ImGui::MenuItem("");
            //     ImGui::EndMenu();
            // }
            ImGui::EndMenu();
        }
        ImGui::Separator();
        if(ImGui::MenuItem("Toggle All")) {
            if(*entityListShow && *entitySpawnerShow) {
                *entityListShow = false;
                *entitySpawnerShow = false;
            }
            else {
                *entityListShow = true;
                *entitySpawnerShow = true;
            }
        }
        ImGui::MenuItem("Show Entity List", nullptr, entityListShow);
        ImGui::MenuItem("Show Entity Spawner", nullptr, entitySpawnerShow);
        ImGui::EndMenu();
    }
}

void ChairloaderGUIEntityManager::update(ChairloaderGUILog* log) {
    if (!gEnv->pSystem->IsPaused()) {

    }
    entityModifyHandler(log);
    archetypeFilterRequestHandler(log);
    filterEntityList(log);
}
void ChairloaderGUIEntityManager::entityModifyHandler(ChairloaderGUILog* log) {
    try {
        if (!modifyQueue.empty()) {
            entityModifyRequest request = modifyQueue.front();
            if (request.entity == nullptr) {
                CryLog("this shit's wack");
                modifyQueue.pop();
                return;
                // throw("Null Entity");
            }
            modifyQueue.pop();
            if (request.type == entityModifyType::pos) {
                if (request.pos.x != 0 && request.pos.y != 0 && request.pos.z != 0) {
                    ((IEntity*)request.entity)->SetPos(request.pos, 0, false, false);
                    log->logItem("set entity pos", modName);
                }
                else {
                    throw("Null Pos");
                }
            } if (request.type == entityModifyType::scale) {
                if (true) {
                    // if ((request.scale.x != 0 && request.scale.y != 0 && request.scale.z != 0) && (request.scale.x == request.scale.y && request.scale.y == request.scale.z)) {
                    CryLog("new scale = %f", request.scale.x);
                    ((IEntity*)request.entity)->SetScale(request.scale, 0);
                }
                else {
                    throw("Null Scale");
                }
            } if (request.type == entityModifyType::playerPos) {
                if (gEntUtils->ArkPlayerPtr() != nullptr) {
                    Vec3_tpl<float> pos;
                    pos = ArkPlayer::GetInstance().GetPlayerWorldEyePos();
                    ((IEntity*)request.entity)->SetPos(pos, 0, false, false);
                    log->logItem("set entity pos to player pos", modName);
                }
            }
        }
    }
    catch (std::string c) {
        std::string msg = "Error handling entity modification request: ";
        log->logItem(msg + c, modName, logLevel::error);
    }
}
void ChairloaderGUIEntityManager::filterEntityList(ChairloaderGUILog* log) {
    if (refreshDisplayList) {
        selected = nullptr;
        entityDisplayList.clear();
        int i = 0;

        IEntityItPtr pIt = gEnv->pEntitySystem->GetEntityIterator();
        pIt->MoveFirst();
        while (!pIt->IsEnd())
        {
            IEntity* pEntity = pIt->Next();
            std::string name = pEntity->GetName();
            std::string newFilterText = filterText;
            std::transform(newFilterText.begin(), newFilterText.end(), newFilterText.begin(), ::tolower);
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            if (name.find(newFilterText) != name.npos || filterText.empty()) {
                entityDisplayList.emplace_back(pEntity);
            }
        }

        refreshDisplayList = false;
    }
}
// void ChairloaderGUIEntityManager::archetypeSpawnRequestHandler(ChairloaderGUILog* log) {
//     if (!archetypeSpawnRequestQueue.empty() && !gEnv->pSystem->IsPaused()) {
//         try {
//
//             spawnRequest request = archetypeSpawnRequestQueue.front();
//             archetypeSpawnRequestQueue.pop();
//             std::string archetypeName = request.archetype->m_name.c_str();
//
//             // gEntUtils->entityArchetypeLibrary.
//             if (request.usePlayerPos) {
//                 Vec3_tpl<float> playerPos;
//                 ArkPlayer* player = gPreyFuncs->ArkPlayerF->getInstance();
//                 playerPos = player->GetEntity()->GetPos();
//                 // gPreyFuncs->ArkPlayerF->getPlayerWorldEyePos(player, &playerPos);
//                 if (player != nullptr) {
//                     // player->GetLocalEyePos(&playerPos);
//                     // CryLog("Player Position x: %f y: %f z:%f\n", playerPos.x, playerPos.y, playerPos.z);
//                     if (playerPos.x != 0 && playerPos.y != 0 && playerPos.z != 0) {
//                         if (request.offsetFromPlayer) {
//                             playerPos.x += gEntUtils->ArkPlayerPtr()->m_cachedReticleDir.x * 5;
//                             playerPos.y += gEntUtils->ArkPlayerPtr()->m_cachedReticleDir.y * 5;
//                         }
//                         request.pos = playerPos;
//                     }
//                     else {
//                         throw ("Error, null player position");
//                     }
//                 }
//                 else {
//                     throw("Error, null player pointer");
//                 }
//             }
//             if ((archetypeName.find("ArkRobots") != std::string::npos || archetypeName.find("ArkHumans") != std::string::npos || archetypeName.find("ArkNpcs") != std::string::npos) && archetypeName != "Turrets.Turret_Default") {
//                 if (request.spawnCount >= 1) {
//                     IEntity* spawnerEntity = gEntUtils->spawnerHelper.GetVictimSpawnerEntity(EntityUtils::EntityType::mimic);
//                     if (spawnerEntity != nullptr) {
//                         const char* oldArchetypeName = gEntUtils->spawnerHelper.SetEntityArchetype(request.archetype->m_id, spawnerEntity);
//                         if (oldArchetypeName != nullptr) {
//                             CArkNpcSpawner* spawner = gPreyFuncs->CEntity->getArkNpcSpawner((CEntity*)spawnerEntity);
//                             // gEntUtils->spawnerHelper.setEntityArchetype(request.archetype->m_id, spawner);
//                             spawner->m_Entity->m_worldTM.m03 = request.pos.x;
//                             spawner->m_Entity->m_worldTM.m13 = request.pos.y;
//                             spawner->m_Entity->m_worldTM.m23 = request.pos.z;
//
//                             gPreyFuncs->CArkNpcSpawnerF->requestSpawn(spawner);
//                             spawner->m_pendingSpawnCount = request.spawnCount;
//                             // while(spawner->m_lastSpawnedEntityId == oldId) {
//                             // 	// Sleep(1);
//                             // }// Sleep(50);
//                             // IEntity* newEntity = newEntity = GetEntitySystem()->GetEntity(spawner->m_lastSpawnedEntityId);
//                             // Sleep(5);
//                             // return newEntity;
//
//                             // IEntity* newEntity = gEntUtils->spawnerHelper.SpawnNpc(spawner, (char*)request.name.c_str());
//
//                             // CryLog("spawned an entity\n");
//                             // if (newEntity != nullptr) {
//                             //     newEntity->SetPos(&request.pos, 0, true, false);
//                             //     newEntity->SetName((char*)request.name.c_str());
//                             //     // CryLog("set position of an entity to x: %f y: %f z:%f\n", request.pos.x, request.pos.y, request.pos.z);
//                             // }
//                             // else {
//                             //     throw("Error, null entity spawned");
//                             // }
//                             // gEntUtils->spawnerHelper.setEntityArchetype(oldArchetypeName, spawnerEntity);
//                             log->logItem("Spawned entity", modName);
//                         }
//                         else {
//                             throw("Error, Old archetype Was null (single spawn)");
//                         }
//                     }
//                     else {
//                         throw("Error, spawner Entity Was null (single spawn)");
//                     }
//                 }
//                 // else {
//                 //     IEntity* spawnerEntity = gEntUtils->spawnerHelper.GetVictimSpawnerEntity(EntityUtils::EntityType::mimic);
//                 //     if (spawnerEntity != nullptr) {
//                 //         const char* oldArchetypeName = gEntUtils->spawnerHelper.SetEntityArchetype(request.archetype->m_id, spawnerEntity);
//                 //         if (oldArchetypeName != nullptr) {
//                 //             CArkNpcSpawner* spawner = gPreyFuncs->CEntity->getArkNpcSpawner((CEntity*)spawnerEntity);
//                 //             for (int i = 0; i < request.spawnCount; i++) {
//                 //                 IEntity* newEntity = gEntUtils->spawnerHelper.SpawnNpc(spawner, (char*)request.name.c_str());
//                 //                 if (newEntity != nullptr) {
//                 //                     newEntity->SetPos(request.pos, 0, true, false);
//                 //                     //                                 if(!request.name.empty())
//                 //                                                         // newEntity->SetName((char*)(request.name + std::to_string(i)).c_str());
//                 //                                                     // CryLog("set position of an entity to x: %f y: %f z:%f\n", request.pos.x, request.pos.y, request.pos.z);
//                 //                 }
//                 //                 else {
//                 //                     throw("Error, null entity spawned");
//                 //                 }
//                 //                 Sleep(10);
//                 //             }
//                 //             gEntUtils->spawnerHelper.SetEntityArchetype(oldArchetypeName, spawnerEntity);
//                 //             log->logItem("Spawned entity successfully", modName);
//                 //             // return logMessage{ , time(nullptr), logLevel::normal };
//                 //         }
//                 //         else {
//                 //             throw("Error, Old archetype Was null (single spawn)");
//                 //         }
//                 //     }
//                 //     else {
//                 //         throw("Error, spawner Entity Was null (single spawn)");
//                 //     }
//                 // }
//             }
//             else {
//                 log->logItem("Using non-npc spawning process", modName, ChairloaderGUILog::logLevel::warning);
//                 for (int i = 0; i < request.spawnCount; i++) {
//                     // CryLog("Using non-npc spawning process\n");
//                     SEntitySpawnParams* params = new SEntitySpawnParams;
//
//                     params->vScale.x = 1;
//                     params->vScale.y = 1;
//                     params->vScale.z = 1;
//                     uint32_t id = gPreyFuncs->CEntitySystemF->generateEntityId(GetEntitySystem(), true);
//                     params->id = id;
//                     params->vPosition.x = request.pos.x;
//                     params->vPosition.y = request.pos.y;
//                     params->vPosition.z = request.pos.z;
//                     params->qRotation.v.x = request.rot.x;
//                     params->qRotation.v.y = request.rot.y;
//                     params->qRotation.v.z = request.rot.z;
//                     params->qRotation.w = request.rot.w;
//                     params->sLayerName = "";
//                     params->pClass = nullptr;
//                     params->pArchetype = nullptr;
//                     params->guid = 0;
//                     params->prevGuid = 0;
//                     params->prevId = 0;
//                     params->bCreatedThroughPool = 0;
//                     params->bIgnoreLock = 0;
//                     params->bStaticEntityId = 0;
//                     params->nFlags = 0;
//                     params->nFlagsExtended = 0;
//                     params->sName = (char*)request.name.c_str();
//                     params->entityNode = nullptr;
//                     params->shadowCasterType = '\0';
//                     params->pUserData = (void*)0x0;
//                     params->sceneMask = '\0';
//                     IEntity* entity;
//
//                     // IEntityArchetype* archetype = (IEntityArchetype*)GetEntitySystem()->GetEntityArchetype();
//                     if (request.archetype != nullptr) {
//                         // log->logItem("Spawn count: " + std::to_string(request.spawnCount), modName.c_str());
//
//                         params->vPosition.x += 0.05f;
//                         // CryLog("Spawning\n");
//                         entity = GetEntitySystem()->SpawnEntityFromArchetype((IEntityArchetype*)request.archetype, *params, true);
//                         GUILog->logItem(std::to_string(((uintptr_t)entity->GetAI())), modName);
//                     }
//                     else {
//                         throw("Error, no archetype found\n");
//                     }
//                 }
//
//             }
//         }
//         catch (const char* c) {
//             log->logItem(c, modName, ChairloaderGUILog::logLevel::error);
//             // return {c, time(nullptr), logLevel::error}
//             // CryLog("%s\n", c);
//         }
//     }
// }
void ChairloaderGUIEntityManager::archetypeFilterRequestHandler(ChairloaderGUILog* log) {
    // FIXME: Find a proper way to get archetype list
    /*
    if (!archetypeFilterRequestQueue.empty()) {
        archetypeFilterRequest request = archetypeFilterRequestQueue.front();
        std::string filterText = request.text;
        std::map<const char*, CEntityArchetype*>* archetypeList = &GetEntitySystem()->m_pEntityArchetypeManager->m_nameToArchetypeMap;
        // static ImGuiTextFilter filter;
        auto itr = archetypeList->begin();
        archetypeFilteredList.clear();
        // if (filterText.size() < strlen(filter.InputBuf)) {
        // strcpy_s(filter.InputBuf, filterText.size(), filterText.c_str());
        // }
        for (int i = 0; i < 400 && itr != archetypeList->end(); ++itr) {
            std::string archetypeName = itr->first;
            // size_t last_period = archetypeName.find_last_of('.');
            // archetypeName = archetypeName.substr(last_period, archetypeName.size());
            std::transform(archetypeName.begin(), archetypeName.end(), archetypeName.begin(), ::tolower);
            std::transform(filterText.begin(), filterText.end(), filterText.begin(), ::tolower);
            if (archetypeName.find(filterText) != std::string::npos || filterText.empty()) {
                archetypeFilteredList.emplace_back(itr->second);
                i++;

            }
        }
        archetypeFilterRequestQueue.pop();
        // CryLog("processed: %s\n", filterText.c_str());
    }
    */
}


