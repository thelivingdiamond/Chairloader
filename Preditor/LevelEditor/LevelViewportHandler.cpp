#include <Prey/Cry3DEngine/IStatObj.h>
#include <Prey/CryEntitySystem/Entity.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/CryPhysics/IPhysics.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Preditor/SceneEditor/SelectionManager.h>
#include "LevelEditMode.h"
#include "LevelViewportHandler.h"

LevelEditor::LevelViewportHandler::LevelViewportHandler(LevelEditMode* pEditor)
{
    m_pEditor = pEditor;
}

LevelEditor::LevelViewportHandler::~LevelViewportHandler()
{
}

void LevelEditor::LevelViewportHandler::ShowViewportControls()
{
}

EEditToolResult LevelEditor::LevelViewportHandler::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    return EEditToolResult::Passthrough;
}

SceneObjectId LevelEditor::LevelViewportHandler::Raycast(const ViewportRaycastInfo& rc)
{
	// TODO 2023-07-15
    return INVALID_SCENE_OBJECT;
}

void LevelEditor::LevelViewportHandler::DrawAuxGeom()
{
	DrawSelectedObjects();
}

void LevelEditor::LevelViewportHandler::DrawSelectedObjects()
{
    // TODO 2023-07-15
}
