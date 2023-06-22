#pragma once

struct IChairloaderToolsPreditor;
struct IViewportWindow;

namespace Main
{

class SimControlWindow;
class FileBrowser;

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
    std::shared_ptr<FileBrowser> m_pProjectBrowser;
    std::shared_ptr<FileBrowser> m_pAssetBrowser;

    bool m_bImGuiDemo = false;

    //! Shows the menu bar for the main window.
    void ShowMainMenuBar();
};

} // namespace Main
