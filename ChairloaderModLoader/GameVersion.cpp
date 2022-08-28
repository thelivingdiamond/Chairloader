#include <zlib.h>
#include <ModLoader/BinDiff.h>
#include "GameVersion.h"
#include "ModLoader.h"
#include "PathUtils.h"

namespace
{

class ZStream
{
public:
	z_stream s;

	ZStream()
	{
		s.avail_in = 0;
		s.next_in = nullptr;
		s.zalloc = nullptr;
		s.zfree = nullptr;
		s.opaque = nullptr;
		int ret = inflateInit2(&s, 16 + MAX_WBITS);
		if (ret != Z_OK)
			throw std::runtime_error("inflateInit2 failed: " + std::string(s.msg));
	}

	~ZStream()
	{
		inflateEnd(&s);
	}
};

std::vector<uint8_t> DecompressGZipFile(const fs::path& path)
{
	constexpr size_t CHUNK_SIZE = 16 * 1024;
	ZStream zstream;
	int ret = 0;
	std::ifstream file;
	file.open(path, std::ios::binary);

	std::vector<uint8_t> outFile;

	// decompress until deflate stream ends or end of file
	do
	{
		uint8_t buf[CHUNK_SIZE];
		file.read((char*)buf, CHUNK_SIZE);
		zstream.s.avail_in = file.gcount();

		if (zstream.s.avail_in == 0)
			break;
		zstream.s.next_in = buf;

		// run inflate() on input until output buffer not full
		do
		{
			uint8_t outBuf[CHUNK_SIZE];
			zstream.s.avail_out = CHUNK_SIZE;
			zstream.s.next_out = outBuf;

			ret = inflate(&zstream.s, Z_NO_FLUSH);
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */

			switch (ret) {
			case Z_NEED_DICT:
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				throw std::runtime_error("inflate failed: " + std::string(zstream.s.msg));
			}

			size_t have = CHUNK_SIZE - zstream.s.avail_out;
			size_t outPos = outFile.size();
			outFile.resize(outPos + have);
			memcpy(outFile.data() + outPos, outBuf, have);

		} while (zstream.s.avail_out == 0);

		// done when inflate() says it's done
	} while (ret != Z_STREAM_END);

	if (ret != Z_STREAM_END)
		throw std::runtime_error("Incomplete gzip stream");

	return outFile;
}

std::vector<uint8_t> ReadFile(const fs::path& path)
{
	std::ifstream file;
	file.exceptions(std::ios::failbit | std::ios::badbit);
	file.open(path, std::ios::binary);
	file.seekg(0, std::ios::end);
	uint64_t size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<uint8_t> data(size);
	file.read((char*)data.data(), size);
	return data;
}

}

GameVersion::GameVersion()
{
	LoadKnownVersions();
	StartAsyncTasks();
	m_bHasBackup = fs::exists(ModLoader::Get().GetGamePath() / PathUtils::GAME_DLL_BACKUP_PATH);
}

GameVersion::~GameVersion()
{
}

void GameVersion::Update()
{
	if (m_State == State::WaitTasks && IsFutureReady(m_HashGameTaskFuture))
	{
		try
		{
			HashGameResult result = m_HashGameTaskFuture.get();

			auto it = m_KnownVersions.find(result.installedGameHash);
			if (it != m_KnownVersions.end())
				m_pInstalledVersion = &it->second;
			else
				m_pInstalledVersion = nullptr;

			m_State = State::Ready;
		}
		catch (const std::exception& e)
		{
			m_State = State::Error;
			m_ErrorText = e.what();
		}
	}
}

