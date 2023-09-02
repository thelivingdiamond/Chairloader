#pragma once

class GameVersion;

class ChairInstallWizard
{
public:
	//! Shows the wizard dialog.
	//! @returns true if installation has succeded.
	bool Show(const char* name, bool* pbIsOpen);

private:
	enum class State
	{
		Error,
		Welcome,
		VersionCheck,
		VerifyFilesWarning,
		Confirm,
		Progress,
		Extract,
		Finish,
	};

	using BtnCallback = std::function<void()>;

	State m_State = State::Welcome;
	bool m_Cancel = false;
	bool m_SuccessFinish = false;

	// State::Error
	std::string m_ErrorText;

	// State::VersionCheck
	std::unique_ptr<GameVersion> m_pGameVersion;
	bool m_bNeedDllPatch = false;

	// State::Progress
	std::future<void> m_InstallFuture;
	mutable std::list<std::string> m_InstallLog; // Updated in install task, read in ShowProgressPage
	mutable std::mutex m_InstallLogMutex;
	bool m_bIsInstallFinished = false;

	std::future<void> m_ExtractFuture;
	bool m_bIsExtractFinished = false;

	void ShowErrorPage();
	void ShowWelcomePage();
	void ShowVersionCheckPage();
	void ShowVerifyFilesWarningPage();
	void ShowConfirmPage();
	void ShowProgressPage();
	void ShowExtractPage();
	void ShowFinishPage();

	void ToVersionCheck();
	void StartInstall();
	void StartExtract();
	void SetError(const std::string& text);

	float GetButtonRowHeight();
	void ShowBottomBtns(BtnCallback&& back, BtnCallback&& next, BtnCallback&& cancel, bool isFinish = false);
	void ShowPatchWarning(bool isFinal);

	void InstallAsyncTask() const;
	void ExtractAsyncTask() const;
};
