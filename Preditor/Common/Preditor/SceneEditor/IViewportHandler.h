#pragma once
#include <Preditor/EditTools/IEditToolManager.h>

struct IViewportHandler
{
    virtual ~IViewportHandler() {}

    //! Called when the viewport is left-clicked.
    //! @param  clickPos    Position where the mouse was clicked [(0,0) is in top-left corner].
    //! @param  vpSize      Size of the viewport.
    //! @returns action result.
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) = 0;
};
