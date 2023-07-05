#pragma once
#include <Manager/ModInfo.h>

namespace Assets
{

class ModListTab : NoCopy
{
public:
    ModListTab();
    ~ModListTab();

    //! @returns whether there are any unsaved changes.
    bool HasUnsavedChanges() { return m_HasUnsavedChanges; }

    //! Resets any user changes, reloads configs from disk.
    void Reset();

    //! Applies user changes.
    void ApplyChanges();

    //! Shows the UI contents.
    void ShowContents();

private:
    struct ListItem
    {
        Manager::ModInfo info;
        fs::path fullPath;
        bool isNameValid = false;
        bool isThisProject = false;
        bool isEnabled = false;
        int loadOrder = std::numeric_limits<int>::max();
    };

    bool m_HasUnsavedChanges = false;
    std::vector<ListItem> m_Items;
    int m_SelectedItemIdx = -1;

    //! Finds all installed mods and adds them to the list.
    void LoadModList();

    //! Loads the mod order from the Chairloader config.
    void LoadModConfig();

    void ShowModList();
    void ShowSelectedModDetails();
};

} // namespace Assets
