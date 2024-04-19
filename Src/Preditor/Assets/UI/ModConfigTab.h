#pragma once

struct IChairManager;
class ConfigManager;

namespace Assets
{

class ModConfigTab
{
public:
    ModConfigTab(IChairManager* pChair);
    ~ModConfigTab();

    //! @returns whether there are any unsaved changes.
    bool HasUnsavedChanges();

    //! Resets any user changes, reloads configs from disk.
    void Reset();

    //! Applies user changes.
    void ApplyChanges();

    //! Shows the UI contents.
    void ShowContents();

private:
    IChairManager* m_pChair = nullptr;
    std::unique_ptr<ConfigManager> m_pConfigManager;
};

} // namespace Assets
