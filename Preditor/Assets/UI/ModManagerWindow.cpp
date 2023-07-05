#include <UI/ModManagerWindow.h>

Assets::ModManagerWindow::ModManagerWindow()
{
    SetTitle("Definitely Not ChairManager");
    SetPersistentID("ModManager");
    SetVisible(false);
    SetDestroyOnClose(false);
    Reset();
}

Assets::ModManagerWindow::~ModManagerWindow()
{
}

void Assets::ModManagerWindow::Reset()
{
    m_ModListTab.Reset();
}

void Assets::ModManagerWindow::ApplyChanges()
{
    if (m_ModListTab.HasUnsavedChanges())
    {
        m_HadModChanges = true;
        m_ModListTab.ApplyChanges();
    }
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

            if (ImGui::BeginTabItem("Mod Config"))
            {
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }
    }
    
    ImGui::EndChild();
    ImGui::Separator();

    bool hasUnsavedChanges = m_ModListTab.HasUnsavedChanges();

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
