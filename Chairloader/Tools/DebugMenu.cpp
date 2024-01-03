#include <Prey/CryGame/IGameFramework.h>
#include <Chairloader/IChairXmlUtils.h>
#include "DebugMenu.h"

class DebugMenu::Attribute
{
public:
    Attribute(const pugi::xml_node& attribute)
    {
        m_Label = attribute.attribute("label").as_string();
        m_SetOnChange = attribute.attribute("setOnChange").as_string();

        if (m_Label.empty())
            CryWarning("{}: Attribute has no label", XML_PATH);

        std::string_view action = attribute.attribute("action").as_string();
        if (!action.empty())
            m_SubActions.emplace_back(action);

        for (pugi::xml_node child : attribute)
        {
            if (!strcmp(child.name(), "list"))
            {
                for (pugi::xml_node listChild : child)
                {
                    if (!strcmp(listChild.name(), "option"))
                    {
                        Option& option = m_Options.emplace_back();
                        option.label = listChild.attribute("label").as_string();
                        option.value = listChild.attribute("value").as_string();
                        ReadSubActions(listChild.child("subactions"), option.subActions);
                    }
                    else
                    {
                        CryError("{}:{} unknown element {} in option list", XML_PATH, m_Label, listChild.name());
                        continue;
                    }
                }
            }
            else if (!strcmp(child.name(), "subactions"))
            {
                ReadSubActions(child, m_SubActions);
            }
            else
            {
                CryError("{}:{} unknown element {} in attribute", XML_PATH, m_Label, child.name());
                continue;
            }
        }
    }

    void ShowMenu()
    {
        if (!m_Options.empty())
        {
            // Command with variable arguments
            if (ImGui::BeginMenu(m_Label.c_str()))
            {
                for (int i = 0; i < m_Options.size(); i++)
                {
                    ImGui::PushID(i);
                    Option& option = m_Options[i];

                    if (ImGui::MenuItem(option.label.c_str()))
                    {
                        if (!option.subActions.empty())
                            ExecuteCommand(option.subActions, option.value);
                        else
                            ExecuteCommand(m_SubActions, option.value);
                    }

                    ImGui::PopID();
                }

                ImGui::EndMenu();
            }
        }
        else if (!m_SubActions.empty())
        {
            // A single command
            if (ImGui::MenuItem(m_Label.c_str()))
            {
                ExecuteCommand(m_SubActions, "");
            }
        }
        else
        {
            // Just a header
            ImGui::TextDisabled("%s", m_Label.c_str());
        }
    }

private:
    struct Option
    {
        std::string label;
        std::string value;
        std::vector<std::string> subActions;
    };

    std::string m_Label;
    bool m_SetOnChange = false;
    std::vector<std::string> m_SubActions;
    std::vector<Option> m_Options;

    static void ExecuteCommand(const std::vector<std::string>& subActions, std::string_view arg)
    {
        for (const std::string& i : subActions)
        {
            std::string cmd = fmt::format("{} {}", i, arg);
            gEnv->pConsole->ExecuteString(cmd.c_str(), false, true);
        }
    }

    static void ReadSubActions(const pugi::xml_node& child, std::vector<std::string>& out)
    {
        for (pugi::xml_node subAction : child)
        {
            std::string_view action = subAction.attribute("action").as_string();
            if (!action.empty())
                out.emplace_back(action);
        }
    }
};

class DebugMenu::Page
{
public:
    Page(const pugi::xml_node& page)
    {
        m_Label = page.attribute("label").as_string();

        if (m_Label.empty())
            CryWarning("{}: Page has no label", XML_PATH);

        for (pugi::xml_node child : page)
        {
            if (!strcmp(child.name(), "attribute"))
            {
                m_Attributes.emplace_back(child);
            }
            else
            {
                CryError("{}:{} unknown element {} in page", XML_PATH, m_Label, child.name());
                continue;
            }
        }
    }

    void ShowMenu()
    {
        if (ImGui::BeginMenu(m_Label.c_str()))
        {
            for (int i = 0; i < m_Attributes.size(); i++)
            {
                ImGui::PushID(i);
                m_Attributes[i].ShowMenu();
                ImGui::PopID();
            }

            ImGui::EndMenu();
        }
    }

private:
    std::string m_Label;
    std::vector<Attribute> m_Attributes;
};

DebugMenu::DebugMenu()
{
    ReloadMenu();
}

DebugMenu::~DebugMenu()
{
}

void DebugMenu::ReloadMenu()
{
    m_Pages.clear();

    try
    {
        pugi::xml_parse_result parseResult;
        pugi::xml_document doc = gCL->pXmlUtils->LoadXmlFromFile(XML_PATH, &parseResult);

        if (!parseResult)
            throw std::runtime_error(fmt::format("{}:{}: {}", XML_PATH, parseResult.offset, parseResult.description()));

        for (pugi::xml_node child : doc.first_child().child("pages"))
        {
            if (!strcmp(child.name(), "page"))
            {
                m_Pages.emplace_back(child);
            }
            else
            {
                CryError("{}: unknown element {}", XML_PATH, child.name());
                continue;
            }
        }
    }
    catch (const std::exception& e)
    {
        CryError("Failed to load debug menu: {}", e.what());
    }
}

void DebugMenu::ShowMenu()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Debug Menu"))
        {
            for (int i = 0; i < m_Pages.size(); i++)
            {
                ImGui::PushID(i);
                m_Pages[i].ShowMenu();
                ImGui::PopID();
            }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}
