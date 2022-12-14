#include <Prey/CryGame/IGameFramework.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ArkLocationManager.h>
#include <Prey/CrySystem/XConsole.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderTools.h>
#include "ChairloaderGUI.h"
#include "ChairloaderCore.h"
#include "ChairloaderConfigManager.h"

ChairloaderGui::ChairloaderGui() {
    ImGui::GetStyle().Alpha = 0.8f;
    gCL->gui = this;
}


//void ChairloaderGui::logItem(std::string msg, const std::string modName, logLevel level, bool displayToScreen) {
//    log.logItem(msg, modName, level, displayToScreen);
//}
//
//void ChairloaderGui::logItem(logMessage message, bool displayToScreen) {
//    log.logItem(message, displayToScreen);
//}


void ChairloaderGui::draw() {
    if(m_bIsEnabled || persistentLogOverlay){
        overlayLogManager.draw();
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
                gChair->GetTools()->ShowMainMenuItems();
                ImGui::Separator();
                ImGui::MenuItem("Config Menu", NULL, &control.showConfigMenu);
//                ImGui::MenuItem("Show Log History", nullptr, &control.showLogHistory);
                ImGui::Separator();
                if (ImGui::BeginMenu("Performance")) {
                    ImGui::MenuItem("Profiler", nullptr, &control.showProfilerDialog);
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("GUI")) {
                    ImGui::MenuItem("Show Style Editor", NULL, &control.showStyleManager);
#ifdef DEBUG_BUILD
                    ImGui::MenuItem("Show ImGui Demo", NULL, &control.showDemoWindow);
                    if (ImGui::MenuItem("Test Log Message")) {
                        // std::string testMsg = "I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG";
                        std::string testMsg = "I've come to make an announcement: Shadow the Hedgehog's a bitch-ass motherfucker. He pissed on my fucking wife. That's right. He took his hedgehog fuckin' quilly dick out and he pissed on my FUCKING wife, and he said his dick was THIS BIG, and I said that's disgusting. So I'm making a callout post on my Twitter.com. Shadow the Hedgehog, you got a small dick. It's the size of this walnut except WAY smaller. And guess what? Here's what my dong looks like. That's right, baby. Tall points, no quills, no pillows, look at that, it looks like two balls and a bong. He fucked my wife, so guess what, I'm gonna fuck the earth. That's right, this is what you get! My SUPER LASER PISS! Except I'm not gonna piss on the earth. I'm gonna go higher. I'm pissing on the MOOOON! How do you like that, OBAMA? I PISSED ON THE MOON, YOU IDIOT! You have twenty-three hours before the piss DROPLETS hit the fucking earth, now get out of my fucking sight before I piss on you too!";
                        OverlayLog("{}", testMsg.c_str());
                    }
                    if (ImGui::MenuItem("Test Error Message")) {
                        OverlayError("Welcome to funland sonic");
                    }
#endif
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
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
            ImGui::PushStyleColor(ImGuiCol_PopupBg, bgColor);
            if (ImGui::BeginMainMenuBar()) {
                if (gEnv->pSystem->IsDevMode()) {
                    if (ImGui::BeginMenu("Console")) {
                        bool freeCam = ChairloaderCore::Get()->IsFreecamEnabled();
                        if (ImGui::MenuItem("Enable Free Cam", ChairloaderCore::Get()->GetKeyStrToggleFreecam().c_str(), freeCam)) {
                            ChairloaderCore::Get()->ToggleFreecam();
                        }

                        if (freeCam) {
                            ICVar* moveDetachedCamera = gEnv->pConsole->GetCVar("g_moveDetachedCamera");
                            if (ImGui::MenuItem("Freeze Free Cam", nullptr, moveDetachedCamera->GetIVal() == 0)) {
                                if (moveDetachedCamera->GetIVal() == 0) {
                                    moveDetachedCamera->Set(1);
                                }
                                else {
                                    moveDetachedCamera->Set(0);
                                }
                            }
                        }
                        if (ImGui::MenuItem("Dump Commands to console")) {
                            auto xConsole = (CXConsole *) gEnv->pConsole;
                            for (auto &command: xConsole->m_mapCommands) {
                                CryLog("{}: {}", command.second.m_sName, command.second.m_sHelp);
                            }
                        }
                        if (ImGui::MenuItem("Dump CVars to file")) {
                            gEnv->pConsole->DumpCVarsToFile("cvar_dump.txt");
                        }
                        ImGui::EndMenu();
                    }
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

//void ChairloaderGui::overlayLog(std::string modName, const char *format, ...) {
//    char buffer[8192];
//    va_list args;
//    va_start(args, format);
//    vsnprintf(buffer, sizeof(buffer), format, args);
//    va_end(args);
//    log.logItem(buffer, modName);
//    CryLog("{}", buffer);
//}
//
//void ChairloaderGui::overlaywarning(std::string modName, const char *format, ...) {
//    char buffer[8192];
//    va_list args;
//    va_start(args, format);
//    vsnprintf(buffer, sizeof(buffer), format, args);
//    va_end(args);
//    log.logItem(buffer, modName, logLevel::warning);
//    CryWarning("{}", buffer);
//}
//
//void ChairloaderGui::overlayError(std::string modName, const char *format, ...) {
//    char buffer[8192];
//    va_list args;
//    va_start(args, format);
//    vsnprintf(buffer, sizeof(buffer), format, args);
//    va_end(args);
//    log.logItem(buffer, modName, logLevel::error);
//    CryError("{}", buffer);
//}

