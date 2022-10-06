#include "App/Application.h"
#include "MainConfig.h"
#include "GameModule.h"

struct IGameStartup;
class LoadGameStage;
class TestStage;
class DevConsoleDialog;

class ModToolKit : public Application
{
public:
	static ModToolKit* Get() { return static_cast<ModToolKit*>(Application::Get()); }

	ModToolKit();
	~ModToolKit();

	MainConfig GetConfig() { return m_Config; }

protected:
	void Update() override;
	void ShowUI() override;

private:
	MainConfig m_Config;
	GameModule m_GameModule;
	std::unique_ptr<DevConsoleDialog> m_pDevConsole;

	std::unique_ptr<LoadGameStage> m_pLoadGameStage;
	std::unique_ptr<TestStage> m_pTestStage;
};