GameVersion::Result GameVersion::ShowInstalledVersion(bool showBtns)
{
	Result result = Result::Loading;

	if (m_State == State::Error)
	{
		result = Result::Error;
		ImGui::TextColored(ImColor(255, 0, 0), "Error: %s", m_ErrorText.c_str());
		ShowModals();
		return result;
	}

	if (m_State == State::WaitTasks)
	{
		result = Result::Loading;
		ImGui::Text("Loading...");
		ShowModals();
		return result;
	}

	if (m_pInstalledVersion)
	{
		std::string ver = m_pInstalledVersion->type + "-" + m_pInstalledVersion->releaseDate;
		ImGui::Text("Game Version: %s", ver.c_str());
		if (m_pInstalledVersion->isSupported)
		{
			result = Result::Supported;
			ImGui::Text("This version is supported by Chairloader");
		}
		else
		{
			result = Result::Patchable;
			ImGui::TextColored(ImColor(255, 255, 0), "This version needs to be patched for Chairloader to work");
		}
	}
	else
	{
		result = Result::NotSupported;
		ImGui::Text("Game Version: Unknown");
		ImGui::TextColored(ImColor(255, 0, 0), "This version is not supported");
	}

	if (showBtns)
	{
		ImGui::BeginDisabled(m_pInstalledVersion == nullptr || m_pInstalledVersion->isSupported);
		if (ImGui::Button("Patch game"))
			ImGui::OpenPopup("Confirm Game Patch");
		ImGui::EndDisabled();

		ImGui::SameLine();

		ImGui::BeginDisabled(!m_bHasBackup);
		if (ImGui::Button("Restore original version"))
			RestoreBackup();
		ImGui::EndDisabled();

		ShowModals();
	}

	return result;
}

void GameVersion::LoadKnownVersions()
{
	assert(m_KnownVersions.empty()); // Hash task may be running

	fs::path xmlPath = fs::current_path() / VERSIONS_PATH / XML_NAME;
	pugi::xml_document xml;
	pugi::xml_parse_result result = xml.load_file(xmlPath.c_str());

	if (!result)
	{
		auto msg = boost::format("Failed to open %s:\n%s\nPosition: %d") % xmlPath.u8string().c_str() % result.description() % result.offset;
		throw std::runtime_error(msg.str());
	}

	// Read all versions
	for (pugi::xml_node ver : xml.child("Versions").children())
	{
		KnownVersion kv;
		kv.sha256 = SHA256::fromString(ver.child("SHA256").child_value());
		kv.type = ver.child("Type").child_value();
		kv.releaseDate = ver.child("ReleaseDate").child_value();
		kv.isSupported = ver.child("IsSupported").text().as_bool(false);

		if (m_KnownVersions.find(kv.sha256) != m_KnownVersions.end())
			throw std::runtime_error("duplicate hash " + SHA256::toString(kv.sha256.data()));

		auto it = m_KnownVersions.insert({ kv.sha256 , kv }).first;

		if (kv.isSupported)
		{
			if (!m_pSupportedVersion)
				m_pSupportedVersion = &it->second;
			else
				throw std::runtime_error("Only one version is supported");
		}
	}
}

void GameVersion::StartAsyncTasks()
{
	m_State = State::WaitTasks;
	m_HashGameTaskFuture = std::async(std::launch::async, [&]() { return HashGameTask(); });
}

void GameVersion::ShowModals()
{
	bool patchGame = false;

	ImGui::SetNextWindowSize({ 600, 0 });
	if (ImGui::BeginPopupModal("Error Occured", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped(m_ModalErrorText.c_str());
		if (ImGui::Button("Close"))
			ImGui::CloseCurrentPopup();
		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Confirm Game Patch", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("Patching the game will turn your version of the game into an Epic Games Store version.\n"
			"This will disable Steam/GOG integration, including achievements.");

		if (ImGui::Button("Continue"))
		{
			ImGui::CloseCurrentPopup();
			patchGame = true;
		}

		ImGui::SameLine();

		if (ImGui::Button("Cancel"))
			ImGui::CloseCurrentPopup();

		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Game Patch Succeded", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("Game has been successfully patched. You can return to the original version in the same menu.");
		if (ImGui::Button("Close"))
			ImGui::CloseCurrentPopup();
		ImGui::EndPopup();
	}

	if (patchGame)
	{
		try
		{
			PatchTheGame();
			StartAsyncTasks();
			ImGui::OpenPopup("Game Patch Succeded");
		}
		catch (const std::exception& e)
		{
			ImGui::OpenPopup("Error Occured");
			m_ModalErrorText = e.what();
		}
	}
}

