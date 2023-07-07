#pragma once

//! Various runtime paths. Set in the Launcher, used by Preditor.
//! They are specific to the selected project.
class PreditorPaths
{
public:
	//! Name of the directory for user-specific files.
	static constexpr char USER_DIR_NAME[] = ".user";

	//! @returns the path to the project directory.
	const fs::path& GetProjectDirPath() const { return m_ProjectDirPath; }

	//! @returns the path to project assets.
	const fs::path& GetAssetPath() const { return m_AssetPath; }

	//! @returns the path to the directory for user-specific project files.
	const fs::path& GetUserPath() const { return m_UserPath; }

	//! @returns the Chairloader Mods directory path.
	const fs::path& GetModsPath() const { return m_ModsPath; }

	//! @returns the imported assets directory.
	const fs::path& GetImportedAssetsPath() const { return m_ImportedAssetsPath; }

	//! @returns the merged assets directory.
	const fs::path& GetMergedAssetsPath() const { return m_MergedAssetsPath; }

	//! @returns the root of merged assets directory, which contains GameSDK directory.
	const fs::path& GetMergedAssetsRootPath() const { return m_MergedAssetsRootPath; }

	//! Sets the path to the project directory. Also sets all paths that depend on it.
	void SetProjectDirPath(const fs::path& path)
	{
		m_ProjectDirPath = path;
		m_AssetPath = m_ProjectDirPath / "Data";

		m_UserPath = path / USER_DIR_NAME;
		m_ModsPath = m_UserPath / "Mods";
		m_ImportedAssetsPath = m_UserPath / "ImportedAssets";
		m_MergedAssetsRootPath = m_UserPath / "MergedAssets";
		m_MergedAssetsPath = m_MergedAssetsRootPath / "GameSDK";
	}

	//! Creates user directories and subdirectories.
	void CreateUserDirs() const
	{
		fs::create_directory(m_UserPath);
		fs::create_directory(m_ModsPath);
		fs::create_directory(m_ImportedAssetsPath);
	}

private:
	// Project paths
	fs::path m_ProjectDirPath;
	fs::path m_AssetPath; // Data

	// User paths
	fs::path m_UserPath; // .user
	fs::path m_ModsPath; // .user/Mods
	fs::path m_ImportedAssetsPath; // .user/ImportedAssets
	fs::path m_MergedAssetsRootPath; // .user/MergedAssets
	fs::path m_MergedAssetsPath; // .user/MergedAssets/GameSDK
};
