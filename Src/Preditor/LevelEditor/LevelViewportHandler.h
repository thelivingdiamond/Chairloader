#pragma once
#include <Preditor/SceneEditor/IViewportHandler.h>

namespace LevelEditor
{

class LevelEditMode;

class LevelViewportHandler : public IViewportHandler
{
public:
    LevelViewportHandler(LevelEditMode* pEditor);
    ~LevelViewportHandler();

    // IViewportHandler
    virtual void ShowViewportControls() override;
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) override;
    virtual ViewportRaycastHit Raycast(const ViewportRaycastInfo& rc) override;
    virtual void DrawAuxGeom() override;

private:
    LevelEditMode* m_pEditor = nullptr;

    void DrawSelectedObjects();
};

} // namespace LevelEditor
