#pragma once

class DebugMenu : NoCopy
{
public:
    DebugMenu();
    ~DebugMenu();

    //! Reloads the menu from file.
    void ReloadMenu();

    //! Shows the ImGui menu.
    void ShowMenu();

private:
    //! Path to the debug menu file.
    static constexpr char XML_PATH[] = "Libs/Config/gameDebug.xml";

    class Attribute;
    class Page;

    std::vector<Page> m_Pages;
};
