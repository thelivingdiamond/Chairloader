#include "GameViewportHandler.h"

GameEditor::GameViewportHandler::GameViewportHandler(GameEditMode* pEditor)
{
    m_pEditor = pEditor;
}

GameEditor::GameViewportHandler::~GameViewportHandler()
{
}

EEditToolResult GameEditor::GameViewportHandler::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    CryLog("GameViewportHandler::OnLeftMouseClick");
    return EEditToolResult::Passthrough;
}
