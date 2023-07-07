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
    virtual EEditToolResult OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize) override;

private:
    GameEditMode* m_pEditor = nullptr;
};

} // namespace GameEditor
