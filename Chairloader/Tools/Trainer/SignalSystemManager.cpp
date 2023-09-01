//
// Created by theli on 8/16/2023.
//

#include "SignalSystemManager.h"
#include "Prey/GameDll/ark/signalsystem/arksignalmanager.h"
#include "Prey/GameDll/ark/ArkGame.h"

SignalSystemManager::SignalSystemManager() {

}

void SignalSystemManager::Update() {

}

void SignalSystemManager::Draw() {
    // draw menu
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Trainer")) {
            if (ImGui::BeginMenu("Signals")) {
                ImGui::MenuItem("Signal System Manager", nullptr, &m_bShowWindow);
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if(m_bShowWindow){
        if(ImGui::Begin("Signal System Manager", &m_bShowWindow)){
            auto pArkGame = ArkGame::GetArkGame();
            if(pArkGame != nullptr){
                auto pArkSignalManager = pArkGame->GetArkSignalManager();
                ImGui::Text("Signal System Manager: %p", &pArkSignalManager);
                if(ImGui::BeginTabBar("Signal System Tabs")){
                    if(ImGui::BeginTabItem("Packages")){
                        if(ImGui::BeginTable("Packages Table", 3)){
                            // three columns, id, name, and number of signals
                            ImGui::TableSetupColumn("ID");
                            ImGui::TableSetupColumn("Name");
                            ImGui::TableSetupColumn("Signals");
                            ImGui::TableHeadersRow();
                            // loop through all packages
                            for(auto pPackage : pArkSignalManager.m_data.m_packages){
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                ImGui::Text("%llu", pPackage.m_id);
                                ImGui::TableNextColumn();
                                ImGui::Text("%s", pPackage.m_name.c_str());
                                ImGui::TableNextColumn();
                                ImGui::Text("%zu", pPackage.m_values.size());
                            }
                            ImGui::EndTable();
                        }
                        ImGui::EndTabItem();
                    }

                    // signals tab
                    if(ImGui::BeginTabItem("Signals")){
                        if(ImGui::BeginTable("Signals Table", 2)){
                            // four columns, id, name, package, and type
                            ImGui::TableSetupColumn("ID");
                            ImGui::TableSetupColumn("Name");
                            ImGui::TableHeadersRow();
                            // loop through all signals
                            for(auto pSignal : pArkSignalManager.m_data.m_signals){
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                ImGui::Text("%llu", pSignal.m_id);
                                ImGui::TableNextColumn();
                                ImGui::Text("%s", pSignal.m_name.c_str());
                            }
                            ImGui::EndTable();
                        }
                        ImGui::EndTabItem();
                    }

                    // modifiers tab
                    if(ImGui::BeginTabItem("Modifiers")){
                        if(ImGui::BeginTable("Modifiers Table", 2)){
                            // four columns, id, name, package, and type
                            ImGui::TableSetupColumn("ID");
                            ImGui::TableSetupColumn("Name");
                            ImGui::TableHeadersRow();
                            // loop through all modifiers
                            for(auto pModifier : pArkSignalManager.m_data.m_modifiers){
                                ImGui::TableNextRow();
                                ImGui::TableNextColumn();
                                ImGui::Text("%llu", pModifier.m_id);
                                ImGui::TableNextColumn();
                                ImGui::Text("%s", pModifier.m_name.c_str());
                            }
                            ImGui::EndTable();
                        }
                        ImGui::EndTabItem();
                    }
                    ImGui::EndTabBar();
                }
            }
        }
        ImGui::End();
    }
}
