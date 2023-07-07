#include "UI/ModManagerWindow.h"
#include "CMAdapter.h"

Assets::ModManagerWindow::ModManagerWindow()
{
    SetTitle("Definitely Not ChairManager");
    SetPersistentID("ModManager");
    SetVisible(false);
    SetDestroyOnClose(false);

    m_pModConfigTab = std::make_unique<ModConfigTab>(static_cast<IChairManager*>(this));

    Reset();
}

Assets::ModManagerWindow::~ModManagerWindow()
{
}

void Assets::ModManagerWindow::Reset()
{
    m_ModListTab.Reset();
    m_pModConfigTab->Reset();
}

void Assets::ModManagerWindow::ApplyChanges()
{
    if (m_ModListTab.HasUnsavedChanges())
    {
        m_HadModChanges = true;
        m_ModListTab.ApplyChanges();
    }

    if (m_pModConfigTab->HasUnsavedChanges())
        m_pModConfigTab->ApplyChanges();
}

void Assets::ModManagerWindow::ShowContents()
{
    float bottomBarHeight = 0;
    bottomBarHeight += ImGui::GetStyle().ItemSpacing.y;
    bottomBarHeight += ImGui::GetFrameHeightWithSpacing();

    if (ImGui::BeginChild("Content", ImVec2(0, -bottomBarHeight)))
    {
        if (ImGui::BeginTabBar("##Mod Tab Bar"))
        {
            if (ImGui::BeginTabItem("Mod List"))
            {
                m_ModListTab.ShowContents();
                ImGui::EndTabItem();
            }

            // ConfigManager::draw creates its own tab
            m_pModConfigTab->ShowContents();

            ImGui::EndTabBar();
        }
    }
    
    ImGui::EndChild();
    ImGui::Separator();

    bool hasUnsavedChanges =
        m_ModListTab.HasUnsavedChanges() ||
        m_pModConfigTab->HasUnsavedChanges();

    ImGui::BeginDisabled(!hasUnsavedChanges);
    {
        if (ImGui::Button("Save config"))
            ApplyChanges();

        ImGui::SameLine();

        if (ImGui::Button("Revert"))
            Reset();

        ImGui::SameLine();
    }
    ImGui::EndDisabled();

    if (m_HadModChanges)
        ImGui::TextColored(ImVec4(1, 1, 0, 1), "Restart Preditor to apply mod list changes");
}

fs::path Assets::ModManagerWindow::GetConfigPath()
{
    return gPreditor->pPaths->GetModsPath() / "Config";
}

fs::path Assets::ModManagerWindow::GetModPath(const std::string& modName)
{
    return m_ModListTab.GetModPath(modName);
}

std::vector<std::string> Assets::ModManagerWindow::GetModNames()
{
    return m_ModListTab.GetModNames();
}

std::string Assets::ModManagerWindow::GetModDisplayName(const std::string& modName)
{
    return m_ModListTab.GetModDisplayName(modName);
}

bool Assets::ModManagerWindow::IsModEnabled(const std::string& modName)
{
    throw std::logic_error("IsModEnabled Not Implemented");
}

void Assets::ModManagerWindow::LogString(severityLevel level, std::string_view str)
{
    CMAdapter::LogString(level, str);
}
