#pragma once
#include <Preditor/EditTools/IEditToolManager.h>

namespace EditTools
{

class EditTool;

class EditToolManager final : public IEditToolManager
{
public:
    EditToolManager(ISceneEditor* pEditor);
    ~EditToolManager();

    //! @returns the current tool (or nullptr, if none).
    EditTool* GetCurrentTool() const { return m_pCurTool; }

    //! Shows controls for the tool selection UI.
    void ShowSelectionUI();

    // IEditToolManager
    virtual void SetEnabled(bool state) override;
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) override;

private:
    bool m_bIsActive = false;
    ISceneEditor* m_pEditor = nullptr;
    EditTool* m_pCurTool = nullptr;

    std::unique_ptr<EditTool> m_pSelectTool;

    //! Changes the active tool to a different one.
    void SetCurrentTool(EditTool* pTool);
};

} // namespace EditTools
