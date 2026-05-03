#pragma once
#include <memory>

class ManagedWindow;

//! Factory + bootstrap for the ReferenceCatalog UI surface. Mirrors the
//! IFlowgraphEditor pattern: implementation lives in the ReferenceCatalog
//! module; the Main module references this header to wire menus.
struct IReferenceCatalogUI
{
    //! Registers all standard providers (GameToken, RemoteEvent, ...) and
    //! flowgraph port → kind rules. One-time guarded; safe to call multiple
    //! times. Call after gPreditor->pConfig is valid.
    static void EnsureDefaults();

    //! Searchable browser across every registered kind. Single-instance.
    static std::shared_ptr<ManagedWindow> CreateBrowserWindow();
};
