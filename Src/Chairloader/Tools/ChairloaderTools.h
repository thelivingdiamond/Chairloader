#pragma once
#include <Chairloader/IChairloaderTools.h>

namespace Internal {
	struct IModDllManager;
	struct ILogManager;
}

class DevConsoleDialog;
class FileBrowser;
class PerfOverlay;
class LocalizationUtil;
class DebugMenu;

class EntityManager;
class PlayerManager;
class WorldManager;
class SignalSystemManager;

class Editor;

class ChairloaderTools : public Internal::IChairloaderTools
{
public:
	ChairloaderTools(std::shared_ptr<IChairloaderConfigManager> configManager, std::shared_ptr<Internal::ILogManager> logManager, std::shared_ptr<Internal::IModDllManager> modDllManager);

	void InitSystem(const Internal::SToolsInitParams& params) override;
	void InitGame() override;
	void UpdateBeforeSystem(unsigned updateFlags) override;
	void MainUpdate(unsigned updateFlags) override;
	bool HandleKeyPress(const SInputEvent& event) override;
	void ShowMainMenuItems() override;

private:
	std::shared_ptr<IChairloaderConfigManager> m_pConfigManager;
	std::shared_ptr<Internal::ILogManager> m_pLogManager;
	std::shared_ptr<Internal::IModDllManager> m_pModDllManager;

	// Dev tools
	bool m_bDrawDevConsole = false;
    EKeyId m_KeyToggleConsole = eKI_Unknown;
	std::unique_ptr<DevConsoleDialog> m_pDevConsole;
	std::unique_ptr<FileBrowser> m_pFileBrowser;
	std::unique_ptr<PerfOverlay> m_pPerfOverlay;
	std::unique_ptr<DebugMenu> m_pDebugMenu;

	// Trainer
	bool m_bEnableTrainer = false;
	std::unique_ptr<EntityManager> m_pEntityManager;
	std::unique_ptr<PlayerManager> m_pPlayerManager;
	std::unique_ptr<WorldManager> m_pWorldManager;
    std::unique_ptr<SignalSystemManager> m_pSignalSystemManager;

	// Editor
	bool m_bEnableEditor = false;
	std::unique_ptr<Editor> m_pEditor;

    // Localization
    std::unique_ptr<LocalizationUtil> m_pLocalizationUtil;

	void ShowMainMenuBar();
};
