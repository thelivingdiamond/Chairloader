#include "ChairloaderToolsPreditor.h"
#include "DevConsoleDialog.h"
#include "FileBrowser.h"
#include "ChairToolsUtils.h"
#include "DebugMenu.h"
#include "Chairloader/IChairloaderDll.h"
#include "Chairloader/IModDllManager.h"
#include "Chairloader/ILogManager.h"
#include "Chairloader/IChairServiceProvider.h"
#include "Chairloader/IChairToPreditor.h"
#include "Editor/ModReloading.h"

std::unique_ptr<IChairloaderToolsPreditor> IChairloaderToolsPreditor::CreateInstance(IChairToPreditor* pChair)
{
	return std::make_unique<ChairloaderToolsPreditor>(pChair);
}

ChairloaderToolsPreditor::ChairloaderToolsPreditor(IChairToPreditor* pChair)
{
	ChairToolsUtils::SetIChairToPreditor(pChair);
	//TODO: do proper service environment for preditor
	m_pModReloading = std::make_unique<ModReloading>(pChair->GetIChairloaderDll()->GetChairloaderEnvironment()->pServiceProvider->GetRequiredService<Internal::IModDllManager>());
	m_pDevConsole = std::make_unique<DevConsoleDialog>(pChair->GetIChairloaderDll()->GetChairloaderEnvironment()->pServiceProvider->GetRequiredService<Internal::ILogManager>());
	m_pFileBrowser = std::make_unique<FileBrowser>();
	m_pDebugMenu = std::make_unique<DebugMenu>();
}

void ChairloaderToolsPreditor::Update()
{
	m_pModReloading->UpdateBeforeSystem();

	if (m_bDrawDevConsole)
		m_pDevConsole->Show(&m_bDrawDevConsole);

	m_pFileBrowser->Draw();
	m_pDebugMenu->ShowMenu();
}

void ChairloaderToolsPreditor::ShowWindowMenu()
{
	ImGui::MenuItem("Developer Console", nullptr, &m_bDrawDevConsole);
}

void ChairloaderToolsPreditor::CheckModulesForChanges()
{
	m_pModReloading->CheckModulesForChanges();
}

void ChairloaderToolsPreditor::ReloadMods()
{
	m_pModReloading->ReloadMods();
}

bool ChairloaderToolsPreditor::ReloadLevel()
{
	return m_pModReloading->ReloadLevel();
}
