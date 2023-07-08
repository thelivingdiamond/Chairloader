#pragma once
#include <Preditor/SceneEditor/Common.h>
#include <Preditor/EditTools/IEditToolManager.h>

//! Scene mask for the real world.
constexpr uint8_t SCENE_MASK_REAL = 1 << 0;

//! Scene mask for the Looking Glass world.
constexpr uint8_t SCENE_MASK_LG = 1 << 1;

struct ViewportRaycastInfo
{
    //! World-space ray from the viewport.
    Ray ray;

    //! Viewport size.
    Vec2 viwportSize = Vec2(ZERO);

    //! Mouse position on the viewport where click occured.
    Vec2 viewportClickPos = Vec2(ZERO);

    //! Viewport scene mask.
    uint8_t sceneMask = 0;
};

struct IViewportHandler
{
    virtual ~IViewportHandler() {}

    //! Shows ImGui controls on the scene viewport.
    virtual void ShowViewportControls() = 0;

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
