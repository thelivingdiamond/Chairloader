#pragma once

struct IChairloaderToolsPreditor;
struct IViewportWindow;
class ManagedWindow;

namespace Main
{

class FileBrowser;
class HierarchyWindow;
class InspectorWindow;
class SelectionWindow;
class SimControlWindow;
class ArkLibraryExplorer;

//! Preditor UI elements using ImGui.
class PreditorUI : NoCopy
{
public:
    PreditorUI();
    ~PreditorUI();

    //! Shows the UI elements.
    void ShowUI();

    //! Adds a level to recent level list.
    void AddLevelToRecent(const std::string& path);

private:
    static constexpr char LEVEL_HISTORY_FILE[] = "RecentLevels.xml";

    std::unique_ptr<IChairloaderToolsPreditor> m_pChairTools;
    std::shared_ptr<IViewportWindow> m_pViewportWindow;
    std::shared_ptr<SimControlWindow> m_pSimControlWindow;
    std::shared_ptr<ManagedWindow> m_pToolSelectionWindow;
    std::shared_ptr<FileBrowser> m_pProjectBrowser;
    std::shared_ptr<FileBrowser> m_pAssetBrowser;
    std::shared_ptr<InspectorWindow> m_pInspectorWindow;
    std::shared_ptr<HierarchyWindow> m_pHierarchyWindow;
    std::shared_ptr<SelectionWindow> m_pSelectionWindow;
    std::weak_ptr<ArkLibraryExplorer> m_pArkLibraryExplorer;

    std::vector<std::string> m_LevelEditHistory;
    bool m_bImGuiDemo = false;

    //! Loads recent level list.
    void LoadLevelEditHistory();

    //! Shows the menu bar for the main window.
    void ShowMainMenuBar();
};

} // namespace Main
