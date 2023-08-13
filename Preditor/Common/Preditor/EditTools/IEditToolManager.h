#pragma once

struct ISceneEditor;
class ManagedWindow;

enum class EEditToolResult
{
    //! The tool has handled the action.
    Handled,

    //! Pass the action to the next tool in the chain (e.g. select tool).
    Passthrough,
};

struct IEditToolManager
{
    //! Creates a new instance of the tool manager.
    static std::unique_ptr<IEditToolManager> CreateInstance(ISceneEditor* pEditor);

    //! Creates a new instance of ToolSelectionWindow.
    static std::shared_ptr<ManagedWindow> CreateToolSelectionWindow();

    virtual ~IEditToolManager() {}

    //! Sets whether the tool manager is enabled.
    virtual void SetEnabled(bool state) = 0;

    //! Called when the viewport is left-clicked.
    //! @param  clickPos    Position where the mouse was clicked [(0,0) is in top-left corner].
    //! @param  vpSize      Size of the viewport.
    //! @returns action result.
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) = 0;

    //! Called from the viewport ImGui window context.
    //! @param  bounds  Viewport bounds.
    virtual void DrawViewport(const Vec4& bounds, const Matrix44& viewMat) = 0;
};
