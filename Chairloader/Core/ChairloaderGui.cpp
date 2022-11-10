#include <Prey/CryGame/IGameFramework.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ArkLocationManager.h>
#include <Prey/CrySystem/XConsole.h>
#include "ChairloaderGUI.h"
#include "ChairloaderCore.h"
#include "ChairloaderConfigManager.h"

ChairloaderGui::ChairloaderGui() {
    GUILog = &log;
    ImGui::GetStyle().Alpha = 0.8f;
    gCL->gui = this;
}


void ChairloaderGui::logItem(std::string msg, const std::string modName, logLevel level, bool displayToScreen) {
    log.logItem(msg, modName, level, displayToScreen);
}

void ChairloaderGui::logItem(logMessage message, bool displayToScreen) {
    log.logItem(message, displayToScreen);
}


void ChairloaderGui::draw() {
    if(m_bIsEnabled || persistentLogOverlay){
        log.drawDisplay();
    }
    if (m_bIsEnabled) {
        auto bgColor = ImGui::GetStyleColorVec4(ImGuiCol_PopupBg);
        bgColor.w = 1.0f;
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
        ImGui::PushStyleColor(ImGuiCol_PopupBg, bgColor);
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Chairloader")) {
                ImGui::MenuItem("Show GUI", ChairloaderCore::Get()->GetKeyStrHideGui().c_str(), &m_bIsEnabled);
                ImGui::MenuItem("  - Keep Overlay Log", nullptr, &persistentLogOverlay);
                //ImGui::MenuItem("Show Console", "~", &control.showDevConsole);
                ImGui::MenuItem("Show Config Menu", NULL, &control.showConfigMenu);
                ImGui::Separator();
                ImGui::MenuItem("Show Log History", nullptr, &control.showLogHistory);
                ImGui::Separator();
                if (ImGui::BeginMenu("Performance")) {
                    ImGui::MenuItem("Profiler", nullptr, &control.showProfilerDialog);
                    ImGui::Separator();
                    //perfOverlay.ShowMenu();
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("ImGui Test/Config")) {
                    ImGui::MenuItem("Show ImGui Demo", NULL, &control.showDemoWindow);
                    ImGui::MenuItem("Show Style Editor", NULL, &control.showStyleManager);
                    // ImGui::ShowStyleEditor();
                    if (ImGui::MenuItem("Test Log Message")) {
                        // std::string testMsg = "I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG";
                        std::string testMsg = "I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too!";
                        overlayLog(modName, "%s", testMsg.c_str());
                    }
                    if (ImGui::MenuItem("Test Error Message")) {
                        overlayError(modName, "Welcome to funland sonic");
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }
//            playerManager.drawMenuBar();
            ImGui::EndMainMenuBar();
        }
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();
        if (!control.hideAll) {
//            auto bgColor = ImGui::GetStyleColorVec4(ImGuiCol_PopupBg);
//            bgColor.w = 1.0f;
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
            ImGui::PushStyleColor(ImGuiCol_PopupBg, bgColor);
            if (ImGui::BeginMainMenuBar()) {
                    if (ImGui::BeginMenu("Console")) {
                        auto inDevMode = gEnv->pSystem->IsDevMode();
                        if (ImGui::Checkbox("Dev Mode", &inDevMode)) {
                            ((CSystem *) gEnv->pSystem)->SetDevMode(inDevMode);
                        }
                        ImGui::Separator();
                        if (ImGui::MenuItem("Enable Free Cam", ChairloaderCore::Get()->GetKeyStrToggleFreecam().c_str(),
                                            control.freeCam)) {
                            control.freeCam = !control.freeCam;
                            if (control.freeCam) {
                                control.devMode = true;
                                ((CSystem *) gEnv->pSystem)->SetDevMode(control.devMode);
                                gEnv->pConsole->ExecuteString("FreeCamEnable", true, false);
                            } else {
                                ((CSystem *) gEnv->pSystem)->SetDevMode(true);
                                gEnv->pConsole->ExecuteString("FreeCamDisable", true, false);
                                ((CSystem *) gEnv->pSystem)->SetDevMode(control.devMode);
                            }
                        }
                        if (control.freeCam) {
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
                        if (ImGui::MenuItem("Dump Commands to console")) {
                            auto xConsole = (CXConsole *) gEnv->pConsole;
                            for (auto &command: xConsole->m_mapCommands) {
                                CryLog("%s: %s", command.second.m_sName.c_str(), command.second.m_sHelp.c_str());
                            }
                        }
                        if (ImGui::MenuItem("Dump CVars to file")) {
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
            ImGui::PopStyleColor();
            ImGui::PopStyleVar();
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowBgAlpha(0.0);
            ImGui::SetNextWindowSize(ImGui::GetWindowViewport()->Size);
            ImGui::Begin("Main Dockspace Window", 0, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration);
            ImGui::DockSpace(ImGui::GetID("Main Dockspace"), ImVec2(0, 0), ImGuiDockNodeFlags_PassthruCentralNode | ImGuiDockNodeFlags_NoDockingInCentralNode);
            ImGui::End();
            if (control.showDemoWindow)
                ImGui::ShowDemoWindow(&control.showDemoWindow);
            if (control.showStyleManager)
                ImGui::ShowStyleEditor();
            if (control.showLogHistory)
                log.drawHistory(&control.showLogHistory);
            if (control.showProfilerDialog)
                profilerDialog.Show(&control.showProfilerDialog);
            if (control.showConfigMenu)
                ChairloaderCore::Get()->GetConfigManager()->Draw(&control.showConfigMenu);
//            log.drawDisplay();
        }
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
    //}
    
}

void ChairloaderGui::overlayLog(std::string modName, const char *format, ...) {
    char buffer[8192];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    log.logItem(buffer, modName);
    CryLog("%s", buffer);
}

void ChairloaderGui::overlaywarning(std::string modName, const char *format, ...) {
    char buffer[8192];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    log.logItem(buffer, modName, logLevel::warning);
    CryWarning("%s", buffer);
}

void ChairloaderGui::overlayError(std::string modName, const char *format, ...) {
    char buffer[8192];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    log.logItem(buffer, modName, logLevel::error);
    CryError("%s", buffer);
}

