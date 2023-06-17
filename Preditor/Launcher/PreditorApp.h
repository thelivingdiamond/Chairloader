#pragma once
#include "App/Application.h"
#include "ProjectSelectStage.h"
#include "ProjectStage.h"
#include "ConfigValidationStage.h"

struct IGameStartup;
struct ExtractionOptions;
class LoadGameStage;
class DevConsoleDialog;

class PreditorApp : public Application
{
public:
	static PreditorApp* Get() { return static_cast<PreditorApp*>(Application::Get()); }

	PreditorApp();
	~PreditorApp();

	PreditorPaths& GetPahts() { return m_Paths; }

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
	PreditorPaths m_Paths;
	std::unique_ptr<PreditorConfig> m_pConfig;
	std::unique_ptr<ExtractionOptions> m_pExtractionOptions;

	void ParseCommandLine();
};
