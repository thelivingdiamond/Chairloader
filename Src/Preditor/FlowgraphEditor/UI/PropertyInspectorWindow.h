#pragma once
#include <WindowManager/ManagedWindow.h>

namespace FlowgraphEditor
{

struct Node;

//! Properties view for the active graph's selected node(s). Renders typed
//! editors for input port defaults; commits route through SetPortDefaultCmd.
class PropertyInspectorWindow : public ManagedWindow
{
public:
    PropertyInspectorWindow();
    ~PropertyInspectorWindow();

protected:
    virtual void ShowContents() override;

private:
    void DrawNodeProperties(Node& node);
};

} // namespace FlowgraphEditor
