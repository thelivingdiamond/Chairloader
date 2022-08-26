#include "ChairloaderGUI.h"
#include "Prey/CryGame/IGameFramework.h"
#include "Prey/GameDll/ark/ArkGame.h"
#include "Prey/GameDll/ark/ArkLocationManager.h"
ChairloaderGui *gui = nullptr;

ChairloaderGui::ChairloaderGui(ChairloaderGlobalEnvironment* env) :
    playerManager(env),
    entityManager(env),
    worldManager(env){
    gCLEnv = env;
    GUILog = &log;
}


void ChairloaderGui::logItem(std::string msg, const std::string modName, logLevel level, bool displayToScreen) {
    log.logItem(msg, modName, level, displayToScreen);
}

void ChairloaderGui::logItem(logMessage message, bool displayToScreen) {
    log.logItem(message, displayToScreen);
}

void ChairloaderGui::draw(bool* bShow) {
    if (*bShow) {
        drawHandleMutex.lock();
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Chairloader")) {
                ImGui::MenuItem("Hide All", NULL, &control.hideAll);
                ImGui::MenuItem("Show Console", "~", &control.showDevConsole);
                ImGui::MenuItem("Show Config Menu", NULL, &control.showConfigMenu);
                ImGui::Separator();
                ImGui::MenuItem("Show Log History", nullptr, &control.showLogHistory);
                ImGui::Separator();
                if (ImGui::BeginMenu("Performance")) {
                    ImGui::MenuItem("Profiler", nullptr, &control.showProfilerDialog);
                    ImGui::Separator();
                    perfOverlay.ShowMenu();
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("ImGui Test/Config")) {
                    ImGui::MenuItem("Show ImGui Demo", NULL, &control.showDemoWindow);
                    ImGui::MenuItem("Show Style Editor", NULL, &control.showStyleManager);
                    // ImGui::ShowStyleEditor();
                    if (ImGui::MenuItem("Test Log Message")) {
                        // std::string testMsg = "I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG";
                        std::string testMsg = "I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too! ";
                        log.logItem(testMsg, modName);
                    }
                    if (ImGui::MenuItem("Test Error Message")) {
                        log.logItem("Welcome to funland sonic", modName, logLevel::error);
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
//            playerManager.drawMenuBar();
            ImGui::EndMainMenuBar();
        }
        if (!control.hideAll) {
            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("Console")) {
                    auto inDevMode = gEnv->pSystem->IsDevMode();
                    if(ImGui::Checkbox("Dev Mode", &inDevMode)){
                        ((CSystem*)gEnv->pSystem)->SetDevMode(inDevMode);
                    }
                    ImGui::Separator();
                    if(ImGui::MenuItem("Enable Free Cam", nullptr, control.freeCam)){
                        control.freeCam = !control.freeCam;
                        if (control.freeCam) {
                            control.devMode = true;
                            ((CSystem*)gEnv->pSystem)->SetDevMode(control.devMode);
                            gEnv->pConsole->ExecuteString("FreeCamEnable", true, false);
                        }
                        else {
                            ((CSystem*)gEnv->pSystem)->SetDevMode(true);
                            gEnv->pConsole->ExecuteString("FreeCamDisable", true, false);
                            ((CSystem*)gEnv->pSystem)->SetDevMode(control.devMode);
                        }
                    }
                    if(control.freeCam) {
                        if (ImGui::MenuItem("Freeze Free Cam", nullptr,
                                            gEnv->pConsole->GetCVar("g_moveDetachedCamera")->GetIVal() == 0)) {
                            auto moveDetachedCamera = gEnv->pConsole->GetCVar("g_moveDetachedCamera");
                            if (moveDetachedCamera->GetIVal() == 0) {
                                moveDetachedCamera->Set(1);
                            } else {
                                moveDetachedCamera->Set(0);
                            }
                        }
                    }
                    ImGui::Separator();
                    if(ImGui::MenuItem("Dump CVars to file")){
                        gEnv->pConsole->DumpCVarsToFile("cvar_dump.txt");
                    }
//                    if (ImGui::Button("Toggle Free Cam")) {
//
//                    }
                    ImGui::EndMenu();
                    // }
                }
                ImGui::EndMainMenuBar();
            }
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowBgAlpha(0.0);
            ImGui::SetNextWindowSize(ImGui::GetWindowViewport()->Size);
            ImGui::Begin("Main Dockspace Window", 0, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration);
            ImGui::DockSpace(ImGui::GetID("Main Dockspace"), ImVec2(0, 0), ImGuiDockNodeFlags_PassthruCentralNode | ImGuiDockNodeFlags_NoDockingInCentralNode);
            ImGui::End();
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.8f);
            if (control.showDemoWindow)
                ImGui::ShowDemoWindow(&control.showDemoWindow);
            if (control.showStyleManager)
                ImGui::ShowStyleEditor();
            if (control.showLogHistory)
                log.drawHistory(&control.showLogHistory);
            log.drawDisplay();
            entityManager.Draw();
            playerManager.draw();
            worldManager.Draw();
            if (control.showProfilerDialog) {
                profilerDialog.Show(&control.showProfilerDialog);
            }

            if (control.showDevConsole) {
                devConsoleDialog.Show(&control.showDevConsole);
            }
            if (control.showConfigMenu)
                gConf->Draw(&control.showConfigMenu);
            log.drawDisplay();
            ImGui::PopStyleVar();
        }
        drawHandleMutex.unlock();
    }
    auto drawList = ImGui::GetBackgroundDrawList();
    auto screenSize = ImGui::GetIO().DisplaySize;
    auto color =  ImColor(ImGui::GetColorU32(ImGuiCol_Border)).operator ImVec4();
    color.w = 0.5f;
    drawList->AddLine(ImVec2(0, screenSize.y-1.0f), ImVec2(screenSize.x, screenSize.y - 1.0f), ImColor(color).operator ImU32(),1.0f);
}

void ChairloaderGui::update() {
    // FIXME: Add IGameFramework
    //auto pAction = reinterpret_cast<CCryAction*>(gCL->GetFramework());
    //if (!pAction->IsInLevelLoad() || !pAction->IsLoadingSaveGame()) {
    drawHandleMutex.lock();
    entityManager.Update();
    playerManager.update();
    worldManager.Update();
    drawHandleMutex.unlock();
    //}
    perfOverlay.Update();
    
}

