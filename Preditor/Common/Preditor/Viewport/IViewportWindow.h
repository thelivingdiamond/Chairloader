#pragma once

struct IViewport;

struct IViewportWindow
{
    //! Creates the viewport window instance.
    static std::shared_ptr<IViewportWindow> CreateInstance();

    virtual ~IViewportWindow() {}

    //! @returns the currently active viewport.
    virtual IViewport* GetCurrentViewport() = 0;

    //! @returns the viewport image bounds in screen coordinates.
    virtual Vec4i GetScreenBounds() = 0;

    //! @returns whether the window is focused.
    virtual bool IsFocused() = 0;

    //! @returns a ray from screen coordinates.
    virtual Ray GetRayForMouse(Vec2 mousePos, Vec2 vpSize) = 0;
};
