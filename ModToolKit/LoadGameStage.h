#pragma once
#include "App/AppStage.h"

struct GameModule;
struct IGameStartup;

class LoadGameStage : AppStage
{
public:
	LoadGameStage(GameModule* pModule, ISystemUserCallback* pSystemUserCallback);
	void Start() override;
	void ShowUI(bool *bOpen) override;
	void UpdateProgressText(const std::string& text);

	IGameStartup* GetIGameStartup() { return m_pGameStartup; }

private:
	//! Progress bar is a lie, I can't know for sure how many stages there are in CrySystem.
	static constexpr int MAX_PROGRESS = 17;
	
	GameModule* m_pMod = nullptr;
	ISystemUserCallback* m_pSystemUserCallback = nullptr;
	IGameStartup* m_pGameStartup = nullptr;

	std::string m_ProgressText;
	std::string m_ErrorText;
	int m_ProgressCount = 0;

	void LoadDLL();
	void InitGame();
};
