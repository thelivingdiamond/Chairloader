#pragma once
#include <WindowManager/ManagedWindow.h>

namespace FlowgraphEditor
{

//! Active graph's metadata + graph-scoped tokens. Edits route through the
//! command history.
class GraphTokensWindow : public ManagedWindow
{
public:
    GraphTokensWindow();
    ~GraphTokensWindow();

protected:
    virtual void ShowContents() override;
};

} // namespace FlowgraphEditor
