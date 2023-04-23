#pragma once
#include <Preditor/Project/ProjectManager.h>
#include "App/Application.h"
#include "ProjectSelectStage.h"
#include "ProjectStage.h"
#include "ConfigValidationStage.h"

struct IGameStartup;
struct ExtractionOptions;
class LoadGameStage;
class DevConsoleDialog;

class Preditor : public Application
{
public:
	static Preditor* Get() { return static_cast<Preditor*>(Application::Get()); }

	Preditor();
	~Preditor();

	//! Called after the config is validated.
	void OnConfigValidated(std::unique_ptr<PreditorConfig>&& pConfig);

	//! Called after the engine is successfully loaded.
	//! @returns the next stage.
	AppStagePtr OnGameLoaded();

protected:
	void Update() override;
	void ShowUI(bool* bOpen) override;
	void PostUpdate() override;

private:
	std::unique_ptr<PreditorConfig> m_pConfig;
	std::unique_ptr<ExtractionOptions> m_pExtractionOptions;

    // MODULES
    std::unique_ptr<ProjectManager> m_pProjectManager;

	void ParseCommandLine();
};
