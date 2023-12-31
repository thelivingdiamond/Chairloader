#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/Engine/ISimulationController.h>
#include <Preditor/SceneEditor/ILevelSceneEditor.h>
#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include "SceneEditorManager.h"

static std::map<ESystemEvent, const char*> GetEventNames()
{
    std::map<ESystemEvent, const char*> m;
#define X(name) m[name] = #name
    X(ESYSTEM_EVENT_LEVEL_LOAD_START_PRELOADINGSCREEN);
    X(ESYSTEM_EVENT_LEVEL_LOAD_RESUME_GAME);
    X(ESYSTEM_EVENT_LEVEL_LOAD_PREPARE);
    X(ESYSTEM_EVENT_LEVEL_LOAD_START_LOADINGSCREEN);
    X(ESYSTEM_EVENT_LEVEL_LOAD_LOADINGSCREEN_ACTIVE);
    X(ESYSTEM_EVENT_LEVEL_LOAD_START);
    X(ESYSTEM_EVENT_LEVEL_LOAD_END);
    X(ESYSTEM_EVENT_LEVEL_LOAD_ERROR);
    X(ESYSTEM_EVENT_LEVEL_NOT_READY);
    X(ESYSTEM_EVENT_LEVEL_PRECACHE_START);
    X(ESYSTEM_EVENT_LEVEL_PRECACHE_CAMERA_READY);
    X(ESYSTEM_EVENT_LEVEL_PRECACHE_FIRST_FRAME);
    X(ESYSTEM_EVENT_LEVEL_GAMEPLAY_START);
    X(ESYSTEM_EVENT_LEVEL_UNLOAD);
    X(ESYSTEM_EVENT_LEVEL_POST_UNLOAD);
    X(ESYSTEM_EVENT_LEVEL_PRECACHE_END);
#undef X
    return m;
}

static auto g_EventNames = GetEventNames();

Main::SceneEditorManager::SceneEditorManager()
{
    gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this);
    gEnv->pConsole->AddCommand("map_edit", &SceneEditorManager::MapEditCmd, VF_NULL, "Load a level in Preditor");

    Reset();
}

Main::SceneEditorManager::~SceneEditorManager()
{
    gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);

    // Unpause
    Engine::ISimulationController* pSim = gPreditor->pEngine->GetSimController();
    pSim->SetSimulationMode(Engine::ESimulationMode::Play);
}

void Main::SceneEditorManager::SetPlayMode(EPlayMode playMode)
{
    assert(m_pLevelEditor);

    if (m_CurrentPlayMode == playMode)
        return;

    Engine::ISimulationController* pSim = gPreditor->pEngine->GetSimController();

    switch (playMode)
    {
    case EPlayMode::Edit:
    {
        if (m_CurrentPlayMode == EPlayMode::Play)
            m_pLevelEditor->OnExitPlayMode();

        SetEditor(m_pLevelEditor.get(), EEditMode::Level);
        m_pSceneEditor.reset();
        pSim->SetSimulationMode(Engine::ESimulationMode::Pause);
        break;
    }
    case EPlayMode::Play:
    {
        assert(!m_pSceneEditor);
        m_pLevelEditor->OnEnterPlayMode();
        m_pSceneEditor = ISceneEditor::CreateGameEditor();
        SetEditor(m_pSceneEditor.get(), EEditMode::Game);
        pSim->SetSimulationMode(Engine::ESimulationMode::Play);
        break;
    }
    case EPlayMode::PhysicsAI:
    {
        if (m_CurrentPlayMode == EPlayMode::Play)
            m_pLevelEditor->OnExitPlayMode();
        pSim->SetSimulationMode(Engine::ESimulationMode::PhysicsAI);
        break;
    }
    }

    m_CurrentPlayMode = playMode;
}

void Main::SceneEditorManager::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
    // Debug print
    if (auto it = g_EventNames.find(event); it != g_EventNames.end())
    {
        CryLog("SceneEditorManager: {} {} {}", it->second, wparam, lparam);
    }

    switch (event)
    {
    case ESYSTEM_EVENT_LEVEL_LOAD_PREPARE:
    {
        // Increment counter so the mouse is not stuck in the loading screen
        m_LoadingMouseGuard.SetIncremented(true);
        break;
    }
    case ESYSTEM_EVENT_LEVEL_LOAD_END:
    {
        m_LoadingMouseGuard.SetIncremented(false);
        OnLevelLoad();
        break;
    }
    case ESYSTEM_EVENT_LEVEL_UNLOAD:
    {
        Reset();
        break;
    }
    case ESYSTEM_EVENT_LEVEL_LOAD_ERROR:
    {
        m_NextLoadIsInEditor = false;
        break;
    }
    }
}

void Main::SceneEditorManager::MapEditCmd(IConsoleCmdArgs* pArgs)
{
    auto pThis = static_cast<SceneEditorManager*>(gPreditor->pSceneEditorManager);
    std::string mapCmd = "map";

    for (int i = 1; i < pArgs->GetArgCount(); i++)
    {
        mapCmd.append(" ");
        mapCmd.append(pArgs->GetArg(i));
    }

    pThis->m_NextLoadIsInEditor = true;
    gEnv->pConsole->ExecuteString(mapCmd.c_str());
}

void Main::SceneEditorManager::Reset()
{
    SetEditor(nullptr, EEditMode::None);
    m_CurrentPlayMode = EPlayMode::Edit; // default value

    assert(!m_pCurrentEditor);
    assert(m_CurrentMode == EEditMode::None);

    m_pSceneEditor = nullptr;
    m_pLevelEditor = nullptr;
    m_NextLoadIsInEditor = false;
}

void Main::SceneEditorManager::OnLevelLoad()
{
    assert(!m_pCurrentEditor);
    assert(m_CurrentMode == EEditMode::None);

    if (m_NextLoadIsInEditor)
    {
        m_pLevelEditor = ILevelSceneEditor::CreateLevelEditor();
        SetEditor(m_pLevelEditor.get(), EEditMode::Level);

        // Pause the engine
        gPreditor->pEngine->GetSimController()->SetSimulationMode(Engine::ESimulationMode::Pause);
    }
    else
    {
        m_pSceneEditor = ISceneEditor::CreateGameEditor();
        SetEditor(m_pSceneEditor.get(), EEditMode::Game);
    }
}

void Main::SceneEditorManager::SetEditor(ISceneEditor* pEditor, EEditMode editMode)
{
    assert((pEditor && editMode != EEditMode::None) || 
          (!pEditor && editMode == EEditMode::None));

    if (m_pCurrentEditor == pEditor)
        return;

    if (m_pCurrentEditor)
        m_pCurrentEditor->OnDisabled();

    m_pCurrentEditor = pEditor;
    m_CurrentMode = editMode;

    if (pEditor)
        pEditor->OnEnabled();

    CryLog("Set editor {}", (int)editMode);
}
