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
    virtual void LogString(severityLevel level, std::string_view str) override;
    virtual void OverlayLogString(severityLevel level, std::string_view str) override;
    virtual fs::path GetConfigPath() override;
    virtual fs::path GetModPath(const std::string& modName) override;
    virtual std::vector<std::string> GetModNames() override;
    virtual std::vector<std::string> GetLegacyModNames() override;
    virtual const std::vector<Mod>& GetMods() const override;
    virtual std::string GetModDisplayName(const std::string& modName) override;
    virtual const ModConfig* GetModConfig(const std::string& modName) const override;
    virtual bool IsModEnabled(const std::string& modName) override;
};

} // namespace Assets
