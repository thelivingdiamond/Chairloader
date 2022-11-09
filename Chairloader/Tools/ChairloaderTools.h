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
	void PreUpdate() override;
	bool HandleKeyPress(const SInputEvent& event) override;

private:
	// Dev tools
	bool m_bDrawDevConsole = false;
	bool m_bDrawPerfOverlay = false;
	std::unique_ptr<DevConsoleDialog> m_pDevConsole;
	std::unique_ptr<FileBrowser> m_pFileBrowser;
	std::unique_ptr<PerfOverlay> m_pPerfOverlay;

	// Trainer
	bool m_bEnableTrainer = false;
	bool m_bDrawEntityManager = false;
	bool m_bDrawPlayerManager = false;
	bool m_bDrawWorldManager = false;
	std::unique_ptr<EntityManager> m_pEntityManager;
	std::unique_ptr<PlayerManager> m_pPlayerManager;
	std::unique_ptr<WorldManager> m_pWorldManager;

	// Editor
	bool m_bEnableEditor = false;
	std::unique_ptr<Editor> m_pEditor;
};
