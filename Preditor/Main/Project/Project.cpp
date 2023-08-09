#include "Project/Project.h"
//
// Created by theli on 10/28/2022.
//

Main::Project::Project(const fs::path& path)
{
	assert(fs::is_directory(path));
	m_ProjectPath = fs::absolute(path); // Absolute to not cause problems on workdir change
	m_ProjectName = m_ProjectPath.filename().u8string();
	ConstructPaths();
	LoadProject();
}

void Main::Project::SaveProject()
{
	// TODO: Serialize to XML
	std::ofstream file(m_ProjectFilePath);
	file << "lol\n";
}

void Main::Project::ConstructPaths()
{
	m_ProjectFilePath = m_ProjectPath / PROJECT_FILE_NAME;
}

void Main::Project::LoadProject()
{
	// TODO: Load from XML
}
