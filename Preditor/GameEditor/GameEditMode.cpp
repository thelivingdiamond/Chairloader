#include "GameEditMode.h"

std::unique_ptr<ISceneEditor> ISceneEditor::CreateGameEditor()
{
    return std::make_unique< GameEditor::GameEditMode>();
}

void GameEditor::GameEditMode::OnEnabled()
{
}

void GameEditor::GameEditMode::OnDisabled()
{
}

void GameEditor::GameEditMode::ShowInspector()
{
}
