#pragma once
#include <WindowManager/ManagedWindow.h>
#include <Manager/IChairManager.h>
#include "UI/ModListTab.h"
#include "UI/ModConfigTab.h"

namespace Assets
{

class ModManagerWindow : public ManagedWindow, private IChairManager
{
public:
    ModManagerWindow();
    ~ModManagerWindow();

    //! Resets any changes and reloads configs.
    void Reset();

    //! Applies user changes.
    void ApplyChanges();

protected:
    // ManagedWindow
    virtual void ShowContents() override;

private:
    ModListTab m_ModListTab;
    std::unique_ptr<ModConfigTab> m_pModConfigTab;
    bool m_HadModChanges = false;

    // IChairManager
    virtual fs::path GetConfigPath() override;
    virtual fs::path GetModPath(const std::string& modName) override;
    virtual std::vector<std::string> GetModNames() override;
    virtual std::string GetModDisplayName(const std::string& modName) override;
    virtual void LogString(severityLevel level, std::string_view str) override;
};

} // namespace Assets
