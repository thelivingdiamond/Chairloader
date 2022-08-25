#include "GamePathDialog.h"
#include "ImGuiFileDialog/ImGuiFileDialog.h"
#include "PathUtils.h"

GamePathDialog::Result GamePathDialog::ShowDialog(const char* name, bool* pbIsOpen)
{
    ImGuiWindowFlags windowFlags =
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_AlwaysAutoResize;

    Result result = Result::None;

    if (ImGui::Begin(name, pbIsOpen, windowFlags))
    {
        //ImGui::Text(R"(Select path to the game. This is where "GameSDK" and "Engine" are.)");
        ImGui::Text(R"(Select path to Prey.exe.)");
        ImGui::PushItemWidth(500);
        if (ImGui::InputText("##path", m_PathInput, sizeof(m_PathInput), 0))
            ValidatePath();
        ImGui::PopItemWidth();
        ImGui::SameLine();

        if (ImGui::Button("Browse..."))
        {
            // Directory selection is broken
            //ImGuiFileDialog::Instance()->OpenDialog("GamePathDialog", "Choose File", nullptr, ".");
            ImGui::SetNextWindowSize({ 800, 500 });
            ImGuiFileDialog::Instance()->OpenDialog("GamePathDialog", "Choose File", ".exe", ".");
        }

        if (ImGuiFileDialog::Instance()->Display("GamePathDialog"))
        {
            // action if OK
            if (ImGuiFileDialog::Instance()->IsOk())
            {
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                snprintf(m_PathInput, sizeof(m_PathInput), "%s", filePathName.c_str());
                ValidatePath();
            }

            // close
            ImGuiFileDialog::Instance()->Close();
        }

        if (!m_ValidationError.empty())
            ImGui::TextColored(ImColor(255, 0, 0), "%s", m_ValidationError.c_str());

        ImGui::BeginDisabled(!m_IsValid);
        if (ImGui::Button("OK"))
            result = Result::Ok;
        ImGui::EndDisabled();
        ImGui::SameLine();
        if (ImGui::Button("Cancel"))
            result = Result::Cancel;
    }

    ImGui::End();
    return result;
}

void GamePathDialog::SetGamePath(const fs::path& path)
{
    std::string pathStr = path.u8string();
    snprintf(m_PathInput, sizeof(m_PathInput), "%s", pathStr.c_str());
    ValidatePath();
}

void GamePathDialog::ValidatePath()
{
    m_IsValid = false;
    m_ValidationError.clear();
    m_Path.clear();

    fs::path exePath = fs::u8path(m_PathInput);
    if (exePath.empty())
        return;

    m_IsValid = PathUtils::ValidateExePath(exePath, &m_ValidationError);

    if (m_IsValid)
        m_Path = PathUtils::ExePathToGamePath(exePath);
}
