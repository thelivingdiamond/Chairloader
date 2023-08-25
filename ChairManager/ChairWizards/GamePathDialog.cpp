#include <Manager/GamePath.h>
#include <WinShell/WinShell.h>
#include "GamePathDialog.h"
#include "../ChairManager.h"


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
        result = ShowContents();
    }

    ImGui::End();
    return result;
}

GamePathDialog::Result GamePathDialog::ShowModal(const char* name)
{
    ImGuiWindowFlags windowFlags =
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_AlwaysAutoResize;

    Result result = Result::None;

    if (ImGui::BeginPopupModal(name, nullptr, windowFlags))
    {
        result = ShowContents();

        if (result == Result::Cancel)
            ImGui::CloseCurrentPopup();

        ImGui::EndPopup();
    }

    return result;
}

GamePathDialog::Result GamePathDialog::ShowContents()
{
    Result result = Result::None;
    //ImGui::Text(R"(Select path to the game. This is where "GameSDK" and "Engine" are.)");
    ImGui::Text(R"(Select path to Prey.exe.)");
    ImGui::PushItemWidth(500);
    if (ImGui::InputText("##path", m_PathInput, sizeof(m_PathInput), 0))
        ValidatePath();
    ImGui::PopItemWidth();
    ImGui::SameLine();

    if (ImGui::Button("Browse..."))
    {
        WinShell::DialogOptions opts;
        opts.title = "Choose the Prey Executable...";
        opts.fileTypes.push_back({ "Prey executable (Prey.exe)", "Prey.exe" });
        WinShell::ImShowFileOpenDialog("GamePathDialog", opts);
    }

    WinShell::DialogResult dialogResult;

    if (WinShell::ImUpdateFileOpenDialog("GamePathDialog", &dialogResult))
    {
        if (dialogResult.isOk)
        {
            std::string filePathName = dialogResult.filePath.u8string();
            snprintf(m_PathInput, sizeof(m_PathInput), "%s", filePathName.c_str());
            ValidatePath();
        }
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

    return result;
}

void GamePathDialog::SetGamePath(const fs::path& path)
{
    fs::path exePath = !path.empty() ? path / ChairManager::Get().GetGamePathUtil()->GetGameExePath() : path;
    exePath = exePath.lexically_normal();
    std::string pathStr = exePath.u8string();
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

    if (ChairManager::Get().GetGamePathUtil()->ValidateGamePath(exePath))
    {
        // Allow the input of game path instead of exe path
        m_IsValid = true;
        m_Path = exePath;
        return;
    }

    m_IsValid = ChairManager::Get().GetGamePathUtil()->ValidateExePath(exePath, &m_ValidationError);

    if (m_IsValid)
        m_Path = ChairManager::Get().GetGamePathUtil()->ExePathToGamePath(exePath);
}
