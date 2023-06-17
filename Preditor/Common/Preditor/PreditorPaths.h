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

	//! @returns the path to the directory for user-specific project files.
	const fs::path& GetUserPath() const { return m_UserPath; }

	//! Sets the path to the project directory. Also sets all paths that depend on it.
	void SetProjectDirPath(const fs::path& path)
	{
		m_ProjectDirPath = path;
		m_UserPath = path / USER_DIR_NAME;
	}

private:
	fs::path m_ProjectDirPath;
	fs::path m_UserPath;
};
