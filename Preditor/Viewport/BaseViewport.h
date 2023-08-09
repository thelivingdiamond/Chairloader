#pragma once
#include <Preditor/Viewport/IViewport.h>

namespace Viewport
{

class BaseViewport : public IViewport
{
public:
    //! @returns whether the viewport is currently active.
    bool IsActive() { return m_IsActive; }

    //! @returns whether the viewport can currently be activated.
    virtual bool CanActivate() { return true; }

    //! Called when the viewport is enabled.
    virtual void OnEnabled();

    //! Called when the viewport is disabled.
    virtual void OnDisabled();

    //! Called on window update.
    virtual void Update(bool isVisible);

    //! Shows the UI. Cursor will be positioned on the line after viewport radio buttons.
    virtual void ShowUI() = 0;

protected:
    //! Fills the rest of the window with the viewport image.
    //! @returns image bounds (top left, bottom right)
    ImVec4 ShowViewportImage();

private:
    bool m_IsActive = false;
};

} // namespace Viewport
