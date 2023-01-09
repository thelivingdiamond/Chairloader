#pragma once
#include "App/AppStage.h"

class LoadGameStage : AppStage
{
public:
	LoadGameStage();
	void Start() override;
	void ShowUI(bool *bOpen) override;
	void UpdateProgressText(const std::string& text);

private:
	//! Progress bar is a lie, I can't know for sure how many stages there are in CrySystem.
	static constexpr int MAX_PROGRESS = 17;

	std::string m_ProgressText;
	std::string m_ErrorText;
	int m_ProgressCount = 0;
};
