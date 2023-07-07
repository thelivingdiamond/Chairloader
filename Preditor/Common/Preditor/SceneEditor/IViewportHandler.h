#pragma once
#include <Preditor/SceneEditor/Common.h>
#include <Preditor/EditTools/IEditToolManager.h>

struct ViewportRaycastInfo
{
    //! World-space ray from the viewport.
    Ray ray;

    //! Viewport size.
    Vec2 viwportSize = Vec2(ZERO);

    //! Mouse position on the viewport where click occured.
    Vec2 viewportClickPos = Vec2(ZERO);
};

struct IViewportHandler
{
    virtual ~IViewportHandler() {}

    //! Called when the viewport is left-clicked.
    //! @param  clickPos    Position where the mouse was clicked [(0,0) is in top-left corner].
    //! @param  vpSize      Size of the viewport.
    //! @returns action result.
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) = 0;

    //! Casts a ray and finds an object.
    virtual SceneObjectId Raycast(const ViewportRaycastInfo& rc) = 0;

    //! Aux geom calls before rendering the world.
    virtual void DrawAuxGeom() = 0;
};
