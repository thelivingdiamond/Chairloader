#pragma once
#include <WindowManager/ManagedWindow.h>
#include "IO/XmlSerializer.h" // GraphSummary

namespace FlowgraphEditor
{

class GraphTab;

class FlowgraphEditorWindow : public ManagedWindow
{
public:
    //! Returns the live instance, or nullptr if none has been constructed yet.
    //! Single-instance assumption — only one FlowgraphEditorWindow exists per session.
    static FlowgraphEditorWindow* Get() { return s_pInstance; }

    FlowgraphEditorWindow();
    ~FlowgraphEditorWindow();

    //! The tab whose canvas was rendered last frame. May be null when no tabs are open
    //! or this window is hidden. Auxiliary windows read from this to stay in sync.
    GraphTab* GetActiveTab() const { return m_pActiveTab; }

    //! Loads every flowgraph from `path` into new tabs, makes the editor visible, and
    //! brings the loaded tabs to focus.
    void OpenFile(const std::string& path);

    //! Loads exactly one graph into a new tab. The graph is identified by the
    //! `target` summary — preferring its `entityGuid` (stable) and falling back
    //! to `indexInFile`. Used by the browser to pick a single graph out of a
    //! multi-graph mission file.
    void OpenGraphFromFile(const std::string& path, const GraphSummary& target);

    //! Saves the active tab to its resolved target path. No-op if no active tab.
    void SaveActiveTab();

    //! Saves every dirty tab whose graph has a saveable source.
    void SaveAll();

protected:
    virtual void Update(bool isVisible) override;
    virtual void ShowContents() override;

private:
    void DrawFileLoader();
    void DrawTabActionsBar();
    void DrawCloseDirtyModal();
    void DrawSaveAsModal();
    void DrawResetModal();
    void LoadGraphsFromFile(const std::string& path);
    bool SaveTab(GraphTab& tab);
    bool SaveTabAs(GraphTab& tab, const std::filesystem::path& target);
    bool ResetTabToVanilla(GraphTab& tab);

    static FlowgraphEditorWindow* s_pInstance;

    std::vector<std::unique_ptr<GraphTab>> m_Tabs;
    GraphTab* m_pActiveTab = nullptr;
    std::string m_LoadPath;
    std::string m_LoadStatus;

    // Modal-pending tab pointers. Raw pointers — safe because all three modals
    // are blocking, so the underlying tab can't be removed from m_Tabs while a
    // modal is up.
    GraphTab* m_pPendingCloseTab  = nullptr; //!< user clicked X on a dirty tab
    GraphTab* m_pPendingSaveAsTab = nullptr; //!< user invoked Save As
    GraphTab* m_pPendingResetTab  = nullptr; //!< user invoked Reset to Vanilla
    std::string m_SaveAsPath;                 //!< buffer for the Save As modal
};

} // namespace FlowgraphEditor
