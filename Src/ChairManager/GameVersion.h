#pragma once
#include <future>
#include <SHA256/SHA256.h>

class GameVersion
{
public:
	static constexpr char VERSIONS_PATH[] = "Versions";
	static constexpr char XML_NAME[] = "Versions.xml";
	static constexpr char DIFF_EXT[] = ".diff.gz";

	enum class Result
	{
		Loading,
		Supported,
		Patchable,
		NotSupported,
		UnknownVersion,
		Error,
	};

	GameVersion();
	~GameVersion();

	Result GetResult() const { return m_Result; }
	void Update();
	Result ShowInstalledVersion(bool showBtns = true);
	const std::string& GetErrorText() { return m_ErrorText; }
	void PatchTheGame() const;
	void CheckAgain() { StartAsyncTasks(); }

private:
	enum class State
	{
		Error,
		WaitTasks,
		Ready,
	};

	struct KnownVersion
	{
		SHA256::Digest sha256;
		std::string type;
		std::string releaseDate;
		bool isSupported = false;
		bool isOutdated = false;
	};

	struct HashGameResult
	{
		SHA256::Digest installedGameHash = {};
	};

	std::map<SHA256::Digest, KnownVersion> m_KnownVersions; // Must only be updated along with m_pSupportedVersion
	KnownVersion* m_pSupportedVersion = nullptr;
	KnownVersion* m_pInstalledVersion = nullptr;
	bool m_bHasBackup = false;
	Result m_Result = Result::Loading;

	State m_State = State::Error;
	std::future<HashGameResult> m_HashGameTaskFuture;
	std::string m_ErrorText;

	std::string m_ModalErrorText;

	void LoadKnownVersions();
	void StartAsyncTasks();
	void ShowModals();
	void RestoreBackup();

	//! Async task to hash the game.
	HashGameResult HashGameTask();
};
