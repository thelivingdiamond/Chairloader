#pragma once

class AppStage;
using AppStagePtr = std::unique_ptr<AppStage>;

//! Base class for Application Stages.
//! They represent different states the app can be in (e.g. different dialogs).
//! Only one stage can be active at a time. The active stage is owned by Application instance.
//! Stages are switched using SetStageFinished on the current stage.
class AppStage
{
public:
	AppStage();
	virtual ~AppStage();

	//! @returns whether the stage is finished and requests a switch to a different stage.
	bool IsStageFinished() const { return m_bIsFinished; }

	//! Requests the stage to be switched to a different one.
	//! @param	pNextStage	The next stage. If null, app will exit.
	void SetStageFinished(AppStagePtr&& pNextStage);

	//! Starts the stage. Called just before the first update.
	virtual void Start();

	//! Updates the stage. Called every frame.
	virtual void Update();

	//! Shows the stage's ImGui IU. Called after Update().
	virtual void ShowUI(bool *bOpen);

private:
	bool m_bIsStarted = false;
	bool m_bIsFinished = false;
	AppStagePtr m_pNextStage;

	void UpdateInternal();

	friend class Application;
};
