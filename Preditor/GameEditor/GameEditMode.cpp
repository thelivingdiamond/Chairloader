#include <Preditor/EditTools/IEditToolManager.h>
#include "EntitySelectionManager.h"
#include "GameEditMode.h"
#include "GameViewportHandler.h"

std::unique_ptr<ISceneEditor> ISceneEditor::CreateGameEditor()
{
    return std::make_unique<GameEditor::GameEditMode>();
}

GameEditor::GameEditMode::GameEditMode()
{
    m_pSelection = std::make_unique<EntitySelectionManager>(this);
    m_pViewportHandler = std::make_unique<GameViewportHandler>(this);
    m_pEditToolManager = IEditToolManager::CreateInstance(this);
}

GameEditor::GameEditMode::~GameEditMode()
{
}

SelectionManager* GameEditor::GameEditMode::GetSelection()
{
    return m_pSelection.get();
}

IViewportHandler* GameEditor::GameEditMode::GetViewport()
{
    return m_pViewportHandler.get();
}

void GameEditor::GameEditMode::OnEnabled()
{
    m_pEditToolManager->SetEnabled(true);
}

void GameEditor::GameEditMode::OnDisabled()
{
    m_pEditToolManager->SetEnabled(false);
}

void GameEditor::GameEditMode::ShowInspector()
{
}
