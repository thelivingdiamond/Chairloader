#include <Preditor/SceneEditor/ISceneEditor.h>
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

    Reset();
}

Main::SceneEditorManager::~SceneEditorManager()
{
    gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);
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
    case ESYSTEM_EVENT_LEVEL_LOAD_END:
    {
        OnLevelLoad();
        break;
    }
    case ESYSTEM_EVENT_LEVEL_UNLOAD:
    {
        Reset();
        break;
    }
    }
}

void Main::SceneEditorManager::Reset()
{
    SetEditor(nullptr, EEditMode::None);
    m_CurrentPlayMode = EPlayMode::Edit; // default value

    assert(!m_pCurrentEditor);
    assert(m_CurrentMode == EEditMode::None);

    m_pSceneEditor = nullptr;
    m_pLevelEditor = nullptr;
}

void Main::SceneEditorManager::OnLevelLoad()
{
    // TODO 2023-06-17: Level editing
    assert(!m_pCurrentEditor);
    assert(m_CurrentMode == EEditMode::None);

    m_pSceneEditor = ISceneEditor::CreateGameEditor();
    SetEditor(m_pSceneEditor.get(), EEditMode::Game);
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