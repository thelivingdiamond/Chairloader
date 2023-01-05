#include "ChairloaderToolsPreditor.h"
#include "DevConsoleDialog.h"
#include "FileBrowser.h"
#include "ChairToolsUtils.h"

std::unique_ptr<IChairloaderToolsPreditor> IChairloaderToolsPreditor::CreateInstance(IChairToPreditor* pChair)
{
	return std::make_unique<ChairloaderToolsPreditor>(pChair);
}

ChairloaderToolsPreditor::ChairloaderToolsPreditor(IChairToPreditor* pChair)
{
	ChairToolsUtils::SetIChairToPreditor(pChair);
	m_pDevConsole = std::make_unique<DevConsoleDialog>();
	m_pFileBrowser = std::make_unique<FileBrowser>();
}

void ChairloaderToolsPreditor::Update()
{
	if (m_bDrawDevConsole)
		m_pDevConsole->Show(&m_bDrawDevConsole);

	m_pFileBrowser->Draw();
}

void ChairloaderToolsPreditor::ShowWindowMenu()
{
	ImGui::MenuItem("Developer Console", nullptr, &m_bDrawDevConsole);
}
