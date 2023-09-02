#pragma once
#include <Prey/CrySystem/File/ICryPak.h>
#include <App/AppStage.h>
#include "ExtractionOptions.h"

namespace ZipDir
{
struct DirHeader;
}

class ExtractionStage : public AppStage
{
public:
	ExtractionStage(ExtractionOptions& opts);
	virtual void Start() override;
	virtual void Update() override;
	virtual void ShowUI(bool* bOpen) override;

private:
	//! Size of the buffer for file extraction.
	static constexpr size_t FILE_BUFFER_SIZE = 16 * 1024 * 1024;

	//! Maps file path to its handle;
	using FileMap = std::map<std::string, ICryArchive::Handle>;

	enum class EState
	{
		None,
		ExtractingPak,
		Done,
		Error,
	};

	ExtractionOptions& m_Opts;
	EState m_State = EState::None;
	bool m_bIsPendingCancel = false;

	pugi::xml_document m_ExtractList;

	// UI variables
	std::string m_CurrentPakName;
	int m_CurrentPakIndex = 0;
	int m_TotalPakCount = 0;
	std::string m_ErrorText;

	// Async variables. Set in the worker, read in the UI.
	std::atomic_bool m_bCancelRequested = false;
	std::mutex m_AsyncMutex;
	std::string m_CurrentFileName;
	int m_CurrentFileIndex = 0;
	int m_TotalFileCount = 0;

	//! Cancels the extraction process. After fully cancelled, exits.
	void Cancel();

	//! Loads ExtractList.xml into m_ExtractList.
	void LoadExtractList();

	//! Extracts the contents of a pak to the output.
	//! @param	node	XML node from the extract list.
	void ExtractPak(const pugi::xml_node node);

	//! Fills `files` with all files in a directory recursively.
	//! @param	pDir	Directory header.
	//! @param	dirPath	Current directory path. Ends with a slash unless the root.
	//! @param	files	List of file paths.
	void FillFileList(const ZipDir::DirHeader* pDir, const std::string& dirPath, FileMap& files);

	//! Filters the map of all file as specified in the XML node.
	//! @param	node		Pak XML node.
	//! @param	allFiles	Map of all files in the pak.
	//! @returns map of files that need to be extracted.
	FileMap FilterFiles(const pugi::xml_node node, const FileMap& allFiles);

	//! Checks if the pak file was modded.
	bool IsModdedPak(const fs::path& pakPath);

	//! Throws CancelledException if the user requested cancellation.
	void ThrowIfCancelling();
};
