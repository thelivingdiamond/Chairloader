#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryGame/Game.h>
#include <Prey/CryAction/ark/IArkSaveLoadSystem.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderCore.h>
#include <Chairloader/IModDllManager.h>
#include "ModReloading.h"
#include "ChairToolsUtils.h"

ModReloading::ModReloading()
{
	m_pDllManager = ChairToolsUtils::GetDll()->GetCore()->GetDllManager();
}

void ModReloading::UpdateBeforeSystem()
{
	if (m_bPendingReload)
		PerformReload();
}

void ModReloading::CheckModulesForChanges()
{
	if (m_pDllManager->CheckModulesForChanges())
		ReloadMods();
}

void ModReloading::ReloadMods()
{
	m_bPendingReload = true;
}

bool ModReloading::ReloadLevel()
{
	return SaveAndUnloadLevel() && RestoreSavedLevel();
}

bool ModReloading::PerformReload()
{
	if (!m_bPendingReload)
		return false;

	// Check the game is not loading
	if (gEnv->pSystem->GetSystemGlobalState() != ESYSTEM_GLOBAL_STATE_RUNNING)
		return false;

	m_bPendingReload = false;

	CTimeValue startTime = gEnv->pTimer->GetAsyncTime();
	bool needToRestore = false;

	if (gCL->cl->GetFramework()->IsGameStarted())
	{
		if (SaveAndUnloadLevel())
			needToRestore = true;
		else
			return false;
	}

	// ReloadModDLLs can only fail fatally
	ChairToolsUtils::GetDll()->ReloadModDLLs();

	if (needToRestore && !RestoreSavedLevel())
		return false;

	CTimeValue endTime = gEnv->pTimer->GetAsyncTime();
	CryLog("[ModReloading] Reloaded mods in {:.3f} s.", endTime.GetDifferenceInSeconds(startTime));
	return true;
}

bool ModReloading::SaveAndUnloadLevel()
{
	IGameFramework* pGameFw = gCL->cl->GetFramework();
	if (!pGameFw->IsGameStarted())
		return false;

	if (!pGameFw->CanSave())
	{
		CryError("[ModReloading] Can't reload level: can't save at the moment.");
		return false;
	}

	// Make a save
	if (!pGameFw->SaveGame(SAVE_NAME, false, true, eSGR_Command, true))
	{
		CryError("[ModReloading] SaveGame failed.");
		return false;
	}

	// Unload the level
	gEnv->pConsole->ExecuteString("disconnect");
	return true;
}

bool ModReloading::RestoreSavedLevel()
{
	IGameFramework* pGameFw = gCL->cl->GetFramework();

	// Reload the save
	ELoadGameResult loadResult = pGameFw->LoadGame(SAVE_NAME, false, true);

	// Delete the save that was just made
	int curSlot = pGameFw->GetArkSaveLoadSystem().GetCampaignSlot();
	g_pGame->m_pArkGame->DeleteSave(curSlot, SAVE_NAME);

	if (loadResult != eLGR_Ok)
	{
		CryError("[ModReloading] LoadGame failed ({}).", (int)loadResult);
		return false;
	}

	return true;
}
