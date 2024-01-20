#include <Prey/CryAction/LevelSystem.h>
#include <Prey/CryEntitySystem/EntitySystem.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include <Preditor/SceneEditor/ILevelSceneEditor.h>
#include "LevelEditorPatch.h"

static auto g_CLevelSystem_LoadLevel_Hook = CLevelSystem::FLoadLevel.MakeHook();
static auto g_CEntitySystem_LoadEntities_Hook = CEntitySystem::FLoadEntitiesOv1.MakeHook();

static ILevel* CLevelSystem_LoadLevel_Hook(CLevelSystem* const _this, const char* _levelName)
{
    gPreditor->pSceneEditorManager->OnLevelLoad();
    return g_CLevelSystem_LoadLevel_Hook.InvokeOrig(_this, _levelName);
}

static void CEntitySystem_LoadEntities_Hook(CEntitySystem* const _this, XmlNodeRef& objectsNode, bool bIsLoadingLevelFile)
{
    if (gPreditor->pSceneEditorManager->IsLevelEditorLoaded())
    {
        // Level editor will load the entities
        assert(bIsLoadingLevelFile);
        auto* pLevelEditor = static_cast<ILevelSceneEditor*>(gPreditor->pSceneEditorManager->GetEditor());
        pLevelEditor->LoadEntities();
    }
    else
    {
        // Normal loading
        g_CEntitySystem_LoadEntities_Hook.InvokeOrig(_this, objectsNode, bIsLoadingLevelFile);
    }
}

void Engine::LevelEditorPatch::InitHooks()
{
    g_CLevelSystem_LoadLevel_Hook.SetHookFunc(&CLevelSystem_LoadLevel_Hook);
    g_CEntitySystem_LoadEntities_Hook.SetHookFunc(&CEntitySystem_LoadEntities_Hook);
}
