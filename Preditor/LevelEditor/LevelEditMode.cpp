#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Prey/CryAction/IActorSystem.h>
#include <Prey/CryEntitySystem/Entity.h>
#include <Prey/CryEntitySystem/EntitySystem.h>
#include <Prey/CryGame/IGame.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryPhysics/physinterface.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Preditor/EditTools/IEditToolManager.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include "Objects/Object.h"
#include "ObjectSelectionManager.h"
#include "LevelEditMode.h"
#include "LevelViewportHandler.h"
#include "ObjectManager.h"

LevelEditor::GlobalLevel* LevelEditor::gLevel;

std::unique_ptr<ILevelSceneEditor> ILevelSceneEditor::CreateLevelEditor()
{
    return std::make_unique<LevelEditor::LevelEditMode>();
}

LevelEditor::LevelEditMode::LevelEditMode()
{
    assert(!gLevel);
    gLevel = &m_Global;
    m_Global.pEditor = this;

    m_pSelection = std::make_unique<ObjectSelectionManager>(this);
    m_pViewportHandler = std::make_unique<LevelViewportHandler>(this);
    m_pEditToolManager = IEditToolManager::CreateInstance(this);
    m_pObjectManager = std::make_unique<ObjectManager>();

    // Disable save/load
    m_pCanSaveLoad = gEnv->pConsole->GetCVar("g_EnableLoadSave");
    m_pCanSaveLoad->Set(false);

    LoadLevel();
}

LevelEditor::LevelEditMode::~LevelEditMode()
{
    // Allow save/load
    m_pCanSaveLoad->Set(true);

    assert(gLevel == &m_Global);
    gLevel = nullptr;
}

SelectionManager* LevelEditor::LevelEditMode::GetSelection()
{
    return m_pSelection.get();
}

IViewportHandler* LevelEditor::LevelEditMode::GetViewport()
{
    return m_pViewportHandler.get();
}

const char* LevelEditor::LevelEditMode::GetObjectName(SceneObjectId id)
{
    if (id == INVALID_SCENE_OBJECT)
        return nullptr;

    IEntity* pEnt = gEnv->pEntitySystem->GetEntity((EntityId)id);
    return pEnt ? pEnt->GetName() : nullptr;
}

void LevelEditor::LevelEditMode::OnEnabled()
{
    m_pEditToolManager->SetEnabled(true);
}

void LevelEditor::LevelEditMode::OnDisabled()
{
    m_pEditToolManager->SetEnabled(false);
}

void LevelEditor::LevelEditMode::ShowHierarchy()
{
    // TODO 2023-07-15
    auto& objs = m_pObjectManager->GetObjects();
    for (int i = 0; i < objs.size(); i++)
    {
        ImGui::PushID(i);
        Object* pObj = objs[i].get();
        
        if (ImGui::Selectable(pObj->GetName().c_str()))
        {
            m_pSelection->ClearSelection();
            m_pSelection->AddToSelection(i);
        }

        ImGui::PopID();
    }
}

void LevelEditor::LevelEditMode::ShowInspector()
{
    // TODO 2023-07-15
    SceneObjectId objId = m_pSelection->GetActiveObject();

    if (objId == INVALID_SCENE_OBJECT)
    {
        ImGui::TextDisabled("No object selected");
    }
    else
    {
        Object* pObj = m_pObjectManager->GetObject(objId);

        if (pObj)
        {
            pObj->ShowInspector();
        }
        else
        {
            ImGui::TextDisabled("Invalid object selected??");
        }
    }
}

void LevelEditor::LevelEditMode::OnEnterPlayMode()
{
    CryLog("================= Enter Play Mode =================");
    gPreditor->pViewportWindow->ActivateGameViewport();

    // Reset 3d engine effects
    gEnv->p3DEngine->ResetPostEffects();
    gEnv->p3DEngine->ResetParticlesAndDecals();
    MovePlayerToSceneCamera();

    NotifyGameModeChange(true);

    // Reset physics state before switching to game.
    gEnv->pSystem->GetIPhysicalWorld()->ResetDynamicEntities();

    m_pObjectManager->InvokeOnAll<&Object::OnEnterPlayMode>();

    // gEnv->pSystem->GetAISystem()->Reset(IAISystem::RESET_ENTER_GAME); // FIXME 2023-07-22
    gEnv->pEntitySystem->ResetAreas();
    ResetEntities(true);

    // gEnv->pSystem->GetIMovieSystem()->Reset(true, false); // FIXME 2023-07-22
}

