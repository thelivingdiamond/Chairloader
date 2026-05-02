#pragma once

class ManagedWindow;

struct IFlowgraphEditor
{
    //! Creates the main Flowgraph Editor window.
    static std::shared_ptr<ManagedWindow> CreateMainWindow();
};