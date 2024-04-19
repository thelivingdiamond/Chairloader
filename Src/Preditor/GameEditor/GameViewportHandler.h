#pragma once
#include <Preditor/SceneEditor/IViewportHandler.h>

namespace GameEditor
{

class GameEditMode;

class GameViewportHandler : public IViewportHandler
{
public:
    GameViewportHandler(GameEditMode* pEditor);
    ~GameViewportHandler();

    // IViewportHandler
    virtual void ShowViewportControls() override;
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) override;
    virtual ViewportRaycastHit Raycast(const ViewportRaycastInfo& rc) override;
    virtual void DrawAuxGeom() override;

private:
    GameEditMode* m_pEditor = nullptr;
    bool m_bPhysicsRaycast = false;

    void DrawSelectedObjects();
};

} // namespace GameEditor