void LevelEditor::LevelEditMode::OnExitPlayMode()
{
    CryLog("================= Exit Play Mode =================");
    gPreditor->pViewportWindow->ActivateSceneViewport();

    // gEnv->pSystem->GetIMovieSystem()->Reset(false, false); // FIXME 2023-07-22

    // Reset 3d engine effects
    gEnv->p3DEngine->ResetPostEffects();
    gEnv->p3DEngine->ResetParticlesAndDecals();

    // this has to be done before the RemoveSink() call, or else some entities may not be removed
    // gEnv->p3DEngine->GetDeferredPhysicsEventManager()->ClearDeferredEvents(); // FIXME 2023-07-22

    // reset movie-system
    gEnv->pSystem->GetIPhysicalWorld()->ResetDynamicEntities();

    ResetEntities(false);

    // clean up AI System
    // gEnv->pSystem->GetAISystem()->Reset(IAISystem::RESET_EXIT_GAME); // FIXME 2023-07-22

    m_pObjectManager->InvokeOnAll<&Object::OnExitPlayMode>();

    NotifyGameModeChange(false);
}

void LevelEditor::LevelEditMode::LoadLevel()
{
    std::string missionXmlPath = gEnv->p3DEngine->GetLevelFilePath("mission_mission0.xml");
    XmlNodeRef missionXml = gEnv->pSystem->LoadXmlFromFile(missionXmlPath.c_str());
    m_pObjectManager->CreateLevelObjects(missionXml->findChild("Objects"));
}

void LevelEditor::LevelEditMode::MovePlayerToSceneCamera()
{
    Matrix34 sceneCam = gPreditor->pViewportWindow->GetSceneCameraTransform();

    // Skip if camera pos is invalid
    if (sceneCam.IsIdentity())
        return;

    IActor* pClActor = gEnv->pGame->GetIGameFramework()->GetClientActor();
    
    if (pClActor)
    {
        // pos coming from editor is a camera position, we must convert it into the player position by subtructing eye height.
        IEntity* myPlayer = pClActor->GetEntity();
        if (myPlayer)
        {
            pe_player_dimensions dim;
            dim.heightEye = 0;
            if (myPlayer->GetPhysics())
            {
                myPlayer->GetPhysics()->GetParams(&dim);
                Vec3 tr = sceneCam.GetTranslation();
                tr.z -= dim.heightEye;
                sceneCam.SetTranslation(tr);
            }
        }

        pClActor->GetEntity()->SetPosRotScale(sceneCam.GetTranslation(), Quat(sceneCam), Vec3(1, 1, 1),
            ENTITY_XFORM_EDITOR | ENTITY_XFORM_POS | ENTITY_XFORM_ROT | ENTITY_XFORM_SCL);
    }
}

void LevelEditor::LevelEditMode::ResetEntities(bool isPlayMode)
{
    auto pEntSystem = static_cast<CEntitySystem*>(gEnv->pEntitySystem);

    for (CEntity* const pEntity : pEntSystem->m_EntityArray)
    {
        if (pEntity == nullptr)
            continue;

        // Activate entity if was deactivated:
        if (pEntity->IsGarbage())
        {
            // Entity may have been queued for deletion
            stl::find_and_erase(pEntSystem->m_deletedEntities, pEntity);

            // If entity was deleted in game, resurrect it.
            SEntityEvent entevnt;
            entevnt.event = ENTITY_EVENT_INIT;
            pEntity->SendEvent(entevnt);
        }
    }

    SEntityEvent event;
    event.event = ENTITY_EVENT_RESET;
    event.nParam[0] = isPlayMode ? 1 : 0;
    pEntSystem->SendEventToAll(event);

    if (isPlayMode)
    {
        event.event = ENTITY_EVENT_START_GAME;
        pEntSystem->SendEventToAll(event);
    }
}

void LevelEditor::LevelEditMode::NotifyGameModeChange(bool isPlayMode)
{
     // gEnv->pGame->EditorResetGame(isPlayMode); // FIXME 2023-07-22: Crashes when entering play mode
    gEnv->pGame->GetIGameFramework()->OnEditorSetGameMode(isPlayMode);

    if (isPlayMode)
    {
        // Revive the player
        if (ArkPlayer* pPlayer = ArkPlayer::GetInstancePtr())
        {
            // pPlayer->Revive();
        }
    }
}
