#pragma once
#include <Preditor/IChairloaderToolsPreditor.h>

class DevConsoleDialog;
class FileBrowser;
class ModReloading;

class ChairloaderToolsPreditor : public IChairloaderToolsPreditor
{
public:
	ChairloaderToolsPreditor(IChairToPreditor* pChair);

	// IChairloaderToolsPreditor
	void Update() override;
	void ShowWindowMenu() override;
	void CheckModulesForChanges() override;
	void ReloadMods() override;
	bool ReloadLevel() override;

private:
	std::unique_ptr<ModReloading> m_pModReloading;

	bool m_bDrawDevConsole = true;
	std::unique_ptr<DevConsoleDialog> m_pDevConsole;
	std::unique_ptr<FileBrowser> m_pFileBrowser;
};
