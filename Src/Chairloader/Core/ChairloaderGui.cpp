#include <Prey/CryGame/IGameFramework.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ArkLocationManager.h>
#include <Prey/CrySystem/XConsole.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderTools.h>
#include "ChairloaderGui.h"
#include "ChairloaderCore.h"
#include "ChairloaderConfigManager.h"
#include "LogManager.h"
#include "DependencyInjection/ServiceLocator.h"

ChairloaderGui::ChairloaderGui(std::shared_ptr<LogManager> logManager)
    : m_pLogManager(logManager)
    , overlayLogManager(logManager)
{
}


//void ChairloaderGui::logItem(std::string msg, const std::string modName, logLevel level, bool displayToScreen) {
//    log.logItem(msg, modName, level, displayToScreen);
//}
//
//void ChairloaderGui::logItem(logMessage message, bool displayToScreen) {
//    log.logItem(message, displayToScreen);
//}


void ChairloaderGui::InitGame() {
    ImGui::GetStyle().Alpha = 0.8f;
    gCL->gui = this;

    m_pCore = std::static_pointer_cast<ChairloaderCore>(ServiceLocator::GetRequiredService<Internal::IChairloaderCore>());
    auto pLogManager = ServiceLocator::GetRequiredService<LogManager>();
    std::string hideGuiKey = m_pCore->GetKeyStrHideGui();
    std::string logMsg;

    if (gEnv->pSystem->IsDevMode())
    {
        // Enable GUI for developers
        m_bIsEnabled = true;
        logMsg = fmt::format(
            "Chairloader Developer Mode is enabled. "
            "Press {} to hide the menu. "
            "Press ~ to open the console", hideGuiKey);
    }
    else
    {
        // Most players don't need to use the GUI very often, hide it
        m_bIsEnabled = false;
        logMsg = fmt::format("Chairloader is active. Press {} to open the menu", hideGuiKey);
    }

    pLogManager->AddMessage(logMsg.data(), logMsg.size(), true);
}

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
                ImGui::MenuItem("Show GUI", m_pCore->GetKeyStrHideGui().c_str(), &m_bIsEnabled);
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

        // Display dock space after the menu
        ShowDockSpace();

        if (!control.hideAll) {
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
            ImGui::PushStyleColor(ImGuiCol_PopupBg, bgColor);
            if (ImGui::BeginMainMenuBar()) {
                if (gEnv->pSystem->IsDevMode()) {
                    if (ImGui::BeginMenu("Console")) {
                        bool freeCam = m_pCore->IsFreecamEnabled();
                        if (ImGui::MenuItem("Enable Free Cam", m_pCore->GetKeyStrToggleFreecam().c_str(), freeCam)) {
                            m_pCore->ToggleFreecam();
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

            if (control.showDemoWindow)
                ImGui::ShowDemoWindow(&control.showDemoWindow);
            if (control.showStyleManager)
                ImGui::ShowStyleEditor();
            if (control.showProfilerDialog)
                profilerDialog.Show(&control.showProfilerDialog);
            if (control.showConfigMenu)
                std::static_pointer_cast<ChairloaderConfigManager>(ServiceLocator::GetRequiredService<IChairloaderConfigManager>())->Draw(&control.showConfigMenu);
//            log.drawDisplay();
        }
    }
    else
    {
        // Keep dock space alive even when GUI is hidden
        ShowDockSpace();
    }
    auto drawList = ImGui::GetBackgroundDrawList();
    auto screenSize = ImGui::GetIO().DisplaySize;
    drawList->AddLine(ImVec2(0, screenSize.y-1.0f), ImVec2(screenSize.x, screenSize.y - 1.0f), ImColor(0, 0, 0, 255).operator ImU32(),1.0f);
}

void ChairloaderGui::update() {
    // FIXME: Add IGameFramework
    //auto pAction = reinterpret_cast<CCryAction*>(gCL->GetFramework());
    //if (!pAction->IsInLevelLoad() || !pAction->IsLoadingSaveGame()) {
    //}
}

void ChairloaderGui::ShowDockSpace()
{
    ImGui::SetNextWindowBgAlpha(0.0f);
    ImGui::DockSpaceOverViewport(nullptr, ImGuiDockNodeFlags_PassthruCentralNode);
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

