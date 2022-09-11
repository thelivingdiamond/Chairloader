#pragma once

//! Base class for Application Stages.
//! They represent different states the app can be in (e.g. different dialogs).
//! Only one stage can be active at a time.
//! Stages call SetStage in the app automatically.
class AppStage
{
public:
	AppStage();
	virtual ~AppStage();

	//! @returns whether the stage is finished and requests a switch to a different stage.
	bool IsStageFinished() const { return m_bIsFinished; }
	void SetStageFinished() { m_bIsFinished = true; }

	//! Starts the stage. Called just before the first update.
	virtual void Start();

	//! Updates the stage. Called every frame.
	virtual void Update();

	//! Shows the stage's ImGui IU. Called after Update().
	virtual void ShowUI();

private:
	bool m_bIsStarted = false;
	bool m_bIsFinished = false;

	void UpdateInternal();

	friend class Application;
};
