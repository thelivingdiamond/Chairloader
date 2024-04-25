#include "OverlayLog.h"
#include "LogManager.h"


static OverlayLogManager s_OverlayLog;

OverlayLogManager::OverlayLogManager() {
}
OverlayLogManager::~OverlayLogManager() {
//    archiveLogQueue.clear();
//    displayLogQueue.clear();
}


// show persistent transparent log overlay
void OverlayLogManager::draw() {
    auto lastAlpha = ImGui::GetStyle().Alpha;
    if (LogManager::Get().GetOverlayMessageCount() > 0) {
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

        for(size_t idx = 0; idx < LogManager::Get().GetOverlayMessageCount(); idx++) {
            char message[1024];
            uint64_t messageTime;
            LogManager::Get().GetOverlayMessage(idx, message, sizeof(message), &messageTime);
            auto textSize = ImGui::CalcTextSize(message, nullptr, false, maxWindowSize.x + ImGui::GetStyle().WindowPadding.x * 2.0f);
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
        //  now go through in reverse order and draw the messages
        for (size_t idx = LogManager::Get().GetOverlayMessageCount(); idx > 0; idx--) {
            char message[1024];
            uint64_t messageTime;
            LogManager::Get().GetOverlayMessage(idx - 1, message, sizeof(message), &messageTime);
            bool entryDelete = false;
            auto currentMillis = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count();
            if (currentMillis >= messageTime + MessageTimeoutTime) {
                LogManager::Get().RemoveOverlayMessage(idx - 1);
                break;
            }
            else {
                if(currentMillis - messageTime > MessageTimeoutTime - 1000){
                    auto fadeTime = currentMillis - messageTime - (MessageTimeoutTime - 1000);
                    auto fadePercent = fadeTime / 1000.0f;
                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f - fadePercent);
                    ImGui::SetNextWindowBgAlpha(1.0f - fadePercent);
                } else {
                    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 1.0f);
                    ImGui::SetNextWindowBgAlpha(1.0f);
                }
                ImVec2 nextWindowSize(0,0);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 3.0f);
                auto textSize = ImGui::CalcTextSize(message, nullptr, false, maxWindowSize.x);
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
                    if (ImGui::Begin(("##" + std::string(message) + std::to_string(messageTime) + std::to_string(idx)).c_str(), nullptr, windowFlags)) {
//                        switch((*itr)->type){
//                            default:
//                            case(EChairLogType::Message):
//                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
//                                break;
//                            case(EChairLogType::Warning):
//                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 0.0f, 1.0f));
//                                break;
//                            case(EChairLogType::Error):
//                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
//                                break;
//                        }
                        ImGui::PushTextWrapPos(0.0f);
                        m_Parser.ProcessLine(message);
                        ImGui::PopTextWrapPos();
//                        ImGui::PopStyleColor();
                        if(ImGui::IsItemClicked(ImGuiMouseButton_Right)){
                            entryDelete = true;
                        }
                    }
                    ImGui::End();
                }
                ImGui::PopStyleVar(2);
                if(entryDelete){
                    LogManager::Get().RemoveOverlayMessage(idx - 1);
                    break;
                }
            }
        }
//        ImGui::PopClipRect();
    }
}

void OverlayLogManager::setMessageTimeoutInterval(float milliseconds) {
    MessageTimeoutTime = milliseconds;
}
// Draw the log history window to display all previous log messages
/*void OverlayLogManager::drawHistory(bool* bShow) {
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
void OverlayLogManager::logItem(std::string msg, const std::string modNameIn, logLevel level, bool displayToScreen) {
    logMessage message(msg, modNameIn, level);
    archiveLogQueue.emplace_back(message);
    if (displayToScreen)
        displayLogQueue.emplace_back(message);
}
// Log Item with a premade logMessage
void OverlayLogManager::logItem(logMessage message, bool displayToScreen) {
    if (!message.empty()) {
        archiveLogQueue.emplace_back(message);
        if (displayToScreen)
            displayLogQueue.emplace_back(message);
    }
}*/



/*
size_t OverlayLogManager::GetMessageCount() {
    return m_Messages.size();
}

void OverlayLogManager::GetMessage(size_t idx, char *buf, size_t bufSize) {
    cry_strcpy(buf, bufSize, m_Messages[idx].text.data(), m_Messages[idx].text.size());
}

OverlayLogManager &OverlayLogManager::Get() {
    return s_OverlayLog;
}

void OverlayLogManager::InitSystem() {
    if (m_MainThreadId != gEnv->mMainThreadId)
        CryFatalError("LogManager wasn't constructed on the main thread");
}

void OverlayLogManager::Update() {
    std::vector<Message> msgs = GetQueuedMessages();
    for (Message& msg : msgs)
    {
        Message& newMsg = GetNewMessage();
        newMsg = std::move(msg);
        // add to display queue
        m_MessagesDisplayQueue.emplace_back(&newMsg);
    }
}

void OverlayLogManager::AddMessage(const char *text, size_t size, EChairLogType type) {
    if (m_MainThreadId == CryGetCurrentThreadId())
    {
        // Add to the buffer
        Message& msg = GetNewMessage();
        msg.text = std::string(text, size);
        msg.type = type;
        msg.time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        m_MessagesDisplayQueue.emplace_back(&msg);
    }
    else
    {
        // Push to the queue
        Message msg;
        msg.text = std::string(text, size);
        msg.type = type;
        msg.time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::scoped_lock lock(m_ThreadQueueMutex);
        m_ThreadQueue.emplace_back(std::move(msg));
    }
}

OverlayLogManager::Message &OverlayLogManager::GetNewMessage() {
    if (m_Messages.size() < MAX_MSG_COUNT)
    {
        // Add new message
        m_MessagesEnd = (m_MessagesEnd + 1) % MAX_MSG_COUNT;
        return m_Messages.emplace_back();
    }
    else
    {
        size_t idx = m_MessagesEnd;
        m_MessagesEnd = (m_MessagesEnd + 1) % MAX_MSG_COUNT;
        return m_Messages[idx];
    }
}

std::vector<OverlayLogManager::Message> OverlayLogManager::GetQueuedMessages()
{
    std::vector<OverlayLogManager::Message> result;
    std::scoped_lock lock(m_ThreadQueueMutex);
    m_ThreadQueue.swap(result);
    return result;
}
*/

ImVec4 g_ConColors[] = {
        ImColor(0, 0, 0, 0),		// 0 Default
        ImColor(255, 255, 255, 255),// 1 White
        ImColor(64, 64, 255, 255),	// 2 Blue
        ImColor(64, 255, 64, 255),	// 3 Green
        ImColor(255, 64, 64, 255),	// 4 Red
        ImColor(0, 255, 255, 255),	// 5 Cyan
        ImColor(255, 255, 0, 255),	// 6 Yellow
        ImColor(255, 0, 255, 255),	// 7 Magenta
        ImColor(192, 64, 0, 255),	// 8 Brown
        ImColor(64, 64, 64, 255),	// 9 Grey
};


void OverlayLogManager::OverlayParser::PrintText(const char *text, size_t size, int colorIdx) {
    ImVec4 color = g_ConColors[colorIdx];
    if (color.w != 0) {
        ImGui::PushStyleColor(ImGuiCol_Text, color);
    }

    ImGui::TextUnformatted(text, text + size);
    ImGui::SameLine(0, 0);

    if (color.w != 0) {
        ImGui::PopStyleColor();
    }
}

void OverlayLogManager::OverlayParser::NewLine() {
    ImGui::NewLine();
}
