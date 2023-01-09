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

    // STAGES
    std::unique_ptr<ConfigValidationStage> m_ConfigValidateStage;
	std::unique_ptr<ProjectSelectStage> m_pProjectSelectStage;
	std::unique_ptr<LoadGameStage> m_pLoadGameStage;
	std::unique_ptr<ProjectStage> m_pProjectStage;
};
