#include <UI/ModManagerWindow.h>

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

void Assets::ModManagerWindow::LogString(severityLevel level, std::string_view str)
{
    EChairLogType type;

    switch (level)
    {
    case severityLevel::trace:
    case severityLevel::debug:
    case severityLevel::info:
        type = EChairLogType::Message;
        break;
    case severityLevel::warning:
        type = EChairLogType::Warning;
        break;
    case severityLevel::error:
    case severityLevel::fatal:
    default:
        type = EChairLogType::Error;
        break;
    }

    VCryLog(type, "{}", fmt::make_format_args(str));

    if (level == severityLevel::fatal)
        throw std::runtime_error(std::string(str));
}