void GameVersion::PatchTheGame() const
{
	assert(m_pInstalledVersion);

	// See if diff file exists
	std::string diffFileName = SHA256::toString(m_pInstalledVersion->sha256.data()).substr(0, 16) + DIFF_EXT;
	fs::path diffPath = fs::current_path() / VERSIONS_PATH / diffFileName;
	if (!fs::exists(diffPath))
		throw std::runtime_error("Diff file \"" + diffFileName + "\" not found");

	// Make a backup of PreyDll.dll
	fs::path dllPath = ModLoader::Get().GetGamePath() / PathUtils::GAME_DLL_PATH;
	fs::path backupFilePath = ModLoader::Get().GetGamePath() / PathUtils::GAME_DLL_BACKUP_PATH;
	fs::copy_file(dllPath, backupFilePath, fs::copy_options::overwrite_existing);

	// Decompress diff file
	std::vector<uint8_t> diffFile = DecompressGZipFile(diffPath);

	// Apply diff
	SHA256::Digest diffOrigFileHash;
	std::vector<uint8_t> origFile = ReadFile(dllPath);
	std::vector<uint8_t> patchedFile = BinDiff::ApplyDiff(origFile, diffFile, diffOrigFileHash);

	if (diffOrigFileHash != m_pInstalledVersion->sha256)
		throw std::runtime_error("Diff file \"" + diffFileName + "\" is created for a different source file. Diff hash is " +
			SHA256::toString(diffOrigFileHash.data()));

	// Write the file
	std::ofstream outDllFile;
	outDllFile.exceptions(std::ios::failbit | std::ios::badbit);
	outDllFile.open(dllPath, std::ios::binary);
	outDllFile.write((char*)patchedFile.data(), patchedFile.size());
}

void GameVersion::RestoreBackup()
{
	try
	{
		fs::path dllPath = ModLoader::Get().GetGamePath() / PathUtils::GAME_DLL_PATH;
		fs::path backupFilePath = ModLoader::Get().GetGamePath() / PathUtils::GAME_DLL_BACKUP_PATH;

		if (!fs::exists(backupFilePath))
			throw std::runtime_error("Backup file no longer exists");

		fs::copy_file(backupFilePath, dllPath, fs::copy_options::overwrite_existing);
		StartAsyncTasks();
	}
	catch (const std::exception& e)
	{
		ImGui::OpenPopup("Error Occured");
		m_ModalErrorText = e.what();
	}
}

GameVersion::HashGameResult GameVersion::HashGameTask()
{
	HashGameResult result;

	// Open the game dll
	fs::path dllPath = ModLoader::Get().GetGamePath() / PathUtils::GAME_DLL_PATH;

	if (!fs::exists(dllPath))
		throw std::runtime_error("PreyDll.dll is missing");

	std::ifstream dllFile;
	dllFile.exceptions(std::ios::failbit | std::ios::badbit);
	dllFile.open(dllPath, std::ios::binary);

	dllFile.seekg(0, std::ios::end);
	uint64_t fileSize = dllFile.tellg();
	dllFile.seekg(0, std::ios::beg);

	// Hash the file
	constexpr uint64_t CHUNK_SIZE = 16 * 1024;
	uint64_t chunks = fileSize / CHUNK_SIZE;
	uint64_t left = fileSize % CHUNK_SIZE;
	char buf[CHUNK_SIZE];

	SHA256 hash;

	for (uint64_t i = 0; i < chunks; i++)
	{
		dllFile.read(buf, CHUNK_SIZE);
		hash.update((uint8_t*)buf, CHUNK_SIZE);
	}

	dllFile.read(buf, left);
	hash.update((uint8_t*)buf, left);

	result.installedGameHash = hash.digest();
	return result;
}
