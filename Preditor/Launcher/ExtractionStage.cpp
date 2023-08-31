#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CrySystem/ZipDirStructures.h>
#include <Chairloader/ChairXmlUtils.h>
#include <Manager/PreditorFiles.h>
#include <mem.h>
#include "ExtractionStage.h"
#include "PreditorApp.h"

static_assert(sizeof(ZipDir::CZipFile) == 64);
static_assert(sizeof(ZipDir::DirHeader) == 4);
static_assert(sizeof(ZipDir::FileEntry) == 48);

namespace
{

//! The rate at which future is checked for updates.
constexpr int WAIT_FOR_FUTURE_FPS = 30;

// _smart_ptr<Cache> TCryArchive<Cache>::m_pCache
constexpr size_t TCRYARCHIVE_CACHE_OFFSET = 16;

// ZipDir::DirHeader* ZipDir::Cache::m_pRootData
constexpr size_t ZIPDIR_CACHE_ROOT_OFFSET = 2704;

//! The exception thrown when the user cancels the operation.
class CancelledException : public std::runtime_error
{
public:
	CancelledException() : std::runtime_error("Operation was cancelled by the user")
	{
	}
};

template <typename T>
static T WaitForFuture(std::future<T>&& future)
{
	PreditorApp::Get()->RefreshUI();

	while (future.wait_for(std::chrono::milliseconds(1000 / WAIT_FOR_FUTURE_FPS)) == std::future_status::timeout)
	{
		PreditorApp::Get()->RefreshUI();
	}

	return future.get();
}

//! TODO: Replace with boost once it's updated.
//! https://github.com/boostorg/core/issues/105
//! Checks if a string starts with a substring.
inline bool startsWith(std::string_view str, std::string_view substr) {
	size_t len = substr.size();
	return str.size() >= len && str.substr(0, len) == substr;
}

//! Checks if a string ends with a substring.
inline bool endsWith(std::string_view str, std::string_view substr) {
	size_t len = substr.size();
	return str.size() >= len && str.substr(str.size() - len, len) == substr;
}

} // namespace

ExtractionStage::ExtractionStage(ExtractionOptions& opts)
	: m_Opts(opts)
{
}

void ExtractionStage::Start()
{
	try
	{
		m_CurrentPakName = "Loading extract list...";
		PreditorApp::Get()->RefreshUI();
		LoadExtractList();

		pugi::xml_node root = m_ExtractList.child("ExtractList");
		for (pugi::xml_node node : root.children())
		{
			if (!node.attribute("dbg:ignore").as_bool())
			{
				std::string path = node.attribute("path").as_string();
				if (path.empty())
					throw std::runtime_error(fmt::format("Pak #{}: empty path", m_CurrentPakIndex));

				m_CurrentPakName = path;
				ExtractPak(node);
			}

			m_CurrentPakIndex++;
		}

		// Create the file to mark data as successfully extracted
		std::ofstream markFile(m_Opts.outputPath / PREDITOR_FILES_EXTRACTED);

		m_State = EState::Done;
		SetStageFinished(nullptr);
	}
	catch (const CancelledException& e)
	{
		m_State = EState::Error;
		m_ErrorText = "cancelled by the user";
	}
	catch (const std::exception& e)
	{
		m_State = EState::Error;
		m_ErrorText = e.what();
	}
}

void ExtractionStage::Update()
{
	// All logic is in Start(). It periodically refreshes the UI.
}

