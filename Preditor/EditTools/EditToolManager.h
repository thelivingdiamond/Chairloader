#pragma once
#include <Preditor/EditTools/IEditToolManager.h>

namespace EditTools
{

class EditTool;
class ImGuizmoTool;

class EditToolManager final : public IEditToolManager
{
public:
    EditToolManager(ISceneEditor* pEditor);
    ~EditToolManager();

    //! @returns the editor that owns this tool manager;
    ISceneEditor* GetEditor() const { return m_pEditor; }

    //! @returns the current tool (or nullptr, if none).
    EditTool* GetCurrentTool() const { return m_pCurTool; }

    //! Shows controls for the tool selection UI.
    void ShowSelectionUI();

    // IEditToolManager
    virtual void SetEnabled(bool state) override;
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) override;
    virtual void DrawViewport(const Vec4& bounds, const CCamera& camera) override;

private:
    bool m_bIsActive = false;
    ISceneEditor* m_pEditor = nullptr;
    EditTool* m_pCurTool = nullptr;

    std::unique_ptr<EditTool> m_pSelectTool;
    std::unique_ptr<ImGuizmoTool> m_pMoveTool;
    std::unique_ptr<ImGuizmoTool> m_pRotateTool;
    std::unique_ptr<ImGuizmoTool> m_pScaleTool;

    //! Changes the active tool to a different one.
    void SetCurrentTool(EditTool* pTool);
};

} // namespace EditTools
