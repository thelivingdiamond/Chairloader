#pragma once
#include <Preditor/IChairloaderToolsPreditor.h>

class DevConsoleDialog;
class FileBrowser;

class ChairloaderToolsPreditor : public IChairloaderToolsPreditor
{
public:
	ChairloaderToolsPreditor(IChairToPreditor* pChair);

	// IChairloaderToolsPreditor
	void Update() override;
	void ShowWindowMenu() override;

private:
	bool m_bDrawDevConsole = true;
	std::unique_ptr<DevConsoleDialog> m_pDevConsole;
	std::unique_ptr<FileBrowser> m_pFileBrowser;
};
