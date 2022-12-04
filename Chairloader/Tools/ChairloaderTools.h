#pragma once
#include <Chairloader/IChairloaderTools.h>

class DevConsoleDialog;
class FileBrowser;
class PerfOverlay;

class EntityManager;
class PlayerManager;
class WorldManager;

class Editor;

class ChairloaderTools : public Internal::IChairloaderTools
{
public:
	void InitSystem(const Internal::SToolsInitParams& params) override;
	void InitGame() override;
	void UpdateBeforeSystem(unsigned updateFlags) override;
	void MainUpdate(unsigned updateFlags) override;
	bool HandleKeyPress(const SInputEvent& event) override;
	void ShowMainMenuItems() override;

private:
	// Dev tools
	bool m_bDrawDevConsole = false;
	std::unique_ptr<DevConsoleDialog> m_pDevConsole;
	std::unique_ptr<FileBrowser> m_pFileBrowser;
	std::unique_ptr<PerfOverlay> m_pPerfOverlay;

	// Trainer
	bool m_bEnableTrainer = false;
	std::unique_ptr<EntityManager> m_pEntityManager;
	std::unique_ptr<PlayerManager> m_pPlayerManager;
	std::unique_ptr<WorldManager> m_pWorldManager;

	// Editor
	bool m_bEnableEditor = false;
	std::unique_ptr<Editor> m_pEditor;

	void ShowMainMenuBar();
};
