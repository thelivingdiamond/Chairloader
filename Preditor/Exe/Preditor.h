#pragma once
#include <Preditor/Project/ProjectManager.h>
#include "App/Application.h"
#include "ConfigManager.h"
#include "FlowgraphEditor.h"
#include "ProjectSelectStage.h"
#include "ProjectStage.h"
#include "ConfigValidationStage.h"
#include "LookingGlass.h"

struct IGameStartup;
class LoadGameStage;
class DevConsoleDialog;

class Preditor : public Application
{
public:
	static Preditor* Get() { return static_cast<Preditor*>(Application::Get()); }

	Preditor();
	~Preditor();

	ConfigManager GetConfig() { return m_Config; }

	//! Called after the config is validated.
	void OnConfigValidated();

	//! Called after the engine is successfully loaded.
	//! @returns the next stage.
	AppStagePtr OnGameLoaded();

protected:
	void Update() override;
	void ShowUI(bool* bOpen) override;
	void PostUpdate() override;

private:
	ConfigManager m_Config;

    // MODULES
	//std::unique_ptr<DevConsoleDialog> m_pDevConsole;
    std::unique_ptr<ProjectManager> m_pProjectManager;
    std::unique_ptr<LookingGlass> m_pLookingGlass;
};
