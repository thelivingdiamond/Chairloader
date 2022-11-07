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
    auto lastAlpha = ImGui::GetStyle().Alpha;
    if (!displayLogQueue.empty()) {
        // get screen X and Y
        auto screenX = ImGui::GetIO().DisplaySize.x;
        auto maxWindowSize = ImVec2(700, 150);
        auto firstWindowPos = ImVec2(screenX - maxWindowSize.x - 5.0f, 22.0f);
        float maxLogHeight = 450;
        float logSpacing = 10.0f;
//        ImGui::PushClipRect(firstWindowPos, ImVec2(firstWindowPos.x + maxWindowSize.x, firstWindowPos.y + maxLogHeight), false);
        auto windowFlags = ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoDecoration |
                ImGuiWindowFlags_NoNavFocus |
                ImGuiWindowFlags_NoResize |
//                ImGuiWindowFlags_NoBackground |
                ImGuiWindowFlags_NoNavInputs |
                ImGuiWindowFlags_NoDocking |
                ImGuiWindowFlags_NoBringToFrontOnFocus |
                ImGuiWindowFlags_NoFocusOnAppearing;
        float totalLogHeight = 0.0f;
        for(auto & logEntry : displayLogQueue){
            auto textSize = ImGui::CalcTextSize(logEntry.message.c_str(), nullptr, false, maxWindowSize.x + ImGui::GetStyle().WindowPadding.x * 2.0f);
            if(textSize.y >= maxWindowSize.y){
                textSize.y = maxWindowSize.y;
            } else {
                textSize.y += ImGui::GetStyle().WindowPadding.y * 2.0f;
            }
            totalLogHeight += textSize.y + logSpacing;
        }
        if(totalLogHeight > maxLogHeight){
            totalLogHeight = maxLogHeight;
        }
        ImVec2 nextWindowPos = firstWindowPos;
        nextWindowPos.y += totalLogHeight;
        for (auto itr = displayLogQueue.rbegin(); itr != displayLogQueue.rend(); ++itr) {
            bool entryDelete = false;
            auto currentMillis = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count();
            if (currentMillis >= itr->time + MessageTimeoutTime) {
                std::advance(itr, 1);
                displayLogQueue.erase(itr.base());
                break;
            }
            else {
                if(currentMillis - itr->time > MessageTimeoutTime - 1000){
                    auto fadeTime = currentMillis - itr->time - (MessageTimeoutTime - 1000);
                    auto fadePercent = fadeTime / 1000.0f;
                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f - fadePercent);
                    ImGui::SetNextWindowBgAlpha(1.0f - fadePercent);
                } else {
                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
                    ImGui::SetNextWindowBgAlpha(1.0f);
                }
                ImVec2 nextWindowSize(0,0);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 3.0f);
                auto textSize = ImGui::CalcTextSize(itr->message.c_str(), nullptr, false, maxWindowSize.x);
                nextWindowPos.x = firstWindowPos.x;
                ImVec2 windowPadding = ImGui::GetStyle().WindowPadding;
                windowPadding.x *= 2;
                windowPadding.y *= 2;

                if(textSize.y + windowPadding.y >= maxWindowSize.y){
                    nextWindowSize.y = maxWindowSize.y;
                } else {
                    nextWindowSize.y = textSize.y + windowPadding.y;
                }
                if(textSize.x >= maxWindowSize.x){
                    nextWindowSize.x = maxWindowSize.x + ImGui::GetStyle().WindowPadding.x * 2.0f + ImGui::GetStyle().FramePadding.x * 2.0f;
                } else {
                    nextWindowSize.x = textSize.x + ImGui::GetStyle().WindowPadding.x * 2.0f + ImGui::GetStyle().FramePadding.x * 2.0f;
                }
                nextWindowPos.y -= nextWindowSize.y + logSpacing;
                nextWindowPos.x += maxWindowSize.x - nextWindowSize.x;
                if(nextWindowPos.y > 0.0f - maxWindowSize.y) {
                    ImGui::SetNextWindowPos(nextWindowPos);
                    ImGui::SetNextWindowSize(nextWindowSize);
                    if (ImGui::Begin(("##" + itr->message + itr->modName + std::to_string(itr->time)).c_str(), nullptr,
                                     windowFlags)) {
                        switch(itr->level){
                            default:
                            case(logLevel::normal):
                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
                                break;
                            case(logLevel::warning):
                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 0.0f, 1.0f));
                                break;
                            case(logLevel::error):
                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
                                break;
                        }
                        ImGui::PushTextWrapPos(0.0f);
                        ImGui::Text("%s", itr->message.c_str());
                        ImGui::PopTextWrapPos();
                        ImGui::PopStyleColor();
                        if(ImGui::IsItemClicked(ImGuiMouseButton_Right)){
                            entryDelete = true;
                        }
                    }
                    ImGui::End();
                }
                ImGui::PopStyleVar(2);
                if(entryDelete){
                    std::advance(itr, 1);
                    displayLogQueue.erase(itr.base());
                    break;
                }
            }
        }
//        ImGui::PopClipRect();
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
                ImGui::TextWrapped("%s", itr->modName.c_str());
                ImGui::TableSetColumnIndex(1);
                ImGui::Bullet();
                ImGui::SameLine();
                if (itr->level == logLevel::normal) {
                    ImGui::TextWrapped("%s", itr->message.c_str());
                }
                else if (itr->level == logLevel::warning) {
                    ImGui::PushStyleColor(ImGuiCol_Text,ImColor{255, 190, 70}.operator ImVec4());
                    ImGui::TextWrapped("%s", itr->message.c_str());
                    ImGui::PopStyleColor();
                }
                else if (itr->level == logLevel::error) {
                    ImGui::PushStyleColor(ImGuiCol_Text, ImColor{255,70,70}.operator ImVec4());
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
    logMessage message(msg, modNameIn, level);
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