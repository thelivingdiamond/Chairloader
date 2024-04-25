#pragma once
#include <WindowManager/ManagedWindow.h>

namespace EditTools
{

class ToolSelectionWindow : public ManagedWindow
{
public:
    ToolSelectionWindow();
    ~ToolSelectionWindow();

protected:
    virtual void ShowContents() override;
};

} // namespace EditTools
