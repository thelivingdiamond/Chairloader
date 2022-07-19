#include "pch.h"
#include "OverlayLog.h"
#include "ChairLoader.h"

ChairloaderGUILog *GUILog = nullptr;


ChairloaderGUILog::ChairloaderGUILog() {
    // No construction needed
}
ChairloaderGUILog::~ChairloaderGUILog() {
    archiveLogQueue.clear();
    displayLogQueue.clear();
}
// show persistent transparent log overlay
void ChairloaderGUILog::drawDisplay() {
    if (!displayLogQueue.empty()) {
        ImGui::SetNextWindowPos(ImVec2(5.0f, 20.0f));
        ImGui::SetNextWindowSize(ImVec2(700, 150));
        if (ImGui::Begin("Log", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoDocking)) {
            float nextCursorPos = ImGui::GetContentRegionAvail().y;
            // std::vector::reverse_iterator
            for (auto itr = displayLogQueue.rbegin(); itr != displayLogQueue.rend(); ++itr) {

                if (time(nullptr) >= itr->time + MessageTimeoutTime) {
                    std::advance(itr, 1);
                    displayLogQueue.erase(itr.base());
                    break;
                }
                else {
                    nextCursorPos -= ImGui::CalcTextSize(itr->message.c_str(), nullptr, false, ImGui::GetContentRegionAvail().x).y;
                    ImGui::SetCursorPosY(nextCursorPos);
                    if (itr->level == logLevel::normal) {
                        ImGui::TextWrapped("%s", itr->message.c_str());
                    }
                    else if (itr->level == logLevel::warning) {
                        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 1,1,0,1 });
                        ImGui::TextWrapped("%s", itr->message.c_str());
                        ImGui::PopStyleColor();
                    }
                    else if (itr->level == logLevel::error) {
                        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 1,0,0,1 });
                        ImGui::TextWrapped("%s", itr->message.c_str());
                        ImGui::PopStyleColor();
                    }
                    // nextCursorPos -= ImGui::GetItemRectSize().y;
                    if (nextCursorPos < 0)
                        break;
                }
            }
            ImGui::End();
        }
    }
}
// Draw the log history window to display all previous log messages
void ChairloaderGUILog::drawHistory(bool* bShow) {
    if (ImGui::Begin("Log History", bShow, ImGuiWindowFlags_NoNavInputs)) {
        if (ImGui::BeginTable("Log Table", 2, ImGuiTableFlags_SizingFixedFit)) {
            ImGui::TableSetupColumn("Time");
            ImGui::TableSetupColumn("Message", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupScrollFreeze(0, 1);
            ImGui::TableHeadersRow();

            for (auto itr = archiveLogQueue.rbegin(); itr != archiveLogQueue.rend(); ++itr) {
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                ImGui::TextWrapped("%s", itr->modName);
                ImGui::TableSetColumnIndex(1);
                ImGui::Bullet();
                ImGui::SameLine();
                if (itr->level == logLevel::normal) {
                    ImGui::TextWrapped("%s", itr->message.c_str());
                }
                else if (itr->level == logLevel::warning) {
                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 1,1,0,1 });
                    ImGui::TextWrapped("%s", itr->message.c_str());
                    ImGui::PopStyleColor();
                }
                else if (itr->level == logLevel::error) {
                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 1,0,0,1 });
                    ImGui::TextWrapped("%s", itr->message.c_str());
                    ImGui::PopStyleColor();
                }
            }
            ImGui::EndTable();
        }
        ImGui::End();
    }
}
// Log Item with std::string, modName, Level, and screenWriting
void ChairloaderGUILog::logItem(std::string msg, const std::string modNameIn, logLevel level, bool displayToScreen) {
    logMessage message = { msg, modNameIn, time(nullptr), level };
    archiveLogQueue.emplace_back(message);
    if (displayToScreen)
        displayLogQueue.emplace_back(message);
}
// Log Item with a premade logMessage
void ChairloaderGUILog::logItem(logMessage message, bool displayToScreen) {
    if (!message.empty()) {
        archiveLogQueue.emplace_back(message);
        if (displayToScreen)
            displayLogQueue.emplace_back(message);
    }
}