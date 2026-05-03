#pragma once

class ManagedWindow;

struct IFlowgraphEditor
{
    //! The main editor with tabbed canvases. Single-instance per session.
    static std::shared_ptr<ManagedWindow> CreateMainWindow();

    //! File tree of vanilla flowgraph-bearing locations. Click-to-open routes
    //! through the main window.
    static std::shared_ptr<ManagedWindow> CreateBrowserWindow();

    //! Searchable, category-grouped browser of all engine prototypes.
    static std::shared_ptr<ManagedWindow> CreatePaletteWindow();

    //! Read-only properties view for the active graph's selected node(s).
    static std::shared_ptr<ManagedWindow> CreateInspectorWindow();

    //! Active graph's metadata + graph-scoped tokens.
    static std::shared_ptr<ManagedWindow> CreateTokensWindow();
};
