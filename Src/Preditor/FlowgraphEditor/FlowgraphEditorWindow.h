#pragma once
#include <WindowManager/ManagedWindow.h>

namespace FlowgraphEditor
{

class FlowgraphEditorWindow : public ManagedWindow
{
public:
    FlowgraphEditorWindow();
    ~FlowgraphEditorWindow();

protected:
    virtual void ShowContents() override;
};

} // namespace FlowgraphEditor