void ExtractionStage::ShowUI(bool* bOpen)
{
	int flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
	
	const char* title = "Extracting...###ExtractionStage";
	if (m_State == EState::Done)
		title = "Extraction Finished###ExtractionStage";
	else if (m_State == EState::Error)
		title = "Extraction Failed###ExtractionStage";

	float fontSize = ImGui::GetFontSize();
	ImGui::SetNextWindowSize(ImVec2(36 * fontSize, 12 * fontSize));

	if (ImGui::Begin(title, nullptr, flags))
	{
		std::string currentFileName;
		int currentFileIndex = 0, totalFileCount = 0;
		
		{
			std::scoped_lock lock(m_AsyncMutex);
			currentFileName = m_CurrentFileName;
			currentFileIndex = m_CurrentFileIndex;
			totalFileCount = m_TotalFileCount;
		}

		// Clamp so the UI doesn't show "11/10" when done.
		int processedPakIndex = std::clamp(m_CurrentPakIndex + 1, 1, m_TotalPakCount);
		int processedFileIndex = std::clamp(currentFileIndex + 1, 1, totalFileCount);

		if (m_TotalPakCount != 0)
		{
			ImGui::Text("%s (%d/%d)", m_CurrentPakName.c_str(), processedPakIndex, m_TotalPakCount);
			ImGui::ProgressBar((float)m_CurrentPakIndex / m_TotalPakCount);
		}
		else
		{
			ImGui::Text("%s", m_CurrentPakName.c_str());
			ImGui::ProgressBar(0);
		}

		if (m_TotalFileCount != 0)
		{
			ImGui::Text("%s (%d/%d)", currentFileName.c_str(), processedFileIndex, totalFileCount);
			ImGui::ProgressBar((float)currentFileIndex / totalFileCount);
		}
		else
		{
			ImGui::Text("%s", currentFileName.c_str());
			ImGui::ProgressBar(0);
		}

		if (!m_ErrorText.empty())
			ImGui::TextColored(ImColor(255, 0, 0), "Error: %s", m_ErrorText.c_str());
		else
			ImGui::NewLine();

		if (m_State == EState::Done || m_State == EState::Error)
		{
			if (ImGui::Button("Close"))
			{
				// Exit
				SetStageFinished(nullptr);
			}
		}
		else
		{
			ImGui::BeginDisabled(m_bIsPendingCancel);
			if (ImGui::Button("Cancel"))
			{
				Cancel();
			}
			ImGui::EndDisabled();
		}
	}
	ImGui::End();
}

void ExtractionStage::Cancel()
{
	if (m_bIsPendingCancel)
		return;

	m_bIsPendingCancel = true;
	m_bCancelRequested = true;
}

void ExtractionStage::LoadExtractList()
{
	fs::path path = PreditorApp::Get()->GetProgramPath() / "Preditor/ExtractList.xml";
	pugi::xml_parse_result result = m_ExtractList.load_file(path.c_str());

	if (!result)
		throw std::runtime_error(fmt::format("Failed to load XML: {}", result.description()));

	pugi::xml_node root = m_ExtractList.child("ExtractList");
	m_TotalPakCount = 0;
	
	for (pugi::xml_node node : root.children())
	{
		if (strcmp(node.name(), "Pak"))
			throw std::runtime_error(fmt::format("Unknown XML tag '{}'", node.name()));
		m_TotalPakCount++;
	}
}

void ExtractionStage::ExtractPak(const pugi::xml_node node)
{
	// Open the archive
	std::string relativePath = node.attribute("path").as_string();
	fs::path fullPath = m_Opts.gamePath / "GameSDK" / fs::u8path(relativePath);

	uint32 flags =
		ICryArchive::FLAGS_RELATIVE_PATHS_ONLY |
		ICryArchive::FLAGS_OPTIMIZED_READ_ONLY | // Required for encrypted paks
		ICryArchive::FLAGS_IN_MEMORY_CPU;
	_smart_ptr<ICryArchive> pPak = gEnv->pCryPak->OpenArchive(fullPath.u8string().c_str(), flags);

	if (!pPak)
		throw std::runtime_error("Failed to open the pak file");

	WaitForFuture(std::async(std::launch::async, [this, node, &pPak]()
		{
			// Update progress
			{
				std::scoped_lock lock(m_AsyncMutex);
				m_CurrentFileName = "Building file list...";
				m_CurrentFileIndex = 0;
				m_TotalFileCount = 0;
			}

			// Get the pointer to root DirHeader
			auto pCache = mem::OffsetInStruct<void*>(pPak.get(), TCRYARCHIVE_CACHE_OFFSET);
			auto pRootDir = mem::OffsetInStruct<ZipDir::DirHeader*>(pCache, ZIPDIR_CACHE_ROOT_OFFSET);

			// Map of all files in the pak to their handles
			FileMap allFiles;
			FillFileList(pRootDir, "", allFiles);
			ThrowIfCancelling();

			// Check if the pak was touched by Chairloader
			if (allFiles.find(MARK_OF_THE_CHAIR) != allFiles.end())
				throw std::runtime_error("pak was modified by Chairloader. Validate game files.");

			FileMap filesToExtract = FilterFiles(node, allFiles);
			ThrowIfCancelling();

			if (filesToExtract.empty())
				throw std::runtime_error("No valid files found in the pak");

			// Pre-allocate the buffer outside the loop
			std::vector<uint8_t> fileBuf;
			fileBuf.reserve(FILE_BUFFER_SIZE);

			// Chairloader is not loaded in this stage, instantiate XmlUtils directly.
			ChairXmlUtils xmlUtils;
			IChairXmlUtils* pXmlUtils = &xmlUtils; // FIXME: Overloads from the interface are not accessible from derived class. Add `using` to the class.

			// Set the output root path
			fs::path outputRootPath = m_Opts.outputPath;

			if (node.attribute("root"))
			{
				// Append the additional root path
				outputRootPath /= fs::u8path(node.attribute("root").as_string());
			}

			if (node.attribute("levelPak").as_bool())
			{
				// Append the pak name without extension
				fs::path pakPath = fs::u8path(node.attribute("path").as_string());
				outputRootPath /= pakPath.parent_path() / pakPath.stem();
			}

			// Extract the files
			int currentFileIndex = 0;
			for (const auto& [filePath, hFile] : filesToExtract)
			{
				// Update progress
				{
					std::scoped_lock lock(m_AsyncMutex);
					m_CurrentFileName = filePath;
					m_CurrentFileIndex = currentFileIndex;
					m_TotalFileCount = filesToExtract.size();
				}

				ThrowIfCancelling();

				// Create the output file
				fs::path outputPath = outputRootPath / fs::u8path(filePath);
				fs::create_directories(outputPath.parent_path());

				std::ofstream outputFile;
				outputFile.exceptions(std::ios::failbit | std::ios::badbit);
				outputFile.open(outputPath, std::ios::binary);

				// Read data into RAM
				uint32_t fileSize = pPak->GetFileSize(hFile);
				fileBuf.resize(fileSize);
				pPak->ReadFile(hFile, fileBuf.data());

				// See if this is a binary XML file
				if (pXmlUtils->IsBinaryXml(fileBuf))
				{
					pugi::xml_parse_result result;
					pugi::xml_document xmlDoc = pXmlUtils->LoadXmlFromBuffer(fileBuf, &result);

					if (result)
					{
						unsigned formatFlags = pugi::format_indent | pugi::format_indent_attributes;
						xmlDoc.save(outputFile, "    ", formatFlags);
					}
					else
					{
						throw std::runtime_error("Failed to load Binary XML");
					}
				}
				else
				{
					// Write as-is
					outputFile.write((const char*)fileBuf.data(), fileBuf.size());
				}

				currentFileIndex++;
			}
		}));
}

