#pragma once
#include <WindowManager/ManagedWindow.h>
#include "UI/ModListTab.h"

namespace Assets
{

class ModManagerWindow : public ManagedWindow
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
    bool m_HadModChanges = false;
};

} // namespace Assets
