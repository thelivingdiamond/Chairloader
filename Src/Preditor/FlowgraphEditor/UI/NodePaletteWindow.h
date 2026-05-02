#pragma once
#include <WindowManager/ManagedWindow.h>

namespace FlowgraphEditor
{

//! Searchable, category-grouped browser of every prototype the registry knows
//! about. Each entry is a drag source for the FLOWGRAPH_PROTOTYPE payload that
//! the graph canvas accepts as a drop target.
class NodePaletteWindow : public ManagedWindow
{
public:
    NodePaletteWindow();
    ~NodePaletteWindow();

protected:
    virtual void ShowContents() override;

private:
    std::string m_Filter;
};

} // namespace FlowgraphEditor
