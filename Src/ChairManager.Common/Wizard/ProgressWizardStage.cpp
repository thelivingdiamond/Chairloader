#include <Wizard/ProgressWizardStage.h>

ProgressWizardStage::~ProgressWizardStage()
{
}

void ProgressWizardStage::OnActive()
{
    if (m_State == EState::NotStarted)
    {
        StartTask();
    }
}

void ProgressWizardStage::Task_UpdateProgressBar(float progress)
{
    auto lock = m_ProgressBar.GetScopedLock();
    m_ProgressBar.GetData() = progress;
}

void ProgressWizardStage::Task_UpdateProgressSubtext(std::string_view text)
{
    auto lock = m_ProgressSubtext.GetScopedLock();
    m_ProgressSubtext.GetData() = std::string(text);
}

void ProgressWizardStage::Task_LogMessage(std::string_view msg)
{
    auto lock = m_Log.GetScopedLock();
    m_Log.GetData().emplace_back(msg);
}

void ProgressWizardStage::Update()
{
    WizardStage::Update();

    if (m_State == EState::InProgress)
    {
        bool isReady = m_CheckFutureFunction();

        if (isReady)
        {
            try
            {
                OnTaskFinished();
                m_State = EState::Success;
            }
            catch (const std::exception& e)
            {
                m_State = EState::Error;
                m_ErrorText = e.what();
            }
        }
    }
}

void ProgressWizardStage::ShowContent()
{
    switch (m_State)
    {
    case EState::NotStarted:
    {
        ImGui::Text("Waiting for task to start...");
        break;
    }
    case EState::InProgress:
    case EState::Success:
    {
        if (m_State == EState::Success)
            ImGui::TextColored(ImColor(127, 255, 127), "Task has finished!");
        else
            ImGui::Text("Task is running...");

        {
            auto lock = m_ProgressBar.GetScopedLock();
            if (m_ProgressBar.GetData() >= 0.0f)
            {
                char buf[16];
                snprintf(buf, sizeof(buf), "%.0f%%", std::floor(m_ProgressBar.GetData() * 100));
                ImGui::ProgressBar(m_ProgressBar.GetData(), ImVec2(-FLT_MIN, 0), buf);
            }
        }

        {
            auto lock = m_ProgressSubtext.GetScopedLock();
            const std::string& text = m_ProgressSubtext.GetData();
            if (!text.empty())
            {
                ImGui::TextUnformatted(text.data(), text.data() + text.size());
            }
        }

        ImGui::Separator();
        ImGui::Text("Log:");

        if (ImGui::BeginChild("Scroll"))
        {
            ImGui::PushTextWrapPos(0.0f);
            ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
            auto lock = m_Log.GetScopedLock();

            for (const std::string& msg : m_Log.GetData())
            {
                ImGui::TextUnformatted(msg.data(), msg.data() + msg.size());
            }

            ImGui::PopStyleColor();
            ImGui::PopTextWrapPos();

            if (m_Log.GetData().size() != m_LastLogSize)
            {
                m_LastLogSize = m_Log.GetData().size();
                ImGui::SetScrollHereY(1.0f);
            }
        }

        ImGui::EndChild();
        break;
    }
    case EState::Error:
    {
        ImGui::TextColored(ImColor(255, 127, 127), "Task has failed!");
        ImGui::TextWrapped("%s", m_ErrorText.c_str());

        ImGui::Separator();
        ImGui::Text("Log:");

        ImGui::PushTextWrapPos(0.0f);
        ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled));
        auto lock = m_Log.GetScopedLock();

        for (const std::string& msg : m_Log.GetData())
        {
            ImGui::TextUnformatted(msg.data(), msg.data() + msg.size());
        }

        ImGui::PopStyleColor();
        ImGui::PopTextWrapPos();
    }
    }
}
