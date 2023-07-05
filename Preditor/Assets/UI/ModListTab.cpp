#include <Manager/IconsMaterialDesign.h>
#include <Manager/ModListConfig.h>
#include "UI/ModListTab.h"

Assets::ModListTab::ModListTab()
{
}

Assets::ModListTab::~ModListTab()
{
}

void Assets::ModListTab::Reset()
{
    // Save selected mod
    std::string selectedMod = m_SelectedItemIdx != -1 ? m_Items[m_SelectedItemIdx].info.modName : "";
    m_SelectedItemIdx = -1;

    LoadModList();
    LoadModConfig();

    // Restore selected mod
    for (int i = 0; i < m_Items.size(); i++)
    {
        if (m_Items[i].info.modName == selectedMod)
        {
            m_SelectedItemIdx = i;
            break;
        }
    }

    m_HasUnsavedChanges = false;
}

void Assets::ModListTab::ApplyChanges()
{
    try
    {
        fs::path chairConfigPath = gPreditor->pPaths->GetModsPath() / "config/Chairloader.xml";
        pugi::xml_document chairConfig;

        if (!chairConfig.load_file(chairConfigPath.c_str()))
            throw std::runtime_error("Failed to load Chairloader config");

        Manager::ModListConfig cfg;

        for (const ListItem& item : m_Items)
        {
            auto& cfgMod = cfg.AddMod(item.info, item.isEnabled);
            cfgMod.fullPath = item.fullPath;
        }

        // Save config
        cfg.SaveXml(chairConfig.first_child().child("ModList"));

        if (!chairConfig.save_file(chairConfigPath.c_str()))
            throw std::runtime_error("Failed to save Chairloader config");

        m_HasUnsavedChanges = false;
    }
    catch (const std::exception& e)
    {
        CryError("[ModListTab] {}", e.what());
    }

}

void Assets::ModListTab::ShowContents()
{
    if (ImGui::BeginChild("Mod List", ImVec2(ImGui::GetContentRegionAvail().x * 0.65f, 0)))
        ShowModList();

    ImGui::EndChild();
    ImGui::SameLine();

    if (ImGui::BeginChild("Mod Details"))
        ShowSelectedModDetails();

    ImGui::EndChild();
}

void Assets::ModListTab::LoadModList()
{
    const fs::path& modDir = gPreditor->pPaths->GetModsPath();
    m_Items.clear();

    for (const fs::directory_entry& entry : fs::directory_iterator(modDir))
    {
        if (!entry.is_directory())
            continue;

        fs::path modInfoPath = entry.path() / Manager::ModInfo::XML_FILE_NAME;

        if (!fs::exists(modInfoPath))
            continue;

        try
        {
            ListItem item;
            item.info.LoadFile(modInfoPath);
            item.isNameValid = Manager::ModInfo::ValidateModName(item.info.modName);

            m_Items.emplace_back(std::move(item));
        }
        catch (const std::exception& e)
        {
            CryError("[ModListTab] Failed to parse mod {}: {}", entry.path().filename().u8string(), e.what());
        }
    }

    // Add the project
    try
    {
        ListItem item;
        item.info.LoadFile(gPreditor->pPaths->GetProjectDirPath() / Manager::ModInfo::XML_FILE_NAME);
        item.isNameValid = Manager::ModInfo::ValidateModName(item.info.modName);
        item.isThisProject = true;
        item.isEnabled = true;

        m_Items.emplace_back(std::move(item));
    }
    catch (const std::exception& e)
    {
        CryError("[ModListTab] Failed add the mod for current project: {}", e.what());
    }
}

void Assets::ModListTab::LoadModConfig()
{
    fs::path chairConfigPath = gPreditor->pPaths->GetModsPath() / "config/Chairloader.xml";
    pugi::xml_document chairConfig;

    if (!chairConfig.load_file(chairConfigPath.c_str()))
    {
        CryError("[ModListTab] Failed to load Chairloader config.");
        return;
    }

    Manager::ModListConfig cfg;
    cfg.LoadXml(chairConfig.first_child().child("ModList"));

    for (int i = 0; i < cfg.mods.size(); i++)
    {
        for (ListItem& item : m_Items)
        {
            if (item.info.modName == cfg.mods[i].modName)
            {
                item.loadOrder = i;
                item.isEnabled = cfg.mods[i].enabled;

                // This project always has the path fixed
                if (!item.isThisProject)
                    item.fullPath = cfg.mods[i].fullPath;
            }
        }
    }

    std::sort(m_Items.begin(), m_Items.end(), [](const ListItem& lhs, const ListItem& rhs)
        {
            return lhs.loadOrder < rhs.loadOrder;
        });

    // Update load order
    for (int i = 0; i < m_Items.size(); i++)
    {
        m_Items[i].loadOrder = i;
    }
}

