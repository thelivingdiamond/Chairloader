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

//! Preditor UI elements using ImGui.
class PreditorUI : NoCopy
{
public:
    PreditorUI();
    ~PreditorUI();

    //! Shows the UI elements.
    void ShowUI();

private:
    std::unique_ptr<IChairloaderToolsPreditor> m_pChairTools;
    std::shared_ptr<IViewportWindow> m_pViewportWindow;
    std::shared_ptr<SimControlWindow> m_pSimControlWindow;
    std::shared_ptr<ManagedWindow> m_pToolSelectionWindow;
    std::shared_ptr<FileBrowser> m_pProjectBrowser;
    std::shared_ptr<FileBrowser> m_pAssetBrowser;
    std::shared_ptr<InspectorWindow> m_pInspectorWindow;
    std::shared_ptr<HierarchyWindow> m_pHierarchyWindow;
    std::shared_ptr<SelectionWindow> m_pSelectionWindow;

    bool m_bImGuiDemo = false;

    //! Shows the menu bar for the main window.
    void ShowMainMenuBar();
};

} // namespace Main
