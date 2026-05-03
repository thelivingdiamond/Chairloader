#pragma once
#include <WindowManager/ManagedWindow.h>

namespace FlowgraphEditor
{

struct Node;
struct Edge;

//! Properties view for the active graph's selected node(s) and edge(s).
//! Renders typed editors for input port defaults; commits route through
//! SetPortDefaultCmd / RenameNodeCmd / SetEdgeEnabledCmd.
class PropertyInspectorWindow : public ManagedWindow
{
public:
    PropertyInspectorWindow();
    ~PropertyInspectorWindow();

protected:
    virtual void ShowContents() override;

private:
    void DrawNodeProperties(Node& node);
    void DrawEdgeProperties(Edge& edge);
};

} // namespace FlowgraphEditor