void Assets::ModListTab::ShowModList()
{
    int tableFlags =
        ImGuiTableFlags_Borders |
        ImGuiTableFlags_SizingStretchProp |
        ImGuiTableFlags_NoBordersInBody;

    float fontSize = ImGui::GetFontSize();

    if (ImGui::BeginTable("Mod List", 4, tableFlags))
    {
        ImGui::TableSetupColumn("##Enable/Disable", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("Mod Name");
        ImGui::TableSetupColumn("Version", ImGuiTableColumnFlags_WidthFixed,
            ImGui::CalcTextSize("Version").x + 16.0f);
        ImGui::TableSetupColumn("Order", ImGuiTableColumnFlags_WidthFixed,
            ImGui::CalcTextSize("Order").x + 16.0f);
        ImGui::TableHeadersRow();

        for (int listItemIdx = 0; listItemIdx < m_Items.size(); listItemIdx++)
        {
            ImGui::TableNextRow();

            ListItem& listItem = m_Items[listItemIdx];
            ImGui::PushID(listItemIdx);

            // Enable/disable checkbox
            {
                ImGui::TableNextColumn();
                ImGui::BeginDisabled(listItem.isThisProject);

                if (ImGui::Checkbox("##Enable", &listItem.isEnabled))
                    m_HasUnsavedChanges = true;

                ImGui::EndDisabled();
            }

            // Mod name selectable
            {
                ImGui::TableNextColumn();
                float storedpos = ImGui::GetCursorPosY() + 0.25f * fontSize;
                ImGui::SetCursorPosY(ImGui::GetCursorPosY() - (0.125f * fontSize));

                if (ImGui::Selectable("##Selectable",
                    listItemIdx == m_SelectedItemIdx, 0,
                    ImVec2{ ImGui::GetColumnWidth(), ImGui::GetFrameHeight() - 0.125f * fontSize }))
                {
                    // Select the mod
                    m_SelectedItemIdx = listItemIdx;
                }

                if (ImGui::IsItemHovered())
                {
                    if (listItem.isThisProject)
                    {
                        ImGui::BeginTooltip();
                        ImGui::Text("Current Preditor project");
                        ImGui::EndTooltip();
                    }
                    else
                    {
                        if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
                        {
                            // Toggle enabled on double-click
                            listItem.isEnabled ^= 1;
                            m_HasUnsavedChanges = true;
                        }
                    }
                }

                ImVec4 textColor;

                if (listItem.isThisProject)
                    textColor = ImVec4(0, 1, 0, 1);
                else if (listItem.isEnabled)
                    textColor = ImGui::GetStyleColorVec4(ImGuiCol_Text);
                else
                    textColor = ImGui::GetStyleColorVec4(ImGuiCol_TextDisabled);

                ImGui::SetCursorPosY(storedpos);
                ImGui::TextColored(textColor, "%s", listItem.info.displayName.c_str());
            }

            // Version
            ImGui::TableNextColumn();
            ImGui::Text("%s", listItem.info.version.c_str());

            // Load order
            ImGui::TableNextColumn();
            ImGui::Text("%i", listItem.loadOrder + 1);

            ImGui::PopID();
        }

        ImGui::EndTable();
    }
}

void Assets::ModListTab::ShowSelectedModDetails()
{
    if (ImGui::Button(ICON_MD_REFRESH))
        Reset();
    
    ImGui::Separator();
    
    if (m_SelectedItemIdx != -1)
    {
        assert(m_SelectedItemIdx >= 0 && m_SelectedItemIdx < m_Items.size());
        ListItem& mod = m_Items[m_SelectedItemIdx];

        const float footerHeight = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
        bool moveUp = false;
        bool moveDown = false;

        if (ImGui::BeginChild("ModInfo", ImVec2(0, -footerHeight)))
        {
            ImGui::PushTextWrapPos(0.0f);

            ImGui::Text("%s", mod.info.displayName.c_str());
            ImGui::Text("(%s)", mod.info.modName.c_str());
            ImGui::Text("By: %s", mod.info.author.c_str());
            ImGui::Text("Version: %s", mod.info.version.c_str());

            if (!mod.info.dllName.empty())
                ImGui::Text("DLL: %s", mod.info.dllName.c_str());

            if (mod.isThisProject)
                ImGui::TextColored(ImVec4(0, 1, 0, 1), "Current Preditor project");

            if (!mod.isNameValid)
                ImGui::TextColored(ImVec4(1, 0, 0, 1), "Mod name is invalid!");

            ImGui::PopTextWrapPos();
        }

        ImGui::EndChild();
        ImGui::Separator();

        bool isFirst = m_SelectedItemIdx == 0;
        bool isLast = m_SelectedItemIdx == m_Items.size() - 1;

        ImGui::BeginDisabled(isFirst);
        if (ImGui::Button(ICON_MD_ARROW_UPWARD))
            moveUp = true;
        ImGui::EndDisabled();
        ImGui::SameLine();

        ImGui::BeginDisabled(isLast);
        if (ImGui::Button(ICON_MD_ARROW_DOWNWARD))
            moveDown = true;
        ImGui::EndDisabled();
        ImGui::SameLine();

        // Move item after reading it - mod will point to the wrong item
        if (moveUp || moveDown)
        {
            int cur = m_SelectedItemIdx;
            int other = -1;

            if (moveUp)
                other = cur - 1;
            else if (moveDown)
                other = cur + 1;

            std::swap(m_Items[cur].loadOrder, m_Items[other].loadOrder);
            std::swap(m_Items[cur], m_Items[other]);
            m_SelectedItemIdx = other;
            m_HasUnsavedChanges = true;
        }
    }

}