void ExtractionStage::FillFileList(const ZipDir::DirHeader* pDir, const std::string& dirPath, FileMap& files)
{
	const char* pNamePool = pDir->GetNamePool();

	// Files
	for (int i = 0; i < pDir->numFiles; i++)
	{
		const ZipDir::FileEntry* pFileEntry = pDir->GetFileEntry(i);
		const char* pFileName = pFileEntry->GetName(pNamePool);
		files.insert({ dirPath + pFileName, (ICryArchive::Handle)pFileEntry });
	}

	// Directories
	for (int i = 0; i < pDir->numDirs; i++)
	{
		const ZipDir::DirEntry* pSubdirEntry = pDir->GetSubdirEntry(i);
		const char* pSubdirName = pSubdirEntry->GetName(pNamePool);
		FillFileList(pSubdirEntry->GetDirectory(), dirPath + pSubdirName + "/", files);
	}
}

ExtractionStage::FileMap ExtractionStage::FilterFiles(const pugi::xml_node node, const FileMap& allFiles)
{
	// List of files that need to be extracted
	FileMap filesToExtract;

	for (pugi::xml_node i : node.children())
	{
		if (!strcmp(i.name(), "AddPrefix"))
		{
			// Add all files that begin with the prefix
			std::string prefix = i.text().as_string();

			if (prefix.empty() && filesToExtract.empty())
			{
				// Shortcut for empty AddPrefix nodes.
				filesToExtract = allFiles;
			}
			else
			{
				for (const auto& file : allFiles)
				{
					if (startsWith(file.first, prefix))
						filesToExtract.insert(file);
				}
			}
		}
		else if (!strcmp(i.name(), "IgnoreSuffix"))
		{
			// Remove all files that end with the suffix
			std::string suffix = i.text().as_string();
			auto it = filesToExtract.begin();

			while (it != filesToExtract.end())
			{
				if (endsWith(it->first, suffix))
				{
					// Remove the element
					it = filesToExtract.erase(it);
				}
				else
				{
					// Go to the next element
					++it;
				}
			}
		}
		else
		{
			throw std::logic_error(fmt::format("Unknown instruction node: {}", i.name()));
		}
	}

	return filesToExtract;
}

void ExtractionStage::ThrowIfCancelling()
{
	if (m_bCancelRequested)
		throw CancelledException();
}
