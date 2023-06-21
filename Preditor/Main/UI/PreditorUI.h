#pragma once

struct IViewportWindow;

namespace Main
{

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
    std::shared_ptr<IViewportWindow> m_pViewportWindow;
    std::shared_ptr<SimControlWindow> m_pSimControlWindow;

    //! Shows the menu bar for the main window.
    void ShowMainMenuBar();
};

} // namespace Main
