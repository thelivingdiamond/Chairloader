#include <Preditor/EditTools/IEditToolManager.h>
#include "EntitySelectionManager.h"
#include "GameEditMode.h"
#include "GameViewportHandler.h"

// I still hate myself...
#include "../../Chairloader/Tools/Components/EntityInspector.h"

std::unique_ptr<ISceneEditor> ISceneEditor::CreateGameEditor()
{
    return std::make_unique<GameEditor::GameEditMode>();
}

GameEditor::GameEditMode::GameEditMode()
{
    m_pSelection = std::make_unique<EntitySelectionManager>(this);
    m_pViewportHandler = std::make_unique<GameViewportHandler>(this);
    m_pEditToolManager = IEditToolManager::CreateInstance(this);
    m_pEntityInspector = std::make_unique<EntityInspector>();
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

const char* GameEditor::GameEditMode::GetObjectName(SceneObjectId id)
{
    if (id == INVALID_SCENE_OBJECT)
        return nullptr;

    IEntity* pEnt = gEnv->pEntitySystem->GetEntity((EntityId)id);
    return pEnt ? pEnt->GetName() : nullptr;
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
    SceneObjectId objId = m_pSelection->GetActiveObject();
    EntityId entId = objId != INVALID_SCENE_OBJECT ? (EntityId)objId : INVALID_ENTITYID;
    m_pEntityInspector->ShowContents(entId);
}
