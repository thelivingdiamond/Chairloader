#pragma once

struct IViewport;

struct IViewportWindow
{
    //! Creates the viewport window instance.
    static std::shared_ptr<IViewportWindow> CreateInstance();

    virtual ~IViewportWindow() {}

    //! @returns the currently active viewport.
    virtual IViewport* GetCurrentViewport() = 0;

    //! @returns the viewport image position in screen coordinates.
    // virtual Vec2i GetScreenPos() = 0;

    //! @returns the viewport image size.
    // virtual Vec2i GetScreenSize() = 0;

    //! @returns whether the window is focused.
    virtual bool IsFocused() = 0;
};
