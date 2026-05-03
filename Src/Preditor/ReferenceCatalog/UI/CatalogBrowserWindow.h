#pragma once
#include <imgui.h>
#include <string>
#include <vector>
#include <WindowManager/ManagedWindow.h>

namespace ReferenceCatalog
{

//! Searchable cross-kind browser. Picks a kind (or "All"), filters by name
//! or id, and renders the resulting entries as a table. Loads each kind on
//! demand via Catalog::TryGet.
class CatalogBrowserWindow : public ManagedWindow
{
public:
    CatalogBrowserWindow();
    ~CatalogBrowserWindow();

protected:
    virtual void ShowContents() override;

private:
    void RebuildKindList();
    void DrawResults();

    std::vector<std::string> m_Kinds;   //!< Sorted kind names; "" entry at index 0 means "All".
    int m_KindIndex = 0;                //!< Index into m_Kinds; 0 == All.
    ImGuiTextFilter m_Filter;
};

} // namespace ReferenceCatalog
