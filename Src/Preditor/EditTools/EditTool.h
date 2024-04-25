#pragma once
#include <Preditor/EditTools/IEditToolManager.h>

namespace EditTools
{

class EditToolManager;

class EditTool : NoCopy
{
public:
    EditTool(EditToolManager* pMgr);
    virtual ~EditTool();

    //! @returns the tool manager that owns this tool.
    EditToolManager* GetManager() const { return m_pMgr; }

    //! @returns whether the tool is currently active.
    bool IsActive() const { return m_bIsActive; }

    //! Called when the tool is enabled.
    virtual void OnEnabled();

    //! Called when the tool is disabled.
    virtual void OnDisabled();

    //! Called from the viewport context.
    //! @param  bounds  Viewport bounds.
    //! @param  camera  Viewport camera.
    virtual void DrawViewport(const Vec4& bounds, const CCamera& camera) {}

    //! Called when the viewport is left-clicked.
    //! @param  clickPos    Position where the mouse was clicked [(0,0) is in top-left corner].
    //! @param  vpSize      Size of the viewport.
    //! @returns action result.
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize);

private:
    EditToolManager* m_pMgr = nullptr;
    bool m_bIsActive = false;

    //! Sets whether the tool is active.
    void SetActive(bool state);

    friend class EditToolManager;
};

} // namespace EditTools
