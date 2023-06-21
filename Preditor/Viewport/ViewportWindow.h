#pragma once
#include <WindowManager/ManagedWindow.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include "BaseViewport.h"
#include "MouseGuard.h"

namespace Viewport
{

class SceneViewport;
class GameViewport;

class ViewportWindow final
    : public ManagedWindow
    , public IViewportWindow
{
public:
    ViewportWindow();
    ~ViewportWindow();

    //! Sets the viewport.
    void SetViewport(BaseViewport* pViewport);

    //! Fills the rest of the window with the viewport image.
    //! @returns image bounds (top left, bottom right)
    ImVec4 ShowViewportImage();

    // IViewportWindow
    virtual IViewport* GetCurrentViewport() override { return m_pCurrentViewport; }
    virtual Vec4i GetScreenBounds() override { return m_ScreenBounds; }
    virtual bool IsFocused() override { return IsFocused(); }

protected:
    void PreUpdate() override;
    void Update(bool isVisible) override;
    void ShowContents() override;

private:
    //! Hardcoded minimum viewport size in the engine
    static constexpr int MIN_WIDTH = 512;
    static constexpr int MIN_HEIGHT = 300;

    //! Maximum reasonable size to prevent crashes
    static constexpr int MAX_SIZE = 8192;

    // Image rendering
    ITexture* m_pViewportTexture = nullptr;
    ICVar* m_pCVarWidth = nullptr;
    ICVar* m_pCVarHeight = nullptr;

    // Resizing
    MouseGuard m_ResizeGuard;
    int m_ResizeFrameCount = 0;

    // Viewport bounds
    Vec4i m_ScreenBounds = Vec4i(0, 0, 0, 0);

    BaseViewport* m_pCurrentViewport = nullptr;

    // Viewports
    std::unique_ptr<SceneViewport> m_pSceneViewport;
    std::unique_ptr<GameViewport> m_pGameViewport;
};

} // namespace Viewport
