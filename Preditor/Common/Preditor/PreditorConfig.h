#pragma once
#include <Manager/GamePath.h>

//! The config file for user/environment-specific but non-project-specific things.
class PreditorConfig
{
public:
	//! Creates a new instance of PreditorConfig.
	//! Throws if env-specific paths can't be configured.
	PreditorConfig();

	//! Checks that the config is valid.
	bool ValidateConfig(std::string* error = nullptr) const;

	//! Reads the config from the XML if it exists.
	//! The config may be invalid after successfull loading. Make sure to call ValidateConfig.
	//! @returns whether the file was read successfully.
	bool LoadFromXml();

	//! Saves the config to the XML.
	void SaveToXml();

	//! @returns the path to the game.
	const GamePath& GetGamePath() const { return m_GamePath; }

	//! Sets the path to the game root.
	//! @returns true if it is valid.
	bool SetRawGamePath(const fs::path& gameRootPath, std::string* error);
	const fs::path& GetRawGamePath() { return m_RawGamePath; }

	//! @returns the path to the program root directory.
	const fs::path& GetPreditorRoot() const { return m_PreditorRoot; }

	//! @returns the path to the original non-merged Prey files.
	const fs::path& GetPreyFiles() const { return m_PreyFiles; }

private:
	static constexpr char XML_FILE_PATH[] = "Preditor/PreditorConfig.xml";

	// User-specific
	GamePath m_GamePath;
	fs::path m_RawGamePath; //!< Path as in the config.

	// Environment-specific
	fs::path m_PreditorRoot;
	fs::path m_PreyFiles;

	//! Fills environment-specific paths.
	void FillEnvPaths();
};
