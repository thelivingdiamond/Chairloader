#include "App/Application.h"
#include "ConfigManager.h"
#include "GameModule.h"
#include "FlowgraphEditor.h"
#include "ProjectManager.h"
#include "ProjectSelectStage.h"
#include "ConfigValidationStage.h"

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

private:
	ConfigManager m_Config;
	GameModule m_GameModule;
	std::unique_ptr<DevConsoleDialog> m_pDevConsole;

    std::unique_ptr<ConfigValidationStage> m_ConfigValidateStage;
	std::unique_ptr<LoadGameStage> m_pLoadGameStage;
    std::unique_ptr<ProjectSelectStage> m_pProjectSelectStage;
};
