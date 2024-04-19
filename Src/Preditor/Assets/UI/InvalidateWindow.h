#pragma once
#include <WindowManager/ManagedWindow.h>

namespace Assets
{

class InvalidateWindow : public ManagedWindow
{
public:
    InvalidateWindow();
    ~InvalidateWindow();

protected:
    // ManagedWindow
    virtual void ShowContents() override;

private:
    bool m_bInvImport = true;
    bool m_bInvMerge = true;
    bool m_bAutoMerge= true;
};

} // namespace Assets
